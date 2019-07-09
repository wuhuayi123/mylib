add_executable (unit-test
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp

    # TODO ADD SOURCE HERE
    )

target_link_libraries (unit-test mylib)
INSTALL(TARGETS unit-test RUNTIME DESTINATION bin)
