#include "il2cpp-Iint.hpp"

void Init_il2cpp()
{
	_set_se_translator(seh_excpetion::TranslateSEHtoCE);

	LOGDEBUG("[Il2cpp] Initializing \n");
	Il2cpp::initialize();
	LOGDEBUG("[Il2cpp] Initialization Complete \n");

	LOGDEBUG("[Il2cpp] Dumping Images\n");
	const auto Il2cpp = std::make_unique<Wrapper>();
	LOGDEBUG("[Il2cpp] Images Dumped\n");

	LOGDEBUG("[Il2cpp] Getting Assembly-CSharp Image\n");
	const auto image = Il2cpp->get_image("Assembly-CSharp.dll");
	LOGDEBUG(fmt::format("[Il2cpp] Assembly-CSharp -> {} ({:#08x})\n", image->get_name(), reinterpret_cast<uintptr_t>(image)));

	try
	{
#define DO_API(adress, ret_type, name, args)\
		Class* name##Class = image->get_class(std::string(#name).substr(0,std::string(#name).find("_")).c_str());\
		void* name##instance = (name##Class->get_method(std::string(#name).substr(std::string(#name).find("_") + 1,std::string(#name).length()).c_str()));\
		name = reinterpret_cast<name##_t>((*(DWORD*)name##instance));\
		LOGDEBUG(fmt::format("[Adress|{:#08x}] {} \n", (DWORD)name, #name));

#include "il2cpp-functions.h"

#undef DO_API
	}
	catch (const seh_excpetion& error)
	{

	}
}