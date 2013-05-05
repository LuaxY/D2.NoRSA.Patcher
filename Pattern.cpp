#include "Pattern.h"

Pattern::Pattern(HANDLE _hProcess, unsigned int _startOffset, unsigned int _step): hProcess(_hProcess), offset(_startOffset), step(_step)
{
}

int Pattern::GetOffset(char *mask, int len)
{
    int result = -1;
    char *buffer = new char[step];
    DWORD bytesReaded;

    while(offset != 0xFF000000)
    {
        ReadProcessMemory(hProcess, (LPCVOID)offset, buffer, step, &bytesReaded);
        result = BytesCompare(buffer, mask, len);

        if(result == 0)
            break;
        else if(result > 0)
            offset += result;
        else
            offset += step;

        //cout << hex << offset << endl;
    }

    delete[] buffer;
    return offset;
}

int Pattern::BytesCompare(char *bufferBytes, char *mask, int len)
{
    if(sizeof(bufferBytes) != sizeof(mask))
        return -1;

    if(bufferBytes[0] == mask[0])
    {
        if(memcmp(bufferBytes, mask, len) == 0)
            return 0;
    }

    for(unsigned int i = 1; i < step; i++)
    {
        if(bufferBytes[i] == mask[0])
            return i;
    }

    return -1;
}
