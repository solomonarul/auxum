#include "platform/app.h"
#include <string.h>

static char* app_path = NULL;

void auxum_set_app_path(char* const path)
{
    app_path = path;
}

char* auxum_get_app_path(void)
{
    return app_path;
}
