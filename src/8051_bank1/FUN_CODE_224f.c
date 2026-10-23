/* 8051_bank1 FUN_CODE_224f @ 0x224F..0x27B5 (1382 bytes) + FUN_CODE_d5a1 @ 0xD59B..0xD5C8 (45 bytes)
 * STBC command switch: carries out ONE command word that the Big chip wrote to the mailbox portal (word +0x00).
 * MATCH: tools/diff8051.py 8051_bank1 FUN_CODE_224f -> 1382/1382, 100 %, exact None, OPTIMIZE(8,SPEED) LARGE
 *        (SPAN_END 0x27B5). Same file: FUN_CODE_d5a1 -> 45/45, 100 %, exact None.
 * Why d5a1 is in this unit (code): 0xD59B..0xD5A0 'MOV R6,#0 / MOV R5,#0 / MOV R4,#0' is the Keil OPTIMIZE(8)
 *   common-entry block of FUN_CODE_d5a1(unsigned long). Its only users are the two calls in 224f (0x2654 with
 *   R7 = 0x0C, 0x27B1 with R7 = 0): so the source calls are d5a1(0x0C) / d5a1(0), and d5a1 was in the same module.
 *   Without d5a1 in the unit Keil emits 'CLR A / MOV R7,A' at 0x27AF. FUN_CODE_d59b is not a function.
 * FUN_CODE_d5a1(off): v = 0; FUN_CODE_b228((uchar)off, &v, 1): writes the 32-bit word 0 to portal +off.
 * Parameter p (XDATA 0xA4A9, ulong) = the command word read by FUN_CODE_9243 (or one word of a command list,
 *   FUN_CODE_1c3c). cmd = bits 7..0, b1 = bits 15..8, b2 = bits 23..16, b3 = bits 31..24, w = bits 31..16.
 *   'cmd = p & 0xFF' (not '(uchar)p') gives the firmware's full R4..R7 load at 0x2255.
 * Jump table 0x22DB (49 LJMPs) for cmd 1..0x31; any other value goes straight to the tail. Commands (hex):
 *   01 abc4(b1,b2,b3)+c59a(b1)  02 c790(b1)  05 a775(b1,b2,b3)  06 c9b0(b1)  08 c278(b1)  09 c03f(b1)  0A c03f(0)
 *   07 I2C slave set-up: bde9(ch=b1, addr=b2), 9f04(ch), c2d3(ch)  (the Big chip's FUN_a0133e7c sends ch 1, 0x6E)
 *   0D A46D = b2, A46C = b3   0E bbca(b1,b2)   0F c7e0(b1)   14 de45(b1), c965(b2:b3), cd8c, d31d ("Update FE2P Addr")
 *   11/12/13/15 flash jobs, each wrapped in the handshake on portal word +0xB8: c163() polls +0xB8 until its low
 *     byte is 1 (max 20000 reads, returns 0 on time-out), then the job runs only if it returned 1; cb1d() then
 *     always writes low byte 2 into +0xB8.  11: d3eb (flash write of the 0xA800 buffer)  12: d3b9 (flash read),
 *     b781, dbdf (post word at +0xB0)  13: da91 (sector erase)  15: 9fc8(b2:b3, b1)
 *   16 CMD_SYS_POWERSAVING: STOP Main (cbac), STOP Sub (cbf2), F150 = 9, F152 |= 0x40, 71f0, run state A770 = 0,
 *     dd41, ccc2(0), chip 0x20: d351.     17 CMD_SYS_POWEROFF: same STOPs and F150/F152, 7a0b, A770 = 1, dd41.
 *   18 de03(w)  19 dec2(b2,b3)  1A decb(b2,b3)  1B deee(b2)  1C c830(w) "setWakeupTimer"  1D / 1E "CMD_SET_P14 /
 *     P15": F0CC = 0x30, F1F0 = 0xFF, SFR 0xA5 = 0xFF, port bit P1.4 / P1.5 = (w != 0)  1F c87f(b1,b2)
 *   20 d5a1(0x0C): zero word +0x0C   21 "CMD_WRITE_DPTXHDCP" d171   22 b2 != 0: F1EB bit 3 = 0, F1E0 bit 3 = 1,
 *     else the opposite   23 b1 = 0..5: XDATA 0xCBC1 + b1 = b2   24 de3a(b2,b3)
 *   25 F17C = b1; XDATA 0xD511 = 0x1A or 0x20: A3E0 = b2, A3E1 = b3, F17D = 1, F17E/F17F = FF/FF (0x1A) or AA/00
 *     (0x20), A35E = 0   26 "CMD_FE2P_SETEXTEND": dee8(b1:b2:b3) (XDATA 0xA717)
 *   27 if c163(): F00A = F0E0 = 0xAA, chip 0x20: FUN_CODE_0022 (empty function); then cb1d, F00A = F0E0 = 0x55
 *   28 b1 0 / 1: bit 0 / bit 2 of XDATA 0xCAB2 = (b2 != 0)   29 FUN_CODE_6c34 'STBC FW updating' flash loop (no return)
 *   2A dd09 ("Enable_DPMRX")   2B de2e   30 d70f(b1,b2,b3)   31 ba6d(b1,b2,b3)
 *   03 04 0B 0C 10 2C..2F: no action (table entry = tail); the empty cases are needed for the jump table
 *   (without them Keil builds a ?C?CCASE search instead).
 * Tail 0x279F: for every cmd except 0, 0x16 and 0x17: d5a1(0) = command word +0x00 := 0 (the 8051 clears the
 *   command word = acknowledges it).
 * Case order in this file = code order in the firmware (Keil places case bodies in source order).
 * Update path (code): every action that the update path needs from the 8051 (07 = I2C slave 0x6E for MSI's
 *   tool, 29 = flash loop) runs only when the Big chip writes that command word. A Big chip that halts during
 *   start-up writes none, so this switch is never entered with 07 or 29.
 * volatile only on hardware registers: F0xx / F1xx and the chip-ID register 0xD511 (re-read at 0x26F9, as in
 *   src/8051_bank1/FUN_CODE_afdc.c). Strings are code addresses through FUN_CODE_2820 (printf), as in FUN_CODE_7b5a.
 */
