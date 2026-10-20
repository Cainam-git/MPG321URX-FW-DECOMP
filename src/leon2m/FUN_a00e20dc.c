/* leon2m FUN_a00e20dc @ 0xa00e20dc-0xa00e2180 (41 words).
 * Calls FUN_a00e05d8(i, addr, mask, v) for i = phy, or for i = 0..2 when phy is 3 or 0xff. Source form: the loop bounds are
 * the two conditional expressions written in the for statement (separate variables give an orcc/subx test instead of
 * the firmware's addx/btst).
 */
extern void FUN_a00e05d8(int, unsigned short, unsigned char, unsigned char);

void FUN_a00e20dc(int phy, unsigned short addr, unsigned char mask, unsigned char v)
{
    int i;

    for (i = (phy == 3 || phy == 0xff) ? 0 : phy; i <= ((phy == 3 || phy == 0xff) ? 2 : phy); i++)
        FUN_a00e05d8(i, addr, mask, v);
}
