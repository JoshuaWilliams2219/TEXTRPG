#ifndef BATTLE_H_INCLUDED
#define BATTLE_H_INCLUDED

#include "dialogue.hpp"
#include "creature.hpp"
#include "armor.hpp"
#include "weapons.hpp"
#include "ability.hpp"
#include "atlas.hpp"
#include <iostream>

class Battle
{
public:




    //Dialogue used to ask the player battle choices
    Dialogue dialogue;

    //Creatures in combat. creatures[0] is the player
    Creature* creatures[2];

    Battle()
    {
    };

    Battle(Creature* player, Creature* b)
    {
        //Start a battle with the player and another creautre
        this->creatures[0] = player;
        this->creatures[1] = b;

        //Set up the dialogue.
        this->dialogue = Dialogue("What will you do?",
                                  {
                                      "Attack",
                                      "Ability",
                                      "Defend"
                                  });
    }



    void playerAttack(Creature* a, Creature* b)
    {
        std::cout << a->name << " attacks!\n";

        //Damage that a will inflict on b
        int damage = 0;

        //Cumulative hitRate
        double hitRate = a->hitRate;

        //If a has equipped a weapon, then add the weapon damage on
        //to the current damage and add the hit rate of the weapon on to
        //the current hit rate
        if(a->equippedWeapon != nullptr)
        {
            damage =
             + a->equippedWeapon->blu
             + a->equippedWeapon->prc
             + a->equippedWeapon->sla
             + a->equippedWeapon->fire
             + a->equippedWeapon->ice
             + a->equippedWeapon->wat
             + a->equippedWeapon->thu
             + a->equippedWeapon->win
             + a->equippedWeapon->ear
             + a->equippedWeapon->lig
             + a->equippedWeapon->drk;
            hitRate += a->equippedWeapon->hitRate;

        }

        if(a->equippedWeapon == nullptr)
        {
            damage =
             + a->blu
             + a->prc
             + a->sla
             + a->fire
             + a->ice
             + a->wat
             + a->thu
             + a->win
             + a->ear
             + a->lig
             + a->drk;

        }


        //Increase the damage by half the attacker's strength
        damage += a->str / 2;


        //Damage the b will block
        int defense = 0;

if(a->equippedWeapon != nullptr)
        {
        if(a->equippedWeapon->blu > 0)
            defense += b->bluRes;
        if(a->equippedWeapon->prc > 0)
            defense += b->prcRes;
        if(a->equippedWeapon->sla > 0)
            defense += b->slaRes;
        if(a->equippedWeapon->fire > 0)
            defense += b->firRes;
        if(a->equippedWeapon->ice > 0)
            defense += b->iceRes;
        if(a->equippedWeapon->wat > 0)
            defense += b->watRes;
        if(a->equippedWeapon->thu > 0)
            defense += b->thuRes;
        if(a->equippedWeapon->win > 0)
            defense += b->winRes;
        if(a->equippedWeapon->ear > 0)
            defense += b->earRes;
        if(a->equippedWeapon->lig > 0)
            defense += b->ligRes;
        if(a->equippedWeapon->drk > 0)
            defense += b->drkRes;
        }

if(a->equippedWeapon == nullptr)
        {
        if(a->blu > 0)
            defense += b->bluRes;
        if(a->prc > 0)
            defense += b->prcRes;
        if(a->sla > 0)
            defense += b->slaRes;
        if(a->fire > 0)
            defense += b->firRes;
        if(a->ice > 0)
            defense += b->iceRes;
        if(a->wat > 0)
            defense += b->watRes;
        if(a->thu > 0)
            defense += b->thuRes;
        if(a->win > 0)
            defense += b->winRes;
        if(a->ear > 0)
            defense += b->earRes;
        if(a->lig > 0)
            defense += b->ligRes;
        if(a->drk > 0)
            defense += b->drkRes;
        }

        //Sum the defense values of the armor that b has equipped and
        //increase the defense by the summed value
        for(int i = 0; i < Armor::Slot::N; ++i)
        {
            if(b->equippedArmor[i] != nullptr)
                {
                if(a->equippedWeapon->blu > 0)
                    defense += b->bluRes;
                if(a->equippedWeapon->prc > 0)
                    defense += b->prcRes;
                if(a->equippedWeapon->sla > 0)
                    defense += b->slaRes;
                if(a->equippedWeapon->fire > 0)
                    defense += b->firRes;
                if(a->equippedWeapon->ice > 0)
                    defense += b->iceRes;
                if(a->equippedWeapon->wat > 0)
                    defense += b->watRes;
                if(a->equippedWeapon->thu > 0)
                    defense += b->thuRes;
                if(a->equippedWeapon->win > 0)
                    defense += b->winRes;
                if(a->equippedWeapon->ear > 0)
                    defense += b->earRes;
                if(a->equippedWeapon->lig > 0)
                    defense += b->ligRes;
                if(a->equippedWeapon->drk > 0)
                    defense += b->drkRes;
                }
        }

        //Decrease the damage by the damage blocked, then sure that
        //damage is always inflicted (we do not want battles to last
        //forever, nor to we want attacks to heal the wounded)

        damage -= defense;
        if(damage < 1) damage = 1;

        //Add the hit rate to the base hit rate and subtract the target's
        //dextrirty from it. Instead of halving it to normalize it into
        //a percentage, we just double the range of rnadomly generated
        //values
        if(rand() % 201 <= 170 + hitRate - b->dex)
           {
               //The attaack hit, so subtract the damage
               std::cout << b->name << " takes "  << damage << " damage!\n";
               b->health -= damage;
               inflictStatus(creatures[0], creatures[1]);

           }
        else
        {
                //The attack missed
                std::cout << a->name << " missed!\n";
        }

        damage = 0;
        return;
    }
    void enemyAttack(Creature* a, Creature* b)
    {
        std::cout << a->name << " attacks!\n";

        //Damage that a will inflict on b
        int damage = 0;

        //Cumulative hitRate
        double hitRate = a->hitRate;

        //If a has equipped a weapon, then add the weapon damage on
        //to the current damage and add the hit rate of the weapon on to
        //the current hit rate
        if(a->equippedWeapon != nullptr)
        {
            damage =
             + a->equippedWeapon->blu
             + a->equippedWeapon->prc
             + a->equippedWeapon->sla
             + a->equippedWeapon->fire
             + a->equippedWeapon->ice
             + a->equippedWeapon->wat
             + a->equippedWeapon->thu
             + a->equippedWeapon->win
             + a->equippedWeapon->ear
             + a->equippedWeapon->lig
             + a->equippedWeapon->drk;
            hitRate += a->equippedWeapon->hitRate;

        }

        if(a->equippedWeapon == nullptr)
        {
            damage =
             + a->blu
             + a->prc
             + a->sla
             + a->fire
             + a->ice
             + a->wat
             + a->thu
             + a->win
             + a->ear
             + a->lig
             + a->drk;

        }

        //Increase the damage by half the attacker's strength
        damage += a->str / 2;


        //Damage the b will block
        int defense = 0;
if(a->equippedWeapon != nullptr)
        {
        if(a->equippedWeapon->blu > 0)
            defense += b->bluRes;
        if(a->equippedWeapon->prc > 0)
            defense += b->prcRes;
        if(a->equippedWeapon->sla > 0)
            defense += b->slaRes;
        if(a->equippedWeapon->fire > 0)
            defense += b->firRes;
        if(a->equippedWeapon->ice > 0)
            defense += b->iceRes;
        if(a->equippedWeapon->wat > 0)
            defense += b->watRes;
        if(a->equippedWeapon->thu > 0)
            defense += b->thuRes;
        if(a->equippedWeapon->win > 0)
            defense += b->winRes;
        if(a->equippedWeapon->ear > 0)
            defense += b->earRes;
        if(a->equippedWeapon->lig > 0)
            defense += b->ligRes;
        if(a->equippedWeapon->drk > 0)
            defense += b->drkRes;
        }

if(a->equippedWeapon == nullptr)
        {
        if(a->blu > 0)
            defense += b->bluRes;
        if(a->prc > 0)
            defense += b->prcRes;
        if(a->sla > 0)
            defense += b->slaRes;
        if(a->fire > 0)
            defense += b->firRes;
        if(a->ice > 0)
            defense += b->iceRes;
        if(a->wat > 0)
            defense += b->watRes;
        if(a->thu > 0)
            defense += b->thuRes;
        if(a->win > 0)
            defense += b->winRes;
        if(a->ear > 0)
            defense += b->earRes;
        if(a->lig > 0)
            defense += b->ligRes;
        if(a->drk > 0)
            defense += b->drkRes;
        }

        //Sum the defense values of the armor that b has equipped and
        //increase the defense by the summed value
        for(int i = 0; i < Armor::Slot::N; ++i)
        {
            if(b->equippedArmor[i] != nullptr)
                {
                    if(a->equippedWeapon != nullptr)
                    {
                if(a->equippedWeapon->blu > 0)
                    defense += b->equippedArmor[i]->bluRes;
                if(a->equippedWeapon->prc > 0)
                    defense += b->equippedArmor[i]->prcRes;
                if(a->equippedWeapon->sla > 0)
                    defense += b->equippedArmor[i]->slaRes;
                if(a->equippedWeapon->fire > 0)
                    defense += b->equippedArmor[i]->firRes;
                if(a->equippedWeapon->ice > 0)
                    defense += b->equippedArmor[i]->iceRes;
                if(a->equippedWeapon->wat > 0)
                    defense += b->equippedArmor[i]->watRes;
                if(a->equippedWeapon->thu > 0)
                    defense += b->equippedArmor[i]->thuRes;
                if(a->equippedWeapon->win > 0)
                    defense += b->equippedArmor[i]->winRes;
                if(a->equippedWeapon->ear > 0)
                    defense += b->equippedArmor[i]->earRes;
                if(a->equippedWeapon->lig > 0)
                    defense += b->equippedArmor[i]->ligRes;
                if(a->equippedWeapon->drk > 0)
                    defense += b->equippedArmor[i]->drkRes;
                    }
                    if(a->equippedWeapon == nullptr)
                    {
                if(a->blu > 0)
                    defense += b->equippedArmor[i]->bluRes;
                if(a->prc > 0)
                    defense += b->equippedArmor[i]->prcRes;
                if(a->sla > 0)
                    defense += b->equippedArmor[i]->slaRes;
                if(a->fire > 0)
                    defense += b->equippedArmor[i]->firRes;
                if(a->ice > 0)
                    defense += b->equippedArmor[i]->iceRes;
                if(a->wat > 0)
                    defense += b->equippedArmor[i]->watRes;
                if(a->thu > 0)
                    defense += b->equippedArmor[i]->thuRes;
                if(a->win > 0)
                    defense += b->equippedArmor[i]->winRes;
                if(a->ear > 0)
                    defense += b->equippedArmor[i]->earRes;
                if(a->lig > 0)
                    defense += b->equippedArmor[i]->ligRes;
                if(a->drk > 0)
                    defense += b->equippedArmor[i]->drkRes;
                    }
                }
        }

        //Decrease the damage by the damage blocked, then sure that
        //damage is always inflicted (we do not want battles to last
        //forever, nor to we want attacks to heal the wounded)

        damage -= defense;
        if(damage < 1) damage = 1;

        //Add the hit rate to the base hit rate and subtract the target's
        //dextrirty from it. Instead of halving it to normalize it into
        //a percentage, we just double the range of rnadomly generated
        //values
        if(rand() % 201 <= 170 + hitRate - b->dex)
           {
               //The attaack hit, so subtract the damage
               std::cout << b->name << " takes "  << damage << " damage!\n";
               b->health -= damage;
               inflictStatus(creatures[1], creatures[0]);

           }
        else
        {
                //The attack missed
                std::cout << a->name << " missed!\n";
        }

        damage = 0;
        return;
    }
void ability(Creature* a, Creature* b)
    {
    if(a->curse == 1)
            {
                std::cout << "You are cursed! You unable to use any abilities!\n";
                return;
            }
        int userInput = 0;

                    //Cannot equip armor if they do not have any
                    //Print a list of the armor and retrieve the amount
                    //of armor in one go
                    int numItems = a->inventory.print_abiliities(true);
                    if(numItems == 0)return;

                    while(!userInput)
                    {
                        //Choose a piece of armor to equip
                        std::cout << "Use which ability?" << std::endl;
                        std::cin >> userInput;
                        //equipment is numbered but stored in a list
                        //so the number must be converted into a list element
                        if(userInput >= 1 && userInput <= numItems)
                        {
                            int i = 1;
                            for(auto it : a->inventory.abilities)
                            {
                                if(i++ == userInput)
                                {
                                    //Equip the armor if it is found
                                    a->useAbility(it.first);
                                    break;
                                }
                            }
                        }
                    }


        std::cout << a->name << " attacks!\n";

        //Damage that a will inflict on b
        int damage = 0;

        //Cumulative hitRate
        double hitRate = a->hitRate;

        //If a has equipped a weapon, then add the weapon damage on
        //to the current damage and add the hit rate of the weapon on to
        //the current hit rate
        if(a->currentAbility != nullptr)
        {
           damage =
             + a->currentAbility->blu
             + a->currentAbility->prc
             + a->currentAbility->sla
             + a->currentAbility->fire
             + a->currentAbility->ice
             + a->currentAbility->wat
             + a->currentAbility->thu
             + a->currentAbility->win
             + a->currentAbility->ear
             + a->currentAbility->lig
             + a->currentAbility->drk;
            hitRate += a->currentAbility->hitRate;
        }

        //Increase the damage by half the attacker's strength
        damage += a->str / 2;

        //Damage the b will block
        int defense = 0;
        if(a->currentAbility != nullptr)
        {
        if(a->currentAbility->blu > 0)
            defense += b->bluRes;
        if(a->currentAbility->prc > 0)
            defense += b->prcRes;
        if(a->currentAbility->sla > 0)
            defense += b->slaRes;
        if(a->currentAbility->fire > 0)
            defense += b->firRes;
        if(a->currentAbility->ice > 0)
            defense += b->iceRes;
        if(a->currentAbility->wat > 0)
            defense += b->watRes;
        if(a->currentAbility->thu > 0)
            defense += b->thuRes;
        if(a->currentAbility->win > 0)
            defense += b->winRes;
        if(a->currentAbility->ear > 0)
            defense += b->earRes;
        if(a->currentAbility->lig > 0)
            defense += b->ligRes;
        if(a->currentAbility->drk > 0)
            defense += b->drkRes;
        }
        //Sum the defense values of the armor that b has equipped and
        //increase the defense by the summed value
        for(int i = 0; i < Armor::Slot::N; ++i)
        {
            if(b->equippedArmor[i] != nullptr)
                {

                if(a->equippedWeapon->blu > 0)
                    defense += b->bluRes;
                if(a->equippedWeapon->prc > 0)
                    defense += b->prcRes;
                if(a->equippedWeapon->sla > 0)
                    defense += b->slaRes;
                if(a->equippedWeapon->fire > 0)
                    defense += b->firRes;
                if(a->equippedWeapon->ice > 0)
                    defense += b->iceRes;
                if(a->equippedWeapon->wat > 0)
                    defense += b->watRes;
                if(a->equippedWeapon->thu > 0)
                    defense += b->thuRes;
                if(a->equippedWeapon->win > 0)
                    defense += b->winRes;
                if(a->equippedWeapon->ear > 0)
                    defense += b->earRes;
                if(a->equippedWeapon->lig > 0)
                    defense += b->ligRes;
                if(a->equippedWeapon->drk > 0)
                    defense += b->drkRes;

                }
        }

        //Decrease the damage by the damage blocked, then sure that
        //damage is always inflicted (we do not want battles to last
        //forever, nor to we want attacks to heal the wounded)

        damage -= defense;
        if(damage < 1) damage = 1;

        //Add the hit rate to the base hit rate and subtract the target's
        //dextrirty from it. Instead of halving it to normalize it into
        //a percentage, we just double the range of rnadomly generated
        //values
        if(rand() % 201 <= 170 + hitRate - b->dex)
           {
               //The attaack hit, so subtract the damage
               std::cout << b->name << " takes "  << damage << " damage!\n";

               b->health -= damage;

           }
        else
        {
                //The attack missed
                std::cout << a->name << " missed!\n";
        }


        a->currentAbility = nullptr;
        return;
    }

