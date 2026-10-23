/* leon2m FUN_a00d4998 @ 0xa00d4998-0xa00d5748 (876 words), flags -mcpu=v8 -O3 -g. No calls, no parameters.
 * Picks a slot k: byte 0xa802d290+0x182 when bit 11 of the word at +0xa8 is clear, otherwise 1 when byte +0x181
 * is 0, else byte +0x181 + 5. For k 0-12 (switch, jump table at 0x73a30) it copies the current values into slot k
 * of the first set (bit 7 of halfword 0xa802cffe clear) or into slot k + 13 of the second set: the bytes +0x09,
 * +0x0a, +0x19, +0x15b, the low 4 bits of halfword +0x34 and byte +0x49 into the byte arrays at +0x58, +0x72, +0x90,
 * +0x15c, +0x1bb and +0x123, the word +0xb0 into the word array at +0xb4 (index k for k 0-6, k + 1 for 7-11, 7
 * for 12; second set k + 13 for 0-5, k + 14 for 6-11, 19 for 12), then bit 31 of the word at +0x11c into one slot
 * bit of that word (sa/sb) and its bit 4 into one slot bit of +0x11c / +0x120 (ta/tb); the bit-fields hold the
 * slots in the order 0-5, 12, 6-11. Finally byte 0xa802b08e |= 2 (also for k > 12).
 * Called from 39 functions, among them FUN_a0088724, FUN_a0095b58, FUN_a00c46d4 and FUN_a00cfacc.
 * Source form: the byte and word copies come before the two bit-field copies in each arm (the other order lets the
 * scheduler move the last byte store first); case order 0, 3, 1, 2, 4, 5, 8, 6, 9, 11, 12, 10, 7; the k selection
 * as an if / else-if chain with the 'b181 == 0' test first.
 */
struct D290 {
    unsigned char p000[9];
    unsigned char b009;
    unsigned char b00a;
    unsigned char p00b[0x19 - 0xb];
    unsigned char b019;
    unsigned char p01a[0x34 - 0x1a];
    unsigned short h034_hi : 12, h034_lo : 4;
    unsigned char p036[0x49 - 0x36];
    unsigned char b049;
    unsigned char p04a[0x58 - 0x4a];
    unsigned char a058[26];
    unsigned char a072[26];
    unsigned char p08c[0x90 - 0x8c];
    unsigned char a090[26];
    unsigned int p0aa : 4, f0a8_11 : 1, p0aa_5 : 11;   /* bits 15-0 of the word at 0xa8 */
    unsigned int w0ac;
    unsigned int w0b0;
    unsigned int w0b4[26];
    unsigned int f11c_31 : 1, sa0 : 1, sa1 : 1, sa2 : 1, sa3 : 1, sa4 : 1, sa5 : 1, sa12 : 1, sa6 : 1, sa7 : 1,
                     sa8 : 1, sa9 : 1, sa10 : 1, sa11 : 1, sb0 : 1, sb1 : 1, sb2 : 1, sb3 : 1, sb4 : 1, sb5 : 1,
                     sb12 : 1, sb6 : 1, sb7 : 1, sb8 : 1, sb9 : 1, sb10 : 1, sb11 : 1, f11c_4 : 1, ta0 : 1,
                     ta1 : 1, ta2 : 1, ta3 : 1;
    unsigned int ta4 : 1, ta5 : 1, ta12 : 1, ta6 : 1, ta7 : 1, ta8 : 1, ta9 : 1, ta10 : 1, ta11 : 1, tb0 : 1,
                     tb1 : 1, tb2 : 1, tb3 : 1, tb4 : 1, tb5 : 1, tb12 : 1, tb6 : 1, tb7 : 1, tb8 : 1, tb9 : 1,
                     tb10 : 1, tb11 : 1;
    unsigned char a123[26];
    unsigned char p13d[0x15b - 0x13d];
    unsigned char b15b;
    unsigned char a15c[26];
    unsigned char p176[0x181 - 0x176];
    unsigned char b181;
    unsigned char b182;
    unsigned char p183[0x1bb - 0x183];
    unsigned char a1bb[26];
};
extern struct D290 DAT_a802d290;
extern unsigned short DAT_a802cffe;
extern unsigned char DAT_a802b08e;

