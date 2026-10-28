/* FUN_a00dae90 (leon2s 0xa00dae90-0xa00db53c, 1708 bytes), flags -mcpu=v8 -Os -g -msoft-float.
 * unsigned char (port, flag, mode). Clears the 64-byte stack buffer buf (func_0xa0fc15ac). mode 0: waits up to
 * 0x13 x func_0xa0fc1794(5) for bit 2 of word 0x258 of DAT_a807609c[DAT_a8078832]; sets bit 7 of word 0xc0 of
 * DAT_a80760a4[DAT_a8078832] around func_0xa0fc1394(0, buf); clears the 4-entry tables DAT_a80795d8 (id),
 * DAT_a807a820 (start) and DAT_a80795d0 (count); prints "PLDtable:" and buf as 8 rows of 8 "%02X " bytes;
 * scans buf[0..0x3e] and collects runs of equal non-zero bytes into the tables (start = i, plus 1 unless
 * func_0xa0f99e4c(0) returns 1; at most 4 entries); prints "Receive :" and each entry ("ID : %d, Start : %d,
 * Count : %d"). When func_0xa0f99e4c(0) returns 0: for j < DAT_a80760ac it writes j to bits 6.. of word 0x2ac,
 * reads v = word 0x284 ("Remove ID : %d"), zeroes the count of the entry with id v and subtracts that count from
 * the start of every entry with a non-zero id and count; then clears bits 6.. of word 0x2ac. With flag set, the
 * entry whose id equals port is removed: its count is added to c, DAT_a8079c61 = id, DAT_a807963c = start;
 * later entries move down with start - c. If func_0xa0f99e4c(0) returns 0 the tables are printed again
 * ("Transform %d:"). func_0xa0f96360(0, 0x80, 0x2c0, 1) non-zero: prints "Write 0x2C0h --> FALSE!\r", returns
 * 0. Then the 3-byte record rec = {0, 0, 0x3f} (mode != 0), {DAT_a8079c61, DAT_a807963c, 0} (flag set), or one
 * record per entry whose id equals port ({id, start, count}), is passed to func_0xa0f963d4(0, 0x80, 0x1c0, 2,
 * rec); a zero result prints "Write 0x1C0h --> FALSE!\r" and returns 0; otherwise returns 1.
 * Source forms the exact build depends on: the scan loop uses its own byte x; the table clear stores id, start,
 * count; in the flag loop 'c += count; DAT_a8079c61 = v; DAT_a807963c = start;' and 'id, start - c, count';
 * the first record write jumps to the 'return 1' after the entry loop (one shared exit block).
 * Compiler aid: __builtin_expect(flag != 0, 0) on the flag test emits no instructions; it sets the branch
 * prediction that places the firmware's instruction in that branch's delay slot.
 */
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a80760ac;
extern unsigned char DAT_a8079c61;
extern unsigned char DAT_a807963c;
extern unsigned char DAT_a80795d0[];
extern unsigned char DAT_a80795d8[];
extern unsigned char DAT_a807a820[];
extern volatile unsigned int *DAT_a807609c[];
extern volatile unsigned int *DAT_a80760a4[];
extern const char DAT_9f1cca08[];
extern const char DAT_9f1cca20[];
extern const char DAT_9f1cca28[];
extern const char DAT_9f1cca30[];
extern const char DAT_9f1cca38[];
extern const char DAT_9f1cca40[];
extern const char DAT_9f1cca48[];
extern const char DAT_9f1cca58[];
extern const char DAT_9f1cca80[];
extern const char DAT_9f1cca98[];
extern const char DAT_9f1ccaa8[];
extern const char DAT_9f1ccac8[];
extern void *func_0xa0fc15ac(void *, int, unsigned int);
extern void func_0xa0fc1794(unsigned int);
extern int func_0xa0fc1394(int, unsigned char *);
extern int func_0xa0f83044(const char *, ...);
extern void func_0xa0f834c4(const char *);
extern int func_0xa0f99e4c(int);
extern int func_0xa0f96360(int, int, int, int);
extern int func_0xa0f963d4(int, int, int, int, unsigned char *);