#pragma LARGE
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;
sfr SFR_A5 = 0xA5;
sbit P1_4 = 0x94;
sbit P1_5 = 0x95;
extern void FUN_CODE_2820(void *fmt, ...) large;   /* printf */
extern unsigned char volatile xdata DAT_EXTMEM_f00a, DAT_EXTMEM_f0e0, DAT_EXTMEM_f0cc, DAT_EXTMEM_f1f0;
extern unsigned char volatile xdata DAT_EXTMEM_f150, DAT_EXTMEM_f152, DAT_EXTMEM_f1eb, DAT_EXTMEM_f1e0;
extern unsigned char volatile xdata DAT_EXTMEM_f17c, DAT_EXTMEM_f17d, DAT_EXTMEM_f17e, DAT_EXTMEM_f17f;
extern unsigned char volatile xdata DAT_EXTMEM_d511;
extern unsigned char xdata DAT_EXTMEM_a770, DAT_EXTMEM_a46c, DAT_EXTMEM_a46d, DAT_EXTMEM_a35e;
extern unsigned char xdata DAT_EXTMEM_a3e0, DAT_EXTMEM_a3e1, DAT_EXTMEM_cab2;
extern unsigned char xdata DAT_EXTMEM_cbc1, DAT_EXTMEM_cbc2, DAT_EXTMEM_cbc3, DAT_EXTMEM_cbc4, DAT_EXTMEM_cbc5, DAT_EXTMEM_cbc6;
extern void FUN_CODE_abc4(uchar, uchar, uchar);
extern void FUN_CODE_c59a(uchar);
extern void FUN_CODE_c790(uchar);
extern void FUN_CODE_a775(uchar, uchar, uchar);
extern void FUN_CODE_c9b0(uchar);
extern void FUN_CODE_bde9(uchar, uchar);
extern void FUN_CODE_9f04(uchar);
extern void FUN_CODE_c2d3(uchar);
extern void FUN_CODE_c278(uchar);
extern void FUN_CODE_c03f(uchar);
extern void FUN_CODE_bbca(uchar, uchar);
extern void FUN_CODE_c7e0(uchar);
extern void FUN_CODE_de45(uchar);
extern void FUN_CODE_c965(uint);
extern void FUN_CODE_cd8c(void);
extern void FUN_CODE_d31d(void);
extern uchar FUN_CODE_c163(void);
extern void FUN_CODE_d3eb(void);
extern void FUN_CODE_d3b9(void);
extern void FUN_CODE_b781(void);
extern void FUN_CODE_dbdf(void);
extern void FUN_CODE_da91(void);
extern void FUN_CODE_cb1d(void);
extern void FUN_CODE_9fc8(uint, uchar);
extern void FUN_CODE_dee8(ulong);
extern void FUN_CODE_cbac(void);
extern void FUN_CODE_cbf2(void);
extern void FUN_CODE_71f0(void);
extern void FUN_CODE_dd41(void);
extern void FUN_CODE_ccc2(uchar);
extern void FUN_CODE_d351(void);
extern void FUN_CODE_7a0b(void);
extern void FUN_CODE_d171(void);
extern void FUN_CODE_de03(uint);
extern void FUN_CODE_dec2(uchar, uchar);
extern void FUN_CODE_decb(uchar, uchar);
extern void FUN_CODE_d70f(uchar, uchar, uchar);
extern void FUN_CODE_ba6d(uchar, uchar, uchar);
extern void FUN_CODE_deee(uchar);
extern void FUN_CODE_c830(uint);
extern void FUN_CODE_c87f(uchar, uchar);
extern void FUN_CODE_b228(uchar off, ulong *src, uchar n);
void FUN_CODE_d5a1(ulong off);
extern void FUN_CODE_de3a(uchar, uchar);
extern void FUN_CODE_0022(void);
extern void FUN_CODE_6c34(void);
extern void FUN_CODE_dd09(void);
extern void FUN_CODE_de2e(void);

