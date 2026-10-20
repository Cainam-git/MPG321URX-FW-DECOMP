/* leon2m FUN_a00d5a28 @ 0xa00d5a28-0xa00d5a9c (29 words).
 * Copies the 16-byte record (eight halfwords) at entry byte 0xa802d2b7 of the table at 0x198488 into a local and
 * calls FUN_a014b968(5, &record). The copy is a plain structure assignment; GCC copies it halfword by halfword
 * because the record only has 2-byte alignment.
 */
struct Rec16 {
    unsigned short h[8];
};
extern const struct Rec16 DAT_00198488[];
extern unsigned char DAT_a802d2b7;
extern void FUN_a014b968(int, struct Rec16 *);

void FUN_a00d5a28(void)
{
    struct Rec16 r = DAT_00198488[DAT_a802d2b7];

    FUN_a014b968(5, &r);
}
