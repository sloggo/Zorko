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
)
