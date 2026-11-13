/* input_init_phy_registers  (FUN_a008ced8)
 *
 * Load the fixed start-up settings of the receiver PHY control block.
 * Name basis: derived - fixed writes to 0xCF0146xx/0xCF0147xx with waits; only caller
 *   input_init_phy_registers_wrapper
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008ced8 @ 0xa008ced8, flags -mcpu=v8 -Os (cflags entry in symbols/leon2s.json: no -g).
 * Source form: the register accesses are volatile macros; the chip revision is read twice (a second call
 * before the final branch), not once.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
#define true 1
#define false 0
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))

#define reg_input_port_control (*(volatile unsigned int *)0xcf012448)
#define _DAT_cf012490 (*(volatile unsigned int *)0xcf012490)
#define _DAT_cf012494 (*(volatile unsigned int *)0xcf012494)
#define _DAT_cf012498 (*(volatile unsigned int *)0xcf012498)
#define _DAT_cf01249c (*(volatile unsigned int *)0xcf01249c)
#define _DAT_cf0146c0 (*(volatile unsigned int *)0xcf0146c0)
#define _DAT_cf0146c4 (*(volatile unsigned int *)0xcf0146c4)
#define _DAT_cf0146fc (*(volatile unsigned int *)0xcf0146fc)
#define _DAT_cf014700 (*(volatile unsigned int *)0xcf014700)
#define _DAT_cf014704 (*(volatile unsigned int *)0xcf014704)
#define _DAT_cf01473c (*(volatile unsigned int *)0xcf01473c)
#define _DAT_cf014754 (*(volatile unsigned int *)0xcf014754)
#define _DAT_cf014760 (*(volatile unsigned int *)0xcf014760)
#define _DAT_cf014774 (*(volatile unsigned int *)0xcf014774)
#define _DAT_cf014788 (*(volatile unsigned int *)0xcf014788)
#define _DAT_cf014790 (*(volatile unsigned int *)0xcf014790)
#define _DAT_cf0147c0 (*(volatile unsigned int *)0xcf0147c0)
#define _DAT_cf0147c4 (*(volatile unsigned int *)0xcf0147c4)
#define _DAT_cf0147c8 (*(volatile unsigned int *)0xcf0147c8)
#define _DAT_cf0147cc (*(volatile unsigned int *)0xcf0147cc)

extern unsigned char sys_get_chip_revision(void);
extern int timer_delay_long_units(int);
extern void hdmi_unit_write_setup(unsigned int, unsigned int, unsigned int);

/*
 * Load the fixed start-up values of the receiver PHY control registers (0xCF0146xx, 0xCF0147xx) and the
 * port control registers (0xCF012448, 0xCF012490..0xCF01249C); called only through
 * input_init_phy_registers_wrapper from input_init_receivers. No parameters, no return value.
 * Two steps depend on the chip revision (above 0x81 or not): the value of 0xCF014760 (0x50, else 3) and the
 * extra set-up of units 4 and 6 with 0xCF014774 = 2 at the end. Order: port control cleared; 0xCF014760;
 * set-up registers of units 0..3, bit 4 of 0xCF014754 and unit 5, bit 5 of 0xCF014754 and unit 7; the block
 * 0xCF0147C0..CC; a pulse on 0xCF014788 and on 0xCF014790; a wait; the two register groups
 * 0xCF0146C0.. and 0xCF014700.. (each: 0x22, 8, then a 0x80 / 0x81 / 0x80 pulse on its last register); a
 * second wait; the second register of each group cleared again; the revision-dependent extra; last the 0xCF01249x registers.
 * The purpose of the individual values is not shown in the firmware.
 */
void input_init_phy_registers(void)
{
    unsigned int chip_revision;
    
    reg_input_port_control = 0;
    chip_revision = sys_get_chip_revision();
    if ((chip_revision & 0xff) > 0x81) {
        _DAT_cf014760 = 0x50;
    } else {
        _DAT_cf014760 = 3;
    }
    
    hdmi_unit_write_setup(0, 0x40, 0x50);
    hdmi_unit_write_setup(1, 0x40, 0x50);
    hdmi_unit_write_setup(2, 0x40, 0x20);
    hdmi_unit_write_setup(3, 0x40, 0x20);
    
    _DAT_cf014754 = _DAT_cf014754 | 0x10;
    hdmi_unit_write_setup(5, 0x40, 0x40);
    _DAT_cf014754 = _DAT_cf014754 | 0x20;
    hdmi_unit_write_setup(7, 0x40, 0x40);
    
    /* Pulse: 0xf1 then 0xf0 on 0xCF014788, 1 then 0 on 0xCF014790. */
    _DAT_cf0147c0 = 0;
    _DAT_cf0147c4 = 0;
    _DAT_cf0147c8 = 0;
    _DAT_cf0147cc = 0xc;
    _DAT_cf014788 = 0xf1;
    _DAT_cf014788 = 0xf0;
    _DAT_cf014790 = 1;
    _DAT_cf014790 = 0;
    
    timer_delay_long_units(1);
    
    _DAT_cf0146c0 = 0x22;
    _DAT_cf0146c4 = 8;
    _DAT_cf0146fc = 0x80;
    _DAT_cf0146fc = 0x81;
    _DAT_cf0146fc = 0x80;
    _DAT_cf014700 = 0x22;
    _DAT_cf014704 = 8;
    _DAT_cf01473c = 0x80;
    _DAT_cf01473c = 0x81;
    _DAT_cf01473c = 0x80;
    
    timer_delay_long_units(1);
    
    /* The value 8 written above to the second register of each group is cleared again. */
    _DAT_cf0146c4 = 0;
    _DAT_cf014704 = 0;
    
    chip_revision = sys_get_chip_revision();
    if ((chip_revision & 0xff) > 0x81) {
        _DAT_cf014774 = 2;
        hdmi_unit_write_setup(4, 0x80, 0x80);
        hdmi_unit_write_setup(6, 0x80, 0x80);
    }
    
    _DAT_cf01249c = 0x20;
    _DAT_cf012498 = 0;
    _DAT_cf012494 = 0;
    _DAT_cf012490 = 0;
}
