#include "file/utils.h"
#include <stdlib.h>

size_t file_get_size(FILE* file)
{
    fseek(file, 0L, SEEK_END);
    size_t size = ftell(file);
    fseek(file, 0L, SEEK_SET);
    return size;
}

char* file_read_all(FILE* file)
{
    size_t size = file_get_size(file);
    char* result = calloc(size + 1, sizeof(char));
    fread(result, sizeof(char), size, file);
    return result;
}
