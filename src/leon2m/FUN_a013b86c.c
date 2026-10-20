/* leon2m FUN_a013b86c @ 0xa013b86c-0xa013b92c (48 words). -mcpu=v8 -O3 -g.
 * What it does (dc6c callee): maps a port number (0..3) to a slot index:
 *   ch = the first channel 0..3 whose record DAT_a802df30[ch] has this 4-bit port field;
 *   result = the first i 0..3 with FUN_a01436b4(i) == ch (FUN_a01436b4 maps 0..3 to a channel number),
 *   or 0xff when port > 3, no channel has the port, or no i maps to that channel.
 * Not rate-dependent.
 * Form: one u8 counter reused for both loops (fw keeps both in %i0, the channel in %l0), the found flag
 * set at the break, 'i = 0xff' when not found; 'port == rec.port' with port FIRST (fw 'cmp %o3,%o5').
 * volatile: none. Aids: none.
 */
struct Chan {
    union { unsigned int w; struct { unsigned int state:4, f24:4, step:4, f16:4, port:4, f8:4, f4:4, f1:3, b0:1; } b; } u;
    unsigned char p04[0x78 - 0x04];
};
extern struct Chan DAT_a802df30[4];
extern unsigned char FUN_a01436b4(unsigned char);
unsigned char FUN_a013b86c(unsigned char port)
{
    unsigned char i = 0, found = 0;
    if (port <= 3) {
        for (i = 0; i < 4; i++)
            if (port == DAT_a802df30[i].u.b.port)
                break;
        if (i <= 3) {
            unsigned char ch = i;
            for (i = 0; i < 4; i++)
                if (FUN_a01436b4(i) == ch) { found = 1; break; }
        }
    }
    if (!found)
        i = 0xff;
    return i;
}
