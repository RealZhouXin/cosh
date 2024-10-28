add_subdirectory(utils)
message(STATUS "ALL_OBJECT_FILES: ${ALL_OBJECT_FILES}")

add_library(coshd SHARED ${ALL_OBJECT_FILES})

set(THIRD_PARTY_LIBS
        fmt::fmt
        spdlog::spdlog
        cjson::cjson
        cppzmq
        # STDEXEC::stdexec
        )
target_link_libraries(coshd PRIVATE ${THIRD_PARTY_LIBS})

# add_executable(cosh main.cpp)
# target_link_libraries(cosh PRIVATE coshd)