/// @file
/// @brief Contains definition of protocol default options for bare-metal application
///    where usage of dynamic memory allocation is disabled.

#pragma once

#ifndef DEFAULT_SEQ_FIXED_STORAGE_SIZE
/// @brief Define default fixed size for various sequence fields
/// @details May be defined during compile time to change the default value.
#define DEFAULT_SEQ_FIXED_STORAGE_SIZE 32
#endif

namespace demo3
{

namespace options
{

/// @brief Default options for bare-metal application where usage of dynamic
///    memory allocation is diabled.
struct BareMetalDefaultOptions
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
            using Data = comms::option::FixedSizeStorage<DEFAULT_SEQ_FIXED_STORAGE_SIZE * 8>;
            
            /// @brief Extra options for @ref demo3::frame::FrameLayers::Id layer.
            using Id = comms::option::InPlaceAllocation;
            
        }; // struct FrameLayers
        
    }; // struct frame
    
    
};

} // namespace options

} // namespace demo3


