#pragma once

#include "models/IModel.h"

class DnDModel : public IModel {
private:
	std::string getDescription() const override;

	void performAttack(ICharacter&, ICharacter&) const override;
	void performHeal(ICharacter&, IHealSource&) const override;
	void performLevelUp(ICharacter&) const override;

	const std::exception badCharacter = std::runtime_error("Unexpected character interfaces. Expected to have IDnDCharacter implementations.");
};