// RPG.cpp : main project file.

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>

#include "atlas.hpp"
#include "dialogue.hpp"
#include "creature.hpp"
#include "item.hpp"
#include "weapons.hpp"
#include "armor.hpp"
#include "inventory.hpp"
#include "battle.hpp"
#include "ability.hpp"
#include "npc.hpp"
#include "companion.hpp"
using namespace std;


Creature dialogue_newchar();


int main(void)
{

    std::vector<Creature> creatureAtlas;
    std::vector<Item> itemAtlas;
    std::vector<Weapon> weaponAtlas;
    std::vector<Armor> armorAtlas;
    std::vector<Ability> abilityAtlas;
    std::vector<Companion> companionAtlas;

    Creature player;

/////////////NPC Declarations/////////////////////////////////////////////
    NPC horace;
    horace.name = "Horace";
    horace.affection = 0;


////////////////////////////////// Build the atlases//////////////////////////////////////////////////////
    buildatlas_creature(creatureAtlas);
    buildatlas_item(itemAtlas);
    buildatlas_weapon(weaponAtlas);
    buildatlas_armor(armorAtlas);
    buildatlas_ability(abilityAtlas);
    buildatlas_companion(companionAtlas);

    srand(time(NULL));

   int result = Dialogue(
		"Welcome!",
		{"New Game","Load Game"}).activate();
    switch(result)
        {
        case 1: player = dialogue_newchar();
        player.inventory.add_ability(&abilityAtlas[0],1);
        player.inventory.add_weapons(&weaponAtlas[0],1);
        player.inventory.add_armor(&armorAtlas[0],1);
        break;
        case 2:
        {
    std::string line;
    int order;
    std::string count;
    int cnt;
    std::string loadFileName;
    std::string wep;
    int weap;
    std::string armH;
    int arH;
    std::string armT;
    int arT;
    std::string armL;
    int arL;
    std::string comp;
    int cmp;
    std::cout << "Enter the name of the file" << std::endl;
    std::cin >> loadFileName;
    std::ifstream loadFile(loadFileName);

    while(loadFile.is_open())
    {
            loadFile >> player.name;
            loadFile >> player.className;
            loadFile >> player.maxHealth;
            loadFile >>player.health;
            loadFile >>player.level;
            loadFile >> player.exp;
            loadFile >>player.str;
            loadFile >>player.end;
            loadFile >>player.dex;
            loadFile >>player.intl;
            loadFile >> wep;
            if(wep != "0000")
            {
            line = wep;
            weap = std::stoi(line);
            player.inventory.add_weapons(&weaponAtlas[weap],1);
                for(auto it : player.inventory.weapons)
                                {
                                player.equipWeapon(it.first);
                                }
            }
            else
            {
            player.equippedWeapon = nullptr;
            }
            loadFile >> armH;
            if( armH != "0000")
            {
            line = armH;
            arH = std::stoi(line);
            player.inventory.add_armor(&armorAtlas[arH],1);
            for(auto it : player.inventory.armor)
                                {
                                player.equipArmor(it.first);
                                }
            }
            else
            {
            player.equippedArmor[Armor::Slot::HEAD] = nullptr;
            }
            loadFile >> armT;
            if(armT != "0000")
            {
            line = armT;
            arT = std::stoi(line);
            player.inventory.add_armor(&armorAtlas[arT],1);
            for(auto it : player.inventory.armor)
                                {
                                player.equipArmor(it.first);
                                }
            }
            else
            {
            player.equippedArmor[Armor::Slot::TORSO] = nullptr;
            }
            loadFile >> armL;
            if(armL != "0000")
            {
            line = armL;
            arL = std::stoi(line);
            player.inventory.add_armor(&armorAtlas[arL],1);
            for(auto it : player.inventory.armor)
                                {
                                player.equipArmor(it.first);
                                }
            }
            else
            {
            player.equippedArmor[Armor::Slot::LEGS] = nullptr;
            }
            loadFile >> comp;
            if(comp != "0000")
            {
            line = comp;
            cmp = std::stoi(line);
            player.currentCompanion = &companionAtlas[cmp];
            }
            else
            {
            player.currentCompanion = nullptr;
            }
            while(true)
                {
                loadFile >> line;

                if(line!= "0000")
                    {
                    if(line == "$")
                        {
                        break;
                        }
                    loadFile >> count;
                    order = std::stoi(line);
                    cnt = std::stoi(count);
                    player.inventory.add_Item(&itemAtlas[order],cnt);
                    }
                else
                   break;
                }
                while(true)
                {
                loadFile >> line;

                if(line!= "0000")
                    {
                    if(line == "$")
                        {
                        if(player.equippedWeapon != nullptr)
                        {
                        int j;
                        j = player.equippedWeapon->order;
                        player.inventory.remove_Weapons(&weaponAtlas[j],1);
                        }
                        break;
                        }
                    loadFile >> count;
                    order = std::stoi(line);
                    cnt = std::stoi(count);
                    player.inventory.add_weapons(&weaponAtlas[order],cnt);
                    }
                else
                    break;
                }
                while(true)
                {
                loadFile >> line;

                if(line!= "0000")
                    {
                    if(line == "$")
                        {
                        if(player.equippedArmor[Armor::Slot::HEAD] != nullptr)
                        {
                        int j;
                        j = player.equippedArmor[Armor::Slot::HEAD]->order;
                        player.inventory.remove_Armor(&armorAtlas[j],1);
                        }
                        if(player.equippedArmor[Armor::Slot::TORSO] != nullptr)
                        {
                        int j;
                        j = player.equippedArmor[Armor::Slot::TORSO]->order;
                        player.inventory.remove_Armor(&armorAtlas[j],1);
                        }
                        if(player.equippedArmor[Armor::Slot::LEGS] != nullptr)
                        {
                        int j;
                        j = player.equippedArmor[Armor::Slot::LEGS]->order;
                        player.inventory.remove_Armor(&armorAtlas[j],1);
                        }
                        break;
                        }
                    loadFile >> count;
                    order = std::stoi(line);
                    cnt = std::stoi(count);
                    player.inventory.add_armor(&armorAtlas[order],cnt);
                    }
                else
                    break;
                }
                while(true)
                {
                loadFile >> line;

                if(line!= "0000")
                    {
                    if(line == "$")
                        {
                        break;
                        }
                    order = std::stoi(line);
                    player.inventory.add_ability(&abilityAtlas[order],1);
                    }
                else
                    break;
                }
            player.blu = 0;
			player.prc = 0;
			player.sla = 0;
			player.fire = 0;
			player.ice = 0;
			player.wat = 0;
			player.thu = 0;
			player.win = 0;
			player.ear = 0;
			player.lig = 0;
			player.drk = 0;
			player.bluRes = 0;
			player.prcRes = 0;
			player.slaRes = 0;
			player.firRes = 0;
			player.iceRes = 0;
			player.watRes = 0;
			player.thuRes = 0;
			player.winRes = 0;
			player.earRes = 0;
			player.ligRes = 0;
			player.drkRes = 0;
			player.bluUP = 0;
			player.prcUP = 0;
			player.slaUP = 0;
			player.fireUP = 0;
			player.iceUP = 0;
			player.watUP = 0;
			player.thuUP = 0;
			player.winUP = 0;
			player.earUP = 0;
			player.ligUP = 0;
			player.drkUP = 0;
			player.physATKup = 0;
			player.physDEFup = 0;
			player.eleATKup = 0;
			player.eleDEFup = 0;
			player.bluResUP = 0;
			player.prcResUP = 0;
			player.slaResUP = 0;
			player.firResUP = 0;
			player.iceResUP = 0;
			player.watResUP = 0;
			player.thuResUP = 0;
			player.winResUP = 0;
			player.earResUP = 0;
			player.ligResUP = 0;
			player.drkResUP = 0;
			player.poison = 0;
			player.stun = 0;
			player.blind = 0;
			player.curse = 0;
			player.slow = 0;
			player.haste = 0;
			player.sleep = 0;
			player.frozen = 0;
			player.burn = 0;
			player.petrified = 0;
			player.stop = 0;
			player.fear = 0;
			player.poisonATK = 0;
			player.stunATK = 0;
			player.blindATK = 0;
			player.curseATK = 0;
			player.slowATK = 0;
			player.hasteATK = 0;
			player.sleepATK = 0;
			player.frozenATK = 0;
			player.burnATK = 0;
			player.petrifiedATK = 0;
			player.stopATK = 0;
			player.fearATK = 0;
			player.hitRate = 0;
			player.hitRateUP = 0;
            player.loot = 0;
			player.status = 0;
			loadFile >> line;
            horace.affection = std::stoi(line);
			break;
        }
        break;
        }
        default: return 0; break;
        }

    while(1)
        {	//If the player has died then inform them as such and close
            //the program
        if (player.health <= 0)
            {
            std::cout << "\t----YOU DIED----\n";
            player.health = player.maxHealth / 2;
            }

        result = Dialogue(
        "Menu\n====",
        {"Items","Equipment","Character","Abilities","Explore", "Location", "People", "Quit"}).activate();
    switch(result)
	    {
	        //Print the items the player owns
        case 1:
            {
            std::cout <<"Items\n=====\n";
            player.inventory.print();
            std::cout << "---------------\n";
            int userInput = 0;

            //Cannot equip armor if they do not have any
            //Print a list of the armor and retrieve the amount
            //of armor in one go
            int numItems = player.inventory.print_items(true);
            if(numItems == 0)break;
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
                    for(auto it : player.inventory.items)
                        {
                        if(i++ == userInput)
                            {
                                //Equip the armor if it is found
                                player.useItem(it.first);
                                if (player.usedItem->heal == 0)
                                    {
                                    player.usedItem = nullptr;
                                    std::cout << "Not a valid item choice." << std::endl;
                                    }
                                else if(player.usedItem->heal > 0)
                                {

                                std::cout << "You are healed for " << player.usedItem->heal << " Hit Points." << std::endl;
                                player.health +=  player.usedItem->heal;
                                if(player.health > player.maxHealth)
                                player.health = player.maxHealth;
                                player.inventory.remove_Item(&itemAtlas[player.usedItem->order],1);
                                player.usedItem = nullptr;
                                break;
                                }

                            }




                        }
                    }
            }

             break;
            }
	    //Print the equipment that the player is wearing (if they are
        //wearing anything) and then ask if hey want to equip a weapon
        //or some armor
        case 2:
            {
             std::cout << "Equipment\n=========\n";
             std::cout << "Head: "
             << (player.equippedArmor[Armor::Slot::HEAD] != nullptr ?
                 player.equippedArmor[Armor::Slot::HEAD]->name : "Nothing")
                 <<std::endl;
             std::cout << "Torso: "
             << (player.equippedArmor[Armor::Slot::TORSO] != nullptr ?
                 player.equippedArmor[Armor::Slot::TORSO]->name : "Nothing")
                 <<std::endl;
             std::cout << "Legs: "
             << (player.equippedArmor[Armor::Slot::LEGS] != nullptr ?
                 player.equippedArmor[Armor::Slot::LEGS]->name : "Nothing")
                 <<std::endl;
             std::cout << "Weapon: "
             <<  (player.equippedWeapon != nullptr  ?
                  player.equippedWeapon->name : "Nothing")
                  << std::endl;

             int result2=Dialogue(" ",{"Equip Armor","Equip Weapon", "Close"}).activate();
                //Equipping armor
                if(result2==1)
                    {
                    int userInput = 0;
                    //Cannot equip armor if they do not have any
                    //Print a list of the armor and retrieve the amount
                    //of armor in one go
                    int numItems = player.inventory.print_armor(true);
                    if(numItems == 0)break;

                    while(!userInput)
                        {
                        //Choose a piece of armor to equip
                        std::cout << "Equip which item?" << std::endl;
                        std::cin >> userInput;
                        //equipment is numbered but stored in a list
                        //so the number must be converted into a list element
                        if(userInput >= 1 && userInput <= numItems)
                            {
                            int i = 1;
                            for(auto it : player.inventory.armor)
                                {
                                if(i++ == userInput)
                                    {
                                    //Equip the armor if it is found
                                    player.equipArmor(it.first);
                                    break;
                                    }
                                }
                            }
                        }
                    }
                //Equip a weapon, using the same algorithms as for armor
                if(result2==2)
                {
                    int userInput = 0;

                    //Cannot equip armor if they do not have any
                    //Print a list of the armor and retrieve the amount
                    //of armor in one go
                    int numItems = player.inventory.print_weapons(true);
                    if(numItems == 0)break;

                    while(!userInput)
                    {
                        //Choose a piece of armor to equip
                        std::cout << "Equip which item?" << std::endl;
                        std::cin >> userInput;
                        //equipment is numbered but stored in a list
                        //so the number must be converted into a list element
                        if(userInput >= 1 && userInput <= numItems)
                        {
                            int i = 1;
                            for(auto it : player.inventory.weapons)
                            {
                                if(i++ == userInput)
                                {
                                    //Equip the armor if it is found
                                    player.equipWeapon(it.first);
                                    break;
                                }
                            }
                        }
                    }
                 }
                std::cout << "----------------\n";
                break;
            }
            // Output the character information, including name, class (if
            // they have one), stats, level, and experience
            case 3:
                {
                std::cout << "Character\n=========\n";
                std::cout << player.name;
                if(player.className != "") std::cout << " the " << player.className;
                std::cout << std::endl;

                std::cout << "HP: " << player.health << " / " << player.maxHealth << std::endl;
                std::cout << "Str: " << player.str << std::endl;
                std::cout << "End: " << player.end << std::endl;
                std::cout << "Dex: " << player.dex << std::endl;
                std::cout << "Int: " << player.intl << std::endl;
                if(player.equippedWeapon != nullptr)
                {
                std::cout << "Bludgeoning: " << player.equippedWeapon->blu << std::endl;
                std::cout << "Piercing: " << player.equippedWeapon->prc << std::endl;
                std::cout << "Slash: " << player.equippedWeapon->sla << std::endl;
                std::cout << "Fire: " << player.equippedWeapon->fire << std::endl;
                std::cout << "Ice: " << player.equippedWeapon->ice << std::endl;
                std::cout << "Water: " << player.equippedWeapon->wat << std::endl;
                std::cout << "Thunder: " << player.equippedWeapon->thu << std::endl;
                std::cout << "Wind: " << player.equippedWeapon->win << std::endl;
                std::cout << "Earth: " << player.equippedWeapon->ear << std::endl;
                std::cout << "Light: " << player.equippedWeapon->lig << std::endl;
                std::cout << "Dark: " << player.equippedWeapon->drk << std::endl;
                }
                if(player.currentCompanion != nullptr)
                {
                    std::cout << "Companion: " << player.currentCompanion->name << std::endl;
                }
                std::cout << "Lvl: " << player.level << " (" << player.exp;
                std::cout <<  " / " << player.expToLevel(player.level+1) << ")" << std::endl;
                std::cout << "----------------\n";

                break;
                }
         case 4:
         player.inventory.print_abiliities(true);
         break;
/////////////////////////////////////////START OF EXPLORATION/////////////////////////////////////////////////////////
            case 5:
                {
                int result= Dialogue("Which area would you like to explore?",{
                                    "Woods",
                                    "Cave",
                                    "Riverside"}).activate();
                switch(result)
                    {
                    case 1:
                      {
////////////////////////////////////////START FOREST EXPLORATION///////////////////////////////////////////////////
                      int result= Dialogue("You enter the forest. What do you do?",{"Go Deeper","Return"}).activate();
                      switch(result)
                        {
                        case 1:
                        {
//////////////////////////////////////////START FOREST EVENTS///////////////////////////////////////////////////////////////
                            int n;
                            n = rand();
                            n = n % 100;
                            if(n <= 9)
                                {
////////////////////////////////////////////START OF COLOR FLOWER///////////////////////////////////////////////////////////////
                                std::cout << "Making your way through the maze of roots and large plants";
                                std::cout << "you notice a [color] flower. It's vibrant colors stand out" ;
                                std::cout << "from the rest of the flora in the area." << std::endl;

                                int result = Dialogue(
                                    "What do you do?",
                                    {"Eat it", "Take it" "Leave it"}).activate();

                                switch(result)
                                {
                                case 1:
                                    std::cout << "You consume the flower in one bite." << std::endl;
                                break;
                                case 2:
                                    std::cout << "You pluck the flower by the stem and put it away." << std::endl;
                                break;
                                case 3:
                                    std::cout <<"You decide to leave the flower alone and return to camp" << std::endl;
                                break;
                                default:
                                break;
                                }

/////////////////////////////////////////////END OF COLOR FLOWER ///////////////////////////////////////////////////////////////
                                break;
                                }
                            else if(n >= 10 && n<= 19)
                                {
////////////////////////////////////START GOBLIN FIGHT/////////////////////////////////////////////////////////////////
                                    std::cout << "The thick branches and flora make it hard to see ahead.";
                                    std::cout << "Finally making your way through, you see goblin.";
                                    std::cout << "It shrieks as it rushes towards you." << std::endl;

                                    Battle(&player, &creatureAtlas[1]).run();
////////////////////////////////////LOOT CHANCE////////////////////////////////////////////////////////////////////////
                                    int n;
                                    n = rand();
                                    if(n > 2)
                                        {
                                        n = n % 3;
                                        };
                                    if(n==1)
                                    {
                                        player.inventory.add_Item(&itemAtlas[0],5);
                                        std::cout << "You found 5 Gold Coins" << std::endl;
                                        break;
                                    }
                                    break;
                                }
                            else if(n >= 20 && n<= 29)
                                {
////////////////////////////////////////////START OF ///////////////////////////////////////////////////////////////
                                std::cout << "A calming walk through the woods calms your nerves and your hunger." << std::endl;
                                break;

////////////////////////////////////////////END OF ///////////////////////////////////////////////////////////////
                                }
                            else if(n >= 30 && n<= 39)
                                {
////////////////////////////////////////////START OF ///////////////////////////////////////////////////////////////
                                std::cout << "The smell of death quickly invades into your nose.";
                                std::cout << "Nearby is a half-eaten carcass of a dead deer.";
                                std::cout << "It doesn't seem that it's been here for too long either." << std::endl;

                                int result = Dialogue(
                                    "What do you do?",
                                    {"Eat it", "Take the meat with you", "Leave it"}).activate();

                                switch(result)
                                {
                                case 1:
                                std::cout << "Half-eaten means there's still of it left. You sit down next to it";
                                std::cout << "and tear large pieces of fur and muscle with your teeth.";
                                std::cout << "With enough time you finish, bones, entrails and all.";
                                break;
                                case 2:
                                    if (player.equippedWeapon != nullptr)
                                        {
                                        if(player.equippedWeapon->sla > 0)
                                            {
                                            std::cout << "You take your " << player.equippedWeapon->name << " and carve";
                                            std::cout << " a decent amount of meat off to eat later." << std::endl;
                                            }
                                        }
                                else
                                    {
                                    std::cout << "You want to take some of it back, but you have nothing to cut ";
                                    std::cout << "it with. So you give up on the task." <<std::endl;
                                    }
                                break;
                                default:
                                break;
                                }
////////////////////////////////////////////END OF ///////////////////////////////////////////////////////////////
                                }
                            else if(n >= 40 && n<= 49)
                                {
////////////////////////////////////////////START OF ///////////////////////////////////////////////////////////////
                                std::cout << "You come across a winding path covered by a tangle of vines and thorns." <<std::endl;
                                int result = Dialogue(
                                    "What do you do?",
                                    {"Clear the way", "Try to slip through", "Leave"}).activate();

                                switch(result)
                                {
                                case 1:
                                if (player.equippedWeapon != nullptr)
                                        {
                                        if(player.equippedWeapon->sla > 0)
                                            {
                                            std::cout << "You take your " << player.equippedWeapon->name << " and cut";
                                            std::cout << " your waay through the bramble" << std::endl;
                                            }
                                        }
                                else
                                    {
                                    std::cout << "You want to clear the way, but you have nothing to cut ";
                                    std::cout << "it with. So you give up on the task." <<std::endl;
                                    }
                                break;
                                case 2:
                                    if(rand() % 201 <= 150 + player.dex)
                                    {
                                    std::cout << "You slip through the bramble without hurting yourself" <<std::endl;
                                    }
                                    else
                                    {
                                    std::cout << "You get caught up and tangled in the thorns and vines";
                                    std::cout << "You take 5 damage and head back empty handed."<<std::endl;
                                    }
                                break;
                                case 3:
                                std::cout<< "You decide to not bother with the bramble and head back." <<std::endl;
                                default:
                                break;
                                }
////////////////////////////////////////////END OF ///////////////////////////////////////////////////////////////
                                }
                            else if(n >= 50 && n<= 59)
                                {
 ////////////////////////////////////////////START OF ///////////////////////////////////////////////////////////////
                                std::cout << "A sweet smell wafts through the area. You feel drawn to follow it." <<std::endl;
                                 int result = Dialogue(
                                    "What do you do?",
                                    {"Follow it", "Leave"}).activate();

                                switch(result)
                                {
                                case 1:
                                    if(rand() % 201 <= 150 + player.dex)
                                    {
                                    std::cout << "You follow the scent carefully and find a trail of giant bees";
                                    std::cout << "At the end of it you see a large brown bear eating the spoils of war.";
                                    }
                                    else
                                    {
                                    std::cout << "You follow the scent enrapture by the heavenly scent.";
                                    std::cout << "You find a bear covered in honey is the source of the smell";
                                    std::cout << "And it doesn't seem happy to see you!" << std::endl;
                                    Battle(&player, &creatureAtlas[18]).run();
                                    }
                                break;
                                default:
                                break;
                                }
 ////////////////////////////////////////////END OF ///////////////////////////////////////////////////////////////
                                }
                            else if(n >= 60 && n<= 69)
                                {
 ////////////////////////////////////////////START OF ///////////////////////////////////////////////////////////////
                                std::cout << "You hear the sound of running water. Excited to find such an important resource, ";
                                std::cout << "you rush towards the sound. A wide river flows vigorously through the woods.";
                                std::cout << "There's a large enough clearing around the river to walk along for seemingly forever." << std::endl;

                                std::cout << "\n You discovered the Riverside" << std::endl;

 ////////////////////////////////////////////END OF ///////////////////////////////////////////////////////////////
                                }
                                else if(n >= 70 && n<= 79)
                                {
 ////////////////////////////////////////////START OF ///////////////////////////////////////////////////////////////
                                std::cout << "You hear the sound of something running through the woods.";
                                std::cout << "And it's coming your way!" << std::endl;

                                int result = Dialogue(
                                    "What do you do?",
                                    {"Stand your ground", "Run away"}).activate();

                                switch(result)
                                {
                                case 1:
                                std::cout << "A wild boar comes crashing through and its hurtling towards you!";
                                Battle(&player, &creatureAtlas[17]).run();
                                break;
                                case 2:
                                std::cout << "You flee until you can't hear the noise anymore. But by then, you're already back at camp" <<std::endl;
                                default:
                                break;
                                }
 ////////////////////////////////////////////END OF ///////////////////////////////////////////////////////////////
                                }
                            else if(n >= 80 && n<= 89)
                                {
 ////////////////////////////////////////////START OF ///////////////////////////////////////////////////////////////
                                std::cout << "A hut with smoke coming out of the chimney stands in the distance." << std::endl;

                                int result = Dialogue(
                                    "What do you do?",
                                    {"Knock on the door", "Peek inside", "Leave"}).activate();

                                switch(result)
                                {
                                case 1:
                                std::cout << "You approach the door to knock, but the door opens on it's own.";
                                std::cout << " 'Welcome, welcome.' a voice lures you in. It seems harmless enough, so you enter." << std::endl;
                                break;
                                default:
                                break;
                                }
 ////////////////////////////////////////////END OF ///////////////////////////////////////////////////////////////
                                }
                            else if(n >= 90 && n<= 99)
                                {
 ////////////////////////////////////////////START OF ///////////////////////////////////////////////////////////////
                                std::cout << "While walking through the woods your foot gets caught on a gnarly root and you trip!" <<std::endl;
                                int result = Dialogue(
                                    "What do you do?",
                                    {"Leave"}).activate();

                                switch(result)
                                {
                                case 1:
                                break;
                                default:
                                break;
                                }
 ////////////////////////////////////////////END OF ///////////////////////////////////////////////////////////////
                                }

/////////////////////////////////////END GOBLIN FIGHT//////////////////////////////////////////////////////////////////
break;
}

////////////////////////////////////RETURN TO CAMP////////////////////////////////////////////////////////////////////
                            case 2:
                                std::cout << "You decided to return to camp" << std::endl;
                            break;
                            default:
                            break;
                        }
////////////////////////////////////END FOREST EVENTS/////////////////////////////////////////////////////////////////
                    break;
                    }

/////////////////////////////START OF CAVE EVENTS/////////////////////////////////////////////////////////////////////
                    case 2:
                        {
////////////////////////////////////START OF HORACE/////////////////////////////////////////
                        std::string wowChoice = "";
                        if(horace.affection >= 15)
                            wowChoice = "Wowzers";

                        int result = Dialogue("You see a silhouette of a man standing in front of the cave's entrance. What do you?",
                                            {"Approach him", "Return to camp", wowChoice }).activate();
                            switch(result)
                            {
                            case 1:
                                if(horace.affection == 0)
                                {
                                    std::cout << "'Hey there, stranger! The man waves as he approaches you." << std::endl;
                                    std::cout <<"'The name's Horace.' seeming a little eager too shake your hand. 'I don't get too many visitors around here'" << std::endl;
                                    std::cout << "'This part of the game isn't ready yet but feel free to visit me!" << std::endl;
                                    std::cout << "You return to camp feeling a little happy meeting a friendly person" << std::endl;
                                    horace.affection += 10;
                                }
                                else if(horace.affection > 5 && horace.affection < 14)
                                {
                                    std::cout << "'Hey buddy! I'm really glad you visited, but there's nothing really to do here but chat if you don't mind'" << std::endl;
                                    std::cout << "You spend some time chatting with Horace before returning to camp." << std::endl;
                                    horace.affection += 10;
                                }
                                else if(horace.affection > 15)
                                {
                                    std::cout << "'You must really like me, haha' Horace jokes guffawing to himself." << std::endl;
                                    std::cout << "You know me by now, I'm always up for a talk.'" << std::endl;
                                    std::cout << "You spend some time chatting with Horace before returning to camp." << std::endl;
                                }
                            break;
////////////////////////////////////END OF HORACE/////////////////////////////////////////////////////////////////////////////////////////////////////////
                            case 2:
                                std::cout << "You decided to return to camp." <<std::endl;
                            break;
                            case 3:
                                if(horace.affection < 15)
                                break;
                                else
                                std::cout << "Wowzers" <<std::endl;
                            default:
                            break;
                            }
                    break;
                        }

                    default:
                    break;
                    }
                    break;
                }
        case 6:
            {
                int result = Dialogue(
                       "Which location do you want to visit?",
                       {"City","Riverside Shop"}).activate();

                switch(result)
                {

                    case 1:
                    break;
                    default:
                    break;
                }
            }
            break;
        case 7:
            {
                int result = Dialogue(
                       "Who do you want to visit?",
                       {"Witch","Sad Bandit", "Merman"}).activate();

                switch(result)
                {

                    case 1:
                    break;
                    default:
                    break;
                }
            }
            break;
        case 8:
        {
            int result = Dialogue("Do you want to save before you quit?",
                {"Yes","No","Return"}).activate();
                switch(result)
                {
                    case 1:
                        {
                        std::string fileName;
                        std::ofstream myfile;
                        std::cout << "Name the save file" << std::endl;
                        std::cin >> fileName;
                        fileName += ".dat";
                        myfile.open (fileName);
                        myfile << player.name << "\n";
                        myfile << player.className << "\n";
                        myfile << player.maxHealth << "\n";
                        myfile << player.health << "\n";
                        myfile << player.level << "\n";
                        myfile << player.exp << "\n";
                        myfile << player.str << "\n";
                        myfile << player.end << "\n";
                        myfile << player.dex << "\n";
                        myfile << player.intl << "\n";
                        if(player.equippedWeapon != nullptr)
                        {
                        myfile << player.equippedWeapon->order << "\n";
                        }
                        if(player.equippedWeapon == nullptr)
                        {
                        myfile << "0000 \n";
                        }
                        if(player.equippedArmor[Armor::Slot::HEAD] != nullptr)
                        {
                        myfile << player.equippedArmor[Armor::Slot::HEAD]->order << "\n";
                        }
                        if(player.equippedArmor[Armor::Slot::HEAD] == nullptr)
                        {
                        myfile << "0000 \n";
                        }
                        if(player.equippedArmor[Armor::Slot::TORSO] != nullptr)
                        {
                        myfile << player.equippedArmor[Armor::Slot::TORSO]->order << "\n";
                        }
                        if(player.equippedArmor[Armor::Slot::TORSO] == nullptr)
                        {
                        myfile << "0000 \n";
                        }
                        if(player.equippedArmor[Armor::Slot::LEGS] != nullptr)
                        {
                        myfile << player.equippedArmor[Armor::Slot::LEGS]->order << "\n";
                        }
                        if(player.equippedArmor[Armor::Slot::LEGS] == nullptr)
                        {
                        myfile << "0000 \n";
                        }
                        if(player.currentCompanion != nullptr)
                        {
                        myfile << player.currentCompanion->order << "\n";
                        }
                        if(player.currentCompanion == nullptr)
                        {
                        myfile << "0000 \n";
                        }
                        if(player.inventory.items.size() == 0)
                        {
                        myfile << "0000 \n";

                        }
                        else
                        {
                            for(auto it : player.inventory.items)
                            {
                            player.useItem(it.first);
                            myfile << player.usedItem->order << "\n";
                            myfile << it.second << "\n";
                            }
                            myfile << "$ \n";
                        }
                        if(player.inventory.weapons.size() == 0)
                        {
                        myfile << "0000 \n";

                        }
                        else
                        {
                            for(auto it : player.inventory.weapons)
                                {
                                player.equipWeapon(it.first);
                                myfile << player.equippedWeapon->order << "\n";
                                myfile << it.second << "\n";
                                }
                                myfile << "$ \n";
                        }
                        if(player.inventory.armor.size() == 0)
                        {
                            myfile << "0000 \n";

                        }
                        else
                        {
                            for(auto it : player.inventory.armor)
                                {
                                player.equipArmor(it.first);
                                if(player.equippedArmor[Armor::Slot::HEAD] != nullptr)
                                    {
                                    myfile << player.equippedArmor[Armor::Slot::HEAD]->order << "\n";
                                    myfile << it.second << "\n";
                                    }
                                }


                            for(auto it : player.inventory.armor)
                            {
                            if(player.equippedArmor[Armor::Slot::TORSO] != nullptr)
                                {
                                player.equipArmor(it.first);
                                myfile << player.equippedArmor[Armor::Slot::TORSO]->order << "\n";
                                myfile << it.second << "\n";
                                }

                            }

                        for(auto it : player.inventory.armor)
                        {
                                if(player.equippedArmor[Armor::Slot::LEGS] != nullptr)
                                {
                                player.equipArmor(it.first);
                                myfile << player.equippedArmor[Armor::Slot::LEGS]->order << "\n";
                                myfile << it.second << "\n";
                                }
                                myfile << "$ \n";
                            }
                        }
                        for(auto it : player.inventory.abilities)
                        {
                            player.useAbility(it.first);
                            myfile << player.currentAbility->order << "\n";
                        }
                        myfile << "$ \n";
                        myfile << horace.affection << "\n";
                        myfile.close();
                        }
                    return 0;
                    break;
                    case 2:
                    return 0;
                    break;
                    case 3:
                    break;
                    default:
                    break;
                }
        }
         default:
         break;
        }
    };
