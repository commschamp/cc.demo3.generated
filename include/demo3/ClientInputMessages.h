/// @file
/// @brief Contains definition of all client input messages bundle.

#pragma once

#include <tuple>
#include "demo3/DefaultOptions.h"

namespace demo3
{

/// @brief Messages of the protocol in ascending order.
/// @tparam TBase Base class of all the messages.
/// @tparam TOpt Protocol definition options.
template <typename TBase, typename TOpt = demo3::DefaultOptions>
using ClientInputMessages =
    std::tuple<
    >;

} // namespace demo3


