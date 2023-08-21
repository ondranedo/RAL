//
// Created by nedoj on 12.04.2023.
//

#include "GLTypes.h"
#include <core/utility/Logger.h>
#include <vendor/glad/gl_4.0_core_debug/include/glad/gl.h>
namespace RAL {
    int GLTypes::getGLType(Types::DataType type) {
        switch (type) {
            case Types::DataType::VOID: return GL_NONE;
            case Types::DataType::FLOAT: return GL_FLOAT;
            case Types::DataType::DOUBLE: return GL_DOUBLE;
            case Types::DataType::INT8: return GL_BYTE;
            case Types::DataType::INT16: return GL_SHORT;
            case Types::DataType::INT32: return GL_INT;
            case Types::DataType::INT64: { RAL_LOG_ERROR("GL does not support 64 bit integers"); return GL_NONE;};
            case Types::DataType::UINT8: return GL_UNSIGNED_BYTE;
            case Types::DataType::UINT16: return GL_UNSIGNED_SHORT;
            case Types::DataType::UINT32: return GL_UNSIGNED_INT;
            case Types::DataType::UINT64: { RAL_LOG_ERROR("GL does not support unsigned 64 bit integers"); return GL_NONE;};
        }
        RAL_LOG_ERROR("Unknown data type when conversion to GL [type:%s]", Types::toString(type).c_str());
        return GL_NONE;
    }
} // RAL