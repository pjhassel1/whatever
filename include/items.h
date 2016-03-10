/* items.h
 *
 * Classes and functions for storing and manipulating items
 */

#ifndef _ITEMS_H
#define _ITEMS_H

#include <string>
#include <vector>

/* Types of items */
enum item_type
{
	WEAPON,
	TOOL,
	SHIRT,
	JACKET,
	PANTS,
	SOCKS,
	SHOES
};

enum weapon_type
{
	PIERCING,
	SLASHING,
	BLUDGEONING,
	PROJECTILE
};

/* Item Class
 *
 * This class represents an item in the game.
 * Note that the name must be unique.  If two items have the same name,
 * it will cause problems if they wind up in the same container.
 */
class Item
{
public:
	Item();
	Item(const std::string &item_name, item_type itype);

	/* Copy constructor */
	//Item(Item& rhs);
	/* Move constructor */
	//Item(Item&& rhs);

	/* Just returns the fail string */
	std::string use();

	/* Returns the next item number for the constructor */
	int get_next_item_num();

	/* Adds an alias for an item, which acts as an addition name */
	void add_alias(const std::string &alias);

	/* Returns true if the string is the name or an alias of this item.
	 * Comparison is case insensitive. */
	bool is_item_name(const std::string &token);

	/* Looks at an item */
	void look();

	/* Mutators */
	void set_name(const std::string &item_name);
	void set_description(const std::string &item_description);
	void set_fail_message(const std::string &item_fail_msg);
	void set_encumberance(const int item_encumberance);
	void set_item_type(const item_type itype);

	/* Accessors */
	int get_item_num() const;
	std::string get_name() const;
	std::string get_description() const;
	std::string get_fail_message() const;
	int get_encumberance() const;
	item_type get_item_type() const;
protected:
	int item_num;
	std::string name;
	std::string description;
	std::string fail_message;
	int encumberance;
	item_type type;
	static int num_items;
	std::vector<std::string> aliases;
};


/* Weapon Class
 *
 */
class Weapon : public Item
{
public:
	Weapon();
	Weapon(const std::string &wep_name, weapon_type wep_type);
	// Weapon(Weapon &rhs);
	// Weapon(Weapon &&rhs);

	/* Load more ammo - number is number of projectiles to add */
	void load(int projectiles);

	weapon_type get_weapon_type() const;
	int get_damage() const;
	int get_ammo_remaining() const;

	void set_weapon_type(const weapon_type wep_type);
	void set_damage(const int wep_damage);
	void set_ammo_remaining(const int wep_ammo_remaining);
private:
	weapon_type wtype;
	int damage;
	int ammo_remaining;
};

#endif /* _ITEMS_H */

/* Emacs stuff, ignore this */
// Local Variables:
// mode: c++
// End:
