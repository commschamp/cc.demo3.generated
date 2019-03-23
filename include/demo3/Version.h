/// @file
/// @brief Contains protocol version definition.

#pragma once

#include "comms/version.h"

/// @brief Version of the protocol library as single numeric value
#define DEMO3_VERSION (5U)

namespace demo3
{

/// @brief Version of the protocol library as single numeric value
inline constexpr unsigned version()
{
    return DEMO3_VERSION;
}

} // namespace demo3


// Generated compile time check for minimal supported version of the COMMS library
static_assert(COMMS_MAKE_VERSION(1, 0, 0) <= comms::version(),
    "The version of COMMS library is too old");

