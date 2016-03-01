#include <iostream>

int main()
{
	std::cout << "whatever" << std::endl;

	/* Only run this in windows */
#ifdef _MSC_VER
	system("pause");
#endif

	return 0;
}
