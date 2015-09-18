#include "Core.hpp"
#include "Window.hpp"
#include "Console.hpp"

namespace grv
{
	Core* Core::_instance = nullptr;

	void Core::Init(HINSTANCE handle)
	{
		if(!_instance)
			new Core(handle);
	}

	void Core::Deinit()
	{
		delete _instance;
	}

	Core::Core(HINSTANCE handle)
		: _application_handle(handle)
		, _window(nullptr)
		, _console(nullptr)
	{
		_instance = this;
	}

	Core::~Core()
	{
		delete _window;
		delete _console;

		_instance = nullptr;
	}

	void Core::InitWindow(u32 width, u32 height)
	{
		_window = new Window(width, height);
	}

	void Core::InitConsole()
	{
		_console = new Console();
	}

}

