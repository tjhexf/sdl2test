cmake_minimum_required(VERSION 3.0.0)
project(sdltest VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()



add_subdirectory(SDL)

add_executable(sdltest src/init.c src/main.c)

INCLUDE_DIRECTORIES (SDL/include/SDL2)

if (DEFINED EMSCRIPTEN)
    target_link_options(${PROJECT_NAME} PRIVATE
    "-SALLOW_MEMORY_GROWTH=1"
    )
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    target_link_libraries(sdltest SDL2main SDL2-static)
elseif(WIN32)
    target_link_libraries(sdltest mingw32 SDL2main SDL2)
else()
    target_link_libraries(sdltest SDL2main SDL2)
endif()



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
