#pragma once

#include "PoppingContainer.h"

#include "characters/CharacterBase.h"
#include "characters/dnd/IDnDCharacter.h"

#include "models/IHealModel.h"
#include "models/IHealSource.h"
#include "models/ILevelingModel.h"

class DnDCharacterImpl : public CharacterBase, public IDnDCharacter {
public:
	DnDCharacterImpl(std::string, AC, HP, Level, std::unique_ptr<IHealModel>, std::unique_ptr<ILevelingModel>);

	// ICharacter
	void speak(const ICharacter&) const override;
	bool isAlive() const override;

	// IDnDCharacter
	AC getAC() const override;
	HP getHP() const override final;
	Level getLevel() const override final;
	Prof getProficiency() const override final;
	Modifier getAbilityModifier() const override;
	Die getDamageDie() const override;
	void receiveDamage(HP amount) override final;
	bool hasPotion() const override final;
	void usePotion() override final;
private:
	AC m_armorClass;
	HP m_maxHitPoints;
	HP m_hitPoints;
	Level m_level;
	Prof m_proficiency;
	Modifier m_modifier;
	Die m_dmgDie;
	Die m_hitDie;
	unsigned short m_potions;
};