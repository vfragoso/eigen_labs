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

#include <iostream>
#include <Eigen/Core>  // For standard vector and matrices.
#include <Eigen/Geometry>  // For cross products.

// This example illustrates how to compute matrix-matrix, matrix-vector, and
// vector-vector operations. For a quick review of more operations using Eigen
// see https://eigen.tuxfamily.org/dox/group__TutorialMatrixArithmetic.html.
int main(int argc, char** argv) {
  // Let's start with vector-vector operations.
  // Dot products.
  Eigen::Vector3f vector1;
  Eigen::Vector3f vector2;
  vector1.setRandom();
  vector2.setRandom();
  std::cout << "vector1 (transpose): " << vector1.transpose() << "\n";
  std::cout << "vector2 (transpose): " << vector2.transpose() << "\n";
  std::cout << "Dot product: " << vector1.dot(vector2) << "\n";
  // Computing norms.
  std::cout << "vector1 (norm): " << vector1.norm() << "\n";
  std::cout << "vector2 (norm): " << vector2.norm() << "\n";
  // Transforming vectors into unit vectors.
  Eigen::Vector3f normalized_vector1 = vector1.normalized();
  // Unit vector in place.
  vector1.normalize();
  // Eigen overloads several operators (e.g., +, -, and *). These overlads
  // allow us to call several operations very naturally.
  // For instance, the addition of vectors:
  const Eigen::Vector3f added_vectors = vector1 + vector2;
  std::cout << "Added vectors (transpose): "
            << added_vectors.transpose() << "\n";
  // Scaling a vector.
  const float scalar = 5.0f;
  const Eigen::Vector3f scaled_vector = scalar * vector1;
  std::cout << "Original vector (norm): " << vector1.norm() << "\n";
  std::cout << "Scaled Vector (norm): " << scaled_vector.norm() << "\n";
  // Cross product.
  const Eigen::Vector3f cross_product = vector1.cross(vector2);
  std::cout << "Cross product: " << cross_product.transpose() << "\n";
  // Let's review matrix-vector operations.
  const Eigen::Matrix3f random_matrix = Eigen::Matrix3f::Random();
  std::cout << "Matrix-vector multiplication: \n"
            << random_matrix * scaled_vector << std::endl;

  // Let's review matrix-matrix operations.
  // Addition.
  const Eigen::Matrix3f identity = Eigen::Matrix3f::Identity();
  std::cout << "Addition: \n" << identity + random_matrix << "\n";
  // Multiplication.
  const Eigen::Matrix3f result = identity * random_matrix;
  std::cout << "Multiplication: \n" << result << "\n";
  // Eigen is very efficient when several operations occur in a statement.
  // It automatically finds a way internally to make the operations as efficient
  // as possible.
  const Eigen::Vector3f result2 =
      (scalar * identity * random_matrix * scaled_vector) + added_vectors;
  std::cout << "Efficient evalution of operations: "
            << result2.transpose() << "\n";
  return 0;
}
