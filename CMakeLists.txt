cmake_minimum_required(VERSION 3.15)
project(binary-demo CXX)

# Set project name from SKBUILD_PROJECT_NAME if available (for Python packaging)
if(DEFINED SKBUILD_PROJECT_NAME)
    set(PYTHON_PROJECT_NAME ${SKBUILD_PROJECT_NAME})
endif()

# C++ library configuration - use static by default
# Use BUILD_SHARED_LIBS from Conan to determine library type if defined
if(DEFINED BUILD_SHARED_LIBS AND BUILD_SHARED_LIBS)
    add_library(binary-demo src/binary-demo.cpp)
else()
    add_library(binary-demo STATIC src/binary-demo.cpp)
endif()

# Include directories
target_include_directories(binary-demo PUBLIC include)

# Set public headers
set_target_properties(binary-demo PROPERTIES PUBLIC_HEADER "include/binary-demo.h")

# Python extension configuration (when building as Python package)
if(DEFINED SKBUILD_PROJECT_NAME)
    set(PYBIND11_FINDPYTHON ON)
    find_package(pybind11 CONFIG REQUIRED)
    
    # Include both source files directly in the module
    pybind11_add_module(_core MODULE src/main.cpp src/binary-demo.cpp)
    
    # Add include directories to the Python module
    target_include_directories(_core PRIVATE include)
    
    # Install Python module
    install(TARGETS _core DESTINATION ${SKBUILD_PROJECT_NAME})
endif()

# Install the library
install(TARGETS binary-demo)
