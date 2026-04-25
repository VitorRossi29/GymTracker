cmake_minimum_required(VERSION 3.10)
project(GymTracker)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

add_subdirectory(glfw)

include_directories(
    imgui
    backends
)

add_executable(GymTracker
    main.cpp

    imgui/imgui.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_tables.cpp
    imgui/imgui_widgets.cpp

    backends/imgui_impl_glfw.cpp
    backends/imgui_impl_opengl3.cpp
)

target_link_libraries(GymTracker
    glfw
    OpenGL::GL
)