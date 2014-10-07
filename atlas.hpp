#ifndef ATLAS_H_INCLUDED
#define ATLAS_H_INCLUDED

#include <vector>

#include "creature.hpp"
#include "item.hpp"
#include "weapons.hpp"
#include "armor.hpp"
#include "ability.hpp"
#include "companion.hpp"

// Atlas building functions. Atlases contain vectors of game data
// that is not modified in gameplay, so the base versions of
// creatures, items etc. Could easily be replaced with functions
// that load the information from config files instead of just
// defining the values in code
void buildatlas_creature(std::vector<Creature>& atlas);
void buildatlas_item(std::vector<Item>& atlas);
void buildatlas_weapon(std::vector<Weapon>& atlas);
void buildatlas_armor(std::vector<Armor>& atlas);
void buildatlas_ability(std::vector<Ability>& atlas);
void buildatlas_combat(std::vector<Ability>& atlas);
void buildatlas_companion(std::vector<Companion>& atlas);

#endif // ATLAS_H_INCLUDED
