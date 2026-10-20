/* leon2s FUN_a00ccf0c @ 0xa00ccf0c-0xa00ccfa8 (39 words), flags -mcpu=v8 -Os -g.
 * Code facts: FUN_a00cca38(0); rec = 24-byte record (arg & 0xff) of the table at 0xa8078bb0
 * (port*3 << 3); rec.w0 = (rec.w0 & 0xfffcffff) | 0x10000; r = func_0xa0f96400(0, 0x90, 0x6921d, 0,
 * &byte 0xa807ce50); (r & 0xff) == 0 -> clear bits 16..17 of rec.w0; else if that byte == 2 ->
 * bits 16..17 = 2 (| 0x20000). The mask 0xfffcffff stays in %l1 for all three uses.
 * Fix vs the autoc draft (97.44): BEHAVIOUR, the draft indexed a uint array by port*0x18 (= 96-byte
 * stride, sll 5); the record stride is 0x18 bytes -> struct R[ ] of 24 bytes (a uint index port*6
 * gives the same code). Aids: none.
 */
extern int FUN_a00cca38();
extern int func_0xa0f96400();
struct R { unsigned int w; unsigned char pad[0x14]; };
extern struct R DAT_a8078bb0[];
extern unsigned char DAT_a807ce50;

void FUN_a00ccf0c(unsigned int param_1)
{
    unsigned int val;
    unsigned int idx;

    FUN_a00cca38(0);
    idx = (param_1 & 0xff) ;
    DAT_a8078bb0[idx].w = (DAT_a8078bb0[idx].w & 0xfffcffff) | 0x10000;

    val = func_0xa0f96400(0, 0x90, 0x6921d, 0, &DAT_a807ce50);

    if ((val & 0xff) == 0) {
        val = DAT_a8078bb0[idx].w & 0xfffcffff;
        DAT_a8078bb0[idx].w = val;
    } else if (DAT_a807ce50 == 2) {
        val = (DAT_a8078bb0[idx].w & 0xfffcffff) | 0x20000;
        DAT_a8078bb0[idx].w = val;
    }
}
