#include "application.h"

#include <QCoreApplication>
#include <QApplication>

#include "application.h"
#include "commandlineparser.h"

// Modules
#include "ui/uimodule.h"
#include "uicomponents/uicomponentsmodule.h"
#include "appshell/appshellmodule.h"

using namespace app::app;

int main(int argc, char *argv[]) {
    Application application;

    /* ============= Load application modules ============= */
    application.addModule(new muse::ui::UiModule());
    application.addModule(new muse::uicomponents::UiComponentsModule());
    application.addModule(new app::appshell::AppShellModule());

    /* ============= Initialize command line arguments ============= */
    CommandLineParser commandLineParser;
    commandLineParser.init();
    commandLineParser.parse(argc, argv);

    /* ============= Initialize Qt Application ============= */
    QCoreApplication *qApplication = new QApplication(argc, argv);

    /* ============= Execute ============= */
    return application.exec(*qApplication, commandLineParser);

    delete qApplication;
};

