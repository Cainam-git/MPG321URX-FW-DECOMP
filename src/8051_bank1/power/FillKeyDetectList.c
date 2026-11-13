/* FillKeyDetectList  (FUN_CODE_9053)
 *
 * Store part of the standby key and wake-up table sent by the main processor.
 *   offset
 *   count
 *   piece: data
 * Name basis: proven - prints 'FillKeyDetectList (%04x)' (original name); message type 8 (main side
 *   ipc_8051_send_wake_key_table), 0xA5ED, 60 bytes
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_9053 @ 0x9053 (248 bytes, 0x9053..0x914B), OPTIMIZE(8,SPEED) LARGE.
 */
extern unsigned char xdata power_key_table[];
extern void lib_printf517(void *fmt, ...) large;

#define KEY_TABLE_BYTES  0x3c  /* size of power_key_table (60 bytes) */

/*
 * FillKeyDetectList - copy one piece of the standby key and wake-up table that the main processor sends
 * (message type IPC_8051_TX_MSG_WAKE_KEYS 8) into power_key_table, and print it.
 *   offset  where the piece starts in the table
 *   count   number of bytes
 *   piece   the bytes
 * A piece that runs past the end of the table prints "KeyDetArray OOR" and is cut at the end; one that starts
 * past the end is dropped.
 * Only caller: ipc_run_message, for message type 8.
 */
void FillKeyDetectList(unsigned int offset, unsigned char count, unsigned char *piece)
{
    unsigned char i;
    if (offset + count > KEY_TABLE_BYTES) {
        lib_printf517((void code *)0x989d);   /* "KeyDetArray OOR\r\n" */
        if (offset < KEY_TABLE_BYTES)
            count = KEY_TABLE_BYTES - offset;
        else
            return;
    }
    for (i = 0; i < count; i++) power_key_table[offset + i] = piece[i];
    lib_printf517((void code *)0x98af, offset);   /* "FillKeyDetectList (%04x) " */
    for (i = 0; i < count; i++) lib_printf517((void code *)0x98c9, piece[i]);   /* "%02x " */
    lib_printf517((void code *)0x98cf);   /* "\r\n" */
}
