#pragma once

#include <functional>
#include <QtWidgets/QWidget>

namespace demo3
{

namespace cc_plugin
{

namespace plugin
{

class Demo3ConfigWidget : public QWidget
{
    Q_OBJECT
public:
    using VersionUpdateCb = std::function<void (int)>;

    explicit Demo3ConfigWidget(int version);

    template <typename TFunc>
    void setVersionUpdateCb(TFunc&& func)
    {
        m_versionUpdateCb = std::forward<TFunc>(func);
    }

private slots:
    void versionChanged(int value);

private:    VersionUpdateCb m_versionUpdateCb;};

} // namespace plugin

} // namespace cc_plugin

} // namespace demo3


