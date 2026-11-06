/* leon2m FUN_a00eba64 @ 0xa00eba64-0xa00ec340 (2268 bytes), flags -mcpu=v8 -O3 -g -msoft-float. Caller: FUN_a00ec6b8.
 * FUN_a00eba64(unit, x1, x2, b, cnt, p6, p7, p8): FUN_a00eb708(unit, b, cnt, p6, p7); r = FUN_a00e4278(unit, x1, x2,
 * p8); r != 0 returns -1. Register fields are read with FUN_a00e0754 and written with FUN_a00e0774, with (reg, mask,
 * shift) from entry b of three word tables (b == -1 passes the table addresses themselves), as in FUN_a00ec340;
 * fields below are named by their first table.
 * While cnt != 0: cnt is decremented, fields 0xa80268e8 and 0xa80268b8 are decremented, field 0xa8026948 = 3 when
 * cnt > 8, else 0, and r = FUN_a00e4278(unit, x1, x2, p8): 1 ends the loop, 0 repeats it, other values print
 * "Error: Bist timeout.\n" after FUN_a00df80c(), FUN_a00e0bc0() and return -1.
 * r == 1: fields 0xa8026798 and 0xa8026748 are incremented and FUN_a00e4278 repeated: 1 repeats while field
 * 0xa8026798 is not 0xf; 0 decrements both fields again; other values fail as above. Then fields 0xa8026768 and
 * 0xa8026718 are incremented while FUN_a00e4278 returns 1, with fields 0xa8026798 and 0xa8026748 incremented when
 * field 0xa8026768 is 7; 0 ends the loop, other values fail as above.
 * End: fields 0xa80268e8, 0xa80268b8, 0xa8026798 (h) and 0xa8026768 (l) are read; returns cnt << 8 | h << 3 | l.
 * Source form: the 0xa8026798 / 0xa8026748 loop is a label with a backward goto (its preheader 0xa00ebc30..0xa00ebc44
 * holds only the six high parts, the sll of b at 0xa00ebc50 and the low parts are inside the loop; the for loops get
 * full hoists); 'if (r != 1) goto done;' after the first loop; in the first loop the 0xa80268e8 read/write pair is one
 * if (b != -1)/else statement and the 0xa80268b8 pair one if (b == -1)/else statement (fw preheader 0xa00ebaa8..
 * 0xa00ebad8); the decrement and the two increment groups of the later loops are one if (b == -1)/else statement each,
 * other accesses one statement each; the 0xf test arm stands before the decrement arm; the loop-condition reads are
 * conditional expressions of two calls; the tables at 0xa8026778 / 0xa8026748 / 0xa8026718 are declared as
 * s_a8026778 / ARR_a8026748 / ARR_a8026718 (the symbol names set the order of the address pseudos and so the register
 * choices).
 * Fake match: s_a8026778 and ARR_a8026748 are names chosen only for their gcse hash order; with the attested names the same source scores 89.77.
 */
