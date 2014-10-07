#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <string>

class Item
{
public:


    //Name and description of the item
    std::string name;
    std::string description;

    unsigned heal;
    unsigned order;

    //Standard Constructor
    Item(std::string name, std::string description, int heal, int order)
    {
        this->name = name;
        this->description = description;
        this->heal = heal;
        this->order = order;
    }

     Item()
    {
    }


};

#endif // ITEM_H_INCLUDED
