/* 8051_bank0 FUN_CODE_0003 @ 0x0003  STBC boot loader: load the partition table (byte-exact with
 * OPTIMIZE(7,SPEED); 0x0003..0x0926, one function: Ghidra had split it at 0x082e).
 * Called via FUN_CODE_1899 from main FUN_CODE_151c. Slot = 0x1000 when CODE 0x7FFF == 0xAA, else 0: the table is
 * at CODE 0x6000 (slot 0) or 0x7000 (slot 1).
 *   0xF1D3 / 0xF1D4 / 0xF1D5 = table bytes 3, 2, 1 (address of the next image).
 *   Slot 1 only: if bytes 0xFF0..0xFF5 of the slot read "DUALFW", the 8 bytes after it patch three XDATA registers
 *   (high byte p0 shared: [p0:p1] &= p2, [p0:p3] |= p4, [p0:p5] = p7 ? x & p6 : x | p6), each printed as
 *   "[0x%04X] = %02BX", then the flash is identified again (FUN_CODE_111f). FW.021 has no DUALFW marker.
 *   Table byte 0 != 0: SetExtendedAddr(byte 0) (FUN_CODE_180d): the image lives in the upper 16 MiB.
 *   0xF1D1 = 0xF1D2 = 0; 0xF1D6 / 0xF1D7 / 0xF1D8 = table bytes 7, 6, 5 (size of the next image).
 *   Share structure (FUN_CODE_1346): kind 0 = version 00 01; kinds 1..9 = 12-byte descriptors built in XDATA 0xA000..
 *   from table bytes 0x08..0x67 (kinds 2 and 3 also carry constants 9F 06 00 00 and 9F 19 60 00 ... 07 FF).
 * NO VALIDATION AT ALL: no checksum, no range check, no signature on the table; the result bit is set at the start
 * and never cleared (byte search: no CLR 20.2 anywhere in the boot loader), so "Can't find valid partition table!!!"
 * in main is unreachable. Whatever sits at 0x6000 / 0x7000 is handed to the hardware as is (same finding as the
 * public MPG 341CQPX write-up; that boot code is byte-identical to this one outside the table).
 */
extern unsigned char code DAT_CODE_6000[];
extern unsigned char xdata DAT_EXTMEM_a000[];
extern unsigned char volatile xdata DAT_EXTMEM_f1d1, DAT_EXTMEM_f1d2, DAT_EXTMEM_f1d3, DAT_EXTMEM_f1d4, DAT_EXTMEM_f1d5;
extern unsigned char volatile xdata DAT_EXTMEM_f1d6, DAT_EXTMEM_f1d7, DAT_EXTMEM_f1d8, DAT_EXTMEM_f00a;
extern void FUN_CODE_0989(void *fmt, ...);
void FUN_CODE_111f(void);
void FUN_CODE_180d(unsigned char ear);
void FUN_CODE_1346(unsigned char kind, unsigned char len, unsigned char *src);

