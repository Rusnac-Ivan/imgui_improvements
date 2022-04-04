#
# === CMake lists for the mlpack_sandbox ===
#


# === CMake options ===

# Set CMake version
cmake_minimum_required(VERSION 3.15 FATAL_ERROR) 

project(imgui_improvements LANGUAGES C CXX)

# Include cmake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Set src and include root path
set(SRC_ROOT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src/")

set(INCLUDE_ROOT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/include/")

file(
    GLOB_RECURSE INCLUDE_LIST
    LIST_DIRECTORIES false
    "${INCLUDE_ROOT_PATH}/*.hpp"
    "${INCLUDE_ROOT_PATH}/*.h"
)

file(
    GLOB_RECURSE SOURCE_FILES
    LIST_DIRECTORIES false
    "${SRC_ROOT_PATH}/*.c"
    "${SRC_ROOT_PATH}/*.cpp"
    "${SRC_ROOT_PATH}/*.h"
    "${SRC_ROOT_PATH}/*.hpp"
)

foreach(_include IN ITEMS ${INCLUDE_LIST})
    get_filename_component(_include_path "${_include}" PATH)
    file(RELATIVE_PATH _include_path_rel "${INCLUDE_ROOT_PATH}" "${_include_path}")
    string(REPLACE "/" "\\" _group_path2 "${_include_path_rel}")
    source_group("include\\${_group_path2}" FILES "${_include}")
endforeach()

foreach(_source IN ITEMS ${SOURCE_FILES})
    get_filename_component(_source_path "${_source}" PATH)
    file(RELATIVE_PATH _source_path_rel "${SRC_ROOT_PATH}" "${_source_path}")
    string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
    source_group("source\\${_group_path}" FILES "${_source}")
endforeach()

add_executable(${PROJECT_NAME} ${INCLUDE_LIST} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE  ${INCLUDE_ROOT_PATH} ${SRC_ROOT_PATH})

if(IMGUI_PATH)
    set(IMGUI_SRC 
            ${IMGUI_PATH}/imconfig.h
            ${IMGUI_PATH}/imgui.cpp
            ${IMGUI_PATH}/imgui.h
            ${IMGUI_PATH}/imgui_demo.cpp
            ${IMGUI_PATH}/imgui_draw.cpp
            ${IMGUI_PATH}/imgui_internal.h
            ${IMGUI_PATH}/imgui_tables.cpp
            ${IMGUI_PATH}/imgui_widgets.cpp
            ${IMGUI_PATH}/imstb_rectpack.h
            ${IMGUI_PATH}/imstb_textedit.h
            ${IMGUI_PATH}/imstb_truetype.h
            ${IMGUI_PATH}/backends/imgui_impl_opengl3.cpp
            ${IMGUI_PATH}/backends/imgui_impl_opengl3.h
            ${IMGUI_PATH}/backends/imgui_impl_glfw.cpp
            ${IMGUI_PATH}/backends/imgui_impl_glfw.h
    )
    
    foreach(_source IN ITEMS ${IMGUI_SRC})
        get_filename_component(_source_path "${_source}" PATH)
        file(RELATIVE_PATH _source_path_rel "${IMGUI_PATH}" "${_source_path}")
        string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
        source_group("source\\imgui\\${_group_path}" FILES "${_source}")
    endforeach()
    
    message(STATUS "IMGUI_SRC: ${IMGUI_SRC}")
    target_sources(${PROJECT_NAME} PRIVATE ${IMGUI_SRC})
    target_include_directories(${PROJECT_NAME} PRIVATE ${IMGUI_PATH})
else()
    message(FATAL_ERROR "IMGUI_PATH is not set!")
endif()

find_package(GLFW3 REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${GLFW3_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${GLFW3_LIBRARY})
message(STATUS "GLFW3_ROOT: ${GLFW3_ROOT}")
message(STATUS "GLFW3_INCLUDE_DIR: ${GLFW3_INCLUDE_DIR}")
message(STATUS "GLFW3_LIBRARY: ${GLFW3_LIBRARY}")
