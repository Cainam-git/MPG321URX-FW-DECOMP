/* leon2m FUN_a00de444 @ 0xa00de444-0xa00de4fc (46 words).
 * Returns the halfword constant for n: 1..5 -> 0xf000..0xf004, 6 -> 0xf010, 7 -> 0xf012, 8..13 -> 0xf114..0xf11e
 * (step 2), 14..17 -> 0xf300..0xf303; other n return 0.
 */
unsigned short FUN_a00de444(unsigned char n)
{
    unsigned short v = 0;

    switch (n) {
    case 1: v = 0xf000; break;
    case 2: v = 0xf001; break;
    case 3: v = 0xf002; break;
    case 4: v = 0xf003; break;
    case 5: v = 0xf004; break;
    case 6: v = 0xf010; break;
    case 7: v = 0xf012; break;
    case 8: v = 0xf114; break;
    case 9: v = 0xf116; break;
    case 10: v = 0xf118; break;
    case 11: v = 0xf11a; break;
    case 12: v = 0xf11c; break;
    case 13: v = 0xf11e; break;
    case 14: v = 0xf300; break;
    case 15: v = 0xf301; break;
    case 16: v = 0xf302; break;
    case 17: v = 0xf303; break;
    }
    return v;
}
