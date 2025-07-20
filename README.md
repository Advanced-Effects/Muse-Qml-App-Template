# Muse App Template

A template application that integrates Muse's UI framework.

So, you came here because you want to develop an **open-source GPL-3.0** app that looks and feels good.

## Recommended lectures

DO read-through these. Print if necessary. They will make development faster.

- C++ W3Schools: https://www.w3schools.com/cpp/default.asp
- Think in React: https://react.dev/learn/thinking-in-react
- CMake key concepts: https://cmake.org/cmake/help/book/mastering-cmake/chapter/Key%20Concepts.html
- QML positioning and layout: https://doc.qt.io/qt-6/qtquick-positioning-topic.html
- QML Module system: https://doc.qt.io/qt-6/qtqml-modules-topic.html
- QML State system: https://doc.qt.io/qt-6/qtquick-statesanimations-topic.html

**PROJECT IS IN CONSTRUCTION.** I want to build the best documentation possible, so if you have any questions at all about how to build this project or you're getting errors, contact me via GitHub issues or Discord: https://discord.gg/xbcecPfne6

## Recommended lectures

DO read-through these. Print if necessary. They will make development faster.

- C++ W3Schools: https://www.w3schools.com/cpp/default.asp
- Think in React: https://react.dev/learn/thinking-in-react
- CMake key concepts: https://cmake.org/cmake/help/book/mastering-cmake/chapter/Key%20Concepts.html
- QML positioning and layout: https://doc.qt.io/qt-6/qtquick-positioning-topic.html
- QML Module system: https://doc.qt.io/qt-6/qtqml-modules-topic.html
- QML State system: https://doc.qt.io/qt-6/qtquick-statesanimations-topic.html


## How it works

This application uses a different edition of Qt than is usually used: instead of using **Qt Widgets**, we use **QtQuick** and **QML**. It looks different and it's coded differently.

The module system used by MuseScore is slightly hard to understand at first. I will work on documentation that explains it later on.

## Dependencies & how to run

- Build system
  - C++17 compiler
  - CMake
  - Ninja
- Qt 6.9 (How to install?)
  - Core
  - Widgets
  - QML
  - QtQuick2
  - QtQuick2Controls
  - QtWebEngine
  - QtNetworkAuthAccess
- Muse framework dependencies

```
git clone https://github.com/kaixoo13/Muse-App-Template.git
mkdir build && cd build
cmake .. -DCMAKE_PREFIX_PATH= -DKORS_LOGGER_ENABLED=ON
cmake --build . -j4
```

