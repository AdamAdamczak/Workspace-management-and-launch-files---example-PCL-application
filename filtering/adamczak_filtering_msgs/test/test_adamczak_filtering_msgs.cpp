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

#include "gtest/gtest.h"
#include "adamczak_filtering_msgs/adamczak_filtering_msgs.hpp"

TEST(TestAdamczakFilteringMsgs, TestHello) {
  std::unique_ptr<adamczak_filtering_msgs::AdamczakFilteringMsgs> adamczak_filtering_msgs_ =
    std::make_unique<adamczak_filtering_msgs::AdamczakFilteringMsgs>();
  auto result = adamczak_filtering_msgs_->foo(999);
  EXPECT_EQ(result, 999);
}
