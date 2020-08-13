#pragma once

#include <memory>

#include "models/IHealModel.h"

class NullHealModel : public IHealModel {
public:
	void heal(ICharacter&, HP) const override {}
};