/// @file
/// @brief Contains definition of protocol default options for server.

#pragma once

#include "DefaultOptions.h"

namespace demo3
{

/// @brief Default options of the protocol specific for a server.
struct ServerDefaultOptions
{
    /// @brief Extra options for messages.
    struct message : public DefaultOptions::message
    {
        /// @brief Extra options for @ref demo3::message::Connect message.
        using Connect =
            std::tuple<
                comms::option::NoWriteImpl,
                comms::option::NoRefreshImpl
            >;
        
        /// @brief Extra options for @ref demo3::message::Msg1 message.
        using Msg1 =
            std::tuple<
                comms::option::NoWriteImpl,
                comms::option::NoRefreshImpl
            >;
        
    };
    
};

} // namespace demo3


