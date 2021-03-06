#include <stdio.h>
#include <stdlib.h>
#include "types.h"

struct player* hero = NULL;
struct creature* necromancer = NULL;
struct creature * enemy = NULL;

void free_all() {
	free( hero );
	free( enemy );
	free( necromancer );
}

int main()
{
	int battle_number;

	hero = malloc(sizeof(struct player));
	if (hero == NULL)
	{
		printf("Everything is bad with hero\n");
		return 0;
	}

	init_hero( hero );

	necromancer = malloc(sizeof(struct creature));
	if (necromancer == NULL)
	{
		printf("Everything is bad with necromancer\n");
		return 0;
	}

	init_necromancer( necromancer );

	printf("Welcome, traveler. You are about to embark on your epic quest.\n\n");
	script_speaking("Villager", 2, "Oh, stranger! Good timing! You look like an experienced warrior!", "Please, help us! Evil necromancer terrorizes our village!"); 
	script_speaking("Villager", 2, "Many of us have already tried to slay him but they failed...", "Please, slay him for us!!!\n");

	enemy = malloc(sizeof(struct creature));
	for (battle_number = 0; battle_number < 5; battle_number++)
	{
		enemy_encountered( enemy );
		if ( battle(hero, enemy) == 2 ){
			free_all();
			return 0;
		}
	}

	script_speaking("Hero", 3, "Seems like there are no necromancer minions left.", "Ah, he finally decided to show himself!", "Hell, it's about time!");

	battle(hero, necromancer);

	free_all();

	return 0;
}
