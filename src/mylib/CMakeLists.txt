########################### CREATE LIBRARY #####################################

add_library(mylib

    ./main.cpp
    # TODO ADD SOURCE HERE
    )

target_link_libraries(mylib ${CONAN_LIBS})

########################### INSTALL HEADER #####################################

INSTALL(FILES

    # TODO ADD EXPORTED HEADER HERE

    DESTINATION

    include/maxhub/mylib)

########################### INSTALL LIBRARY ####################################
INSTALL(TARGETS mylib
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
