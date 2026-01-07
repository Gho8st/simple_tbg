cmake_minimum_required(VERSION 3.22.1)
project(SimpleTBG CXX)

find_package(PkgConfig REQUIRED)
pkg_check_modules(RAYLIB REQUIRED raylib)

add_executable(SimpleTBG
    src/main.cpp
    src/states/menu_state.cpp
    src/states/state_manager.cpp
    src/states/battle_state.cpp

    module/imgui/imgui.cpp
    module/imgui/imgui_draw.cpp
    module/imgui/imgui_tables.cpp
    module/imgui/imgui_widgets.cpp

    module/rlImGui/rlImGui.cpp
)

target_include_directories(SimpleTBG PRIVATE
    include
    module/imgui
    module/rlImGui
    ${RAYLIB_INCLUDE_DIRS}
)

target_link_libraries(SimpleTBG ${RAYLIB_LIBRARIES})