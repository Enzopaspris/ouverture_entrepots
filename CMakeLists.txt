cmake_minimum_required(VERSION 3.16)
project(ProjetEntrepot)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

include_directories(include)

add_executable(ProjetEntrepot
    source/main.cpp
    source/fonction_menu.cpp
    source/fonctions_forcebrute.cpp
    source/fonctions_arborescente.cpp
)

target_link_libraries(ProjetEntrepot Qt6::Widgets)
