/* leon2s FUN_a0073578 @ 0xa0073578  MATCH (-mcpu=v8 -Os -g, twin)
 * Twin of FUN_a00a4610: same code, constants swapped; byte-exact.
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
