set(backend
        Backend/Win32Core.cpp
        Backend/Win32.cpp
)

set(backend_headers
        Backend/Win32.h
        Backend/Win32Core.h
        Backend/Backend.h
)

set (ui_component
        Ui/Component/Win32Window.cpp
)

set(ui_component_headers
        Ui/Component/Element.h
        Ui/Component/Win32Window.h
)

set(ui_component_api
        Ui/Component/api/ElementApi.h
        Backend/Api/CoreApiConcept.h
)

set (all_headers
        ${backend_headers}
        ${ui_component_headers}
        ${ui_component_api}
)

set (all_sources
        ${backend}
        ${ui_component}
        ${ui_component_api}
)

set (all_files
        ${all_headers}
        ${all_sources}
)

add_executable(${PROJECT_NAME}_playground main.cpp ${all_files}
)
target_link_libraries(${PROJECT_NAME}_playground PUBLIC glm)


add_library(${PROJECT_NAME} STATIC ${all_files})
target_link_libraries(${PROJECT_NAME} PUBLIC glm)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(
        .
)