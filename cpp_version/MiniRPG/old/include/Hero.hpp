#ifndef HERO_HPP
#define HERO_HPP

#include "types.hpp"

class Hero: Character {
private:
		int lvl;
	  	int maxHP;
		int potions;
        float critChance;
public:
        Hero(): Character(HERO, 0), lvl(0), maxHP(100), potions(3), critChance(0.05) {};
		int challenge(Character& enemy);
		int hit(Character& enemy);
		void updateExp(const int exp);
		void heal();
		void addPotion();
		void fullHeal();
        void setPotions(const int potions) { this -> potions = potions; };
		const int getMaxHP() { return this -> maxHP; };
        const int throwDice();
        const int getPotions() { return this -> potions; };
};

void Hero :: addPotion() {
    int gold = this -> getGold();
	if (gold >= 50){
		++this -> potions;
		this -> setGold (gold - 50);
	} else {
		std::cout << "Not enough gold! You have only " << gold << std::endl;
	}
}

void Hero :: fullHeal() {
    int gold = this -> getGold();
	if (gold >= 100){
		this -> setHP( this -> maxHP );
		this -> setGold ( gold - 100 );
	}
}

void Hero :: updateExp(const int exp){
	this -> setExp( this -> getExp() + exp );
    int prevLvl = this -> lvl;
   	this -> lvl = this -> getExp() / 20;
	this -> setAtk( this -> getAtk() + 1);
    if (0 == this -> lvl % 2) {
        this -> setDef( this -> getDef() + 1);
    } else {
        this -> critChance += 0.015;
    }
	this -> maxHP += 5;
	//TODO: should i really restore his HP?
    if (prevLvl < this -> lvl){
        this -> setHP ( this -> maxHP );
    }
}

const int Hero :: throwDice() {
    if (rand() % 100 < 100 * (1 - critChance)){
        return 1;
    } else {
        return 2;
    }
}

void Hero :: heal() {
	if (this -> potions){
        this -> setHP ( this -> getHP() + HEAL > this -> maxHP ? this -> maxHP : this -> getHP() + HEAL );
		this -> potions --;
        std::cout << "Potions left: " << this -> potions << std::endl;
	} else {
        std::cout << "Cannot heal: no potions left!" << std::endl;
	}
}

int Hero :: hit(Character& enemy){
    int atk = this -> getAtk();
    int def = enemy.getDef();
	int amount = atk -  def > 0? atk - def : 1;

    int modifier = this -> throwDice();
    if (2 == modifier){
        std::cout << "Critical hit for Hero!" << std::endl;
        amount *= 2;
    }
    enemy.decHP(amount);

    atk = enemy.getAtk();
    def = this -> getDef();
	amount = atk - def > 0? atk - def : 1;

    modifier = this -> throwDice();
    if (2 == modifier){
        std::cout << "Critical hit for " << charNames[enemy.getType()] << "!" << std::endl;
        amount *= 2;
    }
    this -> decHP(amount);

	if ( this -> getHP() <= 0){
		return ::GAME_OVER;
	} else if ( enemy.getHP() <= 0){
		return ::ENEMY_DEAD;
	} else {
		return 0;
	}
}

int Hero :: challenge(Character& enemy) {
	char act = 0;

//	if (Character::Types::NECROMANCER == enemy.getType){
		//TODO: add scripted dialog between hero and necromancer
//	}

	while (enemy.getHP() > 0 && this -> getHP() > 0) {
		std::cout << "HP: " << this -> getHP() << '/' << this -> maxHP << std::endl;
        std::cout << "Atk / Def: " << this -> getAtk() << " / " << this -> getDef() << std::endl;
        std::cout << "Crit chance: " << this -> critChance * 100 << '%' << std::endl;
        std::cout << "Potions: " << this -> potions << std::endl << std::endl;
		std::cout << std::endl;
        std::cout << "Enemy type: " << charNames[enemy.getType()] << std::endl;
        std::cout << "Enemy HP: " << enemy.getHP() << std::endl;
        std::cout << "Atk / Def: " << enemy.getAtk() << " / " << enemy.getDef() << std::endl;
		std::cout << std::endl;
		std::cout << "What will you do?" << std::endl;
		std::cout << "1. Attack" << std::endl;
		std::cout << "2. Use potion ( + " << ::HEAL << " HP )" << std::endl;
        std::cout << "3. Flee from battle" << std::endl;

		std::cin >> act;

		switch (act) {
            case '1':
				int result = this -> hit(enemy);
				if (result == ::GAME_OVER){
					return ::GAME_OVER;
				} else if (result == ::ENEMY_DEAD){
					return 0;
				}
                break;
            case '2':
				this -> heal();
                break;
            case '3': 
				return ::FLED;
			default:
				break;
		}

        while ( ( act = getchar() ) != '\n') {}

        //system("clear");
    }

	return -1;
}

#endif