void FUN_CODE_224f(ulong p)
{
    uchar cmd, b1, b2, b3;
    uint w;
    cmd = p & 0xFF;
    b1 = p >> 8;
    b2 = p >> 16;
    b3 = p >> 24;
    w = p >> 16;
    switch (cmd) {
    case 1: FUN_CODE_abc4(b1, b2, b3); FUN_CODE_c59a(b1); break;
    case 2: FUN_CODE_c790(b1); break;
    case 5: FUN_CODE_a775(b1, b2, b3); break;
    case 6: FUN_CODE_c9b0(b1); break;
    case 7: FUN_CODE_bde9(b1, b2); FUN_CODE_9f04(b1); FUN_CODE_c2d3(b1); break;
    case 8: FUN_CODE_c278(b1); break;
    case 9: FUN_CODE_c03f(b1); break;
    case 10: FUN_CODE_c03f(0); break;
    case 13: DAT_EXTMEM_a46d = b2; DAT_EXTMEM_a46c = b3; break;
    case 14: FUN_CODE_bbca(b1, b2); break;
    case 15: FUN_CODE_c7e0(b1); break;
    case 20: FUN_CODE_de45(b1); FUN_CODE_c965(((uint)b2 << 8) + b3); FUN_CODE_cd8c(); FUN_CODE_d31d(); break;
    case 17: if (FUN_CODE_c163()) FUN_CODE_d3eb(); FUN_CODE_cb1d(); break;
    case 18: if (FUN_CODE_c163()) FUN_CODE_d3b9(); FUN_CODE_b781(); FUN_CODE_dbdf(); FUN_CODE_cb1d(); break;
    case 19: if (FUN_CODE_c163()) FUN_CODE_da91(); FUN_CODE_cb1d(); break;
    case 21: if (FUN_CODE_c163()) FUN_CODE_9fc8(((uint)b2 << 8) + b3, b1); FUN_CODE_cb1d(); break;
    case 38:
        FUN_CODE_2820((void code *)0x54e4 /* "CMD_FE2P_SETEXTEND : %02X%02X%02X" */, (uint)b1, (uint)b2, (uint)b3);
        FUN_CODE_dee8(((ulong)b1 << 16) | ((ulong)b2 << 8) | b3);
        break;
    case 0x16:
        FUN_CODE_2820((void code *)0x5508 /* "CMD_SYS_POWERSAVING" */);
        FUN_CODE_cbac(); FUN_CODE_cbf2();
        DAT_EXTMEM_f150 = 9; DAT_EXTMEM_f152 |= 0x40;
        FUN_CODE_71f0();
        DAT_EXTMEM_a770 = 0;
        FUN_CODE_dd41();
        FUN_CODE_ccc2(0);
        if (DAT_EXTMEM_d511 == 0x20) FUN_CODE_d351();
        break;
    case 0x17:
        FUN_CODE_2820((void code *)0x551e /* "CMD_SYS_POWEROFF" */);
        FUN_CODE_cbac(); FUN_CODE_cbf2();
        DAT_EXTMEM_f150 = 9; DAT_EXTMEM_f152 |= 0x40;
        FUN_CODE_7a0b();
        DAT_EXTMEM_a770 = 1;
        FUN_CODE_dd41();
        break;
    case 33: FUN_CODE_2820((void code *)0x5531 /* "CMD_WRITE_DPTXHDCP" */); FUN_CODE_d171(); break;
    case 24: FUN_CODE_de03(w); break;
    case 25: FUN_CODE_dec2(b2, b3); break;
    case 26: FUN_CODE_decb(b2, b3); break;
    case 48: FUN_CODE_d70f(b1, b2, b3); break;
    case 49: FUN_CODE_ba6d(b1, b2, b3); break;
    case 27: FUN_CODE_deee(b2); break;
    case 28: FUN_CODE_c830(w); FUN_CODE_2820((void code *)0x5546 /* "setWakeupTimer %04x" */, w); break;
    case 29:
        DAT_EXTMEM_f0cc = 0x30; DAT_EXTMEM_f1f0 = 0xFF; SFR_A5 = 0xFF;
        if (w == 0) P1_4 = 0; else P1_4 = 1;
        FUN_CODE_2820((void code *)0x555c /* "CMD_SET_P14 %04x" */, w);
        break;
    case 30:
        DAT_EXTMEM_f0cc = 0x30; DAT_EXTMEM_f1f0 = 0xFF; SFR_A5 = 0xFF;
        if (w == 0) P1_5 = 0; else P1_5 = 1;
        FUN_CODE_2820((void code *)0x556f /* "CMD_SET_P15 %04x" */, w);
        break;
    case 31: FUN_CODE_c87f(b1, b2); break;
    case 32: FUN_CODE_d5a1(0x0C); break;
    case 34:
        if (b2) { DAT_EXTMEM_f1eb &= 0xF7; DAT_EXTMEM_f1e0 |= 0x08; }
        else    { DAT_EXTMEM_f1eb |= 0x08; DAT_EXTMEM_f1e0 &= 0xF7; }
        break;
    case 36: FUN_CODE_de3a(b2, b3); break;
    case 35:
        switch (b1) {
        case 0: DAT_EXTMEM_cbc1 = b2; break;
        case 1: DAT_EXTMEM_cbc2 = b2; break;
        case 2: DAT_EXTMEM_cbc3 = b2; break;
        case 3: DAT_EXTMEM_cbc4 = b2; break;
        case 4: DAT_EXTMEM_cbc5 = b2; break;
        case 5: DAT_EXTMEM_cbc6 = b2; break;
        }
        break;
    case 37:
        DAT_EXTMEM_f17c = b1;
        if (DAT_EXTMEM_d511 == 0x1A || DAT_EXTMEM_d511 == 0x20) {
            DAT_EXTMEM_a3e0 = b2; DAT_EXTMEM_a3e1 = b3;
            DAT_EXTMEM_f17d = 1;
            if (DAT_EXTMEM_d511 == 0x1A) { DAT_EXTMEM_f17e = 0xFF; DAT_EXTMEM_f17f = 0xFF; }
            else { DAT_EXTMEM_f17e = 0xAA; DAT_EXTMEM_f17f = 0; }
            DAT_EXTMEM_a35e = 0;
        }
        break;
    case 39:
        if (FUN_CODE_c163()) {
            DAT_EXTMEM_f00a = 0xAA; DAT_EXTMEM_f0e0 = 0xAA;
            if (DAT_EXTMEM_d511 == 0x20) FUN_CODE_0022();
        }
        FUN_CODE_cb1d();
        DAT_EXTMEM_f00a = 0x55; DAT_EXTMEM_f0e0 = 0x55;
        break;
    case 40:
        switch (b1) {
        case 0: if (b2) DAT_EXTMEM_cab2 |= 0x01; else DAT_EXTMEM_cab2 &= 0xFE; break;
        case 1: if (b2) DAT_EXTMEM_cab2 |= 0x04; else DAT_EXTMEM_cab2 &= 0xFB; break;
        }
        break;
    case 41: FUN_CODE_6c34(); break;
    case 42: FUN_CODE_dd09(); break;
    case 43: FUN_CODE_de2e(); break;
    case 3: case 4: case 11: case 12: case 16: case 44: case 45: case 46: case 47: break;
    }
    if (cmd != 0 && cmd != 0x16 && cmd != 0x17) FUN_CODE_d5a1(0);
}

void FUN_CODE_d5a1(ulong off)
{
    ulong v;
    v = 0;
    FUN_CODE_b228(off, &v, 1);
}
