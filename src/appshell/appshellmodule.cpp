#include "appshellmodule.h"

#include <QQmlEngine>

// Links the module to the .qrc file
// WE put it outside of the app::appshell namespace
// because Q_INIT_RESOURCE can't be located inside a namespace
// (either it fails with error "couldn't find qLinkResources_app()")
static void appshell_init_qrc()
{
    Q_INIT_RESOURCE(appshell);
};

namespace app::appshell {

AppShellModule::AppShellModule() {};

std::string AppShellModule::moduleName() const {
    return "appshell";
};

void AppShellModule::registerResources() {
    appshell_init_qrc();
};

};

