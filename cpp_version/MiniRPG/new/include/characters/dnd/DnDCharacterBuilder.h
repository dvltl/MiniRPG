#pragma once

#include "characters/ICharacterBuilder.h"
#include "characters/dnd/DnDCharacterImpl.h"
#include "types/DnDTypes.h"

#include <map>
#include <functional>

class DnDCharacterBuilder : public ICharacterBuilder {
public:
	DnDCharacterBuilder();

private:
	std::unique_ptr<ICharacter> createHero() const override;
	std::unique_ptr<ICharacter> createBBEG() const override;

	std::unique_ptr<PoppingContainer<ICharacter>> createEnemies() const override;

	std::map<DieThrow, std::function<void*()>> m_enemyMap;
};
