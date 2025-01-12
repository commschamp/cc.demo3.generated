// Generated by commsdsl2comms v7.0.0

/// @file
/// @brief Contains definition of <b>"Message"</b> interface class.

#pragma once

#include <cstdint>
#include <tuple>
#include "cc_demo3/MessageCommon.h"
#include "cc_demo3/MsgId.h"
#include "cc_demo3/field/FieldBase.h"
#include "comms/Message.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"

namespace cc_demo3
{

/// @brief Extra transport fields of @ref Message interface class.
/// @see @ref Message
/// @headerfile cc_demo3/Message.h
struct MessageFields
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
            return cc_demo3::MessageFieldsCommon::VersionCommon::hasSpecials();
        }

        /// @brief Name of the field.
        static const char* name()
        {
            return cc_demo3::MessageFieldsCommon::VersionCommon::name();
        }
    };

    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Version
    >;
};

/// @brief Definition of <b>"Message"</b> common interface class.
/// @tparam TOpt Interface definition options
/// @headerfile cc_demo3/Message.h
template <typename... TOpt>
class Message : public
    comms::Message<
        TOpt...,
        comms::option::def::BigEndian,
        comms::option::def::MsgIdType<cc_demo3::MsgId>,
        comms::option::def::ExtraTransportFields<MessageFields::All>,
        comms::option::def::VersionInExtraTransportFields<0U>
    >
{
    using Base =
        comms::Message<
            TOpt...,
            comms::option::def::BigEndian,
            comms::option::def::MsgIdType<cc_demo3::MsgId>,
            comms::option::def::ExtraTransportFields<MessageFields::All>,
            comms::option::def::VersionInExtraTransportFields<0U>
        >;
public:
    /// @brief Allow access to extra transport fields.
    /// @details See definition of @b COMMS_MSG_TRANSPORT_FIELDS_NAMES macro
    ///     related to @b comms::Message class from COMMS library
    ///     for details.
    ///
    ///     The generated values, types and functions are:
    ///     @li @b TransportFieldIdx_version index, @b TransportField_version type
    ///         and @b transportField_version() access fuction for @ref MessageFields::Version field.
    COMMS_MSG_TRANSPORT_FIELDS_NAMES(
        version
    );
};

} // namespace cc_demo3
