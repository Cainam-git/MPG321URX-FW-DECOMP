# bank 1 data-region rules (exec'd by refs.py with B = Bank(1))
# 1. CODE 0xB114..0xB192: 42 Keil generic pointers (type, hi, lo) = 'unsigned char volatile * code' tables
#    DAT_CODE_b114[7], b129[7], b13e[28] (b153/b168/b17d are slices of b13e), read by FUN_CODE_8947 / FUN_CODE_d56d
#    (split-DPTR MOVC entries in this list). All have type 0x01 = XDATA: hardware registers, fixed.
for at in range(0xB114, 0xB192, 3):
    t, v = B.bk[at], (B.bk[at + 1] << 8) | B.bk[at + 2]
    assert t == 0x01, hex(at)
    B.add(at, 3, (t << 16) | v, {"kind": "ram", "name": "XDATA 0x%04X" % v, "off": None},
          ["codeuse:FUN_CODE_8947", "codeuse:FUN_CODE_d56d", "keil-gptr-table"], "sure", region="table", fixed=True,
          note="generic pointer (type 01 = XDATA) to hardware register 0x%04X in DAT_CODE_b114/b129/b13e; does not move" % v)
# 2. CODE 0x8252 / 0x8292: 8 (register, value) long pairs each, written over the AHB bridge by FUN_CODE_4a85 / 5dcb
#    (?C?LLDCODE). Register words 0x9F...... are hardware (not listed). Value words that are LEON code addresses:
for at, val, what, fo, fn in ((0x825E, 0xA0028000, "Leon2M start-up code (boot / trap base)", 0x0D0000, "FUN_CODE_4a85"),
                              (0x829E, 0xA0060000, "Leon2S program start", 0x050000, "FUN_CODE_5dcb")):
    assert int.from_bytes(B.bk[at:at + 4], "big") == val
    B.add(at, 4, val, {"kind": "function", "name": "LEON 0x%08X = %s" % (val, what), "off": fo},
          ["codeuse:%s" % fn, "src:" + fn + " header (0x9F%s20000 = 0x%08X)" % ("0" if fo == 0x0D0000 else "1", val)], "sure",
          region="table", note="cross-program: LEON-side run address of %s (file 0x%06X); changes only if that program is linked "
          "at another address, not when the 8051 code moves" % (what, fo))
for at, fn in ((0x826E, "FUN_CODE_4a85"), (0x82AE, "FUN_CODE_5dcb")):
    val = int.from_bytes(B.bk[at:at + 4], "big")
    B.add(at, 4, val, {"kind": "unknown", "name": None, "off": None}, ["codeuse:%s" % fn, "no-target-in-file"], "number", region="table",
          note="value 0x%08X written to LEON register 0x9F02000C (0x826E) or 0x9F12000C (0x82AE); no part of the firmware file is loaded "
               "or run at that address, so it refers to nothing that can move (its meaning is not known)" % val)
# 3. ?C_INITSEG values that are pointers by the source type
B.add(0x71C3, 3, 0x01B250, {"kind": "ram", "name": "XDATA 0xB250", "off": None}, ["keil-initseg", "src:unsigned char volatile * xdata DAT_EXTMEM_a76d"],
      "sure", region="initseg", fixed=True, note="initial value of the generic pointer XDATA 0xA76D: type 01 = XDATA 0xB250 (outside the RAM "
      "0xA000..0xAFFF the start-up clears: a hardware register); does not move")
B.add(0x7166, 3, 0x000000, {"kind": "ram", "name": "NULL", "off": None}, ["keil-initseg", "src:unsigned char volatile * xdata DAT_EXTMEM_a6c1"],
      "number", region="initseg", note="generic pointer XDATA 0xA6C1 initialised to NULL (00 00 00): no target")
# 4. CODE 0xDD2F..0xDD41 is the unused routine FUN_CODE_dd2f (in the function table; its text address 0xB55A is found
#    by the code rules like every other).
