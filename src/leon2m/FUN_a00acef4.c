/* leon2m FUN_a00acef4 @ 0xa00acef4  (-mcpu=v8 -O3 -g)
 * m = DAT_a802d290 byte +8 when that byte is 0, 6, 7 or 10, else 1. Calls FUN_a0146b50(0x191, 0) and FUN_a0146b6c(2,
 * 0). Second argument 1: FUN_a0146a80(0x2A, 1, 10, 0x596, 0), then FUN_a00a31a4(0, 0x2A, 1, 10, FUN_a00a3844(table
 * 0x188DA0, byte +8 + 0x91), 0). Second argument 2: the same pair with entry (bit 7 of the word at +0xA8) * 29 + m of
 * the table at 0x193248. Ends with FUN_a0146b6c(0, 0).
 * Callers: FUN_a0092648, FUN_a0095acc, FUN_a0095b58, FUN_a0095d5c, FUN_a0096bd8 and others.
 * Source form: every access names DAT_a802d290 directly (a local pointer to it changes the registers and drops
 * the reload of byte +8 in the assignment).
 */
struct R290 { unsigned char pad[8]; unsigned char b08; unsigned char pad2[0xa8 - 9]; unsigned int wa8; };
extern struct R290 DAT_a802d290;
extern void FUN_a0146b50(int, int);
extern void FUN_a0146b6c(int, int);
extern void FUN_a0146a80(int, int, int, int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);

void FUN_a00acef4(void)
{
    unsigned char m;

    if (DAT_a802d290.b08 == 0 || DAT_a802d290.b08 == 6 || DAT_a802d290.b08 == 7 || DAT_a802d290.b08 == 10)
        m = DAT_a802d290.b08;
    else
        m = 1;
    FUN_a0146b50(0x191, 0);
    FUN_a0146b6c(2, 0);
    FUN_a0146a80(0x2a, 1, 10, 0x596, 0);
    FUN_a00a31a4(0, 0x2a, 1, 10, FUN_a00a3844((unsigned int *)0x188da0, DAT_a802d290.b08 + 0x91), 0);
    FUN_a0146a80(0x2a, 2, 10, 0x596, 0);
    FUN_a00a31a4(0, 0x2a, 2, 10, FUN_a00a3844((unsigned int *)0x193248, ((DAT_a802d290.wa8 >> 7) & 1) * 29 + m), 0);
    FUN_a0146b6c(0, 0);
}
