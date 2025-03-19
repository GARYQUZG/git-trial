#pragma once
#include<iostream>
#include"types.h"
#include"logger.h"
//日志级别
typedef enum{
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_FATAL
}LogLevel;
bool logger_init(const char* logFilePath);
void logger_close(void);
void log_message(LogLevel level, const char* format ...);
void set_log_level(LogLevel level);