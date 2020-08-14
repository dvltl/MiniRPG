cmake_minimum_required(VERSION 2.8.8)

project(MiniRPG)
set(MiniRPG_VERSION 0.5)
set(CMAKE_CXX_STANDARD 11)

include_directories("include")

set(SRC_PREFIX src/)
set(CHAR_PREFIX src/characters/)
set(DND_PREFIX dnd/)
set(MODEL_PREFIX src/models/)

set(SRC_ROOT ${SRC_PREFIX}GameFactory.cpp ${SRC_PREFIX}RPG.cpp)

set(SRC_CHARACTERS ${CHAR_PREFIX}${DND_PREFIX}DnDCharacterBuilder.cpp ${CHAR_PREFIX}${DND_PREFIX}DnDCharacterImpl.cpp)

set(SRC_MODELS ${MODEL_PREFIX}${DND_PREFIX}DnDModel.cpp ${MODEL_PREFIX}${DND_PREFIX}DiceThrower.cpp
	${MODEL_PREFIX}${DND_PREFIX}DnDPotionBuilder.cpp ${MODEL_PREFIX}${DND_PREFIX}DnDPotion.cpp)

set(SOURCES main.cpp ${SRC_ROOT} ${SRC_CHARACTERS} ${SRC_MODELS})

add_executable(MiniRPG.${MiniRPG_VERSION} ${SOURCES})