    void playerTurn()
    {
        //Activate the dialogue and allow the player to choose their
        //battle option
        int result = this->dialogue.activate();

        switch(result)
        {
            //Attack the enemy
        case 1:
            playerAttack(creatures[0], creatures[1]);
            companionAttack(creatures[0], creatures[1]);
            break;
        case 2:
            ability(creatures[0], creatures[1]);
            companionAttack(creatures[0], creatures[1]);
            break;
        case 3:
            std::cout << creatures[0]->name << " defends!\n";
            break;
        default:
            break;
        }

        return;
    }

    void enemyTurn()
    {
        enemyAttack(creatures[1], creatures[0]);

        return;
    }

    //Return true if the creature is dead. Split into it's own function
    //to allow easy addition of effects which simulate death, such as
    //petrification or banishment
    bool isdead(Creature* creature)
    {
         if(creature->health <= 0)
         {
             return true;
         }
         return false;
    }

    //Run a round of battle
    bool activate()
    {
        //The creature with the highest dexterity attacks first with
        //preference to the player
        if(creatures[0]->dex >= creatures[1]->dex)
        {
            //Run each turn and check if the foe is dead at the end of
            //each
            checkPlayerStatus(creatures[0]);
            this->playerTurn();
            if(isdead(creatures[1]))
            {
                std::cout << creatures[1]->name << " was vanquished!\n";
                return true;
            }

            checkEnemyStatus(creatures[1]);
            this->enemyTurn();
            if(isdead(creatures[0]))
            {
                std::cout << creatures[0]->name << " was vanquished\n";
                return true;
            }
        }
        else
        {
            checkEnemyStatus(creatures[1]);
            this->enemyTurn();
            if(isdead(creatures[0]))
            {
                std::cout << creatures[0]->name << " was vanquished!\n";
                return true;
            }
            checkPlayerStatus(creatures[0]);
            this->playerTurn();
            if(isdead(creatures[1]))
            {
                std::cout << creatures[1]->name << " was vanquished!\n";
                return true;
            }
        }
        return false;
    }

