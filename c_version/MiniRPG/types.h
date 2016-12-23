struct player {int max_hp, hp, lvl, exp, atk, def, gold, potions;};

struct creature {
	int hp, atk, def, exp;
	char * name;
};

void script_speaking( char*, char, ... );
void init_hero ( struct player* );
void init_necromancer ( struct creature* );
void enemy_encountered( struct creature* );
int battle ( struct player*, struct creature* );
