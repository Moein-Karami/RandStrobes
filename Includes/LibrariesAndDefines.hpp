#ifndef _LibrariesAndDefines_hpp_
#define _LibrariesAndDefines_hpp_

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#include <chrono>
#include <functional>

#define DEFAULT_SEED 0

const uint64_t DEFAULT_P = 100001;
const uint64_t DEFAULT_Q = pow (2, 16) - 1;
const uint64_t DEFAULT_MASK = -1;
const uint32_t DEFAULT_N = 2;
const uint64_t TYPE_NORMAL = 1;

typedef struct { uint64_t high; uint64_t low; } Int128;

#endif