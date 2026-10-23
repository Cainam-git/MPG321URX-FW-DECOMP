/* leon2m FUN_a0153b20
 * Writes the records P and S of EEPROM device 0 (layout as in FUN_a0153c74). mode 1: copies the ROM
 * defaults P (0x30 bytes, ROM 0x20140) and S (0x50 bytes, ROM 0x20170) to the stack and writes them to EEPROM 0x440
 * (flag 0) and 0x470 (flag 1) with FUN_a0140e74. Other modes: reads S from EEPROM 0x470 (FUN_a0140360), sets its
 * fields +0x38, +0x1A, +0x3E, +0x40 from the ROM record and +0x3C = FUN_a012ce18(), and writes it back to 0x470
 * (flag 1). Called by FUN_a0145508.
 * Source form: the record types and the ROM block at 0x20000 as in FUN_a0153c74 (8-byte aligned structures, copied
 * inline with ldd/std); the field stores in the order h38, b1a, h3e, h40, chk as there.
 */
struct Rec { unsigned char a[0x1a]; unsigned char b1a; unsigned char c[0x1d];
             unsigned short h38, ver, chk, h3e, h40, magic2; unsigned char d[0xc]; } __attribute__((aligned(8)));
struct Part { unsigned char a[0x28]; unsigned short magic1; unsigned char c[6]; } __attribute__((aligned(8)));
struct NV { struct Part p; struct Rec r; };
struct Defaults { unsigned char other[0x140]; struct NV nv; };   /* 0x000..0x13F: not read here */
extern const struct Defaults DAT_00020000;
extern void FUN_a0140360(unsigned char, unsigned short, unsigned short, void *);
extern void FUN_a0140e74(unsigned char, unsigned short, unsigned short, void *, unsigned char);
extern unsigned short FUN_a012ce18(void);

void FUN_a0153b20(unsigned char mode)
{
    struct Rec r;
    struct Part p;

    if (mode == 1) {
        p = DAT_00020000.nv.p;
        r = DAT_00020000.nv.r;
        FUN_a0140e74(0, 0x440, 0x30, &p, 0);
        FUN_a0140e74(0, 0x470, 0x50, &r, 1);
    } else {
        FUN_a0140360(0, 0x470, 0x50, &r);
        r.h38 = DAT_00020000.nv.r.h38;
        r.b1a = DAT_00020000.nv.r.b1a;
        r.h3e = DAT_00020000.nv.r.h3e;
        r.h40 = DAT_00020000.nv.r.h40;
        r.chk = FUN_a012ce18();
        FUN_a0140e74(0, 0x470, 0x50, &r, 1);
    }
}
