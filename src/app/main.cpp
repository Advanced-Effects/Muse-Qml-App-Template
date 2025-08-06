#include "application.h"

#include <QCoreApplication>
#include <QQmlApplicationEngine>
#include <QApplication>

#include "application.h"
#include "commandlineparser.h"

// Modules
#include "global/globalmodule.h"
#include "actions/actionsmodule.h"
#include "context/contextmodule.h"
#include "ui/uimodule.h"
#include "shortcuts/shortcutsmodule.h"
#include "accessibility/accessibilitymodule.h"
#include "uicomponents/uicomponentsmodule.h"
#include "dockwindow/dockmodule.h"
#include "network/networkmodule.h"
#include "learn/learnmodule.h"
#include "languages/languagesmodule.h"
#include "workspace/workspacemodule.h"
#include "appshell/appshellmodule.h"

using namespace app::app;

int main(int argc, char *argv[]) {
    Application application;

    /* ============= Load application modules ============= */
    application.addModule(new muse::GlobalModule());
    application.addModule(new muse::actions::ActionsModule());
    application.addModule(new muse::workspace::WorkspaceModule());
    application.addModule(new muse::accessibility::AccessibilityModule());
    application.addModule(new muse::learn::LearnModule());
    application.addModule(new muse::languages::LanguagesModule());
    application.addModule(new mu::context::ContextModule());
    application.addModule(new muse::ui::UiModule());
    application.addModule(new muse::uicomponents::UiComponentsModule());
    application.addModule(new muse::dock::DockModule());
    application.addModule(new muse::shortcuts::ShortcutsModule());
    application.addModule(new muse::network::NetworkModule());
    application.addModule(new app::appshell::AppShellModule());

    /* ============= Initialize command line arguments ============= */
    CommandLineParser commandLineParser;
    commandLineParser.init();
    commandLineParser.parse(argc, argv);

    /* ============= Initialize Qt Application ============= */
    QCoreApplication *qApplication = new QApplication(argc, argv);
    QQmlApplicationEngine *qEngine = new QQmlApplicationEngine();
    qEngine->addImportPath(":/qml");

    /* ============= Execute ============= */
    return application.exec(*qApplication, commandLineParser, *qEngine);

    delete qApplication;
};

