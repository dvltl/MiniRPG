#pragma once

#include "models/IHealSource.h"

#include <memory>

class IHealSourceBuilder {
public:
	virtual std::unique_ptr<IHealSource> createHealSource() const = 0;
};