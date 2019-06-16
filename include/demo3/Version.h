/// @file
/// @brief Contains protocol version definition.

#pragma once

#include "comms/version.h"

/// @brief Version of the protocol specification.
#define DEMO3_SPEC_VERSION (5U)

/// @brief Major version of the protocol library.
#define DEMO3_MAJOR_VERSION (0U)

/// @brief Minor version of the protocol library.
#define DEMO3_MINOR_VERSION (7U)

/// @brief Patch version of the protocol library.
#define DEMO3_PATCH_VERSION (2U)

/// @brief Full version of the protocol library as single number.
#define DEMO3_VERSION (COMMS_MAKE_VERSION(DEMO3_MAJOR_VERSION, DEMO3_MINOR_VERSION, DEMO3_PATCH_VERSION))


namespace demo3
{

/// @brief Version of the protocol specification.
inline constexpr unsigned specVersion()
{
    return DEMO3_SPEC_VERSION;
}

/// @brief Major version of the protocol library
inline constexpr unsigned versionMajor()
{
    return DEMO3_MAJOR_VERSION;
}

/// @brief Minor version of the protocol library
inline constexpr unsigned versionMinor()
{
    return DEMO3_MINOR_VERSION;
}

/// @brief Patch version of the protocol library
inline constexpr unsigned versionPatch()
{
    return DEMO3_PATCH_VERSION;
}

/// @brief Full version of the protocol library as single number
inline constexpr unsigned version()
{
    return DEMO3_VERSION;
}


} // namespace demo3


// Generated compile time check for minimal supported version of the COMMS library
static_assert(COMMS_MAKE_VERSION(1, 3, 0) <= comms::version(),
    "The version of COMMS library is too old");

