#include "characters/CharacterBase.h"
#include "characters/dnd/IDnDCharacter.h"

#include "models/IHealModel.h"
#include "models/ILevelingModel.h"

class DnDCharacterImpl : public CharacterBase, public IDnDCharacter {
public:
	DnDCharacterImpl(std::string, AC, HP, Level, std::unique_ptr<IHealModel>, std::unique_ptr<ILevelingModel>);
	AC getAC() const override;
	HP getHP() const override;
	Level getLevel() const override;
	Prof getProficiency() const override;
	Modifier getAbilityModifier() const override;
private:
	AC m_armorClass;
	HP m_hitPoints;
	Level m_level;
	Prof m_proficiency;
	Modifier m_modifier;
};