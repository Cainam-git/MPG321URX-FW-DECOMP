/* leon2m FUN_a014c7bc @ 0xa014c7bc-0xa014ce84 (1736 bytes)  SYSAPI command dispatcher (varargs) for the 0xA802E3D0
 * system state. Flags: -mcpu=v8 -O3 -g (434 words).
 *
 * void FUN_a014c7bc(cmd, ...): the five variadic words are spilled at %fp+0x48 (va_list); cmd > 32 does nothing.
 *   Jump table at 0xE35A4 (33 entries; the table holds 0x000ECxxx addresses = code address - 0xA0060000). Cases
 *   (a = low byte of argument 0, b = argument 1; E = record 0xA802E3D0, bits numbered in word 0 / word 1):
 *    0: E w0 bit 31 = (0xA802E1A0 bit 27 ? 0 : a); then 0xA802DF30+0x70 bit 23 cleared if bit 31 set, else set.
 *    4: print "SYSAPI_ConfigSystemPostFRCLockMode = %d \r\n"; E w0 bit 27 = (a != 0 && row +0x0A <= 0xFFF)
 *       (transformed row *DAT_a802d6a4).
 *    5: print "SYSAPI_ConfigSystemPostFRCMainBypass = %d \r\n"; E w0 bit 26 = a.
 *    6: E w0 bit 25 = a; FUN_a012f1ec(0..3, 1).       7: E w0 bit 24 = a; FUN_a0151aa4(0x10, 1);
 *       FUN_a012b328(0, bit 24).                      8: FUN_a0149588(a).   9: FUN_a014931c(a, b).
 *   12: if E+3 != a: (E+3 && a) ? FUN_a012f1ec(0, 4) : (FUN_a0107e44(0, 2400, 1), FUN_a012f1ec(0, 2)); E+3 = a.
 *   13: E w1 bits 28-31 = a; FUN_a012f1ec(0..3, 2).
 *   14: m = b (an inner 5-way switch maps 0..4 to themselves); a == 0: E w1 bits 24-27 = m; a == 1: E w1 bits
 *       20-23 = m; then FUN_a0142418(a, m).
 *   15: E+6 = a; FUN_a01198c8(a, 0); FUN_a01198c8(E+6, 1).   16: E+7 = a; a == 1 ? FUN_a012a774(1) : FUN_a012ad64().
 *   17: FUN_a014bf64(a).  18: E+9 = a; FUN_a013ae00(a).  19: E+0xA = a; FUN_a013b684(a).  20: E+0xB = a;
 *       FUN_a014c118(a).
 *   21: a = 0/1/2: E+0xC/0xD/0xE = b; FUN_a013b42c/b44c/b46c((b * 200 + 50) / 100 + 0x38).
 *   22: a = 0/1/2: E+0xF/0x10/0x11 = b; FUN_a013b5fc/b5a0/b544((b * 200 + 50) / 100 + 0x1C).
 *   23: E+0x18 = a; FUN_a012eeb0(a); FUN_a014c118(E+0xB).
 *   24: E+0x1C = a; FUN_a011855c(); a != 5: FUN_a014110c(E+0x1C).
 *   31: 0xA802E3FE = a.   32: 0xA802E408 = word; 0/1: FUN_a0150120(word, 0); 2/3: FUN_a0150120(1, 1).
 * Callers: no direct call in asm/leon2m.
 * ROW FIELDS READ: transformed row +0x0A (case 4 only).
 * Source form: case order 17,0,4,5,6,7,12,13,9,14,15,16,18,19,20,21,22,23,24,31,32,8 gives the
 *   firmware's block layout; inner a-switches in 21/22 (signed compare tree on the promoted u8); case 32 as an
 *   if-chain (a switch merges 0/1 into a range test); unsigned '/ 100U'.
 * Case 14 facts:
 *   - FUN_a0142418 takes TWO arguments (port, value). Its body never reads the second, but FUN_a015149c passes it
 *     (FUN_a0142418(0, w1 bits 24-27), FUN_a0142418(1, w1 bits 20-23), %o1 set). Passing m keeps m in %o1 and
 *     live across the arms, which gives the firmware's register picture and load/and order.
 *   - 'unsigned int m; m = b;' before the identity switch (no default copy) gives the firmware's 'ldub [ap+7]'.
 *   - case 0 falls through into default (shared call keeps 'a' in %o0); case 1 has its own call, where gcse puts
 *     the constant 1 ('mov 1, %o0'), as in the firmware.
 *   - Top-level case order: whole case blocks, each ends in break; the rename pass (LRU ticks) follows source
 *     block order.
 * Compiler aid (no code): two 'do continue; while (0);' at the start of case 14's
 *   'case 1:' arm. They emit no instructions and change no behaviour; each adds the PRED_CONTINUE branch hint, which
 *   raises that arm's predicted frequency above the inner switch stubs, so bb-reorder places the arm before the
 *   stubs as in the firmware (one hint is not enough; two give the firmware's layout).
 */
