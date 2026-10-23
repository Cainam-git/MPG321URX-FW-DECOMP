/* leon2m FUN_a014ce84 @ 0xa014ce84-0xa014d3d4, flags -mcpu=v8 -O3 -g.
 * Switch on id 6..35 (jump table at 0xe3628; other ids do nothing). Each case stores v into one byte of the
 * 3-byte entry table DAT_a802e1f0: ids 6..23 -> bytes 6..0x17 (entries 2..7), ids 24..26 -> bytes 0x21..0x23
 * (entry 11), ids 27..35 -> bytes 0x18..0x20 (entries 8..10). When apply is non-zero and byte 0xb of
 * DAT_a802e3d0 equals the value of that entry (entries 2..11 -> 1, 4, 5, 6, 7, 8, 9, 0xa, 0xb, 0xf),
 * FUN_a014c118 is tail-called with that value. Caller: FUN_a00d4560.
 * Source form: one case per id in ascending order; GCC shares the call blocks of the three ids of an entry.
 */
extern unsigned char DAT_a802e1f0[];
extern unsigned char DAT_a802e3d0[];
extern void FUN_a014c118(unsigned char);

void FUN_a014ce84(int id, unsigned char v, unsigned char apply)
{
    switch (id) {
    case 6:
        DAT_a802e1f0[0x6] = v;
        if (apply && DAT_a802e3d0[0xb] == 0x1)
            FUN_a014c118(0x1);
        break;
    case 7:
        DAT_a802e1f0[0x7] = v;
        if (apply && DAT_a802e3d0[0xb] == 0x1)
            FUN_a014c118(0x1);
        break;
    case 8:
        DAT_a802e1f0[0x8] = v;
        if (apply && DAT_a802e3d0[0xb] == 0x1)
            FUN_a014c118(0x1);
        break;
    case 9:
        DAT_a802e1f0[0x9] = v;
        if (apply && DAT_a802e3d0[0xb] == 0x4)
            FUN_a014c118(0x4);
        break;
    case 10:
        DAT_a802e1f0[0xa] = v;
        if (apply && DAT_a802e3d0[0xb] == 0x4)
            FUN_a014c118(0x4);
        break;
    case 11:
        DAT_a802e1f0[0xb] = v;
        if (apply && DAT_a802e3d0[0xb] == 0x4)
            FUN_a014c118(0x4);
        break;
    case 12:
        DAT_a802e1f0[0xc] = v;
        if (apply && DAT_a802e3d0[0xb] == 0x5)
            FUN_a014c118(0x5);
        break;
    case 13:
        DAT_a802e1f0[0xd] = v;
        if (apply && DAT_a802e3d0[0xb] == 0x5)
            FUN_a014c118(0x5);
        break;
    case 14:
        DAT_a802e1f0[0xe] = v;
        if (apply && DAT_a802e3d0[0xb] == 0x5)
            FUN_a014c118(0x5);
        break;
    case 15:
        DAT_a802e1f0[0xf] = v;
        if (apply && DAT_a802e3d0[0xb] == 0x6)
            FUN_a014c118(0x6);
        break;
    case 16:
        DAT_a802e1f0[0x10] = v;
        if (apply && DAT_a802e3d0[0xb] == 0x6)
            FUN_a014c118(0x6);
        break;
    case 17:
        DAT_a802e1f0[0x11] = v;
        if (apply && DAT_a802e3d0[0xb] == 0x6)
            FUN_a014c118(0x6);
        break;
    case 18:
        DAT_a802e1f0[0x12] = v;
        if (apply && DAT_a802e3d0[0xb] == 0x7)
            FUN_a014c118(0x7);
        break;
    case 19:
        DAT_a802e1f0[0x13] = v;
        if (apply && DAT_a802e3d0[0xb] == 0x7)
            FUN_a014c118(0x7);
        break;
    case 20:
        DAT_a802e1f0[0x14] = v;
        if (apply && DAT_a802e3d0[0xb] == 0x7)
            FUN_a014c118(0x7);
        break;
    case 21:
        DAT_a802e1f0[0x15] = v;
        if (apply && DAT_a802e3d0[0xb] == 0x8)
            FUN_a014c118(0x8);
        break;
    case 22:
        DAT_a802e1f0[0x16] = v;
        if (apply && DAT_a802e3d0[0xb] == 0x8)
            FUN_a014c118(0x8);
        break;
    case 23:
        DAT_a802e1f0[0x17] = v;
        if (apply && DAT_a802e3d0[0xb] == 0x8)
            FUN_a014c118(0x8);
        break;
    case 24:
        DAT_a802e1f0[0x21] = v;
        if (apply && DAT_a802e3d0[0xb] == 0xf)
            FUN_a014c118(0xf);
        break;
    case 25:
        DAT_a802e1f0[0x22] = v;
        if (apply && DAT_a802e3d0[0xb] == 0xf)
            FUN_a014c118(0xf);
        break;
    case 26:
        DAT_a802e1f0[0x23] = v;
        if (apply && DAT_a802e3d0[0xb] == 0xf)
            FUN_a014c118(0xf);
        break;
    case 27:
        DAT_a802e1f0[0x18] = v;
        if (apply && DAT_a802e3d0[0xb] == 0x9)
            FUN_a014c118(0x9);
        break;
    case 28:
        DAT_a802e1f0[0x19] = v;
        if (apply && DAT_a802e3d0[0xb] == 0x9)
            FUN_a014c118(0x9);
        break;
    case 29:
        DAT_a802e1f0[0x1a] = v;
        if (apply && DAT_a802e3d0[0xb] == 0x9)
            FUN_a014c118(0x9);
        break;
    case 30:
        DAT_a802e1f0[0x1b] = v;
        if (apply && DAT_a802e3d0[0xb] == 0xa)
            FUN_a014c118(0xa);
        break;
    case 31:
        DAT_a802e1f0[0x1c] = v;
        if (apply && DAT_a802e3d0[0xb] == 0xa)
            FUN_a014c118(0xa);
        break;
    case 32:
        DAT_a802e1f0[0x1d] = v;
        if (apply && DAT_a802e3d0[0xb] == 0xa)
            FUN_a014c118(0xa);
        break;
    case 33:
        DAT_a802e1f0[0x1e] = v;
        if (apply && DAT_a802e3d0[0xb] == 0xb)
            FUN_a014c118(0xb);
        break;
    case 34:
        DAT_a802e1f0[0x1f] = v;
        if (apply && DAT_a802e3d0[0xb] == 0xb)
            FUN_a014c118(0xb);
        break;
    case 35:
        DAT_a802e1f0[0x20] = v;
        if (apply && DAT_a802e3d0[0xb] == 0xb)
            FUN_a014c118(0xb);
        break;
    }
}
