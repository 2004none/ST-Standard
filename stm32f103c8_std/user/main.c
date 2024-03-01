#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "SISP.h"
#include "W25Q64.h"
#include "OLED.h"

uint8_t MID;
uint16_t DID;

uint8_t ArrayWrite[] = {0x01, 0x02, 0x03, 0x04};
uint8_t ArrayRead[4];

int main()
{
    LED_Init();
    OLED_Init();
    W25Q64_Init();
    OLED_SetFontSize(SMALL);

    OLED_ShowString(0,0,"MID:   DID:  ");
    OLED_ShowString(1,0,"W:");
    OLED_ShowString(2,0,"R:");

    W25Q64_ReadID(&MID,&DID);
    OLED_ShowHexNum(0,4,MID,2);
    OLED_ShowHexNum(0,11,DID,4);

    W25Q64_SectorErase(0x000000);
    W25Q64_PageProgram(0x000000,ArrayWrite,4);
    W25Q64_ReadData(0x000000,ArrayRead,4);

    OLED_ShowHexNum(2, 3, ArrayWrite[0], 2);
	OLED_ShowHexNum(2, 6, ArrayWrite[1], 2);
	OLED_ShowHexNum(2, 9, ArrayWrite[2], 2);
	OLED_ShowHexNum(2, 12, ArrayWrite[3], 2);
	
	OLED_ShowHexNum(3, 3, ArrayRead[0], 2);
	OLED_ShowHexNum(3, 6, ArrayRead[1], 2);
	OLED_ShowHexNum(3, 9, ArrayRead[2], 2);
	OLED_ShowHexNum(3, 12, ArrayRead[3], 2);
    while(1){
        
    }
}
