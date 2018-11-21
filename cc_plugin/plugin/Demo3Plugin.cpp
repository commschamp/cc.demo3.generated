#include "Demo3Plugin.h"

#include "Demo3Protocol.h"

namespace cc = comms_champion;

namespace demo3
{

namespace cc_plugin
{

namespace plugin
{

Demo3Plugin::Demo3Plugin()
{
    pluginProperties()
        .setProtocolCreateFunc(
            []() -> cc::ProtocolPtr
            {
                return cc::ProtocolPtr(new Demo3Protocol());
            });
}

Demo3Plugin::~Demo3Plugin() = default;

} // namespace plugin

} // namespace cc_plugin

} // namespace demo3


