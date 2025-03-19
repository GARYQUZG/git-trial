#include<iostream>
#include"logger.h"
#include"types.h"
#include<ctime>

static FILE* logFile = nullptr;
static LogLevel currentLevel = LOG_INFO; 

bool logger_init(const char* logFilePath)
{
    if(logFilePath)
    {
        errno_t err = fopen_s(&logFile, logFilePath,"a");
        if(err !=0 || !logFile)
        {
            return false;
        }

    }
    else{
        logFile = stdout;
    }
    return true;
}

void logger_close(void)
{
    if(logFile&&logFile!=stdout)
    {
        fclose(logFile);
    }
    logFile = nullptr;
}

void log_message(LogLevel level, const char* format ...)
{
    if(level<currentLevel || !logFile)
    {
        return;
    }
    time_t now = time(NULL);
    struct tm *now_tm = localtime(&now);
    fprintf(logFile,"[%d-%02d-%02d %02d:%02d:%02d]",now_tm->tm_year+1900,now_tm->tm_mon+1,now_tm->tm_mday,
    now_tm->tm_hour,now_tm->tm_min,now_tm->tm_sec);
    switch(level)
    {
        case LOG_DEBUG:fprintf(logFile,"[DEBUG]");break;
        case LOG_INFO:fprintf(logFile,"[INFO]");break;
        case LOG_WARNING:fprintf(logFile,"[WARNING]");break;
        case LOG_ERROR:fprintf(logFile,"[ERRRO]");break;
        case LOG_FATAL:fprintf(logFile,"[FATAL]");break;
        default: break;
    }
    va_list args;
    _crt_va_start(args,format);
    vfprintf(logFile,format,args);
    _crt_va_end(args);
    fprintf(logFile,"\n");
    fflush(logFile);

}
void set_log_level(LogLevel level)
{
    currentLevel=level;
}