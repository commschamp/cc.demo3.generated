// Generated by commsdsl2comms v6.3.0

/// @file
/// @brief Contains definition of protocol server default options.

#pragma once

#include "cc_demo3/options/DefaultOptions.h"

namespace cc_demo3
{

namespace options
{

/// @brief Default server options of the protocol.
template <typename TBase = cc_demo3::options::DefaultOptions>
struct ServerDefaultOptionsT : public TBase
{
    /// @brief Extra options for messages.
    struct message : public TBase::message
    {
        /// @brief Extra options for @ref
        ///     cc_demo3::message::Connect message.
        using Connect =
            std::tuple<
                comms::option::app::NoWriteImpl,
                comms::option::app::NoRefreshImpl,
                typename TBase::message::Connect
            >;

        /// @brief Extra options for @ref
        ///     cc_demo3::message::Msg1 message.
        using Msg1 =
            std::tuple<
                comms::option::app::NoWriteImpl,
                comms::option::app::NoRefreshImpl,
                typename TBase::message::Msg1
            >;
    }; // struct message
};

/// @brief Alias to @ref ServerDefaultOptionsT with default template parameter.
using ServerDefaultOptions = ServerDefaultOptionsT<>;

} // namespace options

} // namespace cc_demo3
