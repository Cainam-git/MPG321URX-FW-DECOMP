/* leon2m FUN_a0143ff0 @ 0xa0143ff0 (-mcpu=v8 -O2 -g)
 * Maps the channel number ch (0..3) through remap(); an out-of-range channel prints "SYS remapping channel OOR"
 * (s_001a6dd8) and uses channel 0. Takes bits 12..15 of word 0 of the 0x78-byte channel record DAT_a802df30[ch] as
 * an index into the 42-byte records at DAT_a802e224, reads byte 0x0A of that record, passes it to FUN_a0142168 and
 * the low byte of that result to FUN_a0129a10, and returns the low byte of FUN_a0129a10's result.
 *
 * The remap() switch reproduces the target's range check: it returns -1 for any other value, which the unsigned
 * char local turns into 0xFF > 3.
 */
struct Chan { unsigned int w0; unsigned char rest[0x74]; };   /* display channel record, 0x78 bytes */
extern struct Chan DAT_a802df30[4];
struct Tab42 { unsigned char data[42]; };
extern struct Tab42 DAT_a802e224[];
extern int FUN_a00df170();                     /* debug printf */
extern char s_001a6dd8[];                      /* "SYS remapping channel OOR\r\n" */
extern int FUN_a0142168(unsigned char);
extern int FUN_a0129a10(int);

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

unsigned char FUN_a0143ff0(unsigned char ch)
{
    unsigned char i = remap(ch);
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    return FUN_a0129a10(FUN_a0142168(DAT_a802e224[(DAT_a802df30[i].w0 >> 12) & 0xf].data[0xa]) & 0xff);
}
