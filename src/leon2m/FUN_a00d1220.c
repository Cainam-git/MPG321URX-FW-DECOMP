/* leon2m FUN_a00d1220 @ 0xa00d1220 (-mcpu=v8 -O3 -g). Called by FUN_a00d2a98 and FUN_a00d3650.
 * Fills the reply record p for command byte cmd (req = the request record) and stores the FUN_a00d0f68 checksum
 * (0x50 XORed with the (p[1] & 0x7f) + 2 bytes from p[0]) behind the filled bytes. An if/else chain on cmd:
 * 0x99 checksum to p[0x47] (req[6] == 0x40) or p[0x17]; 0x98 nothing; 0x97, 0x92, 0x69, 0x6b and 0xaa are the
 * bodies of FUN_a00d0fa0, FUN_a00d0fe8, FUN_a00d10b4, FUN_a00d1110 and FUN_a00d1184; 0x96 checksum to p[8];
 * 0x93 p[1] = 0x8c, p[7] = 0xe0, p[8..13] = 0, checksum to p[14]; 0x6e / 0x6f p[7] = 0xe0 when FUN_a013851c(1 / 2)
 * returns 1, else 0xe1 (no checksum); 0x6a p[8] = 0xe0, p[7] from the byte 0xa802d298 (0..28, jump table at
 * 0x6ec3c; larger values set p[8] = 0xe4 instead), p[1] = 0x87, checksum to p[9]; 0x1f p[1] = 0x89, checksum to
 * p[11]; 2 p[7] = bit 14 of word 0xa802d290; 8 p[7] = byte 0xa802d465; 0xc2 p[6], p[7] = high and low byte of
 * halfword 0xa802d28a; 0xd0 t = bits 8..23 of word 0xa802e1a8 * 60 + its top byte, p[6] = t >> 8, p[7] = t;
 * 0x0a p[7] = 8, 9, 0xd, 0xf or 0xe1 for FUN_a01445fc(byte 0xa802d2ae) = 0, 1, 2, 3 or other (one call per
 * test); otherwise a switch: p[7] = cmd for 0..2, 2 for 0x88, cmd for 0xe0, 0xe1, 0xe3, 0xe4, 0xe2 for any other
 * value; these last six cases end with the checksum to p[8].
 * Source form: the bodies of the five neighbouring functions are static helpers (inlined); the top byte of the
 * 0xa802e1a8 word is read through a byte member of a union with the word (a byte load, not a second extraction
 * from the same word load); the 0x6a cases are listed from 28 down to 0; case 0xe2 is listed explicitly;
 * the 0x6e / 0x6f stores are if/else, not ?:; p[6] is assigned before p[7] in the 0xd0 and 0xc2 cases.
 */
struct D290 {
    unsigned int w0;
    unsigned char pad[0x1a];
    unsigned char b1e;
};
struct D274 {
    unsigned char b[0x16];
    unsigned short h16;
};
struct D1a0 {
    unsigned int w0, w4;
    union {
        unsigned int w;
        unsigned char b[4];
    } u8;
};
extern struct D290 DAT_a802d290;
extern struct D274 DAT_a802d274;
extern struct D1a0 DAT_a802e1a0;
extern unsigned char DAT_a802d2a1;
extern unsigned char DAT_a802e1f0[];
extern unsigned char DAT_a802d298;
extern unsigned char DAT_a802d465, DAT_a802d466;
extern unsigned char FUN_a013851c(unsigned char);
extern unsigned char FUN_a01445fc(unsigned char);

static unsigned char csum(const unsigned char *p, unsigned char x)
{
    unsigned int n = (p[1] & 0x7f) + 2;
    unsigned char i;

    for (i = 0; i < n; i++)
        x ^= p[i];
    return x;
}

static void fill_97(unsigned char *p)
{
    p[1] = 0x88;
    p[8] = 2;
    p[9] = 1;
    p[7] = 0;
    p[10] = csum(p, 0x50);
}

static void fill_92(unsigned char *p)
{
    p[1] = 0x89;
    p[7] = 0xe0;
    if (DAT_a802d2a1 == 2) {
        p[8] = DAT_a802e1f0[6];
        p[9] = DAT_a802e1f0[7];
        p[10] = DAT_a802e1f0[8];
    }
    else if (DAT_a802d2a1 == 1) {
        p[8] = DAT_a802e1f0[9];
        p[9] = DAT_a802e1f0[10];
        p[10] = DAT_a802e1f0[11];
    }
    else if (DAT_a802d2a1 == 0) {
        p[8] = DAT_a802e1f0[18];
        p[9] = DAT_a802e1f0[19];
        p[10] = DAT_a802e1f0[20];
    }
    p[11] = csum(p, 0x50);
}

static void fill_69(unsigned char *p)
{
    p[6] = DAT_a802d274.b[0x10] & 1;
    p[7] = DAT_a802d274.b[0x10] & 0x3e;
    p[8] = csum(p, 0x50);
}

static void fill_6b(unsigned char *p)
{
    int i;

    p[1] = 0x93;
    p[7] = 0xe0;
    for (i = 0; i < 13; i++)
        p[8 + i] = DAT_a802d274.b[3 + i];
    p[0x15] = csum(p, 0x50);
}

