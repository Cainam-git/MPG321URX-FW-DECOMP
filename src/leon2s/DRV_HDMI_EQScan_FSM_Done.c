/* DRV_HDMI_EQScan_FSM_Done (leon2s 0xa007f670-0xa007f798, 296 bytes), flags -mcpu=v8 -Os -g.
 * Under bit 1 of _DAT_a8078634 prints s_a0067bd0 ("[EQ]: \x1b[1m%s: Port%c\n\x1b[m") with the function name and
 * 'A' + port. Stores FUN_a007b2a0(port) and FUN_a007d054(port) in bytes +4 and +5 of the 0x18-byte record
 * ARR_a807cc64[port], calls FUN_a00a73ac(0xb, word +0xc of the 0x34-byte record ARR_a807db00[port & 1] + 0x7c)
 * and FUN_a007f634(port). When DAT_a8078988[port] is 1 it clears it and prints the "Error Handing Occur!!"
 * message. Prints the "(EXIT)" message, clears DAT_a8078990[port] and returns 0.
 * Source form: the record index k = port & 1 is taken from an unsigned int copy of the port (a direct
 * 'port & 1' folds the byte mask away); the first format string is a separate symbol (it is not next to
 * the other two in the firmware).
 */
struct sel_rec {
    unsigned char b[4];
    unsigned char b4;
    unsigned char b5;
    unsigned char _6[0x18 - 6];
};
struct Port34 { unsigned char pad[0xc]; unsigned int base; unsigned char rest[0x34 - 0x10]; };
extern struct sel_rec ARR_a807cc64[];
extern struct Port34 ARR_a807db00[];
extern unsigned char DAT_a8078988[];
extern unsigned char DAT_a8078990[];
extern unsigned int _DAT_a8078634;
extern int FUN_a0073044(const char *, ...);
extern const char s_a0067bd0[];
extern unsigned char FUN_a007b2a0(unsigned char);
extern unsigned char FUN_a007d054(unsigned char);
extern void FUN_a00a73ac(unsigned int, unsigned int);
extern void FUN_a007f634(unsigned int);
static const char fn_[] = "DRV_HDMI_EQScan_FSM_Done";

int DRV_HDMI_EQScan_FSM_Done(unsigned char port)
{
    unsigned int pi = port;
    unsigned char k = pi & 1;

    if (_DAT_a8078634 & 2)
        FUN_a0073044(s_a0067bd0, fn_, (char)(port + 'A'));
    ARR_a807cc64[port].b4 = FUN_a007b2a0(port);
    ARR_a807cc64[port].b5 = FUN_a007d054(port);
    FUN_a00a73ac(0xb, ARR_a807db00[k].base + 0x7c);
    FUN_a007f634(port);
    if (DAT_a8078988[port] == 1) {
        DAT_a8078988[port] = 0;
        if (_DAT_a8078634 & 2)
            FUN_a0073044("[EQ]: \x1b[1mPort%c : Error Handing Occur!!\n\x1b[m", (char)(port + 'A'));
    }
    if (_DAT_a8078634 & 2)
        FUN_a0073044("[EQ]: \x1b[32;1m# Port%c %s (EXIT)\n\x1b[m", (char)(port + 'A'), fn_);
    DAT_a8078990[port] = 0;
    return 0;
}
