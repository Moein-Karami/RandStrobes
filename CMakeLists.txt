cmake_minimum_required(VERSION 3.5)

set(NAME_PROJECT RandStrobes.out)
set(CMAKE_CXX_STANDARD 20)

include_directories(Includes)

include_directories(Includes/Comparators)
include_directories(Includes/DataGenerators)
include_directories(Includes/DataStoringClasses)
include_directories(Includes/Hashers)
include_directories(Includes/Json)
include_directories(Includes/SeedCreators)


include_directories(Includes/Hashers/HashMethodes)
include_directories(Includes/Hashers/SeedBasedHashers)
include_directories(Includes/Hashers/SimpleHashers)

include_directories(Includes/SeedCreators/RandStrobeCreators)

include_directories(Includes/DataStoringClasses/Seed)

include_directories(Includes/ConfigGenerator)

project(${NAME_PROJECT}
    LANGUAGES CXX C)

add_executable(config.out)
target_sources(config.out PRIVATE ./Src/ConfigGenerator/ConfigGenerator.cpp ./Includes/ConfigGenerator/ConfigGenerator.hpp)
link_directories(./build)
target_link_libraries( config.out
    Maximizer
    Minimizer
    DataGen
    DataStore
    SeedCreators
    RandStrobeCreators
    RandStrobeCreators1
    RandStrobeCreators2
    RandStrobeCreators3
    RandStrobeCreators4
    RandStrobeCreators5
    RandStrobeCreators6
    RandStrobeCreators7
    Json
    Hashers 
    HashersMet1
    HashersMet2
    HashersSeed1
    HashersSeed2
    HashersSeed3
    HasherSimple1
    HasherSimple2 
    ResultPrinter
)

add_executable(${NAME_PROJECT})
target_sources(${NAME_PROJECT} PRIVATE ./Src/BenchMark.cpp ./Includes/BenchMark.hpp )
link_directories(./build)
target_link_libraries(${NAME_PROJECT} 
    Maximizer
    Minimizer
    DataGen
    DataStore
    SeedCreators
    RandStrobeCreators
    RandStrobeCreators1
    RandStrobeCreators2
    RandStrobeCreators3
    RandStrobeCreators4
    RandStrobeCreators5
    RandStrobeCreators6
    RandStrobeCreators7
    Json
    Hashers 
    HashersMet1
    HashersMet2
    HashersSeed1
    HashersSeed2
    HashersSeed3
    HasherSimple1
    HasherSimple2 
    ResultPrinter
    ConfigGen
    )

set (LIBRARY_OUTPUT_PATH ./build)

#Comperators ******************************

add_library(Maximizer STATIC ./Src/Comparators/Maximizer.cpp)

add_library(Minimizer STATIC ./Src/Comparators/Minimizer.cpp)

#DataGenerators ***********************************

add_library(DataGen STATIC ./Src/DataGenerators/RandomDataGenerator.cpp)

#DataStoring *******************************************

add_library(DataStore STATIC ./Src/DataStoringClasses/Strobe.cpp)

#SeedCreators ***************************************

add_library(SeedCreators STATIC ./Src/SeedCreators/SeedCreator.cpp)

add_library(RandStrobeCreators STATIC ./Src/SeedCreators/RandStrobeCreators/RandStrobeCreator.cpp
   ./Src/SeedCreators/SeedCreator.cpp)

add_library(RandStrobeCreators1 STATIC ./Src/SeedCreators/RandStrobeCreators/RandStrobeCreatorGuoPibri.cpp
    ./Src/SeedCreators/RandStrobeCreators/RandStrobeCreator.cpp ./Src/DataStoringClasses/Strobe.cpp
    ./Src/SeedCreators/SeedCreator.cpp) 
add_library(RandStrobeCreators2 STATIC ./Src/SeedCreators/RandStrobeCreators/RandStrobeCreatorLiuPatroLi.cpp
    ./Src/SeedCreators/RandStrobeCreators/RandStrobeCreator.cpp ./Src/DataStoringClasses/Strobe.cpp
    ./Src/SeedCreators/SeedCreator.cpp)
add_library(RandStrobeCreators3 STATIC ./Src/SeedCreators/RandStrobeCreators/RandStrobeCreatorSahlinBitCount.cpp
    ./Src/SeedCreators/RandStrobeCreators/RandStrobeCreator.cpp ./Src/DataStoringClasses/Strobe.cpp
    ./Src/SeedCreators/SeedCreator.cpp)
add_library(RandStrobeCreators4 STATIC ./Src/SeedCreators/RandStrobeCreators/RandStrobeCreatorSahlinMod.cpp
    ./Src/SeedCreators/RandStrobeCreators/RandStrobeCreator.cpp ./Src/DataStoringClasses/Strobe.cpp
    ./Src/SeedCreators/SeedCreator.cpp)
add_library(RandStrobeCreators5 STATIC ./Src/SeedCreators/RandStrobeCreators/RandStrobeCreatorShen.cpp
    ./Src/SeedCreators/RandStrobeCreators/RandStrobeCreator.cpp ./Src/DataStoringClasses/Strobe.cpp
    ./Src/SeedCreators/SeedCreator.cpp)
add_library(RandStrobeCreators6 STATIC ./Src/SeedCreators/RandStrobeCreators/RandStrobeCreatorXorVar.cpp
    ./Src/SeedCreators/RandStrobeCreators/RandStrobeCreator.cpp ./Src/DataStoringClasses/Strobe.cpp
    ./Src/SeedCreators/SeedCreator.cpp)

add_library(RandStrobeCreators7 STATIC ./Src/SeedCreators/RandStrobeCreators/RandStrobeCreatorMAMod.cpp
    ./Src/SeedCreators/RandStrobeCreators/RandStrobeCreator.cpp ./Src/DataStoringClasses/Strobe.cpp
    ./Src/SeedCreators/SeedCreator.cpp)
#Json***********************************************

add_library(Json STATIC ./Src/Json/jsoncpp.cpp)

#Hashers ***************************************

add_library(Hashers STATIC ./Src/Hashers/Hasher.cpp)

add_library(HashersMet1 STATIC ./Src/Hashers/HashMethodes/index.cpp)
add_library(HashersMet2 STATIC ./Src/Hashers/HashMethodes/xxhash.c)

add_library(HashersSeed1 STATIC ./Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp)
add_library(HashersSeed2 STATIC ./Src/Hashers/SeedBasedHashers/WyHash.cpp)
add_library(HashersSeed3 STATIC ./Src/Hashers/SeedBasedHashers/XXHash.cpp ./Src/Hashers/HashMethodes/xxhash.c 
    ./Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp)

add_library(HasherSimple1 STATIC ./Src/Hashers/SimpleHashers/NoHash.cpp)
add_library(HasherSimple2 STATIC ./Src/Hashers/SimpleHashers/ThomasWangHash.cpp)

#ResultPrinter***********************************************

add_library(ResultPrinter STATIC ./Src/ResultPrinter.cpp)

#******************************************************

add_library(ConfigGen STATIC ./Src/ConfigGenerator/ConfigGenerator.cpp)

#*********************************************************
