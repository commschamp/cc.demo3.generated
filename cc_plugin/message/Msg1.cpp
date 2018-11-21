#include "Msg1.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "demo3/message/Msg1.h"
namespace cc = comms_champion;

namespace demo3
{

namespace cc_plugin
{

namespace message
{

namespace
{

static QVariantMap createProps_f1()
{
    using Field = demo3::message::Msg1Fields<>::F1;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_f2()
{
    using InnerField = demo3::message::Msg1Fields<>::F2Field;
    auto props =
        cc::property::field::ForField<InnerField>()
            .name(InnerField::name())
            .asMap();
    
    using Field = demo3::message::Msg1Fields<>::F2;
    return
        cc::property::field::ForField<Field>()
            .name(InnerField::name())
            .uncheckable()
            .field(std::move(props))
            .asMap();
    
}

static QVariantMap createProps_f3()
{
    using InnerField = demo3::message::Msg1Fields<>::F3Field;
    auto props =
        cc::property::field::ForField<InnerField>()
            .name(InnerField::name())
            .asMap();
    
    using Field = demo3::message::Msg1Fields<>::F3;
    return
        cc::property::field::ForField<Field>()
            .name(InnerField::name())
            .uncheckable()
            .field(std::move(props))
            .asMap();
    
}

static QVariantMap createProps_f4()
{
    using InnerField = demo3::message::Msg1Fields<>::F4Field;
    auto props =
        cc::property::field::ForField<InnerField>()
            .name(InnerField::name())
            .asMap();
    
    using Field = demo3::message::Msg1Fields<>::F4;
    return
        cc::property::field::ForField<Field>()
            .name(InnerField::name())
            .uncheckable()
            .field(std::move(props))
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_f1());
    props.append(createProps_f2());
    props.append(createProps_f3());
    props.append(createProps_f4());
    return props;
}

} // namespace

class Msg1Impl : public
    comms_champion::ProtocolMessageBase<
        demo3::message::Msg1<demo3::cc_plugin::Message>,
        Msg1Impl
    >
{
public:
    Msg1Impl() = default;
    Msg1Impl(const Msg1Impl&) = delete;
    Msg1Impl(Msg1Impl&&) = delete;
    virtual ~Msg1Impl() = default;
    Msg1Impl& operator=(const Msg1Impl&) = default;
    Msg1Impl& operator=(Msg1Impl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

Msg1::Msg1() : m_pImpl(new Msg1Impl) {}
Msg1::~Msg1() = default;

Msg1& Msg1::operator=(const Msg1& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

Msg1& Msg1::operator=(Msg1&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* Msg1::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& Msg1::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void Msg1::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void Msg1::resetImpl()
{
    m_pImpl->reset();
}

bool Msg1::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const Msg1*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

Msg1::MsgIdParamType Msg1::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus Msg1::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus Msg1::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool Msg1::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t Msg1::lengthImpl() const
{
    return m_pImpl->length();
}

bool Msg1::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace demo3


