#include "characters/dnd/DnDCharacterBuilder.h"
#include "characters/dnd/DnDCharacterImpl.h"

#include "models/NullHealModel.h"
#include "models/NullLevelingModel.h"
#include "models/dnd/DiceThrower.h"

// TODO: Fill the map 
DnDCharacterBuilder::DnDCharacterBuilder() : m_enemyMap{ 
	// TODO: Probably should introduce CommonDnDCharacter with NullModels and MainDnDCharacter with NonNullModels
	{1, []() { return new DnDCharacterImpl("Spooky Scary Skeleton", 12, 10, 1, std::make_unique<NullHealModel>(), std::make_unique<NullLevelingModel>()); } }, 
	{2, []() { return new DnDCharacterImpl("Spooky Scary Skeleton", 12, 10, 1, std::make_unique<NullHealModel>(), std::make_unique<NullLevelingModel>()); } }, 
	{3, []() { return new DnDCharacterImpl("Spooky Scary Skeleton", 12, 10, 1, std::make_unique<NullHealModel>(), std::make_unique<NullLevelingModel>()); } }, 
	{4, []() { return new DnDCharacterImpl("Spooky Scary Skeleton", 12, 10, 1, std::make_unique<NullHealModel>(), std::make_unique<NullLevelingModel>()); } }, 
} {}

std::unique_ptr<ICharacter> DnDCharacterBuilder::createHero() const {
	return std::unique_ptr<ICharacter>(
		new DnDCharacterImpl("Edgelord Hero", 15, 13, 1, std::make_unique<NullHealModel>(), std::make_unique<NullLevelingModel>())
	);
}

std::unique_ptr<ICharacter> DnDCharacterBuilder::createBBEG() const {
	return std::unique_ptr<ICharacter>(
		new DnDCharacterImpl("Big Bad Necromancer", 16, 100, 10, std::make_unique<NullHealModel>(), std::make_unique<NullLevelingModel>())
	);
}

std::unique_ptr<PoppingContainer<ICharacter>> DnDCharacterBuilder::createEnemies() const {
	auto result = std::make_unique<PoppingContainer<ICharacter>>();

	auto enemiesNum = DiceThrower::getInstance().throwDice(Die::D10);
	for (auto i = 0; i < enemiesNum; ++i) {
		auto enemyType = DiceThrower::getInstance().throwDice(Die::D4);

		std::unique_ptr<ICharacter> newEnemy = std::unique_ptr<ICharacter>(reinterpret_cast<ICharacter*>(m_enemyMap.at(enemyType)()));

		result->add(std::move(newEnemy));
	}

	return result;
}