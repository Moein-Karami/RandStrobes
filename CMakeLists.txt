cmake_minimum_required(VERSION 3.5)

set(NAME_PROJECT "RandStrobes")
set(VERSION_NUMBER 0.1)
set(LANG_USED CXX)
set(MAIN_FILE "")

project(${NAME_PROJECT}
    VERSION ${VERSION_NUMBER}
    LANGUAGES ${LANG_USED})

add_executable(${NAME_PROJECT} ben)
target_compile_features(HelloWorldApp PRIVATE cxx_std_11)