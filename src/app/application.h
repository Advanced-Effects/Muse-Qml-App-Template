#pragma once

#include <QList>
#include <QApplication>
#include <QQmlApplicationEngine>

#include "modularity/imodulesetup.h"

#include "commandlineparser.h"

namespace app::app {

class Application {
public:
    Application();
    ~Application() = default;

    void addModule(muse::modularity::IModuleSetup* module);

    int exec(QCoreApplication& app, CommandLineParser& parser);

private:
    QList<muse::modularity::IModuleSetup*> _modules;

    void initalizeModules();
    void deinitModules();
};

};

