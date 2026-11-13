/* ipc_wait_input_cpu_power_down  (FUN_a013874c)
 *
 * Wait until the input processor reports that it has powered down.
 * Name basis: proven - prints 'wait sub power down'; polls bit 30 of the word at offset 0xC of mailbox portal
 *   1
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013874c @ 0xa013874c, flags -mcpu=v8 -O2 -g.
 * Source form: the address of the status word is taken once into a pointer (the firmware keeps it in a register);
 * the bit test reads the most significant byte of the word (ldub, then btst 0x40).
 */
#define IPC_PORTAL_INPUT_CPU    1       /* mailbox portal of the input processor */
#define STATUS_WORD_OFFSET      0xc     /* byte offset of word 3 of the portal */
#define STATUS_POWERED_DOWN     0x40    /* bit 30 of the word, the bit in its most significant byte */
#define DBG_MAILBOX             0x20    /* debug class of the mailbox prints */
extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern unsigned char dbg_is_print_enabled(unsigned int level);
extern int dbg_printf();

/*
 * Wait until the input processor reports that it has powered down: read word 3 of its mailbox portal until bit 30
 * is set. Each round prints 'wait sub power down' when the mailbox debug class is enabled. There is no time
 * limit.
 *
 * Called from SYSAPI_PowerOff and SYSAPI_PowerSaving.
 */
void ipc_wait_input_cpu_power_down(void)
{
    unsigned int status = 0;
    unsigned int *p = &status;

    do {
        ipc_mailbox_read(IPC_PORTAL_INPUT_CPU, STATUS_WORD_OFFSET, p, 1);
        if (dbg_is_print_enabled(DBG_MAILBOX))
            dbg_printf("wait sub power down\r\n");
    } while (!(((unsigned char *)&status)[0] & STATUS_POWERED_DOWN));
}
