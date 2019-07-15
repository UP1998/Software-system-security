#include <windows.h>


LONG IATHook(
	__in_opt void* pImageBase,
	__in_opt const char* pszImportDllName,
	__in const char* pszRoutineName,
	__in void* pFakeRoutine,
	__out HANDLE* phHook
);

LONG UnIATHook(__in HANDLE hHook);

void* GetIATHookOrign(__in HANDLE hHook);

typedef int(__stdcall* LPFN_MessageBoxA)(__in_opt HWND hWnd, __in_opt const char* lpText, __in_opt char* lpCaption, __in UINT uType);

HANDLE g_hHook_MessageBoxA = NULL;
//////////////////////////////////////////////////////////////////////////

int __stdcall Fake_MessageBoxA(__in_opt HWND hWnd, __in_opt char* lpText, __in_opt char* lpCaption, __in UINT uType)
{
	LPFN_MessageBoxA fnOrigin = (LPFN_MessageBoxA)GetIATHookOrign(g_hHook_MessageBoxA);

	return fnOrigin(hWnd, "hook", lpCaption, uType);
}

//入口函数
int __cdecl wmain(int nArgc, WCHAR** Argv)
{
	do
	{
		// UNREFERENCED_PARAMETER展开传递的参数或表达式。其目的是避免编译器关于未引用参数的警告
		UNREFERENCED_PARAMETER(nArgc);
		UNREFERENCED_PARAMETER(Argv);

		IATHook(
			//GetModuleHandle功能是获取一个应用程序或动态链接库的模块句柄
			GetModuleHandleW(NULL),
			"user32.dll",
			"MessageBoxA",
			Fake_MessageBoxA,
			&g_hHook_MessageBoxA
		);

		MessageBoxA(NULL, "test", "caption", 0);

		UnIATHook(g_hHook_MessageBoxA);

		MessageBoxA(NULL, "test", "caption", 0);

	} while (FALSE);

	return 0;
}