#pragma once
#include "../../pch.h"
#include "../../containers/string.h"

//TO DO:
//	-MUTEX lock
//	-

namespace RAL
{
    class Window
    {
    public:
        Window();
        virtual ~Window();
        virtual void init() = 0;
        virtual void destroy() = 0;
        virtual void makeContextCurrent() = 0;
        virtual void onUpdate() = 0;
        virtual void setEvenCallBack() = 0;

        virtual void setDims(const RAL::Pair<u8_t, u8_t>& dimsWH) = 0;

        virtual void vSyncEnable() = 0;
        virtual void vSyncDisable() = 0;
    protected:
        u32_t m_width;
        u32_t m_height;
        RAL::String m_title;
    };
}