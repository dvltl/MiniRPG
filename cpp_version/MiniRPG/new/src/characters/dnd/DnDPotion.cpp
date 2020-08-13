#include "characters/dnd/DnDPotion.h"

DnDPotion::DnDPotion(Die die, unsigned short dieNum) : m_die(die), m_dieNum(dieNum) {}

HP DnDPotion::restoresFor() {
	HP result = 0;
	for (auto i = 0; i < m_dieNum; ++i) {
		// TODO: properly throw the die here
		result += 2;
	}
	result += dieNum;
	return result;
}