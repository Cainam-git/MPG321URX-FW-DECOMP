/* leon2m FUN_a013480c @ 0xa013480c (-mcpu=v8 -O2 -g)
 * Writes one zero word with func_0x4008c5f8(0, p, &w, 1) (portal 0, offset p, 1 word; the write routine named in
 * FUN_a0134de0).
 */
extern int func_0x4008c5f8();

void FUN_a013480c(unsigned char param_1)
{
    unsigned int local_c;
    local_c = 0;
    func_0x4008c5f8(0, param_1, &local_c, 1);
}