unsigned char FUN_a00dae90(unsigned char port, unsigned char flag, unsigned char mode)
{
    unsigned char buf[64];
    unsigned char rec[3];
    unsigned char i;
    unsigned char j;
    unsigned char v;
    unsigned char c;
    unsigned char w;
    unsigned char x;

    func_0xa0fc15ac(buf, 0, 0x40);
    if (mode == 0) {
        for (i = 0x13; !(DAT_a807609c[DAT_a8078832][0x258 / 4] & 4) && i != 0; i--)
            func_0xa0fc1794(5);
        DAT_a80760a4[DAT_a8078832][0xc0 / 4] |= 0x80;
        func_0xa0fc1394(0, buf);
        DAT_a80760a4[DAT_a8078832][0xc0 / 4] &= ~0x80;
        for (i = 0; i < 4; i++) {
            DAT_a80795d8[i] = 0;
            DAT_a807a820[i] = 0;
            DAT_a80795d0[i] = 0;
        }
        func_0xa0f83044(DAT_9f1cca08, DAT_9f1cca20);
        for (i = 0; i < 8; i++) {
            func_0xa0f83044(DAT_9f1cca28);
            for (j = 0; j < 8; j++)
                func_0xa0f83044(DAT_9f1cca30, buf[i * 8 + j]);
            func_0xa0f83044(DAT_9f1cca38, DAT_9f1cca40);
        }
        j = 0;
        for (i = 0; i < 0x3f; i++) {
            x = buf[i];
            if (x != 0) {
                if (i == 0) {
                    DAT_a80795d8[j] = buf[0];
                    if (buf[0] != 0) {
                        if ((unsigned char)func_0xa0f99e4c(0) == 1)
                            DAT_a807a820[j] = 0;
                        else
                            DAT_a807a820[j] = 1;
                        DAT_a80795d0[j] = 1;
                    }
                } else if (x == DAT_a80795d8[j]) {
                    DAT_a80795d0[j]++;
                } else {
                    if (j + 1 > 3)
                        break;
                    j++;
                    DAT_a80795d8[j] = x;
                    if (x != 0) {
                        if ((unsigned char)func_0xa0f99e4c(0) == 1)
                            DAT_a807a820[j] = i;
                        else
                            DAT_a807a820[j] = i + 1;
                        DAT_a80795d0[j] = 1;
                    }
                }
            }
        }
        func_0xa0f834c4(DAT_9f1cca48);
        for (i = 0; i < 4; i++)
            func_0xa0f83044(DAT_9f1cca58, DAT_a80795d8[i], DAT_a807a820[i], DAT_a80795d0[i]);
        if ((unsigned char)func_0xa0f99e4c(0) == 0) {
            for (j = 0; j < DAT_a80760ac; j++) {
                DAT_a807609c[DAT_a8078832][0x2ac / 4] =
                    (DAT_a807609c[DAT_a8078832][0x2ac / 4] & 0x3f) | (j << 6);
                v = DAT_a807609c[DAT_a8078832][0x284 / 4];
                func_0xa0f83044(DAT_9f1cca80, v);
                c = 0;
                for (i = 0; i < 4; i++) {
                    if (DAT_a80795d8[i] == v) {
                        c = DAT_a80795d0[i];
                        DAT_a80795d0[i] = 0;
                        break;
                    }
                }
                for (i = 0; i < 4; i++)
                    if (DAT_a80795d8[i] != 0 && DAT_a80795d0[i] != 0)
                        DAT_a807a820[i] -= c;
            }
            DAT_a807609c[DAT_a8078832][0x2ac / 4] &= 0x3f;
            if (flag) {
                c = 0;
                j = 0;
                for (i = 0; i < 4; i++) {
                    v = DAT_a80795d8[i];
                    if (v == 0)
                        break;
                    if (v == port) {
                        c += DAT_a80795d0[i];
                        DAT_a8079c61 = v;
                        DAT_a807963c = DAT_a807a820[i];
                    } else {
                        if (c != 0) {
                            DAT_a80795d8[j] = v;
                            DAT_a807a820[j] = DAT_a807a820[i] - c;
                            DAT_a80795d0[j] = DAT_a80795d0[i];
                        }
                        j++;
                    }
                }
            }
        }
    }
    if ((unsigned char)func_0xa0f99e4c(0) == 0) {
        func_0xa0f83044(DAT_9f1cca98, 1);
        for (i = 0; i < 4; i++)
            func_0xa0f83044(DAT_9f1cca58, DAT_a80795d8[i], DAT_a807a820[i], DAT_a80795d0[i]);
    }
    if ((unsigned char)func_0xa0f96360(0, 0x80, 0x2c0, 1) != 0) {
        func_0xa0f834c4(DAT_9f1ccaa8);
        return 0;
    }
    if (mode != 0) {
        rec[2] = 0x3f;
        rec[0] = 0;
        rec[1] = 0;
    } else if (__builtin_expect(flag != 0, 0)) {
        rec[0] = DAT_a8079c61;
        rec[1] = DAT_a807963c;
        rec[2] = 0;
    } else {
        i = 0;
        goto search;
    }
    if ((unsigned char)func_0xa0f963d4(0, 0x80, 0x1c0, 2, rec) != 0)
        goto done;
fail:
    func_0xa0f834c4(DAT_9f1ccac8);
    return 0;
search:
    for (; i < 4; i++) {
        w = DAT_a80795d8[i];
        if (w == 0)
            break;
        if (w == port) {
            rec[0] = w;
            rec[1] = DAT_a807a820[i];
            rec[2] = DAT_a80795d0[i];
            if ((unsigned char)func_0xa0f963d4(0, 0x80, 0x1c0, 2, rec) == 0)
                goto fail;
        }
    }
done:
    return 1;
}
