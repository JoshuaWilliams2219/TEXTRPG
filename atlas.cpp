#include "atlas.hpp"

void buildatlas_creature(std::vector<Creature>& atlas)
{
    // Fill the atlas
    // Creature(Name, Health, Str, End, Dex, Int, Blu, Prc, Sla, Fir, Ice, Wat, Thu, Win, Ear, Lig, Drk,
    //BluRes, PrcRes, SlaRes, FirRes, IceRes, WatRes, ThuRes, WinRes, EarRes, LigRes, DrkRes,  Loot, Hit Rate, Level)
    atlas.push_back(Creature("Rat", 8, 8, 8, 12, 1,
                                //Name, Health, Strength, Endurance, Dexterity, Intelligence
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Resistances: same order as above
                                0,
                                //Useless integer
                                0, 0, 0, 0, 0, 0,
                                //Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //Sleep, Frozen, Burn, Petrification, Stop, Fear
                                 0, 0, 0, 0, 0, 0,
                                //ATK: Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //ATK :Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0,
                                //Physical ATK Mod, Physical DEF Mod
                                0, 0,
                                //Element ATK Mod, Elemental DEF Mod
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for Resistances: same order as above
                                0, 2.0, 0, 1));
                                //Hit Rate, Hit Rate mod, Level
    atlas.push_back(Creature("Goblin", 20, 8, 8, 12, 3,
                                //Name, Health, Strength, Endurance, Dexterity, Intelligence
                                1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, -5, 0, 0, 0, 0, 0, 0, 5,
                                //Resistances: same order as above
                                0,
                                //Useless integer
                                0, 0, 0, 0, 0, 0,
                                //Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0, 0, 0, 0, 0,
                                //ATK: Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //ATK :Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0,
                                //Physical ATK Mod, Physical DEF Mod
                                0, 0,
                                //Element ATK Mod, Elemental DEF Mod
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for Resistances: same order as above
                                0, 2.0, 0, 1));
                                //Hit Rate, Hit Rate mod, Level
    atlas.push_back(Creature("Wolf", 20, 5, 8, 15, 3,
                                //Name, Health, Strength, Endurance, Dexterity, Intelligence
                                0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Resistances: same order as above
                                0,
                                //Useless integer
                                0, 0, 0, 0, 0, 0,
                                //Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0, 0, 0, 0, 0,
                                //ATK: Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //ATK :Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0,
                                //Physical ATK Mod, Physical DEF Mod
                                0, 0,
                                //Element ATK Mod, Elemental DEF Mod
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for Resistances: same order as above
                                0, 2.0, 0, 1));
                                //Hit Rate, Hit Rate mod, Level
    atlas.push_back(Creature("Slime", 30, 10, 10, 5, 3,
                                //Name, Health, Strength, Endurance, Dexterity, Intelligence
                                3, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0,
                                //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                5, 5, 5, -10, -10, 10, 0, 0, 0, 0, 5,
                                //Resistances: same order as above
                                0,
                                //Useless integer
                                0, 0, 0, 0, 0, 0,
                                //Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0, 0, 0, 0, 0,
                                //ATK: Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //ATK :Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0,
                                //Physical ATK Mod, Physical DEF Mod
                                0, 0,
                                //Element ATK Mod, Elemental DEF Mod
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for Resistances: same order as above
                                0, 2.0, 0, 1));
                                //Hit Rate, Hit Rate mod, Level
    atlas.push_back(Creature("Skeleton", 8, 10, 10, 10, 3,
                                //Name, Health, Strength, Endurance, Dexterity, Intelligence
                                5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                -10, 10, 10, -5, 5, 0, 0, 0, 0, -10, 10,
                                //Resistances: same order as above
                                0,
                                //Useless integer
                                0, 0, 0, 0, 0, 0,
                                //Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0, 0, 0, 0, 0,
                                //ATK: Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //ATK :Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0,
                                //Physical ATK Mod, Physical DEF Mod
                                0, 0,
                                //Element ATK Mod, Elemental DEF Mod
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for Resistances: same order as above
                                0, 2.0, 0, 1));
                                //Hit Rate, Hit Rate mod, Level
    atlas.push_back(Creature("Bat Swarm", 30, 2, 8, 15, 3,
                                //Name, Health, Strength, Endurance, Dexterity, Intelligence
                                0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                2, 2, 2, -5, 0, 0, 0, 0, 0, 0, 0,
                                //Resistances: same order as above
                                0,
                                //Useless integer
                                0, 0, 0, 0, 0, 0,
                                //Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0, 0, 0, 0, 0,
                                //ATK: Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //ATK :Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0,
                                //Physical ATK Mod, Physical DEF Mod
                                0, 0,
                                //Element ATK Mod, Elemental DEF Mod
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for Resistances: same order as above
                                0, 2.0, 0, 1));
                                //Hit Rate, Hit Rate mod, Level
    atlas.push_back(Creature("Hobgoblin", 25, 10, 8, 10, 3,
                                //Name, Health, Strength, Endurance, Dexterity, Intelligence
                                0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, -5, 0, 0, 0, 0, 0, 0, 5,
                                //Resistances: same order as above
                                0,
                                //Useless integer
                                0, 0, 0, 0, 0, 0,
                                //Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0, 0, 0, 0, 0,
                                //ATK: Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //ATK :Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0,
                                //Physical ATK Mod, Physical DEF Mod
                                0, 0,
                                //Element ATK Mod, Elemental DEF Mod
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for Resistances: same order as above
                                0, 2.0, 0, 1));
                                //Hit Rate, Hit Rate mod, Level
    atlas.push_back(Creature("Zombie", 50, 10, 8, 2, 3,
                                //Name, Health, Strength, Endurance, Dexterity, Intelligence
                                10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                10, -5, -10, -5, 0, 0, 0, 0, 0, -15, 15,
                                //Resistances: same order as above
                                0,
                                //Useless integer
                                0, 0, 0, 0, 0, 0,
                                //Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0, 0, 0, 0, 0,
                                //ATK: Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //ATK :Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0,
                                //Physical ATK Mod, Physical DEF Mod
                                0, 0,
                                //Element ATK Mod, Elemental DEF Mod
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for Resistances: same order as above
                                0, 2.0, 0, 1));
                                //Hit Rate, Hit Rate mod, Level
    atlas.push_back(Creature("Ghoul", 75, 15, 8, 5, 3,
                                //Name, Health, Strength, Endurance, Dexterity, Intelligence
                                0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                10, -5, -10, -5, 0, 0, 0, 0, 0, -15, 15,
                                //Resistances: same order as above
                                0,
                                //Useless integer
                                0, 0, 0, 0, 0, 0,
                                //Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0, 0, 0, 0, 0,
                                //ATK: Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //ATK :Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0,
                                //Physical ATK Mod, Physical DEF Mod
                                0, 0,
                                //Element ATK Mod, Elemental DEF Mod
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for Resistances: same order as above
                                0, 2.0, 0, 1));
                                //Hit Rate, Hit Rate mod, Level
    atlas.push_back(Creature("Orc", 35, 20, 8, 10, 3,
                                //Name, Health, Strength, Endurance, Dexterity, Intelligence
                                10, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Resistances: same order as above
                                0,
                                //Useless integer
                                0, 0, 0, 0, 0, 0,
                                //Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0, 0, 0, 0, 0,
                                //ATK: Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //ATK :Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0,
                                //Physical ATK Mod, Physical DEF Mod
                                0, 0,
                                //Element ATK Mod, Elemental DEF Mod
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for Resistances: same order as above
                                0, 2.0, 0, 1));
                                //Hit Rate, Hit Rate mod, Level
    atlas.push_back(Creature("Troll", 75, 10, 8, 12, 3,
                                //Name, Health, Strength, Endurance, Dexterity, Intelligence
                                0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Resistances: same order as above
                                0,
                                //Useless integer
                                0, 0, 0, 0, 0, 0,
                                //Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0, 0, 0, 0, 0,
                                //ATK: Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //ATK :Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0,
                                //Physical ATK Mod, Physical DEF Mod
                                0, 0,
                                //Element ATK Mod, Elemental DEF Mod
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for Resistances: same order as above
                                0, 2.0, 0, 1));
                                //Hit Rate, Hit Rate mod, Level
    atlas.push_back(Creature("Merman", 25, 8, 8, 12, 3,
                                //Name, Health, Strength, Endurance, Dexterity, Intelligence
                                0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0,
                                //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, -10, 10, 0, 0, 0, 5,
                                //Resistances: same order as above
                                0,
                                //Useless integer
                                0, 0, 0, 0, 0, 0,
                                //Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0, 0, 0, 0, 0,
                                //ATK: Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //ATK :Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0,
                                //Physical ATK Mod, Physical DEF Mod
                                0, 0,
                                //Element ATK Mod, Elemental DEF Mod
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for Resistances: same order as above
                                0, 2.0, 0, 1));
                                //Hit Rate, Hit Rate mod, Level
    atlas.push_back(Creature("Viper", 10, 2, 8, 20, 3,
                                //Name, Health, Strength, Endurance, Dexterity, Intelligence
                                0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, -5, 0, 0, 0, 0, 0, 0, 5,
                                //Resistances: same order as above
                                0,
                                //Useless integer
                                0, 0, 0, 0, 0, 0,
                                //Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //Sleep, Frozen, Burn, Petrification, Stop, Fear
                                1, 0, 0, 0, 0, 0,
                                //ATK: Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //ATK :Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0,
                                //Physical ATK Mod, Physical DEF Mod
                                0, 0,
                                //Element ATK Mod, Elemental DEF Mod
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for Resistances: same order as above
                                0, 2.0, 0, 1));
                                //Hit Rate, Hit Rate mod, Level
    atlas.push_back(Creature("Ghost", 10, 1, 8, 10, 3,
                                //Name, Health, Strength, Endurance, Dexterity, Intelligence
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                20, 20, 20, 0, 0, 0, 0, 0, 0, -25, 25,
                                //Resistances: same order as above
                                0,
                                //Useless integer
                                0, 0, 0, 0, 0, 0,
                                //Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0, 0, 0, 0, 0,
                                //ATK: Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 1,
                                //ATK :Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0,
                                //Physical ATK Mod, Physical DEF Mod
                                0, 0,
                                //Element ATK Mod, Elemental DEF Mod
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for Resistances: same order as above
                                0, 2.0, 0, 1));
                                //Hit Rate, Hit Rate mod, Level
    atlas.push_back(Creature("Frost Wolf", 40, 10, 8, 12, 3,
                                //Name, Health, Strength, Endurance, Dexterity, Intelligence
                                0, 0, 10, 0, 10, 0, 0, 0, 0, 0, 0,
                                //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, -15, 15, 0, 0, 0, 0, 0, 0,
                                //Resistances: same order as above
                                0,
                                //Useless integer
                                0, 0, 0, 0, 0, 0,
                                //Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0, 0, 0, 0, 0,
                                //ATK: Poison, Stun, Curse, Blind, Slow, Haste
                                0, 1, 0, 0, 0, 0,
                                //ATK :Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0,
                                //Physical ATK Mod, Physical DEF Mod
                                0, 0,
                                //Element ATK Mod, Elemental DEF Mod
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for Resistances: same order as above
                                0, 2.0, 0, 1));
                                //Hit Rate, Hit Rate mod, Level
    atlas.push_back(Creature("Giant Hornet", 15, 5, 8, 20, 3,
                                //Name, Health, Strength, Endurance, Dexterity, Intelligence
                                0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, -5, 0, 0, 0, 0, 0, 0, 5,
                                //Resistances: same order as above
                                0,
                                //Useless integer
                                0, 0, 0, 0, 0, 0,
                                //Poison, Stun, Curse, Blind, Slow, Haste
                                1, 0, 0, 0, 0, 0,
                                //Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0, 0, 0, 0, 0,
                                //ATK: Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //ATK :Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0,
                                //Physical ATK Mod, Physical DEF Mod
                                0, 0,
                                //Element ATK Mod, Elemental DEF Mod
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for Resistances: same order as above
                                0, 2.0, 0, 1));
                                //Hit Rate, Hit Rate mod, Level
    atlas.push_back(Creature("Alrune", 50, 5, 8, 10, 3,
                                //Name, Health, Strength, Endurance, Dexterity, Intelligence
                                0, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, -15, 0, 0, 0, 0, 0, 0, 0,
                                //Resistances: same order as above
                                0,
                                //Useless integer
                                0, 0, 0, 0, 0, 0,
                                //Poison, Stun, Curse, Blind, Slow, Haste
                                0, 1, 0, 0, 0, 0,
                                //Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0, 0, 0, 0, 0,
                                //ATK: Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //ATK :Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0,
                                //Physical ATK Mod, Physical DEF Mod
                                0, 0,
                                //Element ATK Mod, Elemental DEF Mod
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for Resistances: same order as above
                                0, 2.0, 0, 1));
                                //Hit Rate, Hit Rate mod, Level
    atlas.push_back(Creature("Wild Boar", 20, 10, 8, 10, 3,
                                //Name, Health, Strength, Endurance, Dexterity, Intelligence
                                10, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Resistances: same order as above
                                0,
                                //Useless integer
                                0, 0, 0, 0, 0, 0,
                                //Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 1, 0, 0, 0, 0,
                                //ATK: Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //ATK :Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0,
                                //Physical ATK Mod, Physical DEF Mod
                                0, 0,
                                //Element ATK Mod, Elemental DEF Mod
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for Resistances: same order as above
                                0, 2.0, 0, 1));
                                //Hit Rate, Hit Rate mod, Level
    atlas.push_back(Creature("Bear", 50, 10, 8, 10, 3,
                                //Name, Health, Strength, Endurance, Dexterity, Intelligence
                                0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Resistances: same order as above
                                0,
                                //Useless integer
                                0, 0, 0, 0, 0, 0,
                                //Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0, 0, 0, 0, 0,
                                //ATK: Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //ATK :Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0,
                                //Physical ATK Mod, Physical DEF Mod
                                0, 0,
                                //Element ATK Mod, Elemental DEF Mod
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for Resistances: same order as above
                                0, 2.0, 0, 1));
                                //Hit Rate, Hit Rate mod, Level
    atlas.push_back(Creature("Geese", 100, 10, 8, 15, 3,
                                //Name, Health, Strength, Endurance, Dexterity, Intelligence
                                25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Resistances: same order as above
                                0,
                                //Useless integer
                                0, 0, 0, 0, 0, 0,
                                //Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0, 0, 0, 0, 1,
                                //ATK: Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //ATK :Sleep, Frozen, Burn, Petrification, Stop, Fear
                                0, 0,
                                //Physical ATK Mod, Physical DEF Mod
                                0, 0,
                                //Element ATK Mod, Elemental DEF Mod
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Mods for Resistances: same order as above
                                0, 2.0, 0, 1));
                                //Hit Rate, Hit Rate mod, Level
    return;
}

