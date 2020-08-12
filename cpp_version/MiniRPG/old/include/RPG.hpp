#ifndef RPG_HPP
#define RPG_HPP

#include <iostream>
#include <queue>
#include "include/types.hpp"
#include "include/Hero.hpp"

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

	void shop();
	void battle() throw (int);
	std::queue <int> generateEnemies(const int);
	
public:
	RPG();
	void action() throw(int);
	bool isGameOver() { return heroDead || gameCleared; };
};

#endif
