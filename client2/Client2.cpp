

#include <windows.h>
#include <iostream>
#include <tchar.h>


int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE hslot;

	const wchar_t* slotname = TEXT("\\\\.\\mailslot\\demoslot");
	hslot = CreateFile(slotname, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);


	if (hslot == INVALID_HANDLE_VALUE)
	{

		std::cout << "SLOT WRITING FAILED" << std::endl;
		std::cout << "PRESS KEY TO FINICH" << std::endl;
		std::cin.get();
		return 0;

	}

	std::cout << "SLOT IS WAITING" << std::endl;
	int nData;
	int n = 10;
	wchar_t m[] = L"51\0";
	DWORD dwBytesWrite;

	if (!WriteFile(hslot, &m, 3 * sizeof(wchar_t), &dwBytesWrite, NULL))
	{
		std::cout << "WRITE FAILED" << std::endl;
		CloseHandle(hslot);
		std::cout << "PRESS KEY TO FINICH" << std::endl;
		std::cin.get();
		return 0;
	}

	std::wcout << "Data WRITTEN TO BOX: " << m << std::endl;



	std::cout << "PRESS KEY TO FINICH" << std::endl;
	CloseHandle(hslot);
	std::cin.get();
	return 0;


	return 0;
}