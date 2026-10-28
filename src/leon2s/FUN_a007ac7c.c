/* leon2s FUN_a007ac7c @ 0xa007ac7c-0xa007aca0 (-mcpu=v8 -Os -g)
 * void (u8 port). Calls FUN_a007a708(port) and FUN_a007abbc(port), then tail-calls FUN_a0079e00(port).
 * The port byte is masked once at entry ('and %i0,0xff,%i0') and passed unchanged to all three routines.
 * All three callees take an unsigned char port, as in their own definitions.
 */
extern void FUN_a007a708(unsigned char);
extern void FUN_a007abbc(unsigned char);
extern void FUN_a0079e00(unsigned char);

void FUN_a007ac7c(unsigned char port)
{
    FUN_a007a708(port);
    FUN_a007abbc(port);
    FUN_a0079e00(port);
}
