/* leon2s FUN_a00d264c @ 0xa00d264c (-mcpu=v8 -Os -g)
 * Finished by hand from mechanical Ghidra C. Fills the 257-entry 16-bit table at 0xa8077a08
 * with 0x400. Written as a plain array loop; Ghidra's byte-offset form changes the address operand order.
 */
extern unsigned short ARR_a8077a08[];

void FUN_a00d264c(void)
{
    int i;
    for (i = 0; i <= 0x100; i++)
        ARR_a8077a08[i] = 0x400;
}
