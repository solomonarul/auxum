#pragma once
#ifndef AUXUM_STD_H
#define AUXUM_STD_H

#ifdef BUILD_TYPE_WINDOWS
#define _CRT_SECURE_NO_WARNINGS                                                                                     // Windows fix for being annoying.
#endif

#ifdef BUILD_TYPE_VITA
#define __psp2__                                                                                                    // Vita fix for being slightly annoying.
int _newlib_heap_size_user   = #ifdef VITA_NEWLIB_HEAP_SIZE VITA_NEWLIB_HEAP_SIZE #else 100 * 1024 * 1024 #endif;   // 100MB default VITASDK heap, should be more than enough.
unsigned int sceLibcHeapSize = #ifdef VITA_SCELIBC_HEAP_SIZE VITA_SCELIBC_HEAP_SIZE #else 10 * 1024 * 1024 #endif;  // 10MB default SCELibC heap, should be enough.
#endif

#include "std/error.h"
#include "std/unused.h"
#include "std/strings.h"

#endif
