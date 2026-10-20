/* leon2m FUN_a0154580 @ 0xa0154580..0xa015463c (47 words)  main-loop helper that ends with the liveness-ring relay
 * ( -mcpu=v8 -O0 -g: -O1 gives 38 %: this unit was
 * built without optimisation, ldub + and 0xff and or-formed addresses). Called twice from the main-loop task
 * FUN_a0153018 (0xA015326C, 0xA015359C).
 * What the code does (code facts): if byte 0xA802A4C0 == 1: byte 0xA802CF9C = FUN_a011cf88(), byte 0xA802CF9D =
 * FUN_a011d0a8(), FUN_a01544d4(), then 0xA802A4C0 = 0 (a one-shot request flag). If word 0xA802CF98 != 0 and the
 * high nibble of 0xA802CF9C is 8: FUN_a0154574(). Then, unconditionally, func_0x4008ced8 = FUN_a002ced8 (relay
 * 8051 F204 -> F208 and F240 -> F244 via 0xCF03C810 -> C820, C900 -> C910). Returns 0.
 * Liveness: this is the regular (per main-loop pass) source of the Big chip's liveness token; if main() never
 * reaches its loop, only the start-up callers of FUN_a002ced8 (FUN_a002b3e4, FUN_a014512c) relay, and after a halt
 * nothing does.
 */
extern unsigned char DAT_a802a4c0, DAT_a802cf9c, DAT_a802cf9d;
extern unsigned int DAT_a802cf98;
extern unsigned char FUN_a011cf88(void);
extern unsigned char FUN_a011d0a8(void);
extern void FUN_a01544d4(void);
extern void FUN_a0154574(void);
extern void func_0x4008ced8(void);

int FUN_a0154580(void)
{
    if (DAT_a802a4c0 == 1) {
        DAT_a802cf9c = FUN_a011cf88();
        DAT_a802cf9d = FUN_a011d0a8();
        FUN_a01544d4();
        DAT_a802a4c0 = 0;
    }
    if (DAT_a802cf98 != 0 && (DAT_a802cf9c & 0xf0) == 0x80)
        FUN_a0154574();
    func_0x4008ced8();
    return 0;
}
