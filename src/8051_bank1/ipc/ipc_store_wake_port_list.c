/* ipc_store_wake_port_list  (FUN_CODE_b3cb)
 *
 * Store part of the wake-up port table sent by the main processor.
 *   off: offset
 *   n: count
 *   src: data
 * Name basis: proven - prints 'SetZPArry OOR'; message type 9 (main side ipc_8051_send_wake_port_table), table
 *   0xA62F, 30 bytes
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_b3cb, OPTIMIZE(8,SPEED) LARGE. Same shape as FillKeyDetectList and ipc_store_power_cut_list.
 */
extern unsigned char xdata power_wake_port_table[];
extern void lib_printf517(void *fmt, ...) large;

/*
 * ipc_store_wake_port_list - copy n bytes from p into the wake port table (power_wake_port_table, 30 bytes) at
 * offset off. When off + n would pass 30 bytes it prints "SetZPArry OOR", then stores only what fits, or nothing
 * when off is already 30 or more.
 * Caller: the handler of message type 9 (ipc_run_message).
 */
void ipc_store_wake_port_list(unsigned int off, unsigned char n, unsigned char *src)
{
    unsigned char i;
    if (off + n > 0x1e) {
        lib_printf517((void code *)0xddc6);   /* "SetZPArry OOR\r\n" */
        if (off < 0x1e)
            n = 0x1e - off;
        else
            return;
    }
    for (i = 0; i < n; i++) power_wake_port_table[off + i] = src[i];
}
