/* flash_clear_transfer_buffer  (FUN_CODE_dd96)
 *
 * Fill the 2 KB flash transfer buffer with 0xFF.
 * Name basis: derived - buffer 0xA800..0xAFFF used by flash_read_to_buffer / flash_write_from_buffer; 0xFF =
 *   erased flash
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dd96 @ 0xdd96
 * Options: OPTIMIZE(8,SPEED).
 * Source form: the 16-bit index loop gives MOV R6,#08H / MOV R7,#00H / MOV DPTR,#0xA800 / MOV A,#0FFH / MOVX / INC DPTR /
 * DJNZ R7 / DJNZ R6, as in the firmware; countdown, do-while and pointer forms give 28..33 bytes.
 */
#define FLASH_BUFFER_BYTES 0x800   /* 2 KB, XDATA 0xA800..0xAFFF */

extern unsigned char xdata flash_data_buffer[];

/* Fill the flash data buffer with 0xFF. Only caller: sys_main. */
void flash_clear_transfer_buffer(void)
{
    unsigned int index;
    for (index = 0; index < FLASH_BUFFER_BYTES; index++) flash_data_buffer[index] = 0xff;
}
