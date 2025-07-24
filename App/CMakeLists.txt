set(PROJECT_SOURCES
    main.cpp
    MainWindow/MainWindow.cpp
    MainWindow/MainWindow.hpp
    MainWindow/MainWindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(WiedzminYzeApp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Character/CharacterWindow.hpp Character/CharacterWindow.cpp Character/CharacterWindow.ui
    )

# Define target properties for Android with Qt 6 as:
# set_property(TARGET WiedzminYzeApp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
# ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(WiedzminYzeApp SHARED
            ${PROJECT_SOURCES}
        )

    # Define properties for Android with Qt 5 after find_package() calls as:
    # set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(WiedzminYzeApp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(WiedzminYzeApp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# target_link_libraries(WiedzminYzeApp PRIVATE dpp::dpp)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.WiedzminYzeApp)
endif()

set_target_properties(WiedzminYzeApp PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS WiedzminYzeApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(WiedzminYzeApp)
endif()
