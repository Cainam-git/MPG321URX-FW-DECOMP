/* leon2m FUN_a00d58b0 @ 0xa00d58b0-0xa00d58d8 (10 words).
 * FUN_a0087a14(byte 0xa802d2aa limited to 4) as a tail call.
 * Source form: the limited value is held in an unsigned short (an unsigned char drops the and 0xff before the call).
 */
extern unsigned char DAT_a802d2aa;
extern void FUN_a0087a14(unsigned char);

void FUN_a00d58b0(void)
{
    unsigned short v = DAT_a802d2aa;

    if (v > 4)
        v = 4;
    FUN_a0087a14(v);
}
