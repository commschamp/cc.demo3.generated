// Generated by commsdsl2comms v3.5.3

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref demo3::Message interface fields.

#pragma once

#include <cstdint>

namespace demo3
{

/// @brief Common types and functions for fields of 
///     @ref demo3::Message interface.
/// @see demo3::MessageFields
struct MessageFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref demo3::MessageFields::Version field.
    struct VersionCommon
    {
        /// @brief Re-definition of the value type used by
        ///     demo3::MessageFields::Version field.
        using ValueType = std::uint8_t;
    
        /// @brief Name of the @ref demo3::MessageFields::Version field.
        static const char* name()
        {
            return "Version";
        }
        
    };
    
};
} // namespace demo3


