/* leon2m FUN_a0098434 @ 0xa0098434-0xa00984f0 (47 words).
 * v = byte 0xa802d290[0x18a + k] with k = byte 0xa802d433 (offset 0x1a3). Byte 0xa8025c56 = v, then
 * FUN_a00a813c(1, v % 7, 0) and FUN_a00a900c(selection word 0xa802afec - 38, 2). The value is read again, the
 * selection word is set to v + 0x86 and FUN_a00a9650(v % 7, 1) is tail-called.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a0098434(void)
{
    DAT_a8025c56 = DAT_a802d290[DAT_a802d290[0x1a3] + 0x18a];
    FUN_a00a813c(1, DAT_a802d290[DAT_a802d290[0x1a3] + 0x18a] % 7, 0);
    FUN_a00a900c(_DAT_a802afec - 38, 2);
    _DAT_a802afec = DAT_a802d290[DAT_a802d290[0x1a3] + 0x18a] + 0x86;
    FUN_a00a9650(DAT_a802d290[DAT_a802d290[0x1a3] + 0x18a] % 7, 1);
}