void buildatlas_item(std::vector<Item>& atlas)
{
    // Item(Name, Description)
    atlas.push_back(Item("Gold Coin",
        "A small disc made of lustrous metal", 0, 0));
    atlas.push_back(Item("Iron Key",
        "A heavy iron key with a simple cut", 0, 1));
    atlas.push_back(Item("Potion",
        "A flask of healing solution", 25, 2));
    atlas.push_back(Item("Enchanted Stone",
        "An enchanted gem that reveals a hidden entrance to the cave", 0, 3));

    return;
}

void buildatlas_weapon(std::vector<Weapon>& atlas)
{
    // Weapon(Name, Description, Blu, Prc, Sla, Fir, Ice, Wat, Thu, Win, Ear, Lig, Drk, Hit Rate)
    atlas.push_back(Weapon("Iron Dagger",
        "A short blade made of iron with a leather-bound hilt",
        //Name, Description
        0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0,
        //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
        0, 0, 0, 0, 0, 0,
        //Poison, Stun, Curse, Blind, Slow, Haste
        0, 0, 0, 0, 0, 0,
        //Sleep, Frozen, Burn, Petrification, Stop, Fear
        0, 0,
        //Physical ATK Mod, Physical DEF Mod
        0, 0,
        //Element ATK Mod, Elemental DEF Mod
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Mods for Resistances: same order as above
        0, 2.0, 0));
        //Order, Hit Rate, Hit Rate mod));
    atlas.push_back(Weapon("Flame Dagger",
        "A short blade enchanted with fire",
         //Name, Description
        0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0,
        //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
        0, 0, 0, 0, 0, 0,
        //Poison, Stun, Curse, Blind, Slow, Haste
        0, 0, 0, 0, 0, 0,
        //Sleep, Frozen, Burn, Petrification, Stop, Fear
        0, 0,
        //Physical ATK Mod, Physical DEF Mod
        0, 0,
        //Element ATK Mod, Elemental DEF Mod
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Mods for Resistances: same order as above
        1, 2.0, 0));
        //Order, Hit Rate, Hit Rate mod));
    atlas.push_back(Weapon("Spear",
        "A long pole with a sharp metal tip",
         //Name, Description
        0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0,
        //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
        0, 0, 0, 0, 0, 0,
        //Poison, Stun, Curse, Blind, Slow, Haste
        0, 0, 0, 0, 0, 0,
        //Sleep, Frozen, Burn, Petrification, Stop, Fear
        0, 0,
        //Physical ATK Mod, Physical DEF Mod
        0, 0,
        //Element ATK Mod, Elemental DEF Mod
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Mods for Resistances: same order as above
        2, 2.0, 0));
        //Order, Hit Rate, Hit Rate mod));
    atlas.push_back(Weapon("Dark Spear",
        "A spear enchanted with dark magic",
         //Name, Description
        0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 15,
        //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
        0, 0, 0, 0, 0, 0,
        //Poison, Stun, Curse, Blind, Slow, Haste
        0, 0, 0, 0, 0, 0,
        //Sleep, Frozen, Burn, Petrification, Stop, Fear
        0, 0,
        //Physical ATK Mod, Physical DEF Mod
        0, 0,
        //Element ATK Mod, Elemental DEF Mod
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Mods for Resistances: same order as above
        3, 2.0, 0));
        //Order, Hit Rate, Hit Rate mod));
    atlas.push_back(Weapon("Mace",
        "A medium sized bludgeoning weapon",
         //Name, Description
        10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15,
        //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
        0, 1, 0, 0, 0, 0,
        //Poison, Stun, Curse, Blind, Slow, Haste
        0, 0, 0, 0, 0, 0,
        //Sleep, Frozen, Burn, Petrification, Stop, Fear
        0, 0,
        //Physical ATK Mod, Physical DEF Mod
        0, 0,
        //Element ATK Mod, Elemental DEF Mod
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Mods for Resistances: same order as above
        4, 2.0, 0));
        //Order, Hit Rate, Hit Rate mod));
    atlas.push_back(Weapon("Excalibur",
        "The legendary blade, bestowed upon you by the Lady of the Lake",
         //Name, Description
        0, 0, 15, 0, 0, 0, 0, 0, 0, 15, 0,
        //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
        0, 0, 0, 0, 0, 0,
        //Poison, Stun, Curse, Blind, Slow, Haste
        0, 0, 0, 0, 0, 0,
        //Sleep, Frozen, Burn, Petrification, Stop, Fear
        0, 0,
        //Physical ATK Mod, Physical DEF Mod
        0, 0,
        //Element ATK Mod, Elemental DEF Mod
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Mods for Resistances: same order as above
        5, 2.0, 0));
        //Order, Hit Rate, Hit Rate mod));



    return;
}

