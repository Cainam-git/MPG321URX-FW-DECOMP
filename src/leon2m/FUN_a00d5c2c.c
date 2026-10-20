/* leon2m FUN_a00d5c2c @ 0xa00d5c2c-0xa00d5ca0 (29 words).
 * Template FUN_a00d5a28: copies the 16-byte record selected by byte 0xa802d2b7 from the table at 0x198488 and
 * passes it to FUN_a014b968(5, ...).
 * This function is the same code as FUN_a00d5a28 (its source comment explains the details), compiled with
 * other constants (template -> this function):
 * 0x5 -> 0x1, 0x198488 -> 0x1984c8, 0xa014b968 -> 0xa014b900, 0xa802d2b7 -> 0xa802d2d8
 */
struct Rec16 {
    unsigned short h[8];
};
extern const struct Rec16 DAT_001984c8[];
extern unsigned char DAT_a802d2d8;
extern void FUN_a014b900(int, struct Rec16 *);

void FUN_a00d5c2c(void)
{
    struct Rec16 r = DAT_001984c8[DAT_a802d2d8];

    FUN_a014b900(1, &r);
}
