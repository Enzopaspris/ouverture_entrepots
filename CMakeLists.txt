cmake_minimum_required(VERSION 3.10)
project(ouverture_entrepots VERSION 1.0 LANGUAGES CXX)

# Utiliser C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Ajouter le dossier des headers
include_directories(include)

# Récupérer tous les fichiers source
file(GLOB SOURCES "source/*.cpp")

# Trouver Qt5
find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

# Créer l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Lier Qt à l'exécutable
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets)

# Spécifier que l'exécutable sera généré dans le dossier build
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)