    void run()
    {
        std::cout << creatures[1]->name << " appears!" << std::endl;
        creatures[1]->health = creatures[1]->maxHealth;
        //Run the battle until one creature dies
        while(!this->activate());

        //if the enemy is dead, then allocate experience to the player
        if(isdead(creatures[1]))
        {
            //Reset status counters



            //Give experience to the player equal to one eighth
            //of the experience the enemy gained to reach its
            //next level
                unsigned int expGain =
                creatures[1]->expToLevel(creatures[1]->level+1) / 8;
                std::cout << "Gained " << expGain << " exp!\n";
                creatures[0]->exp += expGain;

                //Repeatedly level up the player until they are the highest level they can be for their experience
                while(creatures[0]->levelUp());
        }

        return;
    }

    void learn(Creature* a, Creature* b)
    {

        std::vector<Ability> combatAtlas;
        buildatlas_combat(combatAtlas);

        int n = rand();
        if(n > 3)
        {
            n = n % 4;
        }
        if(n < 2 )
        {
            int learnAbility = b->loot;
            std::cout << learnAbility << std::endl;
            a->inventory.add_ability(&combatAtlas[1],1);
            std::cout << "You learned " << &combatAtlas[1] << std::endl;
        }

    }

    void battleItem (Creature* a, Creature* b)
    {
        int userInput = 0;

        int numItems = a->inventory.print_items(true);
        if(numItems == 0)return;
        while(!userInput)
        {
            //Choose a piece of armor to equip
            std::cout << "Use which item?" << std::endl;
            std::cin >> userInput;
            //equipment is numbered but stored in a list
            //so the number must be converted into a list element
            if(userInput >= 1 && userInput <= numItems)
            {
                int i = 1;
                for(auto it : a->inventory.items)
                {
                    if(i++ == userInput)
                    {
                        //Equip the armor if it is found
                        a->useItem(it.first);
                        if (a->usedItem->heal == 0)
                        {
                            a->usedItem = nullptr;
                            std::cout << "Not a valid item choice." << std::endl;
                        }
                        else if(a->usedItem->heal > 0)
                        {

                            std::cout << "You are healed for " << a->usedItem->heal << " Hit Points." << std::endl;
                            a->health +=  a->usedItem->heal;
                            if(a->health > a->maxHealth)
                            a->health = a->maxHealth;

                            a->usedItem = nullptr;
                            break;
                        }
                    }
                }
            }
        }
    }


void checkPlayerStatus(Creature* a)
{
    if(a->poison == 1)
        {
        int p = a->maxHealth * .08;
        a->health -= p;
        std::cout << a->name << " lost " << p << " Hit Points!" << std::endl;
        }
    if(a->poison == 2)
        {
        int p = a->maxHealth * .16;
        a->health -= p;
        std::cout << a->name << " lost " << p << " Hit Points!" << std::endl;
        }
    if(a->stun == 1)
        while(a->stun == 1)
              {
               a->stun = 0;
               enemyTurn();
              }
    if(a->curse == 1)
        {

        }
    if(a->blind == 1)
        {
        a->hitRate = a->hitRate / 2;
        }
    if(a->slow == 1)
        {
        a->dex = a->dex * .66;
        }
    if(a->haste == 1)
        {
        a->dex = a->dex * 1.33;
        }
    if(a->sleep == 1)
        {
        int h = a->health;
        while(a->health == h)
            {
                enemyTurn();
            }
        std::cout << a->name << " woke up!" << std::endl;
        }
    if(a->frozen == 1)
        {
        for(int f= 0; f< 3; f++)
        {
            enemyTurn();
        }
        std::cout << a->name << " melted!" << std::endl;
        }
    if(a->burn == 1)
        {
        int b = a->maxHealth * .12;
        a->health -= b;
        std::cout << a->name << " lost " << b << " Hit Points!" << std::endl;
        }
    if(a->petrified == 1)
        {
        a->health = 0;
        std::cout << a->name << " has been turned to stone!" << std::endl;
        }
    if(a->stop == 1)
    {
        for(int f= 0; f < 5; f++)
        {
        enemyTurn();
        }
        std::cout << a->name << " can move again!" << std::endl;
    }
    if(a->fear == 1)
    {
        int g = rand();
        if(g % 2 > 1)
           {
               std::cout << a->name << " is too afraid to move!" << std::endl;
               enemyTurn();
           }
    }
    if(a->bluUP == 1)
        a->blu = a->blu * 1.33;
    if(a->prcUP == 1)
    a->prc = a->prc * 1.33;
    if(a->slaUP == 1)
    a->sla = a->sla * 1.33;
    if(a->fireUP == 1)
    a->fire = a->fire * 1.33;
    if(a->iceUP == 1)
    a->ice = a->ice * 1.33;
    if(a->watUP == 1)
    a->wat = a->wat * 1.33;
    if(a->thuUP == 1)
    a->thu = a->thu * 1.33;
    if(a->winUP == 1)
    a->win = a->win * 1.33;
    if(a->earUP == 1)
    a->ear = a->ear * 1.33;
    if(a->ligUP == 1)
    a->lig = a->lig * 1.33;
    if(a->drkUP == 1)
    a->drk = a->drk * 1.33;
    if(a->bluResUP == 1)
    a->bluRes = a->bluRes * 1.33;
    if(a->prcResUP == 1)
    a->prcRes = a->prcRes * 1.33;
    if(a->slaResUP == 1)
    a->slaRes = a->slaRes * 1.33;
    if(a->firResUP == 1)
    a->firRes = a->firRes * 1.33;
    if(a->iceResUP == 1)
    a->iceRes = a->iceRes * 1.33;
    if(a->watResUP == 1)
    a->watRes = a->watRes * 1.33;
    if(a->watResUP == 1)
    a->watRes = a->watRes * 1.33;
    if(a->winResUP == 1)
    a->winRes = a->winRes * 1.33;
    if(a->earResUP == 1)
    a->earRes = a->earRes * 1.33;
    if(a->ligResUP == 1)
    a->ligRes = a->ligRes * 1.33;
    if(a->drkResUP == 1)
    a->drkRes = a->drkRes * 1.33;


}

void checkEnemyStatus(Creature* a)
{
    if(a->poison == 1)
        {
        int p = a->maxHealth * .08;
        a->health -= p;
        std::cout << a->name << " lost " << p << " Hit Points!" << std::endl;
        }
    if(a->poison == 2)
        {
        int p = a->maxHealth * .16;
        a->health -= p;
        std::cout << a->name << " lost " << p << " Hit Points!" << std::endl;
        }
    if(a->stun == 1)
        while(a->stun == 1)
              {
               a->stun = 0;
               playerTurn();
              }
    if(a->curse == 1)
        {

        }
    if(a->blind == 1)
        {
        a->hitRate = a->hitRate / 2;
        }
    if(a->curse == 1)
    {

    }
    if(a->slow == 1)
        {
        a->dex = a->dex * .66;
        }
    if(a->haste == 1)
        {
        a->dex = a->dex * 1.33;
        }
    if(a->sleep == 1)
        {
        int h = a->health;
        while(a->health == h)
            {
                playerTurn();
            }
        std::cout << a->name << " woke up!" << std::endl;
        }
    if(a->frozen == 1)
        {
        for(int f= 0; f< 3; f++)
        {
            playerTurn();
        }
        std::cout << a->name << " melted!" << std::endl;
        }
    if(a->burn == 1)
        {
        int b = a->maxHealth * .12;
        a->health -= b;
        std::cout << a->name << " lost " << b << " Hit Points!" << std::endl;
        }
    if(a->petrified == 1)
        {
        a->health = 0;
        std::cout << a->name << " has been turned to stone!" << std::endl;
        }
    if(a->stop == 1)
    {
        for(int f= 0; f< 5; f++)
        {
        playerTurn();

        }
        std::cout << a->name << " can move again!" << std::endl;
    }
    if(a->fear == 1)
    {
        int g = rand();
        if(g % 2 > 1)
           {
               std::cout << a->name << " is too afraid to move!" << std::endl;
               playerTurn();
           }
    }
    if(a->bluUP == 1)
        a->blu = a->blu * 1.33;
    if(a->prcUP == 1)
    a->prc = a->prc * 1.33;
    if(a->slaUP == 1)
    a->sla = a->sla * 1.33;
    if(a->fireUP == 1)
    a->fire = a->fire * 1.33;
    if(a->iceUP == 1)
    a->ice = a->ice * 1.33;
    if(a->watUP == 1)
    a->wat = a->wat * 1.33;
    if(a->thuUP == 1)
    a->thu = a->thu * 1.33;
    if(a->winUP == 1)
    a->win = a->win * 1.33;
    if(a->earUP == 1)
    a->ear = a->ear * 1.33;
    if(a->ligUP == 1)
    a->lig = a->lig * 1.33;
    if(a->drkUP == 1)
    a->drk = a->drk * 1.33;
    if(a->bluResUP == 1)
    a->bluRes = a->bluRes * 1.33;
    if(a->prcResUP == 1)
    a->prcRes = a->prcRes * 1.33;
    if(a->slaResUP == 1)
    a->slaRes = a->slaRes * 1.33;
    if(a->firResUP == 1)
    a->firRes = a->firRes * 1.33;
    if(a->iceResUP == 1)
    a->iceRes = a->iceRes * 1.33;
    if(a->watResUP == 1)
    a->watRes = a->watRes * 1.33;
    if(a->watResUP == 1)
    a->watRes = a->watRes * 1.33;
    if(a->winResUP == 1)
    a->winRes = a->winRes * 1.33;
    if(a->earResUP == 1)
    a->earRes = a->earRes * 1.33;
    if(a->ligResUP == 1)
    a->ligRes = a->ligRes * 1.33;
    if(a->drkResUP == 1)
    a->drkRes = a->drkRes * 1.33;


}

void inflictStatus(Creature* a, Creature* b)
{
    if(a->equippedWeapon != nullptr)
    {
        if(a->equippedWeapon->poison == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->poison = 1;
                std::cout << b->name << " is poisoned!" << std::endl;
            }
        }
        if(a->equippedWeapon->stun == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->stun = 1;
                std::cout << b->name << " is stunned!" << std::endl;
            }

        }
        if(a->equippedWeapon->blind == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->blind = 1;
                std::cout << b->name << " is blinded!" << std::endl;
            }

        }
        if(a->equippedWeapon->curse == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->stun = 1;
                std::cout << b->name << " is cursed!" << std::endl;
            }

        }
        if(a->equippedWeapon->slow == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->slow = 1;
                std::cout << b->name << " is slowed!" << std::endl;
            }

        }


        if(a->equippedWeapon->sleep == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->sleep = 1;
                std::cout << b->name << " is sleeping!" << std::endl;
            }

        }
        if(a->equippedWeapon->frozen == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->frozen = 1;
                std::cout << b->name << " is frozen!" << std::endl;
            }

        }
        if(a->equippedWeapon->burn == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->burn = 1;
                std::cout << b->name << " is burned!" << std::endl;
            }

        }
        if(a->equippedWeapon->petrified == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->petrified = 1;
                std::cout << b->name << " is petrified!" << std::endl;
            }

        }
        if(a->equippedWeapon->stop == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->stop = 1;
                std::cout << b->name << " is stopped!" << std::endl;
            }

        }
        if(a->equippedWeapon->fear == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->fear = 1;
                std::cout << b->name << " is feared!" << std::endl;
            }

        }

    }
