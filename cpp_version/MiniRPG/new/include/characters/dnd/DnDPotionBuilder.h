#pragma once

#include "characters/IHealSource.h"
#include "types/DnDTypes.h"

#include <memory>

class DnDPotionBuilder {
public:
	enum class PotionType {
		STANDARD, GREATER, SUPERIOR
	};

	static std::unique_ptr<IHealSource> createPotion(PotionType);
};