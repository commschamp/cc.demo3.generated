// Generated by commsdsl2comms v3.5.3

#pragma once

#include <QtCore/QObject>
#include <QtCore/QtPlugin>
#include "comms_champion/Plugin.h"
#include "comms_champion/Protocol.h"

namespace demo3
{

namespace cc_plugin
{

namespace plugin
{

class Demo3Plugin : public comms_champion::Plugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "demo3" FILE "Demo3Plugin.json")
    Q_INTERFACES(comms_champion::Plugin)

public:
    Demo3Plugin();
    virtual ~Demo3Plugin();
private:
    comms_champion::ProtocolPtr m_protocol;
    int m_version = 5U;
};

} // namespace plugin

} // namespace cc_plugin

} // namespace demo3


