/* leon2m FUN_a002992c @ 0xa002992c-0xa0029964 (14 words).
 * FUN_a002992c(on): writes 0x10 to the register 0x9f000090 through FUN_a002c25c when on is not 0, otherwise 0
 * (tail calls). Each arm has its own call.
 */
extern void FUN_a002c25c(unsigned int addr, unsigned int value);

void FUN_a002992c(unsigned char on)
{
    if (on != 0) {
        FUN_a002c25c(0x9f000090, 0x10);
        return;
    }
    FUN_a002c25c(0x9f000090, 0);
}
