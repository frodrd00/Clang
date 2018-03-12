cmake_minimum_required(VERSION 2.8)
project(LoopConvert)

# LLVM dependency
find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Source classes
#set(CLASSES_TO_COMPILE LoopConvert.cpp)

# Source main
set(MAIN_TO_COMPILE LoopConvert.cpp)

# Project compile
set(CMAKE_CXX_FLAGS "-std=c++11 -fno-rtti")
set(CMAKE_CXX_COMPILER "/usr/local/bin/clang++")

# Project output
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Build the tool
#add_executable(main ${CLASSES_TO_COMPILE} ${MAIN_TO_COMPILE})
add_executable(main ${MAIN_TO_COMPILE})

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
target_link_libraries(main ${clang_libs} ${llvm_libs})