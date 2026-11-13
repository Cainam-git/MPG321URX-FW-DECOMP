#!/usr/bin/env python3
"""Give every reference into a mergeable literal section of an ELF32 big-endian object its own symbol.
The original link merged the 8-byte constants and texts of all objects into shared pools, so the entries of one
object's .rodata.cst8 / .rodata.str1.8 are not next to each other in the firmware. A relocation 'section + addend'
is rewritten to 'LIT.<tag>.<section>.<addend> + 0' (new undefined global symbols), so each entry can be bound to
the place where the firmware keeps it. Importable: split(src, dst, tag, sections) -> list of new symbol names."""
import struct
def split(src, dst, tag, sections):
    b = bytearray(open(src, "rb").read())
    assert b[:4] == b"\x7fELF" and b[4] == 1 and b[5] == 2
    shoff, = struct.unpack(">I", b[0x20:0x24]); shentsize, shnum, shstrndx = struct.unpack(">HHH", b[0x2E:0x34])
    sh = [list(struct.unpack(">10I", b[shoff + i * shentsize:shoff + i * shentsize + 40])) for i in range(shnum)]
    def name(strtab_off, o): e = b.index(b"\0", strtab_off + o); return b[strtab_off + o:e].decode()
    names = [name(sh[shstrndx][4], s[0]) for s in sh]
    symi = next(i for i, s in enumerate(sh) if s[1] == 2); stri = sh[symi][6]
    symtab = bytearray(b[sh[symi][4]:sh[symi][4] + sh[symi][5]]); strtab = bytearray(b[sh[stri][4]:sh[stri][4] + sh[stri][5]])
    nsym = len(symtab) // 16
    secsym = {}                       # symbol index -> section name, for section symbols of the wanted sections
    new = {}; moved = []
    for i in range(nsym):
        st_name, st_value, st_size, st_info, st_other, st_shndx = struct.unpack(">IIIBBH", symtab[i * 16:i * 16 + 16])
        if not (0 < st_shndx < shnum and names[st_shndx] in sections): continue
        if st_info & 0xF == 3: secsym[i] = names[st_shndx]; continue
        # an object the file defines in such a section: it becomes an undefined reference, bound at link time to the
        # place where the firmware keeps it (a local name gets a unique global name)
        nm = name(sh[stri][4], st_name)
        if st_info >> 4 == 0:
            nm = f"LIT.{tag}.{nm}"; st_name = len(strtab); strtab += nm.encode() + b"\0"
        symtab[i * 16:i * 16 + 16] = struct.pack(">IIIBBH", st_name, 0, 0, 0x10 | (st_info & 0xF and 0), 0, 0); moved.append(nm)
    for i, s in enumerate(sh):
        if s[1] != 4: continue        # SHT_RELA
        for k in range(s[5] // 12):
            o = s[4] + k * 12; r_off, r_info, r_add = struct.unpack(">IIi", b[o:o + 12])
            si = r_info >> 8
            if si in secsym:
                nm = f"LIT.{tag}{secsym[si]}.{r_add:x}"
                if nm not in new:
                    new[nm] = nsym + len(new)
                    symtab += struct.pack(">IIIBBH", len(strtab), 0, 0, 0x10, 0, 0); strtab += nm.encode() + b"\0"
                b[o:o + 12] = struct.pack(">IIi", r_off, (new[nm] << 8) | (r_info & 0xFF), 0)
    # locals must come first in an ELF symbol table: move the symbols turned global behind the locals by raising
    # nothing here; instead mark the whole table as having no leading locals beyond the first global we created
    first_global = min([i for i in range(len(symtab) // 16) if struct.unpack(">IIIBBH", symtab[i * 16:i * 16 + 16])[3] >> 4] or [sh[symi][7]])
    sh[symi][7] = min(sh[symi][7], first_global)
    for idx, data in ((symi, symtab), (stri, strtab)):
        while len(b) % 4: b.append(0)
        sh[idx][4] = len(b); sh[idx][5] = len(data); b += data
        b[shoff + idx * shentsize:shoff + idx * shentsize + 40] = struct.pack(">10I", *sh[idx])
    open(dst, "wb").write(b)
    return sorted(new) + sorted(moved)
if __name__ == "__main__":
    import sys
    print(split(sys.argv[1], sys.argv[2], sys.argv[3], set(sys.argv[4:])))
