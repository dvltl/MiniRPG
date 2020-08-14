#pragma once

#include "types/CommonTypes.h"

class IHealSource {
public:
	virtual HP restoresFor() const = 0;
};