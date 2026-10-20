/* leon2m FUN_a00de65c @ 0xa00de65c-0xa00de6a8 (19 words), flags -mcpu=v8 -O3 -g.
 * Code facts: ROM register write func_0x4008c25c(0x9f0200e0, 0x60); three 'nop' instructions;
 * func_0x4008c25c(0x9f000014, 0); then a busy-wait of 1024 rounds: i = 0x3ff; loop body 'nop'; 'addcc i,-1; bpos'
 * (do { nop } while (--i >= 0)). void, no parameters (%i0 is never read).
 * Source form: the nops are inline asm (they are real instructions in the fw stream).
 * Compiler aids: none.
 */
extern void func_0x4008c25c(unsigned int addr, unsigned int value);

void FUN_a00de65c(void)
{
    int i;

    func_0x4008c25c(0x9f0200e0, 0x60);
    __asm__ __volatile__("nop");
    __asm__ __volatile__("nop");
    __asm__ __volatile__("nop");
    func_0x4008c25c(0x9f000014, 0);
    i = 0x3ff;
    do {
        __asm__ __volatile__("nop");
    } while (--i >= 0);
}
