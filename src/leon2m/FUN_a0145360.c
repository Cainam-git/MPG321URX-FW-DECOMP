/* leon2m FUN_a0145360 @ 0xa0145360-0xa01454c4 (89 words), flags -mcpu=v8 -O3 -g -msoft-float (plain -O3 -g: 81.11,
 * the loop hoists the s_001a6dd8 sethi into %l2; the fw re-materialises it in the bgu delay slot).
 * Code facts: switch on mode (u8): 0 -> tail FUN_a0153994(0xa802e1f0, 0); 1 -> tail FUN_a0153970(0xa802e1a0, 0);
 * 2 -> for ch = 0..3: if FUN_a013ce6c(ch) == 0xc: j = remap(ch) (0..3, else print s_001a6dd8 "SYS remapping
 * channel OOR" and use 0); if byte +9 of port record 0xa802e224[(DAT_a802df30[j].w0 >> 12) & 0xf] (0x2a bytes)
 * != 5: FUN_a01542c4(0xa802df36 + ch * 0x78) and stop; 3 -> nothing; other -> FUN_a0153994(e1f0, 0) then
 * tail FUN_a0153970(e1a0, 0). remap = the static function of src/leon2m/FUN_a0143f0c.c.
 * Required forms: switch (gcc decision tree: 1 first, ble, 2, 3), struct records, -msoft-float.
 * AID: the FUN_a01542c4 argument uses a second extern name DAT_a802df36 for the channel records
 * seen from +6 (same 0x78 stride). The fw builds 0xa802df36 with its own sethi|or and adds i*0x78 (offset first);
 * '&DAT_a802df30[i].h06' lets CSE reuse the hoisted df30 base + 6 (70.79). No volatile, no asm.
 */
struct Chan { unsigned int w0; unsigned short h04, h06; unsigned char rest[0x70]; };
struct Port { unsigned char b[9]; unsigned char b09; unsigned char rest[0x20]; };
extern struct Chan DAT_a802df30[4];
struct Rec36 { unsigned char b[0x78]; };
extern struct Rec36 DAT_a802df36[4];
extern struct Port DAT_a802e224[];
extern unsigned char DAT_a802e1a0[], DAT_a802e1f0[];
extern char s_001a6dd8[];
extern int FUN_a00df170();
extern unsigned char FUN_a013ce6c(int);
extern void FUN_a0153970(void *, unsigned char);
extern void FUN_a0153994(void *, unsigned char);
extern void FUN_a01542c4(void *);

static int remap(int ch)
{
    switch (ch) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

void FUN_a0145360(unsigned char mode)
{
    unsigned char i, j;

    switch (mode) {
    case 0:
        FUN_a0153994(DAT_a802e1f0, 0);
        break;
    case 1:
        FUN_a0153970(DAT_a802e1a0, 0);
        break;
    case 2:
        for (i = 0; i < 4; i++) {
            if (FUN_a013ce6c(i) == 0xc) {
                j = remap(i);
                if (j > 3) {
                    FUN_a00df170(s_001a6dd8);
                    j = 0;
                }
                if (DAT_a802e224[(DAT_a802df30[j].w0 >> 12) & 0xf].b09 != 5) {
                    FUN_a01542c4(&DAT_a802df36[i]);
                    break;
                }
            }
        }
        break;
    case 3:
        break;
    default:
        FUN_a0153994(DAT_a802e1f0, 0);
        FUN_a0153970(DAT_a802e1a0, 0);
        break;
    }
}
