add_executable (lab2 main.cpp)

add_custom_target(run_lab2 DEPENDS lab2
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab2
)
