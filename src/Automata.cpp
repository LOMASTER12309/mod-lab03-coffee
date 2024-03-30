// Copyright 2024 Yuriy Nazarov

#include<iostream>
#include "Automata.h"

Automata::Automata() {
    cash = 0;
    menu["Black Tea"] = 65;
    menu["Green Tea"] = 65;
    menu["White Tea"] = 70;
    menu["Americano"] = 100;
    menu["Cappuccino"] = 120;
    menu["Latte"] = 120;
    menu["Glace"] = 130;
    menu["Espresso"] = 80;
    menu["Double Espresso"] = 110;
    state = STATES::OFF;
}

Automata::~Automata() {}

void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
    }
}

void Automata::off() {
    if (state == STATES::WAIT) {
        cash = 0;
        state = STATES::OFF;
    }
}

void Automata::coin(int DepMoney) {
    switch (state) {
    case STATES::WAIT:
        state = STATES::ACCEPT;
        cash += DepMoney;
        break;
    case STATES::ACCEPT:
        cash += DepMoney;
        break;
    }
}

void Automata::check(std::string DrinkName) {
    if (state == STATES::CHECK) {
        if (menu[DrinkName] <= cash) {
            cook(DrinkName);
        } else {
            cancel();
        }
    }
}

void Automata::choice(std::string DrinkName) {
    if ((state == STATES::WAIT) || (state == STATES::ACCEPT)) {
        state = STATES::CHECK;
        check(DrinkName);
    }
}

void Automata::cook(std::string DrinkName) {
    if (state == STATES::CHECK) {
        cash -= menu[DrinkName];
        state = STATES::COOK;
        finish();
    }
}

void Automata::finish()
{
    if (state == STATES::COOK) {
        state = STATES::WAIT;
    }
}

void Automata::cancel() {
    if ((state == STATES::CHECK) || (state == STATES::ACCEPT)) {
        state = STATES::WAIT;
    }
}

int Automata::getBalance()
{
    return cash;
}

void Automata::getMenu() {
    for (const auto& [drink, price] : menu)
        std::cout << drink << " - " << price << " руб.\n";
}

STATES Automata::getState() {
    return state;
}
