/* leon2m FUN_a0124244 @ 0xa0124244-0xa01243b0 (91 words), -mcpu=v8 -O3 -g.
 * Called by APPTimerRoutine FUN_a0085984 (colour-cycling chain).
 * What it does: one step of a state-change watcher. lim = 2, f = 0; (u8)FUN_a012ad6c() != 1 -> f = 1, lim = 3.
 *   mode == 1: the two remembered bytes DAT_a802a420 / DAT_a802a421 = 0xff (forget), return.
 *   Else src = (u8)FUN_a0125b94() ? 2 : 0 (FUN_a0125b94 = 'func_0x4008cd38(2, 1) low byte == 1'),
 *   v = FUN_a0125b44() (0/1, 'func_0x4008cd38(2, 8) low byte == 1'). Unchanged (DAT_a802a420 == src and
 *   DAT_a802a421 == (u8)v) -> return. Changed: FUN_a0137864(lim, 1); level = v == 1 ? (src == 2 ? 0x36 : 0x63)
 *   : (src == 2 ? 0x9c : 0xc9); a/b = src == 2 ? 0xf / 1 : 0 / 0; FUN_a012b418(f & 1, level, a & 0xf, b & 1, 1);
 *   FUN_a0137864(lim, 2); remember src and v.
 * No timing value is read here; the inputs are the three callee results and mode.
 * Source form: u8 f/a/b with explicit '& 1 / & 0xf / & 1' at the call (fw keeps the masks); one FUN_a0125b44 call.
 *   src goes through an INT temp 'x = 0; if (...) x = 2; src = x;' set BEFORE the FUN_a0125b44 call (fw
 *   'clr/mov 2 %g1' in the branch delay, 'mov %g1, %l3' in the call delay, 'and %l3, 0xff, %l0' after: the copy
 *   from a register hides src's 0/2 range from combine). Level and a/b selects written with 'src != 2' FIRST in
 *   each if/else (gives the fw block layout: the 0x9c block gets its own copy of the a = 0xf / b = 1 tail).
 *   mode == 1 stores written 0x420 then 0x421 (sched emits 0x421 first, like the fw).
 * Compiler aids: none. No volatile.
 */
extern unsigned char DAT_a802a420;
extern unsigned char DAT_a802a421;
extern unsigned int FUN_a012ad6c(void);
extern int FUN_a0125b94(void);
extern int FUN_a0125b44(void);
extern void FUN_a0137864(unsigned char, int);
extern void FUN_a012b418(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

void FUN_a0124244(unsigned char mode)
{
    unsigned char f, lvl, a, b;
    unsigned char lim;
    unsigned char src;
    int v;
    int x;

    lim = 2;
    f = 0;
    if ((unsigned char)FUN_a012ad6c() != 1) {
        f = 1;
        lim = 3;
    }
    if (mode == 1) {
        DAT_a802a420 = 0xff;
        DAT_a802a421 = 0xff;
        return;
    }
    x = 0;
    if ((unsigned char)FUN_a0125b94())
        x = 2;
    src = x;
    v = FUN_a0125b44();
    if (DAT_a802a420 == src && DAT_a802a421 == (unsigned char)v)
        return;
    FUN_a0137864(lim, 1);
    if ((unsigned char)v != 1) {
        if (src != 2)
            lvl = 0xc9;
        else
            lvl = 0x9c;
    } else {
        if (src != 2)
            lvl = 0x63;
        else
            lvl = 0x36;
    }
    if (src != 2) {
        b = 0;
        a = 0;
    } else {
        b = 1;
        a = 0xf;
    }
    FUN_a012b418(f & 1, lvl, a & 0xf, b & 1, 1);
    FUN_a0137864(lim, 2);
    DAT_a802a420 = src;
    DAT_a802a421 = v;
}
