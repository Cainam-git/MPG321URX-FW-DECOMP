/* 8051_bank1 FUN_CODE_6917 @ 0x6917..0x6AA6 (399 bytes), OPTIMIZE(8,SPEED) LARGE.
 * FUN_CODE_6917(ch, buf): LARGE parameters ch (XDATA 0xA517) and buf (generic pointer, 0xA518..0xA51A); locals
 * n 0xA51B, i 0xA51C. For ch 1..4 it copies bytes from one XDATA ring to buf[0], buf[1], ... (through
 * ?C?CSTOPTR), advancing the ring's IDATA read index after each byte and wrapping it to 0 at the ring size, until
 * the read index equals the ring's IDATA write index; then n = number of bytes copied. Other ch: n = 0. Returns n.
 *   ch 1: ring 0xA1E8 (16 bytes), read index IDATA 0x44 (byte), write index 0x42 (byte).
 *   ch 2: ring 0xA208 (0x38 bytes), read index 0x4C (byte), write index 0x47 (byte).
 *   ch 3: ring 0xA240 (0x38 bytes), read index 0x4E (uint), write index 0x48 (uint).
 *   ch 4: ring 0xA278 (0x38 bytes), read index 0x51 (uint), write index 0x4A (uint).
 * The rings are filled by the interrupt routines FUN_CODE_2c38 / FUN_CODE_3091. Caller: FUN_CODE_38a7 (0x3A1C).
 * Source form: the index increment and the wrap test are separate statements ('x++; if (x >= n) x = 0;'), which
 * gives the firmware's re-read of the index; '++x >= n' keeps it in a register.
 */
extern unsigned char xdata DAT_EXTMEM_a1e8[];
extern unsigned char xdata DAT_EXTMEM_a208[], DAT_EXTMEM_a240[];
extern unsigned char xdata DAT_EXTMEM_a278[];
extern unsigned char idata DAT_INTMEM_42, DAT_INTMEM_44, DAT_INTMEM_47, DAT_INTMEM_4c;
extern unsigned int idata DAT_INTMEM_48, DAT_INTMEM_4e, DAT_INTMEM_4a, DAT_INTMEM_51;

unsigned char FUN_CODE_6917(unsigned char ch, unsigned char *buf)
{
    unsigned char n, i;

    n = 0;
    if (ch == 1) {
        for (i = 0; ; i++) {
            buf[i] = DAT_EXTMEM_a1e8[DAT_INTMEM_44];
            DAT_INTMEM_44++;
            if (DAT_INTMEM_44 >= 0x10) DAT_INTMEM_44 = 0;
            if (DAT_INTMEM_42 == DAT_INTMEM_44) { n = i + 1; break; }
        }
    } else if (ch == 2) {
        for (i = 0; ; i++) {
            buf[i] = DAT_EXTMEM_a208[DAT_INTMEM_4c];
            DAT_INTMEM_4c++;
            if (DAT_INTMEM_4c >= 0x38) DAT_INTMEM_4c = 0;
            if (DAT_INTMEM_47 == DAT_INTMEM_4c) { n = i + 1; break; }
        }
    } else if (ch == 3) {
        for (i = 0; ; i++) {
            buf[i] = DAT_EXTMEM_a240[DAT_INTMEM_4e];
            DAT_INTMEM_4e++;
            if (DAT_INTMEM_4e >= 0x38) DAT_INTMEM_4e = 0;
            if (DAT_INTMEM_48 == DAT_INTMEM_4e) { n = i + 1; break; }
        }
    } else if (ch == 4) {
        for (i = 0; ; i++) {
            buf[i] = DAT_EXTMEM_a278[DAT_INTMEM_51];
            DAT_INTMEM_51++;
            if (DAT_INTMEM_51 >= 0x38) DAT_INTMEM_51 = 0;
            if (DAT_INTMEM_4a == DAT_INTMEM_51) { n = i + 1; break; }
        }
    }
    return n;
}
