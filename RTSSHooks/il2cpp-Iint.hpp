#include "wrapper.hpp"
#include "SEH.hpp"
#include "pch.h"
#include "il2cpp.h"

#define DO_API(adress, ret_type,name,args)\
		using name##_t = ret_type(__cdecl*)args;\
	 	inline name##_t name;

#include "il2cpp-functions.h"

#undef DO_API

void Init_il2cpp();