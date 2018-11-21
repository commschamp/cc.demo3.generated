/// @file
/// @brief Contains definition of <b>"MsgId"</b> field.

#pragma once

#include <cstdint>
#include "comms/field/EnumValue.h"
#include "comms/options.h"
#include "demo3/DefaultOptions.h"
#include "demo3/MsgId.h"
#include "demo3/field/FieldBase.h"

namespace demo3
{

namespace field
{

/// @brief Definition of <b>"MsgId"</b> field.
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = demo3::DefaultOptions, typename... TExtraOpts>
struct MsgId : public
    comms::field::EnumValue<
        demo3::field::FieldBase<>,
        demo3::MsgId,
        TExtraOpts...,
        comms::option::ValidNumValueRange<1, 2>
    >
{
    /// @brief Name of the field.
    static const char* name()
    {
        return "MsgId";
    }
    
};

} // namespace field

} // namespace demo3


