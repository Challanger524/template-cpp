cmake_minimum_required (VERSION 3.26)

project(template
        DESCRIPTION  "<description>"
        HOMEPAGE_URL "https://github.com/Challanger524/template-cpp"
        LANGUAGES     CXX)

# # Setup: main project # #

add_executable            (${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/include"         # project portable library
                                                   "${PROJECT_SOURCE_DIR}/src/int"         # project internal library
                                                   "${PROJECT_SOURCE_DIR}/src"           ) # project sources (.cpp/.hpp)
target_precompile_headers (${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/src/config.hpp") # force include to all source files
set_target_properties     (${PROJECT_NAME} PROPERTIES
  CXX_STANDARD          23
  CXX_STANDARD_REQUIRED ON
  RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}$<0:>" # put executable near the `res/` resource folder
  EXPORT_COMPILE_COMMANDS   ON                          # generate `out/build/${presetName}/compile_commands.json`
)

# # Apply: compile definitions # #
target_compile_definitions(${PROJECT_NAME} PRIVATE "${_DEFINITIONS_}")

# # Gather: sources # #
file(GLOB_RECURSE SOURCE_FILES_ CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/*.cpp")
list(FILTER SOURCE_FILES_ EXCLUDE REGEX ".*\\/_.*\\..*") # exclude files starting with uncderscore `_<file>`: https://regex101.com/r/DT6qGi/1
target_sources        (${PROJECT_NAME} PRIVATE ${SOURCE_FILES_})

# # Apply: compiler and linker flags (from: file:///./CMakePresets.json) # #
target_link_options   (${PROJECT_NAME} PRIVATE "${_FLAGS_LINKER_}")    # flags: linker
target_link_options   (${PROJECT_NAME} PRIVATE "${_FLAGS_COMP_LINK_}") # flags: linker & compiler (mutual)
target_compile_options(${PROJECT_NAME} PRIVATE "${_FLAGS_COMP_LINK_}") #
target_compile_options(${PROJECT_NAME} PRIVATE "${_FLAGS_COMPILE_0_}"  # flags: complier, inherit lvl: base GNU/LLVM (common flags)
                                               "${_FLAGS_COMPILE_1_}"  #                  inherit lvl: base compiler (GCC/Clang)
                                               "${_FLAGS_COMPILE_2_}") #                  inherit lvl: compiler (debug/release/..)

# # Setup: libraries # #

# # Apply: project dependencies # #

target_link_libraries     (${PROJECT_NAME} )
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE
  "${CMAKE_SOURCE_DIR}/dep"                               # silence dependencies
) # child dirs will be treated as SYSTEM, even if opposite stated explicitly (with: -I)


###Stash###

#set(CMAKE_VERBOSE_MAKEFILE ON CACHE BOOL "" FORCE) # debug compiling

# debug file(GLOB_RECURSE)
#string (REPLACE ";" "\n" SOURCE_FILES_ "${SOURCE_FILES_}")
#message(FATAL_ERROR ${SOURCE_FILES_})

#cmake_path(GET CMAKE_CACHEFILE_DIR FILENAME PRESET_)
#message(${CMAKE_CACHEFILE_DIR})
#message(${PRESET_})
