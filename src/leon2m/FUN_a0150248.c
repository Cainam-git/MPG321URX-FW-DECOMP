/* leon2m FUN_a0150248
 * If byte 0xA802CC86 is non-zero: when n (unsigned short) is at most the halfword 0xA802A4A2, calls
 * FUN_a011dd9c(0x18, 0) and sets the halfword counter 0xA802CC88 to 1000; otherwise counts 0xA802CC88 down by one
 * per call, and once it is 0 calls FUN_a011dd9c(0x18, halfword 0xA802A4B0) instead. Called by FUN_a0153018.
 */
extern unsigned char DAT_a802cc86;
extern unsigned short DAT_a802cc88;
extern unsigned short DAT_a802a4a2;
extern unsigned short DAT_a802a4b0;
extern void FUN_a011dd9c(unsigned char a, unsigned short b);

void FUN_a0150248(unsigned short n)
{
    if (DAT_a802cc86 != 0) {
        if (n > DAT_a802a4a2) {
            if (DAT_a802cc88 != 0)
                DAT_a802cc88--;
            else
                FUN_a011dd9c(0x18, DAT_a802a4b0);
        } else {
            FUN_a011dd9c(0x18, 0);
            DAT_a802cc88 = 1000;
        }
    }
}
