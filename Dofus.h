#ifndef DOFUS_H
#define DOFUS_H

#pragma region Build 2.11.0.71682.1
char version[] = "2.11";

char baOutPosition[] = "\x62\x05\x24\x00\x62\x0a";
char baInPosition[]  = "\x62\x04\x24\x00\x62\x0a";
int PositionLen = 6;

char baOutReadByte[] = "\x63\x08\x62\x05\x46\x0c\x00";
char baInReadByte[] = "\x63\x08\x62\x04\x46\x0c\x00";
int ReadByteLen = 7;

char baOutBytesAvailable[] = "\x63\x05\x62\x05\x10\x05\x00\x00";
char baInBytesAvailable[] = "\x63\x05\x62\x04\x10\x05\x00\x00";
int BytesAvailableLen = 8;
#pragma endregion

#endif //DOFUS_H