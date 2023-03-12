#pragma once

namespace RAL{

    class FactoryMgr{

    public:
        void addFactory();

        void addComponent();
        void createComponent();
        void removeComponent();

        void create();
        void init();
        void release();

        void get();

    private:
        BaseFactory* factories;
        BaseComponent* components;
    };
}