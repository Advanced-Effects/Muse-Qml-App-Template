#include "application.h"

#include <QQuickWindow>
#include <QQmlEngine>
#include <QQmlApplicationEngine>
#include <QObject>

#include <QStringLiteral>
#include <QString>
#include <QUrl>

// Links this application with app.qrc
// WE put it outside of the app::appshell namespace
// because Q_INIT_RESOURCE can't be located inside a namespace
// (either it fails with error "couldn't find qLinkResources_app()")
static void app_init_qrc() {
    Q_INIT_RESOURCE(app); // app.qrc
}

namespace app::app {

Application::Application() {};

void Application::addModule(muse::modularity::IModuleSetup *module) {
    _modules.push_back(module);
};

void Application::initalizeModules() {
    for (auto *m : _modules) {
        m->registerResources();
    };

    for (auto *m : _modules) {
        m->registerExports();
    };

    for (auto* m : _modules) {
        m->registerUiTypes();
        m->resolveImports();
        m->registerApi();
    }
}

void Application::deinitModules() {};

QQuickWindow *loadApplicationAndCreateWindow(QQmlApplicationEngine &engine) {
    // We load the Main.qml file to the application engine
    const QUrl url(QStringLiteral("qrc:/qml/Main.qml"));
    engine.load(url);

    // We get the root element (Main.qml)
    QObject *rootUiElement = engine.rootObjects().value(0);

    // Check if it exists
    if (!rootUiElement) {
        qWarning("\nMain.qml wasn't loaded correctly because no element was found in QQmlApplicationEngine OR there was an error.");
        return nullptr;
    }

    // If it exists, get the root element (Window) and cast it to a QQuickWindow
    return qobject_cast<QQuickWindow *>(rootUiElement);
}

int Application::exec(
        QCoreApplication& app,
        CommandLineParser& parser,
        QQmlApplicationEngine& engine) {
    app_init_qrc();
    // Initialize C++ QML types BEFORE loading the window!
    initalizeModules();

    QQuickWindow *window = loadApplicationAndCreateWindow(engine);
    if (!window) return EXIT_FAILURE;

    // Then show it
    window->show();

    // Start application loop (to avoid the application from quitting immediately)
    return app.exec();

    deinitModules();
};

};

