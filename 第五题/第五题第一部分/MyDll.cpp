#include <windows.h>

BOOL WINAPI DllMain(HINSTANCE hinstDll, DWORD dwReason, LPVOID lpvRevered)
{
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		MessageBoxA(NULL, "Hello!", "Hello!", NULL);
		break;
	}
	return TRUE;
}

//DllMain是在Windows系统里注册的一个回调函数（call back）
//DllMain是Dll的缺省入口函数，DLLMain负责Dll装载时的初始化及卸载的收尾工作，每当一个新的进程或者该进程的新的线程访问 DLL或访问DLL的每一个进程或线程不再使用DLL时，都会调用DLLMain。
//DLL_PROCESS_ATTACH:每个进程第一次调用DLL文件被映射到进程的地址空间时，传递的fdwReason参数为DLL_PROCESS_ATTACH。这进程再次调用操作系统只会增加DLL的使用次数。 


