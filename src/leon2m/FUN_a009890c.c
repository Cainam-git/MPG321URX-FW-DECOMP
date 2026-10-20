/* leon2m FUN_a009890c @ 0xa009890c-0xa00989c8 (47 words).
 * Template FUN_a0098434: Copies the stored position to byte 0xa8025c56 and the selection word 0xa802afec and
 * reports it.
 * This function is the same code as FUN_a0098434 (its source comment explains the details), compiled with
 * other constants (template -> this function):
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
