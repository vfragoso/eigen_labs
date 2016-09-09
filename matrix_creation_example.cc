// Copyright (C) 2016 West Virginia University.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above
//       copyright notice, this list of conditions and the following
//       disclaimer in the documentation and/or other materials provided
//       with the distribution.
//
//     * Neither the name of West Virginia University nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// Please contact the author of this library if you have any questions.
// Author: Victor Fragoso (victor.fragoso@mail.wvu.edu)

// This binary illustrates how to create matrices and vectors using Eigen.

#include <iostream>  // Header for printing to stdout.
#include <Eigen/Core>  // Header for including the Eigen library.

// Eigen is a very nice C++-header-only library! This means that there is no
// compiled libraries that we have to link. Instead, our binary will include
// the classes that we use and only those will be compiled and included in the
// final binary.
//
// Eigen is a templated library. This means that many of their classes require
// a type to be specifed. In a way, the library wraps a memory buffer of some
// numerical type and treats it like a Matrix or Vector.
//
// See https://eigen.tuxfamily.org/ for more information about Eigen library.
int main(int argc, char** argv) {
  // Let us start with the simple and most useful objects we will use in our
  // class. These are 3D-vectors, 4D-vectors, 3x3 and 4x4 matrices.
  // Declaration of a 3D vector with floating point numbers and allocated in the
  // stack:
  Eigen::Vector3f my_3d_vector;
  std::cout << "Vector size: " << my_3d_vector.size() << "\n";
  // Same declaration but using double precision numbers.
  Eigen::Vector3d my_3d_vectord;
  std::cout << "Vector size: " << my_3d_vectord.size() << "\n";
  // Declaration of a 4D vector with floating point numbers and allocated in the
  // stack:
  Eigen::Vector4f my_4d_vector;
  std::cout << "Vector size: " << my_4d_vector.size() << "\n";
  // Same declaration but using double precision numbers.
  Eigen::Vector4d my_4d_vectordd;
  std::cout << "Vector size: " << my_3d_vectord.size() << "\n";
  // In this class we will use floating point numbers only. This is because most
  // of the OpenGL calls use floating point numbers.
  // To declare vectors that are allocated in the heap, we need to use a
  // different declaration statement:
  // The constructor expects the dimensionality parameter.
  Eigen::VectorXf my_3d_heap_vector_1(3);
  // We can set the vector to random elements.
  my_3d_heap_vector_1.setRandom();
  std::cout << "Vector (transpose): " << my_3d_heap_vector_1.transpose()
            << "\n";
  // To create a matrix of any size in the heap, we create it as follows.
  // The constructor expects two parameters, number of rows and columns.
  // Note here that the patter is that when we specify X at the end of
  // the class name (e.g., Matrix or Vector) we tell Eigen to allocate in the
  // heap.
  Eigen::MatrixXf my_matrix(3, 3);
  // We can set the matrix to zero.
  my_matrix.setZero();
  // And we can access each element of the matrix by using the the () operators.
  // First argument is the row and the second is the column.
  my_matrix(0, 0) = 1.0;
  my_matrix(1, 1) = 1.0;
  my_matrix(2, 2) = 1.0;
  std::cout << "Matrix: \n" << my_matrix << std::endl;
  // Eigen provides ways to create 3x3 and 4x4 quickly in the stack.
  Eigen::Matrix3f my_3x3;
  my_3x3.setRandom();
  std::cout << "Matrix: \n" << my_3x3 << std::endl;
  Eigen::Matrix4f my_4x4;
  my_4x4.setIdentity();
  std::cout << "Matrix: \n" << my_4x4 << std::endl;
  // To request dimensions from the matrix, we can call the rows() or cols()
  // method.
  std::cout << "Rows: " << my_4x4.rows() << std::endl;
  std::cout << "Cols: " << my_4x4.cols() << std::endl;
  // It turns out that vectors are special cases of matrices in Eigen. Thus,
  // we can use the () to access the entries.
  std::cout << "Vector (transpose): " << my_3d_heap_vector_1(0) << " "
            << my_3d_heap_vector_1(1) << " "
            << my_3d_heap_vector_1(2) << "\n";
  // In particular, the 3D and 4D vectors understand that they can be used as
  // points and we can access their coordinates by calling x(), y(), z(), and
  // w() members.
  std::cout << "Vector (transpose): " << my_3d_heap_vector_1.x() << " "
            << my_3d_heap_vector_1.y() << " "
            << my_3d_heap_vector_1.z() << "\n";
  // Let's set our 4d vector to random.
  my_4d_vectordd.setRandom();
  std::cout << "Vector (transpose): " << my_4d_vectordd.x() << " "
            << my_4d_vectordd.y() << " "
            << my_4d_vectordd.z() << " "
            << my_4d_vectordd.w() << "\n";
  return 0;
}
