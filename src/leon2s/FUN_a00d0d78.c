/* leon2s FUN_a00d0d78 @ 0xa00d0d78-0xa00d12e4 (-mcpu=v8 -Os -g)
 * Link state machine of port p on its 24-byte record DAT_a8078bb0[p] (word 0 bit-fields: b30, b28 bit 28,
 * f24 bits 24-27, b23, b19, mode bits 16-17; byte +2 state; halfword +0x16 timeout). Returns at once when mode is
 * 3. Otherwise sets the timeout to 100, steps the state by mode (1 = advance, 2 = alternative path, 0/3 = back to
 * state 0, 1 or 0x40 depending on the branch; states 0x00-0x18 and 0x40-0x4f, state 0x13 tests b28 and 0x42/0x45
 * test bit 29), sets b23, b19 and the f24 counter in some steps, then sets b30, the timeout (100 to 5000) and f24
 * for the new state, and calls FUN_a00d0530(p + 0xb, timeout).
 * Source form: void function of an unsigned char port (as its caller FUN_a00d12e4 declares it); FUN_a00d0530
 * returns int and its result is tested with 'if (...) return;' after the last call, a no-code aid that keeps
 * the call a normal call instead of a sibling call (the test compiles to nothing).
 * The switch jump table holds addresses of the link 0xF10000 above the load address; tools/exact.py checks it
 * entry by entry at that shift.
 */
struct Rec24 {
    union {
        unsigned int w;
        struct {
            unsigned int b31 : 1, b30 : 1, b29 : 1, b28 : 1, f24 : 4, b23 : 1, : 3, b19 : 1, : 1, mode : 2, : 16;
        } f;
        struct {
            unsigned char b0, b1, state, b3;
        } b;
    } u;
    unsigned char pad[0x12];
    unsigned short timeout;
};
extern struct Rec24 DAT_a8078bb0[];
extern int FUN_a00d0530(unsigned int, unsigned int);

