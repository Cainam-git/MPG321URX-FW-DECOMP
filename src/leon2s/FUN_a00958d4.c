/* leon2s FUN_a00958d4 @ 0xa00958d4-0xa0095c30 (215 words), flags -mcpu=v8 -Os -g.
 * void (u8 port). d = ARR_a807d580[port] (7-word records, bit-fields). When FUN_a0091a10(port) and bit 12 of
 * word 5 are set: unless FUN_a0091bac(port), prints the steps "(1)" .. "(9)" and calls FUN_a00950a0(port, n)
 * with n = 0, 3, (bit 29 of word 0 ? 1 : 2), (bit 4 ? 6 : 5), 0x11, then 0xa ("TMDS Mode") when bit 4 is clear,
 * else 0xc ("DSC Enable", bit 3 set; "DSC Disable" otherwise) and 0xb ("FRL Mode"), then 8, 7; when bit 13 of
 * word 5 is set prints "Update FRL Rate" and calls FUN_a0094fb0(byte +0x15) and FUN_a00919b0(port);
 * FUN_a009434c(port, bit 5 of word 0); when bit 30 is clear prints "(8)" and FUN_a00950a0(port, 4);
 * FUN_a00a80cc(port, 0, 0x123, 8, bit 4 ? 1 : 0); prints "(9)", FUN_a0094c54(port), FUN_a00950a0(port, 0xf),
 * (port, 0xd), FUN_a0091b3c(port). In both FUN_a0091bac cases it ends with the sibling call
 * FUN_a00a9870(port, byte +0x17) when bit 29 of word 0 is set. Otherwise, when FUN_a0091bac(port) is set:
 * FUN_a00950a0(port, 9) and the sibling call FUN_a0091578(port).
 * Source form: the FUN_a0091bac test as 'if (!...) { ... } else { ... }' with the bit-29 call in both arms;
 * the two-value FUN_a00950a0 arguments as separate calls with the clear-bit arm first.
 */
struct Dst {
    unsigned int a31 : 1;
    unsigned int a30 : 1;
    unsigned int a29 : 1;
    unsigned int a24 : 5;
    unsigned int a16 : 8;
    unsigned int a8 : 8;
    unsigned int a7 : 1;
    unsigned int a6 : 1;
    unsigned int a5 : 1;
    unsigned int a4 : 1;
    unsigned int a3 : 1;
    unsigned int a2 : 1;
    unsigned int a1 : 1;
    unsigned int a0 : 1;
    unsigned int w1;
    unsigned int w2;
    unsigned int w3;
    unsigned int w4;
    unsigned int e24 : 8;
    unsigned int e16 : 8;
    unsigned int e15 : 1;
    unsigned int e14 : 1;
    unsigned int e13 : 1;
    unsigned int e12 : 1;
    unsigned int e8 : 4;
    unsigned int e0 : 8;
    unsigned int w6;
};
extern struct Dst ARR_a807d580[];
extern int FUN_a0073044(const char *, ...);
extern int FUN_a00734c4(const char *);
extern unsigned char FUN_a0091a10(unsigned char);
extern unsigned char FUN_a0091bac(unsigned char);
extern void FUN_a00950a0(unsigned char, unsigned char);
extern void FUN_a0094fb0(unsigned char);
extern void FUN_a00919b0(unsigned char);
extern void FUN_a009434c(unsigned char, unsigned char);
extern void FUN_a00a80cc(unsigned char, unsigned char, unsigned short, unsigned int, unsigned char);
extern void FUN_a0094c54(unsigned char);
extern void FUN_a0091b3c(unsigned char);
extern void FUN_a00a9870(unsigned char, unsigned char);
extern void FUN_a0091578(unsigned char);

void FUN_a00958d4(unsigned char port)
{
    if (FUN_a0091a10(port) && ARR_a807d580[port].e12) {
        if (!FUN_a0091bac(port)) {
            FUN_a0073044("\x1b[0;34m[HDMI_TX]: (1) Port%d: Input Source Selection \n", port);
            FUN_a00950a0(port, 0);
            FUN_a00950a0(port, 3);
            FUN_a0073044("\x1b[0;34m[HDMI_TX]: (2) Port%d: Packet Configuration \n", port);
            if (!ARR_a807d580[port].a29)
                FUN_a00950a0(port, 2);
            else
                FUN_a00950a0(port, 1);
            if (ARR_a807d580[port].e13) {
                FUN_a0073044("\x1b[0;34m[HDMI_TX]: -- Port%d: Update FRL Rate !!! --\n", port);
                FUN_a0094fb0(ARR_a807d580[port].e16);
                FUN_a00919b0(port);
            }
            FUN_a0073044("\x1b[0;34m[HDMI_TX]: (3) Port%d: Clock Source Configuration \n", port);
            if (!ARR_a807d580[port].a4)
                FUN_a00950a0(port, 5);
            else
                FUN_a00950a0(port, 6);
            FUN_a0073044("\x1b[0;34m[HDMI_TX]: (4) Port%d: HTX Link_Input_Timing \n", port);
            FUN_a00950a0(port, 0x11);
            FUN_a0073044("\x1b[0;34m[HDMI_TX]: (5) Port%d: HTX PHY+Link Configuration \n", port);
            if (!ARR_a807d580[port].a4) {
                FUN_a00734c4("\x1b[0m\t\t - TMDS Mode \n");
                FUN_a00950a0(port, 0xa);
            } else {
                if (ARR_a807d580[port].a3) {
                    FUN_a00734c4("\x1b[0m\t\t - DSC Enable \n");
                    FUN_a00950a0(port, 0xc);
                } else
                    FUN_a00734c4("\x1b[0m\t\t - DSC Disable \n");
                FUN_a00734c4("\x1b[0m\t\t - FRL Mode \n");
                FUN_a00950a0(port, 0xb);
            }
            FUN_a0073044("\x1b[0;34m[HDMI_TX]: (6) Port%d: HTX PHY Power ON \n", port);
            FUN_a00950a0(port, 8);
            FUN_a0073044("\x1b[0;34m[HDMI_TX]: (7) Port%d: HTX PHY CLK Configuration \n", port);
            FUN_a00950a0(port, 7);
            FUN_a009434c(port, ARR_a807d580[port].a5);
            if (!ARR_a807d580[port].a30) {
                FUN_a0073044("\x1b[0;34m[HDMI_TX]: (8) Port%d: Packet Enable/Disable \n", port);
                FUN_a00950a0(port, 4);
            }
            if (ARR_a807d580[port].a4)
                FUN_a00a80cc(port, 0, 0x123, 8, 1);
            else
                FUN_a00a80cc(port, 0, 0x123, 8, 0);
            FUN_a0073044("\x1b[0;34m[HDMI_TX]: (9) Port%d: Check PSTABLE/Timing \n", port);
            FUN_a0094c54(port);
            FUN_a00950a0(port, 0xf);
            FUN_a00950a0(port, 0xd);
            FUN_a0091b3c(port);
            if (ARR_a807d580[port].a29)
                FUN_a00a9870(port, ARR_a807d580[port].e0);
        } else {
            if (ARR_a807d580[port].a29)
                FUN_a00a9870(port, ARR_a807d580[port].e0);
        }
        return;
    }
    if (FUN_a0091bac(port)) {
        FUN_a00950a0(port, 9);
        FUN_a0091578(port);
    }
}
