/* FUN_a00af690 (leon2s 0xa00af690-0xa00af764, 212 bytes), flags -mcpu=v8 -Os -g.
 * Unless *st == 5 and bit 0 of FUN_a00a6bb8(port, 0x229) is set, clears the byte DAT_a8079338[port] and stores
 * FUN_a00b2064() in the word DAT_a807932c[port]. Otherwise, when FUN_a00b2064() minus the stored word exceeds
 * 0x28, stores a new FUN_a00b2064() value and sets the byte to 1 when FUN_a00aceec(port) is in 301..1929
 * (unsigned short compare of value - 301 with 0x65c), else to 0. Returns the byte DAT_a8079338[port].
 * Source forms: port is a raw unsigned int parameter (repeated and 0xff); the reset arm is written first
 * with a negated || condition.
 */
extern unsigned char DAT_a8079338[];
extern unsigned int DAT_a807932c[];
extern unsigned int FUN_a00a6bb8(unsigned char, unsigned short);
extern unsigned int FUN_a00b2064(void);
extern unsigned short FUN_a00aceec(unsigned char);

unsigned char FUN_a00af690(unsigned char *st, unsigned int port)
{
    if (*st != 5 || !(FUN_a00a6bb8(port, 0x229) & 1)) {
        DAT_a8079338[(unsigned char)port] = 0;
        DAT_a807932c[(unsigned char)port] = FUN_a00b2064();
    } else if (FUN_a00b2064() - DAT_a807932c[(unsigned char)port] > 0x28) {
        DAT_a807932c[(unsigned char)port] = FUN_a00b2064();
        if ((unsigned short)(FUN_a00aceec(port) - 301) <= 0x65c)
            DAT_a8079338[(unsigned char)port] = 1;
        else
            DAT_a8079338[(unsigned char)port] = 0;
    }
    return DAT_a8079338[(unsigned char)port];
}
