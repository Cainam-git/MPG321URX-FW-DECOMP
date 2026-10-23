/* leon2s FUN_a0073578 @ 0xa0073578 (-mcpu=v8 -Os -g)
 * When p1 == 0: sets the record at 0xA80789D4 to {0, word 0xA8079038, address of FUN_a0083324} and calls
 * CONV2HDMITX_UpdateInterface_3 with its address. Same code as FUN_a00a4610 with other constants.
 * See FUN_a00a4610 for the explanation; this copy's constants differ, so its comments were removed.
 */
struct Rec { unsigned int a; unsigned int b; unsigned int c; };
extern unsigned int _DAT_a8079038;
extern struct Rec _DAT_a80789d4;
extern unsigned int FUN_a0083324();
extern int CONV2HDMITX_UpdateInterface_3();

void FUN_a0073578(int param_1)
{
    if (param_1 == 0) {
        _DAT_a80789d4.a = 0;
        _DAT_a80789d4.c = (unsigned int)FUN_a0083324;
        _DAT_a80789d4.b = _DAT_a8079038;
        CONV2HDMITX_UpdateInterface_3(&_DAT_a80789d4);
    }
}
