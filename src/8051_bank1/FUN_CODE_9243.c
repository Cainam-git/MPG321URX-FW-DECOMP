/* 8051_bank1 FUN_CODE_9243 @ 0x9243..0x9339 (246 bytes)  STBC mailbox service, once per main-loop pass.
 * MATCH: tools/diff8051.py 8051_bank1 FUN_CODE_9243 -> 246/246 bytes, 100 %, exact None, at OPTIMIZE(8,SPEED) LARGE.
 * This file is one Keil MODULE: FUN_CODE_8512, FUN_CODE_960f, FUN_CODE_9243, FUN_CODE_a4e9, FUN_CODE_b228. Reason
 * (code): the firmware's FUN_CODE_a4e9 has a Keil OPTIMIZE(8) common-entry block 0xA4D2..0xA4E9 with entry points
 * used only by 8512 (0xA4D2, 0xA4D6), 960f (0xA4E0, 0xA4E3) and 9243 (0xA4E5 'MOV A,#5'), and b228 has the block
 * 0xB222 used by 9243's two calls. Keil builds such a block only from calls inside the same module, so these
 * functions were one module; without 8512 in the unit 9243 drops to 50.8 %.
 * Status of the other members in THIS unit: FUN_CODE_a4e9 and FUN_CODE_b228 are the byte-exact bodies
 *   (FUN_CODE_a4e9 MATCH 149/149 standalone; src/8051_bank1/FUN_CODE_b228.c). FUN_CODE_8512
 *   (61.8 %) and FUN_CODE_960f (43.2 %) are NOT byte-exact yet: their logic is read from the firmware and their
 *   call sites already give the exact a4e9 block, but two shapes differ: (1) the slot test 'ULCMP / JZ +2 / SJMP
 *   break' (fw 0x9649, 0x96A6, 0x859E, 0x85EA; every 'if (..) break' form tried gives a direct JNZ/JZ), (2) in 8512
 *   the bit mask '1 << n' is fw 'CLR A / INC A / MOV R0,R7' (this source gives 'CLR A / MOV R0,R7 / INC A').
 * Key for 9243: the d5a1 argument is '(unsigned int)(idx * 20 + 0x10)' (fw zero-extends R4/R5 with CLR A).
 * Mailbox layout (code facts; AHB 0x9F0A0100 + offset = the Main <-> helper portal, FUN_CODE_a4e9 = read n words,
 *   FUN_CODE_b228 = write n words):
 *   +0x00        command word from the Big chip (FUN_a002f3f4 on the Big chip writes it).
 *   +0x10+20*i   4 message slots Big chip -> 8051 (i = 0..3), 5 words; slot is full when header bits 3..0 != 0.
 *   +0x60+20*i   4 message slots 8051 -> Big chip, header word +0x60, payload 4 words +0x64.
 *   +0xB8        boot / wake byte in bits 15..8 (FUN_CODE_c544).
 * What FUN_CODE_9243 does (code facts):
 *   1. FUN_CODE_c103 (reads and rewrites word +0x0C); cmd = word +0x00; FUN_CODE_224f(cmd): the 49-way command
 *      switch (it acts when the low byte is 1..49; e.g. 0x16 CMD_SYS_POWERSAVING, 0x17 CMD_SYS_POWEROFF, 0x29 the
 *      flash command loop FUN_CODE_6c34).
 *   2. Return if the command changed the run state 0xA770 away from 2.
 *   3. Up to 100 rounds (0xF00A = 0x55 each): i = FUN_CODE_960f() (next full Big->8051 slot, round robin from
 *      0xA358; 0xFE = none -> stop); read its 5 words to msg; FUN_CODE_1c3c(msg) handles it; FUN_CODE_d5a1(off)
 *      writes 0 to the slot header (frees it).
 *   4. Up to 100 rounds (0xF00A = 0x55 each): i = FUN_CODE_8512() (it first ORs into 0xA3E3 the bit (header >> 8)
 *      of every 8051->Big slot whose header bits 3..0 == 3, then returns the next free slot from 0xA3E2, 0xFF =
 *      none -> stop); FUN_CODE_5c06(msg) fills an outgoing message (header 0 = nothing to send -> stop); write the
 *      payload words to +0x64+20*i and then the header to +0x60+20*i; FUN_CODE_ddf4 advances 0xA3E2.
 * Dead Big chip: both loops are bounded (100 rounds), so this function cannot hang the 8051 when the Big chip is
 *   dead: with a halted Big chip no command and no message arrives, 9243 returns, and the "SYSTEM CRASH"
 *   check FUN_CODE_7b5a that FUN_CODE_3fe7 calls right after it trips once the 15000-tick ring-1 limit is passed.
 *   Everything the tool path needs from the 8051 (command 7 = I2C slave set-up, command 0x29 = flash loop) only
 *   happens when the Big chip writes a command word here.
 * volatile only on 0xF00A (hardware register); everything else is RAM or goes through the AHB bridge functions.
 */
typedef union { unsigned long l; unsigned char b[4]; } DW;
extern unsigned char volatile xdata DAT_EXTMEM_f00a;
extern unsigned char xdata DAT_EXTMEM_a770;
extern DW xdata DAT_EXTMEM_a4e7;
extern DW xdata DAT_EXTMEM_a4ec;
extern DW xdata DAT_EXTMEM_a4f0;
extern DW FUN_CODE_bcad(void);
extern void FUN_CODE_beb5(void);
extern void FUN_CODE_c103(void);
extern void FUN_CODE_224f(unsigned long cmd);
extern unsigned char xdata DAT_EXTMEM_a358;
extern unsigned char xdata DAT_EXTMEM_a3e2, DAT_EXTMEM_a3e3;
void FUN_CODE_a4e9(unsigned char off, unsigned long *dst, unsigned char n);
void FUN_CODE_b228(unsigned char off, unsigned long *src, unsigned char n);
unsigned char FUN_CODE_960f(void);
extern void FUN_CODE_1c3c(unsigned long *msg);
extern void FUN_CODE_5c06(unsigned long *msg);
extern void FUN_CODE_d5a1(unsigned long off);
extern void FUN_CODE_ddf4(void);


