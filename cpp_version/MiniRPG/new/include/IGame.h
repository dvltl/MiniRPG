#pragma once

#include <string>

class IGame {
public:
	enum class Result {
		GAME_WON,
		GAME_LOST
	};
	enum class GameType {
		DefaultRPG,
		DnDRPG,
	};

	virtual Result start() = 0;
	virtual std::string getName() const = 0;
};
