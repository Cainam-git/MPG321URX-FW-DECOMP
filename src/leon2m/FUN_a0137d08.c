/* leon2m FUN_a0137d08 @ 0xa0137d08  MATCH (-mcpu=v8 -O2 -g)
 * Packs the five byte parameters into a local array and calls FUN_a01370dc(0x2E, 5, local, 1).
 */
extern int FUN_a01370dc();

void FUN_a0137d08(unsigned char param_1, unsigned char param_2, unsigned char param_3,
                  unsigned char param_4, unsigned char param_5)
{
    unsigned char local[5] = {param_1, param_2, param_3, param_4, param_5};
    FUN_a01370dc(0x2e, 5, local, 1);
}
