// Generated by commsdsl2comms v7.1.0

/// @file
/// @brief Contains definition of <b>"Connect"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include "cc_demo3/field/FieldBase.h"
#include "cc_demo3/message/ConnectCommon.h"
#include "cc_demo3/options/DefaultOptions.h"
#include "comms/MessageBase.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"

namespace cc_demo3
{

namespace message
{

/// @brief Fields of @ref Connect.
/// @tparam TOpt Extra options
/// @see @ref Connect
/// @headerfile cc_demo3/message/Connect.h
template <typename TOpt = cc_demo3::options::DefaultOptions>
struct ConnectFields
{
    /// @brief Definition of <b>"Version"</b> field.
    class Version : public
        comms::field::IntValue<
            cc_demo3::field::FieldBase<>,
            std::uint8_t,
            comms::option::def::HasName,
            comms::option::def::DefaultNumValue<5U>
        >
    {
        using Base =
            comms::field::IntValue<
                cc_demo3::field::FieldBase<>,
                std::uint8_t,
                comms::option::def::HasName,
                comms::option::def::DefaultNumValue<5U>
            >;
    public:
        /// @brief Re-definition of the value type.
        using ValueType = typename Base::ValueType;

        /// @brief Compile time detection of special values presence.
        static constexpr bool hasSpecials()
        {
            return cc_demo3::message::ConnectFieldsCommon::VersionCommon::hasSpecials();
        }

        /// @brief Name of the field.
        static const char* name()
        {
            return cc_demo3::message::ConnectFieldsCommon::VersionCommon::name();
        }
    };

    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Version
    >;
};

/// @brief Definition of <b>"Connect"</b> message class.
/// @details
///     See @ref ConnectFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile cc_demo3/message/Connect.h
template <typename TMsgBase, typename TOpt = cc_demo3::options::DefaultOptions>
class Connect : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::Connect,
        comms::option::def::StaticNumIdImpl<1 /* 0x1 */>,
        comms::option::def::FieldsImpl<typename ConnectFields<TOpt>::All>,
        comms::option::def::MsgType<Connect<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::Connect,
            comms::option::def::StaticNumIdImpl<1 /* 0x1 */>,
            comms::option::def::FieldsImpl<typename ConnectFields<TOpt>::All>,
            comms::option::def::MsgType<Connect<TMsgBase, TOpt> >,
            comms::option::def::HasName
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated values, types and functions are:
    ///     @li @b FieldIdx_version index, @b Field_version type and @b field_version() access fuction
    ///         for @ref ConnectFields::Version field.
    COMMS_MSG_FIELDS_NAMES(
        version
    );

    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static const std::size_t MsgMaxLen = Base::doMaxLength();
    static_assert(MsgMinLen == 1U, "Unexpected min serialisation length");
    static_assert(MsgMaxLen == 1U, "Unexpected max serialisation length");

    /// @brief Name of the message.
    static const char* doName()
    {
        return cc_demo3::message::ConnectCommon::name();
    }
};

} // namespace message

} // namespace cc_demo3
