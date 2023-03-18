#pragma once

#include "baseComponent.h"
#include "baseFactory.h"
#include "../containers/vector.h"
#include "../containers/pair.h"
#include "../containers/string.h"

#define stringize(string) String( #string )

#define RAL_COMPONENT_SCANTHRU u16_t i; for(i = 0; i < m_components.size(); i++)
#define RAL_FACTORY_SCANTHRU u8_t i; for(i = 0; i < m_factories.size(); i++)
#define RAL_COMPONENT_ISNAME if(m_components[i].m_name == name)
#define RAL_FACTORY_ISNAME if(m_factories[i].m_name == stringize(name) )

namespace RAL{

    class FactoryMgr{

    public:
        template<class name> void addFactory();

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
            String m_name;
            //flags
            bool m_hadDefaultCreated;
        };

        Vector<Component> m_components;
        Vector<Factory> m_factories;
    };
}