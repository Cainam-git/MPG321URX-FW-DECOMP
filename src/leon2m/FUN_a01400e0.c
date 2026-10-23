/* leon2m FUN_a01400e0 @ 0xa01400e0..0xa0140304 (137 words)  start-up step 5 of FUN_a015266c (first call after WAIT 2):
 * lays out the EEPROM areas from the two ROM descriptor tables.
 * What it does (code facts):
 *  - 3 ROM records A[i] (36 bytes, DAT_001a6a24 = flash 0x2AEA24: h0 size, b2 kind, b3 group, name at +4; FW.021:
 *    "OPR_EEPROM_1/2/3", size 0x8000 / 0 / 0, kind 2, group 1 / 2 / 3): per group a running u16 offset (local
 *    sum[4], starts 0); RAM record D[i] (12 bytes, DAT_a802cbdc) gets h0 = the group's offset before adding A[i].h0,
 *    w4 = -1, b8 = 0xFF.
 *  - 1 ROM record B[0] (38 bytes, DAT_001a69fe = flash 0x2AE9FE: b0 A-index, b1, h2 size, b4 shift, name at +5;
 *    FW.021: "DG_EEPROM1", b0 = b1 = 0, size 0x80, b4 = 0): RAM record E[0] (4 bytes, DAT_a802cc00) gets h0 = running
 *    offset of slot 2*b0+b1 (local sum2[2]) and b2 = 8 >> b4.
 *  - For B[0] whose A[b0] has kind 0 only: n = (A.h0 >> 8) >> (b4 - 1) pages, D[b0].b9 = n, and D[b0].b8 = the
 *    first page j < n whose last byte (address D.h0 + (j + 1) * (b4 << 8) - 1, read in place) is 0x55, else 0xFF.
 *    FW.021: A[0].kind = 2, so this page scan does NOT run (D[0].b8 stays 0xFF).
 *  FUN_a0140ab4 / FUN_a01405d0 later use D/E to find which area an address belongs to (their headers).
 * Can it fail or wait? No: fixed loops (4, 3, 2, 1, 1 turns; the page scan is bounded by n), no registers, no timeout.
 * Exact form: sum2 declared first with 8 u16 slots (fw frame 128 = sum2 at fp-24, sum at fp-32; slot index 2*b0+b1
 * can reach 5; only slots 0..1 are cleared, as in the fw), the running sums as '+=' (operand order), loop-1 stores
 * w4, b8 before the read, the page scan inside 'if (kind == 0)' (a 'continue' duplicates the b8 store), the
 * one-record loops as for (i < 1) (fw 'cmp i,0; be'), u8 counters.
 */
struct A36 { unsigned short h0; unsigned char b2, b3; char name[32]; };
struct B38 { unsigned char b0, b1; unsigned short h2; unsigned char b4; char name[33]; };
struct D12 { unsigned short h0; unsigned short h2; int w4; unsigned char b8, b9; unsigned char pad[2]; };
struct E4 { unsigned short h0; unsigned char b2, b3; };
extern const struct A36 DAT_001a6a24[];
extern const struct B38 DAT_001a69fe[];
extern struct D12 DAT_a802cbdc[];
extern struct E4 DAT_a802cc00[];

void FUN_a01400e0(void)
{
    unsigned short sum2[8];
    unsigned short sum[4];
    unsigned char i, j, b, m, n, r;
    unsigned short old;
    struct D12 *d;

    for (i = 0; i < 4; i++)
        sum[i] = 0;
    for (i = 0; i < 3; i++) {
        DAT_a802cbdc[i].w4 = -1;
        DAT_a802cbdc[i].b8 = 0xff;
        DAT_a802cbdc[i].h0 = sum[DAT_001a6a24[i].b3];
        sum[DAT_001a6a24[i].b3] += DAT_001a6a24[i].h0;
    }
    for (i = 0; i < 2; i++)
        sum2[i] = 0;
    for (i = 0; i < 1; i++) {
        b = DAT_001a69fe[i].b0 * 2 + DAT_001a69fe[i].b1;
        old = sum2[b];
        sum2[b] += DAT_001a69fe[i].h2;
        DAT_a802cc00[i].b2 = 8 >> DAT_001a69fe[i].b4;
        DAT_a802cc00[i].h0 = old;
    }
    for (i = 0; i < 1; i++) {
        b = DAT_001a69fe[i].b0;
        if (DAT_001a6a24[b].b2 == 0) {
            m = DAT_001a69fe[i].b4;
            d = &DAT_a802cbdc[b];
            n = (DAT_001a6a24[b].h0 >> 8) >> (m - 1);
            d->b9 = n;
            r = 0xff;
            for (j = 0; j < n; j++)
                if (*(unsigned char *)(DAT_a802cbdc[b].h0 + (j + 1) * (m << 8) - 1) == 0x55) {
                    r = j;
                    break;
                }
            d->b8 = r;
        }
    }
}
