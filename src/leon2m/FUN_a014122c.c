/* leon2m FUN_a014122c @ 0xa014122c-0xa0141290 (25 words).
 * Stores v in both bytes of entry FUN_a011909c() of the 16 two-byte entries of record i of the 0x20-byte records at
 * 0x1a3648 (FUN_a011909c is called once for each store), then calls FUN_a0118be4 with record i of the 0x1e-byte
 * records at 0x1a3668 and record i at 0x1a3648. The data word at 0xa0141290 that follows is not part of the function.
 */
struct RecA { unsigned char b[0x1e]; };
struct RecB { unsigned char e[16][2]; };
extern struct RecA DAT_001a3668[];
extern struct RecB DAT_001a3648[];
extern unsigned char FUN_a011909c(void);
extern void FUN_a0118be4(struct RecA *, struct RecB *);

void FUN_a014122c(unsigned char i, unsigned char v)
{
    DAT_001a3648[i].e[FUN_a011909c()][0] = v;
    DAT_001a3648[i].e[FUN_a011909c()][1] = v;
    FUN_a0118be4(&DAT_001a3668[i], &DAT_001a3648[i]);
}
