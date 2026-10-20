/* leon2m FUN_a013b754 @ 0xa013b754-0xa013b7e0 (35 words), flags -mcpu=v8 -O3 -g.
 * Code facts: now = func_0x4008d588() (u16); diff = now - u16 0xa802cbd0; 0xa802cbd0 = now;
 * for idx = 0..8 (u8) over the u16 timer table at 0xa802cbbe: t < diff -> t = 0, else t -= diff;
 * then table[param_1] = (u16)param_2. %i0 is never written: 'void' and the draft's
 * 'return param_1' give the same code (kept void).
 * Fix vs the autoc draft (97.14): BEHAVIOUR, the table is indexed by idx (u16 stride, fw
 * 'add %g1,%g1'); the draft used idx*2 (4-byte stride, sll 2). Aids: none.
 */
extern unsigned short _DAT_a802cbd0;
extern int func_0x4008d588();
extern unsigned short ARR_a802cbbe[];

void FUN_a013b754(int param_1, int param_2) {
    unsigned short new_val;
    unsigned short old;
    unsigned short diff;
    unsigned char idx;
    int i;
    unsigned short val;
    
    new_val = (unsigned short)func_0x4008d588();
    old = _DAT_a802cbd0;
    _DAT_a802cbd0 = new_val;
    diff = (unsigned short)(new_val - old);
    
    idx = 0;
    do {
        i = idx;
        val = ARR_a802cbbe[i];
        if (val < diff) {
            idx++;
            ARR_a802cbbe[i] = 0;
            if (idx > 8) goto done;
        } else {
            idx++;
            ARR_a802cbbe[i] = val - diff;
            if (idx > 8) goto done;
        }
    } while (idx <= 8);
done:
    ARR_a802cbbe[param_1] = (unsigned short)param_2;

}
