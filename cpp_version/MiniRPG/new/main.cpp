#include <iostream>
#include <thread>

#include "IGame.h"
#include "GameFactory.h"

int main() try {
	// TODO: add IIOHandler to choose the type of game to play
	std::unique_ptr<IGame> game = GameFactory().createGame(IGame::GameType::DnDRPG);

	std::cout << game->getName().c_str() << std::endl;

	IGame::Result res = game->start();

	// TODO: handle this output through the respective IIOHandler
	switch (res) {
	case IGame::Result::GAME_WON:
		std::cout << "Congratulations! You've won!" << std::endl;
		break;
	case IGame::Result::GAME_LOST:
		std::cout << "You lost... Oh well, you can always try again." << std::endl;
		break;
	default:
		std::cout << "Well, this is unexpected... The game ended, but we don't know why." << std::endl;
		break;
	}

	std::this_thread::sleep_for(std::chrono::seconds(3));
	
	return 0;
}
catch (std::exception & err) {
	std::cerr << "There was an error during the game: " << err.what() << std::endl;
	return 1;
}
