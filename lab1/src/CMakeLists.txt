add_executable (lab1 main.cpp)

add_custom_target(run_lab1 DEPENDS lab1
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab1
)
