/* leon2m FUN_a00d5a9c @ 0xa00d5a9c-0xa00d5b10 (29 words).
 * Template FUN_a00d5a28: copies the 16-byte record selected by byte 0xa802d2b7 from the table at 0x198488 and
 * passes it to FUN_a014b968(5, ...).
 * This function is the same code as FUN_a00d5a28 (its source comment explains the details), compiled with
 * other constants (template -> this function):
 * 0x5 -> 0x6, 0xa802d2b7 -> 0xa802d2b8
 */
struct Rec16 {
    unsigned short h[8];
};
extern const struct Rec16 DAT_00198488[];
extern unsigned char DAT_a802d2b8;
extern void FUN_a014b968(int, struct Rec16 *);

void FUN_a00d5a9c(void)
{
    struct Rec16 r = DAT_00198488[DAT_a802d2b8];

    FUN_a014b968(6, &r);
}
