#pragma once

#include "PoppingContainer.h"
#include "characters/ICharacter.h"


class ICharacterBuilder {
public:
	virtual std::unique_ptr<ICharacter> createHero() const = 0;
	virtual std::unique_ptr<ICharacter> createBBEG() const = 0;

	virtual std::unique_ptr<PoppingContainer<ICharacter>> createEnemies() const = 0;
};
