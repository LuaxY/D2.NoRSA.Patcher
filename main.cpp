#include <windows.h>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstring>

#include "Dofus.h"
#include "Pattern.h"

using namespace std;

int main()
{
	SetConsoleTitle(TEXT("D2 NoRSA Patcher"));

	int pid;

	cout << "Entrez le PID de Dofus.exe: ";
	cin >> pid;

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

    if(!hProcess)
    {
        cout << "Impossible d'ouvrir le processus Id: " << pid << "." << endl;
        return 1;
    }

	ostringstream title;
	title << "D2 NoRSA Patcher - Dofus.exe [" << pid << "]";
	SetConsoleTitle(title.str().c_str());

    Pattern *scan = new Pattern(hProcess, 0x00000000, 128);

    clock_t tStart = clock();
    SIZE_T bytesWrited;

    unsigned int PositionOffset = scan->GetOffset(baOutPosition, PositionLen);
    unsigned int ReadByteOffset = scan->GetOffset(baOutReadByte, ReadByteLen);
    unsigned int BytesAvailableOffset = scan->GetOffset(baOutBytesAvailable, BytesAvailableLen);

    cout << "Time scanning: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << "s" << endl << endl;

    cout << "baOutPosition: " << hex << PositionOffset << endl;
    cout << "baOutReadByte: " << hex << ReadByteOffset << endl;
    cout << "baOutBytesAvailable: " << hex << BytesAvailableOffset << endl;

    WriteProcessMemory(hProcess, (LPVOID)PositionOffset, baInPosition, PositionLen, &bytesWrited);
    WriteProcessMemory(hProcess, (LPVOID)ReadByteOffset, baInReadByte, ReadByteLen, &bytesWrited);
    WriteProcessMemory(hProcess, (LPVOID)BytesAvailableOffset, baInBytesAvailable, BytesAvailableLen, &bytesWrited);

    cout << endl << "Dofus " << version << " successfully patched" << endl;

    CloseHandle(hProcess);
    delete scan;

    return 0;
}