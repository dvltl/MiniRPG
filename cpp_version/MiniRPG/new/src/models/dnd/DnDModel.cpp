#include "models/dnd/DnDModel.h"
#include "models/dnd/DiceThrower.h"
#include "characters/dnd/IDnDCharacter.h"

#include <string>
#include <memory>

std::string DnDModel::getDescription() const {
	return "D&D-like model";
}

void DnDModel::performHeal(ICharacter& actor, IHealSource& source) const {
	if (typeid(actor) == typeid(IDnDCharacter)) {
		IDnDCharacter * dndActor = (IDnDCharacter*)(&actor);
		if (dndActor->hasPotion()) {
			auto amount = source.restoresFor();
			dndActor->usePotion();
			actor.heal(amount);
		}
	}
	else {
		throw badCharacter;
	}
}

void DnDModel::performAttack(ICharacter& source, ICharacter& target) const {
	auto validSource = typeid(source) == typeid(IDnDCharacter);
	auto validTarget = typeid(target) == typeid(IDnDCharacter);

	if (validSource && validTarget) {
		IDnDCharacter * dndSource = (IDnDCharacter*)(&source);
		IDnDCharacter * dndTarget = (IDnDCharacter*)(&target);

		auto res = DiceThrower::getInstance().throwDice(Die::D20);
		res += dndSource->getAbilityModifier();
		res += dndSource->getProficiency();

		if (res > dndTarget->getAC()) {
			auto die = dndSource->getDamageDie();
			auto damage =DiceThrower::getInstance().throwDice(die);
			damage += dndSource->getAbilityModifier();
			
			dndTarget->receiveDamage(damage);
		}
	}
	else {
		throw badCharacter;
	}
}

void DnDModel::performLevelUp(ICharacter& actor) const {
	actor.levelUp();
}
