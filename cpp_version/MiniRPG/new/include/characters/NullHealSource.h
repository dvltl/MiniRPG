#pragma once

#include <memory>

#include "characters/IHealSource.h"

class NullHealSource : public IHealSource {
public:
	HP restoresFor() const override { return 0; }
};