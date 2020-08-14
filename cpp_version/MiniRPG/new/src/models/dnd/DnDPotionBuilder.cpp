#include "models/dnd/DnDPotionBuilder.h"
#include "models/dnd/DnDPotion.h"
#include "models/NullHealSource.h"

std::unique_ptr<IHealSource> DnDPotionBuilder::createPotion(PotionType type) const {
	std::unique_ptr<IHealSource> result;
	switch (type) {
	case PotionType::STANDARD:
		result = std::make_unique<DnDPotion>(Die::D4, 2);
		break;
	case PotionType::GREATER:
		result = std::make_unique<DnDPotion>(Die::D4, 4);
		break;
	case PotionType::SUPERIOR:
		result = std::make_unique<DnDPotion>(Die::D4, 8);
		break;
	default:
		result = std::make_unique<NullHealSource>();
	}

	return result;
}

std::unique_ptr<IHealSource> DnDPotionBuilder::createHealSource() const {
	return createPotion(PotionType::GREATER);
}