void FUN_CODE_9243(void);

unsigned char FUN_CODE_8512(void)
{
    unsigned long hdr;
    unsigned char r;
    unsigned char start;

    r = 0xff;
    DAT_EXTMEM_a3e3 = 0;
    for (r = 0; r < 4; r++) {
        FUN_CODE_a4e9(r * 20 + 0x60, &hdr, 1);
        if ((hdr & 0x0f) == 3) DAT_EXTMEM_a3e3 |= 1 << ((hdr >> 8) & 0xff);
    }
    start = DAT_EXTMEM_a3e2;
    for (r = 0; r < 4; r++) {
        FUN_CODE_a4e9(DAT_EXTMEM_a3e2 * 20 + 0x60, &hdr, 1);
        if ((hdr & 0x0f) == 0) break;
        DAT_EXTMEM_a3e2++;
        if (DAT_EXTMEM_a3e2 >= 4) DAT_EXTMEM_a3e2 = 0;
    }
    if (r != 0 && r != 4) {
        DAT_EXTMEM_a3e2 = start;
        for (r = 0; r < 4; r++) {
            FUN_CODE_a4e9(DAT_EXTMEM_a3e2 * 20 + 0x60, &hdr, 1);
            if ((hdr & 0x0f) == 0) break;
            DAT_EXTMEM_a3e2++;
            if (DAT_EXTMEM_a3e2 >= 4) DAT_EXTMEM_a3e2 = 0;
        }
    }
    if (r == 4) r = 0xff;
    else r = DAT_EXTMEM_a3e2;
    return r;
}

unsigned char FUN_CODE_960f(void)
{
    unsigned long hdr;
    unsigned char r;
    unsigned char start;

    r = 0xff;
    start = DAT_EXTMEM_a358;
    for (r = 0; r < 4; r++) {
        FUN_CODE_a4e9(DAT_EXTMEM_a358 * 20 + 0x10, &hdr, 1);
        if ((hdr & 0x0f) != 0) break;
        DAT_EXTMEM_a358++;
        if (DAT_EXTMEM_a358 >= 4) DAT_EXTMEM_a358 = 0;
    }
    if (r != 0 && r != 4) {
        DAT_EXTMEM_a358 = start;
        for (r = 0; r < 4; r++) {
            FUN_CODE_a4e9(DAT_EXTMEM_a358 * 20 + 0x10, &hdr, 1);
            if ((hdr & 0x0f) != 0) break;
            DAT_EXTMEM_a358++;
            if (DAT_EXTMEM_a358 >= 4) DAT_EXTMEM_a358 = 0;
        }
    }
    if (r == 4) {
        r = 0xfe;
    } else {
        r = DAT_EXTMEM_a358;
        DAT_EXTMEM_a358++;
        if (DAT_EXTMEM_a358 >= 4) DAT_EXTMEM_a358 = 0;
    }
    return r;
}

void FUN_CODE_9243(void)
{
    unsigned char idx;
    unsigned char n1;
    unsigned char n2;
    unsigned long cmd;
    unsigned long msg[5];

    FUN_CODE_c103();
    FUN_CODE_a4e9(0, &cmd, 1);
    FUN_CODE_224f(cmd);
    if (DAT_EXTMEM_a770 != 2) return;
    n1 = 100;
    do {
        DAT_EXTMEM_f00a = 0x55;
        idx = FUN_CODE_960f();
        if (idx == 0xfe) break;
        FUN_CODE_a4e9(idx * 20 + 0x10, msg, 5);
        FUN_CODE_1c3c(msg);
        FUN_CODE_d5a1((unsigned int)(idx * 20 + 0x10));
        n1--;
    } while (n1 > 0);
    n2 = 100;
    do {
        DAT_EXTMEM_f00a = 0x55;
        idx = FUN_CODE_8512();
        if (idx == 0xff) break;
        FUN_CODE_5c06(msg);
        if (msg[0] == 0) break;
        FUN_CODE_b228(idx * 20 + 0x64, &msg[1], 4);
        FUN_CODE_b228(idx * 20 + 0x60, &msg[0], 1);
        FUN_CODE_ddf4();
        n2--;
    } while (n2 > 0);
}

void FUN_CODE_a4e9(unsigned char off, unsigned long *dst, unsigned char n)
{
    unsigned char i;
    DW addr;
    DW val;
    addr.l = 0x9F0A0100;
    for (i = 0; i < n; i++) {
        addr.b[3] = off + i * 4;
        DAT_EXTMEM_a4e7 = addr;
        val = FUN_CODE_bcad();
        dst[i] = val.l;
    }
}

void FUN_CODE_b228(unsigned char off, unsigned long *src, unsigned char n)
{
    unsigned char i;
    DW addr;
    DW val;
    addr.l = 0x9F0A0100;
    for (i = 0; i < n; i++) {
        addr.b[3] = off + i * 4;
        val.l = src[i];
        DAT_EXTMEM_a4ec = addr;
        DAT_EXTMEM_a4f0 = val;
        FUN_CODE_beb5();
    }
}
