/* leon2m FUN_a009a37c @ 0xa009a37c (-mcpu=v8 -O2 -g)
 * Passes the byte at 0xA802D290 + 0x1E0 to FUN_a00a93bc, replaces it with DAT_a8025c55, calls FUN_a00af44c(0x34, 3),
 * sets _DAT_a802afec = 0xBD, calls FUN_a00a9650(2, 1) and clears DAT_a8025c55. The table is addressed through a
 * local base pointer (%l0 = 0xA802D290, load from [%l0 + 0x1e0]).
 */
extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00af44c(unsigned int, unsigned int);
extern void FUN_a00a9650(unsigned int, unsigned int);

void FUN_a009a37c(void)
{
    unsigned char *base = (unsigned char *)0xa802d290;
    FUN_a00a93bc(base[0x1e0]);
    base[0x1e0] = DAT_a8025c55;
    FUN_a00af44c(0x34, 3);
    _DAT_a802afec = 0xbd;
    FUN_a00a9650(2, 1);
    DAT_a8025c55 = 0;
}
