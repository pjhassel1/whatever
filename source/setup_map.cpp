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
		"Shelves line the walls which are filled with books.  A large oak desk with intricate carvings on it is in the middle of the room.");

	map.add_room(5, "Dojo",
		"A large sparring mat fills the center of the room and has yellowed with time.  Banners depicting combat hang on the east and west walls.  A shrine is prominately displayed on the south wall.");

	map.add_room(6, "Main room",
		"In the center of the room is a long dead circular fire pit.  Above it is a stainless steel hood to capture the smoke.  Around the pit are leather couches and chairs.  The northwest corner has a cabinet and there is a small horizontal slot on the west wall beside the cabinet.");

	map.add_room(7, "Bedroom1",
		"Twin beds on east and west walls with headboards along the north wall.  Night stands beside each bed.");

	map.add_room(8, "Bedroom2",
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



	return true;

}
