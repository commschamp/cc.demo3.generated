/// @file
/// @brief Contains definition of protocol default options.

#pragma once

#include "comms/options.h"

namespace demo3
{

namespace options
{

/// @brief Default (empty) options of the protocol.
struct DefaultOptions
{
    /// @brief Extra options for messages.
    struct message
    {
        /// @brief Extra options for @ref demo3::message::Connect message.
        using Connect = comms::option::EmptyOption;
        
        /// @brief Extra options for @ref demo3::message::Msg1 message.
        using Msg1 = comms::option::EmptyOption;
        
    }; // struct message
    
    /// @brief Extra options for frames.
    struct frame
    {
        /// @brief Extra options for Layers of @ref demo3::frame::Frame frame.
        struct FrameLayers
        {
            /// @brief Extra options for @ref demo3::frame::FrameLayers::Data layer.
            using Data = comms::option::EmptyOption;
            
            /// @brief Extra options for @ref demo3::frame::FrameLayers::Id layer.
            using Id = comms::option::EmptyOption;
            
        }; // struct FrameLayers
        
    }; // struct frame
    
    
};

} // namespace options

} // namespace demo3


