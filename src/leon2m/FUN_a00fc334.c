/* FUN_a00fc334 (leon2m 0xa00fc334-0xa00fca34, 448 words), flags -mcpu=v8 -O3 -g.
 * Receive step of the controller at 0xcf012000 (status word 0xcf012034). Status bits 0x38: writes 0x38 back,
 * result 5; bit 1 clear: result 6; word 0xcf01203c == 0: writes 1 to the status word, result 6. Otherwise reads the
 * header word 0xcf0120c4 and the 16 data words 0xcf0120c8.. into a byte buffer, stores header >> 4 in DAT_a802c97d
 * and dispatches on buffer byte 0, one switch for header & 0xf == 0xf and one for the other values. The arms set
 * bits of DAT_a802c97c, copy buffer bytes to DAT_a802c97e/f, DAT_a802c978[4] and DAT_a802c968[5], or write reply
 * words to 0xcf012084.. and send them with the body of FUN_a00fca4c (hook word 0xa802c970, destination, length).
 * Then 1 is written to the status word, result 1. When the result is 1 the function returns 1..7 for the lowest
 * set bit 0x01..0x40 of DAT_a802c97c (0 when none) and clears DAT_a802c97c; otherwise it returns 0.
 * Source form: receive() and send() are static helpers, inlined (send() four times, the fw shares one copy of the
 * wait-loop tail at 0xa00fc4d8); receive() returns unsigned char (the fw keeps 'mov 5' and 'cmp 1' at 0xa00fc358).
 * In every arm the data bytes are stored first, in index order, and the DAT_a802c97c bit is set last (fw store
 * order at 0xa00fc6d8..0xa00fc700 and 0xa00fc7dc..0xa00fc80c). Case order: 0x36, 0x82/0x84, 0x87 in the first
 * switch; 0x9d, 0x83, 0x36, 0x91, 0x8f, 0x0f, 0x93/0xff, 0x44, 0x47 in the second (other case orders give
 * other registers inside the arms).
 * Compiler aids: none.
 */
#define REG(a) (*(volatile unsigned int *)(a))
extern void (*_DAT_a802c970)(int, int);
extern unsigned short func_0x4008d588(void);
extern void func_0x4008ced8(void);
extern unsigned short func_0x4008d594(unsigned short);
extern unsigned char DAT_a802c97c, DAT_a802c97d, DAT_a802c97e, DAT_a802c97f;
extern unsigned char DAT_a802c968[5], DAT_a802c978[4];

static void send(unsigned char dest, unsigned char len)
{
    unsigned short t;

    REG(0xcf012034) = 0x2e;
    if (_DAT_a802c970 != 0)
        _DAT_a802c970(dest, len);
    else {
        REG(0xcf012080) = dest;
        REG(0xcf012040) = len;
    }
    t = func_0x4008d588();
    while (!(REG(0xcf012034) & 0x2e)) {
        func_0x4008ced8();
        if (func_0x4008d594(t) > 1000)
            break;
    }
    REG(0xcf012034);
    REG(0xcf012034) = 0x2e;
}

static unsigned char receive(void)
{
    unsigned char buf[16];
    unsigned char hdr, i;

    if (REG(0xcf012034) & 0x38) {
        REG(0xcf012034) = 0x38;
        return 5;
    }
    if (!(REG(0xcf012034) & 1))
        return 6;
    if (REG(0xcf01203c) == 0) {
        REG(0xcf012034) = 1;
        return 6;
    }
    hdr = REG(0xcf0120c4);
    for (i = 0; i < 16; i++)
        buf[i] = REG(0xcf000000 | ((0x4832 + i) << 2));
    DAT_a802c97d = hdr >> 4;
    if ((hdr & 0xf) == 0xf) {
        switch (buf[0]) {
        case 0x36:
            DAT_a802c97c |= 2;
            break;
        case 0x82:
        case 0x84:
            DAT_a802c97e = buf[1];
            if (buf[1] != 0)
                DAT_a802c97c |= 4;
            break;
        case 0x87:
            DAT_a802c978[0] = buf[0];
            DAT_a802c978[1] = buf[1];
            DAT_a802c978[2] = buf[2];
            DAT_a802c978[3] = buf[3];
            DAT_a802c97c |= 0x20;
            break;
        }
    } else {
        switch (buf[0]) {
        case 0x9d:
            DAT_a802c97e = buf[1];
            DAT_a802c97c |= 8;
            break;
        case 0x83:
            REG(0xcf012084) = 0x84;
            REG(0xcf012088) = 0;
            REG(0xcf01208c) = 0;
            REG(0xcf012090) = 0;
            send(0xf, 4);
            break;
        case 0x36:
            DAT_a802c97c |= 2;
            break;
        case 0x91:
            REG(0xcf012084) = 0x32;
            REG(0xcf012088) = 0x65;
            REG(0xcf01208c) = 0x6e;
            REG(0xcf012090) = 0x67;
            send(DAT_a802c97d, 4);
            break;
        case 0x8f:
            REG(0xcf012084) = 0x90;
            REG(0xcf012088) = 0;
            send(DAT_a802c97d, 2);
            break;
        case 0x0f:
            REG(0xcf012084) = 0;
            REG(0xcf012088) = 2;
            send(DAT_a802c97d, 2);
            break;
        case 0x93:
        case 0xff:
            REG(0xcf012084) = 0;
            REG(0xcf012088) = 0;
            REG(0xcf01208c) = 0;
            send(DAT_a802c97d, 3);
            break;
        case 0x44:
            DAT_a802c97f = buf[1];
            DAT_a802c97c |= 0x10;
            break;
        case 0x47:
            DAT_a802c968[0] = buf[0];
            DAT_a802c968[1] = buf[1];
            DAT_a802c968[2] = buf[2];
            DAT_a802c968[3] = buf[3];
            DAT_a802c968[4] = buf[4];
            DAT_a802c97c |= 0x40;
            break;
        }
    }
    REG(0xcf012034) = 1;
    return 1;
}

int FUN_a00fc334(void)
{
    int r = 0;
    unsigned char f;

    if (receive() == 1) {
        f = DAT_a802c97c;
        if (f & 1)
            r = 1;
        else if (f & 2)
            r = 2;
        else if (f & 4)
            r = 3;
        else if (f & 8)
            r = 4;
        else if (f & 0x10)
            r = 5;
        else if (f & 0x20)
            r = 6;
        else if (f & 0x40)
            r = 7;
        DAT_a802c97c = 0;
    }
    return r;
}
