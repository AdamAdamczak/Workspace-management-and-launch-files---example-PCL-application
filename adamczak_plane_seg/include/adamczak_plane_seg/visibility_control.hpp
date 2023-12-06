// Copyright 2023 AdamA
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

#ifndef ADAMCZAK_PLANE_SEG__VISIBILITY_CONTROL_HPP_
#define ADAMCZAK_PLANE_SEG__VISIBILITY_CONTROL_HPP_

////////////////////////////////////////////////////////////////////////////////
#if defined(__WIN32)
  #if defined(ADAMCZAK_PLANE_SEG_BUILDING_DLL) || defined(ADAMCZAK_PLANE_SEG_EXPORTS)
    #define ADAMCZAK_PLANE_SEG_PUBLIC __declspec(dllexport)
    #define ADAMCZAK_PLANE_SEG_LOCAL
  #else  // defined(ADAMCZAK_PLANE_SEG_BUILDING_DLL) || defined(ADAMCZAK_PLANE_SEG_EXPORTS)
    #define ADAMCZAK_PLANE_SEG_PUBLIC __declspec(dllimport)
    #define ADAMCZAK_PLANE_SEG_LOCAL
  #endif  // defined(ADAMCZAK_PLANE_SEG_BUILDING_DLL) || defined(ADAMCZAK_PLANE_SEG_EXPORTS)
#elif defined(__linux__)
  #define ADAMCZAK_PLANE_SEG_PUBLIC __attribute__((visibility("default")))
  #define ADAMCZAK_PLANE_SEG_LOCAL __attribute__((visibility("hidden")))
#elif defined(__APPLE__)
  #define ADAMCZAK_PLANE_SEG_PUBLIC __attribute__((visibility("default")))
  #define ADAMCZAK_PLANE_SEG_LOCAL __attribute__((visibility("hidden")))
#else
  #error "Unsupported Build Configuration"
#endif

#endif  // ADAMCZAK_PLANE_SEG__VISIBILITY_CONTROL_HPP_
