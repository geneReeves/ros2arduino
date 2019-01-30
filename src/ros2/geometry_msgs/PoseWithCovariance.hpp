// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*! 
 * @file PoseWithCovariance.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _GEOMETRY_MSGS_POSE_WITH_CONVARIANCE_HPP_
#define _GEOMETRY_MSGS_POSE_WITH_CONVARIANCE_HPP_


#include "../topic.hpp"


#include "../geometry_msgs/Pose.hpp"

namespace geometry_msgs {

class PoseWithCovariance : public ros2::Topic<PoseWithCovariance>
{
public:
  geometry_msgs::Pose pose;
  double covariance[36];

  PoseWithCovariance():
    Topic("geometry_msgs::msg::dds_::PoseWithCovariance_", "PoseWithCovariance"),
    pose()
  { 
    memset(covariance, 0, sizeof(covariance));
  }

  bool serialize(void* msg_buf, const PoseWithCovariance* topic)
  {
    ucdrBuffer* writer = (ucdrBuffer*)msg_buf;
    (void) pose.serialize(writer, &topic->pose);
    (void) ucdr_serialize_array_double(writer, topic->covariance, 36);

    return !writer->error;
  }

  bool deserialize(void* msg_buf, PoseWithCovariance* topic)
  {
    ucdrBuffer* reader = (ucdrBuffer*)msg_buf;
    (void) pose.deserialize(reader, &topic->pose);
    (void) ucdr_deserialize_array_double(reader, topic->covariance, 36);

    return !reader->error;
  }

  uint32_t size_of_topic(const PoseWithCovariance* topic, uint32_t size)
  {
    uint32_t previousSize = size;
    size += pose.size_of_topic(&topic->pose, size);
    size += ucdr_alignment(size, 8) + ((36) * 8);
    
    return size - previousSize;
  }



};

} // namespace geometry_msgs


#endif // _GEOMETRY_MSGS_POSE_WITH_CONVARIANCE_HPP_
