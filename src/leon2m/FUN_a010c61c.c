/* leon2m FUN_a010c61c @ 0xa010c61c-0xa010d068 (659 words).
 * ch selects a record (ch 1: 0xA802D7C4, ch 2: 0xA802D784, otherwise 0xA802D744); the low byte of sel is stored at
 * its byte +0x27. v = word +0x10 of the register block of entry ch (entry 0 when ch > 2) of the pointer table
 * 0x19AED8. By (unsigned char)sel (jump table), each register write goes to the block of entry ch in both tables
 * 0x19AED8 and 0x19AECC, or to entries 0..2 of the table when ch > 2:
 * 0 clears record words +0x28..+0x34, clears bits 5-6 of v, writes v to block word +0x10 and 0 to +0x30..+0x3c;
 * 1 stores a and b in record words +0x28/+0x2c, sets bit 5 of v, writes v to +0x10, a to +0x30 and b to +0x34;
 * 2 clears +0x28/+0x2c and bit 5, writes v to +0x10 and 0 to +0x30/+0x34;
 * 3 stores a and b in +0x30/+0x34, sets bit 6, writes v to +0x10, a to +0x38 and b to +0x3c;
 * 4 clears +0x30/+0x34 and bit 6, writes v to +0x10 and 0 to +0x38/+0x3c. Other sel values write nothing more.
 * Same form as FUN_a010e0f4. Source form: the per-table write is a macro with the loop counter j declared once at
 * function level (a static helper or a block-local counter gives other registers). No direct callers were found.
 */
struct Rec {
    unsigned char pad[0x27];
    unsigned char sel;
    unsigned int w28, w2c, w30, w34;
};
extern struct Rec DAT_a802d744, DAT_a802d784, DAT_a802d7c4;
extern volatile unsigned int *DAT_0019aed8[], *DAT_0019aecc[];

static struct Rec *rec(unsigned char ch)
{
    struct Rec *p;
    switch (ch) {
    case 1: p = &DAT_a802d7c4; break;
    case 2: p = &DAT_a802d784; break;
    default: p = &DAT_a802d744; break;
    }
    return p;
}

/* Word n of the register block of entry ch in table t, or of entries 0..2 when ch > 2 (uses ch and j of the caller). */
#define PUT(t, n, val) do { if (ch > 2) { for (j = 0; j <= 2; j++) t[j][n] = val; } else t[ch][n] = val; } while (0)

void FUN_a010c61c(unsigned char ch, unsigned int sel, unsigned int a, unsigned int b)
{
    struct Rec *p;
    unsigned int v;
    unsigned char k;
    unsigned int j;

    p = rec(ch);
    p->sel = sel;
    k = ch;
    if (ch > 2)
        k = 0;
    v = DAT_0019aed8[k][4];
    switch ((unsigned char)sel) {
    case 0:
        p->w28 = 0;
        p->w2c = 0;
        p->w30 = 0;
        p->w34 = 0;
        v &= ~0x60;
        PUT(DAT_0019aed8, 4, v);
        PUT(DAT_0019aecc, 4, v);
        PUT(DAT_0019aed8, 12, 0);
        PUT(DAT_0019aecc, 12, 0);
        PUT(DAT_0019aed8, 13, 0);
        PUT(DAT_0019aecc, 13, 0);
        PUT(DAT_0019aed8, 14, 0);
        PUT(DAT_0019aecc, 14, 0);
        PUT(DAT_0019aed8, 15, 0);
        PUT(DAT_0019aecc, 15, 0);
        break;
    case 1:
        p->w28 = a;
        p->w2c = b;
        v |= 0x20;
        PUT(DAT_0019aed8, 4, v);
        PUT(DAT_0019aecc, 4, v);
        PUT(DAT_0019aed8, 12, a);
        PUT(DAT_0019aecc, 12, a);
        PUT(DAT_0019aed8, 13, b);
        PUT(DAT_0019aecc, 13, b);
        break;
    case 2:
        p->w28 = 0;
        p->w2c = 0;
        v &= ~0x20;
        PUT(DAT_0019aed8, 4, v);
        PUT(DAT_0019aecc, 4, v);
        PUT(DAT_0019aed8, 12, 0);
        PUT(DAT_0019aecc, 12, 0);
        PUT(DAT_0019aed8, 13, 0);
        PUT(DAT_0019aecc, 13, 0);
        break;
    case 3:
        p->w30 = a;
        p->w34 = b;
        v |= 0x40;
        PUT(DAT_0019aed8, 4, v);
        PUT(DAT_0019aecc, 4, v);
        PUT(DAT_0019aed8, 14, a);
        PUT(DAT_0019aecc, 14, a);
        PUT(DAT_0019aed8, 15, b);
        PUT(DAT_0019aecc, 15, b);
        break;
    case 4:
        p->w30 = 0;
        p->w34 = 0;
        v &= ~0x40;
        PUT(DAT_0019aed8, 4, v);
        PUT(DAT_0019aecc, 4, v);
        PUT(DAT_0019aed8, 14, 0);
        PUT(DAT_0019aecc, 14, 0);
        PUT(DAT_0019aed8, 15, 0);
        PUT(DAT_0019aecc, 15, 0);
        break;
    }
}
