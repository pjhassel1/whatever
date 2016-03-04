/* items.h
 *
 * Classes and functions for storing and manipulating items
 */

#ifndef _ITEMS_H
#define _ITEMS_H

#include <string>

using std::string;

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

class Item
{
public:
	Item();
	Item(const string &item_name, const string &item_description,
	     const string &item_fail_msg, int item_encumberance,
	     item_type itype);

	/* Copy constructor */
	Item(Item& rhs);
	/* Move constructor */
	Item(Item&& rhs);

	/* Desctructor */
	~Item();

	string use();
	string use(Item direct_object);

	void set_name(const string &item_name);
	void set_description(const string &item_description);
	void set_fail_message(const string &item_fail_msg);
	void set_encumberance(int item_encumberance);
	void set_item_type(item_type itype);

	string get_name() const;
	string get_description() const;
	string get_fail_message() const;
	int get_encumberance() const;
	item_type get_item_type() const;
protected:
	string name;
	string description;
	string fail_message;
	int encumberance;
	item_type type;
};

class Weapon : public Item
{
public:
	Weapon();
	Weapon(const string &wep_name, const string &wep_description,
	       const string &wep_fail_msg, int wep_encumberance,
	       weapon_type wep_type, int wep_damage, int wep_ammo_remaining);
	Weapon(Weapon &rhs);
	Weapon(Weapon &&rhs);
private:
	weapon_type wtype;
	int damage;
	int ammo_remaining;
};

#endif /* _ITEMS_H */
