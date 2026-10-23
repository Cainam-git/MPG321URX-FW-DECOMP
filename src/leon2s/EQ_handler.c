/* EQ_handler (leon2s 0xa007501c-0xa007517c, 352 bytes), flags -mcpu=v8 -Os -g.
 * When the low byte of FUN_a0074fc4(port) is 1: under bit 1 of _DAT_a8078634 prints "[EQ]: # Port%c EQ Clock
 * Unstable. Set Mute\n" when FUN_a0073520(port) is not 0 and the low byte of FUN_a0096308(port) is 1, then
 * prints "[EQ]: # Port%c Clock Unstable, Restart EQ (%d)\n" with 0x2ed and clears byte +1 of the 0x18-byte
 * record ARR_a807cc64[port]. Then, unless the low byte of FUN_a00735e8(port) is set, clears that byte again
 * when bits 16..19 of FUN_a00a7314(port, 0x1148), (port, 0x1548) or (port, 0x1948) are not all 0xf.
 */
struct sel_rec {
    unsigned char b0;
    unsigned char b1;
    unsigned char _2[0x18 - 2];
};
extern struct sel_rec ARR_a807cc64[];
extern unsigned int _DAT_a8078634;
extern int FUN_a0073044(const char *, ...);
extern int FUN_a0074fc4(unsigned char);
extern unsigned char FUN_a0073520(unsigned char);
extern int FUN_a0096308(int);
extern unsigned int FUN_a00735e8(unsigned char);
extern unsigned int FUN_a00a7314(unsigned int, unsigned short);

void EQ_handler(unsigned char port)
{
    if ((unsigned char)FUN_a0074fc4(port) == 1) {
        if (FUN_a0073520(port) && (unsigned char)FUN_a0096308(port) == 1) {
            if (_DAT_a8078634 & 2)
                FUN_a0073044("[EQ]: # Port%c EQ Clock Unstable. Set Mute\n", (char)(port + 'A'));
        }
        if (_DAT_a8078634 & 2)
            FUN_a0073044("[EQ]: # Port%c Clock Unstable, Restart EQ (%d)\n", (char)(port + 'A'), 0x2ed);
        ARR_a807cc64[port].b1 = 0;
    }
    if ((unsigned char)FUN_a00735e8(port))
        return;
    if ((FUN_a00a7314(port, 0x1148) >> 16 & 0xf) != 0xf || (FUN_a00a7314(port, 0x1548) >> 16 & 0xf) != 0xf
        || (FUN_a00a7314(port, 0x1948) >> 16 & 0xf) != 0xf)
        ARR_a807cc64[port].b1 = 0;
}
