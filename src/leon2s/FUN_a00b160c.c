/* leon2s FUN_a00b160c @ 0xa00b160c  MATCH (-mcpu=v8 -Os -g)
 * Delay loop: param_1 outer iterations (16-bit counter), each an inner nop loop whose count depends on param_1:
 * 0x21 for 0..4, 0x2E for 5..0x13, 0x2F for 0x14..0x5F, 0x30 for 0x60..0x1EA, 0x31 above 0x1EA. The inner test
 * `uVar2 < count` compiles to cmp %g1, count - 1 / bleu after the inc (cmp %g1, 0x30 for 0x31).
 */
extern void FUN_a00b160c(unsigned int param_1);

void FUN_a00b160c(unsigned int param_1)
{
    unsigned short uVar1;
    unsigned short uVar2;
    
    if (param_1 > 0x1ea) {
        uVar1 = 0;
        if (param_1 != 0) {
            do {
                for (uVar2 = 0; uVar2 < 0x31; uVar2++) __asm__("nop");
                uVar1 = uVar1 + 1;
            } while ((uVar1 & 0xffff) < param_1);
        }
    }
    else if (param_1 > 0x5f) {
        uVar1 = 0;
        if (param_1 != 0) {
            do {
                for (uVar2 = 0; uVar2 < 0x30; uVar2++) __asm__("nop");
                uVar1 = uVar1 + 1;
            } while ((uVar1 & 0xffff) < param_1);
        }
    }
    else if (param_1 > 0x13) {
        uVar1 = 0;
        if (param_1 != 0) {
            do {
                for (uVar2 = 0; uVar2 < 0x2f; uVar2++) __asm__("nop");
                uVar1 = uVar1 + 1;
            } while ((uVar1 & 0xffff) < param_1);
        }
    }
    else if (param_1 > 4) {
        uVar1 = 0;
        if (param_1 != 0) {
            do {
                for (uVar2 = 0; uVar2 < 0x2e; uVar2++) __asm__("nop");
                uVar1 = uVar1 + 1;
            } while ((uVar1 & 0xffff) < param_1);
        }
    }
    else {
        uVar1 = 0;
        if (param_1 != 0) {
            do {
                for (uVar2 = 0; uVar2 < 0x21; uVar2++) __asm__("nop");
                uVar1 = uVar1 + 1;
            } while ((uVar1 & 0xffff) < param_1);
        }
    }
    return;
}
