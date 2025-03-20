#pragma once
#include "error_handling.h"
bool is_nullptr(const void *ptr);

#define SAFE_DEREF(ptr, defaultValue) \ (is_nullptr(ptr) ? (log_error("Attempted to dereference a NULL pointer."), defaultValue) : *(ptr))
