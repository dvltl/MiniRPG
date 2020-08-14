#pragma once

#include "types/CommonTypes.h"
#include "types/DnDTypes.h"

class IDnDCharacter {
public:
	virtual AC getAC() const = 0;
	virtual HP getHP() const = 0;
	virtual Level getLevel() const = 0;
	virtual Prof getProficiency() const = 0;
	virtual Modifier getAbilityModifier() const = 0;
	virtual Die getDamageDie() const = 0;
	virtual void receiveDamage(HP amount) = 0;
	virtual bool hasPotion() const = 0;
	virtual void usePotion() = 0;
};