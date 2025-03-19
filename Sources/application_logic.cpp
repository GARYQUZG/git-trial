#include"application_logic.h"
#include"error_handling.h"
#include"logger.h"
#include"memory_manager.h"
#include"pointer_safety.h"
#define PATH "application.log"
bool app_init()
{
    if(!logger_init(NULL))
    {
        fprintf(stderr,"Failed to initialize logger.");
        return false;
    }
    set_log_level(LOG_DEBUG);
    log_message(LOG_INFO,"Application initializing...");
    return true;
}
bool app_execute()
{
    log_message(LOG_DEBUG,"Starting app_execute.");
    size_t size = sizeof(int);
    int* data = static_cast<int*>(safe_malloc(size));
    if(data==nullptr)
    {
        log_error("Failed to allocate memory for data.");
        return false;
    }

    log_message(LOG_DEBUG,"Memory allocated successfully,now setting value.");
    *data=42;
    log_message(LOG_INFO,"Data value set to %d",*data);
    safe_free((void**)&data);
    log_message(LOG_DEBUG,"Finishing app_execute.");
    return true;
}

    

void app_cleanup()
{
    log_message(LOG_INFO,"Cleaning up application...");
}