#pragma once

#include <tuple>
#include <QtCore/QVariantList>
#include "comms_champion/TransportMessageBase.h"
#include "demo3/frame/Frame.h"
#include "cc_plugin/Message.h"

namespace demo3
{

namespace cc_plugin
{

namespace frame
{

struct FrameTransportMessageFields
{
    using All =
        std::tuple<
            demo3::frame::FrameLayers<>::SyncMembers::Sync,
            demo3::frame::FrameLayers<>::SizeMembers::Size,
            demo3::field::MsgId<>,
            demo3::frame::FrameLayers<>::VersionMembers::Version,
            demo3::frame::FrameLayers<>::Data::Field,
            demo3::frame::FrameLayers<>::ChecksumMembers::Checksum
        >;
};

class FrameTransportMessage : public
    comms_champion::TransportMessageBase<
        demo3::cc_plugin::Message,
        FrameTransportMessageFields::All
    >
{
protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override;
    virtual comms::ErrorStatus readImpl(ReadIterator& iter, std::size_t len) override;
};

} // namespace frame

} // namespace cc_plugin

} // namespace demo3