if(a->poisonATK == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->poison = 1;
                std::cout << b->name << " is poisoned!" << std::endl;
            }
        }
        if(a->stunATK == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->stun = 1;
                std::cout << b->name << " is stunned!" << std::endl;
            }

        }
        if(a->blindATK == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->blind = 1;
                std::cout << b->name << " is blinded!" << std::endl;
            }

        }
        if(a->curseATK == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->stun = 1;
                std::cout << b->name << " is cursed!" << std::endl;
            }

        }
        if(a->slowATK == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->slow = 1;
                std::cout << b->name << " is slowed!" << std::endl;
            }

        }


        if(a->sleepATK == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->sleep = 1;
                std::cout << b->name << " is sleeping!" << std::endl;
            }

        }
        if(a->frozenATK == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->frozen = 1;
                std::cout << b->name << " is frozen!" << std::endl;
            }

        }
        if(a->burnATK == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->burn = 1;
                std::cout << b->name << " is burned!" << std::endl;
            }

        }
        if(a->petrifiedATK == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->petrified = 1;
                std::cout << b->name << " is petrified!" << std::endl;
            }

        }
        if(a->stopATK == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->stop = 1;
                std::cout << b->name << " is stopped!" << std::endl;
            }

        }
        if(a->fearATK == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->fear = 1;
                std::cout << b->name << " is feared!" << std::endl;
            }
        }

}

