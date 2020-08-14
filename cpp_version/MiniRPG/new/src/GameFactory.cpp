#include "GameFactory.h"
#include "RPG.h"

#include "models/IModel.h"
#include "models/dnd/DnDModel.h"
#include "models/IHealSourceBuilder.h"

#include "characters/dnd/DnDCharacterBuilder.h"
#include "models/dnd/DnDPotionBuilder.h"

std::unique_ptr<IGame> GameFactory::createGame(IGame::GameType type) {
	std::unique_ptr<IModel> model;
	std::unique_ptr<ICharacterBuilder> actorBuilder;
	std::unique_ptr<IHealSourceBuilder> healBuilder;
	std::unique_ptr<IGame> result;

	switch (type) {
	case IGame::GameType::DnDRPG:
		model = std::make_unique<DnDModel>();
		actorBuilder = std::make_unique<DnDCharacterBuilder>();
		healBuilder = std::make_unique<DnDPotionBuilder>();
		result = RPG::createRPG(std::move(model), std::move(actorBuilder), std::move(healBuilder));
		break;
	case IGame::GameType::DefaultRPG:
	default:
		result = nullptr;
		break;
	}

	return result;
}