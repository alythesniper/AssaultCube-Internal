#pragma once
#include <windows.h>
#include <vector>

namespace mem {
	bool patchBytes(void* source, void* destination, int size);

	bool nopBytes(void* location, int size);

	uintptr_t derefPtrChain(uintptr_t modBaseAdd, std::vector<int> offsets);

	uintptr_t trampHook(uintptr_t targetAddress, uintptr_t hookFuncAddress, int size);
};