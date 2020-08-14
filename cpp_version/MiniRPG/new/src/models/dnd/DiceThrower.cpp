#include "models/dnd/DiceThrower.h"

#include <cstdlib>
#include <ctime>

DiceThrower::DiceThrower() : m_diceMap { {Die::D4, 4}, {Die::D6, 6},
	{Die::D8, 8}, {Die::D10, 10}, {Die::D12, 12}, {Die::D20, 20} }
{
	std::srand(std::time(nullptr));
}

DieThrow DiceThrower::throwDice(const Die& die) const {
	DieThrow result = 1;
	auto randNum = std::rand();
	result += randNum % (m_diceMap.at(die));

	return result;
}