/// @file
/// @brief Contains dispatch to handling function(s) for client input messages.

#pragma once

#include <type_traits>
#include "demo3/MsgId.h"
#include "demo3/input/ClientInputMessages.h"

namespace demo3
{

namespace dispatch
{

/// @brief Dispatch message object to its appropriate handling function.
/// @details @b switch statement based (on message ID) cast and dispatch functionality.
/// @tparam TProtOptions Protocol options struct used for the application,
///     like @ref demo3::options::DefaultOptions.
/// @param[in] id Numeric message ID.
/// @param[in] msg Message object held by reference to its interface class.
/// @param[in] handler Reference to handling object. Must define
///     @b handle() member function for every message type it exects
///     to handle and one for the interface class as well.
///     @code
///     using MyInterface = demo3::Message<...>;
///     using MySomeMessage = demo3::message::SomeMessage<MyInterface, demo3::options::DefaultOptions>;
///     using MySomeOtherMessage = demo3::message::SomeOtherMessage<MyInterface, demo3::options::DefaultOptions>;
///     struct MyHandler {
///         void handle(MySomeMessage& msg) {...}
///         void handle(MySomeOtherMessage& msg) {...}
///         ...
///         // Handle all unexpected or irrelevant messages.
///         void handle(MyInterface& msg) {...}
///     };
///     @endcode
///     Every @b handle() function may return a value, but every
///     function must return the @b same type.
/// @note Defined in demo3/dispatch/DispatchClientInputMessage.h
template<typename TProtOptions, typename TMsg, typename THandler>
auto dispatchClientInputMessage(
    demo3::MsgId id,
    TMsg& msg,
    THandler& handler) -> decltype(handler.handle(msg))
{
    using InterfaceType = typename std::decay<decltype(msg)>::type;
    switch(id) {
    default:
        break;
    };

    return handler.handle(msg);
}

/// @brief Dispatch message object to its appropriate handling function.
/// @details Same as other dispatchClientInputMessage(), but receives extra @b idx parameter.
/// @tparam TProtOptions Protocol options struct used for the application,
///     like @ref demo3::options::DefaultOptions.
/// @param[in] id Numeric message ID.
/// @param[in] idx Index of the message among messages with the same ID.
///     Expected to be @b 0.
/// @param[in] msg Message object held by reference to its interface class.
/// @param[in] handler Reference to handling object.
/// @see dispatchClientInputMessage()
/// @note Defined in demo3/dispatch/DispatchClientInputMessage.h
template<typename TProtOptions, typename TMsg, typename THandler>
auto dispatchClientInputMessage(
    demo3::MsgId id,
    std::size_t idx,
    TMsg& msg,
    THandler& handler) -> decltype(handler.handle(msg))
{
    if (idx != 0U) {
        return handler.handle(msg);
    }
    return dispatchClientInputMessage(id, msg, handler);
}

/// @brief Dispatch message object to its appropriate handling function.
/// @details Same as other dispatchClientInputMessage(), but passing
///     demo3::options::DefaultOptions as first template parameter.
/// @param[in] id Numeric message ID.
/// @param[in] msg Message object held by reference to its interface class.
/// @param[in] handler Reference to handling object.
/// @see dispatchClientInputMessage()
/// @note Defined in demo3/dispatch/DispatchClientInputMessage.h
template<typename TMsg, typename THandler>
auto dispatchClientInputMessageDefaultOptions(
    demo3::MsgId id,
    TMsg& msg,
    THandler& handler) -> decltype(handler.handle(msg))
{
    return dispatchClientInputMessage<demo3::options::DefaultOptions>(id, msg, handler);
}

/// @brief Dispatch message object to its appropriate handling function.
/// @details Same as other dispatchClientInputMessageDefaultOptions(), 
///     but receives extra @b idx parameter.
/// @param[in] id Numeric message ID.
/// @param[in] idx Index of the message among messages with the same ID.
/// @param[in] msg Message object held by reference to its interface class.
/// @param[in] handler Reference to handling object.
/// @see dispatchClientInputMessageDefaultOptions()
/// @note Defined in demo3/dispatch/DispatchClientInputMessage.h
template<typename TMsg, typename THandler>
auto dispatchClientInputMessageDefaultOptions(
    demo3::MsgId id,
    std::size_t idx,
    TMsg& msg,
    THandler& handler) -> decltype(handler.handle(msg))
{
    return dispatchClientInputMessage<demo3::options::DefaultOptions>(id, idx, msg, handler);
}

} // namespace dispatch

} // namespace demo3


