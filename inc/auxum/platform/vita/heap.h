#pragma once
#ifndef AUXUM_VITAHEAP_FIX_H
#define AUXUM_VITAHEAP_FIX_H

#include "../../std.h"

#ifdef BUILD_TYPE_VITA
#ifdef VITA_NEWLIB_HEAP_SIZE
int _newlib_heap_size_user = VITA_NEWLIB_HEAP_SIZE;
#else
int _newlib_heap_size_user = 100 * MB;              // 100MB default VITASDK heap, should be more than enough.
#endif
#ifdef VITA_SCELIBC_HEAP_SIZE
unsigned int sceLibcHeapSize = VITA_SCELIBC_HEAP_SIZE;
#else
unsigned int sceLibcHeapSize = 10 * MB;             // 10MB default SCELibC heap, should be enough.
#endif
#endif

#endif
