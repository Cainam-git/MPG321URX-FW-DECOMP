/* leon2m FUN_a0137d6c @ 0xa0137d6c (-mcpu=v8 -O2 -g)
 * Calls FUN_a01370dc(0x74, 1, buf, 1) with a 4-byte local buffer whose first byte is param_1. The initializer
 * {param_1} produces the firmware's clear of the whole word followed by a single byte store.
 */
extern int FUN_a01370dc();

void FUN_a0137d6c(unsigned char param_1)
{
    unsigned char local[4] = {param_1};
    FUN_a01370dc(0x74, 1, local, 1);
}
