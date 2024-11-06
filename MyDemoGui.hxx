#ifndef __MYDEMOGUI_HXX__
#define __MYDEMOGUI_HXX__

#include "LightApp_Module.h"

#include <QObject>

class MyDemoGui : public LightApp_Module
{
    Q_OBJECT
public:
    MyDemoGui(const QString &module_name);
    void initialize(CAM_Application *app) override;
    void windows(QMap<int, int> &aMap) const override;
    bool activateModule(SUIT_Study *study) override;
    bool deactivateModule(SUIT_Study *study) override;
    virtual ~MyDemoGui();
};
#endif
