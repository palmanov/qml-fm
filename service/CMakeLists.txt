cmake_minimum_required(VERSION 3.14)

project(filehelper VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt5 COMPONENTS Core DBus REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core DBus REQUIRED)

include_directories(include)

set(PROJECT_SOURCES
  src/main.cpp
  include/FileHelperService.h
  src/FileHelperService.cpp
  include/filehelper_adaptor.h
  src/filehelper_adaptor.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::DBus)
