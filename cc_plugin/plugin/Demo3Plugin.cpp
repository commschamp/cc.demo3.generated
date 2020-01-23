// Generated by commsdsl2comms v3.3.1

#include "Demo3Plugin.h"

#include "Demo3Protocol.h"

#include "Demo3ConfigWidget.h"
namespace cc = comms_champion;

namespace demo3
{

namespace cc_plugin
{

namespace plugin
{

Demo3Plugin::Demo3Plugin()
  : m_protocol(new Demo3Protocol())
{
    pluginProperties()
        .setProtocolCreateFunc(
            [this]() -> cc::ProtocolPtr
            {
                return m_protocol;
            })
        .setConfigWidgetCreateFunc(
            [this]() -> QWidget*
            {
                auto* w =
                    new Demo3ConfigWidget(
                        static_cast<Demo3Protocol*>(m_protocol.get())->getVersion());
                w->setVersionUpdateCb(
                    [this](int value) {
                        static_cast<Demo3Protocol*>(m_protocol.get())->setVersion(value);
                    });
                return w;
            })
            ;
}

Demo3Plugin::~Demo3Plugin() = default;

} // namespace plugin

} // namespace cc_plugin

} // namespace demo3


