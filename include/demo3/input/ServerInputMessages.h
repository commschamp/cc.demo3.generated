/// @file
/// @brief Contains definition of all server input messages bundle.

#pragma once

#include <tuple>
#include "demo3/message/Connect.h"
#include "demo3/message/Msg1.h"
#include "demo3/options/DefaultOptions.h"

namespace demo3
{

namespace input
{

/// @brief Messages of the protocol in ascending order.
/// @tparam TBase Base class of all the messages.
/// @tparam TOpt Protocol definition options.
template <typename TBase, typename TOpt = demo3::options::DefaultOptions>
using ServerInputMessages =
    std::tuple<
        demo3::message::Connect<TBase, TOpt>,
        demo3::message::Msg1<TBase, TOpt>
    >;

} // namespace input

} // namespace demo3

