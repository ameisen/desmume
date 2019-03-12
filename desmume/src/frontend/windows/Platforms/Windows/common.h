#pragma once

// Make sure we are performing the include of the Windows headers to be as clean as possible.
#undef NOMINMAX
#define NOMINMAX 1
#undef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#undef VC_EXTRALEAN
#define VC_EXTRALEAN 1

#include <Windows.h>
#include <commdlg.h>
#include <Shellapi.h>
#include <shlwapi.h>
#include <CommCtrl.h>
#include <tchar.h>
#include <ShlObj.h>
#include <windowsx.h>
#include <windef.h>
#include <mmsystem.h>
#include <direct.h>

namespace Platform {
	template <typename T = char> using win_cstring = T *;
}

// This is strictly undefined behavior, but is required to use the Win32 API correctly.
// TODO : Consider supporting WinRT API, which doesn't have these issues.
static constexpr inline auto operator "" _winstring(const char* str, size_t) {
	return Platform::win_cstring<char>(str);
}
static constexpr inline auto operator "" _winstring(const wchar_t* str, size_t) {
	return Platform::win_cstring<wchar_t>(str);
}

