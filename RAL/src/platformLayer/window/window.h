#pragma once
#include "../../pch.h"

//TO DO:
//	-MUTEX lock
//	-

namespace RAL
{
    class Window
    {
    public:
        virtual ~Window();
        virtual void init() = 0;
        virtual void Destroy() = 0;
        virtual void MakeContextCurrent() = 0;
        virtual void onUpdate() = 0;

        virtual void setDims(const RAL::Pair<u8_t, u8_t>& dimsWH) = 0;

        virtual void VSyncenable() = 0;
        virtual void VSyncdisable() = 0;
    protected:
        struct Config
        {
            u32_t m_width;
            u32_t m_height;
            const char* m_title;

            Config(u32_t width = 1280,
                   u32_t height = 720,
                   const char* title = "RAL")
                    : m_width(width), m_height(height), m_title(title) {}
        };
        Config m_config;
    };
}