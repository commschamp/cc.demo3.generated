// Generated by commsdsl2comms v6.2.1

/// @file
/// @brief Contains definition of <b>"Frame"</b> frame class.

#pragma once

#include <cstdint>
#include "cc_demo3/field/FieldBase.h"
#include "cc_demo3/field/MsgId.h"
#include "cc_demo3/frame/FrameCommon.h"
#include "cc_demo3/input/AllMessages.h"
#include "cc_demo3/options/DefaultOptions.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "comms/protocol/ChecksumLayer.h"
#include "comms/protocol/MsgDataLayer.h"
#include "comms/protocol/MsgIdLayer.h"
#include "comms/protocol/MsgSizeLayer.h"
#include "comms/protocol/SyncPrefixLayer.h"
#include "comms/protocol/TransportValueLayer.h"
#include "comms/protocol/checksum/Crc.h"

namespace cc_demo3
{

namespace frame
{

/// @brief Layers definition of @ref Frame frame class.
/// @tparam TOpt Protocol options.
/// @see @ref Frame
/// @headerfile cc_demo3/frame/Frame.h
template <typename TOpt = cc_demo3::options::DefaultOptions>
struct FrameLayers
{
    /// @brief Definition of layer "Data".
    using Data =
        comms::protocol::MsgDataLayer<
            typename TOpt::frame::FrameLayers::Data
        >;

    /// @brief Scope for field(s) of @ref Version layer.
    struct VersionMembers
    {
        /// @brief Definition of <b>"Version"</b> field.
        class Version : public
            comms::field::IntValue<
                cc_demo3::field::FieldBase<>,
                std::uint8_t,
                comms::option::def::EmptySerialization,
                comms::option::def::DefaultNumValue<5U>
            >
        {
            using Base =
                comms::field::IntValue<
                    cc_demo3::field::FieldBase<>,
                    std::uint8_t,
                    comms::option::def::EmptySerialization,
                    comms::option::def::DefaultNumValue<5U>
                >;
        public:
            /// @brief Re-definition of the value type.
            using ValueType = typename Base::ValueType;

            /// @brief Compile time detection of special values presence.
            static constexpr bool hasSpecials()
            {
                return cc_demo3::frame::FrameLayersCommon::VersionMembersCommon::VersionCommon::hasSpecials();
            }

            /// @brief Name of the field.
            static const char* name()
            {
                return cc_demo3::frame::FrameLayersCommon::VersionMembersCommon::VersionCommon::name();
            }
        };
    };

    /// @brief Definition of layer "Version".
    using Version =
        comms::protocol::TransportValueLayer<
            typename VersionMembers::Version,
            0U,
            Data,
            comms::option::def::PseudoValue
        >;

    /// @brief Definition of layer "Id".
    template <typename TMessage, typename TAllMessages>
    using Id =
        comms::protocol::MsgIdLayer<
            cc_demo3::field::MsgId<
                TOpt
            >,
            TMessage,
            TAllMessages,
            Version,
            typename TOpt::frame::FrameLayers::Id
        >;

    /// @brief Scope for field(s) of @ref Size layer.
    struct SizeMembers
    {
        /// @brief Definition of <b>"Size"</b> field.
        class Size : public
            comms::field::IntValue<
                cc_demo3::field::FieldBase<>,
                std::uint16_t,
                comms::option::def::NumValueSerOffset<2>
            >
        {
            using Base =
                comms::field::IntValue<
                    cc_demo3::field::FieldBase<>,
                    std::uint16_t,
                    comms::option::def::NumValueSerOffset<2>
                >;
        public:
            /// @brief Re-definition of the value type.
            using ValueType = typename Base::ValueType;

            /// @brief Compile time detection of special values presence.
            static constexpr bool hasSpecials()
            {
                return cc_demo3::frame::FrameLayersCommon::SizeMembersCommon::SizeCommon::hasSpecials();
            }

            /// @brief Name of the field.
            static const char* name()
            {
                return cc_demo3::frame::FrameLayersCommon::SizeMembersCommon::SizeCommon::name();
            }
        };
    };

    /// @brief Definition of layer "Size".
    template <typename TMessage, typename TAllMessages>
    using Size =
        comms::protocol::MsgSizeLayer<
            typename SizeMembers::Size,
            Id<TMessage, TAllMessages>
        >;

