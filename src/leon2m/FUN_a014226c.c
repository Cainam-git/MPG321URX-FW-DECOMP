/* leon2m FUN_a014226c @ 0xa014226c-0xa01422f4 (34 words). -mcpu=v8 -O3 -g.
 * What it does (leaf): maps a port code to an index: 0x31 -> 0, 0x41 -> 1, 0x51 -> 2, 0x61 -> 3, 0x71 -> 0,
 * 0x81 -> 1, every other value -> 0xff. Callers: the channel bring-up dc6c, FUN_a0136054, FUN_a013d018.
 * Not rate-dependent; it turns the input's port code into the 0..3 index.
 * The compare tree (fw: root 0x51; left: ==0x21, <=0x21, ==0x31, ==0x41; right: ==0x81, >0x81, ==0x61, ==0x71)
 * is gcc 3.4's balance_case_nodes (stmt.c) for a 9-node case list with one range at each end:
 *   [x < 0x21] [0x21] 0x31 0x41 | 0x51 | 0x61 0x71 0x81 [range ..0xff]  (a range counts 2 in the split).
 * So the original switch had, besides the six real cases, case labels with the default's value 0xff:
 * 0x21 plus one value below it on the SAME label, and a GNU case range ending at 0xff that starts above
 * 0x82 (0x82 ... 0xff makes the node 'bounded' and changes the tree). The bytes do not fix those values:
 * 0x11 and 0x91 ... 0xff are chosen here (the 0xN1 port-code pattern). These are no-code case labels.
 * Case order 0x31, 0x51, 0x61, 0x71, 0x41, 0x81
 * (by value 0/2/3, then the two '1' cases) gives the fw block order at the end (0x71 test, then default).
 * Aids: the case labels above (no code of their own; behaviour = the six real cases + default 0xff).
 */
unsigned char FUN_a014226c(unsigned char p)
{
    unsigned char r;

    switch (p) {
    case 0x11:
    case 0x21: r = 0xff; break;
    case 0x31: r = 0; break;
    case 0x51: r = 2; break;
    case 0x61: r = 3; break;
    case 0x71: r = 0; break;
    case 0x41: r = 1; break;
    case 0x81: r = 1; break;
    case 0x91 ... 0xff: r = 0xff; break;
    default: r = 0xff; break;
    }
    return r;
}
