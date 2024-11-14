/*
 * Bootloader.c
 *
 *  Created on: Nov 12, 2024
 *      Author: chelly
 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Bootloader.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
static u8 BL_HOST_RX_BUFFER [200];
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
static void Bootloader_Get_version(u8* BL_HOST_BUFFER);
static void Bootloader_Get_CID(u8* BL_HOST_BUFFER);
static void Bootloader_Get_RDB_Status(u8* BL_HOST_BUFFER);
static void Bootloader_APP_Erase(u8* BL_HOST_BUFFER);
static void Bootloader_Upload_APP(u8* BL_HOST_BUFFER);
static void Bootloader_Jump_To_APP(u8* BL_HOST_BUFFER);
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
static void Bootloader_Get_version(u8* BL_HOST_BUFFER){
	u8 BL_version[4]={ CBL_VENDOR_ID, CBL_SW_MAJOR_VERSION, CBL_SW_MINOR_VERSION, CBL_SW_PATCH_VERSION};
	Host_CMD_Packet_len=0;
	Host_CRC32=0;

}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void BL_UART_Fetch_Host_Command(void){

	memset(BL_HOST_RX_BUFFER,0,sizeof(BL_HOST_RX_BUFFER));

	UART_ReceiveByte(BL_HOST_COMMUNICATION_UART, &BL_HOST_RX_BUFFER[0], UART_MAX_DELAY);
	UART_voidReceive(BL_HOST_COMMUNICATION_UART, &BL_HOST_RX_BUFFER[1], BL_HOST_RX_BUFFER[0],UART_MAX_DELAY);

	switch(BL_HOST_RX_BUFFER[1]){

		case CBL_GET_VER:
			Bootloader_Get_version(BL_HOST_BUFFER);

			break;
		case CBL_GET_CID:
			Bootloader_Get_CID(BL_HOST_BUFFER);

			break;
		case CBL_GET_RDP_STATUS:
			Bootloader_Get_RDB_Status(BL_HOST_BUFFER);

			break;
		case CBL_APP_ERASE:
			Bootloader_APP_Erase(BL_HOST_BUFFER);

			break;
		case CBL_MEM_WRITE:
			Bootloader_Upload_APP(BL_HOST_BUFFER);

			break;
		case CBL_GO_TO_MAIN_APP:
			Bootloader_Jump_To_APP(BL_HOST_BUFFER);

			break;
		default:

			break;

	}
}


/**********************************************************************************************************************
 *  END OF FILE: ${file_name}
 *********************************************************************************************************************/

