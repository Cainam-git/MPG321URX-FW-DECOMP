/* leon2m FUN_a009b20c @ 0xa009b20c  MATCH (-mcpu=v8 -O3 -g, twin)
 * Twin of FUN_a009b154: same code, constants swapped; byte-exact.
 * See FUN_a009b154 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d290[];
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);

void FUN_a009b20c(void)
{
    int t;

    FUN_a00a93bc(_DAT_a802afec - 0xdd);
    do {
        t = (unsigned short)_DAT_a802afec - 0xdc;
        t = t % 5;
        _DAT_a802afec = t + 0xdd;
    } while (FUN_a00aad30(t) != 1);
    DAT_a802d290[0x13e] = _DAT_a802afec - 0xdd;
    FUN_a00a9650(_DAT_a802afec - 0xdd, 1);
    {
        unsigned char v = DAT_a8025c55;
        if (_DAT_a802afec - 0xdd == v)
            FUN_a00a813c(1, v, 0);
        else
            FUN_a00a813c(1, v, 1);
    }
}
