/* leon2m FUN_a012c16c @ 0xa012c16c (-mcpu=v8 -O2 -g)
 * 
 */
extern unsigned int _DAT_a802cb08;

int FUN_a012c16c(unsigned int param_1)
{
    return (_DAT_a802cb08 >> (param_1 << 2) & 0xf) << 7;
}
