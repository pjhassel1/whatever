#include <iostream>
#include "include/map.h"
#include "include/items.h"
#include "include/room.h"
#include "include/setup_map.h"
#include "include/utility.h"

using std::cout;
using std::endl;


int main()
{
	Map map;

	if (! setup_map(map)) {
		cout << "Map failed to initialize." << endl;
		return 1;
	}

	// cout << map.get_current_room().get_name() << endl;
	// cout << word_wrap(map.get_current_room().get_description()) << endl;

	look(map);

	/* Only run this in windows */
#ifdef _MSC_VER
	system("pause");
#endif

	return 0;
}
