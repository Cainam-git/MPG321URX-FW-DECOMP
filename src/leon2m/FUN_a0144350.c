/* leon2m FUN_a0144350 @ 0xa0144350-0xa0144414 (49 words), flags -mcpu=v8 -O3 -g.
 * Same remap helper and channel check as FUN_a0144144 / FUN_a0146e2c.
 * Code facts: mapped = u8 remap(ch) (1 / 0 / 2 / 3 -> itself, else -1; case tree rooted at 1); mapped > 3 ->
 * FUN_a00df170(s_001a6dd8 "SYS remapping channel OOR\r\n") and mapped = 0 (out-of-line block, bgu). Then
 * idx = bits 12..15 of word DAT_a802df30[mapped] (0x78-byte records), b = byte +9 of the 42-byte record
 * DAT_a802e224[idx]; returns 1 when (u8)(b - 2) <= 2 (b is 2..4), else 0 (mov 1 / clr in the branch slots).
 * Source form: the record bases and types, one u8 param, the early 'return 1; return 0;' form (a 'v <= 2'
 * expression gives subx). Aids: none.
 */
struct Chan { unsigned int w0; unsigned char rest[0x74]; };
extern struct Chan DAT_a802df30[4];
struct Tab42 { unsigned char data[42]; };
extern struct Tab42 DAT_a802e224[];
extern int FUN_a00df170();
extern char s_001a6dd8[];

static int remap(int ch)
{
    switch (ch) {
    case 1: return 1;
    case 0: return 0;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

unsigned char FUN_a0144350(unsigned char ch)
{
    unsigned char i = remap(ch);
    unsigned char v;
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    v = DAT_a802e224[(DAT_a802df30[i].w0 >> 12) & 0xf].data[9] - 2;
    if (v <= 2)
        return 1;
    return 0;
}
