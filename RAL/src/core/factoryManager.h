#pragma once

#include "baseComponent.h"
#include "baseFactory.h"
#include "../containers/vector.h"
#include "../containers/pair.h"
#include "../containers/string.h"

#define RAL_COMPONENT_SCANTHRU for(i16_t i = 0; i < m_components.size(); i++)
#define RAL_COMPONENT_ISNAME if(stringCompare(name, m_components[i].y))

namespace RAL{

    class FactoryMgr{

    public:
        void addFactory();

        void addComponent(BaseComponent* component, const String& name);
        void createComponent();
        void removeComponent(const String& name);

        void create();
        void init();
        void release();

        BaseComponent* get(const String& name);

    private:
        Vector<Pair<BaseComponent*, String>> m_components;
        Vector<u8_t> m_flags;
#define RAL_WAS_INITIALIZED (1 << 0)

        Vector<BaseFactory<BaseComponent>> m_factories;

        bool stringCompare(const String& a, const String& b);
        i16_t findIndex(const String& name);
    };
}