// Generated by commsdsl2comms v3.7.0

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref demo3::message::Connect message and its fields.

#pragma once

#include <cstdint>
#include <type_traits>
#include <utility>

namespace demo3
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref demo3::message::Connect message.
/// @see demo3::message::ConnectFields
struct ConnectFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref demo3::message::ConnectFields::Version field.
    struct VersionCommon
    {
        /// @brief Re-definition of the value type used by
        ///     demo3::message::ConnectFields::Version field.
        using ValueType = std::uint8_t;
    
        /// @brief Name of the @ref demo3::message::ConnectFields::Version field.
        static const char* name()
        {
            return "Version";
        }
        
        /// @brief Compile time detection of special values presence.
        static constexpr bool hasSpecials()
        {
            return false;
        }
        
    };
    
};

/// @brief Common types and functions of 
///     @ref demo3::message::Connect message.
/// @see demo3::message::Connect
struct ConnectCommon
{
    /// @brief Name of the @ref demo3::message::Connect message.
    static const char* name()
    {
        return "Connect";
    }
    
};

} // namespace message

} // namespace demo3


