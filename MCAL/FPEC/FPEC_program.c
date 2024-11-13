/*
 * FPEC_program.c
 *
 *  Created on: Nov 12, 2024
 *      Author: chelly
 */


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "FPEC_intrface.h"
#include "FPEC_private.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
static void FLASH_UNLOCK(void);
static void FLASH_LOCK(void);
static void WAIT_FOR_BSY(void);
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
static void FLASH_UNLOCK(void){
	FPEC->KEYR = FLASH_KEY1;
	FPEC->KEYR = FLASH_KEY2;
}
static void FLASH_LOCK(void){
	SET_BIT(FPEC->CR,FLASH_LOCK_BIT_POS);
}
static void WAIT_FOR_BSY(void){
	while(GET_BIT(FPEC->SR,FLASH_BSY_FLAG_BIT_POS) == 1);
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void FPEC_Write(u32 Copy_u32Address, u32* copy_u32Data, u32 Copy_u32DataLength){

	u32 local_conter = 0;
	FLASH_UNLOCK();

	for (local_conter = 0; local_conter < Copy_u32DataLength; ++local_conter) {
		WAIT_FOR_BSY();
		SET_BIT(FPEC->CR, FLASH_PROGRAMMING_ACTIVE_BIT_POS);
		*((volatile u8*)Copy_u32Address) = copy_u32Data[local_conter];
		WAIT_FOR_BSY();
		CLR_BIT(FPEC->CR,FLASH_PROGRAMMING_ACTIVE_BIT_POS);
		Copy_u32Address++;
	}



	FLASH_LOCK();

}
void FPEC_EraseSectors(u8 Copy_u8SectorNumber, u8 Copy_u8NbOfSectors){

	u32 local_conter = 0;
	FLASH_UNLOCK();

	for (local_conter = 0; local_conter < Copy_u8NbOfSectors; ++local_conter) {
		WAIT_FOR_BSY();
		SET_BIT(FPEC->CR, SECTOR_ERASE_ACTIVE_BIT_POS);
		MODIFY_REG(FPEC->CR,0xF<<3,Copy_u8SectorNumber<<3);
		SET_BIT(FPEC->CR,FLASH_ERASE_START_BIT_POS);
		WAIT_FOR_BSY();
		Copy_u8SectorNumber++;
		CLR_BIT(FPEC->CR,SECTOR_ERASE_ACTIVE_BIT_POS);

	}


	FLASH_UNLOCK();
}

int FPEC_Get_ReadProtectionLevel(void){
return ((FPEC->OPTCR >> 8)&0xFF);
}



/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/

