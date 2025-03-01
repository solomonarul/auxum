#include "std/strings.h"

#include <string.h>

void string_nconcat(char* const dest, char* const first, int first_size, char* const second, int second_size)
{
    memccpy((void*)dest, first, '\0', first_size);
    memccpy((void*)(dest + first_size), second, '\0', second_size);
    dest[first_size + second_size] = '\0';   
}

void string_concat(char* const dest, char* const first, char* const second)
{
    const int first_len = strlen(first);
    const int second_len = strlen(second);
    string_nconcat(dest, first, first_len, second, second_len);
}

char* string_strip(char* const src)
{
    char* result = src;
    while((result[0] == ' ' || result[0] == '\n') && result[0] != '\0') result++;
    int length = strlen(result);
    while((result[length - 1] == ' ' || result[length - 1] == '\n') && length > 0)
    {
        result[length - 1] = '\0';
        length--;
    }
    return result;
}
