cmake_minimum_required(VERSION 3.5)

project(LibraryManagementSoftware VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        managebooks.cpp
        managebooks.h
        managebooks.ui
        addbook.cpp
        addbook.h
        addbook.ui
        deletebook.cpp
        deletebook.h
        deletebook.ui
        findbook.cpp
        findbook.h
        findbook.ui
        databaseheader.h
        login.cpp
        login.h
        login.ui
        addmember.cpp
        addmember.h
        addmember.ui
        edit_member.cpp
        edit_member.h
        edit_member.ui
        deletemember.cpp
        deletemember.h
        deletemember.ui
        viewmember.cpp
        viewmember.h
        viewmember.ui
        member_management.cpp
        member_management.h
        member_management.ui
        issuebook.cpp
        issuebook.h
        issuebook.ui
        signup.cpp
        signup.ui
        signup.h
        resource.qrc
        editbook.cpp
        editbook.h
        editbook.ui
    )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(LibraryManagementSoftware
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET LibraryManagementSoftware APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(LibraryManagementSoftware SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(LibraryManagementSoftware
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(LibraryManagementSoftware PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

set_target_properties(LibraryManagementSoftware PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS LibraryManagementSoftware
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(LibraryManagementSoftware)
endif()
