/* leon2m FUN_a01447bc @ 0xa01447bc-0xa014489c (-mcpu=v8 -O3 -g)
 * k = p1; any k above 3 prints "SYS remapping channel OOR" (s_001a6dd8) through FUN_a00df170 and uses 0. With
 * n = bits 12-15 of word 0 of record k of the 0x78-byte records at 0xA802DF30, r = FUN_a0142168(byte +0xA of entry
 * n of the 42-byte entries at 0xA802E224) & 0xff; r above 6 becomes 0; returns byte +5 of the 18-byte record r at
 * 0xA802E116.
 * Source form: FUN_a0144144 with its last call replaced by a static getter get5() (inlined).
 */
struct Chan { unsigned int w0; unsigned char rest[0x74]; };
extern struct Chan DAT_a802df30[4];
struct Tab42 { unsigned char data[42]; };
extern struct Tab42 DAT_a802e224[];
extern int FUN_a00df170();
extern char s_001a6dd8[];
extern int FUN_a0142168(unsigned char);

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

struct Rec18 { unsigned char b0[5]; unsigned char b5; unsigned char p6[10]; unsigned char b10; unsigned char b11; };
extern struct Rec18 DAT_a802e116[7];

static unsigned char get5(unsigned char i)
{
    if (i > 6)
        i = 0;
    return DAT_a802e116[i].b5;
}

unsigned char FUN_a01447bc(unsigned char ch)
{
    unsigned char i = remap(ch);
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    return get5(FUN_a0142168(DAT_a802e224[(DAT_a802df30[i].w0 >> 12) & 0xf].data[0xa]) & 0xff);
}
