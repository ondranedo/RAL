//
// Created by Vojta on 11.03.2023.
//

#pragma once
namespace RAL
{
    class BaseComponent
    {
    public:
        virtual void init() = 0;
        virtual void release() = 0;
        virtual ~BaseComponent();
    };
}
