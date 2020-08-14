#include <iostream>

#include "RPG.h"

std::unique_ptr<RPG> RPG::createRPG(
	std::unique_ptr<IModel>&& mechanicsModel,
	std::unique_ptr<ICharacterBuilder>&& actorBuilder,
	std::unique_ptr<IHealSourceBuilder>&& healBuilder
) {
	// private constructor ==> this way of creating a pointer to object instead of std::make_unique
	return std::unique_ptr<RPG>(new RPG(std::move(mechanicsModel), std::move(actorBuilder), std::move(healBuilder)));
}

RPG::RPG(std::unique_ptr<IModel>&& mechanicsModel, std::unique_ptr<ICharacterBuilder>&& actorBuilder, std::unique_ptr<IHealSourceBuilder>&& healBuilder) : 
	m_modelUsed(std::move(mechanicsModel)),
	m_healBuilder(std::move(healBuilder)),
	m_actorBuilder(std::move(actorBuilder)),
	m_enemies(std::move(m_actorBuilder->createEnemies())),
	m_hero(std::move(m_actorBuilder->createHero())),
	m_bbeg(std::move(m_actorBuilder->createBBEG()))
{}

std::string RPG::getName() const {
	return "RPG with " + m_modelUsed->getDescription();
}

void RPG::setAtmosphere() const {
	// TODO: implement this
}

void RPG::battle(ICharacter& firstActor, ICharacter& secondActor) {
	while (firstActor.isAlive() && secondActor.isAlive()) {
		/*
		auto result = m_battleHandler->handleInput();

		// TODO: Maybe introduce another abstraction that would transform MenuItems into Menu-specific Actions?
		switch (result) {
		case IIOHandler::MenuItem::FIRST:
			m_modelUsed->performAttack(firstActor, secondActor);
			m_modelUsed->performAttack(secondActor, firstActor);
			break;
		case IIOHandler::MenuItem::SECOND:
			m_modelUsed->performHeal(firstActor, *m_healBuilder->createHealSource());
			break;
		case IIOHandler::MenuItem::THIRD:
			// m_modelUsed->performFlee(firstActor, secondActor);
		default:
			break;
		}
		*/
	}
	// TODO: Award XP and Gold to the character instead
	m_modelUsed->performLevelUp(firstActor);
}

IGame::Result RPG::mainLoop() {
	auto result = IGame::Result::GAME_WON;

	while (!m_enemies->isEmpty()) {
		auto nextEnemy = m_enemies->getNext();
		battle(*m_hero, *nextEnemy);
		if (!m_hero->isAlive()) {
			result = IGame::Result::GAME_LOST;
			break;
		}
	}

	battle(*m_hero, *m_bbeg);
	if (!m_hero->isAlive()) {
		result = IGame::Result::GAME_LOST;
	}

	return result;
}

IGame::Result RPG::start() {
	setAtmosphere();
	std::string inputStr;
	std::cin >> inputStr;
	std::cout << inputStr << std::endl;
	return mainLoop();
}