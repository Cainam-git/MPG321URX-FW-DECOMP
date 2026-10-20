/* FUN_a008b9b0 (leon2s 0xa008b9b0-0xa008b9ec, 60 bytes incl. the merged ret/restore tail at 0xa008b9e4),
 * flags -mcpu=v8 -Os -g. of 15 words.
 * void, u8 port and u8 flag 'on' (btst 0xff, %i1). When on != 0 it calls FUN_a008b6f4(port) (one argument: only
 * %o0 is set) and then tail-calls FUN_a00a6c98(port, 0x50, 0x40, 0) (call + restore). When on == 0 it returns at
 * once.
 * Prototype of FUN_a00a6c98 as in FUN_a00ac4ec.c (void; u32, u16, u32, u32).
 */
extern void FUN_a008b6f4(unsigned char);
extern void FUN_a00a6c98(unsigned int, unsigned short, unsigned int, unsigned int);

void FUN_a008b9b0(unsigned char port, unsigned char on)
{
  if (on != 0) {
    FUN_a008b6f4(port);
    FUN_a00a6c98(port, 0x50, 0x40, 0);
  }
}
