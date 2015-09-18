#include "Window.hpp"
#include <System/Console.hpp>

LRESULT CALLBACK WndProc(HWND window, UINT message, WPARAM w_param, LPARAM l_param)
{
	switch(message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(window, message, w_param, l_param);
	}
	return 0;
}

namespace grv
{
	Window::Window(HINSTANCE handle, u32 width, u32 height)
		: _application_handle(handle)
		, _width(width)
		, _height(height)
	{
		// Create the window
		WNDCLASSEX wc;
		memset(&wc, 0, sizeof(wc));

		wc.cbSize = sizeof(WNDCLASSEX);
		wc.lpfnWndProc = WndProc;
		wc.hInstance = _application_handle;
		wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
		wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wc.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
		wc.lpszMenuName = nullptr;
		wc.lpszClassName = "Graphical RamVerk Class";
		wc.hIconSm = wc.hIcon;

		if(!RegisterClassEx(&wc))
		{
			ErrL("Failed to register class: %s", wc.lpszClassName);
			return;
		}

		LPSTR window_title = "Graphical RamVerk";
		_window = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			wc.lpszClassName,
			window_title,
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			width,
			height,
			nullptr,
			nullptr,
			_application_handle,
			nullptr
			);

		if(!_window)
		{
			ErrL("Failed to create window: %s", window_title);
			return;
		}
	}

	Window::~Window()
	{

	}
}
