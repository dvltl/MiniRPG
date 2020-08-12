#include "GameFactory.h"
#include "RPG.h"
#include "models/IModel.h"
#include "models/DnDModel.h"

std::unique_ptr<IGame> GameFactory::createGame(IGame::GameType type) {
	std::unique_ptr<IModel> model;
	std::unique_ptr<IGame> result;

	switch (type) {
	case IGame::GameType::DnDRPG:
		model = std::make_unique<DnDModel>();
		result = RPG::createRPG(std::move(model));
		break;
	case IGame::GameType::DefaultRPG:
	default:
		result = nullptr;
		break;
	}

	return result;
}