/* leon2m FUN_a00d5bb8 @ 0xa00d5bb8-0xa00d5c2c (29 words).
 * Copies the 16-byte record (eight halfwords) at entry byte 0xa802d2d6 of the table at 0x1984c8 into a local and
 * calls FUN_a014b900(0, &record). Same code as FUN_a00d5a28 with another index byte, table and callee.
 */
struct Rec16 {
    unsigned short h[8];
};
extern const struct Rec16 DAT_001984c8[];
extern unsigned char DAT_a802d2d6;
extern void FUN_a014b900(int, struct Rec16 *);

void FUN_a00d5bb8(void)
{
    struct Rec16 r = DAT_001984c8[DAT_a802d2d6];

    FUN_a014b900(0, &r);
}
