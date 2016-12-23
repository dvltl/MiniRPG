#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include "types.h"


void init_hero(struct player* hero)
{
	hero -> max_hp = 100;
	hero -> hp = hero -> max_hp;
	hero -> lvl = 1;
	hero -> exp = 0;
	hero -> atk = 12;
	hero -> def = 6;
	hero -> potions = 3;
	hero -> gold = 100;
}

void init_necromancer(struct creature* necromancer)
{
	necromancer -> atk = 20;
	necromancer -> def = 14;
	necromancer -> hp = 200;
	necromancer -> exp = 40;
}	

struct creature* enemy_encountered(void)
{
	struct creature* enemy = malloc(sizeof(struct creature));
	int k = rand() % 3;

	if (enemy == NULL) printf("Enemy fled\n");
	switch (k)
	{
		case 0:	printf("Creepy skeleton appeared\n");
				enemy -> hp = 50;
				enemy -> atk = 15;
				enemy -> def = 5;
				enemy -> exp = 10;
				break;
		case 1: printf("Drunk goblin appeared\n");
				enemy -> hp = 70;
				enemy -> atk = 12;
				enemy -> def = 8;
				enemy -> exp = 20;
				break;
		case 2: printf("Spooky ghost appeared\n");
				enemy -> hp = 80;
				enemy -> atk = 8;
				enemy -> def = 10;
				enemy -> exp = 15;
				break;
	}
	return enemy;
}

void hit(struct player* hero, struct creature *enemy)
{
	int _hit = hero->atk - enemy->def;
	if (_hit > 0)
		enemy -> hp -= _hit;
	else 
		enemy->hp -= 1;
	
	if ((_hit = enemy->atk - hero->def) > 0)
		hero -> hp -= _hit;
	else 
		hero->hp -= 1; 	
}

void heal(struct player* hero)
{
	if (hero->potions)
	{
		hero -> hp += 50;
		-- hero->potions;
		printf("Potions left: %d\n", hero->potions);
	} else printf("No potions left!\n");
}

void rank_player(struct player* hero, int exp)
{
	hero -> exp += exp;
	hero -> lvl = exp / 20;
	hero -> atk += 2;
	hero -> def += 2;
	hero -> max_hp += 20;
	hero -> hp = hero -> max_hp;
}	

void script_speaking(char* who, char num,  ...)
{
	va_list args;
	va_start (args, num);
	while ( num -- )
	{
		printf("%s: %s\n", who, va_arg(args, char*));
	}
	va_end (args);
}

int battle(struct player* hero, struct creature *enemy)
{	
	int act;
	
	if (enemy -> hp == 200)
	{
		script_speaking("Necromancer", 1, "How dare you, mere human, interfere in my great plans!");
		script_speaking("Hero", 1, "Oh, don't worry. Nothing personal, really. I just like beeing a thorn in someone's side.");
		script_speaking("Necromancer", 1, "Fool! That was your last mistake! You won't leave this place alive!");
		script_speaking("Hero", 2, "Yeah-yeah, whatever you say, pal.", "(to himself) It's showtime!");
	}

	while (1)
	{	
		printf("What should we do???\n");
		printf("HP: %d/%d Enemy HP:%d\n", hero->hp, hero->max_hp, enemy->hp);
		printf("1.Attack\n");
		printf("2.Use potion / +50 HP\n");
		printf("3.Leave the battle\n");
		scanf("%d",&act);
		system("clear");
		switch (act)
		{
			case 1: hit(hero, enemy);
					if (hero -> hp <= 0)
					{
						printf("Bad end!\nGame over...\n");
						return 2;
					}
					if (enemy -> hp <= 0) goto victory;
					break;
			case 2: heal( hero );
					break;
			case 3:
				if (enemy -> exp != 40)
			       		goto leave;
				else
					printf("Cannot flee from this battle...\n");		
		}
	}
victory:
	if (enemy -> exp == 40)
	{
		script_speaking("Necromancer", 4, "I...", "will never be a memory...", "We will meet again soon enough...", "And then I WILL kill you");
		script_speaking("Hero", 3, "(merely standing on his feet) Finally...", "I think I'll stay here for a while", "I need to recover from the battle");
	}

	rank_player( hero, enemy -> exp );
	return 0;
leave:
	return 1;
}
