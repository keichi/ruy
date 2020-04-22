/* Copyright 2019 Google LLC. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef RUY_RUY_CONTEXT_INTERNAL_H_
#define RUY_RUY_CONTEXT_INTERNAL_H_

#include "ruy/context.h"

namespace ruy {

class ContextInternal {
 public:
  static void SetRuntimeEnabledPaths(Context* context, Path paths);
  static Path GetRuntimeEnabledPaths(Context* context);
  static const std::vector<std::unique_ptr<PerThreadState>>& GetPerThreadStates(
      Context* context, int thread_count);
  static Allocator* GetMainAllocator(Context* context);
  static PrepackedCache* GetPrepackedCache(Context* context);
  static Tuning GetMainThreadTuning(Context* context);

  template <Path CompiledPaths>
  static Path GetPathToTake(Context* context) {
    context->last_taken_path_ =
        GetMostSignificantPath(CompiledPaths & GetRuntimeEnabledPaths(context));
    return context->last_taken_path_;
  }
};

}  // end namespace ruy

#endif  // RUY_RUY_CONTEXT_INTERNAL_H_
