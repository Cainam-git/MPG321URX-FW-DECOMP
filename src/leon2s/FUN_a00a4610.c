/* FUN_a00a4610 (leon2s, 0xa00a4610-0xa00a4658, 72 bytes, 18 words, leaf-frame tail call).
 * Flags: -mcpu=v8 -Os -g.
 * Code facts: when param_1 == 0, fills the 3-word record _DAT_a8079218: word 0 = 0, word 2 = the
 * address of FUN_a00a4658, word 1 = _DAT_a8079214, then tail-calls CONV2HDMITX_UpdateInterface_3
 * (0xa00b20dc) with the record address (fw: mov %o7,%g1 / call / mov %g1,%o7 sibcall form).
 * Fix vs draft: the record is a STRUCT symbol (fw clears word 0 via [%o3 + %lo] of the symbol and
 * writes +8/+4 via the full address); the draft's pointer p gave the clear first. Aids: none.
 */
struct Rec { unsigned int a; unsigned int b; unsigned int c; };
extern unsigned int _DAT_a8079214;
extern struct Rec _DAT_a8079218;
extern unsigned int FUN_a00a4658();
extern int CONV2HDMITX_UpdateInterface_3();

void FUN_a00a4610(int param_1)
{
    if (param_1 == 0) {
        _DAT_a8079218.a = 0;
        _DAT_a8079218.c = (unsigned int)FUN_a00a4658;
        _DAT_a8079218.b = _DAT_a8079214;
        CONV2HDMITX_UpdateInterface_3(&_DAT_a8079218);
    }
}
