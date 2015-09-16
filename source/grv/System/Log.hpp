#pragma once

#include <System.hpp>
#include <cstdio>
#ifndef CPP11
#include <cstdarg>
#endif

namespace grv
{
	enum LogStatus
	{
		LOG_DEFAULT,
		LOG_WARNING,
		LOG_ERROR
	};

#if CPP11
	template<typename... Params>
	static void __Log(LogStatus status, const char* message, Params... parameters)
	{
		FILE* output = stdout;

		switch(status)
		{
		case LOG_ERROR:
			SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 0x0C);
			output = stderr;
			break;
		case LOG_WARNING:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0E);
			break;
		case LOG_DEFAULT:
		default:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
		}

		fprintf(output, message, parameters...);
	}
#else
	static void __Log(LogStatus status, const char* message, ...)
	{
		va_list args;
		va_start(args, message);

		FILE* output = stdout;

		switch(status)
		{
		case LOG_ERROR:
			SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 0x0C);
			output = stderr;
			break;
		case LOG_WARNING:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0E);
			break;
		case LOG_DEFAULT:
		default:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
		}

		vfprintf_s(output, message, args);

		va_end(args);
	}
#endif
}

#define __STR(x) #x
#define STR(x) __STR(x)

#define LineAndFile(message) "Line " STR(__LINE__) " in " __FILE__ ": " message

#define Log(message, ...) grv::__Log(grv::LOG_DEFAULT, message, __VA_ARGS__)
#define Warn(message, ...) grv::__Log(grv::LOG_WARNING, LineAndFile(message), __VA_ARGS__)
#define Err(message, ...) grv::__Log(grv::LOG_ERROR, LineAndFile(message), __VA_ARGS__)

// appends a newline after the message
#define LogL(message, ...) Log(message "\n", __VA_ARGS__)
#define WarnL(message, ...) Warn(message "\n", __VA_ARGS__)
#define ErrL(message, ...) Err(message "\n", __VA_ARGS__)
