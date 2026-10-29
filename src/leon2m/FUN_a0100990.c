/* leon2m FUN_a0100990 @ 0xa0100990-0xa0100a40 (176 bytes), flags -mcpu=v8 -O3 -g.
 * Returns 0x28 when x != 4. Otherwise maps the byte DAT_a8027a7c through a switch (jump table 0xa0584,
 * 42 entries): 0, 1, 27 -> 2; 2, 14, 16, 17, 18 -> 15; 4, 5, 6 -> 3; 8, 10, 11, 12 -> 9; 20, 22, 23, 24 -> 21;
 * 26, 36 -> 34; 28, 30-33 -> 29; 34, 37, 38, 39 -> 35; every other value (including 41 and values above 41)
 * is returned unchanged. The result is held in an int and returned as unsigned char.
 * Source form: one case body per value (case 38 and 39 share one), case 36 written before case 26; the value is
 * read into an unsigned short and the values returned unchanged are written '(unsigned char)v'; case 41 keeps
 * r = v without an assignment.
 * Compiler aid: __builtin_expect(x != 4, 1) emits no instructions; it changes the branch prediction so that
 * block reordering copies the final 'and 0xff' into every case.
 */
extern unsigned char DAT_a8027a7c;

unsigned char FUN_a0100990(unsigned char x)
{
    unsigned short v;
    int r;

    if (__builtin_expect(x != 4, 1))
        return 0x28;
    v = DAT_a8027a7c;
    r = v;
    switch (r) {
    case 0:
        r = 2;
        break;
    case 1:
        r = 2;
        break;
    case 2:
        r = 15;
        break;
    case 3:
        r = (unsigned char)v;
        break;
    case 4:
        r = 3;
        break;
    case 5:
        r = 3;
        break;
    case 6:
        r = 3;
        break;
    case 7:
        r = (unsigned char)v;
        break;
    case 8:
        r = 9;
        break;
    case 9:
        r = (unsigned char)v;
        break;
    case 10:
        r = 9;
        break;
    case 11:
        r = 9;
        break;
    case 12:
        r = 9;
        break;
    case 13:
        r = (unsigned char)v;
        break;
    case 14:
        r = 15;
        break;
    case 15:
        r = (unsigned char)v;
        break;
    case 16:
        r = 15;
        break;
    case 17:
        r = 15;
        break;
    case 18:
        r = 15;
        break;
    case 19:
        r = (unsigned char)v;
        break;
    case 20:
        r = 21;
        break;
    case 21:
        r = (unsigned char)v;
        break;
    case 22:
        r = 21;
        break;
    case 23:
        r = 21;
        break;
    case 24:
        r = 21;
        break;
    case 25:
        r = (unsigned char)v;
        break;
    case 36:
        r = 34;
        break;
    case 26:
        r = 34;
        break;
    case 27:
        r = 2;
        break;
    case 28:
        r = 29;
        break;
    case 29:
        r = (unsigned char)v;
        break;
    case 30:
        r = 29;
        break;
    case 31:
        r = 29;
        break;
    case 32:
        r = 29;
        break;
    case 33:
        r = 29;
        break;
    case 34:
        r = 35;
        break;
    case 35:
        r = (unsigned char)v;
        break;
    case 37:
        r = 35;
        break;
    case 38:
    case 39:
        r = 35;
        break;
    case 40:
        r = (unsigned char)v;
        break;
    case 41:
        break;
    default:
        r = (unsigned char)v;
        break;
    }
    return r;
}
