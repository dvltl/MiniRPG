#include "characters/dnd/DnDCharacterImpl.h"

DnDCharacterImpl::DnDCharacterImpl(std::string name, AC ac, HP hp, Level level, std::unique_ptr<IHealModel> healModel, std::unique_ptr<ILevelingModel> levelingModel):
	CharacterBase(name, std::move(healModel), std::move(levelingModel)), m_armorClass(ac), m_hitPoints(hp), m_level(level)
{}

AC DnDCharacterImpl::getAC() const {
	return m_armorClass;
}

HP DnDCharacterImpl::getHP() const {
	return m_hitPoints;
}

Level DnDCharacterImpl::getLevel() const {
	return m_level;
}