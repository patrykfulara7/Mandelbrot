set(MANDELBROT_PRJ_NAME mandelbrot)
project(${MANDELBROT_PRJ_NAME})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../..)

add_executable(${MANDELBROT_PRJ_NAME})
add_subdirectory(src)
target_include_directories(${MANDELBROT_PRJ_NAME} PRIVATE src)
target_link_libraries(${MANDELBROT_PRJ_NAME} PRIVATE automata)
