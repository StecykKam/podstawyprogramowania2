add_executable (lab5 main.cpp)

add_custom_target(run_lab5 DEPENDS lab5
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab5
)
