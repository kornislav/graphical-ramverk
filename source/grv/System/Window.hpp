#pragma once

#include <System.hpp>

namespace grv
{
	class Window
	{
	public:
		Window(HINSTANCE handle, u32 width, u32 height);
		~Window();

	private:
		HINSTANCE _application_handle;
		HWND _window;

		u32 _width;
		u32 _height;
	};
}

