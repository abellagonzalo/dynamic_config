/*
 *  Software License Agreement (BSD License)
 *
 *  Copyright (c) 2013, Open Source Robotics Foundation, Inc.
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
 *   * Neither the name of Open Source Robotics Foundation, Inc. nor
 *     the names of its contributors may be used to endorse or promote
 *     products derived from this software without specific prior
 *     written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef DYNAMIC_CONFIG_CONFIGURATION_LISTENER_H
#define DYNAMIC_CONFIG_CONFIGURATION_LISTENER_H

#include <ros/ros.h>

#include "dynamic_config/Conf.h"
#include "gsoc/configuration/configuration.h"
#include "gsoc/configuration/msg_handler.h"

namespace gsoc {

  namespace configuration {

    class ConfigurationListener {
    public:

      typedef boost::function<void (Configuration&)> Callback;

      ConfigurationListener(ros::NodeHandle& n, Callback cb);

      ConfigurationListener(const ConfigurationListener& other);

      ConfigurationListener& operator=(const ConfigurationListener& rhs);

      bool operator==(const ConfigurationListener& rhs) const;

      bool operator!=(const ConfigurationListener& rhs) const;

      bool operator<(const ConfigurationListener& rhs) const;

      operator void*() const;

      void shutdown();

    private:

      void callback(const dynamic_config::Conf& msg);

      struct Impl {
        ros::Subscriber subscriber_;
        Callback cb_;
      };
      typedef boost::shared_ptr<Impl> ImplPtr;
      ImplPtr impl_;

    };

  } // configuration

} // gsoc

#endif