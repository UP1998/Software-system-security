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

//DllMain����Windowsϵͳ��ע���һ���ص�������call back��
//DllMain��Dll��ȱʡ��ں�����DLLMain����Dllװ��ʱ�ĳ�ʼ����ж�ص���β������ÿ��һ���µĽ��̻��߸ý��̵��µ��̷߳��� DLL�����DLL��ÿһ�����̻��̲߳���ʹ��DLLʱ���������DLLMain��
//DLL_PROCESS_ATTACH:ÿ�����̵�һ�ε���DLL�ļ���ӳ�䵽���̵ĵ�ַ�ռ�ʱ�����ݵ�fdwReason����ΪDLL_PROCESS_ATTACH��������ٴε��ò���ϵͳֻ������DLL��ʹ�ô����� 


