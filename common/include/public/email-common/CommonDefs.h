// @@@LICENSE
//
//      Copyright (c) 2010-2013 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// LICENSE@@@

#ifndef COMMONDEFS_H_
#define COMMONDEFS_H_

#include <boost/shared_ptr.hpp>
#include "core/MojCoreDefs.h"
#include "core/MojErr.h"
#include "core/MojRefCount.h"

// Functions that are used very infrequently
#if (__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3) // GCC 4.3 or higher only
#define __cold__ __attribute__ ((cold))
#else
#define __cold__
#endif

#if defined(__GNUC__)
#ifndef unlikely
#define unlikely(x) __builtin_expect((x),0)
#endif
#ifndef likely
#define likely(x) __builtin_expect((x),1)
#endif
#else
#ifndef unlikely
#define unlikely(x) x
#endif
#ifndef likely
#define likely(x) x
#endif
#endif

#endif /*COMMONDEFS_H_*/
