#pragma once
#ifndef AUXUM_STD_H
#define AUXUM_STD_H

#ifdef BUILD_TYPE_WINDOWS
#define _CRT_SECURE_NO_WARNINGS     // Windows fix for being annoying.
#endif

#ifdef BUILD_TYPE_VITA
#define __psp2__                    // Vita fix for being slightly annoying.
#endif

#include "std/error.h"
#include "std/unused.h"
#include "std/strings.h"

#endif
