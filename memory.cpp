#include "memory.h"

bool mem::patchBytes(void* source, void* destination, int size)
{
	DWORD oldperms;
	VirtualProtect(destination, size, PAGE_EXECUTE_READWRITE, &oldperms);
	memcpy(destination, source, size);
	VirtualProtect(destination, size, oldperms, &oldperms);
	return true;

}

bool mem::nopBytes(void* location, int size)
{
	DWORD oldperms;
	VirtualProtect(&location, size, PAGE_EXECUTE_READWRITE, &oldperms);
	memset(location, 0x90, size);
	VirtualProtect(location, size, oldperms, &oldperms);
	return true;

}


uintptr_t mem::derefPtrChain(uintptr_t modBaseAdd, std::vector<int> offsets) {

	uintptr_t addr = modBaseAdd;

	for (auto offset : offsets) {
		addr = *(uintptr_t*)(addr += offset);
	}

	return addr;
}

uintptr_t mem::trampHook(uintptr_t targetAddress, uintptr_t hookFuncAddress, int size)
{
	if (size < 5) { return 0x0; }
	//setup trampoline
	uintptr_t trampolinePtr = (uintptr_t)VirtualAlloc((void*)targetAddress, size + 5, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	
	if(trampolinePtr == NULL)
	{
		return 0x0;
	}

	uintptr_t relativeJmp = (targetAddress + size) - (hookFuncAddress + size + 5);

	memcpy((void*)trampolinePtr, (void*)targetAddress, size);
	memcpy((void*)(trampolinePtr+size), "\xE9", 1);
	memcpy((void*)(trampolinePtr+size+1), &relativeJmp, 4);



	relativeJmp = hookFuncAddress - (targetAddress + 5);

	DWORD oldperms;
	VirtualProtect((void*)targetAddress, size, PAGE_EXECUTE_READWRITE, &oldperms);

	memcpy((void*)targetAddress, "\x90", size);
	memcpy((void*)targetAddress, "\xE9", 1);
	memcpy((void*)targetAddress, &hookFuncAddress, 4);

	VirtualProtect((void*)targetAddress, size, oldperms, &oldperms);
	return trampolinePtr;

}
