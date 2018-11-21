/// @file
/// @brief Contains definition of protocol default options for client.

#pragma once

#include "DefaultOptions.h"

namespace demo3
{

/// @brief Default options of the protocol specific for a client.
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

} // namespace demo3


