add_library(
    cosh_utils
    OBJECT
    log.cpp)
set(ALL_OBJECT_FILES
    ${ALL_OBJECT_FILES}
    $<TARGET_OBJECTS:cosh_utils>
    PARENT_SCOPE)
