#pragma once

#include <QtCore/QObject>
#include <QtCore/QtPlugin>
#include "comms_champion/Plugin.h"

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
};

} // namespace plugin

} // namespace cc_plugin

} // namespace demo3


