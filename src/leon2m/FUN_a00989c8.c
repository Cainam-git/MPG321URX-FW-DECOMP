/* leon2m FUN_a00989c8 @ 0xa00989c8-0xa0098a74 (43 words).
 * v = byte 0xa802d298 (offset 8 of the block at 0xa802d290). Byte 0xa8025c56 = v, then FUN_a00a813c(1, v % 7, 0) and
 * FUN_a00a900c(selection word 0xa802afec - 42, 2). The value is read again, the selection word is set to v + 0x92 and
 * FUN_a00a9650(v % 7, 1) is tail-called. Same code as FUN_a0098434 with a fixed byte instead of an indexed one.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a00989c8(void)
{
    DAT_a8025c56 = DAT_a802d290[8];
    FUN_a00a813c(1, DAT_a802d290[8] % 7, 0);
    FUN_a00a900c(_DAT_a802afec - 42, 2);
    _DAT_a802afec = DAT_a802d290[8] + 0x92;
    FUN_a00a9650(DAT_a802d290[8] % 7, 1);
}
