#ifndef TYPES_HPP
#define TYPES_HPP

#include <string>
#include <iostream>
//#include <cstdarg>

namespace {
	const int GAME_OVER = 400;
	const int ENEMY_DEAD = 404;
	const int FLED = 405;
	const int HEAL = 65;
}

std::string charNames[] =  { "Hero", "Necromancer", "Creepy skeleton", "Drunk goblin", "Spooky ghost" };

class Character {
public:
		enum Types {
			HERO = 0,
			NECROMANCER = 1,
			SKELETON = 2,
			GOBLIN = 3,
			GHOST = 4
		};
        Character();
		Character(Types);
		void decHP(const int amount) { this -> hp -= amount; };
       	void setHP(const int hp) { this -> hp = hp; };
		void setExp(const int exp) { this -> exp = exp; };
		void setAtk(const int atk) { this -> atk = atk; };
		void setDef(const int def) { this -> def = def; };
		void setGold(const int gold) { this -> gold = gold; };
		const int getAtk() const { return this -> atk; };
		const int getDef() const { return this -> def; };
		const int getExp() const { return this -> exp; };
		const int getHP() const { return this -> hp; };
		const int getType() const { return this -> type; };
        const int getGold() const { return this -> gold; };
        virtual const int throwDice() const;
//		void speak(const char num, ...);
private:
		const Types type;
		int hp;
		int atk;
		int def;
		int exp;
        int gold;

};

Character :: Character(){
    this -> type = NORM_ENEMY;
}

Character :: Character(Types type) {
	this -> type = type;
	switch (type) {
		//Hero
		case HERO: {
            this -> hp = 100;
            this -> atk = 12;
            this -> def = 6;
            this -> exp = 0;
            this -> gold = 100;
            break;
        }
		//Necromancer
		case NECROMANCER: {
            this -> hp = 200;
            this -> atk = 20;
            this -> def = 14;
            this -> exp = 40;
            this -> gold = 150;
            break;
        }
		//Skeleton
		case SKELETON: {
            this -> hp = 50;
            this -> atk = 15;
            this -> def = 5;
            this -> exp = 10;
            this -> gold = 10;
            break;
        }
		//Goblin
		case GOBLIN: {
            this -> hp = 70;
            this -> atk = 12;
            this -> def = 8;
            this -> exp = 20;
            this -> gold = 14;
            break;
        }
		//Ghost
		case GHOST: {
            this -> hp = 80;
            this -> atk = 9;
            this -> def = 10;
            this -> exp = 15;
            this -> gold = 12;
            break;
        }
	}
}

const int Character :: throwDice() {
    if (rand() % 20 < 19){
        return 1;
    } else {
        return 2;
    }
}

/*
    void Character :: speak(char num, ...){
	va_list args;
	va_start (args, num);
	while (num --){
		std::cout << charNames[this.type] << ": " << va_arg(args, char*);
	}
	va_end(args);
}
*/

#endif
