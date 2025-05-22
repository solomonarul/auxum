#pragma once
#ifndef AUXUM_PLUGIN_H
#define AUXUM_PLUGIN_H

#ifndef BUILD_TYPE_VITA

#ifdef BUILD_TYPE_WINDOWS
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __attribute__((visibility("default")))
#endif

#endif

#endif
