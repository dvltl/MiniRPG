#include "characters/CharacterContainerImpl.h"

#include <memory>

void CharacterContainerImpl::add(std::unique_ptr<ICharacter> ch) {
	m_container.emplace(std::move(ch));
}

std::unique_ptr<ICharacter> CharacterContainerImpl::getNext() {
	std::unique_ptr<ICharacter> result = std::move(m_container.front());
	m_container.pop();
	return std::move(result);
}

bool CharacterContainerImpl::isEmpty() const {
	return m_container.empty();
}