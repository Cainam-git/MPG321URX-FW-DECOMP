/* ipc_request_8051_access  (FUN_a0062f3c)
 *
 * Ask the 8051 controller for access to the shared table and wait for its grant.
 *   mode: 1 = interrupt request
 * Returns: 1 when granted, 0 on timeout
 * Name basis: derived - 0x55 to shared byte F200, waits for 0xDD in F201, 0x88 on timeout; mode 1 raises a
 *   software interrupt instead
 *
 * Matching notes
 * --------------
 * FUN_a0062f3c (leon2s 0xa0062f3c, 140 bytes), flags -mcpu=v8 -Os -g.
 * The poll counter is initialised at its declaration. The poll loop and the final store go through two register
 * pointers set before the loop (the firmware keeps both addresses in registers). The eight nops are the delay
 * body between two polls.
 */
#define REG_C800 (*(volatile unsigned int *)0xcf03c800)     /* shared 8051 byte F200 */
#define REG_C804 (*(volatile unsigned int *)0xcf03c804)     /* shared 8051 byte F201 */
extern void irq_raise_software_irq_bit0(void);

/* Request modes (same names as in the caller). */
#define IPC_8051_SHARED_BYTE_REQUEST 0      /* write the request value to F200 */
#define IPC_8051_IRQ_REQUEST         1      /* raise the software interrupt instead */

#define IPC_8051_REQUEST       0x55         /* written to F200 to ask for access */
#define IPC_8051_GRANTED       0xdd         /* value of F201 that ends the wait */
#define IPC_8051_GIVE_UP       0x88         /* written to F200 when the wait ran out */
#define IPC_8051_POLL_LIMIT    0x9c400      /* last counter value of the wait: 0x9C401 polls */

/*
 * Ask the 8051 for access to the shared table and wait until it grants it.
 *
 *   mode  IPC_8051_IRQ_REQUEST: raise the software interrupt (irq_raise_software_irq_bit0);
 *         any other value: write 0x55 to shared byte F200
 *
 * Returns 1 when shared byte F201 reads 0xDD; polls it up to 0x9C401 times, with eight nops between polls.
 * When it never does, 0x88 is written to F200 and 0 is returned. A granted access is ended with
 * ipc_release_8051_access.
 */
int ipc_request_8051_access(unsigned char mode)
{
    unsigned int i = 0;
    volatile unsigned int *request_reg, *status_reg;

    if (mode == IPC_8051_IRQ_REQUEST)
        irq_raise_software_irq_bit0();
    else
        REG_C800 = IPC_8051_REQUEST;
    request_reg = &REG_C800;
    status_reg = &REG_C804;
    for (; i <= IPC_8051_POLL_LIMIT; i++) {
        if (*status_reg == IPC_8051_GRANTED)
            return 1;
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
    }
    *request_reg = IPC_8051_GIVE_UP;
    return 0;
}
