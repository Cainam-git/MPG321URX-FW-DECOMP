/* leon2m FUN_a01295e4 @ 0xa01295e4  OLED FRC power-up handler (hand; bitfield state word)
 *
 * State machine for the OLED panel's FRC chip, state = top 4 bits of the halfword at 0xA802D892, +2 = timestamp
 * (ms tick, FUN_a002d588/FUN_a002d594), bits 0x400/0x800 = flags, low byte = a channel/mode number.
 * Pins: P = FUN_a0124828() = GPIO group 13 bit 5 (0xCF03C478 & 0x20); R = FUN_a01248c8() = GPIO group 9 bit 3
 * (0xCF03C458 & 0x08), the same pin that gates the I2C read of device 0x60 in FUN_a0126878.
 *   state 0 (and 4..15): when P is high -> state 1, timestamp; if FUN_a00803a4() == 1: (if FUN_a0108e54() == 1:
 *            FUN_a01084a8(FUN_a013cda8(0), 0) and FUN_a0109110(0)), then FUN_a00dac38(1, 1, 1) (forces panel row 1),
 *            FUN_a01023f4(0) and FUN_a0102f6c(); always prints "OLED_FRC_DVDD_ON".
 *   state 1: P low -> state 0; after > 500 ms with R high -> state 2, "OLED_FRC_FRC_READY".
 *   state 2: P low -> state 0; first pass prints "OLED_FRC_Handler %d" (low byte), FUN_a0126704(low byte), sets
 *            0x800, clears 0x400, timestamp; after > 500 ms -> state 3, "OLED_FRC_IIC_READY".
 *   state 3: P low -> state 0; when flag 0x400 is set again -> back to state 2 ("OLED_FRC_FRC_READY").
 * P is the FRC chip's DVDD-on indication and R its ready line. I2C device 0x60 (register 0xB2) is the FRC chip:
 * FUN_a0126704 prints "OLED set/Get Frame rate control" around its accesses, and FUN_a0126878 reads it only while R
 * is high.
 * Callers: FUN_a0085984, FUN_a014512c.
 * Flag 0x400 is set by the helper at 0xA01295D0 (not in Ghidra's function list), called by the mode-change state
 * machine FUN_a008454c right after FUN_a00dac38 has chosen the panel row; the low byte is that row number
 * (0xA802D893), so state 3 -> 2 re-sends the new row to the FRC chip via FUN_a0126704 (register 0xB2).
 * FW.012 kept the row number in bits 8..9 of its state word and sent ((word >> 8) & 3) here.
 * The state word is a bitfield struct: the original reads the row byte as ldub [base+1] and merges
 * "sent = 1; req = 0" into one or/and, which only a struct { state:4, sent:1 (0x800), req:1 (0x400), :2; u8 ch; u16 t }
 * reproduces.
 * BYTE-EXACT at -O3 (register renaming). Required form: a non-volatile state struct; each state has its own
 *   'panel off -> state 0' reset (gcc merges them, a shared goto does not reproduce the layout); the default (idle)
 *   state is written first in the switch. The double lduh at the case-3 test is reorg copying the state=0 target's
 *   load into the delay slot, not a second read in the source.
 */
struct FrcSm { unsigned short state:4; unsigned short sent:1; unsigned short req:1; unsigned short pad:2; unsigned char ch; unsigned short t; };

extern struct FrcSm DAT_a802d892;
extern unsigned char FUN_a0124828(void);
extern unsigned char FUN_a01248c8(void);
extern unsigned char FUN_a0108e54(void);
extern int FUN_a00df170();
extern void FUN_a0126704(unsigned char);
extern unsigned short func_0x4008d588(void);
extern unsigned short func_0x4008d594(unsigned short);
extern unsigned char FUN_a00803a4(void);
extern void FUN_a00dac38(int, int, int);
extern void FUN_a01023f4(int);
extern void FUN_a0102f6c(void);
extern int FUN_a013cda8(int);
extern void FUN_a01084a8(unsigned char, int);
extern void FUN_a0109110(int);
extern char s_001a4e20[], s_001a4e40[], s_001a4e60[], s_001a4e80[];
void FUN_a01295e4(void)
{
    switch (DAT_a802d892.state) {
    default:
        if (FUN_a0124828() != 1) break;
        DAT_a802d892.state = 1; DAT_a802d892.sent = 0; DAT_a802d892.req = 0;
        DAT_a802d892.t = func_0x4008d588();
        if ((unsigned char)FUN_a00803a4() == 1) {
            if ((unsigned char)FUN_a0108e54() == 1) {
                FUN_a01084a8(FUN_a013cda8(0), 0);
                FUN_a0109110(0);
            }
            FUN_a00dac38(1, 1, 1);
            FUN_a01023f4(0);
            FUN_a0102f6c();
        }
        FUN_a00df170(s_001a4e40);
        break;
    case 1:
        if (!FUN_a0124828()) { DAT_a802d892.state = 0; break; }
        if (func_0x4008d594(DAT_a802d892.t) > 500 && (unsigned char)FUN_a01248c8() == 1) {
            DAT_a802d892.state = 2;
            FUN_a00df170(s_001a4e60);
        }
        break;
    case 2:
        if (!FUN_a0124828()) { DAT_a802d892.state = 0; break; }
        if (!(DAT_a802d892.sent == 1 && DAT_a802d892.req == 0)) {
            FUN_a00df170(s_001a4e20, DAT_a802d892.ch);
            FUN_a0126704(DAT_a802d892.ch);
            DAT_a802d892.sent = 1; DAT_a802d892.req = 0;
            DAT_a802d892.t = func_0x4008d588();
        } else if (func_0x4008d594(DAT_a802d892.t) > 500) {
            DAT_a802d892.state = 3;
            FUN_a00df170(s_001a4e80);
        }
        break;
    case 3:
        if (!FUN_a0124828()) { DAT_a802d892.state = 0; break; }
        if (DAT_a802d892.req) {
            DAT_a802d892.state = 2;
            FUN_a00df170(s_001a4e60);
        }
        break;
    }
}
