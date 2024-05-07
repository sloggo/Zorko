cmake_minimum_required(VERSION 3.28)
project(untitled2)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled2 main.cpp
        Headers/Player.h
        Headers/Player.h
        Headers/Subject.h
        Headers/Observer.h
        Headers/Item.h
        Headers/Weapon.h
        Headers/Enemy.h
        Headers/Battlable.h
        Headers/Runnable.h
        Headers/Room.h
        Headers/Stage.h
        Classes/Subject.cpp
        Classes/Observer.cpp
        Headers/InputHandler.h
        Classes/InputHandler.cpp
        Classes/Player.cpp
        Classes/Weapon.cpp
        Classes/Item.cpp
        Classes/Battlable.cpp
        Headers/DataHandler.h
        Classes/DataHandler.cpp
        Classes/Stage.cpp
        Classes/Room.cpp
        Classes/Runnable.cpp
        utils.cpp
        utils.h
        Headers/GameState.h
        Classes/GameState.cpp
        Headers/Potion.h
        Classes/Potion.cpp
        Classes/Enemy.cpp
        Headers/BattleHandler.h
        Classes/BattleHandler.cpp
)
