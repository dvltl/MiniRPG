#include "include/RPG.hpp"

RPG :: RPG(): necromancer(Character(Character::NECROMANCER, 1)), heroDead(false), gameCleared(false), shopOpportunity(false) {
	std::srand(0);
	hero = Hero();
	enemies = generateEnemies( std::rand() % 10 );

    for (int i = 2; i < 5; ++i){ // 0 - Hero, 1 - Necomancer
        minions.push_back( Character( Character::NORM_ENEMY ) );
    }
}

std::queue <int> RPG :: generateEnemies(const int enemyNumber) {
	std::queue <int> result = std::queue <int>();
	int num = enemyNumber;

	while (num--) {
		result.push( 2 + rand() % 3 );
	}

	result.push( Character::NECROMANCER );

	return result;
}

void RPG :: action () throw (int){
	int result = std::rand() % 45;

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
	char act;
	bool inShop = true;

	std::cout << "Welcome to the shop!" << std::endl;
	std::cout << "Here you can buy potions and heal yourself" << std::endl;

	while (inShop) {
		std::cout << std::endl << "What would you like to do?" << std::endl;
		std::cout << "1. Buy potion - 50 Gold" << std::endl;
		std::cout << "2. Buy treatment (Full Health) - " << hero.getMaxHP() - hero.getHP() << " Gold" << std::endl;
		std::cout << "3. Leave shop" << std::endl << std::endl;

        std::cout << "You have " << hero.getGold() << " Gold" << std::endl;

		std::cin >> act;

		switch(act) {
			case '1': {
				hero.addPotion();
                break;
			}
			case '2': {
				hero.fullHeal();
                break;
			}
			case '3': {
				inShop = false;
                break;
			}

		}

        while ( ( act = getchar() ) != '\n'){

        }

        system("clear");
	}

	return;
}

void RPG :: battle() throw (int){
    Character enemy = Character();
	if (!enemies.empty()) {
        int front = this -> enemies.front();
        if (Character::NECROMANCER == front){
            enemy = necromancer;
        } else {
            enemy = minions[ front - 2 ];
        }
        this -> enemies.pop();

		int result = hero.challenge(enemy);

		if (0 > result){
			throw WAT;
		} else if (GAME_OVER == result){
			heroDead = true;
            std::cout << "GAME OVER. You died." << std::endl;
		} else if (FLED != result) {
			hero.updateExp(enemy.getExp());
            hero.setGold(hero.getGold() + enemy.getGold());

            if (Character::NECROMANCER == enemy.getType()){
                gameCleared = true;
            }

            std::cout << charNames[enemy.getType()] << " killed" << std::endl;
            std::cout << "Got " << enemy.getExp() << " EXP" << std::endl;
            std::cout << "Got " << enemy.getGold() << " Gold" << std::endl;
            //sleep(1);
        } else {
            if (Character::NECROMANCER == enemy.getType()){
                std::cout << "You have fled from battle with necromancer" << std::endl;
                necromancer.setHP(enemy.getHP() + 125);
                necromancer.setAtk(necromancer.getAtk() + 7);
                necromancer.setDef(necromancer.getDef() + 3);
                enemies = generateEnemies(rand() % 10);
                std::cout << "He summoned more of his minions to stall you while he is healing" << std::endl;
                std::cout << "You have to fight through them again" << std::endl;
                hero.setPotions(hero.getPotions() + 1);
                std::cout << "Found a potion!" << std::endl;
            }
        }
	} else {
        std::cout << "No other enemies in site" << std::endl;
		gameCleared = true;
	}
	return;
}

