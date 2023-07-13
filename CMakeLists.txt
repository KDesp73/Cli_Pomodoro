cmake_minimum_required(VERSION 3.5)
project(CliPomodoro)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(Cli-Kit)
include_directories(Cli-Kit include)
 
# Add your source files
set(SOURCES
    src/main.cpp
    
    src/timer/timer.cpp
    src/timer/time.cpp
    
    src/menu/menu.cpp

    src/pomodoro/pomodoro.cpp
    src/utils/utils.cpp
)

# Add your header files
set(HEADERS
    include/timer.h
    include/my_time.h
    include/menu.h
    include/pomodoro.h
    include/utils.h
)

set(TESTS
)

# Add an executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${TESTS})

target_link_libraries(${PROJECT_NAME} CliKit)


