// Generated by commsdsl2comms v6.3.2

/// @file
/// @brief Contains common template parameters independent functionality of
///    fields used in definition of @ref cc_demo3::frame::Frame frame.

#pragma once

#include <cstdint>

namespace cc_demo3
{

namespace frame
{

/// @brief Common types and functions of fields using in definition of
///     @ref cc_demo3::frame::Frame frame.
/// @see cc_demo3::frame::FrameLayers
struct FrameLayersCommon
{
    /// @brief Scope for all the common definitions of the fields defined in
    ///     @ref cc_demo3::frame::FrameLayers::SyncMembers struct.
    struct SyncMembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref cc_demo3::frame::FrameLayers::SyncMembers::Sync field.
        struct SyncCommon
        {
            /// @brief Re-definition of the value type used by
            ///     cc_demo3::frame::FrameLayers::SyncMembers::Sync field.
            using ValueType = std::uint16_t;

            /// @brief Name of the @ref cc_demo3::frame::FrameLayers::SyncMembers::Sync field.
            static const char* name()
            {
                return "Sync";
            }

            /// @brief Compile time detection of special values presence.
            static constexpr bool hasSpecials()
            {
                return false;
            }
        };
    };

    /// @brief Scope for all the common definitions of the fields defined in
    ///     @ref cc_demo3::frame::FrameLayers::ChecksumMembers struct.
    struct ChecksumMembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref cc_demo3::frame::FrameLayers::ChecksumMembers::Checksum field.
        struct ChecksumCommon
        {
            /// @brief Re-definition of the value type used by
            ///     cc_demo3::frame::FrameLayers::ChecksumMembers::Checksum field.
            using ValueType = std::uint16_t;

            /// @brief Name of the @ref cc_demo3::frame::FrameLayers::ChecksumMembers::Checksum field.
            static const char* name()
            {
                return "Checksum";
            }

            /// @brief Compile time detection of special values presence.
            static constexpr bool hasSpecials()
            {
                return false;
            }
        };
    };

    /// @brief Scope for all the common definitions of the fields defined in
    ///     @ref cc_demo3::frame::FrameLayers::SizeMembers struct.
    struct SizeMembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref cc_demo3::frame::FrameLayers::SizeMembers::Size field.
        struct SizeCommon
        {
            /// @brief Re-definition of the value type used by
            ///     cc_demo3::frame::FrameLayers::SizeMembers::Size field.
            using ValueType = std::uint16_t;

            /// @brief Name of the @ref cc_demo3::frame::FrameLayers::SizeMembers::Size field.
            static const char* name()
            {
                return "Size";
            }

            /// @brief Compile time detection of special values presence.
            static constexpr bool hasSpecials()
            {
                return false;
            }
        };
    };

    /// @brief Scope for all the common definitions of the fields defined in
    ///     @ref cc_demo3::frame::FrameLayers::VersionMembers struct.
    struct VersionMembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref cc_demo3::frame::FrameLayers::VersionMembers::Version field.
        struct VersionCommon
        {
            /// @brief Re-definition of the value type used by
            ///     cc_demo3::frame::FrameLayers::VersionMembers::Version field.
            using ValueType = std::uint8_t;

            /// @brief Name of the @ref cc_demo3::frame::FrameLayers::VersionMembers::Version field.
            static const char* name()
            {
                return "Version";
            }

            /// @brief Compile time detection of special values presence.
            static constexpr bool hasSpecials()
            {
                return false;
            }
        };
    };
};

} // namespace frame

} // namespace cc_demo3
