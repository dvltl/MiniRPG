#pragma once

#include "types/DnDTypes.h"

#include <map>
#include <memory>

class DiceThrower {
public:
	DieThrow throwDice(const Die&) const;

	static DiceThrower& getInstance() {
		static DiceThrower instance;
		return instance;
	}

private:
	DiceThrower();
	DiceThrower(const DiceThrower &);
	DiceThrower& operator=(DiceThrower &) = delete;
	const std::map<Die, DieThrow> m_diceMap;
};