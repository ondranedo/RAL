#pragma once

#include "baseComponent.h"
#include "baseFactory.h"
#include "../containers/vector.h"
#include "../containers/pair.h"
#include "../containers/string.h"

#define RAL_COMPONENT_SCANTHRU for(i16_t i = 0; i < m_components.size(); i++)
#define RAL_FACTORY_SCANTHRU for(i8_t i = 0; i < m_factories.size(); i++)
#define RAL_COMPONENT_ISNAME if(m_components[i].m_name == name)

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
        struct Component{

            BaseComponent* m_component;
            String m_name;
            // flags
            bool m_wasInitialized;
        };

        struct Factory{

            BaseFactory<BaseComponent>* m_factory;
            //flags
            bool m_hadDefaultCreated;
        };

        Vector<Component> m_components;
        Vector<Factory> m_factories;

        i16_t findIndex(const String& name);
    };
}