#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED

#include "item.hpp"
#include "weapons.hpp"
#include "armor.hpp"
#include "ability.hpp"

#include <list>
#include <utility>
#include <iostream>

class Inventory
{
    public:


    //Whilst weapons and armor are also items they have their own
    //specfic properties and so cannot be stored in the same list
    //as items. Use a list and not a vector as inventories are highly
    //mutable. This way they can also be efficiently sorted. The first
    //element of the pair stores a point to the item in the item/weapon
    //armor atlas, defined in main(), and the second element stores
    //the quantity of the item
    std::list<std::pair<Item*, int>>items;
    std::list<std::pair<Weapon*, int>>weapons;
    std::list<std::pair<Armor*, int>>armor;
    std::list<std::pair<Ability*, int>>abilities;
    Inventory()
    {

    }

    Inventory(std::list<std::pair<Item*, int>>items,
              std::list<std::pair<Weapon*, int>>weapons,
              std::list<std::pair<Armor*, int>>armor,
              std::list<std::pair<Ability*, int>>abilities)
    {
        this->items = items;
        this->weapons = weapons;
        this->armor = armor;
    }

    void add_Item(Item* item, int count)
    {
        //increase the quantity if the item already exists
        for(auto& it : this->items)
        {
            if(it.first == item)
            {
            it.second += count;return;
            }
        }
        //if the item doesn't already exist in the inventory
        //them a pair must be created too
        this->items.push_back(std::make_pair(item,count));
    }

    void add_weapons(Weapon* weapons, int count)
    {
        for(auto& it : this->weapons)
        {
            if(it.first == weapons)
            {
                it.second += count; return;
            }
        }
        this->weapons.push_back(std::make_pair(weapons, count));
    }


    void add_armor(Armor* armor, int count)
    {
        for(auto& it : this->armor)
        {
            if(it.first == armor)
            {
                it.second += count;return;
            }
        }
        this->armor.push_back(std::make_pair(armor, count));
    }

    void remove_Item(Item* item, int count)
    {
        //Iterate through the items and if they are found then decrease
        //the quantity by the quantity removed
        for(auto& it : this->items)
        {
            if(it.first == item) it.second -= count;
        }

        //Iterate through the list again, and remove any elements from
        //the list that have zero or less for their quantity
        //Do this in two passes because removing an element from a list
        //during a for loop invalidates the iterators, and the loop
        //stops working
        this->items.remove_if([](std::pair<Item*, int>& element)
        {
            return element.second < 1;
        });
    }

    void remove_Weapons(Weapon* weapons, int count)
    {
        //Iterate through the items and if they are found then decrease
        //the quantity by the quantity removed
        for(auto& it : this->weapons)
        {
            if(it.first == weapons) it.second -= count;
        }

        //Iterate through the list again, and remove any elements from
        //the list that have zero or less for their quantity
        //Do this in two passes because removing an element from a list
        //during a for loop invalidates the iterators, and the loop
        //stops working
        this->weapons.remove_if([](std::pair<Weapon*, int>&element)
        {
            return element.second < 1;
        });
    }

    void remove_Armor(Armor* armor, int count)
    {
        //Iterate through the items and if they are found then decrease
        //the quantity by the quantity removed
        for(auto& it : this->armor)
        {
            if(it.first == armor) it.second -= count;
        }

        //Iterate through the list again, and remove any elements from
        //the list that have zero or less for their quantity
        //Do this in two passes because removing an element from a list
        //during a for loop invalidates the iterators, and the loop
        //stops working
        this->armor.remove_if([](std::pair<Armor*, int>&element)
        {
            return element.second < 1;
        });
    }

    //Merge the specified inventory with the current one, adding
    //item quantities together if they already exist and adding the item
    //into a new slot if they do not
    void merge(Inventory* inventory)
    {
        //You can't merge an inventory with itself
        if(inventory == this) return;

        //Loop through the items to be added and add them our addition
        //function will take of the rest
        for(auto it : inventory->items)
        {
            this->add_Item(it.first,it.second);
        }
        for(auto it: inventory->weapons)
        {
            this->add_weapons(it.first,it.second);
        }
        for(auto it: inventory->armor)
        {
            this->add_armor(it.first,it.second);
        }

        return;
    }
    //Rmove all items from the iventory, destroying them in the process
    void clear()
    {
        this->items.clear();
        this->weapons.clear();
        this->armor.clear();
    }

