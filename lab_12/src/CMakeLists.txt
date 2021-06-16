add_executable (lab_12 main.cpp)

add_custom_target(run_lab_12 DEPENDS lab_12
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab_12
)
