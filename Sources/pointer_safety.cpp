#include "pointer_safety.h"
#include "error_handling.h"
#include "logger.h"
bool is_nullptr(const void *ptr)
{
    if (ptr == nullptr)
    {
        log_error("Detected a nullptr.");
        return true;
    }
    return false;
}