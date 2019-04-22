/// @file
/// @brief Contains definition of protocol default options for a client.

#pragma once

#include "DefaultOptions.h"

namespace demo3
{

namespace options
{

/// @brief Default options of the protocol for a client.
struct ClientDefaultOptions
{
    /// @brief Extra options for messages.
    struct message : public DefaultOptions::message
    {
        /// @brief Extra options for @ref demo3::message::Connect message.
        using Connect =
            std::tuple<
                comms::option::NoReadImpl,
                comms::option::NoDispatchImpl
            >;
        
        /// @brief Extra options for @ref demo3::message::Msg1 message.
        using Msg1 =
            std::tuple<
                comms::option::NoReadImpl,
                comms::option::NoDispatchImpl
            >;
        
    };
    
};

} // namespace options

} // namespace demo3


