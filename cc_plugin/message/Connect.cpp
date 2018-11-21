#include "Connect.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "demo3/message/Connect.h"
namespace cc = comms_champion;

namespace demo3
{

namespace cc_plugin
{

namespace message
{

namespace
{

static QVariantMap createProps_version()
{
    using Field = demo3::message::ConnectFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_version());
    return props;
}

} // namespace

class ConnectImpl : public
    comms_champion::ProtocolMessageBase<
        demo3::message::Connect<demo3::cc_plugin::Message>,
        ConnectImpl
    >
{
public:
    ConnectImpl() = default;
    ConnectImpl(const ConnectImpl&) = delete;
    ConnectImpl(ConnectImpl&&) = delete;
    virtual ~ConnectImpl() = default;
    ConnectImpl& operator=(const ConnectImpl&) = default;
    ConnectImpl& operator=(ConnectImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

Connect::Connect() : m_pImpl(new ConnectImpl) {}
Connect::~Connect() = default;

Connect& Connect::operator=(const Connect& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

Connect& Connect::operator=(Connect&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* Connect::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& Connect::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void Connect::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void Connect::resetImpl()
{
    m_pImpl->reset();
}

bool Connect::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const Connect*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

Connect::MsgIdParamType Connect::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus Connect::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus Connect::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool Connect::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t Connect::lengthImpl() const
{
    return m_pImpl->length();
}

bool Connect::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace demo3


