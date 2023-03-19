#pragma once

#include "baseComponent.h"
#include "baseFactory.h"
#include "../containers/vector.h"
#include "../containers/pair.h"
#include "../containers/string.h"

#define stringize(string) #string

#define RAL_COMPONENT_SCANTHRU for(i = 0; i < m_components.size(); i++)
#define RAL_FACTORY_SCANTHRU for(i = 0; i < m_factories.size(); i++)
#define RAL_COMPONENT_ISNAME if(m_components[i].m_name == name)

namespace RAL{

    class FactoryMgr{

    public:
        template<typename factory> void addFactory();

        void addComponent(BaseComponent* component, const String& name);
        template<typename factory> void createComponent(const String& name);
        void removeComponent(const String& name);

        void create();
        void init();
        void release();

        BaseComponent* operator[](const String& name);

    private:
        struct Component{

            BaseComponent* m_component;
            String m_name;
            // flags
            bool m_wasInitialized;
        };

        struct Factory{

            BaseFactory<BaseComponent>* m_factory;
            String m_productName;
            //flags
            bool m_hadDefaultCreated;
        };

        Vector<Component> m_components;
        Vector<Factory> m_factories;
    };
}