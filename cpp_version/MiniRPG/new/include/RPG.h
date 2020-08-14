#pragma once

#include <memory>

#include "IGame.h"
#include "PoppingContainer.h"

#include "io/IIOHandler.h"
#include "characters/ICharacterBuilder.h"

#include "models/IModel.h"
#include "models/IHealSourceBuilder.h"

class RPG : public IGame {
public:
	static std::unique_ptr<RPG> createRPG(
		std::unique_ptr<IModel>&& mechanicsModel,
		std::unique_ptr<ICharacterBuilder>&& characterBuilder,
		std::unique_ptr<IHealSourceBuilder>&& healBuilder
	);

private:
	RPG(std::unique_ptr<IModel>&&, std::unique_ptr<ICharacterBuilder>&&, std::unique_ptr<IHealSourceBuilder>&&);

	std::string getName() const override;

	void setAtmosphere() const;
	IGame::Result start();

	IGame::Result mainLoop();
	//void shop();
	void battle(ICharacter& firstActor, ICharacter& secondActor);

	const std::unique_ptr<IHealSourceBuilder> m_healBuilder;
	const std::unique_ptr<ICharacterBuilder> m_actorBuilder;
	const std::unique_ptr<ICharacter> m_hero;
	const std::unique_ptr<ICharacter> m_bbeg;
	const std::unique_ptr<IModel> m_modelUsed;
	const std::unique_ptr<IIOHandler> m_battleHandler;
	// const std::unique_ptr<IIOHandler> m_shopHandler;
	const std::unique_ptr<PoppingContainer<ICharacter>> m_enemies;

	bool m_shopOpportunity;
	bool m_heroDead;
};