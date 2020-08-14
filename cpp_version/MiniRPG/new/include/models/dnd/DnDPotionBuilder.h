#pragma once

#include "models/IHealSourceBuilder.h"
#include "types/DnDTypes.h"

#include <memory>

class DnDPotionBuilder : public IHealSourceBuilder {
public:
	std::unique_ptr<IHealSource> createHealSource() const override;

	enum class PotionType {
		STANDARD, GREATER, SUPERIOR
	};

	std::unique_ptr<IHealSource> createPotion(PotionType) const;
};