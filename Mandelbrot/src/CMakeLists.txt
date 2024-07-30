file(GLOB MANDELBROT_SRCS *.cxx *.hxx)

target_sources(${MANDELBROT_PRJ_NAME} PRIVATE ${MANDELBROT_SRCS})
target_precompile_headers(${MANDELBROT_PRJ_NAME} PRIVATE mppch.hxx)
