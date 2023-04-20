// Copyright (C) 2023 Ondřej Nedojedlý (https://www.github.com/ondranedo).
// This file is part of `RAL` project which is released under MIT licence.
// See file LICENSE for full license details.

#include <RAL/Layers.h>
#include <RAL/Games.h>

#include <iostream>

class TestLayer : public RAL::Layer
{
public:
    void onEvent(RAL::Event *event) override {

    }

    void onUpdate() override {

    }

    void onAttach() override {

    }

    void onDetach() override {

    }

};

class TestGame : public RAL::BaseGame
{
public:
    void onUpdate() override {

    }

    void onStartup() override {
        addLayer(new TestLayer());
    }

    void onShutdown() override {
    }
};

RAL::BaseGame* RAL::createGame()
{
    return new TestGame();
}