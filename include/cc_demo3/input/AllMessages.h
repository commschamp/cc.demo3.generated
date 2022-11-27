// Generated by commsdsl2comms v5.1.3

/// @file
/// @brief Contains definition of the AllMessages messages bundle.

#pragma once

#include <tuple>
#include "cc_demo3/message/Connect.h"
#include "cc_demo3/message/Msg1.h"
#include "cc_demo3/options/DefaultOptions.h"

namespace cc_demo3
{

namespace input
{

/// @brief Messages of the protocol in ascending order.
/// @tparam TBase Base class of all the messages.
/// @tparam TOpt Protocol definition options.
template <typename TBase, typename TOpt = cc_demo3::options::DefaultOptions>
using AllMessages =
    std::tuple<
        cc_demo3::message::Connect<TBase, TOpt>,
        cc_demo3::message::Msg1<TBase, TOpt>
    >;

} // namespace input

} // namespace cc_demo3
