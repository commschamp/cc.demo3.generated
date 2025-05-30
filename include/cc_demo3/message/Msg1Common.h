// Generated by commsdsl2comms v7.1.0

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref cc_demo3::message::Msg1 message and its fields.

#pragma once

#include <cstdint>

namespace cc_demo3
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref cc_demo3::message::Msg1 message.
/// @see cc_demo3::message::Msg1Fields
struct Msg1FieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref cc_demo3::message::Msg1Fields::F1 field.
    struct F1Common
    {
        /// @brief Re-definition of the value type used by
        ///     cc_demo3::message::Msg1Fields::F1 field.
        using ValueType = std::uint8_t;

        /// @brief Name of the @ref cc_demo3::message::Msg1Fields::F1 field.
        static const char* name()
        {
            return "F1";
        }

        /// @brief Compile time detection of special values presence.
        static constexpr bool hasSpecials()
        {
            return false;
        }
    };

    /// @brief Common types and functions for
    ///     @ref cc_demo3::message::Msg1Fields::F2 field.
    struct F2Common
    {
        /// @brief Re-definition of the value type used by
        ///     cc_demo3::message::Msg1Fields::F2 field.
        using ValueType = std::uint8_t;

        /// @brief Name of the @ref cc_demo3::message::Msg1Fields::F2 field.
        static const char* name()
        {
            return "F2";
        }

        /// @brief Compile time detection of special values presence.
        static constexpr bool hasSpecials()
        {
            return false;
        }
    };

    /// @brief Common types and functions for
    ///     @ref cc_demo3::message::Msg1Fields::F3 field.
    struct F3Common
    {
        /// @brief Re-definition of the value type used by
        ///     cc_demo3::message::Msg1Fields::F3 field.
        using ValueType = std::uint8_t;

        /// @brief Name of the @ref cc_demo3::message::Msg1Fields::F3 field.
        static const char* name()
        {
            return "F3";
        }

        /// @brief Compile time detection of special values presence.
        static constexpr bool hasSpecials()
        {
            return false;
        }
    };

    /// @brief Common types and functions for
    ///     @ref cc_demo3::message::Msg1Fields::F4 field.
    struct F4Common
    {
        /// @brief Re-definition of the value type used by
        ///     cc_demo3::message::Msg1Fields::F4 field.
        using ValueType = std::uint8_t;

        /// @brief Name of the @ref cc_demo3::message::Msg1Fields::F4 field.
        static const char* name()
        {
            return "F4";
        }

        /// @brief Compile time detection of special values presence.
        static constexpr bool hasSpecials()
        {
            return false;
        }
    };
};

/// @brief Common types and functions of 
///     @ref cc_demo3::message::Msg1 message.
struct Msg1Common
{
    /// @brief Name of the @ref cc_demo3::message::Msg1 message.
    static const char* name()
    {
        return "Msg1";
    }
};

} // namespace message

} // namespace cc_demo3
