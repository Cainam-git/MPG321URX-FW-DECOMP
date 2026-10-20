/* leon2m FUN_a00f87dc @ 0xa00f87dc  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, near)
 * near-miss repaired mechanically (tools/nearfix.py): name g_buf->DAT_a802b7d8
 */
extern unsigned short DAT_a802b7d8[];                 /* 0xa802b7d8 */
extern void FUN_a00f1ad4(int, int, int);       /* 0xa00f1ad4 */
extern void FUN_a00f1d48(int, int, int);       /* 0xa00f1d48 */

void FUN_a00f87dc(void)
{
    unsigned int i = 0;
    unsigned int j = 0;

    do {
        DAT_a802b7d8[j] = 0;
        i++;
        j = i & 0xff;
    } while (j <= 7);

    FUN_a00f1ad4(8, 0x42, 0);
    FUN_a00f1ad4(8, 6, 0);
    FUN_a00f1d48(8, 0xc, 0x20);
    FUN_a00f1d48(8, 0xe, 0);
    FUN_a00f1d48(8, 0x10, 0x1e0);
    FUN_a00f1d48(8, 0x12, 0x88);
    FUN_a00f1d48(8, 0x14, 0x280);
    FUN_a00f1ad4(8, 0x16, 0);
    FUN_a00f1ad4(8, 0, 0xa1);
    FUN_a00f1ad4(8, 3, 0x80);
}
