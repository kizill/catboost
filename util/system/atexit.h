#pragma once

#include "defaults.h"

using TAtExitFunc = void (*)(void*);
using TTraditionalAtExitFunc = void (*)();

void AtExit(TAtExitFunc func, void* ctx);
void AtExit(TAtExitFunc func, void* ctx, size_t priority);

void AtExit(TTraditionalAtExitFunc func);
void AtExit(TTraditionalAtExitFunc func, size_t priority);

/**
 * This method only for very special cases, like graceful python DLL module unload
 */
void ManualRunAtExitFinalizers();

bool ExitStarted();
