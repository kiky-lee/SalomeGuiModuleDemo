#include "MyDemoGui.hxx"

#include "LightApp_Application.h"
#include "SUIT_Desktop.h"
#include "SUIT_Session.h"
#include "SUIT_ViewManager.h"

MyDemoGui::MyDemoGui(const QString &module_name) : LightApp_Module(module_name)
{
}

void MyDemoGui::initialize(CAM_Application *app)
{
    LightApp_Module::initialize(app);
    LightApp_Application *anApp = getApp();
    SUIT_Desktop *dsk = anApp->desktop();
    // get resources manager
    QWidget *widget = new QWidget(dsk);
    widget->setWindowTitle("MyDemo Window");
    SUIT_ResourceMgr *resMgr = app->resourceMgr();
}

void MyDemoGui::windows(QMap<int, int> &aMap) const
{
#ifndef DISABLE_PYCONSOLE
    aMap.insert(LightApp_Application::WT_PyConsole, Qt::BottomDockWidgetArea);
#endif
}

bool MyDemoGui::activateModule(SUIT_Study *study)
{
    bool isDone(LightApp_Module::activateModule(study));
    if (isDone)
    {
        LightApp_Application *app(dynamic_cast<LightApp_Application *>(SUIT_Session::session()->activeApplication()));
        if (!app)
            return false;
        SUIT_ViewManager *aViewManager(app->getViewManager("MyDemo Window",
                                                           false)); // create if necessary
        if (aViewManager)
            aViewManager->setShown(false);
        // showView(true);
        setMenuShown(true);
        setToolShown(true);
    }
    return isDone;
}

bool MyDemoGui::deactivateModule(SUIT_Study *study)
{
    // hide own menus
    setMenuShown(false);
    // hide own toolbars
    setToolShown(false);

    // call parent implementation and return the activation status
    return LightApp_Module::deactivateModule(study);
}

MyDemoGui::~MyDemoGui()
{
    // do nothing
}
