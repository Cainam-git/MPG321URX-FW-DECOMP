/* FUN_a0079054 (leon2s 0xa0079054-0xa0079460, 1036 bytes), flags -mcpu=v8 -Os -g.
 * u8 port, u8 force; called with force 1 by FSM_EQSCAN_DONE and with force 0 by LINK_STANDBY.
 * force == 1 sets the byte DAT_a80789c0[port]. Runs only when FUN_a00b2064() minus the word DAT_a80789b4[port]
 * is above 100 or force == 1; the word is then set to a new FUN_a00b2064() value.
 * Reads registers 0x1ea0 / 0x1ea4 of the port with FUN_a00a7314(port, reg) into three 15-bit values:
 * e0 = (0x1ea0 bits 8..31 | 0x1ea0 bits 16..23 >> 16) & 0x7fff, e1 = (0x1ea0 bits 24..31 >> 16 | 0x1ea4 bits
 * 0..7) & 0x7fff, e2 = (0x1ea4 bits 8..31 | 0x1ea4 bits 16..23 >> 16) & 0x7fff (each read is its own call).
 * Any value above 0x80: prints "ERROR : %04x, %04x, %04x" with them, writes bits 0..7 of 0x1ea0 = 0x87, 0xc7,
 * 0x87 (FUN_a00a7488(port, reg, keep mask, value)); when byte +8 of the 12-byte record ARR_a807ccc4[port] is 1:
 * DAT_a80789c0[port] = 1, bits 16..23 of 0x1170, 0x1570, 0x1970 = 0x2c, then FUN_a00787f4(port).
 * Otherwise, when that byte +8 is 1 and DAT_a80789c0[port] is 1: clears DAT_a80789c0[port]; for channel k =
 * 0..2 (register base 0x1178 / 0x1578 / 0x1978) RCT = bits 0..3 and CCT = bits 8..23 of the register (two
 * reads each); writes bits 0..3 and 8..23 back from them (keep mask 0xff0000f0), then bits 16..23 of
 * 0x1170, 0x1570, 0x1970 = 0x2f, and prints " Port%d, CHk CCT [0x%04x] RCT [0x%02x]" per channel.
 * Local arrays: RCT bytes initialised {8, 8, 8}, CCT halfwords {0xfff, 0xfff, 0xfff}, error halfwords {0}.
 * Source form: the initialisers of the two arrays are copied by memcpy (FUN_a00b15d8) from read-only data
 * that follows the unreferenced string "DRV_HDMI_EQScan_FSM_Search_EQTable" in the firmware (0xa00b3db0,
 * initialisers at 0xa00b3dd3 and 0xa00b3dd6). That string is declared here with __attribute__((used)) so
 * the read-only data has the firmware layout (the 3-byte RCT initialiser is followed directly by the
 * 2-aligned CCT initialiser); it emits no instructions.
 */
struct Rec12 { unsigned int w0; unsigned int w4; unsigned char b8; unsigned char pad[3]; };
extern struct Rec12 ARR_a807ccc4[];
extern unsigned int DAT_a80789b4[];
extern unsigned char DAT_a80789c0[];
extern void *memcpy(void *, const void *, unsigned int) __asm__("FUN_a00b15d8");
extern int FUN_a0073044(const char *, ...);
extern unsigned int FUN_a00b2064(void);
extern unsigned int FUN_a00a7314(unsigned int, unsigned short);
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);
extern void FUN_a00787f4(unsigned char);

static const char fn_[] __attribute__((used)) = "DRV_HDMI_EQScan_FSM_Search_EQTable";

void FUN_a0079054(unsigned char port, unsigned char force)
{
    unsigned short err[3] = { 0, 0, 0 };
    unsigned char rct[3] = { 8, 8, 8 };
    unsigned short cct[3] = { 0xfff, 0xfff, 0xfff };

    if (force == 1)
        DAT_a80789c0[port] = 1;
    if (FUN_a00b2064() - DAT_a80789b4[port] > 100 || force == 1) {
        DAT_a80789b4[port] = FUN_a00b2064();
        err[0] = ((FUN_a00a7314(port, 0x1ea0) & 0xffffff00) | ((FUN_a00a7314(port, 0x1ea0) & 0xff0000) >> 16)) & 0x7fff;
        err[1] = (((FUN_a00a7314(port, 0x1ea0) & 0xff000000) >> 16) | (FUN_a00a7314(port, 0x1ea4) & 0xff)) & 0x7fff;
        err[2] = ((FUN_a00a7314(port, 0x1ea4) & 0xffffff00) | ((FUN_a00a7314(port, 0x1ea4) & 0xff0000) >> 16)) & 0x7fff;
        if (err[0] > 0x80 || err[1] > 0x80 || err[2] > 0x80) {
            FUN_a0073044("ERROR : %04x, %04x, %04x  \n", err[0], err[1], err[2]);
            FUN_a00a7488(port, 0x1ea0, 0xffffff00, 0x87);
            FUN_a00a7488(port, 0x1ea0, 0xffffff00, 0xc7);
            FUN_a00a7488(port, 0x1ea0, 0xffffff00, 0x87);
            if (ARR_a807ccc4[port].b8 == 1) {
                DAT_a80789c0[port] = 1;
                FUN_a00a7488(port, 0x1170, 0xff00ffff, 0x2c0000);
                FUN_a00a7488(port, 0x1570, 0xff00ffff, 0x2c0000);
                FUN_a00a7488(port, 0x1970, 0xff00ffff, 0x2c0000);
                FUN_a00787f4(port);
            }
        } else if (ARR_a807ccc4[port].b8 == 1 && DAT_a80789c0[port] == 1) {
            DAT_a80789c0[port] = 0;
            rct[0] = FUN_a00a7314(port, 0x1178) & 0xf;
            cct[0] = (FUN_a00a7314(port, 0x1178) & 0xffff00) >> 8;
            rct[1] = FUN_a00a7314(port, 0x1578) & 0xf;
            cct[1] = (FUN_a00a7314(port, 0x1578) & 0xffff00) >> 8;
            rct[2] = FUN_a00a7314(port, 0x1978) & 0xf;
            cct[2] = (FUN_a00a7314(port, 0x1978) & 0xffff00) >> 8;
            FUN_a00a7488(port, 0x1178, 0xff0000f0, (rct[0] & 0xf) | (cct[0] << 8));
            FUN_a00a7488(port, 0x1578, 0xff0000f0, (rct[1] & 0xf) | (cct[1] << 8));
            FUN_a00a7488(port, 0x1978, 0xff0000f0, (rct[2] & 0xf) | (cct[2] << 8));
            FUN_a00a7488(port, 0x1170, 0xff00ffff, 0x2f0000);
            FUN_a00a7488(port, 0x1570, 0xff00ffff, 0x2f0000);
            FUN_a00a7488(port, 0x1970, 0xff00ffff, 0x2f0000);
            FUN_a0073044(" Port%d, CH0 CCT [0x%04x] RCT [0x%02x]\n", port, cct[0], rct[0]);
            FUN_a0073044(" Port%d, CH1 CCT [0x%04x] RCT [0x%02x]\n", port, cct[1], rct[1]);
            FUN_a0073044(" Port%d, CH2 CCT [0x%04x] RCT [0x%02x]\n\n", port, cct[2], rct[2]);
        }
    }
}
