#ifndef WEAPONS_H_INCLUDED
#define WEAPONS_H_INCLUDED

#include "item.hpp"

#include <string>

//Weapons are items so they should inherit their properties
class Weapon : public Item
{
    public:

        unsigned blu; // bludgeoning damage
		unsigned prc; // pierce damage
		unsigned sla; // slashing damage
		unsigned fire; //fire damage
		unsigned ice; //ice damage
		unsigned wat; //water damage
		unsigned thu; //thunder damage
		unsigned win; //wind damage
		unsigned ear;// earth damage
		unsigned lig; // light damage
		unsigned drk; // dark damage
    //Weapon damage 1-50
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


        //modifier to hit chance, 5%-30$
        double hitRate;
        unsigned order;

    //Pass inherited qualities to the normal item constructor
    Weapon(std::string name,std::string description,
                    int blu, int prc, int sla,
                    int fire, int ice, int wat, int thu, int win, int ear, int lig, int drk,
                    int poison,	int stun, int curse, int blind, int slow, int haste,
                    int sleep, int frozen, int burn, int petrified,	int stop, int fear,
                    int physATKup, int physDEFup,
                    int eleATKup, int eleDEFup,
                    int bluUP, int prcUP, int slaUP,
                    int fireUP, int iceUP, int watUP, int thuUP, int winUP, int earUP, int ligUP, int drkUP,
                    int bluResUP, int prcResUP,	int slaResUP, int firResUP,	int iceResUP, int watResUP,	int thuResUP, int winResUP, int earResUP, int ligResUP,	int drkResUP,
                    int order, double hitRate, double hitRateUP) :
        Item(name,description, heal, order)
    {

            this->blu = blu;
			this->prc = prc;
			this->sla = sla;
			this->fire = fire;
			this->ice = ice;
			this->wat = wat;
			this->thu = thu;
			this->win = win;
			this->ear = ear;
			this->lig = lig;
			this->drk = drk;
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
			this->hitRate = hitRate;    }
   Weapon()
    {

    }
};


#endif // WEAPONS_H_INCLUDED
