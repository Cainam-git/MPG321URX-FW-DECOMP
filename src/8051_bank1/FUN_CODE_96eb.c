/* 8051_bank1 FUN_CODE_96eb @ 0x96EB..0x97C4 (217 bytes)  STBC start-up: load and start the USB MCU (bank-2 image)
 * MATCH: tools/diff8051.py 8051_bank1 FUN_CODE_96eb -> 217/217, 100 %, exact None, OPTIMIZE(7,SPEED)
 * (LARGE by pragma; the function has no xdata locals: i / j live in R6:R7 / R4:R5, p stays in R1..R3).
 * What it does (code):
 *   1. chip ID 0xD511 == 0x1A: pulse 0xD5AF bit 0 (1 then 0); else 0xF15A = 3 then 0.
 *   2. 0xF1E0 = 0xC1, 0xCD0A = 0xCD2A = 0xC0; busy wait 100 x 1000 x 8 NOPs; 0xCD0A = 0xCD2A = 0x40; 0xF1E0 = 0.
 *   3. Loader block 0xF166..0xF16F: F168 = F169 = 0, F16A/F16B/F16C = p[3]/p[2]/p[1] (24-bit flash address, low byte
 *      first), F16D/F16E/F16F = p[7]/p[6]/p[5] (24-bit length), F166 = 0xFF, F167 = 0x87, wait until F167 reads 0.
 *      Same layout and start value 0x87 as the boot loader's F1D1..F1D8 / F1D0 = 0x87 (FUN_CODE_0003 / 151c).
 *   4. Writes the six bytes "USBONE" (0x55 53 42 4F 4E 45) to 0xF1E5, then F1E4 = 0, F1EB = 0x8A, F1E0 = 0.
 * p = &0xA47F (only caller FUN_CODE_0b0d at 0x0C46) = share-structure kind 1, which FUN_CODE_0003 fills from partition
 *   table bytes 0x08..0x0F: in FW.021 '00 02 00 00 00 00 E5 52' = flash 0x020000, length 0xE552 = the 8051_bank2
 *   image. Bank 2 is the USB code: its strings include "fotg210: reset by host", "Device Mode Init",
 *   "CMD_LOADFILE2DRAM", "STATUS_WAIT_FW_UPDATE", "CMD_START_ISP_ROMCODE_MODE".
 * F1E0 elsewhere (code): FUN_CODE_7a0b (0x7A0D) and FUN_CODE_71f0 (0x71F2) write F1E0 = 0xC1 as their first register
 *   write; 224f command 0x22 toggles F1E0 / F1EB bit 3. 7a0b is the hardware sequence of CMD_SYS_POWEROFF and of the
 *   FUN_CODE_7b5a crash path, and no code after the 7b5a park writes F1E0 again. 96eb runs only from 0b0d (start-up
 *   at 0x406B and wake-up at 0x42D5 in FUN_CODE_3fe7).
 * Order: the USB MCU is loaded by the 8051 BEFORE the Big chip is started (0x0C46 is before 4a85 / 8e61). After
 *   the 7b5a trip F1E0 stays 0xC1, the value 96eb uses while it holds the block.
 * volatile only on hardware registers: 0xF1xx, 0xD511 (chip ID) and 0xD5AF (its bit pulse re-reads the register at
 *   0x96F9; without volatile 35.5 %). 0xCD0A / 0xCD2A are plain (same bytes either way).
 */
#pragma LARGE
#include <intrins.h>
extern unsigned char volatile xdata DAT_EXTMEM_d511, DAT_EXTMEM_d5af, DAT_EXTMEM_f15a, DAT_EXTMEM_f1e0;
extern unsigned char xdata DAT_EXTMEM_cd0a, DAT_EXTMEM_cd2a;
extern unsigned char volatile xdata DAT_EXTMEM_f166, DAT_EXTMEM_f167, DAT_EXTMEM_f168, DAT_EXTMEM_f169, DAT_EXTMEM_f16a, DAT_EXTMEM_f16b;
extern unsigned char volatile xdata DAT_EXTMEM_f16c, DAT_EXTMEM_f16d, DAT_EXTMEM_f16e, DAT_EXTMEM_f16f, DAT_EXTMEM_f1e5, DAT_EXTMEM_f1e4, DAT_EXTMEM_f1eb;
void FUN_CODE_96eb(unsigned char *p)
{
    unsigned int i, j;
    if (DAT_EXTMEM_d511 == 0x1A) {
        DAT_EXTMEM_d5af |= 0x01;
        DAT_EXTMEM_d5af &= 0xFE;
    } else {
        DAT_EXTMEM_f15a = 3;
        DAT_EXTMEM_f15a = 0;
    }
    DAT_EXTMEM_f1e0 = 0xC1;
    DAT_EXTMEM_cd0a = 0xC0;
    DAT_EXTMEM_cd2a = 0xC0;
    for (i = 0; i != 100; i++)
        for (j = 0; j != 1000; j++) {
            _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
        }
    DAT_EXTMEM_cd0a = 0x40;
    DAT_EXTMEM_cd2a = 0x40;
    DAT_EXTMEM_f1e0 = 0;
    DAT_EXTMEM_f168 = 0;
    DAT_EXTMEM_f169 = 0;
    DAT_EXTMEM_f16a = p[3];
    DAT_EXTMEM_f16b = p[2];
    DAT_EXTMEM_f16c = p[1];
    DAT_EXTMEM_f16d = p[7];
    DAT_EXTMEM_f16e = p[6];
    DAT_EXTMEM_f16f = p[5];
    DAT_EXTMEM_f166 = 0xFF;
    DAT_EXTMEM_f167 = 0x87;
    while (DAT_EXTMEM_f167 != 0) ;
    DAT_EXTMEM_f1e5 = 'U';
    DAT_EXTMEM_f1e5 = 'S';
    DAT_EXTMEM_f1e5 = 'B';
    DAT_EXTMEM_f1e5 = 'O';
    DAT_EXTMEM_f1e5 = 'N';
    DAT_EXTMEM_f1e5 = 'E';
    DAT_EXTMEM_f1e4 = 0;
    DAT_EXTMEM_f1eb = 0x8A;
    DAT_EXTMEM_f1e0 = 0;
}
