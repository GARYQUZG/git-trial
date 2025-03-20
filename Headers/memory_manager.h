#pragma once
#include "types.h"
#include <iostream>
void *safe_malloc(size_t size);
void *safe_remalloc(void *ptr, size_t newsize);
void safe_free(void **ptr);