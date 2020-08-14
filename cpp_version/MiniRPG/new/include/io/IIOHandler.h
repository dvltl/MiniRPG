#pragma once

// This class should be decorated with handlers that will return game-specific actions
class IIOHandler {
protected:
	enum class MenuItem {
		FIRST, SECOND, THIRD, BAD_ITEM
	};

	virtual MenuItem handleInput() const = 0;
	virtual MenuItem handleOutput() const = 0;
};