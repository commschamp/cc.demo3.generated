/// @file
/// @brief Contains definition of <b>"Connect"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include "comms/MessageBase.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "demo3/DefaultOptions.h"
#include "demo3/MsgId.h"
#include "demo3/field/FieldBase.h"

namespace demo3
{

namespace message
{

/// @brief Fields of @ref Connect.
/// @tparam TOpt Extra options
/// @see @ref Connect
/// @headerfile "demo3/message/Connect.h"
template <typename TOpt = demo3::DefaultOptions>
struct ConnectFields
{
    /// @brief Definition of <b>"Version"</b> field.
    struct Version : public
        comms::field::IntValue<
            demo3::field::FieldBase<>,
            std::uint8_t,
            comms::option::DefaultNumValue<5U>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return "Version";
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
/// @headerfile "demo3/message/Connect.h"
template <typename TMsgBase, typename TOpt = demo3::DefaultOptions>
class Connect : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::Connect,
        comms::option::StaticNumIdImpl<demo3::MsgId_Connect>,
        comms::option::FieldsImpl<typename ConnectFields<TOpt>::All>,
        comms::option::MsgType<Connect<TMsgBase, TOpt> >,
        comms::option::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::Connect,
            comms::option::StaticNumIdImpl<demo3::MsgId_Connect>,
            comms::option::FieldsImpl<typename ConnectFields<TOpt>::All>,
            comms::option::MsgType<Connect<TMsgBase, TOpt> >,
            comms::option::HasName
        >;

public:
    /// @brief Allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_ACCESS macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated functions are:
    ///     @li @b field_version() for @ref ConnectFields::Version field.
    COMMS_MSG_FIELDS_ACCESS(
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
        return "Connect";
    }
    
    
};

} // namespace message

} // namespace demo3


