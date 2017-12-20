#pragma once

#include <windows.h>
#include <unordered_map>

namespace ArkApi
{
	class Offsets
	{
	public:
		static Offsets& Get();

		Offsets(const Offsets&) = delete;
		Offsets(Offsets&&) = delete;
		Offsets& operator=(const Offsets&) = delete;
		Offsets& operator=(Offsets&&) = delete;

		void Init(std::unordered_map<std::string, intptr_t>&& offsets_dump);

		DWORD64 GetAddress(const void* base, const std::string& structure, const std::string& offset);
		LPVOID GetAddress(const std::string& structure, const std::string& offset);
	private:
		Offsets();

		DWORD64 module_base_;
		std::unordered_map<std::string, intptr_t> offsets_dump_;
	};
}
