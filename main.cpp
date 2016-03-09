#include <iostream>
#include "include/map.h"
#include "include/items.h"
#include "include/room.h"
#include "include/setup_map.h"

using std::cout;
using std::endl;


int main()
{
	Map map;

	if (setup_map(map))
		cout << "Map initialized." << endl;
	else
		cout << "Map failed to initialize." << endl;

	std::cout << "whatever" << std::endl;

	/* Only run this in windows */
#ifdef _MSC_VER
	system("pause");
#endif

	return 0;
}
