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

Prof DnDCharacterImpl::getProficiency() const {
	return m_proficiency;
}

Modifier DnDCharacterImpl::getAbilityModifier() const {
	return m_modifier;
}

Die DnDCharacterImpl::getDamageDie() const {
	return m_dmgDie;
}

void DnDCharacterImpl::receiveDamage(HP amount) {
	m_hitPoints -= amount;
}

bool DnDCharacterImpl::hasPotion() const {
	return (m_potions > 0);
}

void DnDCharacterImpl::usePotion() {
	--m_potions;
}

void DnDCharacterImpl::speak(const ICharacter& other) const {
	// TODO: implement this
}

bool DnDCharacterImpl::isAlive() const {
	return m_hitPoints > 0;
}