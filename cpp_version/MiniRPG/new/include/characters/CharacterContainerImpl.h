#pragma once

#include <queue>
#include <memory>

#include "characters/ICharacter.h"

class CharacterContainerImpl {
public:
	void add(std::unique_ptr<ICharacter>);
	std::unique_ptr<ICharacter> getNext();
	bool isEmpty() const;
private:
	std::queue<std::unique_ptr<ICharacter>> m_container;
};