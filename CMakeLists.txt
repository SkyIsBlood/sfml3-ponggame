cmake_minimum_required(VERSION 3.16)

# Enable Hot Reload for MSVC compilers if supported
if(POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project(firstgame LANGUAGES CXX)

# Capitalized component names for SFML 3
find_package(SFML COMPONENTS Graphics Window System REQUIRED)

file(GLOB_RECURSE PROJECT_SOURCES 
    CONFIGURE_DEPENDS
    "src/*.cpp"
    "src/*.hpp"
    "src/*.h"

)
add_executable(firstgame ${PROJECT_SOURCES})
add_custom_command(TARGET firstgame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/src/assets"
        "$<TARGET_FILE_DIR:firstgame>/assets"
)
target_compile_features(firstgame PRIVATE cxx_std_20)
target_include_directories(firstgame PRIVATE src)

# Capitalized, namespaced targets for SFML 3
target_link_libraries(firstgame PRIVATE 
    SFML::Graphics 
    SFML::Window 
    SFML::System
)