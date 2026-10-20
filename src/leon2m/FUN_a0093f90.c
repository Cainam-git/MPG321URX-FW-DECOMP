/* leon2m FUN_a0093f90 @ 0xa0093f90-0xa0094108 (94 words), flags -mcpu=v8 -O3 -g. No direct callers (reached through
 * a table). Uses the halfwords 0xa802d034 and 0xa802d03a ('restarted' = set to FUN_a0147724(); 'more than n have
 * passed since t' = func_0x4008d594(t) > n) and byte 0xa802cffc (0xa802cff4 + 8). When more than 100 have passed
 * since 0xa802d034, the byte is set to 0x38 and 0xa802d03a restarted; 0xa802d034 is restarted; when the high nibble
 * of the byte is not 3, the byte is set to 0x38 and 0xa802d03a restarted. When more than 2000 and when more than
 * 5000 have passed since 0xa802d03a, the byte is set to 0x38 unless more than 99 have passed since 0xa802d034. Then,
 * when byte 0xa802d2c1 (0xa802d290 + 0x31) is 0, 1 or 2, the halfword 0xa802d2e6 (+0x56) is lowered by the low
 * nibble of the byte when it is at least that nibble, else cleared. Ends with FUN_a00d7a70(0) and sets bit 1 (0x02)
 * of byte 0xa802b08e. FUN_a0093bac is the same with 0x28, high nibble 2 and the halfword +0x54.
 * Exact form: the byte is a union of a plain byte and two 4-bit bit-fields; the step is the low bit-field read into
 * an unsigned short local. The decrement is written out once for each of the values 0, 1 and 2 (GCC merges the
 * copies into one block behind a compare chain; an || of the three tests becomes a range test).
 */
union U8 { unsigned char b; struct { unsigned char hi : 4, lo : 4; } f; };
struct Rcff4 { unsigned char pad[8]; union U8 u; };
struct R290 { unsigned char pad[0x31]; unsigned char b31; unsigned char pad32[0x22]; unsigned short h54, h56; };
extern struct Rcff4 DAT_a802cff4;
extern struct R290 DAT_a802d290;
extern unsigned short DAT_a802d034, DAT_a802d03a;
extern unsigned char DAT_a802b08e;
extern unsigned short FUN_a0147724(void);
extern unsigned short func_0x4008d594(unsigned short start);
extern void FUN_a00d7a70(int);

void FUN_a0093f90(void)
{
    unsigned short step;

    if (func_0x4008d594(DAT_a802d034) > 100) {
        DAT_a802cff4.u.b = 0x38;
        DAT_a802d03a = FUN_a0147724();
    }
    DAT_a802d034 = FUN_a0147724();
    if ((DAT_a802cff4.u.b >> 4) != 3) {
        DAT_a802cff4.u.b = 0x38;
        DAT_a802d03a = FUN_a0147724();
    }
    if (func_0x4008d594(DAT_a802d03a) > 2000)
        if (func_0x4008d594(DAT_a802d034) <= 99)
            DAT_a802cff4.u.b = 0x38;
    if (func_0x4008d594(DAT_a802d03a) > 5000)
        if (func_0x4008d594(DAT_a802d034) <= 99)
            DAT_a802cff4.u.b = 0x38;
    if (DAT_a802d290.b31 == 0) {
        step = DAT_a802cff4.u.f.lo;
        if (step <= DAT_a802d290.h56)
            DAT_a802d290.h56 -= step;
        else
            DAT_a802d290.h56 = 0;
    } else if (DAT_a802d290.b31 == 1) {
        step = DAT_a802cff4.u.f.lo;
        if (step <= DAT_a802d290.h56)
            DAT_a802d290.h56 -= step;
        else
            DAT_a802d290.h56 = 0;
    } else if (DAT_a802d290.b31 == 2) {
        step = DAT_a802cff4.u.f.lo;
        if (step <= DAT_a802d290.h56)
            DAT_a802d290.h56 -= step;
        else
            DAT_a802d290.h56 = 0;
    }
    FUN_a00d7a70(0);
    DAT_a802b08e |= 2;
}