#include <stdarg.h>
struct E3D0bits {
    unsigned int b31:1, b30:1, b29:1, b28:1, b27:1, b26:1, b25:1, b24:1, r0:24;
    unsigned int f28:4, f24:4, f20:4, r1:20;
};
union E3D0 { struct E3D0bits f; unsigned char b[0x30]; };
struct In { unsigned char pad[0x70]; unsigned int w70; };
struct PanelParam { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short h08; unsigned short h0a; };
extern struct PanelParam *DAT_a802d6a4;
extern union E3D0 DAT_a802e3d0;
extern struct In DAT_a802df30;
extern unsigned int DAT_a802e1a0, DAT_a802e408;
extern unsigned char DAT_a802e3d7, DAT_a802e3d9, DAT_a802e3da, DAT_a802e3db, DAT_a802e3dc, DAT_a802e3dd,
    DAT_a802e3de, DAT_a802e3df, DAT_a802e3e0, DAT_a802e3e1, DAT_a802e3fe;
extern char s_001a6f78[], s_001a6f48[];
extern int FUN_a00df170();
extern void FUN_a0150120(int, int);
extern void FUN_a011855c(void);
extern void FUN_a014110c(unsigned char);
extern void FUN_a012eeb0(unsigned char);
extern void FUN_a014c118(unsigned char);
extern void FUN_a013b42c(unsigned short), FUN_a013b44c(unsigned short), FUN_a013b46c(unsigned short);
extern void FUN_a013b5fc(unsigned char), FUN_a013b5a0(unsigned char), FUN_a013b544(unsigned char);
extern void FUN_a013b684(unsigned char);
extern void FUN_a012f1ec(int, int);
extern void FUN_a0107e44(int, unsigned short, int);
extern void FUN_a014931c(unsigned char, unsigned char);
extern void FUN_a0149588(unsigned char);
extern void FUN_a0151aa4(int, int);
extern int FUN_a012b328(unsigned int, unsigned int);
extern void FUN_a012a774(int);
extern void FUN_a012ad64(void);
extern void FUN_a0142418(unsigned char, unsigned char);
extern void FUN_a013ae00(unsigned char);
extern void FUN_a014bf64(unsigned char);
extern void FUN_a01198c8(unsigned int, unsigned char);

