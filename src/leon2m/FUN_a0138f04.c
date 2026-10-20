/* leon2m FUN_a0138f04 @ 0xa0138f04  MATCH (-mcpu=v8 -O2 -g, twin)
 * Twin of FUN_a0138eb4: same code, constants swapped; byte-exact.
 * See FUN_a0138eb4 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern int FUN_a01370dc();

void FUN_a0138f04(void)
{
    unsigned char buf[4] = {0, 0, 0, 0};
    FUN_a01370dc(0xa2, 4, buf, 0);
}
