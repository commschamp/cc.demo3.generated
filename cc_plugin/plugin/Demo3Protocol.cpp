#include "Demo3Protocol.h"

#include "comms_champion/ProtocolBase.h"
#include "cc_plugin/frame/Frame.h"
#include "cc_plugin/frame/FrameTransportMessage.h"

namespace cc = comms_champion;

namespace demo3
{

namespace cc_plugin
{

namespace plugin
{

class Demo3ProtocolImpl : public
    cc::ProtocolBase<
        demo3::cc_plugin::frame::Frame,
        demo3::cc_plugin::frame::FrameTransportMessage
    >
{
    using Base =
        cc::ProtocolBase<
            demo3::cc_plugin::frame::Frame,
            demo3::cc_plugin::frame::FrameTransportMessage
        >;
public:
    friend class demo3::cc_plugin::plugin::Demo3Protocol;

    Demo3ProtocolImpl() = default;
    virtual ~Demo3ProtocolImpl() = default;

protected:
    virtual const QString& nameImpl() const override
    {
        static const QString Str("demo3");
        return Str;
    }

    using Base::createInvalidMessageImpl;
    using Base::createRawDataMessageImpl;
    using Base::createExtraInfoMessageImpl;
};

Demo3Protocol::Demo3Protocol()
  : m_pImpl(new Demo3ProtocolImpl())
{
}

Demo3Protocol::~Demo3Protocol() = default;

const QString& Demo3Protocol::nameImpl() const
{
    return m_pImpl->name();
}

Demo3Protocol::MessagesList Demo3Protocol::readImpl(const cc::DataInfo& dataInfo, bool final)
{
    return m_pImpl->read(dataInfo, final);
}

cc::DataInfoPtr Demo3Protocol::writeImpl(cc::Message& msg)
{
    return m_pImpl->write(msg);
}

Demo3Protocol::MessagesList Demo3Protocol::createAllMessagesImpl()
{
    return m_pImpl->createAllMessages();
}

cc::MessagePtr Demo3Protocol::createMessageImpl(const QString& idAsString, unsigned idx)
{
    return static_cast<cc::Protocol*>(m_pImpl.get())->createMessage(idAsString, idx);
}

Demo3Protocol::UpdateStatus Demo3Protocol::updateMessageImpl(cc::Message& msg)
{
    return m_pImpl->updateMessage(msg);
}

cc::MessagePtr Demo3Protocol::cloneMessageImpl(const cc::Message& msg)
{
    return m_pImpl->cloneMessage(msg);
}

cc::MessagePtr Demo3Protocol::createInvalidMessageImpl()
{
    return m_pImpl->createInvalidMessageImpl();
}

cc::MessagePtr Demo3Protocol::createRawDataMessageImpl()
{
    return m_pImpl->createRawDataMessageImpl();
}

cc::MessagePtr Demo3Protocol::createExtraInfoMessageImpl()
{
    return m_pImpl->createExtraInfoMessageImpl();
}

} // namespace plugin

} // namespace cc_plugin

} // namespace demo3


