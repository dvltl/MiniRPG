#include "models/dnd/DnDPotion.h"

#include "models/dnd/DiceThrower.h"

DnDPotion::DnDPotion(Die die, unsigned short dieNum) : m_die(die), m_dieNum(dieNum) {}

HP DnDPotion::restoresFor() const {
	HP result = 0;
	
	for (auto i = 0; i < m_dieNum; ++i) {
		result += DiceThrower::getInstance().throwDice(m_die);
	}
	result += m_dieNum;
	return result;
}