void buildatlas_armor(std::vector<Armor>& atlas)
{
    // Armour(Name, Description, Defense, Slot)
    atlas.push_back(Armor("Leather Cuirass",
        "Torso armor made of tanned hide",
        //Name, Description
        5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0,
        //Resistances: Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
        0, 0, 0, 0, 0, 0,
        //Poison, Stun, Curse, Blind, Slow, Haste
        0, 0, 0, 0, 0, 0,
        //Sleep, Frozen, Burn, Petrification, Stop, Fear
        0, 0,
        //Physical ATK Mod, Physical DEF Mod
        0, 0,
        //Element ATK Mod, Elemental DEF Mod
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Mods for Resistances: same order as above
        0, 0, Armor::Slot::TORSO));
        //Order, Hit Rate mod, Armor Slot

    return;
}

void buildatlas_ability(std::vector<Ability>& atlas)
{
    // Ability(Name, Description, Blu, Prc, Sla, Fir, Ice, Wat, Thu, Win, Ear, Lig, Drk, Order, Hit Rate)
    atlas.push_back(Ability("Bite",
        "Use your fangs to bite the enemy",
        //Name, Description
        0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Resistances: same order as above
        0, 0, 0, 0, 0, 0,
        //Poison, Stun, Curse, Blind, Slow, Haste
        0, 0, 0, 0, 0, 0,
        //Sleep, Frozen, Burn, Petrification, Stop, Fear
        0, 0,
        //Physical ATK Mod, Physical DEF Mod
        0, 0,
        //Element ATK Mod, Elemental DEF Mod
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Mods for Resistances: same order as above
        0, 2.0, 0));
        //Order, Hit Rate, Hit Rate mod
    atlas.push_back(Ability("Claw",
        "Use your claws to slash the enemy",
       //Name, Description
        0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0,
        //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Resistances: same order as above
        0, 0, 0, 0, 0, 0,
        //Poison, Stun, Curse, Blind, Slow, Haste
        0, 0, 0, 0, 0, 0,
        //Sleep, Frozen, Burn, Petrification, Stop, Fear
        0, 0,
        //Physical ATK Mod, Physical DEF Mod
        0, 0,
        //Element ATK Mod, Elemental DEF Mod
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Mods for Resistances: same order as above
        1, 2.0, 0));
        //Order, Hit Rate, Hit Rate mod));


    return;
}

