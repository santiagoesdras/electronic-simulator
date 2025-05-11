cmake_minimum_required(VERSION 3.19)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(simulator LANGUAGES C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)

option(USE_RAYLIB "Use raylib" ON)

# Funtions Common
include(FetchContent)
function(add_git_dependency libName gitURL gitTag)

        FetchContent_Declare(${libName}
            GIT_REPOSITORY ${gitURL}
            GIT_TAG        ${gitTag}
            GIT_SHALLOW    1
            GIT_PROGRESS   TRUE
        )

        if(NOT ("${libName}" STREQUAL "libname"))
            FetchContent_MakeAvailable(${libName})
        endif()

        # exclude lib to avoid errors
        if(NOT "${libName}" STREQUAL "libname" AND NOT "${libName}" STREQUAL "rlImGui")
            # target_compile_options(${libName} PRIVATE "-w")
        endif()
endfunction()

# Raylib setup
if(USE_RAYLIB)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games
    set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
    set(CUSTOMIZE_BUILD OFF CACHE BOOL "" FORCE)

    set(dep raylib)
    add_git_dependency(
        ${dep}
        https://github.com/raysan5/raylib.git
        master
    )

    FetchContent_GetProperties(${dep})
    if(NOT ${dep}_POPULATED)
        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/external/raylib/config.h ${CMAKE_CURRENT_SOURCE_DIR}/build/_deps/raylib-src/src/config.h COPYONLY)
        FetchContent_Populate(${dep})

        add_subdirectory(${${dep}_SOURCE_DIR} ${${dep}_BINARY_DIR})
    endif()

    # add the dependency here to be linked
    list(APPEND LIBRARIES ${dep})
endif()


# External C
add_library(external
    external/bitops.c
    external/circuit.c
    external/gates.c
    external/names.c
    external/names.h
)
target_include_directories(external PUBLIC ${CMAKE_SOURCE_DIR}/external)

# Simulator UI (C++)
add_library(ui
    simulator/ui/ui.cpp
    simulator/ui/ui.h
)
target_include_directories(ui 
    PUBLIC ${CMAKE_SOURCE_DIR}/simulator/ui
    projectUBLIC ${CMAKE_SOURCE_DIR}/external
        )

# Executable
add_executable(simulator main.cpp)
target_include_directories(simulator PRIVATE ${raylib_SOURCE_DIR}/src)
target_include_directories(ui PUBLIC ${raylib_SOURCE_DIR}/src)
target_link_libraries(simulator PRIVATE external ui raylib)
target_link_libraries(ui PUBLIC external)

add_executable(demo_widgets simulator/ui/widgets/demo_widgets.cpp)
target_link_libraries(demo_widgets raylib)
target_include_directories(demo_widgets PRIVATE ${CMAKE_SOURCE_DIR}/simulator/ui/widgets)

