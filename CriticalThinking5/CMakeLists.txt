cmake_minimum_required(VERSION 4.1)
project(CriticalThinking5)
set(BASE_TXT_FILE "CSC450_CT5_mod5.txt")
set(CMAKE_CXX_STANDARD 20)

add_executable(CriticalThinking5 main.cpp)

add_custom_target(copy_base_txt_file ALL
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_SOURCE_DIR}/${BASE_TXT_FILE}"
        "${CMAKE_CURRENT_BINARY_DIR}/${BASE_TXT_FILE}"
        COMMENT "Copying ${BASE_TXT_FILE} to the build directory..."
)
add_dependencies(${PROJECT_NAME} copy_base_txt_file)
