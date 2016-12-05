project(Ass2)

link_directories(src)

add_subdirectory(src)
add_subdirectory(test)

set(SOURCE_FILES src)
add_executable(Ass2 ${SOURCE_FILES})
