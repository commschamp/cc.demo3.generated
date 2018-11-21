#pragma once

#include <tuple>
#include "cc_plugin/message/Connect.h"
#include "cc_plugin/message/Msg1.h"

namespace demo3
{

namespace cc_plugin
{

using AllMessages =
    std::tuple<
        demo3::cc_plugin::message::Connect,
        demo3::cc_plugin::message::Msg1
    >;

} // namespace cc_plugin

} // namespace demo3