static void fill_aa(const unsigned char *req, unsigned char *p)
{
    if (req[7] == 0)
        p[7] = (DAT_a802d290.w0 >> 14) & 1;
    else if (req[7] == 1)
        p[7] = DAT_a802d465;
    else if (req[7] == 2)
        p[7] = DAT_a802d466;
    else
        p[7] = 0xe4;
    p[8] = csum(p, 0x50);
}

void FUN_a00d1220(const unsigned char *req, unsigned char *p, unsigned char cmd)
{
    unsigned int t;

    if (cmd == 0x99) {
        if (req[6] == 0x40)
            p[0x47] = csum(p, 0x50);
        else
            p[0x17] = csum(p, 0x50);
    }
    else if (cmd == 0x98) {
    }
    else if (cmd == 0x97) {
        fill_97(p);
    }
    else if (cmd == 0x96) {
        p[8] = csum(p, 0x50);
    }
    else if (cmd == 0x93) {
        p[1] = 0x8c;
        p[7] = 0xe0;
        p[8] = 0;
        p[9] = 0;
        p[10] = 0;
        p[11] = 0;
        p[12] = 0;
        p[13] = 0;
        p[14] = csum(p, 0x50);
    }
    else if (cmd == 0x92) {
        fill_92(p);
    }
    else if (cmd == 0x69) {
        fill_69(p);
    }
    else if (cmd == 0x6e) {
        if (FUN_a013851c(1) == 1)
            p[7] = 0xe0;
        else
            p[7] = 0xe1;
    }
    else if (cmd == 0x6f) {
        if (FUN_a013851c(2) == 1)
            p[7] = 0xe0;
        else
            p[7] = 0xe1;
    }
    else if (cmd == 0x6a) {
        p[8] = 0xe0;
        switch (DAT_a802d298) {
        case 28: p[7] = 0x1f; break;
        case 27: p[7] = 0x1e; break;
        case 26: p[7] = 0x1d; break;
        case 25: p[7] = 5; break;
        case 24: p[7] = 8; break;
        case 23: p[7] = 0x1c; break;
        case 22: p[7] = 6; break;
        case 21: p[7] = 0x1b; break;
        case 20: p[7] = 0x1a; break;
        case 19: p[7] = 0x19; break;
        case 18: p[7] = 0x18; break;
        case 17: p[7] = 0x17; break;
        case 16: p[7] = 0x16; break;
        case 15: p[7] = 0x15; break;
        case 14: p[7] = 0x14; break;
        case 13: p[7] = 0x10; break;
        case 12: p[7] = 0x13; break;
        case 11: p[7] = 0x12; break;
        case 10: p[7] = 0x11; break;
        case 9: p[7] = 7; break;
        case 8: p[7] = 9; break;
        case 7: p[7] = 0xd; break;
        case 6: p[7] = 0xe; break;
        case 5: p[7] = 3; break;
        case 4: p[7] = 4; break;
        case 3: p[7] = 1; break;
        case 2: p[7] = 2; break;
        case 1: p[7] = 0; break;
        case 0: p[7] = 0xc; break;
        default: p[8] = 0xe4; break;
        }
        p[1] = 0x87;
        p[9] = csum(p, 0x50);
    }
    else if (cmd == 0x6b) {
        fill_6b(p);
    }
    else if (cmd == 0x1f) {
        p[1] = 0x89;
        p[11] = csum(p, 0x50);
    }
    else if (cmd == 2) {
        p[7] = (DAT_a802d290.w0 >> 14) & 1;
        p[8] = csum(p, 0x50);
    }
    else if (cmd == 8) {
        p[7] = DAT_a802d465;
        p[8] = csum(p, 0x50);
    }
    else if (cmd == 0xaa) {
        fill_aa(req, p);
    }
    else if (cmd == 0xc2) {
        p[6] = DAT_a802d274.h16 >> 8;
        p[7] = DAT_a802d274.h16;
    }
    else if (cmd == 0xd0) {
        t = (unsigned short)(DAT_a802e1a0.u8.w >> 8) * 60 + DAT_a802e1a0.u8.b[0];
        p[6] = t >> 8;
        p[7] = t;
    }
    else if (cmd == 0x0a) {
        if (FUN_a01445fc(DAT_a802d290.b1e) == 0)
            p[7] = 8;
        else if (FUN_a01445fc(DAT_a802d290.b1e) == 1)
            p[7] = 9;
        else if (FUN_a01445fc(DAT_a802d290.b1e) == 2)
            p[7] = 0xd;
        else if (FUN_a01445fc(DAT_a802d290.b1e) == 3)
            p[7] = 0xf;
        else
            p[7] = 0xe1;
        p[8] = csum(p, 0x50);
    }
    else {
        switch (cmd) {
        case 0:
        case 1:
        case 2:
            p[7] = cmd;
            break;
        case 0x88:
            p[7] = 2;
            break;
        case 0xe0:
            p[7] = 0xe0;
            break;
        case 0xe1:
            p[7] = 0xe1;
            break;
        case 0xe2:
            p[7] = 0xe2;
            break;
        case 0xe3:
            p[7] = 0xe3;
            break;
        case 0xe4:
            p[7] = 0xe4;
            break;
        default:
            p[7] = 0xe2;
            break;
        }
        p[8] = csum(p, 0x50);
    }
}
