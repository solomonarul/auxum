#pragma once
#ifndef AUXUM_FILE_UTILS_H
#define AUXUM_FILE_UTILS_H

#include <stdint.h>
#include <stdio.h>

size_t file_get_size(FILE* file);
char* file_read_all(FILE* file);

#endif
