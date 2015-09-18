#include <System.hpp>
#include <System/Core.hpp>

BOOL WINAPI DllMain(HINSTANCE handle, DWORD, LPVOID)
{
	grv::Core::Initialize(handle);

	return TRUE;
}