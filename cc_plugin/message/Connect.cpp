#include "Connect.h"

#include "comms_champion/property/field.h"
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

Connect::Connect() = default;
Connect::~Connect() = default;
Connect& Connect::operator=(const Connect&) = default;
Connect& Connect::operator=(Connect&&) = default;

const QVariantList& Connect::fieldsPropertiesImpl() const
{
    static const QVariantList Props = createProps();
    return Props;
}

} // namespace message

} // namespace cc_plugin

} // namespace demo3