bit FUN_CODE_0003(void)
{
    unsigned char z;        /* DATA 0x22: set to 0 and never read (dead store in the original) */
    unsigned int slot;
    unsigned char ver[2];   /* share-structure version 00 01 */
    unsigned char prm[8];   /* DUALFW parameters */
    unsigned char i;
    unsigned char xdata *p;
    bit ok;                 /* bit 0x20.2: set here, never cleared -> always "valid" */
    z = 0;
    ok = 1;
    ver[0] = 0;
    ver[1] = 1;
    if (DAT_CODE_6000[0x1fff] == 0xaa) slot = 0x1000; else slot = 0;
    DAT_EXTMEM_f1d3 = DAT_CODE_6000[slot + 3];
    DAT_EXTMEM_f1d4 = DAT_CODE_6000[slot + 2];
    DAT_EXTMEM_f1d5 = DAT_CODE_6000[slot + 1];
    if (slot != 0 && DAT_CODE_6000[slot + 0x0ff0] == 'D' && DAT_CODE_6000[slot + 0x0ff1] == 'U' && DAT_CODE_6000[slot + 0x0ff2] == 'A'
        && DAT_CODE_6000[slot + 0x0ff3] == 'L' && DAT_CODE_6000[slot + 0x0ff4] == 'F' && DAT_CODE_6000[slot + 0x0ff5] == 'W') {
        for (i = 0; i < 8; i++) {
            prm[i] = DAT_CODE_6000[slot + 0x0ff6 + i];
            DAT_EXTMEM_f00a = 0x55;
        }
        p = (unsigned char xdata *)((prm[0] << 8) + prm[1]);
        *p &= prm[2];
        FUN_CODE_0989((void code *)0x1886, (unsigned int)p, *p);
        p = (unsigned char xdata *)((prm[0] << 8) + prm[3]);
        *p |= prm[4];
        FUN_CODE_0989((void code *)0x1886, (unsigned int)p, *p);
        p = (unsigned char xdata *)((prm[0] << 8) + prm[5]);
        if (prm[7]) *p &= prm[6]; else *p |= prm[6];
        FUN_CODE_0989((void code *)0x1886, (unsigned int)p, *p);
        DAT_EXTMEM_f00a = 0x55;
        FUN_CODE_111f();
    }
    if (DAT_CODE_6000[slot]) FUN_CODE_180d(DAT_CODE_6000[slot]);
    DAT_EXTMEM_f1d1 = 0;
    DAT_EXTMEM_f1d2 = 0;
    DAT_EXTMEM_f1d6 = DAT_CODE_6000[slot + 7];
    DAT_EXTMEM_f1d7 = DAT_CODE_6000[slot + 6];
    DAT_EXTMEM_f1d8 = DAT_CODE_6000[slot + 5];
    FUN_CODE_1346(0, 2, ver);
    DAT_EXTMEM_a000[0x00] = DAT_CODE_6000[slot + 0x08];
    DAT_EXTMEM_a000[0x01] = DAT_CODE_6000[slot + 0x09];
    DAT_EXTMEM_a000[0x02] = DAT_CODE_6000[slot + 0x0a];
    DAT_EXTMEM_a000[0x03] = DAT_CODE_6000[slot + 0x0b];
    DAT_EXTMEM_a000[0x04] = DAT_CODE_6000[slot + 0x0c];
    DAT_EXTMEM_a000[0x05] = DAT_CODE_6000[slot + 0x0d];
    DAT_EXTMEM_a000[0x06] = DAT_CODE_6000[slot + 0x0e];
    DAT_EXTMEM_a000[0x07] = DAT_CODE_6000[slot + 0x0f];
    FUN_CODE_1346(1, 0x0c, &DAT_EXTMEM_a000[0x00]);
    DAT_EXTMEM_a000[0x0c] = DAT_CODE_6000[slot + 0x10];
    DAT_EXTMEM_a000[0x0d] = DAT_CODE_6000[slot + 0x11];
    DAT_EXTMEM_a000[0x0e] = DAT_CODE_6000[slot + 0x12];
    DAT_EXTMEM_a000[0x0f] = DAT_CODE_6000[slot + 0x13];
    DAT_EXTMEM_a000[0x10] = DAT_CODE_6000[slot + 0x14];
    DAT_EXTMEM_a000[0x11] = DAT_CODE_6000[slot + 0x15];
    DAT_EXTMEM_a000[0x12] = DAT_CODE_6000[slot + 0x16];
    DAT_EXTMEM_a000[0x13] = DAT_CODE_6000[slot + 0x17];
    DAT_EXTMEM_a000[0x14] = DAT_CODE_6000[slot + 0x18];
    DAT_EXTMEM_a000[0x15] = DAT_CODE_6000[slot + 0x19];
    DAT_EXTMEM_a000[0x16] = DAT_CODE_6000[slot + 0x1a];
    DAT_EXTMEM_a000[0x17] = DAT_CODE_6000[slot + 0x1b];
    DAT_EXTMEM_a000[0x1c] = DAT_CODE_6000[slot + 0x1c];
    DAT_EXTMEM_a000[0x1d] = DAT_CODE_6000[slot + 0x1d];
    DAT_EXTMEM_a000[0x1e] = DAT_CODE_6000[slot + 0x1e];
    DAT_EXTMEM_a000[0x1f] = DAT_CODE_6000[slot + 0x1f];
    DAT_EXTMEM_a000[0x20] = DAT_CODE_6000[slot + 0x20];
    DAT_EXTMEM_a000[0x21] = DAT_CODE_6000[slot + 0x21];
    DAT_EXTMEM_a000[0x22] = DAT_CODE_6000[slot + 0x22];
    DAT_EXTMEM_a000[0x23] = DAT_CODE_6000[slot + 0x23];
    DAT_EXTMEM_a000[0x18] = 0x9f;
    DAT_EXTMEM_a000[0x19] = 0x06;
    DAT_EXTMEM_a000[0x1a] = 0x00;
    DAT_EXTMEM_a000[0x1b] = 0x00;
    DAT_EXTMEM_a000[0x24] = 0x00;
    DAT_EXTMEM_a000[0x25] = 0x00;
    DAT_EXTMEM_a000[0x26] = 0x00;
    DAT_EXTMEM_a000[0x27] = 0x00;
    DAT_EXTMEM_a000[0x28] = 0x00;
    DAT_EXTMEM_a000[0x29] = 0x00;
    DAT_EXTMEM_a000[0x2a] = 0x00;
    DAT_EXTMEM_a000[0x2b] = 0x00;
    FUN_CODE_1346(2, 0x24, &DAT_EXTMEM_a000[0x0c]);
    DAT_EXTMEM_a000[0x30] = DAT_CODE_6000[slot + 0x28];
    DAT_EXTMEM_a000[0x31] = DAT_CODE_6000[slot + 0x29];
    DAT_EXTMEM_a000[0x32] = DAT_CODE_6000[slot + 0x2a];
    DAT_EXTMEM_a000[0x33] = DAT_CODE_6000[slot + 0x2b];
    DAT_EXTMEM_a000[0x34] = DAT_CODE_6000[slot + 0x2c];
    DAT_EXTMEM_a000[0x35] = DAT_CODE_6000[slot + 0x2d];
    DAT_EXTMEM_a000[0x36] = DAT_CODE_6000[slot + 0x2e];
    DAT_EXTMEM_a000[0x37] = DAT_CODE_6000[slot + 0x2f];
    DAT_EXTMEM_a000[0x38] = DAT_CODE_6000[slot + 0x30];
    DAT_EXTMEM_a000[0x39] = DAT_CODE_6000[slot + 0x31];
    DAT_EXTMEM_a000[0x3a] = DAT_CODE_6000[slot + 0x32];
    DAT_EXTMEM_a000[0x3b] = DAT_CODE_6000[slot + 0x33];
    DAT_EXTMEM_a000[0x40] = DAT_CODE_6000[slot + 0x34];
    DAT_EXTMEM_a000[0x41] = DAT_CODE_6000[slot + 0x35];
    DAT_EXTMEM_a000[0x42] = DAT_CODE_6000[slot + 0x36];
    DAT_EXTMEM_a000[0x43] = DAT_CODE_6000[slot + 0x37];
    DAT_EXTMEM_a000[0x44] = DAT_CODE_6000[slot + 0x40];
    DAT_EXTMEM_a000[0x45] = DAT_CODE_6000[slot + 0x41];
    DAT_EXTMEM_a000[0x46] = DAT_CODE_6000[slot + 0x42];
    DAT_EXTMEM_a000[0x47] = DAT_CODE_6000[slot + 0x43];
    DAT_EXTMEM_a000[0x48] = DAT_CODE_6000[slot + 0x44];
    DAT_EXTMEM_a000[0x49] = DAT_CODE_6000[slot + 0x45];
    DAT_EXTMEM_a000[0x4a] = DAT_CODE_6000[slot + 0x46];
    DAT_EXTMEM_a000[0x4b] = DAT_CODE_6000[slot + 0x47];
    DAT_EXTMEM_a000[0x3c] = 0x9f;
    DAT_EXTMEM_a000[0x3d] = 0x19;
    DAT_EXTMEM_a000[0x3e] = 0x60;
    DAT_EXTMEM_a000[0x3f] = 0x00;
    DAT_EXTMEM_a000[0x4c] = 0x00;
    DAT_EXTMEM_a000[0x4d] = 0x00;
    DAT_EXTMEM_a000[0x4e] = 0x00;
    DAT_EXTMEM_a000[0x4f] = 0x00;
    DAT_EXTMEM_a000[0x50] = 0x00;
    DAT_EXTMEM_a000[0x51] = 0x00;
    DAT_EXTMEM_a000[0x52] = 0x07;
    DAT_EXTMEM_a000[0x53] = 0xff;
    FUN_CODE_1346(3, 0x28, &DAT_EXTMEM_a000[0x30]);
    DAT_EXTMEM_a000[0x58] = DAT_CODE_6000[slot + 0x38];
    DAT_EXTMEM_a000[0x59] = DAT_CODE_6000[slot + 0x39];
    DAT_EXTMEM_a000[0x5a] = DAT_CODE_6000[slot + 0x3a];
    DAT_EXTMEM_a000[0x5b] = DAT_CODE_6000[slot + 0x3b];
    DAT_EXTMEM_a000[0x5c] = DAT_CODE_6000[slot + 0x3c];
    DAT_EXTMEM_a000[0x5d] = DAT_CODE_6000[slot + 0x3d];
    DAT_EXTMEM_a000[0x5e] = DAT_CODE_6000[slot + 0x3e];
    DAT_EXTMEM_a000[0x5f] = DAT_CODE_6000[slot + 0x3f];
    FUN_CODE_1346(4, 0x0c, &DAT_EXTMEM_a000[0x58]);
    DAT_EXTMEM_a000[0x64] = DAT_CODE_6000[slot + 0x48];
    DAT_EXTMEM_a000[0x65] = DAT_CODE_6000[slot + 0x49];
    DAT_EXTMEM_a000[0x66] = DAT_CODE_6000[slot + 0x4a];
    DAT_EXTMEM_a000[0x67] = DAT_CODE_6000[slot + 0x4b];
    DAT_EXTMEM_a000[0x68] = DAT_CODE_6000[slot + 0x4c];
    DAT_EXTMEM_a000[0x69] = DAT_CODE_6000[slot + 0x4d];
    DAT_EXTMEM_a000[0x6a] = DAT_CODE_6000[slot + 0x4e];
    DAT_EXTMEM_a000[0x6b] = DAT_CODE_6000[slot + 0x4f];
    FUN_CODE_1346(6, 0x0c, &DAT_EXTMEM_a000[0x64]);
    DAT_EXTMEM_a000[0x70] = DAT_CODE_6000[slot + 0x50];
    DAT_EXTMEM_a000[0x71] = DAT_CODE_6000[slot + 0x51];
    DAT_EXTMEM_a000[0x72] = DAT_CODE_6000[slot + 0x52];
    DAT_EXTMEM_a000[0x73] = DAT_CODE_6000[slot + 0x53];
    DAT_EXTMEM_a000[0x74] = DAT_CODE_6000[slot + 0x54];
    DAT_EXTMEM_a000[0x75] = DAT_CODE_6000[slot + 0x55];
    DAT_EXTMEM_a000[0x76] = DAT_CODE_6000[slot + 0x56];
    DAT_EXTMEM_a000[0x77] = DAT_CODE_6000[slot + 0x57];
    FUN_CODE_1346(7, 0x0c, &DAT_EXTMEM_a000[0x70]);
    DAT_EXTMEM_a000[0x7c] = DAT_CODE_6000[slot + 0x58];
    DAT_EXTMEM_a000[0x7d] = DAT_CODE_6000[slot + 0x59];
    DAT_EXTMEM_a000[0x7e] = DAT_CODE_6000[slot + 0x5a];
    DAT_EXTMEM_a000[0x7f] = DAT_CODE_6000[slot + 0x5b];
    DAT_EXTMEM_a000[0x80] = DAT_CODE_6000[slot + 0x5c];
    DAT_EXTMEM_a000[0x81] = DAT_CODE_6000[slot + 0x5d];
    DAT_EXTMEM_a000[0x82] = DAT_CODE_6000[slot + 0x5e];
    DAT_EXTMEM_a000[0x83] = DAT_CODE_6000[slot + 0x5f];
    FUN_CODE_1346(8, 0x0c, &DAT_EXTMEM_a000[0x7c]);
    DAT_EXTMEM_a000[0x88] = DAT_CODE_6000[slot + 0x60];
    DAT_EXTMEM_a000[0x89] = DAT_CODE_6000[slot + 0x61];
    DAT_EXTMEM_a000[0x8a] = DAT_CODE_6000[slot + 0x62];
    DAT_EXTMEM_a000[0x8b] = DAT_CODE_6000[slot + 0x63];
    DAT_EXTMEM_a000[0x8c] = DAT_CODE_6000[slot + 0x64];
    DAT_EXTMEM_a000[0x8d] = DAT_CODE_6000[slot + 0x65];
    DAT_EXTMEM_a000[0x8e] = DAT_CODE_6000[slot + 0x66];
    DAT_EXTMEM_a000[0x8f] = DAT_CODE_6000[slot + 0x67];
    FUN_CODE_1346(9, 0x0c, &DAT_EXTMEM_a000[0x88]);
    return ok;
}
