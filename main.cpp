#include<iostream>
#include"types.h"
#include"application_logic.h"
#include"error_handling.h"
#include"logger.h"
#include"memory_manager.h"
#include"pointer_safety.h"
int main()
{
    if(!app_init())
    {
        log_message(LOG_ERROR,"Application initialization failed.");
        logger_close();
        return EXIT_FAILURE;
    }
    if(!app_execute())
    {
        log_message(LOG_ERROR,"Application execution failed.");
        app_cleanup();
        return EXIT_FAILURE;
    }
    app_cleanup();
    logger_close();
    log_message(LOG_INFO,"Application exited successfully.");
    return EXIT_SUCCESS;
}