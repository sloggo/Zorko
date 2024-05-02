//
// Created by Josh Sloggett on 02/05/2024.
//
#include <utility>

#include"../Headers/Item.h"

Item::Item(std::string nameI, std::string desc) {
    name = std::move(nameI);
    description = std::move(desc);
}
