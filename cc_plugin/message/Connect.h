#pragma once

#include <memory>
#include <QtCore/QVariantList>
#include "comms_champion/ProtocolMessageBase.h"
#include "demo3/message/Connect.h"
#include "cc_plugin/Message.h"

namespace demo3
{

namespace cc_plugin
{

namespace message
{

class Connect : public
    comms_champion::ProtocolMessageBase<
        demo3::message::Connect<demo3::cc_plugin::Message>,
        Connect
    >
{
public:
    Connect();
    Connect(const Connect&) = delete;
    Connect(Connect&&) = delete;
    virtual ~Connect();
    Connect& operator=(const Connect&);
    Connect& operator=(Connect&&);

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override;
};

} // namespace message

} // namespace cc_plugin

} // namespace demo3



