#include <iostream>

#include "RPG.h"

std::unique_ptr<RPG> RPG::createRPG(std::unique_ptr<IModel>&& model) {
	// private constructor ==> this way of creating a pointer to object instead of std::make_unique
	return std::unique_ptr<RPG>(new RPG(std::move(model)));
}

RPG::RPG(std::unique_ptr<IModel>&& model) : m_modelUsed(std::move(model)),
	m_enemies(std::move(m_modelUsed->createEnemies())),
	m_hero(std::move(m_modelUsed->createHero())),
	m_bbeg(std::move(m_modelUsed->createBBEG()))
{}

std::string RPG::getName() const {
	return "RPG with " + m_modelUsed->getDescription();
}

IGame::Result RPG::start() {
	setAtmosphere();
	std::string inputStr;
	std::cin >> inputStr;
	std::cout << inputStr << std::endl;
	return IGame::Result::GAME_LOST;
}