add_executable (lab6 main.cpp)

add_custom_target(run_lab6 DEPENDS lab6
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab6
)
