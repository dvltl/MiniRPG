#pragma once

#include "characters/ICharacter.h"

class ILevelingModel {
public:
	virtual void levelUp(ICharacter&) const = 0;
};