#pragma once

#include <memory>

#include "IGame.h"
#include "PoppingContainer.h"
#include "models/IModel.h"

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

	const std::unique_ptr<ICharacter> m_hero;
	const std::unique_ptr<ICharacter> m_bbeg;
	const std::unique_ptr<IModel> m_modelUsed;
	const std::unique_ptr<PoppingContainer<ICharacter>> m_enemies;

	bool m_shopOpportunity;
	bool m_heroDead;
};