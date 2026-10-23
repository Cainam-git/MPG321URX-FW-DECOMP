/* leon2m FUN_a00d57e8 @ 0xa00d57e8-0xa00d58b0 (50 words).
 * Copies the 0x1fc bytes at 0x198524 to DAT_a802d290 (FUN_a013c910) and writes them with
 * FUN_a014aed0(0x30, DAT_a802d290, 0, 0x1fc); then copies the 28-byte record at 0x198508 to DAT_a802d274 and
 * writes it with FUN_a014aed0(0x30, &DAT_a802d274, 0x2e0, 0x1c) (tail call).
 * Source form: DAT_a802d290 is passed through one pointer local (the whole address stays in a register); the
 * 28-byte record is a structure of 14 halfwords (2-byte alignment: copied halfword by halfword).
 */
struct S274 { unsigned short h[14]; };
extern unsigned char DAT_a802d290[];
extern const unsigned char DAT_00198524[];
extern struct S274 DAT_a802d274;
extern const struct S274 DAT_00198508;
extern void *FUN_a013c910(void *dst, const void *src, int n);
extern int FUN_a014aed0(int, void *, int, int);

void FUN_a00d57e8(void)
{
    unsigned char *p = DAT_a802d290;

    FUN_a013c910(p, DAT_00198524, 0x1fc);
    FUN_a014aed0(0x30, p, 0, 0x1fc);
    DAT_a802d274 = DAT_00198508;
    FUN_a014aed0(0x30, &DAT_a802d274, 0x2e0, 0x1c);
}
