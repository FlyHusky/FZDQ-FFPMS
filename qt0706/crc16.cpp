#include "crc16.h"


CRC16::CRC16()
{
}


WORD CRC16::Get_CRC16(BYTE* pchMsg, WORD wDataLen)
{
    BYTE chCRCHi = 0xFF; // 高CRC字节初始化
    BYTE chCRCLo = 0xFF; // 低CRC字节初始化
    WORD wIndex;            // CRC循环中的索引
    while (wDataLen--)
    {
        // 计算CRC
        wIndex = chCRCLo ^ *pchMsg++ ;
        chCRCLo = chCRCHi ^ chCRCHTalbe[wIndex];
        chCRCHi = chCRCLTalbe[wIndex] ;
    }
    *pchMsg=chCRCLo;
    *(++pchMsg)=chCRCHi;
    return ((chCRCHi << 8) | chCRCLo) ;
}

WORD CRC16::Check_CRC16(BYTE* pchMsg, WORD wDataLen)
{
    BYTE chCRCHi = 0xFF; // 高CRC字节初始化
    BYTE chCRCLo = 0xFF; // 低CRC字节初始化
    WORD wIndex;            // CRC循环中的索引
    while (wDataLen--)
    {
        // 计算CRC
        wIndex = chCRCLo ^ *pchMsg++ ;
        chCRCLo = chCRCHi ^ chCRCHTalbe[wIndex];
        chCRCHi = chCRCLTalbe[wIndex] ;
    }
    return ((chCRCHi << 8) | chCRCLo) ;
}
