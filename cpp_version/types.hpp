#include <string>
//#include <vector>
#include <iostream>
//#include <cstdarg>

using namespace std;

#define N 4
#define HERO 0
#define NECROMANCER 1
#define GAME_OVER 400
#define ENEMY_DEAD 404
#define FLED 405

string charNames[N] =  { "Hero", "Necromancer", "Creepy skeleton", "Drunk goblin", "Spooky ghost" };

class Character {
	private:
		int type;
		int hp;
		int atk;
		int def;
		int exp;
	public:
		Character(const int);
		void decHP(const int amount) { this.hp -= amount; };
		const int getAtk() { return this.atk; };
		const int getDef() { return this.def; };
		const int getExp() { return this.exp; };
		const int getHP() { return this.hp; };
		const int getType() { return this.type; };
//		void speak(const char num, ...);
};

class Hero: public Character {
	private:
		int level;
		int gold;
	  	int maxHP;
		int potions;
	public:
		Hero(): level(1), gold(100), maxHP(100), potions(3) {
			Character(HERO);
		}
		int challange(Character& enemy);
		int hit(Character& enemy);
		void updateExp(const int exp);
		void heal();
		void addPotion();
		void fullHeal();
		const int getMaxHP() { return this.maxHP; };
}

void Hero :: addPotion() {
	if (this.gold >= 50){
		++this.potions;
		this.gold -= 50;
	} else {
		cout << "Not enough gold! You have only " << this.gold << endl;
	}
}

void Hero :: fullHeal() {
	if (this.gold >= 100){
		this.hp = this.maxHP();
		this.gold -= 100;
	}
}

void Hero :: updateExp(const int exp){
	this.exp += exp;
   	this.lvl = exp / 20;
	this.atk += 2;
	this.def += 2;
	this.maxHP += 5;
	//TODO: should i really restore his HP?
	this.hp = this.maxHP;
}

void Hero :: heal() {
	if (this.potions){
		this.hp += 50;
		this.potions --;
		cout << "Potions left: " << this.potions;
	} else {
		cout << "Cannot heal: no potions left!";
	}
}

int Hero :: hit(Character& enemy){
	int def = enemy.getDef();
	int amount = this.atk -  def ? this.atk - def : 1;
	enemy.decHP(amount);
	int atk = enemy.getAtk();
	amount = atk - this.def ? atk - this.def : 1;
	this.decHP(amount);

	if (!this.hp){
		return GAME_OVER;
	} else if (!enemy.getHP()){
		return  ENEMY_DEAD;
	} else {
		return 0;
	}
}

int Hero :: challenge(Character& enemy) {
	int act = 0;

//	if (NECROMANCER == enemy.getType){
		//TODO: add scripted dialog between hero and necromancer
//	}

	while (enemy.getHP() > 0 && this.hp > 0) {
		cout << "What should we do?" << endl;
		cout << "HP: " << this.hp << '/' << this.maxHP << endl;
		cout << "Enemy HP: " << enemy.getHP() << endl;
		cout << "1. Attack" << endl;
		cout << "2. Use potion" << endl;
		cout << "3. Flee from battle"

		cin >> act;
		system("clear");

		switch (act) {
			case 1: {
				int result = this.hit(enemy);
				if (result == GAME_OVER){
					return GAME_OVER;
				} else if (result == ENEMY_DEAD){
					return 0;
				}
			}
			case 2: {
				this.heal();
			}
			case 3: {
				return FLED;
			}
		}
	}

	return -1;
}

Character :: Character(const int type) {
	this.type = type;
	switch (type) {
		//Hero
		case 0: {
					this.hp = 100;
					this.atk = 12;
					this.def = 6;
					this.exp = 0;
				}
		//Necromancer
		case 1: {
					this.hp = 200;
					this.atk = 20;
					this.def = 14;
					this.exp = 40;
				}
		//Skeleton
		case 2: {
					this.hp = 50;
					this.atk = 15;
					this.def = 5;
					this.exp = 10;
				}
		//Goblin
		case 3: {
					this.hp = 70;
					this.atk = 12;
					this.def = 8;
					this.hp = 20;
				}
		//Ghost
		case 4: {
					this.hp = 80;
					this.atk = 8;
					this.def = 10;
					this.exp = 15;
				}
	}
}

/*
    void Character :: speak(char num, ...){
	va_list args;
	va_start (args, num);
	while (num --){
		cout << charNames[this.type] << ": " << va_arg(args, char*);
	}
	va_end(args);
}
*/
