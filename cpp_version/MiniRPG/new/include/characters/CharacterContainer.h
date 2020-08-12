#pragma once

#include <memory>

// pimpl idiom

class CharacterContainerImpl;

class CharacterContainer {
public:
	// need to define those methods, otherwise there will be compilation error
	CharacterContainer();
	~CharacterContainer();

	void addCharacter(std::unique_ptr<ICharacter>);
	std::unique_ptr<ICharacter> getNextCharacter();
	bool isEmpty() const;

private:
	std::unique_ptr<CharacterContainerImpl> m_container;
};