#include "Console.hpp"

#include <cstdio>
#include <io.h>
#include <fcntl.h>

namespace grv
{
	Console::Console()
	{
		assert(AllocConsole());
		int input_handle = _open_osfhandle(reinterpret_cast<intptr_t>(GetStdHandle(STD_INPUT_HANDLE)), _O_TEXT);
		int output_handle = _open_osfhandle(reinterpret_cast<intptr_t>(GetStdHandle(STD_OUTPUT_HANDLE)), _O_TEXT);
		int error_handle = _open_osfhandle(reinterpret_cast<intptr_t>(GetStdHandle(STD_ERROR_HANDLE)), _O_TEXT);
		*stdin = *_fdopen(input_handle, "r");
		*stdout = *_fdopen(output_handle, "w");
		*stderr = *_fdopen(error_handle, "w");
	}

	Console::~Console()
	{
		fclose(stdout);
		fclose(stdin);
		fclose(stderr);
		FreeConsole();
	}
}
