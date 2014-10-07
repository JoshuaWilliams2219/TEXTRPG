#ifndef CREATURE_H_INCLUDED
#define CREATURE_H_INCLUDED

#include "inventory.hpp"
#include "weapons.hpp"
#include "armor.hpp"
#include "ability.hpp"
#include "companion.hpp"

#include <cstdlib>
#include <string>

class Creature
{
	public:
		//Name of creature and vocation if it has one
		std::string name;
		std::string className;

		//creature stats reasonable value in parentheses
        int health; //curent hit points (10-1000)
		int maxHealth; //Maximum hit points (10-1000)
		int str; //Strength, determines damage in battle (1-100)
		int end; //Endurance, determines maximum health
		int dex; //Dexterity, determines speed in battle
		int intl; //Intelligence, determines spell power
		int blu; // bludgeoning damage
		int prc; // pierce damage
		int sla; // slashing damage
		int fire; //fire damage
		int ice; //ice damage
		int wat; //water damage
		int thu; //thunder damage
		int win; //wind damage
		int ear;// earth damage
		int lig; // light damage
		int drk; // dark damage
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
		double hitRate; //Modifier to hit chance (1 -15)
		double hitRateUP;
		int loot;
		int status;
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
		int poisonATK;
		int stunATK;
		int curseATK;
		int blindATK;
		int slowATK;
		int hasteATK;
		int sleepATK;
		int frozenATK;
		int burnATK;
		int petrifiedATK;
		int stopATK;
		int fearATK;
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


		//Curent level of creature
		//determines the amount of exp granted on defeat
		//and the amount needed to level up again

		unsigned int level;

		//Current experience, see the levelup() function
		unsigned int exp;

		// Items that the creature possesses
        Inventory inventory;

        // Currently equipped weapon. Used as a pointer to an atlas entry,
        // but not necessary. nullptr denotes that no weapon is equipped
        Weapon* equippedWeapon;

        // Armour currently equipped into each slot
        Armor* equippedArmor[Armor::Slot::N];

        Item* usedItem;

        Ability* currentAbility;

        Companion* currentCompanion;

        Creature(std::string name, int health, int str, int end, int dex,int intl,
                    int blu, int prc,int sla,
                    int fire, int ice, int wat, int thu, int win, int ear, int lig, int drk,
                    int bluRes, int prcRes,int slaRes,
                    int firRes, int iceRes, int watRes, int thuRes, int winRes, int earRes, int ligRes, int drkRes,
                    int status,
                    int poison,	int stun, int curse, int blind, int slow, int haste,
                    int sleep, int frozen, int burn, int petrified,	int stop, int fear,
                    int poisonATK,	int stunATK, int curseATK, int blindATK, int slowATK, int hasteATK,
                    int sleepATK, int frozenATK, int burnATK, int petrifiedATK,	int stopATK, int fearATK,
                    int physATKup, int physDEFup,
                    int eleATKup, int eleDEFup,
                    int bluUP, int prcUP, int slaUP,
                    int fireUP, int iceUP, int watUP, int thuUP, int winUP, int earUP, int ligUP, int drkUP,
                    int bluResUP, int prcResUP,	int slaResUP, int firResUP,	int iceResUP, int watResUP,	int thuResUP, int winResUP, int earResUP, int ligResUP,	int drkResUP,
                    int loot, double hitRate, double hitRateUP,
          unsigned level =1, std::string className = "")
		{
			this->name = name;
			this->health =health;
			this->maxHealth = health;
			this->str = str;
			this->end = end;
			this->dex = dex;
			this->intl = intl;
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
			this->bluUP = bluUP;
			this->prcUP = prcUP;
			this->slaUP = slaUP;
			this->fireUP = fireUP;
			this->iceUP = iceUP;
			this->watUP = watUP;
			this->thuUP = thuUP;
			this->winUP = winUP;
			this->earUP = earUP;
			this->ligUP = ligUP;
			this->drkUP = drkUP;
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
			this->poisonATK = poisonATK;
			this->stunATK = stunATK;
			this->blindATK = blindATK;
			this->curseATK = curseATK;
			this->slowATK = slowATK;
			this->hasteATK = hasteATK;
			this->sleepATK = sleepATK;
			this->frozenATK = frozenATK;
			this->burnATK = burnATK;
			this->petrifiedATK = petrifiedATK;
			this->stopATK = stopATK;
			this->fearATK = fearATK;
			this->hitRate = hitRate;
			this->hitRateUP = hitRateUP;
			this->className = className;
			this->equippedArmor[Armor::Slot::HEAD] = nullptr;
            this->equippedArmor[Armor::Slot::TORSO] = nullptr;
            this->equippedArmor[Armor::Slot::LEGS] = nullptr;
            this->equippedWeapon = nullptr;
			this->currentAbility = nullptr;
			this->usedItem = nullptr;
			this->currentCompanion = nullptr;
			this->level = level;
			this->exp = 0;
			this->loot = loot;
			this->status = status;
		}

