set(target ${LIBRARY})

file(GLOB hdrs "*.h*" "${INCLUDE}/*.h*")
file(GLOB srcs "*.cpp")

add_executable(${target} ${srcs} ${hdrs})

