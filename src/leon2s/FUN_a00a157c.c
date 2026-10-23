/* FUN_a00a157c (leon2s 0xa00a157c-0xa00a15c8, 76 bytes), flags -mcpu=v8 -Os -g.
 * For the 400-byte record DAT_a807d7e0[port]: sets bytes +0x158 and +0x157 (fields f44, f43 of the block at
 * +0x114) to 1 and, when byte +0x159 (f45) is 0, calls FUN_a009fed0(port, &block) as a tail call. Twin of
 * FUN_a00a1104. Address word at 0xa00b8664. Source form: f43 before f44 gives the firmware's store order.
 */
struct blk114 { unsigned char d[0x43]; unsigned char f43, f44, f45; unsigned char _46[2]; };
struct mode_rec { unsigned char _000[0x114]; struct blk114 b114; unsigned char _15c[0x34]; };
extern struct mode_rec DAT_a807d7e0[];
extern unsigned char FUN_a009fed0(unsigned char, struct blk114 *);

void FUN_a00a157c(unsigned char port)
{
    DAT_a807d7e0[port].b114.f43 = 1;
    DAT_a807d7e0[port].b114.f44 = 1;
    if (DAT_a807d7e0[port].b114.f45 == 0)
        FUN_a009fed0(port, &DAT_a807d7e0[port].b114);
}
