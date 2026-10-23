/* leon2m FUN_a012c16c @ 0xa012c16c (-mcpu=v8 -O2 -g)
 * Returns nibble p of word 0xA802CB08 (bits 4p..4p+3) shifted left by 7.
 */
extern unsigned int _DAT_a802cb08;

int FUN_a012c16c(unsigned int param_1)
{
    return (_DAT_a802cb08 >> (param_1 << 2) & 0xf) << 7;
}
