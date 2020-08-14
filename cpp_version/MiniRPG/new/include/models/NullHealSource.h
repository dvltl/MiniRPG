#pragma once

#include <memory>

#include "models/IHealSource.h"

class NullHealSource : public IHealSource {
public:
	HP restoresFor() const override { return 0; }
};