    /// @brief Scope for field(s) of @ref Checksum layer.
    struct ChecksumMembers
    {
        /// @brief Definition of <b>"Checksum"</b> field.
        class Checksum : public
            comms::field::IntValue<
                cc_demo3::field::FieldBase<>,
                std::uint16_t
            >
        {
            using Base =
                comms::field::IntValue<
                    cc_demo3::field::FieldBase<>,
                    std::uint16_t
                >;
        public:
            /// @brief Re-definition of the value type.
            using ValueType = typename Base::ValueType;

            /// @brief Compile time detection of special values presence.
            static constexpr bool hasSpecials()
            {
                return cc_demo3::frame::FrameLayersCommon::ChecksumMembersCommon::ChecksumCommon::hasSpecials();
            }

            /// @brief Name of the field.
            static const char* name()
            {
                return cc_demo3::frame::FrameLayersCommon::ChecksumMembersCommon::ChecksumCommon::name();
            }
        };
    };

    /// @brief Definition of layer "Checksum".
    template <typename TMessage, typename TAllMessages>
    using Checksum =
        comms::protocol::ChecksumLayer<
            typename ChecksumMembers::Checksum,
            comms::protocol::checksum::Crc_CCITT,
            Size<TMessage, TAllMessages>
        >;

    /// @brief Scope for field(s) of @ref Sync layer.
    struct SyncMembers
    {
        /// @brief Definition of <b>"Sync"</b> field.
        class Sync : public
            comms::field::IntValue<
                cc_demo3::field::FieldBase<>,
                std::uint16_t,
                comms::option::def::FailOnInvalid<comms::ErrorStatus::ProtocolError>,
                comms::option::def::DefaultNumValue<43981L>,
                comms::option::def::ValidNumValue<43981L>,
                comms::option::def::HasCustomRefresh
            >
        {
            using Base =
                comms::field::IntValue<
                    cc_demo3::field::FieldBase<>,
                    std::uint16_t,
                    comms::option::def::FailOnInvalid<comms::ErrorStatus::ProtocolError>,
                    comms::option::def::DefaultNumValue<43981L>,
                    comms::option::def::ValidNumValue<43981L>,
                    comms::option::def::HasCustomRefresh
                >;
        public:
            /// @brief Re-definition of the value type.
            using ValueType = typename Base::ValueType;

            /// @brief Compile time detection of special values presence.
            static constexpr bool hasSpecials()
            {
                return cc_demo3::frame::FrameLayersCommon::SyncMembersCommon::SyncCommon::hasSpecials();
            }

            /// @brief Name of the field.
            static const char* name()
            {
                return cc_demo3::frame::FrameLayersCommon::SyncMembersCommon::SyncCommon::name();
            }

            /// @brief Generated refresh functionality.
            bool refresh()
            {
                bool updated = Base::refresh();
                if (Base::valid()) {
                    return updated;
                };
                Base::setValue(43981L);
                return true;
            }
        };
    };

    /// @brief Definition of layer "Sync".
    template <typename TMessage, typename TAllMessages>
    using Sync =
        comms::protocol::SyncPrefixLayer<
            typename SyncMembers::Sync,
            Checksum<TMessage, TAllMessages>
        >;

    /// @brief Final protocol stack definition.
    template<typename TMessage, typename TAllMessages>
    using Stack = Sync<TMessage, TAllMessages>;
};

/// @brief Definition of <b>"Frame"</b> frame class.
/// @tparam TMessage Common interface class of all the messages
/// @tparam TAllMessages All supported input messages.
/// @tparam TOpt Frame definition options
/// @headerfile cc_demo3/frame/Frame.h
template <
   typename TMessage,
   typename TAllMessages = cc_demo3::input::AllMessages<TMessage>,
   typename TOpt = cc_demo3::options::DefaultOptions
>
class Frame : public
    FrameLayers<TOpt>::template Stack<TMessage, TAllMessages>
{
    using Base = typename
        FrameLayers<TOpt>::template Stack<TMessage, TAllMessages>;
public:
    /// @brief Allow access to frame definition layers.
    /// @details See definition of @b COMMS_PROTOCOL_LAYERS_NAMES macro
    ///     from COMMS library for details.
    ///
    ///     The generated types and functions are:
    ///     @li @b Layer_data type and @b layer_data() function
    ///         for @ref FrameLayers::Data layer.
    ///     @li @b Layer_version type and @b layer_version() function
    ///         for @ref FrameLayers::Version layer.
    ///     @li @b Layer_id type and @b layer_id() function
    ///         for @ref FrameLayers::Id layer.
    ///     @li @b Layer_size type and @b layer_size() function
    ///         for @ref FrameLayers::Size layer.
    ///     @li @b Layer_checksum type and @b layer_checksum() function
    ///         for @ref FrameLayers::Checksum layer.
    ///     @li @b Layer_sync type and @b layer_sync() function
    ///         for @ref FrameLayers::Sync layer.
    COMMS_PROTOCOL_LAYERS_NAMES(
        data,
        version,
        id,
        size,
        checksum,
        sync
    );
};

} // namespace frame

} // namespace cc_demo3
