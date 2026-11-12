cmake_minimum_required(VERSION 3.15)
project(PolyInfusion LANGUAGES CXX)

add_executable(PolyInfusion
    src/main.cpp
    src/console/Console.cpp
    src/distributeurEau/DistributeurEau.cpp
    src/distributeurEau/DistributeurEauPro.cpp
    src/distributeurEau/DistributeurEauCompact.cpp
    src/distributeurEau/EauInsuffisante.cpp
    src/distributeurThe/DistributeurThe.cpp
    src/distributeurThe/DistributeurThePro.cpp
    src/distributeurThe/DistributeurTheCompact.cpp
    src/distributeurThe/TheInsuffisant.cpp
    src/fabrique/FabriqueSysteme.cpp
    src/notification/AppDistant.cpp
    src/notification/Ecran.cpp
    src/notification/Notificateur.cpp
    src/notification/Observateur.cpp
    src/preparation/Infuseur.cpp
    src/preparation/Rinceur.cpp
    src/systeme/Systeme.cpp
    src/systeme/SystemePro.cpp
    src/systeme/SystemeCompact.cpp
    src/systemeChauffage/SystemeChauffage.cpp
    src/systemeChauffage/SystemeChauffagePro.cpp
    src/systemeChauffage/SystemeChauffageCompact.cpp
)
target_include_directories(PolyInfusion PRIVATE include)
target_compile_features(PolyInfusion PRIVATE cxx_std_17)
set_target_properties(PolyInfusion PROPERTIES CXX_EXTENSIONS OFF)
if(MSVC)
    target_compile_options(PolyInfusion PRIVATE /W4 /utf-8)
else()
    target_compile_options(PolyInfusion PRIVATE -Wall -Wextra -Wpedantic)
endif()
