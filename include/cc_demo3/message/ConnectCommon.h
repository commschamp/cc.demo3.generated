// Generated by commsdsl2comms v6.1.0

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref cc_demo3::message::Connect message and its fields.

#pragma once

#include <cstdint>

namespace cc_demo3
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref cc_demo3::message::Connect message.
/// @see cc_demo3::message::ConnectFields
struct ConnectFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref cc_demo3::message::ConnectFields::Version field.
    struct VersionCommon
    {
        /// @brief Re-definition of the value type used by
        ///     cc_demo3::message::ConnectFields::Version field.
        using ValueType = std::uint8_t;

        /// @brief Name of the @ref cc_demo3::message::ConnectFields::Version field.
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
///     @ref cc_demo3::message::Connect message.
struct ConnectCommon
{
    /// @brief Name of the @ref cc_demo3::message::Connect message.
    static const char* name()
    {
        return "Connect";
    }
};

} // namespace message

} // namespace cc_demo3
