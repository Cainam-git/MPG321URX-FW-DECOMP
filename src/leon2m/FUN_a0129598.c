/* leon2m FUN_a0129598 @ 0xa0129598, flags -mcpu=v8 -O3 -g.
 *
 * Resets the OLED FRC handler state halfword at 0xA802D892: keeps bits 8..9, clears the state (bits 12..15) and the
 * flags 0x400/0x800, and sets the low byte (the panel row index, 0xA802D893) to 0xFF = "no row selected", so the
 * next row selection and the handler's state machine start again. Caller: FUN_a0087020.
 */
struct FrcSm { unsigned short w; unsigned short t; };
extern struct FrcSm DAT_a802d892;
void FUN_a0129598(void)
{
    DAT_a802d892.w &= 0x3ff;
    ((unsigned char *)&DAT_a802d892)[1] = 0xff;
}
