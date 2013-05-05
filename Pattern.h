#ifndef PATTERN_H
#define PATTERN_H

#include <windows.h>
#include <iostream>
#include <cstring>

using namespace std;

class Pattern
{
public:
    Pattern(HANDLE _hProcess, unsigned int _startOffset, unsigned int _step);
    int GetOffset(char *mask, int len);
private:
    int BytesCompare(char *bufferBytes, char *mask, int searchLen);

    HANDLE hProcess;
    unsigned int offset;
    unsigned int step;
};

#endif //PATTERN_H
