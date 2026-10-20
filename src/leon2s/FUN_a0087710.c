/* leon2s FUN_a0087710 @ 0xa0087710  MATCH (-mcpu=v8 -Os -g, twin)
 * Twin of FUN_a00876ec: same code, constants swapped; byte-exact.
 * See FUN_a00876ec for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned char ARR_a807a928[];

unsigned char FUN_a0087710(unsigned int param_1)
{
    return ARR_a807a928[(param_1 & 0xff) * 40 + 0x14];
}