void buildatlas_combat(std::vector<Ability>& atlas)
{
    atlas.push_back(Ability("Bite",
        "Use your fangs to bite the enemy",
        //Name, Description
        0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Resistances: same order as above
        0, 0, 0, 0, 0, 0,
        //Poison, Stun, Curse, Blind, Slow, Haste
        0, 0, 0, 0, 0, 0,
        //Sleep, Frozen, Burn, Petrification, Stop, Fear
        0, 0,
        //Physical ATK Mod, Physical DEF Mod
        0, 0,
        //Element ATK Mod, Elemental DEF Mod
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Mods for Resistances: same order as above
        0, 2.0, 0));
        //Order, Hit Rate, Hit Rate mod
    atlas.push_back(Ability("Claw",
        "Use your claws to slash the enemy",
       //Name, Description
        0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0,
        //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Resistances: same order as above
        0, 0, 0, 0, 0, 0,
        //Poison, Stun, Curse, Blind, Slow, Haste
        0, 0, 0, 0, 0, 0,
        //Sleep, Frozen, Burn, Petrification, Stop, Fear
        0, 0,
        //Physical ATK Mod, Physical DEF Mod
        0, 0,
        //Element ATK Mod, Elemental DEF Mod
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Mods for:Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //Mods for Resistances: same order as above
        1, 2.0, 0));
        //Order, Hit Rate, Hit Rate mod));



    return;
}

void buildatlas_companion(std::vector<Companion>& atlas)
{
    atlas.push_back(Companion("Horace",
                                //Name
                                10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Bludgeon, Pierce, Slashing, Fire, Ice, Water, Thunder, Wind, Earth, Light, Dark
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                //Resistances: same order as above
                                0, 0, 0, 0, 0, 0,
                                //Poison, Stun, Curse, Blind, Slow, Haste
                                0, 0, 0, 0, 0, 0,
                                //Mods for Resistances: same order as above
                                0,
                                //Order
                                5.0, 1));
                                //Hit Rate, Level
}
