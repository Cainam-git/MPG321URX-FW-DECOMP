/* FUN_a0070000 (leon2s 0xa0070000-0xa00700cc, 204 bytes), flags -mcpu=v8 -Os -g.
 * v. Clears the word DAT_a80788d8, then for i = 0..2 ORs bits into it from bit i of the three low bytes of v
 * (b0, b1, b2): bit i when b0 or b1 has bit i set, bit 8 + i when b2 has it, bit 16 + i when both b0 and b1 have
 * it, and bit 24 + i when b1 has it.
 * Source form: the loop ORs into the global directly (GCC keeps it in a register over the loop and stores it once
 * after, with the address high part copied to a second register); v >> 8 and v >> 16 written in the tests.
 */
extern unsigned int DAT_a80788d8;

void FUN_a0070000(unsigned int v)
{
    unsigned char i;

    DAT_a80788d8 = 0;
    for (i = 0; i < 3; i++) {
        if ((unsigned char)(v & (1 << i)) || (unsigned char)((v >> 8) & (1 << i)))
            DAT_a80788d8 |= (1 << i);
        if ((unsigned char)((v >> 16) & (1 << i)))
            DAT_a80788d8 |= (1 << i) << 8;
        if ((unsigned char)(v & (1 << i)) && (unsigned char)((v >> 8) & (1 << i)))
            DAT_a80788d8 |= (1 << i) << 16;
        if ((unsigned char)((v >> 8) & (1 << i)))
            DAT_a80788d8 |= (1 << i) << 24;
    }
}
