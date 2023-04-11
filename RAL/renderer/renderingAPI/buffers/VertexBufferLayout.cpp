/////////////////////////////////////////////////////////
// Copyright (C) 2023                                  //
// Ondřej Nedojedlý (https://www.github.com/ondranedo),//
// Matyáš Noska (https://www.github.com/sutiama),      //
// Vojtěch Šokala (https://github.com/Karnatour),      //
// Adam Wiszczor (https://github.com/1nome).           //
//                                                     //
// This file is part of `RAL_PROJECT` project          //
// which is released under `GNU General Public         //
// License v3.0` license.                              //
// See file `LICENSE` for full license details.        //
/////////////////////////////////////////////////////////
#include "VertexBufferLayout.h"
#include <core/utility/Logger.h>
namespace RAL
{

    VertexBufferLayout::VertexBufferLayout() : m_layout({}) {}

    VertexBufferLayout::Layout VertexBufferLayout::getLayout() const { return m_layout; }

    VertexBufferLayout::VertexBufferLayout(const Layout& layout) : m_layout(layout) {}
    VertexBufferLayout::VertexBufferLayout(VertexBufferLayout::Layout &&layout) : m_layout(std::move(layout)) {}

    void VertexBufferLayout::setLayout(const Layout& layout){ m_layout = layout; }
    void VertexBufferLayout::setLayout(Layout&& layout){ m_layout = std::move(layout); }

    std::string VertexBufferLayout::EntryTypeToString(VertexBufferLayout::LayoutEntryType type) {
        switch (type) {
            case VertexBufferLayout::LayoutEntryType::COLOUR_RGB: return "Colour RGB";
            case VertexBufferLayout::LayoutEntryType::COLOUR_RGBA: return "Colour RGB-A";
            case VertexBufferLayout::LayoutEntryType::POS_XY: return "Position XY";
            case VertexBufferLayout::LayoutEntryType::POS_XYZ: return "Position XYZ";
        }

        RAL_LOG_ERROR("Unknown layout entry type to string");
        return "Unknown";
    }

    uint8_t VertexBufferLayout::EntryTypeSize(VertexBufferLayout::LayoutEntryType type) {
        uint8_t size = EntryTypeComponents(type) * Types::size(EntryTypeToDataType(type));
        return size;
    }

    uint8_t VertexBufferLayout::EntryTypeComponents(VertexBufferLayout::LayoutEntryType type) {
        switch (type) {
            case VertexBufferLayout::LayoutEntryType::COLOUR_RGB:
            case VertexBufferLayout::LayoutEntryType::POS_XYZ: return 3;
            case VertexBufferLayout::LayoutEntryType::COLOUR_RGBA: return 4;
            case VertexBufferLayout::LayoutEntryType::POS_XY: return 2;
        }

        RAL_LOG_ERROR("Unknown layout component count in entry type");
        return 0;
    }


    uint32_t VertexBufferLayout::getStride() const {
        uint32_t stride = 0;
        for(auto& entry : m_layout) {
            stride += EntryTypeSize(entry);
        }
        return stride;
    }

    Types::DataType VertexBufferLayout::EntryTypeToDataType(VertexBufferLayout::LayoutEntryType type) {
        switch (type) {
            case VertexBufferLayout::LayoutEntryType::COLOUR_RGB:
            case VertexBufferLayout::LayoutEntryType::COLOUR_RGBA: return Types::DataType::UINT8;
            case VertexBufferLayout::LayoutEntryType::POS_XY:
            case VertexBufferLayout::LayoutEntryType::POS_XYZ: return Types::DataType::FLOAT;
        }

        RAL_LOG_ERROR("Unknown layout entry type data type");
        return Types::DataType::VOID;
    }
} // RAL*