void FUN_a014c7bc(unsigned int cmd, ...)
{
    va_list ap;
    unsigned char a, b; unsigned int m;
    unsigned int v;

    va_start(ap, cmd);
    switch (cmd) {
    case 17:
        a = va_arg(ap, int);
        FUN_a014bf64(a);
        break;
    case 0:
        a = va_arg(ap, int);
        if (DAT_a802e1a0 & 0x8000000) DAT_a802e3d0.f.b31 = 0;
        else DAT_a802e3d0.f.b31 = a;
        if (DAT_a802e3d0.f.b31) DAT_a802df30.w70 &= ~0x800000;
        else DAT_a802df30.w70 |= 0x800000;
        break;
    case 4:
        a = va_arg(ap, int);
        FUN_a00df170(s_001a6f48, a);
        if (a && DAT_a802d6a4->h0a <= 0xfff) DAT_a802e3d0.f.b27 = 1;
        else DAT_a802e3d0.f.b27 = 0;
        break;
    case 5:
        a = va_arg(ap, int);
        FUN_a00df170(s_001a6f78, a);
        DAT_a802e3d0.f.b26 = a;
        break;
    case 6:
        a = va_arg(ap, int);
        DAT_a802e3d0.f.b25 = a;
        FUN_a012f1ec(0, 1);
        FUN_a012f1ec(1, 1);
        FUN_a012f1ec(2, 1);
        FUN_a012f1ec(3, 1);
        break;
    case 7:
        a = va_arg(ap, int);
        DAT_a802e3d0.f.b24 = a;
        FUN_a0151aa4(0x10, 1);
        FUN_a012b328(0, DAT_a802e3d0.f.b24);
        break;
    case 12:
        a = va_arg(ap, int);
        if (DAT_a802e3d0.b[3] != a) {
            if (DAT_a802e3d0.b[3] != 0 && a != 0) FUN_a012f1ec(0, 4);
            else {
                FUN_a0107e44(0, 0x960, 1);
                FUN_a012f1ec(0, 2);
            }
            DAT_a802e3d0.b[3] = a;
        }
        break;
    case 13:
        a = va_arg(ap, int);
        DAT_a802e3d0.f.f28 = a;
        FUN_a012f1ec(0, 2);
        FUN_a012f1ec(1, 2);
        FUN_a012f1ec(2, 2);
        FUN_a012f1ec(3, 2);
        break;
    case 9:
        a = va_arg(ap, int);
        b = va_arg(ap, int);
        FUN_a014931c(a, b);
        break;
    case 14:
        a = va_arg(ap, int);
        b = va_arg(ap, int);
        m = b;
        switch (b) {
        case 0: m = 0; break;
        case 1: m = 1; break;
        case 2: m = 2; break;
        case 3: m = 3; break;
        case 4: m = 4; break;
        default: break;
        }
        switch (a) {
        case 0: DAT_a802e3d0.f.f24 = m;
        default: FUN_a0142418(a, m); break;
        case 1: do continue; while (0); do continue; while (0); DAT_a802e3d0.f.f20 = m; FUN_a0142418(a, m); break;
        }
        break;
    case 15:
        a = va_arg(ap, int);
        DAT_a802e3d0.b[6] = a;
        FUN_a01198c8(a, 0);
        FUN_a01198c8(DAT_a802e3d0.b[6], 1);
        break;
    case 16:
        a = va_arg(ap, int);
        DAT_a802e3d7 = a;
        if (a == 1) FUN_a012a774(1);
        else FUN_a012ad64();
        break;
    case 18:
        a = va_arg(ap, int);
        DAT_a802e3d9 = a;
        FUN_a013ae00(a);
        break;
    case 19:
        a = va_arg(ap, int);
        DAT_a802e3da = a;
        FUN_a013b684(a);
        break;
    case 20:
        a = va_arg(ap, int);
        DAT_a802e3db = a;
        FUN_a014c118(a);
        break;
    case 21:
        a = va_arg(ap, int);
        b = va_arg(ap, int);
        switch (a) {
        case 0:
            DAT_a802e3dc = b;
            FUN_a013b42c((b * 200 + 50) / 100U + 0x38);
            break;
        case 1:
            DAT_a802e3dd = b;
            FUN_a013b44c((b * 200 + 50) / 100U + 0x38);
            break;
        case 2:
            DAT_a802e3de = b;
            FUN_a013b46c((b * 200 + 50) / 100U + 0x38);
            break;
        }
        break;
    case 22:
        a = va_arg(ap, int);
        b = va_arg(ap, int);
        switch (a) {
        case 0:
            DAT_a802e3df = b;
            FUN_a013b5fc((b * 200 + 50) / 100U + 0x1c);
            break;
        case 1:
            DAT_a802e3e0 = b;
            FUN_a013b5a0((b * 200 + 50) / 100U + 0x1c);
            break;
        case 2:
            DAT_a802e3e1 = b;
            FUN_a013b544((b * 200 + 50) / 100U + 0x1c);
            break;
        }
        break;
    case 23:
        a = va_arg(ap, int);
        DAT_a802e3d0.b[0x18] = a;
        FUN_a012eeb0(a);
        FUN_a014c118(DAT_a802e3d0.b[0xb]);
        break;
    case 24:
        a = va_arg(ap, int);
        DAT_a802e3d0.b[0x1c] = a;
        if (a == 5) FUN_a011855c();
        else {
            FUN_a011855c();
            FUN_a014110c(DAT_a802e3d0.b[0x1c]);
        }
        break;
    case 31:
        a = va_arg(ap, int);
        DAT_a802e3fe = a;
        break;
    case 32:
        v = va_arg(ap, unsigned int);
        DAT_a802e408 = v;
        if (v == 0) FUN_a0150120(v, 0);
        else if (v == 1) FUN_a0150120(v, 0);
        else if (v == 2) FUN_a0150120(1, 1);
        else if (v == 3) FUN_a0150120(1, 1);
        break;
    case 8:
        a = va_arg(ap, int);
        FUN_a0149588(a);
        break;
    }
    va_end(ap);
}
