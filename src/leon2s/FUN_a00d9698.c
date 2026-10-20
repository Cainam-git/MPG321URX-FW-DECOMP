/* leon2s FUN_a00d9698 @ 0xa00d9698-0xa00d97bc (292 bytes, 73 words)
 * Flags: -mcpu=v8 -Os -g.
 * Code facts: void(void) message dispatcher. v = (u8)FUN_a00d95e4(). A switch (signed compare tree, root 0x20)
 * on 1, 2, 0x10, 0x11, 0x14, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25 and 0x38 sibcalls one handler each. The
 * handlers take NO argument: their entries never read %i0, and the fw 'call; restore' leaves v in %o0 only as a
 * left-over. The draft passed (v, param_2...), and constant args give 'restore %g0, K, %o0'. The default
 * sibcalls FUN_a00d9474(v, 4, 0). The case source order is ascending (the stub order in the fw). No aids.
 */
extern void FUN_a00d7e6c(void);
extern void FUN_a00d82c8(void);
extern void FUN_a00d8300(void);
extern void FUN_a00d84f4(void);
extern void FUN_a00d8714(void);
extern void FUN_a00d87fc(void);
extern void FUN_a00d8b90(void);
extern void FUN_a00d8d20(void);
extern void FUN_a00d8f58(void);
extern void FUN_a00d8fdc(void);
extern void FUN_a00d904c(void);
extern void FUN_a00d90dc(void);
extern void FUN_a00d9474(unsigned char, int, int);
extern unsigned int FUN_a00d95e4(void);

void FUN_a00d9698(void)
{
    unsigned char v = FUN_a00d95e4();

    switch (v) {
    case 0x1: FUN_a00d7e6c(); break;
    case 0x2: FUN_a00d82c8(); break;
    case 0x10: FUN_a00d8300(); break;
    case 0x11: FUN_a00d84f4(); break;
    case 0x14: FUN_a00d8714(); break;
    case 0x20: FUN_a00d87fc(); break;
    case 0x21: FUN_a00d8b90(); break;
    case 0x22: FUN_a00d8d20(); break;
    case 0x23: FUN_a00d8f58(); break;
    case 0x24: FUN_a00d8fdc(); break;
    case 0x25: FUN_a00d904c(); break;
    case 0x38: FUN_a00d90dc(); break;
    default: FUN_a00d9474(v, 4, 0); break;
    }
}
