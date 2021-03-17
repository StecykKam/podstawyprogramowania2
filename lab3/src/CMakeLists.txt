add_executable (lab3 main.cpp)

add_custom_target(run_lab3 DEPENDS lab3
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab3
)
