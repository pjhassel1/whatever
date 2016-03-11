#include "../include/setup_map.h"
// rm #, rm name, rm description


bool setup_map(Map &map)
{
	map.add_room(1, "Teleport Room",
		"This room almost looks like an interogation room.  It only has a stainless steel table in the center of the room. ");

	map.add_room(2, "North closet",
		"Very small room. There is a small horizontal slot on the east wall.");

	map.add_room(3, "South closet",
		"Very small room.  There is a small horizontal slot on the east wall.");

	map.add_room(4, "Office",
		"Shelves line the walls which are filled with books.  A large oak desk with intricate carvings on it is in the middle of the room.  There is a horizontal slot on the south wall.");

	map.add_room(5, "Dojo",
		"A large sparring mat fills the center of the room and has yellowed with time.  Banners depicting combat hang on the east and west walls.  A shrine holding two swords is prominately displayed on the south wall.  There is a horizontal slot on the north wall.");

	map.add_room(6, "Main room",
		"In the center of the room is a long dead circular fire pit.  Above it is a stainless steel hood to capture the smoke.  Around the pit are leather couches and chairs.");

	map.add_room(8, "Bedroom",
		"Queen bed in center of room with headboard on the north wall.  Nightstands on either side of bed.");

	map.add_room(9, "Hallway",
		"Portraits line the north and south walls.  One is of a youth knealing and accepting a Katana from a grey haired man.");

	map.add_room(10, "Kitchen",
		"No frills kitchen.  Pots and pans hang from the cieling over a center island.  Cabinets line north, south and east walls.  On the north wall are a fridge and a stove.  Within the east counter is a sink.  Circuit breaker box on the south wall.");

	map.add_room(11, "Dining Room",
		"A large dining table fills the center of this room.  There are 13 normal chairs around the table with a larger one on the west end of the table.");

	map.add_room(12, "Attic",
		"Both the north and south walls are lined with ornate storage trunks.  Near the east end of the room is a gothic padded kneeler facing the east wall.");

	map.add_room(13, "Basement",
		"Old waterlogged furnature along the south wall.  A couple of rusted out weapons racks on the north wall.");

	map.add_room(14, "Well room",
		"In the center of the east half of room is a water well.");

	map.add_exit_to_room(1, "north", 2);
	map.add_exit_to_room(1, "south", 3);
	map.add_exit_to_room(2, "south", 1);
	map.add_exit_to_room(3, "north", 1);
	map.add_exit_to_room(5, "north", 6);
	map.add_exit_to_room(6, "south", 5);
	map.add_exit_to_room(6, "down", 13);
	map.add_exit_to_room(6, "east", 9);
	map.add_exit_to_room(6, "up", 12);
	map.add_exit_to_room(8, "south", 9);
	map.add_exit_to_room(9, "south", 11);
	map.add_exit_to_room(9, "north", 8);
	map.add_exit_to_room(9, "west", 6);
	map.add_exit_to_room(10, "west", 11);
	map.add_exit_to_room(11, "east", 10);
	map.add_exit_to_room(11, "north", 9);
	map.add_exit_to_room(12, "down", 6);
	map.add_exit_to_room(13, "up", 6);
	map.add_exit_to_room(13, "east", 14);
	map.add_exit_to_room(14, "west", 13);




	return true;

}

bool setup_items(Map &map)
{
	Item newitem = Item("Singnature Ring", TOOL);
	newitem.set_description("Silver ring with inset red stone which has a coat of arms emblem made of silver.");
	newitem.set_fail_message("Nothing happens.");
	newitem.set_encumberance(1);
	newitem.add_alias("ring");
	newitem.add_alias("Signature ring");
	map.add_item_to_room(4, std::move(newitem));



	newitem = Item("Blue Card", TOOL);
	newitem.set_description("Looks like a credit card with a smart chip on it.");
	newitem.set_fail_message("You appear back in the Teleport room.");
	newitem.set_encumberance(1);
	newitem.add_alias("blue");
	newitem.add_alias("card");
	map.add_item_to_room(1, std::move(newitem));

	newitem = Item("Red Card", TOOL);
	newitem.set_description("Looks like a credit card with a smart chip on it.");
	newitem.set_fail_message("You appear back in the Teleport room.");
	newitem.set_encumberance(1);
	newitem.add_alias("red");
	newitem.add_alias("card");
	map.add_item_to_room(1, std::move(newitem));

	newitem = Item("Katana", WEAPON);
	newitem.set_description("42inch sligtly curved sword with the edge on the outside of the curve.");
	newitem.set_fail_message("You nearly cut your toes off.  Watch it!!");
	newitem.set_encumberance(2);
	newitem.add_alias("sword");
	map.add_item_to_room(5, std::move(newitem));

	newitem = Item("Tachi", WEAPON);
	newitem.set_description("24inch sligtly curved sword with the edge on the outside of the curve.");
	newitem.set_fail_message("You nearly cut your toes off.  Watch it!!");
	newitem.set_encumberance(1);
	newitem.add_alias("knife");
	map.add_item_to_room(5, std::move(newitem));

	newitem = Item("Flashlight", TOOL);
	newitem.set_description("6inch black flashlight.");
	newitem.set_fail_message("You shine the light in your eyes.");
	newitem.set_encumberance(1);
	newitem.add_alias("torch");
	map.add_item_to_room(8, std::move(newitem));

	newitem = Item("Blacklight", TOOL);
	newitem.set_description("6inch black flashlight.");
	newitem.set_fail_message("You see nothing.");
	newitem.set_encumberance(1);
	newitem.add_alias("purple");
	map.add_item_to_room(8, std::move(newitem));



	return true;
}
