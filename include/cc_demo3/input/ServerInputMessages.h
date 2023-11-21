// Generated by commsdsl2comms v6.2.4

/// @file
/// @brief Contains definition of the ServerInputMessages messages bundle.

#pragma once

#include <tuple>
#include "cc_demo3/message/Connect.h"
#include "cc_demo3/message/Msg1.h"
#include "cc_demo3/options/DefaultOptions.h"

namespace cc_demo3
{

namespace input
{

/// @brief Server input messages of the protocol in ascending order.
/// @tparam TBase Base class of all the messages.
/// @tparam TOpt Protocol definition options.
template <typename TBase, typename TOpt = cc_demo3::options::DefaultOptions>
using ServerInputMessages =
    std::tuple<
        cc_demo3::message::Connect<TBase, TOpt>,
        cc_demo3::message::Msg1<TBase, TOpt>
    >;

} // namespace input

} // namespace cc_demo3

/// @brief Create type aliases for the server input messages of the protocol.
/// @param prefix_ Prefix of the alias message type.
/// @param suffix_ Suffix of the alias message type.
/// @param interface_ Type of the common message interface.
/// @param opts_ Type of the used protocol definition options.
#define CC_DEMO3_ALIASES_FOR_SERVER_INPUT_MESSAGES(prefix_, suffix_, interface_, opts_) \
    using prefix_ ## Connect ## suffix_ = cc_demo3::message::Connect<interface_, opts_>; \
    using prefix_ ## Msg1 ## suffix_ = cc_demo3::message::Msg1<interface_, opts_>;

/// @brief Create type aliases for the server input messages of the protocol using default options.
/// @param prefix_ Prefix of the alias message type.
/// @param suffix_ Suffix of the alias message type.
/// @param interface_ Type of the common message interface.
#define CC_DEMO3_ALIASES_FOR_SERVER_INPUT_MESSAGES_DEFAULT_OPTIONS(prefix_, suffix_, interface_) \
    CC_DEMO3_ALIASES_FOR_SERVER_INPUT_MESSAGES(prefix_, suffix_, interface_, cc_demo3::options::DefaultOptions)
