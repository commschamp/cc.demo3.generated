// Generated by commsdsl2comms v7.0.2

/// @file
/// @brief Contains definition of protocol client default options.

#pragma once

#include "cc_demo3/options/DefaultOptions.h"

namespace cc_demo3
{

namespace options
{

/// @brief Default client options of the protocol.
template <typename TBase = cc_demo3::options::DefaultOptions>
struct ClientDefaultOptionsT : public TBase
{
    /// @brief Extra options for messages.
    struct message : public TBase::message
    {
        /// @brief Extra options for @ref
        ///     cc_demo3::message::Connect message.
        using Connect =
            std::tuple<
                comms::option::app::NoReadImpl,
                comms::option::app::NoDispatchImpl,
                typename TBase::message::Connect
            >;

        /// @brief Extra options for @ref
        ///     cc_demo3::message::Msg1 message.
        using Msg1 =
            std::tuple<
                comms::option::app::NoReadImpl,
                comms::option::app::NoDispatchImpl,
                typename TBase::message::Msg1
            >;
    }; // struct message
};

/// @brief Alias to @ref ClientDefaultOptionsT with default template parameter.
using ClientDefaultOptions = ClientDefaultOptionsT<>;

} // namespace options

} // namespace cc_demo3