void companionAttack(Creature* a, Creature* b)
    {

        if(a->currentCompanion != nullptr)
        {
        std::cout << a->currentCompanion->name << " attacks!\n";

        //Damage that a will inflict on b
        int damage = 0;

        //Cumulative hitRate
        double hitRate = a->hitRate;

        //If a has equipped a weapon, then add the weapon damage on
        //to the current damage and add the hit rate of the weapon on to
        //the current hit rate
        damage =
             + a->currentCompanion->blu
             + a->currentCompanion->prc
             + a->currentCompanion->sla
             + a->currentCompanion->fire
             + a->currentCompanion->ice
             + a->currentCompanion->wat
             + a->currentCompanion->thu
             + a->currentCompanion->win
             + a->currentCompanion->ear
             + a->currentCompanion->lig
             + a->currentCompanion->drk;
            hitRate = a->currentCompanion->hitRate;


        //Increase the damage by half the attacker's strengthcurrentCompanion

        //Damage the b will block
        int defense = 0;

        if(a->currentCompanion->blu > 0)
            defense += b->bluRes;
        if(a->currentCompanion->prc > 0)
            defense += b->prcRes;
        if(a->currentCompanion->sla > 0)
            defense += b->slaRes;
        if(a->currentCompanion->fire > 0)
            defense += b->firRes;
        if(a->currentCompanion->ice > 0)
            defense += b->iceRes;
        if(a->currentCompanion->wat > 0)
            defense += b->watRes;
        if(a->currentCompanion->thu > 0)
            defense += b->thuRes;
        if(a->currentCompanion->win > 0)
            defense += b->winRes;
        if(a->currentCompanion->ear > 0)
            defense += b->earRes;
        if(a->currentCompanion->lig > 0)
            defense += b->ligRes;
        if(a->currentCompanion->drk > 0)
            defense += b->drkRes;

        //Sum the defense values of the armor that b has equipped and
        //increase the defense by the summed value


        //Decrease the damage by the damage blocked, then sure that
        //damage is always inflicted (we do not want battles to last
        //forever, nor to we want attacks to heal the wounded)

        damage -= defense;
        if(damage < 1) damage = 1;

        //Add the hit rate to the base hit rate and subtract the target's
        //dextrirty from it. Instead of halving it to normalize it into
        //a percentage, we just double the range of rnadomly generated
        //values
        if(rand() % 201 <= 170 + hitRate - b->dex)
           {
               //The attaack hit, so subtract the damage
               std::cout << b->name << " takes "  << damage << " damage!\n";
               inflictCompanionStatus(creatures[0], creatures[1]);
               b->health -= damage;

           }
        else
        {
                //The attack missed
                std::cout << a->currentCompanion->name << " missed!\n";
        }
    }
        return;
    }


