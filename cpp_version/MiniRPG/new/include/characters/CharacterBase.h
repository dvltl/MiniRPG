#pragma once

#include <string>
#include <memory>

#include "characters/ICharacter.h"
#include "models/IHealModel.h"
#include "models/ILevelingModel.h"

class CharacterBase : public ICharacter {
public:
	CharacterBase(std::string name, std::unique_ptr<IHealModel> healModel, std::unique_ptr<ILevelingModel> levelingModel) :
		m_name(name), m_healModel(std::move(healModel)), m_levelingModel(std::move(levelingModel))
	{}

	std::string getName() const final { return m_name; };
	void levelUp() final { m_levelingModel->levelUp(*this); };
	void heal(HP amount) final { m_healModel->heal(*this, amount); };

private:
	std::string m_name;
	std::unique_ptr<IHealModel> m_healModel;
	std::unique_ptr<ILevelingModel> m_levelingModel;
};