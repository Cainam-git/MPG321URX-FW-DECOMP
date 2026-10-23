/* leon2m FUN_a00adc98 @ 0xa00adc98 (-mcpu=v8 -O2 -g)
 * Same code as FUN_a00ae288 except the last field update: m = (b17c * 2 + 4) & 0xff (b17c = byte 0xA802D290 + 0x17c);
 * FUN_a00b3ed0(0, 0, 0, 0); m == 10 -> FUN_a00b32e4(0, 0, 0x792, 3, 10, 2, 0) and FUN_a00b32e4(1, 0, 0x3092, 3, 0xc, 1,
 * 0x11), else FUN_a00b32e4(0, 0, 0x792, 3, m, 3, 0); then FUN_a00b32e4(0, 0, 0x792, 0x12, m, 3, 0);
 * b17c = (b17c + 1) % 3 (FUN_a00ae288: + 2); FUN_a00ad86c(b17c, 1); byte 0xA802B08E |= 2.
 */
struct St {
    unsigned char pad[0x17c];
    unsigned char b17c;
};
extern struct St DAT_a802d290;
extern unsigned char DAT_a802b08e;
extern void FUN_a00ad86c(unsigned char, unsigned char);
extern void FUN_a00b32e4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00b3ed0(unsigned char, unsigned char, unsigned int, unsigned int);

void FUN_a00adc98(void)
{
    unsigned char m;
    
    m = (DAT_a802d290.b17c * 2 + 4) & 0xff;
    FUN_a00b3ed0(0, 0, 0, 0);
    
    if (m == 10) {
        FUN_a00b32e4(0, 0, 0x792, 3, 10, 2, 0);
        FUN_a00b32e4(1, 0, 0x3092, 3, 0xc, 1, 0x11);
    } else {
        FUN_a00b32e4(0, 0, 0x792, 3, m, 3, 0);
    }
    
    FUN_a00b32e4(0, 0, 0x792, 0x12, m, 3, 0);
    
    DAT_a802d290.b17c = (DAT_a802d290.b17c + 1) % 3;
    FUN_a00ad86c(DAT_a802d290.b17c, 1);
    DAT_a802b08e = DAT_a802b08e | 2;
}
