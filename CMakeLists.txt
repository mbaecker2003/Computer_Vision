cmake_minimum_required(VERSION 3.5.0)
project(main VERSION 0.1.0)

include(CTest)
enable_testing()

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

# Add the executable for main.cpp
add_executable(main main.cpp)

# Link OpenCV libraries to both executables
target_link_libraries(main ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
