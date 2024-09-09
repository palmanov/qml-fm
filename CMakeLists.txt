cmake_minimum_required(VERSION 3.14)

project(qmlfilemanager VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt5 COMPONENTS Core Quick QuickControls2 Widgets DBus REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick QuickControls2 Widgets DBus REQUIRED)

add_subdirectory(service)

include_directories(include)

set(PROJECT_SOURCES
  src/main.cpp
  include/filesystemmodel.h
  src/filesystemmodel.cpp
  include/iconprovider.h
  src/iconprovider.cpp
  include/filemanager.h
  src/filemanager.cpp
  qml.qrc
  res.qrc
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::QuickControls2 Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::DBus)
