/* leon2m FUN_a0105c0c @ 0xa0105c0c  (-mcpu=v8 -O3 -g)
 *
 * Installs the transformed 0x58-byte row: stores the 0x58-byte row passed by value (from FUN_a0141840) at 0xA802D6A8
 * and points DAT_a802d6a4 at it. Every limit/timing reader (FUN_a01070b4, FUN_a008380c, FUN_a0121f58,
 * FUN_a01227f0, FUN_a0105150, FUN_a0106d64, FUN_a01062e0, FUN_a0107e44 ...) reads the active row through that
 * pointer. FW.012 vs FW.021: only addresses moved (tools/fwdiff.py: 10 differing words, all global addresses).
 */
struct PanelRow { unsigned long long q[11]; };
extern struct PanelRow DAT_a802d6a8;
extern struct PanelRow *DAT_a802d6a4;
void FUN_a0105c0c(struct PanelRow r)
{
    DAT_a802d6a8 = r;
    DAT_a802d6a4 = &DAT_a802d6a8;
}
