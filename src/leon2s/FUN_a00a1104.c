/* FUN_a00a1104 (leon2s 0xa00a1104-0xa00a1150, 76 bytes), flags -mcpu=v8 -Os -g.
 * For the 400-byte record DAT_a807d7e0[port]: sets bytes +0x182 and +0x181 (fields f20, f1f of the block at
 * +0x162) to 1 and, when byte +0x183 (f21) is 0, calls FUN_a00a0268(port, &block) as a tail call. Same record
 * layout as DRV_HDMI_ModeDetect_FSM_Complete. Address word at 0xa00b86d4. Source form: f1f is assigned
 * before f20, which gives the firmware's store order (+0x182 first).
 */
struct blk162 { unsigned char d[0x1f]; unsigned char f1f, f20, f21; };
struct mode_rec { unsigned char _000[0x162]; struct blk162 b162; unsigned char _184[0xc]; };
extern struct mode_rec DAT_a807d7e0[];
extern unsigned char FUN_a00a0268(unsigned char, struct blk162 *);

void FUN_a00a1104(unsigned char port)
{
    DAT_a807d7e0[port].b162.f1f = 1;
    DAT_a807d7e0[port].b162.f20 = 1;
    if (DAT_a807d7e0[port].b162.f21 == 0)
        FUN_a00a0268(port, &DAT_a807d7e0[port].b162);
}
