// Copyright 2024 Yuriy Nazarov

#include "Automata.h"
#include <iostream>

int main() {
    Automata automata;
    automata.on();
    automata.coin(20);
    automata.coin(110);
    automata.choice("Cappuccino");
    std::cout << automata.getBalance();
    return 0;
}
