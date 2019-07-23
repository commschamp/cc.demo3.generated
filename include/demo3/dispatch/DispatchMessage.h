/// @file
/// @brief Contains dispatch to handling function(s) for all input messages.

#pragma once

#include <type_traits>
#include "demo3/MsgId.h"
#include "demo3/input/AllMessages.h"

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
///     using MyConnect = demo3::message::Connect<MyInterface, demo3::options::DefaultOptions>;
///     using MyMsg1 = demo3::message::Msg1<MyInterface, demo3::options::DefaultOptions>;
///     struct MyHandler {
///         void handle(MyConnect& msg) {...}
///         void handle(MyMsg1& msg) {...}
///         ...
///         // Handle all unexpected or irrelevant messages.
///         void handle(MyInterface& msg) {...}
///     };
///     @endcode
///     Every @b handle() function may return a value, but every
///     function must return the @b same type.
/// @note Defined in demo3/dispatch/DispatchMessage.h
template<typename TProtOptions, typename TMsg, typename THandler>
auto dispatchMessage(
    demo3::MsgId id,
    TMsg& msg,
    THandler& handler) -> decltype(handler.handle(msg))
{
    using InterfaceType = typename std::decay<decltype(msg)>::type;
    switch(id) {
    case demo3::MsgId_Connect:
    {
        using MsgType = demo3::message::Connect<InterfaceType, TProtOptions>;
        auto& castedMsg = static_cast<MsgType&>(msg);
        return handler.handle(castedMsg);
    }
    case demo3::MsgId_Msg1:
    {
        using MsgType = demo3::message::Msg1<InterfaceType, TProtOptions>;
        auto& castedMsg = static_cast<MsgType&>(msg);
        return handler.handle(castedMsg);
    }
    default:
        break;
    };

    return handler.handle(msg);
}

/// @brief Dispatch message object to its appropriate handling function.
/// @details Same as other dispatchMessage(), but receives extra @b idx parameter.
/// @tparam TProtOptions Protocol options struct used for the application,
///     like @ref demo3::options::DefaultOptions.
/// @param[in] id Numeric message ID.
/// @param[in] idx Index of the message among messages with the same ID.
///     Expected to be @b 0.
/// @param[in] msg Message object held by reference to its interface class.
/// @param[in] handler Reference to handling object.
/// @see dispatchMessage()
/// @note Defined in demo3/dispatch/DispatchMessage.h
template<typename TProtOptions, typename TMsg, typename THandler>
auto dispatchMessage(
    demo3::MsgId id,
    std::size_t idx,
    TMsg& msg,
    THandler& handler) -> decltype(handler.handle(msg))
{
    if (idx != 0U) {
        return handler.handle(msg);
    }
    return dispatchMessage(id, msg, handler);
}

/// @brief Dispatch message object to its appropriate handling function.
/// @details Same as other dispatchMessage(), but passing
///     demo3::options::DefaultOptions as first template parameter.
/// @param[in] id Numeric message ID.
/// @param[in] msg Message object held by reference to its interface class.
/// @param[in] handler Reference to handling object.
/// @see dispatchMessage()
/// @note Defined in demo3/dispatch/DispatchMessage.h
template<typename TMsg, typename THandler>
auto dispatchMessageDefaultOptions(
    demo3::MsgId id,
    TMsg& msg,
    THandler& handler) -> decltype(handler.handle(msg))
{
    return dispatchMessage<demo3::options::DefaultOptions>(id, msg, handler);
}

/// @brief Dispatch message object to its appropriate handling function.
/// @details Same as other dispatchMessageDefaultOptions(), 
///     but receives extra @b idx parameter.
/// @param[in] id Numeric message ID.
/// @param[in] idx Index of the message among messages with the same ID.
/// @param[in] msg Message object held by reference to its interface class.
/// @param[in] handler Reference to handling object.
/// @see dispatchMessageDefaultOptions()
/// @note Defined in demo3/dispatch/DispatchMessage.h
template<typename TMsg, typename THandler>
auto dispatchMessageDefaultOptions(
    demo3::MsgId id,
    std::size_t idx,
    TMsg& msg,
    THandler& handler) -> decltype(handler.handle(msg))
{
    return dispatchMessage<demo3::options::DefaultOptions>(id, idx, msg, handler);
}

} // namespace dispatch

} // namespace demo3

