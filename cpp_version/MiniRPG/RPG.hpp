#include <iostream>
#include <queue>
#include <cstdlib>
#include "types.hpp"

#define WAT 406

class RPG {
	private:
		Hero hero;
        Character necromancer;
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

RPG :: RPG(): necromancer(Character(NECROMANCER)), heroDead(false), gameCleared(false), shopOpportunity(false) {
	hero = Hero();
	enemies = generateEnemies( rand() % 10 );
}

queue <Character> RPG :: generateEnemies(const int enemyNumber) {
	queue <Character> result = queue <Character>();
	int num = enemyNumber;

	while (num--) {
		result.push( Character( 2 + rand() % 3 ) );
	}

	result.push( necromancer );

	return result;
}

void RPG :: action () throw (int){
	int result = rand() % 45;

	if (!shopOpportunity && result >= 35) {
		result = 0;
	}

    system("clear");
    
	if (result < 35) {
		battle();
        shopOpportunity = true;
	} else {
		shop();
        shopOpportunity = false;
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
		cout << "3. Leave shop" << endl << endl;

        cout << "You have " << hero.getGold() << " Gold" << endl;
        
		cin >> act;

		switch(act) {
			case 1: {
				hero.addPotion();
                break;
			}
			case 2: {
				hero.fullHeal();
                break;
			}
			case 3: {
				inShop = false;
                break;
			}
			default: {
				cout << "Please enter one of the numbers of the actions listed below" << endl;
                break;
			}
		}
        system("clear");
	}

	return;
}

void RPG :: battle() throw (int){
	if (!enemies.empty()) {
		Character enemy = this -> enemies.front();
        this -> enemies.pop();
        
        if (enemy.getType() == NECROMANCER){
            shopOpportunity = false;
        }
        
		int result = hero.challenge(enemy);

		if (0 > result){
			throw WAT;
		} else if (GAME_OVER == result){
			heroDead = true;
            cout << "GAME OVER. You died." << endl;
		} else if (FLED != result) {
			hero.updateExp(enemy.getExp());
            hero.setGold(hero.getGold() + enemy.getGold());
            
            cout << charNames[enemy.getType()] << " killed" << endl;
            cout << "Got " << enemy.getExp() << " EXP" << endl;
            cout << "Got " << enemy.getGold() << " Gold" << endl;
            //sleep(1);
        } else {
            if (enemies.empty()){
                cout << "You have fled from battle with necromancer" << endl;
                necromancer.setHP(necromancer.getHP() + 100);
                enemies = generateEnemies(rand() % 10);
                cout << "He summoned more of his minions" << endl;
                cout << "You have to fight through them again" << endl;
                hero.setPotions(hero.getPotions() + 1);
                cout << "Found a potion!" << endl;
            }
        }
	} else {
        cout << "No other enemies in site" << endl;
		gameCleared = true;
	}
	return;
}

