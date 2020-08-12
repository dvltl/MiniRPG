#include "characters/CharacterContainer.h"
#include "characters/CharacterContainerImpl.h"

CharacterContainer::CharacterContainer() : m_container(std::make_unique<CharacterContainerImpl>()) {}

CharacterContainer::~CharacterContainer() {}

void CharacterContainer::addCharacter(std::unique_ptr<ICharacter> ch) {
	m_container->add(std::move(ch));
}

std::unique_ptr<ICharacter> CharacterContainer::getNextCharacter() {
	return std::move(m_container->getNext());
}

bool CharacterContainer::isEmpty() const {
	return m_container->isEmpty();
}