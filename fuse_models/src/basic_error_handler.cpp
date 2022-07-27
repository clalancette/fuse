/*
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2022, Locus Robotics
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

#include <fuse_models/basic_error_handler.h>
#include <pluginlib/class_list_macros.h>

// Register this motion model with ROS as a plugin.
PLUGINLIB_EXPORT_CLASS(fuse_models::BasicErrorHandler, fuse_core::ErrorHandler)

namespace fuse_models 
{

  BasicErrorHandler::BasicErrorHandler() {};

  void BasicErrorHandler::initialize(const std::string& name) 
  {
    name_ = name;
  }

  void BasicErrorHandler::runtimeError(const std::string& info) 
  {
    throw std::runtime_error(info);
  }

  void BasicErrorHandler::invalidArgument(const std::string& info) 
  {
    throw std::invalid_argument(info);
  }

  void BasicErrorHandler::outOfRangeError(const std::string& info)
  {
    throw std::out_of_range(info);
  }

  void BasicErrorHandler::logicError(const std::string& info)
  {
    throw std::logic_error(info);
  }
}