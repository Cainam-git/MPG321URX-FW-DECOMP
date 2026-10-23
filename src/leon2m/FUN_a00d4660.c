/* leon2m FUN_a00d4660 @ 0xa00d4660-0xa00d4690 (12 words).
 * Limits byte DAT_a802d290+0xb to 100 (stored back) and passes it to FUN_a014929c (tail call).
 * Source form: the limited value is held in an unsigned short (keeps the and 0xff before the call).
 */
struct R290 {
    unsigned char pad[0xb];
    unsigned char b0b;
};
extern struct R290 DAT_a802d290;
extern void FUN_a014929c(unsigned char);

void FUN_a00d4660(void)
{
    unsigned short v = DAT_a802d290.b0b;

    if (v > 100)
        v = 100;
    DAT_a802d290.b0b = v;
    FUN_a014929c(v);
}
