/* FUN_a014a0d8: stores bit 0 of on into bit 24 of the RAM word DAT_a802e3d0, calls FUN_a0151aa4(0x10, 1) and
 * then tail-calls FUN_a012b328(0, bit 24 of DAT_a802e3d0) (read back). Caller: FUN_a00d5f3c.
 * Bit 24 is a 1-bit bit-field (read back with ldub of byte 0 and & 1).
 */
struct E3d0 { unsigned int b31_25 : 7, b24 : 1, rest : 24; };
extern struct E3d0 DAT_a802e3d0;
extern void FUN_a0151aa4(unsigned int, unsigned int);
extern void FUN_a012b328(unsigned char ch, unsigned char on);

void FUN_a014a0d8(unsigned int on)
{
    DAT_a802e3d0.b24 = on;
    FUN_a0151aa4(0x10, 1);
    FUN_a012b328(0, DAT_a802e3d0.b24);
}
