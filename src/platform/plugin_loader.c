#include "platform/plugin_loader.h"

#ifndef BUILD_TYPE_VITA

plugin_result_t plugin_load(char* const path)
{
    plugin_result_t result = {0};
#ifdef BUILD_TYPE_WINDOWS
    result.result = (plugin_t)LoadLibrary(path);
#else
    result.result = dlopen(path, RTLD_NOW);
#endif
    if(!result.result)
    {
        result.ok = false;
        result.error = "Could not find the plugin!";
        return result;
    }
    result.ok = true;
    return result;
}

plugin_function_result_t plugin_get_symbol(plugin_t self, char* const name)
{
    plugin_function_result_t result = {0};
    #ifdef BUILD_TYPE_WINDOWS
    result.result = (void*)GetProcAddress(self, name);
#else
    result.result = dlsym(self, name);
#endif
    if(!result.result)
    {
        result.ok = false;
        result.error = "Could not find symbol!";
        return result;
    }
    result.ok = true;
    return result;
}

#endif
