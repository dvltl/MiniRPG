#pragma once

#include <string>

#include "types/CommonTypes.h"

class ICharacter {
public:
	virtual std::string getName() const = 0;
	virtual void speak(const ICharacter &) const = 0;
	virtual void levelUp() = 0;
	virtual void heal(HP amount) = 0;
	virtual bool isAlive() const = 0;
};
