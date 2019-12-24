cmake_minimum_required(VERSION 2.8)

project(hello_world)
set(SOURCE_EXE main.cpp)

set(BUILD_LIBS 
    upper 
    version
)


set(INCLUDE_DIRS 
    upper 
    version
)

foreach(LIB ${BUILD_LIBS})
    file(GLOB LIB_SOURCE "${LIB}/*.cpp")
    add_library(${LIB} SHARED ${LIB_SOURCE})
    target_compile_features(${LIB} PUBLIC cxx_std_17)
endforeach()



add_executable(printUpper ${SOURCE_EXE})
target_compile_features(printUpper PUBLIC cxx_std_17)
target_include_directories(printUpper PRIVATE ${INCLUDE_DIRS})
target_link_libraries(printUpper ${BUILD_LIBS})

install(TARGETS printUpper ${BUILD_LIBS}
    RUNTIME DESTINATION "/usr/bin" COMPONENT libraries
    LIBRARY DESTINATION "/usr/lib" COMPONENT libraries
)

SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "KK") #required
INCLUDE(CPack)