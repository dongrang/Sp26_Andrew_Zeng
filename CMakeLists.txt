cmake_minimum_required(VERSION 3.20)
project(Cervantes VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

find_package(OpenGL REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(third_party/glfw)


add_library(glad STATIC third_party/glad/src/gl.c)
target_include_directories(glad PUBLIC third_party/glad/include)

add_library(stb_image STATIC third_party/stb_image/stb_image.c)
target_include_directories(stb_image PUBLIC third_party/stb_image)

add_library(CervantesLib     
    src/core/application.cpp
    src/core/Picture.cpp    
    src/core/PictureOpenGL.cpp   
    src/core/Shader.cpp     
    src/core/ShaderOpenGL.cpp    
    src/core/window.cpp
    src/core/Events.cpp    
    src/core/OpenGLWindow.cpp
    src/core/OpenGLRenderer.cpp
    src/core/Renderer.cpp
    src/core/Unit.cpp
    src/core/Screen.cpp
    )
target_include_directories(CervantesLib PUBLIC includes)

target_precompile_headers(CervantesLib PUBLIC src/pch.hpp)

target_link_libraries(CervantesLib PRIVATE OpenGL::GL glfw glad stb_image)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}/game)
add_subdirectory(game)