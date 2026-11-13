/* ipc_store_power_cut_list  (FUN_CODE_a819)
 *
 * Store part of the power-cut table sent by the main processor.
 *   offset
 *   count
 *   piece: data
 * Name basis: proven - prints 'CutPwArray OOR %d %d'; message type 10 (main side
 *   ipc_8051_send_power_cut_table), 0xA6AF, 18 bytes
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_a819 @ 0xA819..0xA8BB (162 bytes), OPTIMIZE(8,SPEED) LARGE.
 * LARGE parameters offset (uint, XDATA 0xA4A9..0xA4AA), count (0xA4AB), piece (generic pointer, 0xA4AC..0xA4AE);
 *   i is kept in R7. The print arguments are passed as unsigned int. Same shape as FillKeyDetectList.
 */
extern unsigned char xdata power_cut_table[];
extern void lib_printf517(void *fmt, ...) large;

#define CUT_TABLE_BYTES  0x12  /* size of power_cut_table: six 3-byte entries (18 bytes) */

/*
 * ipc_store_power_cut_list - copy one piece of the power-cut table that the main processor sends (message type
 * IPC_8051_TX_MSG_POWER_CUT 10) into power_cut_table; power_apply_cut_list works through it.
 *   offset  where the piece starts in the table
 *   count   number of bytes
 *   piece   the bytes
 * A piece that runs past the end of the table prints "CutPwArray OOR %d %d" with offset and count and is cut at
 * the end; one that starts past the end is dropped.
 * Only caller: ipc_run_message, for message type 10.
 */
void ipc_store_power_cut_list(unsigned int offset, unsigned char count, unsigned char *piece)
{
    unsigned char i;
    if (offset + count > CUT_TABLE_BYTES) {
        lib_printf517((void code *)0xcee6, offset, (unsigned int)count);   /* "CutPwArray OOR %d %d\r\n" */
        if (offset < CUT_TABLE_BYTES)
            count = CUT_TABLE_BYTES - offset;
        else
            return;
    }
    for (i = 0; i < count; i++) power_cut_table[offset + i] = piece[i];
}
