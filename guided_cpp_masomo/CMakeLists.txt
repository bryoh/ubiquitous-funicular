cmake_minimum_required(VERSION 3.16)

project(guided_cpp_masomo VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

option(GUIDED_CPP_BUILD_GUI "Build the Qt Widgets application when Qt is available" ON)
option(GUIDED_CPP_BUILD_TESTS "Build tests when GoogleTest is available" ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(guided_cpp_core
  src/csv/csv_importer.cpp
  src/core/dataset.cpp
)

target_include_directories(guided_cpp_core
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(guided_cpp_core PUBLIC cxx_std_17)

add_executable(csv_preview_cli
  src/app/cli_main.cpp
)

target_link_libraries(csv_preview_cli PRIVATE guided_cpp_core)

if(GUIDED_CPP_BUILD_GUI)
  find_package(Qt6 QUIET COMPONENTS Widgets Charts)
  find_package(Qt5 QUIET COMPONENTS Widgets Charts)

  if(Qt6_FOUND)
    qt_standard_project_setup()

    qt_add_executable(csv_chart_studio
      src/ui/dataset_table_model.cpp
      src/ui/main.cpp
      src/ui/main_window.cpp
    )

    target_link_libraries(csv_chart_studio
      PRIVATE
        guided_cpp_core
        Qt6::Widgets
        Qt6::Charts
    )
  elseif(Qt5_FOUND)
    add_executable(csv_chart_studio
      src/ui/dataset_table_model.cpp
      src/ui/main.cpp
      src/ui/main_window.cpp
    )

    target_link_libraries(csv_chart_studio
      PRIVATE
        guided_cpp_core
        Qt5::Widgets
        Qt5::Charts
    )
  else()
    message(STATUS "Qt Widgets/Charts not found; skipping csv_chart_studio target")
  endif()
endif()

if(GUIDED_CPP_BUILD_TESTS)
  enable_testing()
  find_package(GTest QUIET)

  if(GTest_FOUND)
    add_executable(guided_cpp_tests
      tests/dataset_test.cpp
    )

    target_link_libraries(guided_cpp_tests
      PRIVATE
        guided_cpp_core
        GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(guided_cpp_tests)
  else()
    message(STATUS "GoogleTest not found; skipping guided_cpp_tests target")
  endif()
endif()
