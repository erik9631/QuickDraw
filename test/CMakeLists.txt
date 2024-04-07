set(src
    mainTests.cpp
)


add_executable(${PROJECT_NAME}_tests ${src})
target_link_libraries(${PROJECT_NAME}_tests PUBLIC catch_amalgamated)