#include "il2cpp-Iint.hpp"

void Init_il2cpp()
{
	_set_se_translator(seh_excpetion::TranslateSEHtoCE);

	LOGDEBUG("[Il2cpp] Initializing \n");
	Mono = new Untiy3D::MonoCollector("GameAssembly.dll");
	LOGDEBUG("[Il2cpp] Initialization Complete \n");

	try
	{
#define DO_API(ret_type, name, args)\
		auto name##adress = Mono->il2cpp_GetMethodAddress(std::string(#name).substr(0,std::string(#name).find("_")),std::string(#name).substr(std::string(#name).find("_") + 1,std::string(#name).length()));\
		name = reinterpret_cast<name##_t>(name##adress);\
		LOGDEBUG(fmt::format("[Adress|{:#08x}] {} \n", (DWORD)name##adress, #name));

#include "il2cpp-functions.h"

#undef DO_API
	}
	catch (const seh_excpetion& error)
	{

	}
}