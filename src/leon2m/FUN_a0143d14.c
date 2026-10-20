/* leon2m FUN_a0143d14 @ 0xa0143d14  Flags: -mcpu=v8 -O3 -g.
 * Channel wrapper: channel 0..3 checked (otherwise prints "SYS remapping channel OOR" and uses 0), then returns
 * FUN_a013cea0(channel) as a byte. Same shape as FUN_a0148c94. Called by the APP event generator FUN_a0080c10
 * (row 1e).
 */
extern int FUN_a00df170();                     /* debug printf */
extern char s_001a6dd8[];                      /* "SYS remapping channel OOR\r\n" */
extern unsigned char FUN_a013cea0(unsigned char);

/* channel number check: 0..3 pass, anything else is -1 */
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

unsigned char FUN_a0143d14(unsigned char ch)
{
    unsigned char i = remap(ch);
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    return FUN_a013cea0(i);
}
