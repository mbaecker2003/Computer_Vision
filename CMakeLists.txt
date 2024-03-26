cmake_minimum_required(VERSION 3.5.0)
project(main VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Include-path for Classes
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/BasicTransformation)

# Add Files for Classes
set(BasicTransformation_SOURCES
    BasicTransformation/BasicTransformation.cpp
)

# Add executable in main.cpp
add_executable(main main.cpp ${BasicTransformation_SOURCES})

# Link OpenCV-libary with executable
target_link_libraries(main ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
