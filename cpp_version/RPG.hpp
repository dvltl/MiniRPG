#include <iostream>
#include <queue>
#include <ctime>
#include "types.hpp"

#define WAT 406

class RPG {
	private:
		Hero hero;
		queue <Character> enemies;
		bool heroDead;
		bool gameCleared;
		bool shopOpportunity;
	public:
		RPG();
		void action() throw(int);
		void shop();
		void battle() throw (int);
		bool isGameOver() { return heroDead || gameCleared; };
		queue <Character> generateEnemies(const int);
};

RPG :: RPG(): heroDead(false), gameCleared(false), shopOpportunity(false) {
	hero = Hero();
	generateEnemies( rand() % 10 );
}

queue <Character> RPG :: generateEnemies(const int enemyNumber) {
	queue <Character> result = queue();
	int num = enemyNumber;

	while (num--) {
		result.add( Character( rand() % 3 ) );
	}

	result.add( Character(NECROMANCER) );

	return result;
}

void RPG :: action () throw (int){
	int result = rand() % 45;

	if (!shopOpprotunity && result >= 35) {
		result = 0;
	}

	if (result < 35) {
		battle();
	} else {
		shop();
	}

	return;
}

void RPG :: shop() {
	int act;
	bool inShop = true;

	cout << "Welcome to the shop!" << endl;
	cout << "Here you can buy potions and heal yourself" << endl;

	while (inShop) {
		cout << endl << "What would you like to do?" << endl;
		cout << "1. Buy potion - 50 Gold" << endl;
		cout << "2. Buy treatment (Full Health) - " << hero.getMaxHP() - hero.getHP() << " Gold" << endl;
		cout << "3. Leave shop" << endl;

		cin >> act;

		switch(act) {
			case 1: {
				hero.addPotion();
			}
			case 2: {
				hero.fullHeal();
			}
			case 3: {
				inShop = false;
			}
			default: {
				cout << "Please enter one of the numbers of the actions listed below" << endl;
			}
		}
	}

	return;
}

void RPG :: battle() throw (int){
	if (!enemies.isEmpty()) {
		Character enemy = this.enemies.pop();

		result = hero.challenge(enemy);

		if (0 > result){
			throw WAT;
		} else if (GAME_OVER == result){
			heroDead = true;
		} else if (FLED != result) {
			hero.updateExp(enemy.getExp());
		}
	} else {
		gameCleared = true;
	}
	return;
}

