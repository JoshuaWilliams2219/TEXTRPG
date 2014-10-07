#ifndef ARMOR_H_INCLUDED
#define ARMOR_H_INCLUDED

#include "item.hpp"

#include <string>

//Armor also inherits item properties

class Armor : public Item
{
    public:

    //armor can go into one of three slots and only one piece of
    //armor can occupy each slot at a time. The N is there to
    //quickly retrieve the number of slots, without having to use
    //another variable
    enum Slot {TORSO, HEAD, LEGS, N};

    Slot slot;

    //1-50
        int bluRes; // bludgeoning resistance
        int prcRes; //pierce resistance
        int slaRes; // slash resistance
        int firRes; // fire resistance
        int iceRes;// ice resistance
        int watRes;// water resistance
        int thuRes;// thunder resistance
        int winRes;// wind resistance
        int earRes;//earth resistance
        int ligRes;//light resistance
        int drkRes;//dark resistance
        double hitRateUP;
        int poison;
        int stun;
        int curse;
        int blind;
        int slow;
        int haste;
        int sleep;
        int frozen;
        int burn;
        int petrified;
        int stop;
        int fear;
        int physATKup;
        int physDEFup;
        int eleATKup;
        int eleDEFup;
        int bluUP; // bludgeoning damage
        int prcUP; // pierce damage
        int slaUP; // slashing damage
		int fireUP; //fire damage
		int iceUP; //ice damage
		int watUP; //water damage
		int thuUP; //thunder damage
		int winUP; //wind damage
		int earUP;// earth damage
		int ligUP; // light damage
		int drkUP; // dark damage
		int bluResUP; // bludgeoning resistance
		int prcResUP; //pierce resistance
		int slaResUP; // slash resistance
		int firResUP; // fire resistance
		int iceResUP;// ice resistance
		int watResUP;// water resistance
		int thuResUP;// thunder resistance
		int winResUP;// wind resistance
		int earResUP;//earth resistance
		int ligResUP;//light resistance
		int drkResUP;//dark resistance
        unsigned order;

    //Constructor
    Armor(std::string name,std::string description,
                    int bluRes, int prcRes,int slaRes,
                    int firRes, int iceRes, int watRes, int thuRes, int winRes, int earRes, int ligRes, int drkRes,
                    int poison,	int stun, int curse, int blind, int slow, int haste,
                    int sleep, int frozen, int burn, int petrified,	int stop, int fear,
                    int physATKup, int physDEFup,
                    int eleATKup, int eleDEFup,
                    int bluUP, int prcUP, int slaUP,
                    int fireUP, int iceUP, int watUP, int thuUP, int winUP, int earUP, int ligUP, int drkUP,
                    int bluResUP, int prcResUP,	int slaResUP, int firResUP,	int iceResUP, int watResUP,	int thuResUP, int winResUP, int earResUP, int ligResUP,	int drkResUP,
                    int order, double hitRateUP,
                    Armor::Slot slot) :
        Item(name,description, heal, order)
    {

        this->slot = slot;
        this->bluRes = bluRes;
        this->prcRes = prcRes;
        this->slaRes = slaRes;
        this->firRes = firRes;
        this->iceRes = iceRes;
        this->watRes = watRes;
        this->thuRes = thuRes;
        this->winRes = winRes;
        this->earRes = earRes;
        this->ligRes = ligRes;
        this->drkRes = drkRes;
        this->physATKup = physATKup;
        this->physDEFup = physDEFup;
        this->eleATKup = eleATKup;
        this->eleDEFup = eleDEFup;
        this->bluResUP = bluResUP;
        this->prcResUP = prcResUP;
        this->slaResUP = slaResUP;
        this->firResUP = firResUP;
        this->iceResUP = iceResUP;
        this->watResUP = watResUP;
        this->thuResUP = thuResUP;
        this->winResUP = winResUP;
        this->earResUP = earResUP;
        this->ligResUP = ligResUP;
        this->drkResUP = drkResUP;
        this->poison = poison;
        this->stun = stun;
        this->blind = blind;
        this->curse = curse;
        this->slow = slow;
        this->haste = haste;
        this->sleep = sleep;
        this->frozen = frozen;
        this->burn = burn;
        this->petrified = petrified;
        this->stop = stop;
        this->fear = fear;
        this->order = order;
    }

    Armor()
    {

    }

};

#endif // ARMOR_H_INCLUDED
