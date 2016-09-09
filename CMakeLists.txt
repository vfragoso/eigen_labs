# Copyright (C) 2016 West Virginia University.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
#     * Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#
#     * Redistributions in binary form must reproduce the above
#       copyright notice, this list of conditions and the following
#       disclaimer in the documentation and/or other materials provided
#       with the distribution.
#
#     * Neither the name of West Virginia University nor the
#       names of its contributors may be used to endorse or promote products
#       derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# Please contact the author of this library if you have any questions.
# Author: Victor Fragoso (victor.fragoso@mail.wvu.edu)
CMAKE_MINIMUM_REQUIRED(VERSION 3.1.0)
CMAKE_POLICY(VERSION 3.1)

IF (COMMAND cmake_policy)
  CMAKE_POLICY(SET CMP0003 NEW)
ENDIF (COMMAND cmake_policy)

PROJECT(CS470_EIGEN_LABS C CXX)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})

# These lines below only work for Cmake 3.1 >.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Eigen.
FIND_PACKAGE(Eigen REQUIRED)
IF (EIGEN_FOUND)
  MESSAGE("-- Found Eigen version ${EIGEN_VERSION}: ${EIGEN_INCLUDE_DIRS}")
ENDIF (EIGEN_FOUND)

# Include directories so that the compiler knows where to find them.
INCLUDE_DIRECTORIES(${EIGEN_INCLUDE_DIRS})

# Simple matrix and vector creation using Eigen.
ADD_EXECUTABLE(matrix_creation_example matrix_creation_example.cc)

# Simple matrix and vector creation using Eigen.
ADD_EXECUTABLE(basic_matrix_operations_example basic_matrix_operations_example.cc)
