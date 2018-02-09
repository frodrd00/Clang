cmake_minimum_required(VERSION 3.4.3)
project(libToolingASTMatchers)

# LLVM dependency
find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Project compile flags
set(CMAKE_CXX_FLAGS "-std=c++11 -fno-rtti")

# Project output
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Build the tool
add_executable(borrardor borrador.cpp)

# Set the clang libraries that we wish to use
set(clang_libs "clangTooling" "clangFrontend" "clangFrontendTool" "clangDriver"
               "clangSerialization" "clangParse" "clangSema"
               "clangStaticAnalyzerCheckers" "clangStaticAnalyzerCore"
               "clangAnalysis" "clangRewriteFrontend" "clangEdit"
               "clangASTMatchers" "clangAST" "clangLex" "clangBasic" "clang")

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs irreader core support libdriver
                                          codegen)

# Link against clang and LLVM
target_link_libraries(borrador ${clang_libs} ${llvm_libs})
