#include <System.hpp>
#include <System/Core.hpp>

BOOL WINAPI DllMain(HINSTANCE handle, DWORD, LPVOID)
{
	grv::Core::Init(handle);

	return TRUE;
}