void FUN_a00d4998(void)
{
    unsigned char k;

    if (!DAT_a802d290.f0a8_11)
        k = DAT_a802d290.b182;
    else if (DAT_a802d290.b181 == 0)
        k = 1;
    else
        k = DAT_a802d290.b181 + 5;
    switch (k) {
    case 0:
        if (DAT_a802cffe & 0x80) {
            DAT_a802d290.a058[13] = DAT_a802d290.b009;
            DAT_a802d290.a072[13] = DAT_a802d290.b00a;
            DAT_a802d290.a090[13] = DAT_a802d290.b019;
            DAT_a802d290.a15c[13] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[13] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[13] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[13] = DAT_a802d290.b049;
            DAT_a802d290.sb0 = DAT_a802d290.f11c_31;
            DAT_a802d290.tb0 = DAT_a802d290.f11c_4;
        }
        else {
            DAT_a802d290.a058[0] = DAT_a802d290.b009;
            DAT_a802d290.a072[0] = DAT_a802d290.b00a;
            DAT_a802d290.a090[0] = DAT_a802d290.b019;
            DAT_a802d290.a15c[0] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[0] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[0] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[0] = DAT_a802d290.b049;
            DAT_a802d290.sa0 = DAT_a802d290.f11c_31;
            DAT_a802d290.ta0 = DAT_a802d290.f11c_4;
        }
        break;
    case 3:
        if (DAT_a802cffe & 0x80) {
            DAT_a802d290.a058[16] = DAT_a802d290.b009;
            DAT_a802d290.a072[16] = DAT_a802d290.b00a;
            DAT_a802d290.a090[16] = DAT_a802d290.b019;
            DAT_a802d290.a15c[16] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[16] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[16] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[16] = DAT_a802d290.b049;
            DAT_a802d290.sb3 = DAT_a802d290.f11c_31;
            DAT_a802d290.tb3 = DAT_a802d290.f11c_4;
        }
        else {
            DAT_a802d290.a058[3] = DAT_a802d290.b009;
            DAT_a802d290.a072[3] = DAT_a802d290.b00a;
            DAT_a802d290.a090[3] = DAT_a802d290.b019;
            DAT_a802d290.a15c[3] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[3] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[3] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[3] = DAT_a802d290.b049;
            DAT_a802d290.sa3 = DAT_a802d290.f11c_31;
            DAT_a802d290.ta3 = DAT_a802d290.f11c_4;
        }
        break;
    case 1:
        if (DAT_a802cffe & 0x80) {
            DAT_a802d290.a058[14] = DAT_a802d290.b009;
            DAT_a802d290.a072[14] = DAT_a802d290.b00a;
            DAT_a802d290.a090[14] = DAT_a802d290.b019;
            DAT_a802d290.a15c[14] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[14] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[14] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[14] = DAT_a802d290.b049;
            DAT_a802d290.sb1 = DAT_a802d290.f11c_31;
            DAT_a802d290.tb1 = DAT_a802d290.f11c_4;
        }
        else {
            DAT_a802d290.a058[1] = DAT_a802d290.b009;
            DAT_a802d290.a072[1] = DAT_a802d290.b00a;
            DAT_a802d290.a090[1] = DAT_a802d290.b019;
            DAT_a802d290.a15c[1] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[1] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[1] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[1] = DAT_a802d290.b049;
            DAT_a802d290.sa1 = DAT_a802d290.f11c_31;
            DAT_a802d290.ta1 = DAT_a802d290.f11c_4;
        }
        break;
    case 2:
        if (DAT_a802cffe & 0x80) {
            DAT_a802d290.a058[15] = DAT_a802d290.b009;
            DAT_a802d290.a072[15] = DAT_a802d290.b00a;
            DAT_a802d290.a090[15] = DAT_a802d290.b019;
            DAT_a802d290.a15c[15] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[15] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[15] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[15] = DAT_a802d290.b049;
            DAT_a802d290.sb2 = DAT_a802d290.f11c_31;
            DAT_a802d290.tb2 = DAT_a802d290.f11c_4;
        }
        else {
            DAT_a802d290.a058[2] = DAT_a802d290.b009;
            DAT_a802d290.a072[2] = DAT_a802d290.b00a;
            DAT_a802d290.a090[2] = DAT_a802d290.b019;
            DAT_a802d290.a15c[2] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[2] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[2] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[2] = DAT_a802d290.b049;
            DAT_a802d290.sa2 = DAT_a802d290.f11c_31;
            DAT_a802d290.ta2 = DAT_a802d290.f11c_4;
        }
        break;
    case 4:
        if (DAT_a802cffe & 0x80) {
            DAT_a802d290.a058[17] = DAT_a802d290.b009;
            DAT_a802d290.a072[17] = DAT_a802d290.b00a;
            DAT_a802d290.a090[17] = DAT_a802d290.b019;
            DAT_a802d290.a15c[17] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[17] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[17] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[17] = DAT_a802d290.b049;
            DAT_a802d290.sb4 = DAT_a802d290.f11c_31;
            DAT_a802d290.tb4 = DAT_a802d290.f11c_4;
        }
        else {
            DAT_a802d290.a058[4] = DAT_a802d290.b009;
            DAT_a802d290.a072[4] = DAT_a802d290.b00a;
            DAT_a802d290.a090[4] = DAT_a802d290.b019;
            DAT_a802d290.a15c[4] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[4] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[4] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[4] = DAT_a802d290.b049;
            DAT_a802d290.sa4 = DAT_a802d290.f11c_31;
            DAT_a802d290.ta4 = DAT_a802d290.f11c_4;
        }
        break;
    case 5:
        if (DAT_a802cffe & 0x80) {
            DAT_a802d290.a058[18] = DAT_a802d290.b009;
            DAT_a802d290.a072[18] = DAT_a802d290.b00a;
            DAT_a802d290.a090[18] = DAT_a802d290.b019;
            DAT_a802d290.a15c[18] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[18] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[18] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[18] = DAT_a802d290.b049;
            DAT_a802d290.sb5 = DAT_a802d290.f11c_31;
            DAT_a802d290.tb5 = DAT_a802d290.f11c_4;
        }
        else {
            DAT_a802d290.a058[5] = DAT_a802d290.b009;
            DAT_a802d290.a072[5] = DAT_a802d290.b00a;
            DAT_a802d290.a090[5] = DAT_a802d290.b019;
            DAT_a802d290.a15c[5] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[5] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[5] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[5] = DAT_a802d290.b049;
            DAT_a802d290.sa5 = DAT_a802d290.f11c_31;
            DAT_a802d290.ta5 = DAT_a802d290.f11c_4;
        }
        break;
    case 8:
        if (DAT_a802cffe & 0x80) {
            DAT_a802d290.a058[21] = DAT_a802d290.b009;
            DAT_a802d290.a072[21] = DAT_a802d290.b00a;
            DAT_a802d290.a090[21] = DAT_a802d290.b019;
            DAT_a802d290.a15c[21] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[22] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[21] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[21] = DAT_a802d290.b049;
            DAT_a802d290.sb8 = DAT_a802d290.f11c_31;
            DAT_a802d290.tb8 = DAT_a802d290.f11c_4;
        }
        else {
            DAT_a802d290.a058[8] = DAT_a802d290.b009;
            DAT_a802d290.a072[8] = DAT_a802d290.b00a;
            DAT_a802d290.a090[8] = DAT_a802d290.b019;
            DAT_a802d290.a15c[8] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[9] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[8] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[8] = DAT_a802d290.b049;
            DAT_a802d290.sa8 = DAT_a802d290.f11c_31;
            DAT_a802d290.ta8 = DAT_a802d290.f11c_4;
        }
        break;
    case 6:
        if (DAT_a802cffe & 0x80) {
            DAT_a802d290.a058[19] = DAT_a802d290.b009;
            DAT_a802d290.a072[19] = DAT_a802d290.b00a;
            DAT_a802d290.a090[19] = DAT_a802d290.b019;
            DAT_a802d290.a15c[19] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[20] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[19] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[19] = DAT_a802d290.b049;
            DAT_a802d290.sb6 = DAT_a802d290.f11c_31;
            DAT_a802d290.tb6 = DAT_a802d290.f11c_4;
        }
        else {
            DAT_a802d290.a058[6] = DAT_a802d290.b009;
            DAT_a802d290.a072[6] = DAT_a802d290.b00a;
            DAT_a802d290.a090[6] = DAT_a802d290.b019;
            DAT_a802d290.a15c[6] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[6] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[6] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[6] = DAT_a802d290.b049;
            DAT_a802d290.sa6 = DAT_a802d290.f11c_31;
            DAT_a802d290.ta6 = DAT_a802d290.f11c_4;
        }
        break;
    case 9:
        if (DAT_a802cffe & 0x80) {
            DAT_a802d290.a058[22] = DAT_a802d290.b009;
            DAT_a802d290.a072[22] = DAT_a802d290.b00a;
            DAT_a802d290.a090[22] = DAT_a802d290.b019;
            DAT_a802d290.a15c[22] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[23] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[22] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[22] = DAT_a802d290.b049;
            DAT_a802d290.sb9 = DAT_a802d290.f11c_31;
            DAT_a802d290.tb9 = DAT_a802d290.f11c_4;
        }
        else {
            DAT_a802d290.a058[9] = DAT_a802d290.b009;
            DAT_a802d290.a072[9] = DAT_a802d290.b00a;
            DAT_a802d290.a090[9] = DAT_a802d290.b019;
            DAT_a802d290.a15c[9] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[10] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[9] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[9] = DAT_a802d290.b049;
            DAT_a802d290.sa9 = DAT_a802d290.f11c_31;
            DAT_a802d290.ta9 = DAT_a802d290.f11c_4;
        }
        break;
    case 11:
        if (DAT_a802cffe & 0x80) {
            DAT_a802d290.a058[24] = DAT_a802d290.b009;
            DAT_a802d290.a072[24] = DAT_a802d290.b00a;
            DAT_a802d290.a090[24] = DAT_a802d290.b019;
            DAT_a802d290.a15c[24] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[25] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[24] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[24] = DAT_a802d290.b049;
            DAT_a802d290.sb11 = DAT_a802d290.f11c_31;
            DAT_a802d290.tb11 = DAT_a802d290.f11c_4;
        }
        else {
            DAT_a802d290.a058[11] = DAT_a802d290.b009;
            DAT_a802d290.a072[11] = DAT_a802d290.b00a;
            DAT_a802d290.a090[11] = DAT_a802d290.b019;
            DAT_a802d290.a15c[11] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[12] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[11] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[11] = DAT_a802d290.b049;
            DAT_a802d290.sa11 = DAT_a802d290.f11c_31;
            DAT_a802d290.ta11 = DAT_a802d290.f11c_4;
        }
        break;
    case 12:
        if (DAT_a802cffe & 0x80) {
            DAT_a802d290.a058[25] = DAT_a802d290.b009;
            DAT_a802d290.a072[25] = DAT_a802d290.b00a;
            DAT_a802d290.a090[25] = DAT_a802d290.b019;
            DAT_a802d290.a15c[25] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[19] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[25] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[25] = DAT_a802d290.b049;
            DAT_a802d290.sb12 = DAT_a802d290.f11c_31;
            DAT_a802d290.tb12 = DAT_a802d290.f11c_4;
        }
        else {
            DAT_a802d290.a058[12] = DAT_a802d290.b009;
            DAT_a802d290.a072[12] = DAT_a802d290.b00a;
            DAT_a802d290.a090[12] = DAT_a802d290.b019;
            DAT_a802d290.a15c[12] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[7] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[12] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[12] = DAT_a802d290.b049;
            DAT_a802d290.sa12 = DAT_a802d290.f11c_31;
            DAT_a802d290.ta12 = DAT_a802d290.f11c_4;
        }
        break;
    case 10:
        if (DAT_a802cffe & 0x80) {
            DAT_a802d290.a058[23] = DAT_a802d290.b009;
            DAT_a802d290.a072[23] = DAT_a802d290.b00a;
            DAT_a802d290.a090[23] = DAT_a802d290.b019;
            DAT_a802d290.a15c[23] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[24] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[23] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[23] = DAT_a802d290.b049;
            DAT_a802d290.sb10 = DAT_a802d290.f11c_31;
            DAT_a802d290.tb10 = DAT_a802d290.f11c_4;
        }
        else {
            DAT_a802d290.a058[10] = DAT_a802d290.b009;
            DAT_a802d290.a072[10] = DAT_a802d290.b00a;
            DAT_a802d290.a090[10] = DAT_a802d290.b019;
            DAT_a802d290.a15c[10] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[11] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[10] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[10] = DAT_a802d290.b049;
            DAT_a802d290.sa10 = DAT_a802d290.f11c_31;
            DAT_a802d290.ta10 = DAT_a802d290.f11c_4;
        }
        break;
    case 7:
        if (DAT_a802cffe & 0x80) {
            DAT_a802d290.a058[20] = DAT_a802d290.b009;
            DAT_a802d290.a072[20] = DAT_a802d290.b00a;
            DAT_a802d290.a090[20] = DAT_a802d290.b019;
            DAT_a802d290.a15c[20] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[21] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[20] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[20] = DAT_a802d290.b049;
            DAT_a802d290.sb7 = DAT_a802d290.f11c_31;
            DAT_a802d290.tb7 = DAT_a802d290.f11c_4;
        }
        else {
            DAT_a802d290.a058[7] = DAT_a802d290.b009;
            DAT_a802d290.a072[7] = DAT_a802d290.b00a;
            DAT_a802d290.a090[7] = DAT_a802d290.b019;
            DAT_a802d290.a15c[7] = DAT_a802d290.b15b;
            DAT_a802d290.w0b4[8] = DAT_a802d290.w0b0;
            DAT_a802d290.a1bb[7] = DAT_a802d290.h034_lo;
            DAT_a802d290.a123[7] = DAT_a802d290.b049;
            DAT_a802d290.sa7 = DAT_a802d290.f11c_31;
            DAT_a802d290.ta7 = DAT_a802d290.f11c_4;
        }
        break;
    }
    DAT_a802b08e |= 2;
}

