/* leon2m FUN_a0149fb8 @ 0xa0149fb8-0xa014a060 (42 words).
 * Maps the channel number ch (0..3, else -1, by the same remap helper as FUN_a0143e70); a channel outside 0..3 prints
 * "SYS remapping channel OOR" (string 0x1a6dd8) and uses channel 0. Then FUN_a012f1ec(i, 2) and the tail call
 * FUN_a0109474(FUN_a013cda8(i), 0).
 */
extern int FUN_a00df170();
extern char s_001a6dd8[];
extern void FUN_a012f1ec(unsigned char, int);
extern unsigned char FUN_a013cda8(unsigned char);
extern void FUN_a0109474(unsigned char, int);

static int remap(int ch)
{
    switch (ch) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

void FUN_a0149fb8(unsigned char ch)
{
    unsigned char i = remap(ch);

    if (i > 3) {
        FUN_a00df170(s_001a6dd8);
        i = 0;
    }
    FUN_a012f1ec(i, 2);
    FUN_a0109474(FUN_a013cda8(i), 0);
}
