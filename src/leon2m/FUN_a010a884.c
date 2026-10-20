/* leon2m FUN_a010a884 @ 0xa010a884 (-mcpu=v8 -O2 -g, gcc 3.4.4; mechanical draft)
 * FRC output line length (horizontal total, pixels), 16 bits. Twin of FUN_a010a9e8 (the frame length).
 *   0xCF011A80 bit 7 set: sum of the four registers 0xCF011AC0, 0xCF011AC8, 0xCF011AD0, 0xCF011AD8 (FUN_a00f3078 reads),
 *     no scaling; bit 7 clear: the register 0xCF011C20 (FUN_a0109bbc's Lock-mode arithmetic uses 0xCF011C20 & 0xFFFF as
 *     the output line length). Result truncated to 16 bits.
 * Callers: FUN_a01070b4 (panel limitation check, "htotal" when FRC is on) and FUN_a012b9a8 (output timing for the
 * Small chip message of FUN_a012bc08).
 */

extern int FUN_a00f3078(int);

unsigned short FUN_a010a884(void)
{
    unsigned short sum;

    if (*(volatile unsigned int *)0xcf011a80 & 0x80) {
        sum = FUN_a00f3078(0xcf011ac0);
        sum += FUN_a00f3078(0xcf011ac8);
        sum += FUN_a00f3078(0xcf011ad0);
        sum += FUN_a00f3078(0xcf011ad8);
    } else {
        sum = FUN_a00f3078(0xcf011c20);
    }
    return (unsigned short)sum;
}
