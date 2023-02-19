#pragma once
#include "il2cpp.h"

#define DO_APP_FUNC(r, n, p) static r (*n) p
namespace app {
#include "il2cpp-functions.h"
}
#undef DO_APP_FUNC

