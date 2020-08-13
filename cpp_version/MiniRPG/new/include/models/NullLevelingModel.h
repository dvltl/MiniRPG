#pragma once

#include <memory>

#include "models/ILevelingModel.h"

class NullLevelingModel : public ILevelingModel {
public:
	void levelUp(ICharacter&) const override {}
};