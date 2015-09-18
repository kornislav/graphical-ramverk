#include <System.hpp>
#include <cassert>

namespace grv
{
	class Window;
	class Console;

	class Core
	{
	public:
		API static void Init(HINSTANCE handle);
		API static void Deinit();

		API static Core& GetInstance() { assert(_instance); return *_instance; }
		API static Core* GetInstancePtr() { return _instance; }

		API void InitWindow(u32 width, u32 height);
		API void InitConsole();

	private:
		Core(HINSTANCE handle);
		~Core();

		static Core* _instance;

		HINSTANCE _application_handle;
		Window* _window;
		Console* _console;
	};
}