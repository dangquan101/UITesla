cmake_minimum_required(VERSION 3.16)

project(TestlaInfortament VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appTestlaInfortament
    main.cpp
)

qt_add_qml_module(appTestlaInfortament
    URI TestlaInfortament
    VERSION 1.0
    QML_FILES
        Main.qml
        QML_FILES ui/BottomBar/BottomBar.qml
        RESOURCES ui/assets/carRender.jpg
        QML_FILES ui/RightScreen/RightScreen.qml
        QML_FILES ui/LeftScreen/LeftScreen.qml
        RESOURCES assets.qrc
        SOURCES Controllers/system.h Controllers/system.cpp
        QML_FILES ui/RightScreen/NavigationSearchBox.qml
        QML_FILES ui/BottomBar/HVAComponent.qml
        SOURCES Controllers/hvachandler.h Controllers/hvachandler.cpp
        SOURCES
        SOURCES Controllers/audiocontroler.h Controllers/audiocontroler.cpp
        QML_FILES ui/BottomBar/VolumControlerComponent.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appTestlaInfortament PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appTestlaInfortament
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appTestlaInfortament
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appTestlaInfortament
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
