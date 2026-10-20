/* leon2s FUN_a009c794 @ 0xa009c794-0xa009c7e4 (20 words), flags -mcpu=v8 -Os -g.
 * Leaf. p = word +4 (a register-block pointer) of the 0x34-byte record ARR_a807db00[port] (smul 0x34); when
 * the u8 'on' == 1: sibcall FUN_a00a73ac(0x19, p + 0x34), else sibcall FUN_a00a73d4(0x19, p + 0x34). void.
 * The base is ARR_a807db00; the field is a byte pointer at +4.
 */
struct Port34 { unsigned int pad0; unsigned char *ctl; unsigned char pad8[0x2c]; };
extern struct Port34 ARR_a807db00[];
extern void FUN_a00a73ac(int, unsigned char *);
extern void FUN_a00a73d4(int, unsigned char *);

void FUN_a009c794(unsigned char port, unsigned char on)
{
  if (on == 1) {
    FUN_a00a73ac(0x19, ARR_a807db00[port].ctl + 0x34);
    return;
  }
  FUN_a00a73d4(0x19, ARR_a807db00[port].ctl + 0x34);
}
