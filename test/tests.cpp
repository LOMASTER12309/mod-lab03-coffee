// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(TestAutomata, turnOn) {
    Automata automata;
    automata.on();
    EXPECT_EQ(STATES::WAIT, automata.getState());
}

TEST(TestAutomata, turnOff) {
    Automata automata;
    automata.on();
    automata.off();
    EXPECT_EQ(STATES::OFF, automata.getState());
}

TEST(TestAutomata, addAccept) {
    Automata automata;
    automata.on();
    automata.coin(20);
    EXPECT_EQ(STATES::ACCEPT, automata.getState());
}

TEST(TestAutomata, addCoin) {
    Automata automata;
    automata.on();
    automata.coin(20);
    automata.coin(100);
    EXPECT_EQ(120, automata.getBalance());
}

TEST(TestAutomata, choiceFail) {
    Automata automata;
    automata.on();
    automata.coin(10);
    automata.coin(100);
    automata.choice("Cappuccino");
    EXPECT_EQ(STATES::WAIT, automata.getState());
    EXPECT_EQ(110, automata.getBalance());
}

TEST(TestAutomata, choiceSuccess) {
    Automata automata;
    automata.on();
    automata.coin(10);
    automata.coin(100);
    automata.choice("Americano");
    EXPECT_EQ(STATES::WAIT, automata.getState());
    EXPECT_EQ(10, automata.getBalance());
}

TEST(TestAutomata, doubleOrder) {
    Automata automata;
    automata.on();
    automata.coin(200);
    automata.coin(100);
    automata.choice("Latte");
    automata.choice("Glace");
    EXPECT_EQ(STATES::WAIT, automata.getState());
    EXPECT_EQ(50, automata.getBalance());
}

TEST(TestAutomata, doubleOrderWithDep) {
    Automata automata;
    automata.on();
    automata.coin(200);
    automata.choice("Latte");
    automata.coin(100);
    automata.choice("Glace");
    EXPECT_EQ(STATES::WAIT, automata.getState());
    EXPECT_EQ(50, automata.getBalance());
}

TEST(TestAutomata, tripleOrderFail) {
    Automata automata;
    automata.on();
    automata.coin(200);
    automata.choice("Latte");
    automata.coin(100);
    automata.choice("Glace");
    automata.coin(10);
    automata.choice("Green Tea");
    EXPECT_EQ(STATES::WAIT, automata.getState());
    EXPECT_EQ(60, automata.getBalance());
}

TEST(TestAutomata, cancel) {
    Automata automata;
    automata.on();
    automata.coin(200);
    automata.cancel();
    EXPECT_EQ(STATES::WAIT, automata.getState());
    EXPECT_EQ(200, automata.getBalance());
}