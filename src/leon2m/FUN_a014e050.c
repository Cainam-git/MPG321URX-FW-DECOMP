/* FUN_a014e050: mode == 1: FUN_a01393f0(0x2a, 0, 0x2040); other modes: FUN_a0139b90(). Then FUN_a013a98c(mode)
 * and a tail call FUN_a0138edc(mode). Callers: FUN_a00db054. (GCC loads 0x2a / 0 / 0x2040 into the argument
 * registers before the test, so FUN_a0139b90 is entered with the same registers.)
 */
extern void FUN_a01393f0(unsigned int, unsigned int, unsigned short);
extern void FUN_a0139b90(void);
extern void FUN_a013a98c(unsigned short arg);
extern void FUN_a0138edc(unsigned char mode);

void FUN_a014e050(unsigned char mode)
{
    if (mode == 1)
        FUN_a01393f0(0x2a, 0, 0x2040);
    else
        FUN_a0139b90();
    FUN_a013a98c(mode);
    FUN_a0138edc(mode);
}
