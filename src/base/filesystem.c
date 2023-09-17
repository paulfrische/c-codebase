#include "filesystem.h"
#include "base.h"
#include "memory.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

// read entire file
String filesystem_read_file(Arena* arena, String path)
{
    Arena* scratch = arena_init_sized(path.len);
    char* cpath = str_to_c_str(scratch, path);
    FILE* file = fopen(cpath, "r");
    if (file == NULL) {
        LOG("file %s doesn't exits/could'd be opened", cpath);
    }

    u64 len = 1;
    char* content = (char*)malloc(len * sizeof(char));
    if (content == NULL) {
        LOG("couldn't malloc string for reading file", "");
    }

    char c;
    while ((c = fgetc(file))) {
        if (c == EOF) {
            break;
        }
        content[len - 1] = c;
        len++;
        content = realloc(content, len);
    }

    /* LOG("run?", ""); */
    String temp = {
        .str = content,
        .len = len,
    };

    String result = str_copy(arena, temp);

    free(content);
    fclose(file);
    arena_free(scratch);

    return result;
}

// write content to file
void filesystem_write_file(String path, String content)
{
    Arena* scratch = arena_init_sized(path.len + content.len);
    FILE* file = fopen(str_to_c_str(scratch, path), "w");

    fprintf(file, "%s", str_to_c_str(scratch, content));

    fclose(file);
    arena_free(scratch);
}

// append content to file
void filesystem_append_file(String path, String content)
{
    Arena* scratch = arena_init_sized(path.len + content.len);
    FILE* file = fopen(str_to_c_str(scratch, path), "a");

    fprintf(file, "%s", str_to_c_str(scratch, content));

    fclose(file);
    arena_free(scratch);
}
