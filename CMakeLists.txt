cmake_minimum_required(VERSION 3.15)

# ------------------------------------------------------------
# Nom du projet et paramètres globaux
# ------------------------------------------------------------
project(GestionEntrepots
    VERSION 1.0
    DESCRIPTION "Simulation d'affectation de magasins à des entrepôts"
    LANGUAGES CXX
)

# Utilisation du standard C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ------------------------------------------------------------
# Organisation des répertoires
# ------------------------------------------------------------
# Dossier contenant les fichiers sources et headers
set(SRC_DIR "${CMAKE_SOURCE_DIR}/source")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

# Inclure les headers globalement
include_directories(${INCLUDE_DIR})

# ------------------------------------------------------------
# Recherche automatique de tous les fichiers .cpp du projet
# ------------------------------------------------------------
file(GLOB_RECURSE PROJECT_SOURCES
    "${SRC_DIR}/*.cpp"
)

# ------------------------------------------------------------
# Création de l'exécutable
# ------------------------------------------------------------
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# ------------------------------------------------------------
# Options de compilation (mode debug/release)
# ------------------------------------------------------------
if(MSVC)
    # Options spécifiques à Visual Studio
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    # Options pour GCC/Clang
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

# ------------------------------------------------------------
# Tests unitaires (optionnels)
# ------------------------------------------------------------
enable_testing()
add_test(NAME run COMMAND ${PROJECT_NAME})

# ------------------------------------------------------------
# Message d'information après configuration
# ------------------------------------------------------------
message(STATUS "")
message(STATUS "🧩 Configuration du projet ${PROJECT_NAME}")
message(STATUS "📁 Sources : ${SRC_DIR}")
message(STATUS "📁 Includes : ${INCLUDE_DIR}")
message(STATUS "🔧 Mode de build : ${CMAKE_BUILD_TYPE}")
message(STATUS "")
