/* Common precompiled header */

#pragma once

#include "Platforms/common.h"

// Common Includes (libc)
#include <cassert>
#include <cerrno>
#include <cctype>
#include <fcntl.h>
#include <io.h>
#include <climits>
#include <cmath>
#include <process.h>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>

#ifndef _WIN32
#	include <sys/mman.h>
#	include <unistd.h>
#endif

// Common Includes (libstdc++)
#include <algorithm>
#include <complex>
#include <fstream>
#include <iostream>
#include <list>
#include <unordered_map>
#include <map>
#include <queue>
#include <unordered_set>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

// POSIX Common
#include <sys/stat.h>
#include <sys/types.h>

// The code uses these without a namespace everywhere.
using std::min, std::max;
