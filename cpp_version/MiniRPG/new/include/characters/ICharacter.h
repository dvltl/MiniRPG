#pragma once

#include <string>

class ICharacter {
public:
	virtual std::string getName() const = 0;
	virtual void speak(const ICharacter &) const = 0;
};
