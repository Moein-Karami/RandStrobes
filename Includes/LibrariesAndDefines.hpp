#ifndef _LibrariesAndDefines_hpp_
#define _LibrariesAndDefines_hpp_

#include <bits/stdc++.h>
#include <chrono>
#include <functional>

#define DEFAULT_SEED 0

const uint64_t DEFAULT_P = 997;
const uint64_t DEFAULT_Q = pow (2, 16) - 1;
const uint64_t DEFAULT_MASK = -1;
const uint32_t DEFAULT_N = 2;
const uint64_t TYPE_NORMAL = 1;

typedef struct { uint64_t high; uint64_t low; } Int128;

#endif