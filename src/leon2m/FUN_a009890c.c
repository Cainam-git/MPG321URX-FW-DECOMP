/* leon2m FUN_a009890c @ 0xa009890c-0xa00989c8 (47 words).
 * Same instructions and constants as FUN_a0098434 (whose header describes them); only the call displacements
 * differ because the code lies at another address. v = byte 0xa802d290[0x18a + k] with k = byte 0xa802d433
 * (offset 0x1a3); byte 0xa8025c56 = v, FUN_a00a813c(1, v % 7, 0), FUN_a00a900c(word 0xa802afec - 38, 2), word
 * 0xa802afec = v + 0x86 and the tail call FUN_a00a9650(v % 7, 1); v is read again for each use.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a009890c(void)
{
    DAT_a8025c56 = DAT_a802d290[DAT_a802d290[0x1a3] + 0x18a];
    FUN_a00a813c(1, DAT_a802d290[DAT_a802d290[0x1a3] + 0x18a] % 7, 0);
    FUN_a00a900c(_DAT_a802afec - 38, 2);
    _DAT_a802afec = DAT_a802d290[DAT_a802d290[0x1a3] + 0x18a] + 0x86;
    FUN_a00a9650(DAT_a802d290[DAT_a802d290[0x1a3] + 0x18a] % 7, 1);
}
