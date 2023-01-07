cmake_minimum_required(VERSION 2.6)

project(MYPROJECT)

find_package(Geant4 REQUIRED)
include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)


add_executable(myproject main.cc DetectorConstruction.cc PrimaryGeneratorAction.cc RunAction.cc EventAction.cc SteppingAction.cc  GMTubeSD.cc PhysicsList.cc)

target_link_libraries(myproject ${Geant4_LIBRARIES})