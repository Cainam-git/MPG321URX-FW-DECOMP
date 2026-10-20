/* leon2m FUN_a0146518 @ 0xa0146518  pass the active row's h08 / h0a to FUN_a01199ac
 * Flags: -mcpu=v8 -O3 -g -msoft-float.
 *
 * Tail call FUN_a01199ac(a, b, raw row +0x08, raw row +0x0A, c) with the raw active panel row at 0xA802E378
 * (+0x08 / +0x0A are 16-bit timing fields; FUN_a01023f4 programs +0x0A as the active height-related value).
 * Change-rule reader of the panel row (scorecard row 1c).
 */
struct RawRow { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short h08, h0a; };
extern struct RawRow DAT_a802e378;
extern void FUN_a01199ac(unsigned short, unsigned short, unsigned short, unsigned short, unsigned char);

void FUN_a0146518(unsigned short a, unsigned short b, unsigned char c)
{
    FUN_a01199ac(a, b, DAT_a802e378.h08, DAT_a802e378.h0a, c);
}
