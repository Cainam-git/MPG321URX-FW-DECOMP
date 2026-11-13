/* startup_load_port_edids  (FUN_a012c188)
 *
 * Load the EDID of each port whose EDID flag is 1 into the 8051; switch the other internal EDIDs off.
 * Note: The per-port test is edid_get_port_flag; when callback slot 11 is set, that routine does the work
 *   instead.
 * Name basis: proven - EDID load into the 8051's DDC slaves; called from start-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012c188 @ 0xa012c188..0xa012c320 (102 words), flags -mcpu=v8 -O3 -g.
 * Source form: the hang loop is a for (;;) whose body is two asm nops (the firmware's loop body is two nop
 * instructions). The data pointer is read before the length, both indexed by device_settings[0x1b + port]
 * written out; the nibble update is two statements, 'word &= ~(0xf << shift); word |= (size >> 7) << shift;'
 * (the one-expression form swaps two temporary registers).
 */
extern unsigned int edid_port_size_codes;
extern void (*sys_callback_table_slot11)(void);
extern unsigned char device_settings[];
extern const unsigned short edid_variant_lengths[];
extern unsigned int edid_default_ptrs[];
extern unsigned short edid_get_port_memory_size(unsigned char);
extern unsigned char edid_get_port_flag(unsigned char);
extern unsigned short edid_get_port_memory_base(unsigned char);
extern void ipc_8051_disable_internal_edid(unsigned char);
extern void ipc_8051_wait_tx_queue(unsigned char, unsigned short);
extern void ipc_8051_write_port_memory(unsigned short, unsigned short, unsigned int);
extern void ipc_8051_enable_internal_edid(unsigned char, unsigned short, unsigned char);
extern int dbg_printf(const char *, ...);

#define PORT_COUNT          7       /* ports 0..6 */
#define SIZE_CODE_SHIFT     7       /* memory size in 128-byte units */
#define EDID_CHOICE_OFFSET  0x1b    /* device_settings[0x1b + port]: the stored EDID choice of the port */

/*
 * Start-up: give every port its internal EDID in the 8051's DDC slave memory, or switch it off. Called once,
 * near the end of the start-up routine, after the display start-up.
 *
 * Order:
 *   1. for each of the 7 ports record the size of its EDID memory in 128-byte units as nibble `port` of
 *      edid_port_size_codes (old nibble cleared first);
 *   2. if the callback slot 11 (sys_callback_table_slot11) is set, call it and return: the ports are then not
 *      touched here;
 *   3. otherwise, for each port: when its per-port flag (edid_get_port_flag) is not 1, tell the 8051 to switch
 *      the internal EDID off. When it is 1, take the port's memory base, the EDID the stored settings choose
 *      for it (pointer in edid_default_ptrs, length in edid_variant_lengths, both indexed by
 *      device_settings[0x1b + port]) and, if the EDID is longer than the port's memory, print
 *      "DDC_%d : MaxLen %d / EDID_%d : Len %d" (in red) and stop for ever in a loop of two nops; else wait
 *      until the 8051 queue is empty (ipc_8051_wait_tx_queue), write the EDID into the port memory
 *      (ipc_8051_write_port_memory) and switch the internal EDID on, giving the 8051 the length and the base in
 *      128-byte units (ipc_8051_enable_internal_edid).
 * Two places can block without end: the endless loop for a too long EDID, and the queue wait, which has no
 * timeout. Unlike edid_set_port_internal_edid this code does not test the stored choice for 0xFF.
 */
void startup_load_port_edids(void)
{
    unsigned short port;
    unsigned short memory_size_or_base, length;
    unsigned int data;

    for (port = 0; port < PORT_COUNT; port++) {
        memory_size_or_base = edid_get_port_memory_size(port);
        edid_port_size_codes &= ~(0xf << ((unsigned char)port * 4));
        edid_port_size_codes |= (memory_size_or_base >> SIZE_CODE_SHIFT) << ((unsigned char)port * 4);
    }
    if (sys_callback_table_slot11 != 0) {
        sys_callback_table_slot11();
        return;
    }
    for (port = 0; port < PORT_COUNT; port++) {
        if (edid_get_port_flag(port) == 1) {
        memory_size_or_base = edid_get_port_memory_base(port);
        data = edid_default_ptrs[device_settings[EDID_CHOICE_OFFSET + port]];
        length = edid_variant_lengths[device_settings[EDID_CHOICE_OFFSET + port]];
        if (length > edid_get_port_memory_size(port)) {
            dbg_printf("\033[1;31mDDC_%d : MaxLen %d / EDID_%d : Len %d\r\n\033[m", port, edid_get_port_memory_size(port), device_settings[EDID_CHOICE_OFFSET + port], length);
            for (;;) {
                __asm__ volatile ("nop");
                __asm__ volatile ("nop");
            }
        }
        ipc_8051_wait_tx_queue(1, length);
        ipc_8051_write_port_memory(memory_size_or_base, length, data);
        ipc_8051_enable_internal_edid(1 << port, length, memory_size_or_base >> SIZE_CODE_SHIFT);
        } else
            ipc_8051_disable_internal_edid(1 << port);
    }
}
