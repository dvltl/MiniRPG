#pragma once

#include "characters/ICharacter.h"
#include "models/IHealSource.h"

class IModel {
public:
	virtual std::string getDescription() const = 0;

	// Strategy part
	virtual void performAttack(ICharacter&, ICharacter&) const = 0;
	virtual void performHeal(ICharacter&, IHealSource&) const = 0;
	virtual void performLevelUp(ICharacter&) const = 0;
};