/* ipc_store_flash_data  (FUN_CODE_a36c)
 *
 * Copy a block of flash data from the main processor into the 2 KB buffer.
 *   offset
 *   count
 *   src: data
 * Note: Its range message reuses the text 'KeyDetArray OOR'.
 * Name basis: proven - message type 7 (main side ipc_8051_send_storage_block); buffer 0xA800 used by flash
 *   jobs 0x11/0x15
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_a36c @ 0xa36c..0xa41f (179 bytes), OPTIMIZE(8,SPEED) LARGE.
 * LARGE parameters: offset 0xA4A9, count 0xA4AB, src 0xA4AD; local dest (generic pointer) at 0xA4B0; i stays in
 * R6:R7. Source form: '*dest++ = *src++' (both pointers advance with ?C?ILDIX, the byte moves with ?C?CLDPTR /
 * ?C?CSTPTR).
 */
extern unsigned char xdata flash_data_buffer[];
extern void lib_printf517(void *fmt, ...) large;

#define FLASH_DATA_BUFFER_BYTES  0x800  /* size of flash_data_buffer (XDATA 0xA800) */

/*
 * ipc_store_flash_data - copy one piece of flash data from the main processor (message type
 * IPC_8051_TX_MSG_FLASH_DATA 7) into flash_data_buffer at offset; the flash commands 0x11 and 0x15 program
 * from there.
 *   offset  position in the buffer
 *   count   number of bytes
 *   src     the bytes
 * A piece that runs past the 2 KB buffer prints "KeyDetArray OOR" (the same text as FillKeyDetectList) and is cut at
 * the end; one that starts past the end is dropped.
 * Only caller: ipc_run_message.
 */
void ipc_store_flash_data(unsigned int offset, unsigned int count, unsigned char *src)
{
    unsigned char *dest;
    unsigned int i;
    if (offset + count > FLASH_DATA_BUFFER_BYTES) {
        lib_printf517((void code *)0xc4bb);   /* "KeyDetArray OOR\r\n" */
        if (offset >= FLASH_DATA_BUFFER_BYTES) return;
        count = FLASH_DATA_BUFFER_BYTES - offset;
    }
    dest = &flash_data_buffer[offset];
    for (i = 0; i < count; i++) *dest++ = *src++;
}
