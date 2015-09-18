#pragma once

#include <System.hpp>

namespace grv
{
	class Window
	{
	public:
		Window(u32 width, u32 height);
		~Window();

	private:
		u32 _width;
		u32 _height;
	};
}

