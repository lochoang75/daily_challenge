project(l_shell)
cmake_minimum_required(VERSION 3.10)
set(lsh_helper_src ${CMAKE_CURRENT_SOURCE_DIR}/src/lsh_main_helper.c
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/lsh_sig_handle.c
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/lsh_command.c
                    )
set(lsh_command_executor ${CMAKE_CURRENT_SOURCE_DIR}/src/executor/copy.c)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third_party/logging)
add_executable(${PROJECT_NAME} ${lsh_helper_src} ${lsh_command_executor})
target_include_directories(${PROJECT_NAME} PUBLIC ${printf_logging_SOURCE_DIR}
                                                    ${CMAKE_CURRENT_SOURCE_DIR}/include
                                                    ${CMAKE_CURRENT_SOURCE_DIR}/internal
                                                    ${CMAKE_CURRENT_SOURCE_DIR}/library)
target_link_libraries(${PROJECT_NAME} printf_logging)