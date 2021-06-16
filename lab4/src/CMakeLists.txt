add_executable (lab4 main.cpp)

add_custom_target(run_lab4 DEPENDS lab4
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab4
)
