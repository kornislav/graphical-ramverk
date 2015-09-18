#include "Core.hpp"

namespace grv
{
	Core* Core::_instance = nullptr;

	void Core::Initialize(HINSTANCE handle)
	{
		if(!_instance)
			new Core(handle);
	}

	void Core::Deinitialize()
	{
		delete _instance;
	}

	Core::Core(HINSTANCE handle)
		: _application_handle(handle)
	{
		_instance = this;
	}

	Core::~Core()
	{
		_instance = nullptr;
	}
}

