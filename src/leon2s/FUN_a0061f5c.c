/* FUN_a0061f5c (leon2s 0xa0061f5c-0xa0062308, 940 bytes), flags -mcpu=v8 -Os -g.
 * void (unsigned char mode). Calls FUN_a00a67b8(0 / 1, 0x7e, 0x80, 0) and FUN_a00a6aa0(0 / 1, 0x9c9, 1, 0), then
 * per mode sets the byte DAT_a8078a39 = mode, the function pointers DAT_a807cd74 / DAT_a807cd70 / DAT_a807cd7c /
 * DAT_a807cd78, the byte DAT_a8078a38 and the halfwords / byte DAT_a8076274, DAT_a8076272, DAT_a8076270,
 * DAT_a807626e, DAT_a807626c, DAT_a807626a:
 * modes 0 / 1: FUN_a00a657c, FUN_a00a65c4 (cd70 and cd7c), FUN_a00a67b8, a38 = mode, 0x7c, 0x80, 0x263..0x266;
 * modes 2 / 3: FUN_a00a69b4, FUN_a00a69fc (cd70 and cd7c), FUN_a00a6aa0, a38 = mode - 2, 0x9c8, 1, 0x404..0x407;
 * modes 0..3 then call DAT_a807cd78(DAT_a8078a38, 0x7e / 0x9c9, ..) and DAT_a807cd78(DAT_a8078a38, 0x79 / 0x391,
 * ..) with last argument 1. Modes 4 / 5: cd74 = FUN_a0061eb4, a38 = mode - 4, 6274 = 5, 6272 = 0x20.
 * Source form: cd70 and cd7c are set in one chained assignment 'DAT_a807cd70 = DAT_a807cd7c = f;'.
 */
typedef unsigned char (*rd_fn)(unsigned char, unsigned short);
typedef void (*wr_fn)(unsigned int, unsigned short, unsigned int);
typedef void (*mod_fn)(unsigned char, unsigned short, unsigned char, unsigned char);

extern rd_fn DAT_a807cd74;
extern wr_fn DAT_a807cd70;
extern wr_fn DAT_a807cd7c;
extern mod_fn DAT_a807cd78;
extern unsigned short DAT_a8076274;
extern unsigned char DAT_a8076272;
extern unsigned short DAT_a8076270;
extern unsigned short DAT_a807626e;
extern unsigned short DAT_a807626c;
extern unsigned short DAT_a807626a;
extern unsigned char DAT_a8078a38;
extern unsigned char DAT_a8078a39;
extern void FUN_a00a67b8(unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a00a6aa0(unsigned char, unsigned short, unsigned char, unsigned char);
extern unsigned int FUN_a00a657c(unsigned int, unsigned short);
extern void FUN_a00a65c4(unsigned int, unsigned short, unsigned int);
extern unsigned int FUN_a00a69b4(unsigned int, unsigned short);
extern void FUN_a00a69fc(unsigned int, unsigned short, unsigned int);
extern int FUN_a0061eb4(unsigned char, unsigned int);

void FUN_a0061f5c(unsigned char mode)
{
    FUN_a00a67b8(0, 0x7e, 0x80, 0);
    FUN_a00a67b8(1, 0x7e, 0x80, 0);
    FUN_a00a6aa0(0, 0x9c9, 1, 0);
    FUN_a00a6aa0(1, 0x9c9, 1, 0);
    if (mode == 0) {
        DAT_a8078a39 = 0;
        DAT_a807cd74 = (rd_fn)FUN_a00a657c;
        DAT_a807cd70 = DAT_a807cd7c = FUN_a00a65c4;
        DAT_a807cd78 = FUN_a00a67b8;
        DAT_a8078a38 = 0;
        DAT_a8076274 = 0x7c;
        DAT_a8076272 = 0x80;
        DAT_a8076270 = 0x263;
        DAT_a807626e = 0x264;
        DAT_a807626c = 0x265;
        DAT_a807626a = 0x266;
        DAT_a807cd78(DAT_a8078a38, 0x7e, 0x80, 1);
        DAT_a807cd78(DAT_a8078a38, 0x79, 0x80, 1);
    } else if (mode == 1) {
        DAT_a8078a39 = 1;
        DAT_a807cd74 = (rd_fn)FUN_a00a657c;
        DAT_a807cd70 = DAT_a807cd7c = FUN_a00a65c4;
        DAT_a807cd78 = FUN_a00a67b8;
        DAT_a8078a38 = 1;
        DAT_a8076274 = 0x7c;
        DAT_a8076272 = 0x80;
        DAT_a8076270 = 0x263;
        DAT_a807626e = 0x264;
        DAT_a807626c = 0x265;
        DAT_a807626a = 0x266;
        DAT_a807cd78(DAT_a8078a38, 0x7e, 0x80, 1);
        DAT_a807cd78(DAT_a8078a38, 0x79, 0x80, 1);
    } else if (mode == 2) {
        DAT_a8078a39 = 2;
        DAT_a807cd74 = (rd_fn)FUN_a00a69b4;
        DAT_a807cd70 = DAT_a807cd7c = FUN_a00a69fc;
        DAT_a807cd78 = FUN_a00a6aa0;
        DAT_a8078a38 = 0;
        DAT_a8076274 = 0x9c8;
        DAT_a8076272 = 1;
        DAT_a8076270 = 0x404;
        DAT_a807626e = 0x405;
        DAT_a807626c = 0x406;
        DAT_a807626a = 0x407;
        DAT_a807cd78(DAT_a8078a38, 0x9c9, 1, 1);
        DAT_a807cd78(DAT_a8078a38, 0x391, 1, 1);
    } else if (mode == 3) {
        DAT_a8078a39 = 3;
        DAT_a807cd74 = (rd_fn)FUN_a00a69b4;
        DAT_a807cd70 = DAT_a807cd7c = FUN_a00a69fc;
        DAT_a807cd78 = FUN_a00a6aa0;
        DAT_a8078a38 = 1;
        DAT_a8076274 = 0x9c8;
        DAT_a8076272 = 1;
        DAT_a8076270 = 0x404;
        DAT_a807626e = 0x405;
        DAT_a807626c = 0x406;
        DAT_a807626a = 0x407;
        DAT_a807cd78(DAT_a8078a38, 0x9c9, 1, 1);
        DAT_a807cd78(DAT_a8078a38, 0x391, 1, 1);
    } else if (mode == 4) {
        DAT_a8078a39 = 4;
        DAT_a807cd74 = (rd_fn)FUN_a0061eb4;
        DAT_a8078a38 = 0;
        DAT_a8076274 = 5;
        DAT_a8076272 = 0x20;
    } else if (mode == 5) {
        DAT_a8078a39 = 5;
        DAT_a807cd74 = (rd_fn)FUN_a0061eb4;
        DAT_a8078a38 = 1;
        DAT_a8076274 = 5;
        DAT_a8076272 = 0x20;
    }
}
