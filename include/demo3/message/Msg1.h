/// @file
/// @brief Contains definition of <b>"Msg1"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include "comms/MessageBase.h"
#include "comms/field/IntValue.h"
#include "comms/field/Optional.h"
#include "comms/options.h"
#include "demo3/MsgId.h"
#include "demo3/field/FieldBase.h"
#include "demo3/options/DefaultOptions.h"

namespace demo3
{

namespace message
{

/// @brief Fields of @ref Msg1.
/// @tparam TOpt Extra options
/// @see @ref Msg1
/// @headerfile "demo3/message/Msg1.h"
template <typename TOpt = demo3::options::DefaultOptions>
struct Msg1Fields
{
    /// @brief Definition of <b>"F1"</b> field.
    struct F1 : public
        comms::field::IntValue<
            demo3::field::FieldBase<>,
            std::uint8_t,
            comms::option::DefaultNumValue<1>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return "F1";
        }
        
    };
    
    /// @brief Inner field of @ref F2 optional.
    struct F2Field : public
        comms::field::IntValue<
            demo3::field::FieldBase<>,
            std::uint8_t,
            comms::option::DefaultNumValue<2>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return "F2";
        }
        
    };
    
    /// @brief Definition of <b>"F2"</b> field.
    struct F2 : public
        comms::field::Optional<
            F2Field,
            comms::option::ExistsByDefault,
            comms::option::ExistsUntilVersion<1U>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return F2Field::name();
        }
    };
    
    /// @brief Inner field of @ref F3 optional.
    struct F3Field : public
        comms::field::IntValue<
            demo3::field::FieldBase<>,
            std::uint8_t,
            comms::option::DefaultNumValue<3>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return "F3";
        }
        
    };
    
    /// @brief Definition of <b>"F3"</b> field.
    struct F3 : public
        comms::field::Optional<
            F3Field,
            comms::option::ExistsByDefault,
            comms::option::ExistsSinceVersion<3U>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return F3Field::name();
        }
    };
    
    /// @brief Inner field of @ref F4 optional.
    struct F4Field : public
        comms::field::IntValue<
            demo3::field::FieldBase<>,
            std::uint8_t,
            comms::option::DefaultNumValue<4>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return "F4";
        }
        
    };
    
    /// @brief Definition of <b>"F4"</b> field.
    struct F4 : public
        comms::field::Optional<
            F4Field,
            comms::option::ExistsByDefault,
            comms::option::ExistsBetweenVersions<3U, 4U>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return F4Field::name();
        }
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        F1,
        F2,
        F3,
        F4
    >;
};

/// @brief Definition of <b>"Msg1"</b> message class.
/// @details
///     See @ref Msg1Fields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "demo3/message/Msg1.h"
template <typename TMsgBase, typename TOpt = demo3::options::DefaultOptions>
class Msg1 : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::Msg1,
        comms::option::StaticNumIdImpl<demo3::MsgId_Msg1>,
        comms::option::FieldsImpl<typename Msg1Fields<TOpt>::All>,
        comms::option::MsgType<Msg1<TMsgBase, TOpt> >,
        comms::option::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::Msg1,
            comms::option::StaticNumIdImpl<demo3::MsgId_Msg1>,
            comms::option::FieldsImpl<typename Msg1Fields<TOpt>::All>,
            comms::option::MsgType<Msg1<TMsgBase, TOpt> >,
            comms::option::HasName
        >;

public:
    /// @brief Allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_ACCESS macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated functions are:
    ///     @li @b field_f1() for @ref Msg1Fields::F1 field.
    ///     @li @b field_f2() for @ref Msg1Fields::F2 field.
    ///     @li @b field_f3() for @ref Msg1Fields::F3 field.
    ///     @li @b field_f4() for @ref Msg1Fields::F4 field.
    COMMS_MSG_FIELDS_ACCESS(
        f1,
        f2,
        f3,
        f4
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static const std::size_t MsgMaxLen = Base::doMaxLength();
    static_assert(MsgMinLen == 1U, "Unexpected min serialisation length");
    static_assert(MsgMaxLen == 4U, "Unexpected max serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return "Msg1";
    }
    
    
};

} // namespace message

} // namespace demo3