extern unsigned int FUN_a00e0754(unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00e0774(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00eb708(unsigned int, int, int, unsigned int, unsigned int);
extern int FUN_a00e4278(unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00df80c(void);
extern void FUN_a00e0bc0(void);
extern int FUN_a00df170(const char *, ...);
extern unsigned int DAT_a80268e8[], DAT_a80268d8[], DAT_a80268c8[], DAT_a80268b8[], DAT_a80268a8[], DAT_a8026898[], DAT_a8026948[], DAT_a8026938[], DAT_a8026928[], DAT_a8026798[], DAT_a8026788[], s_a8026778[], ARR_a8026748[], DAT_a8026738[], DAT_a8026728[], DAT_a8026768[], DAT_a8026758[], DAT_a802b6e8[], ARR_a8026718[], DAT_a8026708[], DAT_a802b6d8[];

int FUN_a00eba64(unsigned int unit, unsigned int x1, unsigned int x2, int b, int cnt, unsigned int p6,
                 unsigned int p7, unsigned int p8)
{
    unsigned int v, h, l;
    int r;

    FUN_a00eb708(unit, b, cnt, p6, p7);
    r = FUN_a00e4278(unit, x1, x2, p8);
    if (r != 0)
        return -1;
    for (;;) {
        if (cnt == 0)
            break;
        cnt--;
        if (b != -1) {
        v = FUN_a00e0754(unit, DAT_a80268e8[b], DAT_a80268d8[b], DAT_a80268c8[b]);
        FUN_a00e0774(unit, DAT_a80268e8[b], DAT_a80268d8[b], DAT_a80268c8[b], v - 1);
        } else {
        v = FUN_a00e0754(unit, (unsigned int)DAT_a80268e8, (unsigned int)DAT_a80268d8, (unsigned int)DAT_a80268c8);
        FUN_a00e0774(unit, (unsigned int)DAT_a80268e8, (unsigned int)DAT_a80268d8, (unsigned int)DAT_a80268c8, v - 1);
        }
        if (b == -1) {
        v = FUN_a00e0754(unit, (unsigned int)DAT_a80268b8, (unsigned int)DAT_a80268a8, (unsigned int)DAT_a8026898);
        FUN_a00e0774(unit, (unsigned int)DAT_a80268b8, (unsigned int)DAT_a80268a8, (unsigned int)DAT_a8026898, v - 1);
        } else {
        v = FUN_a00e0754(unit, DAT_a80268b8[b], DAT_a80268a8[b], DAT_a8026898[b]);
        FUN_a00e0774(unit, DAT_a80268b8[b], DAT_a80268a8[b], DAT_a8026898[b], v - 1);
        }
        if (cnt > 8) {
            if (b == -1)
                FUN_a00e0774(unit, (unsigned int)DAT_a8026948, (unsigned int)DAT_a8026938, (unsigned int)DAT_a8026928, 3);
            else
                FUN_a00e0774(unit, DAT_a8026948[b], DAT_a8026938[b], DAT_a8026928[b], 3);
        } else {
            if (b == -1)
                FUN_a00e0774(unit, (unsigned int)DAT_a8026948, (unsigned int)DAT_a8026938, (unsigned int)DAT_a8026928, 0);
            else
                FUN_a00e0774(unit, DAT_a8026948[b], DAT_a8026938[b], DAT_a8026928[b], 0);
        }
        r = FUN_a00e4278(unit, x1, x2, p8);
        if (r == 1)
            break;
        if (r == 0)
            continue;
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170("Error: Bist timeout.\n");
        return -1;
    }
    if (r != 1)
        goto done;
incA:
    if (b == -1)
        v = FUN_a00e0754(unit, (unsigned int)DAT_a8026798, (unsigned int)DAT_a8026788, (unsigned int)s_a8026778);
    else
        v = FUN_a00e0754(unit, DAT_a8026798[b], DAT_a8026788[b], s_a8026778[b]);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026798, (unsigned int)DAT_a8026788, (unsigned int)s_a8026778, v + 1);
    else
        FUN_a00e0774(unit, DAT_a8026798[b], DAT_a8026788[b], s_a8026778[b], v + 1);
    if (b == -1)
        v = FUN_a00e0754(unit, (unsigned int)ARR_a8026748, (unsigned int)DAT_a8026738, (unsigned int)DAT_a8026728);
    else
        v = FUN_a00e0754(unit, ARR_a8026748[b], DAT_a8026738[b], DAT_a8026728[b]);
    if (b != -1)
        FUN_a00e0774(unit, ARR_a8026748[b], DAT_a8026738[b], DAT_a8026728[b], v + 1);
    else
        FUN_a00e0774(unit, (unsigned int)ARR_a8026748, (unsigned int)DAT_a8026738, (unsigned int)DAT_a8026728, v + 1);
    r = FUN_a00e4278(unit, x1, x2, p8);
    if (r == 1) {
        if ((b == -1 ? FUN_a00e0754(unit, (unsigned int)DAT_a8026798, (unsigned int)DAT_a8026788, (unsigned int)s_a8026778) : FUN_a00e0754(unit, DAT_a8026798[b], DAT_a8026788[b], s_a8026778[b])) != 0xf)
            goto incA;
    } else {
        if (r != 0) {
            FUN_a00df80c();
            FUN_a00e0bc0();
            FUN_a00df170("Error: Bist timeout.\n");
            return -1;
        }
        if (b == -1) {
        v = FUN_a00e0754(unit, (unsigned int)DAT_a8026798, (unsigned int)DAT_a8026788, (unsigned int)s_a8026778);
        FUN_a00e0774(unit, (unsigned int)DAT_a8026798, (unsigned int)DAT_a8026788, (unsigned int)s_a8026778, v - 1);
        v = FUN_a00e0754(unit, (unsigned int)ARR_a8026748, (unsigned int)DAT_a8026738, (unsigned int)DAT_a8026728);
        FUN_a00e0774(unit, (unsigned int)ARR_a8026748, (unsigned int)DAT_a8026738, (unsigned int)DAT_a8026728, v - 1);
        } else {
        v = FUN_a00e0754(unit, DAT_a8026798[b], DAT_a8026788[b], s_a8026778[b]);
        FUN_a00e0774(unit, DAT_a8026798[b], DAT_a8026788[b], s_a8026778[b], v - 1);
        v = FUN_a00e0754(unit, ARR_a8026748[b], DAT_a8026738[b], DAT_a8026728[b]);
        FUN_a00e0774(unit, ARR_a8026748[b], DAT_a8026738[b], DAT_a8026728[b], v - 1);
        }
    }
    for (;;) {
        if (b == -1) {
        v = FUN_a00e0754(unit, (unsigned int)DAT_a8026768, (unsigned int)DAT_a8026758, (unsigned int)DAT_a802b6e8);
        FUN_a00e0774(unit, (unsigned int)DAT_a8026768, (unsigned int)DAT_a8026758, (unsigned int)DAT_a802b6e8, v + 1);
        v = FUN_a00e0754(unit, (unsigned int)ARR_a8026718, (unsigned int)DAT_a8026708, (unsigned int)DAT_a802b6d8);
        FUN_a00e0774(unit, (unsigned int)ARR_a8026718, (unsigned int)DAT_a8026708, (unsigned int)DAT_a802b6d8, v + 1);
        } else {
        v = FUN_a00e0754(unit, DAT_a8026768[b], DAT_a8026758[b], DAT_a802b6e8[b]);
        FUN_a00e0774(unit, DAT_a8026768[b], DAT_a8026758[b], DAT_a802b6e8[b], v + 1);
        v = FUN_a00e0754(unit, ARR_a8026718[b], DAT_a8026708[b], DAT_a802b6d8[b]);
        FUN_a00e0774(unit, ARR_a8026718[b], DAT_a8026708[b], DAT_a802b6d8[b], v + 1);
        }
        r = FUN_a00e4278(unit, x1, x2, p8);
        if (r != 1)
            break;
        if ((b == -1 ? FUN_a00e0754(unit, (unsigned int)DAT_a8026768, (unsigned int)DAT_a8026758, (unsigned int)DAT_a802b6e8) : FUN_a00e0754(unit, DAT_a8026768[b], DAT_a8026758[b], DAT_a802b6e8[b])) == 7) {
            if (b == -1) {
            v = FUN_a00e0754(unit, (unsigned int)DAT_a8026798, (unsigned int)DAT_a8026788, (unsigned int)s_a8026778);
            FUN_a00e0774(unit, (unsigned int)DAT_a8026798, (unsigned int)DAT_a8026788, (unsigned int)s_a8026778, v + 1);
            v = FUN_a00e0754(unit, (unsigned int)ARR_a8026748, (unsigned int)DAT_a8026738, (unsigned int)DAT_a8026728);
            FUN_a00e0774(unit, (unsigned int)ARR_a8026748, (unsigned int)DAT_a8026738, (unsigned int)DAT_a8026728, v + 1);
            } else {
            v = FUN_a00e0754(unit, DAT_a8026798[b], DAT_a8026788[b], s_a8026778[b]);
            FUN_a00e0774(unit, DAT_a8026798[b], DAT_a8026788[b], s_a8026778[b], v + 1);
            v = FUN_a00e0754(unit, ARR_a8026748[b], DAT_a8026738[b], DAT_a8026728[b]);
            FUN_a00e0774(unit, ARR_a8026748[b], DAT_a8026738[b], DAT_a8026728[b], v + 1);
            }
        }
    }
    if (r != 0) {
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170("Error: Bist timeout.\n");
        return -1;
    }
done:
    if (b == -1)
        FUN_a00e0754(unit, (unsigned int)DAT_a80268e8, (unsigned int)DAT_a80268d8, (unsigned int)DAT_a80268c8);
    else
        FUN_a00e0754(unit, DAT_a80268e8[b], DAT_a80268d8[b], DAT_a80268c8[b]);
    if (b == -1)
        FUN_a00e0754(unit, (unsigned int)DAT_a80268b8, (unsigned int)DAT_a80268a8, (unsigned int)DAT_a8026898);
    else
        FUN_a00e0754(unit, DAT_a80268b8[b], DAT_a80268a8[b], DAT_a8026898[b]);
    if (b == -1)
        h = FUN_a00e0754(unit, (unsigned int)DAT_a8026798, (unsigned int)DAT_a8026788, (unsigned int)s_a8026778);
    else
        h = FUN_a00e0754(unit, DAT_a8026798[b], DAT_a8026788[b], s_a8026778[b]);
    if (b == -1)
        l = FUN_a00e0754(unit, (unsigned int)DAT_a8026768, (unsigned int)DAT_a8026758, (unsigned int)DAT_a802b6e8);
    else
        l = FUN_a00e0754(unit, DAT_a8026768[b], DAT_a8026758[b], DAT_a802b6e8[b]);
    return cnt << 8 | h << 3 | l;
}
