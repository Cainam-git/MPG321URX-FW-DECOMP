/* leon2s FUN_a00a2b08 @ 0xa00a2b08  MATCH (-mcpu=v8 -Os -g)
 * For both per-port records i = 0, 1 of the 0x34-byte table at 0xA807DB00 (base = record word 0 + 0xB4):
 * FUN_a00a73ac(0xe, base); then, if param_1 == 1, FUN_a00a73ac(0xa, base), or if param_1 == 0, FUN_a00a73d4(8,
 * base) and FUN_a00a73d4(0xa, base). Returns 0 (restore %g0, 0, %o0). The u8 counter is masked with & 0xff at each
 * use, and the loop is a do-while ending at i <= 1.
 */
extern unsigned char DAT_a807db00;
extern void FUN_a00a73ac(unsigned int param_1, int param_2);
extern void FUN_a00a73d4(unsigned int param_1, int param_2);

int FUN_a00a2b08(unsigned char param_1)
{
    unsigned char i;
    
    i = 0;
    do {
        FUN_a00a73ac(0xe, *(int *)(&DAT_a807db00 + (i & 0xff) * 0x34) + 0xb4);
        if (param_1 == 1) {
            FUN_a00a73ac(0xa, *(int *)(&DAT_a807db00 + (i & 0xff) * 0x34) + 0xb4);
        }
        else if (param_1 == 0) {
            FUN_a00a73d4(8, *(int *)(&DAT_a807db00 + (i & 0xff) * 0x34) + 0xb4);
            FUN_a00a73d4(0xa, *(int *)(&DAT_a807db00 + (i & 0xff) * 0x34) + 0xb4);
        }
        i++;
    } while ((i & 0xff) <= 1);
  return 0;
}
