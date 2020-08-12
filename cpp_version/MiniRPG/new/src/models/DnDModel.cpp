#include "models/DnDModel.h"

#include <string>

std::string DnDModel::getDescription() const {
	return "D&D-like model";
}

std::unique_ptr<IMainCharacter> DnDModel::createHero() const {
	return nullptr;
}

std::unique_ptr<IMainCharacter> DnDModel::createBBEG() const {
	return nullptr;
}

std::unique_ptr<CharacterContainer> DnDModel::createEnemies() const {
	auto result = std::make_unique<CharacterContainer>();
	return std::move(result);
}
