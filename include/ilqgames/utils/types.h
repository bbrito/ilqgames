/*
 * Copyright (c) 2019, The Regents of the University of California (Regents).
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *    1. Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *    2. Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *
 *    3. Neither the name of the copyright holder nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS AS IS
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Please contact the author(s) of this library if you have any questions.
 * Authors: David Fridovich-Keil   ( dfk@eecs.berkeley.edu )
 */

///////////////////////////////////////////////////////////////////////////////
//
// Custom types.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef ILQGAMES_UTILS_TYPES_H
#define ILQGAMES_UTILS_TYPES_H

// ------------------------------- INCLUDES -------------------------------- //

#include <math.h>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <algorithm>
#include <iostream>
#include <limits>
#include <memory>
#include <random>
#include <string>
#include <vector>

// ------------------------------- CONSTANTS -------------------------------- //

namespace ilqgames {
namespace constants {
// Acceleration due to gravity (m/s/s).
static constexpr float kGravity = 9.81;

// Small number for use in approximate equality checking.
static constexpr float kSmallNumber = 1e-4;

// Float precision infinity.
static constexpr float kInfinity = std::numeric_limits<float>::infinity();
}  // namespace constants

// --------------------------------- TYPES ---------------------------------- //

using PlayerIndex = unsigned short;
using Dimension = int;
using Time = float;
using Point2 = Eigen::Vector2f;

// Empty struct for setting unused/unimplemented template args.
struct Empty {};

// ---------------------------- SIMPLE FUNCTIONS ---------------------------- //

template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args &&... args) {
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

template <typename T> inline constexpr
T sgn(T x, std::false_type is_signed) {
  return T(0) < x;
}

template <typename T> inline constexpr
T sgn(T x, std::true_type is_signed) {
  return (T(0) < x) - (x < T(0));
}

template <typename T> inline constexpr
T sgn(T x) {
  return sgn(x, std::is_signed<T>());
}

}  // namespace ilqgames

// ------------------------ THIRD PARTY TYPEDEFS ---------------------------- //

using Eigen::MatrixXf;
using Eigen::VectorXf;

#endif
