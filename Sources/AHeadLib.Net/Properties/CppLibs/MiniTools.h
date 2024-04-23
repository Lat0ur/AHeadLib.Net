#pragma once

#include <windows.h>
#include <Psapi.h>

#ifdef  __cplusplus

#ifndef G_BEGIN_DECLS
# define G_BEGIN_DECLS  extern "C" {
#endif

#ifndef G_END_DECLS
# define G_END_DECLS    }
#endif

#else

#ifndef G_BEGIN_DECLS
# define G_BEGIN_DECLS
#endif

#ifndef G_END_DECLS
# define G_END_DECLS
#endif

#endif


G_BEGIN_DECLS
bool ReplaceMemory(void* dest, const void* source, int length);
bool FindModuleSection(HMODULE module, const char* segmentName, void** outSectionStart, LONGLONG* outSize);
void* SearchInSection(HMODULE module, const char* segmentName, const void* signature, int length);
void* SearchInMemory(const void* startPos, const void* endPos, const void* signature, int length);
bool PatchMemory(HMODULE module, const char* segmentName, const void* signature, const void* newBytes, int length);
bool PatchMultipleMemories(HMODULE module, const char* segmentName, const void** signaturePtr, const void** newBytesPtr, int* lengthPtr, int count);
G_END_DECLS