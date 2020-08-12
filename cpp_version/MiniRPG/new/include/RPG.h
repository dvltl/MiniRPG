#pragma once

#include <memory>

#include "IGame.h"
#include "models/IModel.h"
#include "characters/IMainCharacter.h"

class RPG : public IGame {
public:
	static std::unique_ptr<RPG> createRPG(std::unique_ptr<IModel>&&);

private:
	RPG(std::unique_ptr<IModel>&&);

	std::string getName() const override;
	IGame::Result start();
	void setAtmosphere() const;

	//void shop();
	//void battle();

	std::unique_ptr<IMainCharacter> m_hero;
	std::unique_ptr<IMainCharacter> m_bbeg;
	std::unique_ptr<IModel> m_modelUsed;
	std::unique_ptr<CharacterContainer> m_enemies;

	bool m_shopOpportunity;
	bool m_heroDead;
};