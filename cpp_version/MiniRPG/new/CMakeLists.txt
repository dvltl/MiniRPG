cmake_minimum_required(VERSION 2.8.8)

project(MiniRPG)
set(MiniRPG_VERSION 0.5)
set(CMAKE_CXX_STANDARD 11)

include_directories("include")

set(SRC_PREFIX src/)
set(SRC_ROOT ${SRC_PREFIX}GameFactory.cpp ${SRC_PREFIX}RPG.cpp)
set(CHAR_PREFIX src/characters/)
set(DND_CHAR_PREFIX src/characters/dnd/)
set(SRC_CHARACTERS ${DND_CHAR_PREFIX}DnDCharacterImpl.cpp ${DND_CHAR_PREFIX}DnDPotionBuilder.cpp ${DND_CHAR_PREFIX}DnDPotion.cpp)
set(MODEL_PREFIX src/models/)
set(SRC_MODELS ${MODEL_PREFIX}DnDModel.cpp)

set(SOURCES main.cpp ${SRC_ROOT} ${SRC_CHARACTERS} ${SRC_MODELS})

add_executable(MiniRPG.${MiniRPG_VERSION} ${SOURCES})