/* FUN_a00dd814 (leon2m 0xa00dd814-0xa00dd83c, 40 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores 1 to the byte DAT_a802b0ac when a is 1, otherwise 0, then stores b to the word DAT_a802b0a8. Its CPU
 * address 0x7d814 is stored in the word at 0xa01f8df4. It lies between FUN_a00dd808 and FUN_a00dd83c.
 */
extern unsigned char DAT_a802b0ac;
extern unsigned int DAT_a802b0a8;

void FUN_a00dd814(int a, unsigned int b)
{
    if (a == 1)
        DAT_a802b0ac = 1;
    else
        DAT_a802b0ac = 0;
    DAT_a802b0a8 = b;
}