    Creature()
	{
		this->equippedArmor[Armor::Slot::HEAD] = nullptr;
		this->equippedArmor[Armor::Slot::TORSO] = nullptr;
		this->equippedArmor[Armor::Slot::LEGS] = nullptr;
		this->equippedWeapon = nullptr;
		this->usedItem = nullptr;
		this->currentAbility = nullptr;
		this->currentCompanion = nullptr;
		this->level = 1;
		this->exp = 0;
	}

// Equip a weapon by setting the equipped weapon pointer. Currently
// a pointless function (simple enough to be rewritten each time)
// but handy if dual wielding is ever added, or shields etc
void equipWeapon(Weapon* weapon)
{
    this->equippedWeapon = weapon;

    return;
}

// Equip the armour into it's correct slot. A slightly more useful
// function!
void equipArmor(Armor* armor)
{
    this->equippedArmor[(int)armor->slot] = armor;

    return;
}

void useItem(Item* item)
{
    this->usedItem = item;

    return;
}

void useAbility(Ability* ability)
{
    this->currentAbility = ability;

    return;
}

void gainCompanion(Companion* companion)
{
    this->currentCompanion = companion;

    return;
}

//Calculates experienc neded to level up
		unsigned int expToLevel(unsigned int level)
		{
			//Exp to level x = 128*x^2
			return 128 * level * level;
		}

		//Level the creature to the next level if it has
		//enough experience,returns true and levels up
		//otherwise returns false

		bool levelUp()
		{
			//get the experience needed for the next level
			//not the current level
			if(this->exp >=expToLevel(this->level+1))
			{
				//advance to the next level
				++level;

				//Variables that will keep track of stat changes
				//as you level up
				unsigned int healthBoost = 0;
				unsigned int strBoost = 0;
				unsigned int endBoost = 0;
				unsigned int dexBoost = 0;

				//Give a large boost to health every third lvel
				if(level % 3 == 0)
				{
					//Randomly boost health but is still influenced
					//by endurance
					healthBoost= 10 +(rand() % 4) + this->end/4;
				}
				else
				{
					healthBoost= this->end / 4;
				}
				//If the creature is a fighter, then favour strength
				//and endurance over dex
				if(this->className == "Fighter")
				{
					strBoost = 1;
					endBoost = 1;
					if(rand() % 2 == 0) dexBoost = 1;
				}
				//if the creature is a rogue, it favors
				//dex over strength
				if(this->className == "Rogue")
				{
					dexBoost= 1;
					endBoost= 1;
					if(rand() %2 == 0) strBoost= 1;
				}

				//Adjust stat values accordingly
				this->maxHealth += healthBoost;
				this->str += strBoost;
				this->dex += dexBoost;
				this->end += endBoost;

				//Tell the user that they leveled up and
				//how their stats changed

				std::cout <<this->name << " grew to level " <<level << "!\n";
				std::cout <<"Health +" << healthBoost << " -> " << this->maxHealth << std::endl;
				std::cout <<"Strength +" << strBoost << " -> " << this->str <<std::endl;
				std::cout <<"Dexterity +" << dexBoost << " -> " << this->dex << std::endl;
				std::cout <<"Endurance +" << endBoost << " -> " << this->end << std::endl;
				std::cout << "------------------------------\n";

				return true;
			}

			return false;
		}

};
#endif /*CREAUTRE_HPP*/
