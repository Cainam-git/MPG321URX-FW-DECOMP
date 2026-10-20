/* leon2m FUN_a010a494 @ 0xa010a494-0xa010a4d0 (15 words), flags -mcpu=v8 -O3 -g.
 * Code facts: picks one of two 16-bit register pairs of the frame-rate-converter output timing block and reads it
 * with FUN_a00f3078 (two hardware words, (p[1] << 8) | p[0]): when bit 7 of 0xcf011a80 is set it reads 0xcf011ad8,
 * else 0xcf011c18; returns the low 16 bits. 0xcf011a80 bit 7 and the 0xcf011aXX / 0xcf011cXX pairs are the registers
 * FRCConfigPostFRC FUN_a0107e44 programs. Callers: FUN_a01062e0 (output path set-up), FUN_a012b9a8.
 * volatile only on the real hardware register 0xcf011a80. Aids: none.
 */
extern unsigned int FUN_a00f3078(volatile unsigned int *p);
unsigned short FUN_a010a494(void)
{
    if (*(volatile unsigned int *)0xcf011a80 & 0x80)
        return FUN_a00f3078((volatile unsigned int *)0xcf011ad8);
    return FUN_a00f3078((volatile unsigned int *)0xcf011c18);
}
