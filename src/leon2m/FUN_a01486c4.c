/* FUN_a01486c4: walks the eight bits i = 0..7 of the constant mask 0x55. en != 0: for each bit set in the mask
 * calls FUN_a0133e7c(1 << i, FUN_a01243c8(i)), for each clear bit FUN_a0133e58(1 << i). en == 0: calls
 * FUN_a0133e58(1 << i) for each bit set in the mask. No direct callers were found (the address may be reached
 * through a pointer). Built with -msoft-float (the register choice of the loop set-up depends on it).
 */
extern unsigned char FUN_a01243c8(unsigned int i);
extern void FUN_a0133e58(unsigned char m);
extern void FUN_a0133e7c(unsigned char m, unsigned char v);

void FUN_a01486c4(unsigned char en)
{
    unsigned char i;

    if (en) {
        for (i = 0; i < 8; i++) {
            if ((0x55 >> i) & 1)
                FUN_a0133e7c(1 << i, FUN_a01243c8(i));
            else
                FUN_a0133e58(1 << i);
        }
    } else {
        for (i = 0; i < 8; i++) {
            if ((0x55 >> i) & 1)
                FUN_a0133e58(1 << i);
        }
    }
}
