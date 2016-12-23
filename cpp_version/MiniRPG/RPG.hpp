#ifndef RPG_HPP
#define RPG_HPP

#include <iostream>
#include <queue>
#include <cstdlib>
#include "types.hpp"

namespace {
	const int WAT = 406;
}

class RPG {
private:
	Hero hero;
    Character necromancer;
    std::vector<Character> minions;
	std::queue <int> enemies;
	bool heroDead;
	bool gameCleared;
	bool shopOpportunity;
public:
	RPG();
	void action() throw(int);
	void shop();
	void battle() throw (int);
	bool isGameOver() { return heroDead || gameCleared; };
	std::queue <int> generateEnemies(const int);
};

#endif