    //output a list of the items onto stdout
    int print_items(bool label = false)
	{
		unsigned int i = 1;

		for(auto it : this->items)
		{
			// Number the items if asked
			if(label) std::cout << i++ << ": ";
			// Output the item name, quantity and description, e.g.
			// Gold Piece (29) - Glimmering discs of wealth
			std::cout << it.first->name << " (" << it.second << ") - ";
			std::cout << it.first->description << std::endl;
		}

		// Return the number of items outputted, for convenience
		return this->items.size();
	}

	// Same as for items
	int print_weapons(bool label = false)
	{
		unsigned int i = 1;

		for(auto it : this->weapons)
		{
			if(label) std::cout << i++ << ": ";
			std::cout << it.first->name << " (" << it.second << ") - ";
			std::cout << it.first->description << std::endl;
		}

		return this->weapons.size();
	}

	// Same as for items
	int print_armor(bool label = false)
	{
		unsigned int i = 1;

		for(auto it : this->armor)
		{
			if(label) std::cout << i++ << ": ";
			std::cout << it.first->name << " (" << it.second << ") - ";
			std::cout << it.first->description << std::endl;
		}

		return this->armor.size();
	}

	// Print the entire inventory; items, then weapons, then armour,
	// but if the inventory is empty then output "Nothing"
	void print(bool label = false)
	{
		if(this->items.size() == 0 &&
			this->weapons.size() == 0 &&
			this->armor.size() == 0
			)
		{
			std::cout << "Nothing" << std::endl;
		}
		else
		{
			this->print_items(label);
			this->print_weapons(label);
			this->print_armor(label);

		}

		return;
	}

	    void use(Item* item, int count)
    {

    }

           void add_ability(Ability* ability, int count)
    {

        this->abilities.push_back(std::make_pair(ability, count));

    }

    int print_abiliities(bool label = false)
	{
		unsigned int i = 1;

		for(auto it : this->abilities)
		{
			// Number the items if asked
			if(label) std::cout << i++ << ": ";
			// Output the item name, quantity and description, e.g.
			// Gold Piece (29) - Glimmering discs of wealth
			std::cout << it.first->name << " (" << it.second << ") - ";
			std::cout << it.first->description << std::endl;
		}

		// Return the number of items outputted, for convenience
		return this->abilities.size();
	}

    int print_items_order(bool label = false)
	{
		unsigned int i = 1;

		for(auto it : this->items)
		{
			// Number the items if asked
			if(label) std::cout << i++ << ": ";
			// Output the item name, quantity and description, e.g.
			// Gold Piece (29) - Glimmering discs of wealth
			std::cout << it.first->order << std::endl;
		}

		// Return the number of items outputted, for convenience
		return this->items.size();
	}

	// Same as for items
	int print_weapons_order(bool label = false)
	{
		unsigned int i = 1;

		for(auto it : this->weapons)
		{
			if(label) std::cout << i++ << ": ";
			std::cout << it.first->order << std::endl;
		}

		return this->weapons.size();
	}

	// Same as for items
	int print_armor_order(bool label = false)
	{
		unsigned int i = 1;

		for(auto it : this->armor)
		{
			std::cout << it.first->order << std::endl;
		}

		return this->armor.size();
	}

	// Print the entire inventory; items, then weapons, then armour,
	// but if the inventory is empty then output "Nothing"
	void printorder(bool label = false)
	{
		if(this->items.size() == 0 &&
			this->weapons.size() == 0 &&
			this->armor.size() == 0
			)
		{
			std::cout << "Nothing" << std::endl;
		}
		else
		{
			this->print_items_order(label);
			this->print_weapons_order(label);
			this->print_armor_order(label);

		}
    }
};



#endif // INVENTORY_H_INCLUDED
