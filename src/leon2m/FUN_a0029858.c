/* leon2m FUN_a0029858 @ 0xa0029858-0xa002992c (53 words), flags -mcpu=v8 -O3 -g. No direct callers.
 * A fixed sequence of register writes through FUN_a002c25c(addr, value) and the read-modify-write
 * FUN_a002c268(p, v, mask): 0x9f000090 = 0, 0x9f020028 = 0xffff, 0x9f00009c = 0xffff, 0x9f020034 = 0xffff;
 * bits 0x7ffe of 0x9f020030 and 0x9f000090 set, of 0x9f020028 cleared; 0x9f020034 = 0x7ffe; bit 0x100000 of
 * 0x9f020038 set; then FUN_a0029820(1, 0x10) and FUN_a0029820(4, 0x25): clear the mask bits in register
 * 0x9f020034 + 4 * n and write the mask to 0x9f02006c + 4 * n.
 * Source form: FUN_a0029820 (the function just before this one) is defined here as a static copy of its body and
 * inlined; the firmware keeps the two block bases 0x9f020034 / 0x9f02006c in registers and adds 4 * n.
 */
extern void FUN_a002c25c(unsigned int addr, unsigned int value);
extern void FUN_a002c268(volatile unsigned int *p, unsigned int v, unsigned int mask);

static void FUN_a0029820(int n, unsigned short m)
{
    FUN_a002c268((volatile unsigned int *)(0x9f020034 + n * 4), 0, m);
    FUN_a002c25c(0x9f02006c + n * 4, m);
}

void FUN_a0029858(void)
{
    FUN_a002c25c(0x9f000090, 0);
    FUN_a002c25c(0x9f020028, 0xffff);
    FUN_a002c25c(0x9f00009c, 0xffff);
    FUN_a002c25c(0x9f020034, 0xffff);
    FUN_a002c268((volatile unsigned int *)0x9f020030, 0x7ffe, 0x7ffe);
    FUN_a002c268((volatile unsigned int *)0x9f000090, 0x7ffe, 0x7ffe);
    FUN_a002c268((volatile unsigned int *)0x9f020028, 0, 0x7ffe);
    FUN_a002c25c(0x9f020034, 0x7ffe);
    FUN_a002c268((volatile unsigned int *)0x9f020038, 0x100000, 0x100000);
    FUN_a0029820(1, 0x10);
    FUN_a0029820(4, 0x25);
}
