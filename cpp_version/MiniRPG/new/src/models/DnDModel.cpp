#include "models/dnd/DnDModel.h"
#include "models/dnd/DiceThrower.h"
#include "characters/dnd/IDnDCharacter.h"

#include <string>
#include <memory>

std::string DnDModel::getDescription() const {
	return "D&D-like model";
}

void DnDModel::performHeal(ICharacter& actor, IHealSource& source) const {
	auto amount = source.restoresFor();
	actor.heal(amount);
}

void DnDModel::performHit(ICharacter& source, ICharacter& target) const {
	auto validSource = typeid(source) == typeid(IDnDCharacter);
	auto validTarget = typeid(target) == typeid(IDnDCharacter);

	if (validSource && validTarget) {
		IDnDCharacter * dndSource = (IDnDCharacter*)(&source);
		IDnDCharacter * dndTarget = (IDnDCharacter*)(&target);

		DiceThrower thrower;
		auto res = thrower.throwDice(Die::D20);
		res += dndSource->getAbilityModifier();
		res += dndSource->getProficiency();

		if (res > dndTarget->getAC()) {
			auto die = dndSource->getDamageDie();
			auto damage = thrower.throwDice(die);
			damage += dndSource->getAbilityModifier();
			
			dndTarget->receiveDamage(damage);
		}
	}
	else {
		throw std::runtime_error("Unexpected character interfaces. Expected to have IDnDCharacter implementations.");
	}
}

void DnDModel::performLevelUp(ICharacter& actor) const {
	actor.levelUp();
}
