/* leon2s FUN_a00a1c74 @ 0xa00a1c74 (-mcpu=v8 -Os -g)
 * Masks both arguments to 8 bits. If the second is non-zero, calls FUN_a00a2bec, DRV_HDMI_IF_Enable_RxPort(param1,
 * param2 & 0xFF) and FUN_a00a15c8, and tail-calls FUN_a00a0560 with the masked first argument. Otherwise calls
 * FUN_a00a2bec with 0, FUN_a00a0558 and FUN_a00a1638, and tail-calls DRV_HDMI_IF_Enable_RxPort(param1, 0).
 * DRV_HDMI_IF_Enable_RxPort takes two word arguments: the if path sets %o1, the else path clears %i1 before the
 * tail-call restore.
 */
/* FUN_a00a1c74 at 0xa00a1c74 */
extern void FUN_a00a2bec(unsigned int, unsigned int);          /* 0xa00a2bec */
extern void DRV_HDMI_IF_Enable_RxPort(unsigned int, unsigned int); /* 0xa00a16cc */
extern void FUN_a00a15c8(unsigned int);                        /* 0xa00a15c8 */
extern void FUN_a00a0560(unsigned int);                        /* 0xa00a0560 */
extern void FUN_a00a0558(unsigned int);                        /* 0xa00a0558 */
extern void FUN_a00a1638(unsigned int);                        /* 0xa00a1638 */

void FUN_a00a1c74(unsigned int param1, unsigned int param2)
{
    unsigned int l0 = param2 & 0xff;
    unsigned int l1 = param1 & 0xff;

    if (l0 != 0) {
        FUN_a00a2bec(l1, l0);
        DRV_HDMI_IF_Enable_RxPort(param1, l0);
        FUN_a00a15c8(param1);
        FUN_a00a0560(l1);
        return;
    } else {
        FUN_a00a2bec(l1, 0);
        FUN_a00a0558(l1);
        FUN_a00a1638(param1);
        DRV_HDMI_IF_Enable_RxPort(param1, 0);
        return;
    }
}
