# bank 0 data-region rules (exec'd by refs.py with B = Bank(0)). Partition table at CODE/file 0x6000.
# Record k (8 bytes, big-endian): bytes 0..3 flash address (byte 0 = A31..24 for SetExtendedAddr, 1..3 = A23..0),
# bytes 4..7 length. Evidence: FUN_CODE_0003 (record 0 into the copy registers F1D3..F1D8; records 1.. raw into the
# share structure XDATA 0x3000), bank 1 FUN_CODE_0b0d (share 0x3002.. -> record block 0xA47F..) and its users.
RECS = [
    (0x6000, "8051 bank 1 (main application)", 0x010000, "FUN_CODE_0003 -> F1D3..F1D5 / F1D6..F1D8 (hardware copy of bank 1)", True),
    (0x6008, "8051 bank 2 (update agent)", 0x020000, "FUN_CODE_0003 -> share kind 1 (0x3002) -> bank1 0xA47F/0xA483 -> FUN_CODE_96eb", True),
    (0x6010, "Leon2M start-up code", 0x0D0000, "share kind 2 (0x300E) -> bank1 0xA48B/0xA48F -> FUN_CODE_0b0d copy to 0x9F040000", True),
    (0x6018, "Leon2M initialised data", 0x0EC000, "share kind 2 -> bank1 0xA493 (src) / 0xA49B (len), dst 0x9F060000 constant", True),
    (0x6020, "Leon2M code window", 0x108000, "share kind 2 -> bank1 0xA49F -> F1DB..F1DE (FUN_CODE_0b0d tail); length NOT copied", False),
    (0x6028, "Leon2S program", 0x050000, "share kind 3 (0x3032) -> bank1 0xA4AF/0xA4B3 -> FUN_CODE_0b0d record 3", True),
    (0x6030, "Leon2S part at 0x0A6000 (copied to 0x9F196000)", 0x0A6000, "share kind 3 -> bank1 0xA4B7/0xA4BF -> FUN_CODE_0b0d record 5", True),
    (0x6038, "Tensilica program", 0x030000, "share kind 4 (0x305A) -> bank1 0xA4D7 -> FUN_CODE_c43e", True),
    (0x6040, "Leon2S part at 0x0B0000 (copied to 0x9F1B0000 for D511 in 16/1E/1F/17)", 0x0B0000, "share kind 3 -> bank1 0xA4C3/0xA4C7 -> FUN_CODE_0b0d record 4", True),
]
for at, what, exp, path, lenused in RECS:
    a = int.from_bytes(B.bk[at:at + 4], "big"); n = int.from_bytes(B.bk[at + 4:at + 8], "big")
    assert a == exp, (hex(at), hex(a))
    B.add(at, 4, a, {"kind": "data", "name": what, "off": a}, ["codeuse:FUN_CODE_0003", "partition-table"], "sure",
          region="partition", note="partition record 0x%04X: flash address of %s; %s" % (at, what, path))
    if lenused:
        B.add(at + 4, 4, n, {"kind": "length", "name": "length of " + what, "off": None},
              ["codeuse:FUN_CODE_0003", "partition-table"], "sure", region="partition",
              note="partition record 0x%04X: length 0x%X of %s (ends file 0x%06X); changes when that part grows" % (at, n, what, a + n))
    else:
        B.add(at + 4, 4, n, {"kind": "length", "name": "length of " + what, "off": None}, ["partition-table", "record-format"], "sure",
              region="partition", note="length 0x%X of %s (ends file 0x%06X): no 8051 code reads it (FUN_CODE_0003 copies only "
              "bytes 0x20..0x23 of this record); listed because it is the length field of a partition record like the other eight, "
              "and it would be wrong after that part grows" % (n, what, a + n))

# LEON-side load destinations the boot loader writes into the share structure as constants (a000[0x18..0x1b] =
# 9F 06 00 00 = Leon2M initialised-data destination; a000[0x3c..0x3f] = 9F 19 60 00 = destination of the 0x0A6000
# part). Byte-wise MOV DPTR,#0xA0xx / MOV A,#imm / MOVX: one entry per 4-byte constant, at its first byte's operand.
# operand offsets checked by disassembly (0x0401.. and 0x05DF..); zero bytes come from CLR A (no operand)
for v, ops, base, what in ((0x9F060000, {0: 0x405, 1: 0x409}, 0xA018, "Leon2M initialised-data load destination"),
                           (0x9F196000, {0: 0x5E3, 1: 0x5E7, 2: 0x5EB}, 0xA03C, "load destination of the 0x0A6000 part")):
    for k, o in ops.items(): assert B.bk[o] == (v >> (24 - 8 * k)) & 0xFF, hex(o)
    B.add(ops[0], 4, v, {"kind": "ram", "name": "LEON-side 0x%08X" % v, "off": None}, ["codeuse:FUN_CODE_0003"], "sure",
          region="code", fixed=True, split={"b%d" % k: B.base + o for k, o in ops.items()},
          note="%s, stored byte by byte (MOV A,#imm / MOVX, zero bytes by CLR A) into share structure XDATA 0x%04X..; "
               "LEON-side address, independent of the 8051 and flash layout" % (what, base))
