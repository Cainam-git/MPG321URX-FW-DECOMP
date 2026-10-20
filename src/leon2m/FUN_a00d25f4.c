/* leon2m FUN_a00d25f4 @ 0xa00d25f4  tool command: full-screen fill colour / panel Inspection Pattern (hand; -mcpu=v8 -O3 -g, also -msoft-float)
 *
 * cmd[6] == 0: cmd[7] == 1 -> port-0 fill colour on, white (FUN_a0145fe8(0, 0xff, 0xff, 0xff, 1)),
 *              FUN_a0145fc0(0x100, 0x100, 0x100), FUN_a0143804(0x3ff), FUN_a00d7de0() with settings byte
 *              DAT_a802d29a (DAT_a802d290[0xa]) kept across the call;
 *              cmd[7] == 0 -> FUN_a0148268(0, 1), FUN_a0148268(1, 1), FUN_a00d8cd4(), FUN_a00d7de0(), FUN_a00d9764().
 * cmd[6] == 1: cmd[7] == 0 -> OLED Inspection Mode off (FUN_a01275b0(0));
 *              cmd[7] == 1..6 -> Inspection Mode on + Inspection Pattern cmd[7]; cmd[7] == 7 -> on + pattern 0.
 * Always returns 0xE0 (ack). The panel's own test patterns are reached only from here
 * and the factory menu.
 */
extern void FUN_a0145fe8();
extern void FUN_a0145fc0(unsigned short a, unsigned short b, unsigned short c);
extern void FUN_a0143804(unsigned short a);
extern void FUN_a00d7de0(void);
extern void FUN_a0148268(int a, int b);
extern void FUN_a00d8cd4(void);
extern void FUN_a00d9764(void);
extern void FUN_a01275b0(unsigned char on);
extern void FUN_a0127724(unsigned char pat);
extern unsigned char DAT_a802d290[];

int FUN_a00d25f4(unsigned char *cmd)
{
    if (cmd[6] == 0) {
        if (cmd[7] == 1) {
            unsigned char b;
            FUN_a0145fe8(0, 0xff, 0xff, 0xff, 1);
            FUN_a0145fc0(0x100, 0x100, 0x100);
            FUN_a0143804(0x3ff);
            b = DAT_a802d290[0xa];
            FUN_a00d7de0();
            DAT_a802d290[0xa] = b;
        } else if (cmd[7] == 0) {
            FUN_a0148268(0, 1);
            FUN_a0148268(1, 1);
            FUN_a00d8cd4();
            FUN_a00d7de0();
            FUN_a00d9764();
        }
    } else if (cmd[6] == 1) {
        unsigned char c = cmd[7];
        if (c == 0) {
            FUN_a01275b0(0);
        } else if (c == 1) {
            FUN_a01275b0(1); FUN_a0127724(1);
        } else if (c == 2) {
            FUN_a01275b0(1); FUN_a0127724(2);
        } else if (c == 3) {
            FUN_a01275b0(1); FUN_a0127724(3);
        } else if (c == 4) {
            FUN_a01275b0(1); FUN_a0127724(4);
        } else if (c == 5) {
            FUN_a01275b0(1); FUN_a0127724(5);
        } else if (c == 6) {
            FUN_a01275b0(1); FUN_a0127724(6);
        } else if (c == 7) {
            FUN_a01275b0(1); FUN_a0127724(0);
        }
    }
    return 0xe0;
}
