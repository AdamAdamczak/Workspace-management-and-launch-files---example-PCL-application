// Copyright 2023 AAdamczak
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ADAMCZAK_FILTERING_MSGS__ADAMCZAK_FILTERING_MSGS_HPP_
#define ADAMCZAK_FILTERING_MSGS__ADAMCZAK_FILTERING_MSGS_HPP_

#include <cstdint>

#include "adamczak_filtering_msgs/visibility_control.hpp"


namespace adamczak_filtering_msgs
{

class ADAMCZAK_FILTERING_MSGS_PUBLIC AdamczakFilteringMsgs
{
public:
  AdamczakFilteringMsgs();
  int64_t foo(int64_t bar) const;
};

}  // namespace adamczak_filtering_msgs

#endif  // ADAMCZAK_FILTERING_MSGS__ADAMCZAK_FILTERING_MSGS_HPP_
