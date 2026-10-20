/* leon2m FUN_a0142910 @ 0xa0142910  per-port sync state machine; copies the port-entry flags (incl. the line-rate switch)
 * into the port status words (hand; -mcpu=v8 -O3 -g -msoft-float).
 *
 * For each port i = 0..3, p = 0xA802E224 + 42*i (h0 = halfword +0, state +2, type +3):
 *   state 1: p+9 = 1, FUN_a0121cf4(i), next port.
 *   k = FUN_a0142168(p+0xa); k == 0xFF: state = 1, next port.
 *   k == 6: type = 5, +0x1a/+0x1c/+0x16/+0x18 = FUN_a00f92f4/9314/9334/9354(p+0xb), h0 bits 0x8000/0x4000 cleared.
 *   else (E = 18-byte entry 0xA802E116 + 18*k): type = E type nibble; ONLY if it is 5: +0x1a/+0x1c/+0x16/+0x18 = E+6/+8/+0xa/
 *     +0xc, +0x28 = E+4, and h0 bits: 0x8000/0x4000/0x2000 = E bits 10/9/8, 0x800 = E bit 5, 0x400 = E bit 4 (THE LINE-RATE
 *     SWITCH), 0x200 = E bit 3, 0x100 = E bit 2, 0x40 = E bit 1, 0x80 = E bit 0, 0x20 = E+2 bit 15.
 *     A type != 5 leaves h0 untouched (bit 0x400 keeps its old value).
 *   p+9 = FUN_a01213a4(i, (u8)p+0x1e, p+9) (the 'i == 6 || i == 7' arm is dead for i = 0..3).
 *   switch (state): 2: FUN_a00f8f58(i, 0); FUN_a012082c(i, E+2 bit 5 ? 0xB0 : 4); if p+9 != 1 and type 5: start ticks
 *     (+6, +0x12), state 3, 'Go To SYNC_WAIT_STABLE(%d, %d)'. 3: type 5 and stable > 100 ticks -> FUN_a014285c(p, i),
 *     state 4 'Go To SYNC_IS_STABLE2'; changes / loss -> state 2. 4: loss -> state 2 (+0x1000 'Exit SYNC_IS_STABLE').
 *     Non-type-5 ports in states 3/4 are cleared (+4, +0x16..+0x20, +0x22..+0x24, +0x26) and put back to state 2.
 * Line-rate switch chain, CONFIRMED byte-exact: port h0 bit 0x400 = entry h0 bit 4 = template +0xc bit 2, copied only
 *   when the entry type is 5 (and k != 6, 0xFF).
 * Callers: FUN_a0153018 (call at 0xA0153024, right after FUN_a002f550).
 * keys: -msoft-float; every port field through the pointer p (also the bitfields); the 'last statement of a
 *   block is scheduled first' rule of gcc 3.4 sched1 -> write CLEAR before 'state = 2' / before 'p12 = 1' (the original
 *   order then comes out); case 4 written 'if (type != 5) {reset} else {...}' (only changes the pre-layout block order,
 *   which drives -frename-registers' register choice); b9 select and FUN_a012082c as if/else (not ?:).
 */
struct Ent {
    unsigned short type:4;     /* bits 15..12 */
    unsigned short e11:1, e10:1, e9:1, e8:1, e7:1, e6:1, e5:1, e4:1, e3:1, e2:1, e1:1, e0:1;
    unsigned short h15:1, h14_6:9, h5:1, h4_0:5;   /* +2 */
    unsigned char b4, b5;
    unsigned short w6, w8, wa, wc, we, w10;
};
struct Port {
    unsigned short p15:1, p14:1, p13:1, p12:1, p11:1, p10:1, p9:1, p8:1, p7:1, p6:1, p5:1, plo:5;  /* +0 */
    unsigned char state;   /* +2 */
    unsigned char type;    /* +3 */
    unsigned short w4;     /* +4 */
    unsigned short w6;     /* +6 */
    unsigned char b8, b9;  /* +8, +9 */
    unsigned char id;      /* +0xa */
    unsigned char b0b;     /* +0xb */
    unsigned char pad0c[6];
    unsigned short w12, w14, w16, w18, w1a, w1c, w1e, w20;   /* +0x12..+0x21 */
    unsigned char b22, b23, b24, pad25;
    unsigned short w26;
    unsigned char b28, pad29;
};
extern struct Ent DAT_a802e116[];
extern struct Port DAT_a802e224[];
extern char s_001a6d40[], s_001a6d60[], s_001a6d88[];  /* "Go To SYNC_IS_STABLE2 (%d)\r\n", "Go To SYNC_WAIT_STABLE(%d, %d)\r\n", "Exit SYNC_IS_STABLE (%d)\r\n" */
extern unsigned char FUN_a0142168(unsigned char);
extern void FUN_a0121cf4(unsigned char);
extern unsigned char FUN_a01213a4(unsigned char, unsigned char, unsigned char);
extern unsigned short FUN_a00f92f4(unsigned char), FUN_a00f9314(unsigned char), FUN_a00f9334(unsigned char);
extern short FUN_a00f9354(unsigned char);
extern unsigned char FUN_a00fd820(unsigned char);
extern void FUN_a014285c(struct Port *, unsigned char);
extern void FUN_a00f8f58(unsigned char, unsigned char);
extern void FUN_a012082c(unsigned char, unsigned char);
extern unsigned short func_0x4008d588(void);
extern unsigned short func_0x4008d594(unsigned short);
extern unsigned char FUN_a00dd614(unsigned int);
extern int FUN_a00df170();

