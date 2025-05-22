#pragma once
#include "std/error.h"
#ifndef AUXUM_PLUGIN_H
#define AUXUM_PLUGIN_H

#ifndef BUILD_TYPE_VITA

#ifdef BUILD_TYPE_WINDOWS
#include <windows.h>
typedef HMODULE plugin_t;
#define plugin_free(handle) FreeLibrary(handle)
#else
#include <dlfcn.h>
typedef void* plugin_t;
#define plugin_free(handle) dlclose(handle)
#endif

DEFINE_RESULT(plugin_t, char*, plugin_result_t);
DEFINE_RESULT(void*, char*, plugin_function_result_t);

plugin_result_t plugin_load(char* const path);
plugin_function_result_t plugin_get_symbol(plugin_t self, char* const name);

#endif

#endif
