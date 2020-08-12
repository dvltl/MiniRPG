#pragma once

#include "models/IModel.h"

class DnDModel : public IModel {
private:
	std::string getDescription() const override;

	std::unique_ptr<IMainCharacter> createHero() const override;
	std::unique_ptr<IMainCharacter> createBBEG() const override;

	std::unique_ptr<CharacterContainer> createEnemies() const override;
};