/* field reset used 5 times */
#define CLEAR(p) do { (p)->w4 = 0; (p)->w16 = 0; (p)->w18 = 0; (p)->w1a = 0; (p)->w1c = 0; (p)->w1e = 0; \
    (p)->w20 = 0; (p)->b22 = 0; (p)->b23 = 0; (p)->b24 = 0; (p)->w26 = 0; } while (0)

void FUN_a0142910(void)
{
    unsigned char i, k;
    struct Port *p;
    struct Ent *e;

    for (i = 0; i < 4; i++) {
        p = &DAT_a802e224[i];
        if (p->state == 1) {
            p->b9 = 1;
            FUN_a0121cf4(i);
            continue;
        }
        k = FUN_a0142168(p->id);
        if (k == 0xff) {
            p->state = 1;
            continue;
        }
        if (k == 6) {
            p->type = 5;
            p->w1a = FUN_a00f92f4(p->b0b);
            p->w1c = FUN_a00f9314(p->b0b);
            p->w16 = FUN_a00f9334(p->b0b);
            p->w18 = FUN_a00f9354(p->b0b);
            p->p15 = 0;
            p->p14 = 0;
        } else {
            p->type = DAT_a802e116[k].type;
            if (DAT_a802e116[k].type == 5) {
                e = &DAT_a802e116[k];
                p->w1a = e->w6;
                p->w1c = e->w8;
                p->w16 = e->wa;
                p->w18 = e->wc;
                p->p15 = e->e10;
                p->p14 = e->e9;
                p->p13 = e->e8;
                p->type = e->type;
                p->b28 = e->b4;
                p->p11 = e->e5;
                p->p10 = e->e4;
                p->p9 = e->e3;
                p->p8 = e->e2;
                p->p6 = e->e1;
                p->p7 = e->e0;
                p->p5 = e->h15;
            }
        }
        if ((i == 6 || i == 7) && p->p11)
            if (p->type == 5) p->b9 = 5; else p->b9 = 1;
        else
            p->b9 = FUN_a01213a4(i, p->w1e, p->b9);
        switch (p->state) {
        case 2:
            FUN_a00f8f58(i, 0);
            if (DAT_a802e116[k].h5)
                FUN_a012082c(i, 0xb0);
            else
                FUN_a012082c(i, 4);
            if (p->b9 != 1 && p->type == 5) {
                p->w6 = func_0x4008d588();
                p->w12 = func_0x4008d588();
                p->state = 3;
                p->b8 = p->b9;
                if (FUN_a00dd614(2))
                    FUN_a00df170(s_001a6d60, i, p->w6);
            }
            break;
        case 3:
            if (p->type == 5) {
                if (p->p11 && FUN_a00fd820(i) != 0xb1 && i <= 3) {
                    CLEAR(p);
                    p->state = 2;
                } else if (p->b8 != p->b9) {
                    p->b8 = p->b9;
                    p->state = 2;
                } else {
                    switch (p->b8) {
                    case 1:
                        p->b8 = p->b9;
                        p->state = 2;
                        break;
                    case 2: case 3: case 4: case 5:
                        if (func_0x4008d594(p->w6) > 100) {
                            FUN_a014285c(p, i);
                            p->state = 4;
                            if (FUN_a00dd614(2))
                                FUN_a00df170(s_001a6d40, i);
                        }
                        break;
                    }
                }
            } else {
                CLEAR(p);
                p->state = 2;
            }
            break;
        case 4:
            if (p->type != 5) {
                CLEAR(p);
                p->state = 2;
                p->p12 = 1;
            } else {
                if (p->p11 && FUN_a00fd820(i) != 0xb1 && i <= 3) {
                    CLEAR(p);
                    p->state = 2;
                } else if (p->b9 == 1) {
                    p->b8 = p->b9;
                    p->state = 2;
                    p->w6 = func_0x4008d588();
                    CLEAR(p);
                    p->p12 = 1;
                    if (FUN_a00dd614(2))
                        FUN_a00df170(s_001a6d88, i);
                } else {
                    FUN_a014285c(p, i);
                }
            }
            break;
        }
    }
}
