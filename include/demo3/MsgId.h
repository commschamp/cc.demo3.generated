/// @file
/// @brief Contains definition of message ids enumeration.

#pragma once

#include <cstdint>

namespace demo3
{

/// @brief Message ids enumeration.
enum MsgId : std::uint8_t
{
    MsgId_Connect = 1, ///< message id @b Connect
    MsgId_Msg1 = 2, ///< message id @b Msg1
    
};

} // namespace demo3


