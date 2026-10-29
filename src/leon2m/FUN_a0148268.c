/* leon2m FUN_a0148268 @ 0xa0148268-0xa0148350 (232 bytes), -mcpu=v8 -O3 -g.
 * Maps the byte channel ch 0..3 to itself through the switch helper remap (any other value gives -1); when the
 * low byte of the result is above 3 it prints s_001a6dd8 ("SYS remapping channel OOR") through FUN_a00df170 and
 * uses channel 0. Then calls FUN_a012f1ec(channel, mode) for mode 0, 1, 2 or 3; other modes call nothing.
 * Source form: remap is an inlined static helper returning int (its return value is copied into i, as in
 * FUN_a0147560); the four mode tests are separate if statements, so the calls for modes 0..2 are plain calls and
 * only the mode 3 call is a sibling call.
 */
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a012f1ec(unsigned char ch, unsigned char m);
extern char s_001a6dd8[];

static int remap(unsigned char ch)
{
    switch (ch) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

void FUN_a0148268(unsigned char ch, unsigned char mode)
{
    int i = remap(ch);

    if ((unsigned char)i > 3) {
        FUN_a00df170(s_001a6dd8);
        i = 0;
    }
    if (mode == 0)
        FUN_a012f1ec(i, 0);
    if (mode == 1)
        FUN_a012f1ec(i, 1);
    if (mode == 2)
        FUN_a012f1ec(i, 2);
    if (mode == 3)
        FUN_a012f1ec(i, 3);
}
