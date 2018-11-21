#pragma once

#include "comms_champion/MessageBase.h"
#include "demo3/Message.h"

namespace demo3
{

namespace cc_plugin
{

class Message : public
    comms_champion::MessageBase<
        demo3::Message
    >
{
protected:
    virtual const QVariantList& extraTransportFieldsPropertiesImpl() const override;
};

} // namespace cc_plugin

} // namespace demo3



