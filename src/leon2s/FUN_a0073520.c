/* leon2s FUN_a0073520 @ 0xa0073520-0xa0073540 (8 words), flags -mcpu=v8 -Os -g.
 * Leaf: returns 1 if (u8)(v - 2) <= 1 (v == 2 or 3), else 0. Same body as leon2m FUN_a0142360.
 * The test is on the u8 of v - 2 (the firmware masks with 'and 0xff' after the add). u8 param / u8 return.
 */
unsigned char FUN_a0073520(unsigned char v)
{
    if ((unsigned char)(v - 2) <= 1)
        return 1;
    return 0;
}
