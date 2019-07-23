/// @file
/// @brief Contains definition of protocol default options for a server.

#pragma once

#include "DefaultOptions.h"

namespace demo3
{

namespace options
{

/// @brief Default options of the protocol for a server.
struct ServerDefaultOptions
{
    /// @brief Extra options for messages.
    struct message : public DefaultOptions::message
    {
        /// @brief Extra options for
        ///     @ref demo3::message::Connect message.
        using Connect =
            std::tuple<
                comms::option::app::NoWriteImpl,
                comms::option::app::NoRefreshImpl
            >;
        
        /// @brief Extra options for
        ///     @ref demo3::message::Msg1 message.
        using Msg1 =
            std::tuple<
                comms::option::app::NoWriteImpl,
                comms::option::app::NoRefreshImpl
            >;
        
    };
    
};

} // namespace options

} // namespace demo3


