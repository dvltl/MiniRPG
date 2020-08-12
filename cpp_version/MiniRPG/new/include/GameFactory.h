#pragma once

#include <memory>

#include "IGame.h"

class GameFactory {
public:
	std::unique_ptr<IGame> createGame(IGame::GameType type);
};
