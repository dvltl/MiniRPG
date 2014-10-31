struct player {int max_hp, hp, lvl, exp, atk, def, gold, potions;};
	
struct creature {int hp, atk, def, exp;};

void script_speaking( char*, char, ... );
void init_hero ( struct player* );
void init_necromancer ( struct creature* );
struct creature* enemy_encountered(void);
int battle ( struct player*, struct creature* );
