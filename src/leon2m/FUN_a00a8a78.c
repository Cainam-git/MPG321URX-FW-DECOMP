/* leon2m FUN_a00a8a78 @ 0xa00a8a78-0xa00a8ae0 (26 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Maps the halfword returned by FUN_a0090fcc (halfword 0xa802afee) to 0, 1 or 2: 1 for one group of values, 2
 * for a second group, 1 for 0xc0..0xc2 when p == 2 (0 otherwise), 0 for all other values. The result is returned
 * as (r & 3). The groups are the cases of a switch with a jump table (0x43878, values 0x3f..0xf9).
 * The 0xc0..0xc2 group is the second-to-last case group: GCC places it first after the jump.
 */
extern unsigned short FUN_a0090fcc(void);

unsigned char FUN_a00a8a78(unsigned char p)
{
    unsigned char r = 0;

    switch (FUN_a0090fcc()) {
    case 0x3f:
    case 0x40:
    case 0x41:
    case 0x44:
    case 0x45:
    case 0x53:
    case 0x56:
    case 0x58:
    case 0x59:
    case 0x5a:
    case 0x5b:
    case 0x6f:
    case 0x7a:
    case 0x7b:
    case 0x7c:
    case 0x82:
    case 0x83:
    case 0xb3:
    case 0xba:
    case 0xbd:
    case 0xbe:
    case 0xbf:
    case 0xdc:
    case 0xe1:
    case 0xe6:
        r = 1;
        break;
    case 0xc0:
    case 0xc1:
    case 0xc2:
        if (p == 2)
            r = 1;
        break;
    case 0x69:
    case 0x6a:
    case 0x6b:
    case 0xaf:
    case 0xb0:
    case 0xca:
    case 0xcb:
    case 0xcc:
    case 0xf5:
    case 0xf7:
    case 0xf8:
    case 0xf9:
        r = 2;
        break;
    }
    return r & 3;
}
