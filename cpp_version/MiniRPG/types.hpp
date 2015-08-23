#include <string>
#include <iostream>
//#include <cstdarg>

using namespace std;

#define HERO 0
#define NECROMANCER 1
#define GAME_OVER 400
#define ENEMY_DEAD 404
#define FLED 405

#define HEAL 65

string charNames[] =  { "Hero", "Necromancer", "Creepy skeleton", "Drunk goblin", "Spooky ghost" };

class Character {
	private:
		int type;
		int hp;
		int atk;
		int def;
		int exp;
        int gold;
    public:
		Character(const int);
		void decHP(const int amount) { this -> hp -= amount; };
        void setHP(const int hp) { this -> hp = hp; };
        void setExp(const int exp) { this -> exp = exp; };
        void setAtk(const int atk) { this -> atk = atk; };
        void setDef(const int def) { this -> def = def; };
        void setGold(const int gold) { this -> gold = gold; };
		const int getAtk() { return this -> atk; };
		const int getDef() { return this -> def; };
		const int getExp() { return this -> exp; };
		const int getHP() { return this -> hp; };
		const int getType() { return this -> type; };
        const int getGold() { return this -> gold; };
        virtual const int throwDice();
//		void speak(const char num, ...);
};

class Hero: public Character {
	private:
		int lvl;
	  	int maxHP;
		int potions;
        float critChance;
	public:
        Hero(): Character(HERO), lvl(0), maxHP(100), potions(3), critChance(0.05) {};
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
		cout << "Not enough gold! You have only " << gold << endl;
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
        cout << "Potions left: " << this -> potions << endl;
	} else {
        cout << "Cannot heal: no potions left!" << endl;
	}
}

int Hero :: hit(Character& enemy){
    int atk = this -> getAtk();
    int def = enemy.getDef();
	int amount = atk -  def > 0? atk - def : 1;

    int modifier = this -> throwDice();
    if (2 == modifier){
        cout << "Critical hit for Hero!" << endl;
        amount *= 2;
    }
    enemy.decHP(amount);
    
    atk = enemy.getAtk();
    def = this -> getDef();
	amount = atk - def > 0? atk - def : 1;
	
    modifier = this -> throwDice();
    if (2 == modifier){
        cout << "Critical hit for " << charNames[enemy.getType()] << "!" << endl;
        amount *= 2;
    }
    this -> decHP(amount);

	if ( this -> getHP() <= 0){
		return GAME_OVER;
	} else if ( enemy.getHP() <= 0){
		return ENEMY_DEAD;
	} else {
		return 0;
	}
}

int Hero :: challenge(Character& enemy) {
	int act = 0;

//	if (NECROMANCER == enemy.getType){
		//TODO: add scripted dialog between hero and necromancer
//	}

	while (enemy.getHP() > 0 && this -> getHP() > 0) {
        cout << "Enemy type: " << charNames[enemy.getType()] << endl;
		cout << "What should we do?" << endl;
		cout << "HP: " << this -> getHP() << '/' << this -> maxHP << endl;
        cout << "Atk / Def: " << this -> getAtk() << " / " << this -> getDef() << endl;
        cout << "Crit chance: " << this -> critChance << endl;
		cout << "Enemy HP: " << enemy.getHP() << endl;
        cout << "Atk / Def: " << enemy.getAtk() << " / " << enemy.getDef() << endl;
        cout << "Potions: " << this -> potions << endl << endl;
		cout << "1. Attack" << endl;
		cout << "2. Use potion ( + " << HEAL << " HP )" << endl;
        cout << "3. Flee from battle" << endl;

		cin >> act;

		switch (act) {
            case 1: {
				int result = this -> hit(enemy);
				if (result == GAME_OVER){
					return GAME_OVER;
				} else if (result == ENEMY_DEAD){
					return 0;
				}
                break;
            }
            case 2: {
				this -> heal();
                break;
            }
            case 3: {
                return FLED;
            }
            default: {
            }
		}
	}

	return -1;
}

Character :: Character(const int type) {
	this -> type = type;
	switch (type) {
		//Hero
		case 0: {
            this -> hp = 100;
            this -> atk = 12;
            this -> def = 6;
            this -> exp = 0;
            this -> gold = 100;
            break;
        }
		//Necromancer
		case 1: {
            this -> hp = 200;
            this -> atk = 20;
            this -> def = 14;
            this -> exp = 40;
            this -> gold = 150;
            break;
        }
		//Skeleton
		case 2: {
            this -> hp = 50;
            this -> atk = 15;
            this -> def = 5;
            this -> exp = 10;
            this -> gold = 10;
            break;
        }
		//Goblin
		case 3: {
            this -> hp = 70;
            this -> atk = 12;
            this -> def = 8;
            this -> exp = 20;
            this -> gold = 14;
            break;
        }
		//Ghost
		case 4: {
            this -> hp = 80;
            this -> atk = 8;
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
		cout << charNames[this.type] << ": " << va_arg(args, char*);
	}
	va_end(args);
}
*/
