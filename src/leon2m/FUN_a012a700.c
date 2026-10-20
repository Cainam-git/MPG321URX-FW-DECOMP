/* leon2m FUN_a012a700 @ 0xa012a700-0xa012a774 (29 words), flags -mcpu=v8 -O3 -g.
 * Code facts: v (u16 param) = v * 0x381 / 0x3ff + 0x7e (unsigned: umul by 0x401005), stored in the parameter's own
 * home slot %fp+0x44 (its address is taken); if the hook word 0xa802cc50 is non-zero: hook(&v); then FUN_a0143804(v)
 * (v re-read with lduh, the hook may change it). void.
 * FUN_a0143804 takes v (fw lduh [%fp+0x44] into %o0 in the call's delay slot). The scaling is unsigned (0x381U) and
 * written back into the parameter itself (no separate local array). Compiler aids: none.
 */
extern void (*_DAT_a802cc50)(unsigned short *);
extern void FUN_a0143804(unsigned short);

void FUN_a012a700(unsigned short v)
{
    v = v * 0x381U / 0x3ff + 0x7e;
    if (_DAT_a802cc50 != 0)
        _DAT_a802cc50(&v);
    FUN_a0143804(v);
}
