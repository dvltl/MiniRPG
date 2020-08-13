#pragma once

#include "PoppingContainer.h"
#include "characters/ICharacter.h"


class ICharacterBuilder {
	std::unique_ptr<ICharacter> createHero() const override;
	std::unique_ptr<ICharacter> createBBEG() const override;

	std::unique_ptr<PoppingContainer<ICharacter>> createEnemies() const override;
};
