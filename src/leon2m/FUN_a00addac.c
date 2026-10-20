/* leon2m FUN_a00addac @ 0xa00addac  MATCH (-mcpu=v8 -O2 -g)
 * m = (byte 0xA802D290+0x17C * 2 + 4) & 0xFF; FUN_a00b3ed0(0, 0, 0, 0); for m == 10 two FUN_a00b32e4 calls
 * (0x792 / 0x3092), otherwise one with m; then FUN_a00b32e4(0, 0, 0x792, 0x12, m, 3, 0). Afterwards the byte
 * becomes (byte + 2) % 3, FUN_a00ad86c(byte, 1) is called and bit 1 of DAT_a802b08e is set. The byte is read again
 * for the write-back, which produces the fresh load, the add of 2 and the magic-number division.
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

void FUN_a00addac(void)
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
    
    DAT_a802d290.b17c = (DAT_a802d290.b17c + 2) % 3;
    FUN_a00ad86c(DAT_a802d290.b17c, 1);
    DAT_a802b08e = DAT_a802b08e | 2;
}
