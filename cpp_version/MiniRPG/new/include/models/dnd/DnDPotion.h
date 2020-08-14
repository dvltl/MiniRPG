#pragma once

#include "models/IHealSource.h"
#include "types/DnDTypes.h"

class DnDPotion : public IHealSource {
public:
	HP restoresFor() const override;

	DnDPotion(Die die, unsigned short dieNum);
private:
	const Die m_die;
	const unsigned short m_dieNum;
};

