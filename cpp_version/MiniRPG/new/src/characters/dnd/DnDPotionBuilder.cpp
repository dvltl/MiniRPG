#include "characters/dnd/DnDPotionBuilder.h"
#include "characters/dnd/DnDPotion.h"
#include "characters/NullHealSource.h"

std::unique_ptr<IHealSource> DnDPotionBuilder::createPotion(DnDPotionBuilder::PotionType type) {
	std::unique_ptr<IHealSource> result;
	switch (type) {
	case DnDPotionBuilder::PotionType::STANDARD:
		result = std::make_unique<DnDPotion>(Die::D4, 2);
		break;
	case DnDPotionBuilder::PotionType::GREATER:
		result = std::make_unique<DnDPotion>(Die::D4, 4);
		break;
	case DnDPotionBuilder::PotionType::SUPERIOR:
		result = std::make_unique<DnDPotion>(Die::D4, 8);
		break;
	default:
		result = std::make_unique<NullHealSource>();
	}

	return result;
}
