cmake_minimum_required(VERSION 3.20)

project(SelfCpp LANGUAGES CXX)

# --------------------------------------------------
# Global settings
# --------------------------------------------------

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# --------------------------------------------------
# Options
# --------------------------------------------------

option(ENABLE_SANITIZERS "Enable Address/Undefined sanitizers" ON)
option(ENABLE_CLANG_TIDY "Enable clang-tidy if available" OFF)
option(ENABLE_TESTING "Enable CTest" ON)
option(ENABLE_FMT "Enable fmt if available/fetched" OFF)

# --------------------------------------------------
# Warnings
# --------------------------------------------------

add_compile_options(
  -Wall
  -Wextra
  -Wpedantic
)

# --------------------------------------------------
# Sanitizers
# --------------------------------------------------

if(ENABLE_SANITIZERS AND CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
  add_compile_options(
    -O0
    -g
    -fno-omit-frame-pointer
    -fsanitize=address,undefined
  )

  add_link_options(
    -fsanitize=address,undefined
  )
endif()

# --------------------------------------------------
# clang-tidy
# --------------------------------------------------

if(ENABLE_CLANG_TIDY)
  find_program(CLANG_TIDY_EXE NAMES clang-tidy)
  if(CLANG_TIDY_EXE)
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
    message(STATUS "clang-tidy enabled: ${CLANG_TIDY_EXE}")
  else()
    message(WARNING "ENABLE_CLANG_TIDY=ON, but clang-tidy was not found.")
  endif()
endif()

# --------------------------------------------------
# fmt (optional)
# --------------------------------------------------

if(ENABLE_FMT)
  include(FetchContent)
  FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 11.0.2
  )
  FetchContent_MakeAvailable(fmt)
endif()

# --------------------------------------------------
# Testing
# --------------------------------------------------

if(ENABLE_TESTING)
  include(CTest)
  enable_testing()
endif()

# --------------------------------------------------
# Common library (optional)
# --------------------------------------------------

set(COMMON_DIR "${CMAKE_SOURCE_DIR}/common")

if(EXISTS "${COMMON_DIR}")
  file(GLOB_RECURSE COMMON_SOURCES
    CONFIGURE_DEPENDS
    "${COMMON_DIR}/*.cpp"
  )

  if(COMMON_SOURCES)
    add_library(common STATIC ${COMMON_SOURCES})
    target_include_directories(common PUBLIC "${COMMON_DIR}")

    target_compile_features(common PUBLIC cxx_std_20)

    if(ENABLE_FMT)
      target_link_libraries(common PUBLIC fmt::fmt)
    endif()
  endif()
endif()

# --------------------------------------------------
# Discover exercises: directories containing main.cpp
# --------------------------------------------------

file(GLOB_RECURSE MAIN_FILES
  CONFIGURE_DEPENDS
  "${CMAKE_SOURCE_DIR}/Chap*/main.cpp"
  "${CMAKE_SOURCE_DIR}/Chap*/*/main.cpp"
  "${CMAKE_SOURCE_DIR}/Chap*/*/*/main.cpp"
)

if(NOT MAIN_FILES)
  message(FATAL_ERROR "No main.cpp files found under Chap* directories.")
endif()

foreach(main_src IN LISTS MAIN_FILES)
  file(READ "${main_src}" source_text)
  if(source_text MATCHES "CMAKE_SKIP_EXE")
    continue()
  endif()

  get_filename_component(ex_dir "${main_src}" DIRECTORY)
  file(RELATIVE_PATH rel_dir "${CMAKE_SOURCE_DIR}" "${ex_dir}")

  string(REPLACE "/" "_" target "${rel_dir}")

  file(GLOB EX_SOURCES
    CONFIGURE_DEPENDS
    "${ex_dir}/*.cpp"
  )

  add_executable(${target} ${EX_SOURCES})
  target_compile_features(${target} PRIVATE cxx_std_20)

  target_include_directories(${target}
    PRIVATE
      "${CMAKE_SOURCE_DIR}"
  )

  if(TARGET common)
    target_link_libraries(${target} PRIVATE common)
  endif()

  if(ENABLE_FMT)
    target_link_libraries(${target} PRIVATE fmt::fmt)
  endif()

  # ----------------------------------------------
  # run_<target>
  # ----------------------------------------------
  add_custom_target(run_${target}
    COMMAND ${target}
    DEPENDS ${target}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    USES_TERMINAL
  )

  # ----------------------------------------------
  # Per-exercise tests
  # If test.cmake exists in the same directory,
  # expose TARGET_NAME and TARGET_PATH to it.
  # ----------------------------------------------
  if(ENABLE_TESTING)
    set(TARGET_NAME "${target}")
    set(TARGET_PATH "$<TARGET_FILE:${target}>")
    set(TEST_CMAKE_FILE "${ex_dir}/test.cmake")

    if(EXISTS "${TEST_CMAKE_FILE}")
      include("${TEST_CMAKE_FILE}")
    endif()
  endif()
endforeach()