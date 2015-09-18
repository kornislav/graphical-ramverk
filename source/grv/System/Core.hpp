#include <System.hpp>
#include <cassert>

namespace grv
{
	class Core
	{
	public:
		static void Initialize(HINSTANCE handle);
		static void Deinitialize();

		static Core& GetInstance() { assert(_instance); return *_instance; }
		static Core* GetInstancePtr() { return _instance; }

	private:
		Core(HINSTANCE handle);
		~Core();

		static Core* _instance;

		HINSTANCE _application_handle;
	};
}