#pragma once

#include "characters/ICharacter.h"

class IHealModel {
public:
	virtual void heal(ICharacter&, HP amount) const = 0;
};