void FUN_a00d0d78(unsigned char port)
{
    struct Rec24 *r = &DAT_a8078bb0[port];
    unsigned char st = r->u.b.state;
    unsigned char mode = r->u.f.mode;

    if (mode == 3)
        return;
    r->timeout = 100;
    switch (st) {
    case 0x00:
        if (mode == 1)
            r->u.b.state = 1;
        else
            r->u.b.state = 0;
        break;
    case 0x01:
        if (mode == 1)
            r->u.b.state = 0x10;
        else if (mode == 2)
            r->u.b.state = 0x40;
        else
            r->u.b.state = 0;
        break;
    case 0x10:
        if (mode == 1)
            r->u.b.state = 0x11;
        else
            r->u.b.state = 1;
        break;
    case 0x11:
        if (mode == 1)
            r->u.b.state = 0x12;
        else
            r->u.b.state = 1;
        break;
    case 0x12:
        if (mode == 0)
            r->u.b.state = 0x13;
        break;
    case 0x13:
        if (mode == 1 || mode == 2) {
            if (DAT_a8078bb0[port].u.f.b28)
                r->u.b.state = 0x14;
            else
                r->u.b.state = 0x16;
        } else
            r->u.b.state = 1;
        break;
    case 0x14:
        if (mode == 1)
            r->u.b.state = 0x15;
        else if (mode == 2) {
            r->u.b.state = 1;
            r->u.f.b23 = 1;
        } else
            r->u.b.state = 1;
        break;
    case 0x15:
        if (mode == 1)
            r->u.b.state = 0x16;
        else
            r->u.b.state = 1;
        break;
    case 0x16:
        if (mode == 1) {
            r->u.b.state = 0x17;
            r->u.f.b23 = 1;
        } else
            r->u.b.state = 1;
        break;
    case 0x17:
        if (mode == 1) {
            r->u.b.state = 0x18;
            r->u.f.f24 = 3;
        } else
            r->u.b.state = 1;
        break;
    case 0x18:
        if (mode != 1)
            r->u.b.state = 1;
        break;
    case 0x40:
        if (mode == 1) {
            r->u.b.state = 0x41;
            r->u.f.f24 = 10;
        } else if (mode == 3)
            return;
        else
            r->u.b.state = 0;
        break;
    case 0x41:
        if (mode == 1)
            r->u.b.state = 0x42;
        else
            r->u.b.state = 0;
        break;
    case 0x42:
        if (mode == 1) {
            r->u.f.b19 = 1;
            if (r->u.w & 0x20000000)
                r->u.b.state = 0x44;
            else
                r->u.b.state = 0x43;
        } else
            r->u.b.state = 0;
        break;
    case 0x43:
    case 0x44:
        if (mode == 1)
            r->u.b.state = 0x45;
        else
            r->u.b.state = 0x40;
        break;
    case 0x45:
        if (mode == 1) {
            r->u.f.f24 = 5;
            if (r->u.w & 0x20000000)
                r->u.b.state = 0x47;
            else
                r->u.b.state = 0x46;
        } else
            r->u.b.state = 0x40;
        break;
    case 0x46:
        if (mode == 1)
            r->u.b.state = 0x47;
        else
            r->u.b.state = 0x40;
        break;
    case 0x47:
        if (mode == 1)
            r->u.b.state = 0x48;
        else
            r->u.b.state = 0x40;
        break;
    case 0x48:
        if (mode == 1)
            r->u.b.state = 0x49;
        else if (mode == 2) {
            r->u.b.state = 0x47;
            r->u.f.f24--;
        } else
            r->u.b.state = 0x40;
        break;
    case 0x49:
        if (mode == 1) {
            r->u.b.state = 0x4e;
            r->u.f.b23 = 1;
        } else if (mode == 2)
            r->u.b.state = 0x4a;
        else
            r->u.b.state = 0x40;
        break;
    case 0x4a:
        if (mode == 1)
            r->u.b.state = 0x4b;
        else if (mode == 2) {
            r->u.b.state = 0;
            r->u.f.b23 = 1;
        } else
            r->u.b.state = 0x40;
        break;
    case 0x4b:
        if (mode == 1) {
            r->u.b.state = 0x4c;
            r->u.f.b23 = 1;
        } else if (mode == 2) {
            r->u.b.state = 0x4e;
            r->u.f.b23 = 1;
        } else
            r->u.b.state = 0x40;
        break;
    case 0x4c:
        if (mode == 1)
            r->u.b.state = 0x4d;
        else
            r->u.b.state = 0x40;
        break;
    case 0x4d:
        if (mode == 1)
            r->u.b.state = 0x4e;
        else if (mode == 2)
            r->u.b.state = 0x4c;
        else
            r->u.b.state = 0x40;
        break;
    case 0x4e:
        if (mode == 0)
            r->u.b.state = 0x4f;
        break;
    case 0x4f:
        if (mode == 2)
            r->u.b.state = 0x4a;
        else if (mode == 0)
            r->u.b.state = 1;
        break;
    }
    switch (r->u.b.state) {
    case 0x00:
        r->u.f.b30 = 0;
        r->timeout = 500;
        break;
    case 0x01:
        r->u.f.b30 = 0;
        break;
    case 0x10:
        r->u.f.b30 = 0;
        break;
    case 0x11:
        r->u.f.b30 = 0;
        r->u.f.f24 = 10;
        break;
    case 0x12:
        r->u.f.b30 = 1;
        r->timeout = 100;
        break;
    case 0x13:
        r->u.f.b30 = 1;
        r->timeout = 5000;
        r->u.f.f24 = 10;
        break;
    case 0x14:
        r->u.f.b30 = 1;
        r->timeout = 5000;
        break;
    case 0x15:
        r->u.f.b30 = 0;
        r->u.f.f24 = 3;
        break;
    case 0x16:
        r->u.f.b30 = 0;
        break;
    case 0x17:
        r->u.f.b30 = 0;
        break;
    case 0x18:
        r->u.f.b30 = 0;
        break;
    case 0x40:
        r->u.f.b30 = 0;
        r->u.f.f24 = 5;
        break;
    case 0x41:
        r->u.f.b30 = 1;
        r->timeout = 100;
        break;
    case 0x42:
        r->u.f.b30 = 0;
        r->u.f.f24 = 4;
        break;
    case 0x43:
        r->u.f.b30 = 0;
        break;
    case 0x44:
        r->u.f.b30 = 0;
        break;
    case 0x45:
        r->u.f.b30 = 1;
        r->timeout = 1000;
        break;
    case 0x46:
        r->u.f.b30 = 1;
        r->timeout = 300;
        break;
    case 0x47:
        r->u.f.b30 = 0;
        break;
    case 0x48:
        r->u.f.b30 = 1;
        r->timeout = 1000;
        break;
    case 0x49:
        r->u.f.b30 = 0;
        break;
    case 0x4a:
        r->u.f.b30 = 1;
        r->timeout = 3000;
        break;
    case 0x4b:
        r->u.f.b30 = 0;
        r->timeout = 200;
        break;
    case 0x4c:
        r->u.f.b30 = 0;
        break;
    case 0x4d:
        r->u.f.b30 = 1;
        r->timeout = 150;
        break;
    case 0x4e:
        r->u.f.b30 = 1;
        r->timeout = 220;
        break;
    case 0x4f:
        r->u.f.b30 = 0;
        r->timeout = 1000;
        break;
    default:
        r->u.f.b30 = 1;
        r->timeout = 5000;
        break;
    }
    if (FUN_a00d0530(port + 0xb, r->timeout))
        return;
}
