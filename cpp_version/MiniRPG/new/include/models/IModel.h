#pragma once

#include "characters/IMainCharacter.h"
#include "characters/CharacterContainer.h"

class IModel {
public:
	virtual std::string getDescription() const = 0;

	// Factory part
	virtual std::unique_ptr<IMainCharacter> createHero() const = 0;
	virtual std::unique_ptr<IMainCharacter> createBBEG() const = 0;
	virtual std::unique_ptr<CharacterContainer> createEnemies() const = 0;

	// Strategy part
	virtual void performHit(ICharacter&, ICharacter&) const = 0;
	virtual void performHeal(ICharacter&) const = 0;
};