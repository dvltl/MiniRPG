#pragma once

#include "characters/ICharacter.h"

class IMainCharacter : public ICharacter {
public:
	virtual void levelUp() = 0;
	virtual void heal() = 0;
};
