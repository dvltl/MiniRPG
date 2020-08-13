#pragma once

#include "characters/ICharacter.h"
#include "characters/IHealSource.h"

class IModel {
public:
	virtual std::string getDescription() const = 0;

	// Strategy part
	virtual void performHit(ICharacter&, ICharacter&) const = 0;
	virtual void performHeal(ICharacter&, IHealSource&) const = 0;
	virtual void performLevelUp(ICharacter&) const = 0;
};