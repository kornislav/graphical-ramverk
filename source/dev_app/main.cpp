#include <grv.hpp>

int main()
{
	grv::Core::GetInstance().InitConsole();
	LogL("Working!");
	system("pause");

	return 0;
}