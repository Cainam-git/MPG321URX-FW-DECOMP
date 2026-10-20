/* leon2m FUN_a00b6b88 @ 0xa00b6b88-0xa00b6bec (25 words), flags -mcpu=v8 -O3 -g.
 * Code facts: leaf u8 step of a 0..7 value: dir == 1 (down): v == 0 -> 7 (wrap), else v - 1 if (u8)(v - 1) <= 6,
 * else v; other dir (up): v == 7 -> 0 (wrap), v > 6 -> v unchanged, else v + 1.
 * Fix vs the autoc draft (76.00): early returns (the fw writes each result straight into %o0 before retl; a result
 * variable gives a shared 'mov %o5, %o0' tail and reordered tests); u8 return. Aids: none.
 */
unsigned char FUN_a00b6b88(unsigned char v, unsigned char dir)
{
    unsigned char t;

    if (dir == 1) {
        if (v == 0)
            return 7;
        t = v - 1;
        if (t <= 6)
            return t;
        return v;
    }
    if (v == 7)
        return 0;
    if (v > 6)
        return v;
    return v + 1;
}
