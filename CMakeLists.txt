cmake_minimum_required(VERSION 3.10)
project(ouverture_entrepots VERSION 1.0 LANGUAGES CXX)

# Utiliser le standard C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Inclure le dossier des headers
include_directories(include)

# Ajouter tous les fichiers sources
file(GLOB SOURCES "source/*.cpp")

# Créer l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES})
