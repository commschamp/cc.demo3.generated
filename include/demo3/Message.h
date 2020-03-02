// Generated by commsdsl2comms v3.3.3

/// @file
/// @brief Contains definition of <b>"Message"</b> interface class.

#pragma once

#include <cstdint>
#include <tuple>
#include "comms/Message.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "demo3/MessageCommon.h"
#include "demo3/MsgId.h"
#include "demo3/field/FieldBase.h"

namespace demo3
{

/// @brief Extra transport fields of @ref Message interface class.
/// @see @ref Message
/// @headerfile "demo3/Message.h"
struct MessageFields
{
    /// @brief Definition of <b>"Version"</b> field.
    struct Version : public
        comms::field::IntValue<
            demo3::field::FieldBase<>,
            std::uint8_t,
            comms::option::def::DefaultNumValue<5U>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return demo3::MessageFieldsCommon::VersionCommon::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Version
    >;
};

/// @brief Definition of <b>"Message"</b> common interface class.
/// @tparam TOpt Interface definition options
/// @headerfile "demo3/Message.h"
template <typename... TOpt>
class Message : public
    comms::Message<
        TOpt...,
        comms::option::def::BigEndian,
        comms::option::def::MsgIdType<demo3::MsgId>,
        comms::option::def::ExtraTransportFields<MessageFields::All>,
        comms::option::def::VersionInExtraTransportFields<0U>
    >
{
    using Base =
        comms::Message<
            TOpt...,
            comms::option::def::BigEndian,
            comms::option::def::MsgIdType<demo3::MsgId>,
            comms::option::def::ExtraTransportFields<MessageFields::All>,
            comms::option::def::VersionInExtraTransportFields<0U>
        >;
public:
    /// @brief Allow access to extra transport fields.
    /// @details See definition of @b COMMS_MSG_TRANSPORT_FIELDS_NAMES macro
    ///     related to @b comms::Message class from COMMS library
    ///     for details.
    ///
    ///     The generated functions are:
    ///     @li @b TransportField_version type and @b transportField_version() function for
    ///         @ref MessageFields::Version field.
    COMMS_MSG_TRANSPORT_FIELDS_NAMES(
        version
    );
};

} // namespace demo3


