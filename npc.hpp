#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <string>

class NPC
{
    public:

        std::string name;
        unsigned affection;


        NPC(int affection, std::string name)
        {
            this->name = name;
            this->affection = affection;
        }

        NPC()
        {
        }
};

#endif // NPC_H_INCLUDED
