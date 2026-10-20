/* leon2m FUN_a00d2384 @ 0xa00d2384 (-mcpu=v8 -O2 -g)
 * Copies byte 7 of the buffer param_1 to byte 0x10 of the mode record DAT_a802d290, calls FUN_a00d4970(), then
 * FUN_a014aed0(0x30, DAT_a802d290, 0, 0x1fc) (0x1FC bytes of the record), and returns 0xE0.
 */
extern unsigned char DAT_a802d290[];
extern void FUN_a00d4970(void);
extern int FUN_a014aed0();

int FUN_a00d2384(unsigned char *param_1)
{
    DAT_a802d290[0x10] = param_1[7];
    FUN_a00d4970();
    FUN_a014aed0(0x30, DAT_a802d290, 0, 0x1fc);
    return 0xe0;
}