return 0;
}

//New Character Menu

Creature dialogue_newchar()
{
	//ask for a name and class
	//Name does not use a dialogue since dialogues only request
	//options, not string input, could be generalised in its
	//own textinput class, but is not really necessary
	std::cout<< "Choose your name" <<std::endl;
	std::string name;
	std::cin >> name;

	int result = Dialogue(
                       "Choose your class",
                       {"Fighter", "Rogue", "Arrow Dude"}).activate();

	switch(result)
	{
		//Fighter class favors health and strength
	case 1:
		return Creature(name, 35, 20, 10, 10, 5,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0,
                  0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0,
                  0, 0,
                  0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0, 10.0, 0, 1, "Fighter");


		break;

		//Rogue class favors dexterity and hit rate
	case 2:
		return Creature(name, 30, 10, 10, 20, 10,
                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                   0,
                   0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0,
                   0, 0,
                   0, 0,
                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                   0, 15.0, 0, 1, "Rogue");


		break;
		//Default case that should never happen
		//but it's good to be safe
	case 3:
        return Creature(name, 25, 15, 10, 15, 15,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0,
                  0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0,
                  0, 0,
                  0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0, 20.0, 0, 1, "Swordsman");

        break;
	default:
		return Creature(name, 30, 10, 10, 10, 0,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0,
                  0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0,
                  0, 0,
                  0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0,10.0, 0, 1, "Adventurer");


		break;
	}
}




