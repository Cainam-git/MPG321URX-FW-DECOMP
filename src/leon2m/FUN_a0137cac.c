/* leon2m FUN_a0137cac @ 0xa0137cac (-mcpu=v8 -O2 -g)
 * Sends {p1, p2, 0, 0} with FUN_a01370dc(0x2c, 4, buf, 0): a 4-byte stack buffer whose first two bytes are the two
 * parameters and the rest zero (initialiser list). Same form as FUN_a0137aec / FUN_a0137c1c (message code 0x2c here,
 * last argument 0).
 */
extern int FUN_a01370dc();

void FUN_a0137cac(unsigned char param_1, unsigned char param_2)
{
    unsigned char local_10[4] = {param_1, param_2};
    FUN_a01370dc(0x2c, 4, local_10, 0);
}
