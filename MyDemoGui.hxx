#ifndef __MYDEMOGUI_HXX__
#define __MYDEMOGUI_HXX__

#ifdef WIN32
# if defined MYDEMO_EXPORTS || defined MyDemo_EXPORTS
#   define MYDEMO_EXPORT __declspec(dllexport)
# else
#   define MYDEMO_EXPORT __declspec(dllimport)
# endif
#else
# define MYDEMO_EXPORT
#endif

#include "LightApp_Module.h"

#include <QObject>

class MYDEMO_EXPORT MyDemoGui : public LightApp_Module
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
