#include "MsgId.h"

#include "comms_champion/property/field.h"
#include "demo3/field/MsgId.h"


namespace cc = comms_champion;

namespace demo3
{

namespace cc_plugin
{

namespace field
{

QVariantMap createProps_msgId(const char* name, bool serHidden)
{
    static_cast<void>(serHidden);
    using Field = demo3::field::MsgId<>;
    return
        cc::property::field::ForField<Field>()
            .name(name)
            .serialisedHidden(serHidden)
            .add("Connect", 1)
            .add("Msg1", 2)
            .asMap();
    
}

} // namespace field

} // namespace cc_plugin

} // namespace demo3


