import QtQuick 2.15

import Muse.UiComponents 1.0

AppWindow {
    id: root

    function toggleMaximized() {
        if (root.visibility === Window.Maximized) {
            root.showNormal()
        } else {
            root.showMaximized()
        }
    }

    AppTitleBar {
        id: appTitleBar

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        height: 48
        title: root.title

        onShowWindowMinimizedRequested: {
            root.showMinimized()
        }

        onToggleWindowMaximizedRequested: {
            root.toggleMaximized()
        }

        onCloseWindowRequested: {
            root.close()
        }
    }

    WindowContent {
        id: window

        anchors.top: appTitleBar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchorsbottom: parent.bottom
    }
}

