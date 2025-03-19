#include"error_handling.h"
#include<cassert>
void log_error(const char* format, ...)
{
    va_list args;
    _crt_va_start(args,format);
    log_message(LOG_ERROR,format,args);
    _crt_va_end(args);
}
void log_warning(const char* format, ...)
{
    va_list args;
    _crt_va_start(args,format);
    log_message(LOG_WARNING,format,args);
    _crt_va_end(args);
}
void log_fatal(const char* format, ...)
{
    va_list args;
    _crt_va_start(args,format);
    log_message(LOG_WARNING,format,args);
    _crt_va_end(args);
    exit(EXIT_FAILURE);
}