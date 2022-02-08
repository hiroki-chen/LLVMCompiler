# Set the minimum version of CMake required.
cmake_minimum_required(VERSION 3.10.0 FATAL_ERROR)

# Set the project name and version.
project(Kaleidoscope VERSION 1.0 LANGUAGES CXX)

# C++ standard settings.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE RELEASE)
# set(CMAKE_VERBOSE_MAKEFILE ON)

# Yacc and lex settings.
find_package(BISON)
find_package(FLEX)
set(YACC_SRC "${PROJECT_SOURCE_DIR}/src/parser/parser.ypp")
set(FLEX_SRC "${PROJECT_SOURCE_DIR}/src/parser/lexer.l")

# Configure the LLVM.
set(LLVM_DIR "/usr/local/Cellar/llvm/13.0.0_2/lib/cmake/llvm")
find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

# Configure the Clang.
set(Clang_DIR "/usr/local/Cellar/llvm/13.0.0_2/lib/cmake/clang")
find_package(Clang REQUIRED CONFIG)
include_directories(${CLANG_INCLUDE_DIRS})
add_definitions(${CLANG_DEFINITIONS})
message(STATUS "Found Clang ${CLANG_PACKAGE_VERSION}")
message(STATUS "Using ClangConfig.cmake in: ${Clang_DIR}")

# Check the compiler
set (SUPPRESS_WARN_FLAGS "${SUPPRESS_WARN_FLAGS} -Wno-return-type")
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(SUPPRESS_WARN_FLAGS "${SUPPRESS_WARN_FLAGS} -Wno-sign-compare \
                                                     -Wno-unused-parameter \
                                                     -Wno-nullability-completeness \
                                                     -Wno-register")
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(SUPPRESS_WARN_FLAGS "${SUPPRESS_WARN_FLAGS} -Wno-sign-compare -Wno-unused-parameter")

endif ()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG} ${SUPPRESS_WARN_FLAGS}")

IF(COMPILER_DEBUG)
    ADD_DEFINITIONS(-DCOMPILER_DEBUG)
ENDIF(COMPILER_DEBUG)

if ("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
    message("In-source builds are not allowed.")
endif ()

# Output yacc and lex files.
BISON_TARGET(yacc ${YACC_SRC} ${PROJECT_SOURCE_DIR}/src/parser/parser.cc)
FLEX_TARGET(flex ${FLEX_SRC} ${PROJECT_SOURCE_DIR}/src/parser/lexer.cc)
ADD_FLEX_BISON_DEPENDENCY(flex yacc)

add_custom_target(
    header
    COMMAND mv ${PROJECT_SOURCE_DIR}/src/parser/parser.hh ${PROJECT_SOURCE_DIR}/include/parser
    DEPENDS ${PROJECT_SOURCE_DIR}/src/parser/parser.cc ${PROJECT_SOURCE_DIR}/src/parser/lexer.cc
)

# Add all files.
file(GLOB_RECURSE COMPILER_SRC RELATIVE ${PROJECT_SOURCE_DIR} 
    "src/parser/*.cc"
    "src/runtime/*.cc"
    "src/*.cc"
)

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader)

add_executable(${PROJECT_NAME} ${COMPILER_SRC})
target_include_directories(${PROJECT_NAME} PRIVATE include)
# Link against LLVM libraries
target_link_libraries(${PROJECT_NAME} ${llvm_libs} ${CLANG_LIBS})
add_dependencies(${PROJECT_NAME} header)