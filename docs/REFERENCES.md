# Stored addresses

A list of every place in the firmware file that holds the address of code or data, and how the list was made.

The firmware stores addresses outside its instructions: tables of function addresses, tables that point at menu
texts, jump tables, start-up records. If code or data moves (a function grows, a table is extended), each of these
stored addresses has to change with it. A stored address that is missed leads the processor to the wrong place; an
ordinary number that is wrongly treated as an address gets corrupted. So the list has to be complete, and every
entry needs evidence.

Addresses inside instructions are not in this list. Most of them come from symbols in the source (`FUN_…`,
`DAT_…`) and follow when the code is linked. Two kinds do not, and have lists of their own: addresses that the
source writes as plain numbers, and names that carry an address instead of naming a function (see
[below](#addresses-written-as-numbers-in-the-source)).

## The lists

| File | Contents |
|---|---|
| `symbols/leon2m.refs.json` | Main processor: 17,765 stored addresses. |
| `symbols/leon2s.refs.json` | Input processor: 1,333 stored addresses. |
| `symbols/8051_bank0.refs.json`, `…bank1…`, `…bank2…` | Helper processor: 95, 506 and 174 stored addresses, including the partition table of the boot loader. |
| `symbols/<section>.refs-manual.json` | The entries and ranges that no rule settled and were decided by hand, each with its reason (36 rulings in the main processor, none in the input processor). |
| `symbols/leon2m.srcaddr.json`, `symbols/leon2s.srcaddr.json` | Addresses that the C and assembly source write as plain numbers instead of symbols (89 and 57 places; in the main processor these are RAM and start-up code addresses and one code-window address, see [linked build](LINKING.md#addresses-in-the-source)). |
| `symbols/leon2m.aliases.json`, `symbols/leon2s.aliases.json` | Names in the C source that carry an address instead of naming a function (76 and 109 names), each with the function it stands for. |

Each entry gives the file offset of the stored value, its width in bytes, the value, the file offset and kind of
what it points at, and the names of the rules that prove it. In the 8051 lists an address that the code builds from
several instruction operands is one entry with a `split` field, and `"fixed": true` marks addresses of hardware
registers or of another processor's memory, which do not move with the 8051 code.

The Tensilica program needs no list: its assembly source in `src/tensilica/` already writes every address as a
label (see its [README](../src/tensilica/README.md)).

## How the LEON lists were made

`tools/refs/scan.py` collects the candidates: every 4-byte word outside the function bodies whose value lies in an
address range of that processor (program, start values, RAM, start-up code). Most candidates are not addresses: a
font picture or a table of numbers contains many values that happen to fall into such a range. For the main
processor there are 28,185 candidates, of which 17,765 are addresses, 10,412 are plain numbers and 8 could not be
decided (see [Limits](#limits)).

`tools/refs/classify.py` then settles each candidate by evidence. Rule RV is the version comparison:
`tools/refs/vmap.py` maps every position of FW.021 to the same position in FW.020, FW.016 and FW.012, and between
versions code and data moved.

- A stored word that changed by exactly the distance its target moved is an address. This verdict is decisive.
- A word that is unchanged although its target moved is a plain number. This verdict only counts inside a long
  identical block and not for evenly spaced tables, where a table can look identical to itself at a shifted
  position.

The other rules:

| Rule | Evidence | Verdict |
|---|---|---|
| R1 | The word is part of a jump table of a matched function. The function's exact check proves every entry. | address |
| R6 | At least 8 consecutive words that all point into one function (jump tables stored in front of their function). | address |
| R2, R2b | At least 8 consecutive words that each point at a menu text (a length byte, the text, zero padding). | address |
| R3, R3s | At least 3 consecutive words, or 4 words at one constant spacing, that are exact function starts. | address |
| R10 | A word in the start values whose value is its own load address or within 16 bytes of it (list heads that point at themselves). | address |
| R11, R12 | Input processor only, where addresses are full 32-bit patterns: the value points exactly at the start of a text of at least two characters outside the function bodies, or is exactly a function start. | address |
| R4, R4b | The word lies in a menu font table or in a picture or logo byte stream. The code that reads these uses the words as pixel rows and sends the streams byte by byte to the display hardware. | number |
| R5 | The word lies in an EDID block, a standard format without addresses. | number |
| R9 | The value points into a function body but is not a multiple of 4. | number |
| R14 | The word lies in an object that every declaration in the matched source reads as bytes or halfwords, and that the source only uses by index (never passes on or takes the address of). | number |
| M | Decided by hand from the code that uses the object; the reason is in `symbols/<section>.refs-manual.json`. A ruling can cover one word or a range (for example the two start-up command scripts, which are read byte by byte). | either |

Where a rule and the version comparison disagree, the entry is reported as a conflict; the final lists have none.

### Cross-checks

- Every word outside the function bodies that the version map identifies as a moved address is in the list as an
  address, in all three older versions.
- Every word of every jump-table entry of the function tables is in the list as an address.
- The words that changed between versions and are not in the list are real changes of content (the build date
  text, a format string, table values).

## How the 8051 lists were made

The 8051 part is byte-identical in all four firmware versions, so there is no version comparison. The scripts in
`tools/refs/8051/` disassemble every function and apply these rules:

| Rule | What is recognised |
|---|---|
| C1 | `MOV DPTR,#v` whose value is then used to read from code memory or as a jump base. |
| C2 | `MOV DPTR,#v` with another use, when the source names `v` as a code address. |
| C3 | A Keil generic pointer loaded into R3:R2:R1 with memory type 0xFF (code). |
| C4 | A register pair loaded with a value that the source names as a code address. |
| C5 | A code address built in DPH/DPL from separate immediates. |
| C6 | The inline tables behind calls to Keil's `?C?CCASE` switch function. |
| C7 | Jump tables reached with `JMP @A+DPTR`. |
| D | Data regions: the interrupt and reset vectors, Keil's `?C_INITSEG` initialisation records, the partition table at file offset 0x6000 (flash address and length of each part of the firmware), and tables of pointers in code memory. |

Keil places data inside code in three ways (switch tables, 4 constant bytes behind calls to its store-long-constant
functions, and a bit table in each start-up function); the disassembly skips all three. Every code address that a
source file names has an entry, and every jump table has exactly as many entries as the range check in front of it
allows.

## Addresses written as numbers in the source

`tools/refs/srclit.py` and `tools/refs/srcclass.py` list the numbers in the source of the two LEON sections that
are really addresses:

- In the C files: values cast to a pointer and values passed in an argument position that takes an address (a
  format text, a table, a callback). Bit masks, limits and arithmetic constants in the same value range are counted
  as plain numbers.
- In the hand-written assembly files: the high parts of addresses (`sethi %hi(…)` operands in the processor's own
  memory range), for example the jumps of the trap table into the start-up code.

Before code or data can move, each of them has to become a symbol or be shown to stay where it is; the
[linked build](LINKING.md) says which stay numbers.

`tools/refs/aliases.py` lists the names of the form `func_0x<address>`. The checking tools turn such a name into
the number written in it, so it does not follow the function it means. The address in such a name was computed
from the listing address of the calling function:

- The main program of the main processor is listed 0xA0060000 above the address it runs at, so `func_0x4008…` in a
  main-program file is a start-up function at 0xA002… (`FUN_a002…`), not a second address of the start-up code:
  `func_0x4008d1a0` is the start-up function at 0xA002D1A0 (`timer_sleep_ticks` (`FUN_a002d1a0`)). Used as a value
  (a stored function address) the name is the run address itself.
- In the input processor these names are the calls between the first and the third program part (`func_0xa0f…` is
  0xF10000 above the function it means, see the [firmware map](MAP.md#address-numbering)).

Every one of the 185 names resolves to a function start. The [linked build](LINKING.md) replaces each name by the
function it means.

## Code outside the function table

The function tables came from the decompiler, which only lists code that something calls or jumps to.
`tools/refs/gapfn.py` examines the space between the listed functions of the LEON sections. It found:

- small functions that nothing calls directly: 95 in the main processor and 4 in the input processor. Almost all of
  them only load a few values and pass control to another function; most are unused, a few are reached through a
  stored address. They were added to the function tables and given source like every other function;
- the `nop` that the compiler places behind a tail call or a final call, at the end of 223 listed functions. Those
  functions were extended by that word;
- one unused function in 8051 bank 1 (`FUN_CODE_dd2f`).

A scan of every region outside the listed functions for instruction patterns (function entry, return, tail call)
finds nothing else in the two LEON sections apart from the hand-written start-up assembly.

## Regenerating

```
python3 -I tools/refs/vmap.py --build              # version maps, written to work/refs/
python3 -I tools/refs/scan.py leon2m --write       # candidates (also leon2s)
python3 -I tools/refs/classify.py leon2m --export  # settles them and writes symbols/leon2m.refs.json
python3 -I tools/refs/8051/scan.py 1               # 8051 bank 1 (also 0 and 2)
python3 -I tools/refs/8051/refs.py 1 --export
python3 -I tools/refs/srclit.py leon2m             # address numbers in the source
python3 -I tools/refs/srcclass.py leon2m --export
python3 -I tools/refs/aliases.py leon2m --export   # names that carry an address
python3 -I tools/refs/gapfn.py leon2m              # code between the listed functions
```

`classify.py` refuses to export while an entry is unsettled.

## Limits

- Eight words in the default-settings data of the main processor's data image could not be decided
  (`"undecided"` in `symbols/leon2m.refs.json`). Their values would point into the EDID area or the first bytes of
  the code window, which sit at the same place in all four firmware versions, so the version comparison says
  nothing, and the objects they lie in are handed on to other code. They are treated as plain numbers; a build
  that moves the EDID area has to settle them first.
- The 8051 lists recognise the address-forming patterns listed above. An address formed in another way and not
  named in the source would be missed.
- Two values in 8051 bank 1 (0x50000000, written to control registers of the two LEON processors) are counted as
  plain numbers because no part of the firmware is loaded or run at that address; what they mean is not known.
- A table of flash vendor names in 8051 bank 2 (0xCB5F-0xCB8B) has no reference anywhere.
- The length field of the main processor's code window in the partition table (file offset 0x6024) is listed like
  the other partition fields, although no 8051 code reads it.
