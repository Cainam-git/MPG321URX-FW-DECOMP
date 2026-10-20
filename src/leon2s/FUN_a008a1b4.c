/* leon2s FUN_a008a1b4 @ 0xa008a1b4-0xa008a1f8 (17 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp 0/17 mismatches.
 * Code facts: leaf sibling call. Only for mode 4 or 6: FUN_a00a71fc(port & 0xff, 3, 0x20,
 * (u8)(val << 5)) (the 4th arg is masked 0xe0 by the u8 conversion). void.
 * Fix vs the autoc draft (83.33): a 'switch (mode) { case 4: case 6: ... }' gives the fw's two
 * compare-and-branch tests (the '||' form becomes branch-free subx flags: 60.00). Aids: none.
 */
extern void FUN_a00a71fc(unsigned char, unsigned short, unsigned char, unsigned char);

void FUN_a008a1b4(unsigned char mode, unsigned char port, unsigned int val)
{
    switch (mode) {
    case 4:
    case 6:
        FUN_a00a71fc(port, 3, 0x20, val << 5);
        break;
    }
}