void inflictCompanionStatus(Creature* a, Creature* b)
{
    if(a->currentCompanion != nullptr)
    {
        if(a->currentCompanion->poison == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->poison = 1;
                std::cout << b->name << " is poisoned!" << std::endl;
            }
        }
        if(a->currentCompanion->stun == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->stun = 1;
                std::cout << b->name << " is stunned!" << std::endl;
            }

        }
        if(a->currentCompanion->blind == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->blind = 1;
                std::cout << b->name << " is blinded!" << std::endl;
            }

        }
        if(a->currentCompanion->curse == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->stun = 1;
                std::cout << b->name << " is cursed!" << std::endl;
            }

        }
        if(a->currentCompanion->slow == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->slow = 1;
                std::cout << b->name << " is slowed!" << std::endl;
            }

        }


        if(a->currentCompanion->sleep == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->sleep = 1;
                std::cout << b->name << " is sleeping!" << std::endl;
            }

        }
        if(a->currentCompanion->frozen == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->frozen = 1;
                std::cout << b->name << " is frozen!" << std::endl;
            }

        }
        if(a->currentCompanion->burn == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->burn = 1;
                std::cout << b->name << " is burned!" << std::endl;
            }

        }
        if(a->currentCompanion->petrified == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->petrified = 1;
                std::cout << b->name << " is petrified!" << std::endl;
            }

        }
        if(a->currentCompanion->stop == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->stop = 1;
                std::cout << b->name << " is stopped!" << std::endl;
            }

        }
        if(a->currentCompanion->fear == 1)
        {
            int n = rand();
            if(n % 100 > 74)
            {
                b->fear = 1;
                std::cout << b->name << " is feared!" << std::endl;
            }

        }

    }



}


};

#endif // BATTLE_H_INCLUDED
