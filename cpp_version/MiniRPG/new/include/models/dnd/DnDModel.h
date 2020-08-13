#pragma once

#include "models/IModel.h"

class DnDModel : public IModel {
private:
	std::string getDescription() const override;

	void performHit(ICharacter&, ICharacter&) const override;
	void performHeal(ICharacter&, IHealSource&) const override;
	void performLevelUp(ICharacter&) const override;
};