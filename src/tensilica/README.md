# Tensilica program: assembly source

This folder holds the source of the program for the chip's Tensilica Xtensa core: flash bank 3 of
`firmware/MSI_MPG321URX_V021_7F69.bin`, file offset 0x30000-0x3D8DB (0xD8DC bytes), which runs at address
0x40000000. Built with the free GNU assembler, the source gives the same 55,516 bytes as the firmware.

Its messages describe local dimming of an LED backlight; this OLED monitor has no backlight (see the
[firmware map](../../docs/MAP.md#what-it-does)).

## Why assembly

The program was written in C and compiled without optimisation, but the C compiler that built it is not available
to this project. The free GNU binutils for Xtensa can assemble every instruction the program uses, so the program
is kept as assembly source. That source is complete: the program can be changed and rebuilt from it, and labels
and data addresses follow when code moves (see [Changing the source](#changing-the-source)).

## Building and checking

```
python3 -I tools/xtensa_check.py
```

This builds `tensilica.S` and compares the result with the firmware. It prints each differing byte with its address
and the symbol it belongs to, and exits with status 0 only when the build is byte-identical. `--out FILE` also
writes the built program to a file.

The toolchain is Espressif's `xtensa-esp32-elf` GCC 8.4 release esp-2020r3 (binutils 2.31.1), unpacked into
`toolchains/xtensa-esp32-elf/` (see `docs/TOOLCHAINS.md`). The check runs these commands:

```
as --no-transform -I src/tensilica -o tensilica.o src/tensilica/tensilica.S
ld -Ttext=0x40000000 --no-relax -e 0x40000000 -o tensilica.elf tensilica.o
objcopy -O binary -j .text tensilica.elf tensilica.bin
```

- `-I src/tensilica` is needed because `tensilica.S` includes the other files by name.
- `--no-transform` (and `.begin no-transform` in `tensilica.S`) makes the assembler keep every instruction exactly
  as written: it does not widen or narrow instructions, add alignment or move literals.
- `--no-relax` stops the linker from shortening calls.
- No linker script is needed: the whole program is one `.text` section linked at 0x40000000.

## Files

`tensilica.S` includes the other files in address order. Together they form one assembly unit, so every label is
visible in every file.

| File | Address range | Contents |
|---|---|---|
| `vectors.S` | 0x40000000-0x400003FF | Vector slots, each placed with `.org`, and the handler `fn_40000010` |
| `reset.S` | 0x40000400-0x400007FF | Reset code with its own literal words, then zero bytes up to 0x40000800 |
| `fn_XXXXXXXX.S` | 0x40000800-0x4000AC37 | One file per function (300 files) |
| `section_table.S` | 0x4000AC38-0x4000ACF7 | Table of the regions that the reset code copies to RAM |
| `rodata.S` | 0x4000ACF8-0x4000C767 | Read-only data, copied to RAM 0x3FFE0000: text, jump tables, other tables |
| `literals.S` | 0x4000C768-0x4000D083 | Literal words read by `l32r`, copied to RAM 0x3FFE1A70; then 4 zero bytes |
| `data.S` | 0x4000D088-0x4000D8DB | Initialised data, copied to RAM 0x3FFE2390 |

Every function file starts with a header comment that lists:

- the function's address range and firmware file offsets, and its number of instructions;
- where it is called from, or which data words hold its address;
- the functions it calls and the number of indirect calls;
- the text it loads, the other addresses and values it loads with `l32r`, and the special registers it reads or
  writes.

Every instruction line ends with a comment giving its address. An `l32r` line also shows the value of the literal
word, and the text when that value is the address of a string.

## Names

| Name | Meaning |
|---|---|
| `fn_XXXXXXXX` | Function or handler at address 0xXXXXXXXX |
| `.LXXXXXXXX` | Branch, jump or loop target, or an address held in a jump table |
| `vec_XXXXXXXX`, `vec_base` | Vector slot; `vec_base` is 0x40000000, the value the reset code writes to VECBASE |
| `reset_40000400` | Reset code |
| `lit_4000XXXX` | Literal word inside the code (vector area and reset code) |
| `lit_3ffeXXXX` | Literal word of the program code, named by its RAM address |
| `ro_3ffeXXXX`, `data_3ffeXXXX` | Read-only data and initialised data, named by their RAM addresses |
| `rodata_start`, `literals_start`, `data_start`, `..._end`, `image_end` | Region boundaries in flash |
| `RODATA_RAM`, `LITERALS_RAM`, `DATA_RAM` | RAM start addresses of the copied regions (`tensilica.S`) |

The code uses the RAM copies of the data regions. A name such as `ro_3ffe0064` is therefore defined in `rodata.S` as
`. - rodata_start + RODATA_RAM`: the address of the RAM copy of the byte that follows the definition. Addresses of
RAM outside the three copies (variables without initial values, the stack and hardware registers) are written as
plain numbers.

The functions have no other names yet. Names taken from the strings a function prints can be added later.

## How the code and the data were told apart

- The code was decoded by following the program flow. Decoding started from the reset code, the vector slots, the
  two handler addresses that the reset code writes to EXCSAVE3 and EXCSAVE5, the six entries of the exception-cause
  table (`ro_3ffe19fc`, read by the user exception vector), and every word in the data regions whose value is an
  address in the code. From there it followed every call, branch, jump and loop target.
- Functions start on a 4-byte boundary, and the gaps between them are zero bytes. 58 functions with an `entry`
  instruction are not called from anywhere and their address is not stored in any 4-byte aligned word. They were
  decoded from their `entry` instruction.
- 11 instructions come directly after an unconditional jump or return and no branch leads to them (in
  `fn_40001b08`, `fn_40005de8`, `fn_4000a3cc` and `fn_4000a458`). They were decoded from the byte after the jump or
  return. In `fn_4000a458`, eight of them start at 0x4000a4a4, where the `retw.n` at 0x4000a4a2 returns to: it
  computes `a0 = a12 + 0x80000007`, and `a12` holds the return address 0xC000A49D written by the `call12` at
  0x4000a49a.
- After this, every byte from 0x40000000 to 0x4000AC37 is an instruction, a literal word read by `l32r`, or a zero
  byte.

The level-3 handler `fn_4000a680` runs straight on (without a jump) into an `entry` instruction at 0x4000a6a4. Since
nothing calls that address, it is part of the same file.

## Assembler configuration

The free binutils are built for the ESP32's Xtensa core configuration, not for the configuration of this chip's
core. Besides the base instructions, the program uses windowed-register, loop, MAC16 (ACCLO/ACCHI), TLB and
interrupt instructions. The ESP32 configuration has all of them, and every instruction in the source assembles back
to its original bytes. But a few configuration-specific details come from the ESP32 configuration:

- `read_impwire` (in `fn_40008c38` and `fn_40008c58`) is the name that the ESP32 configuration gives to this
  encoding. On this chip, the same encoding may stand for a different instruction.
- The names of the vector slots after the six window vectors (level-2 to level-5 interrupts, debug, NMI, kernel,
  user and double exception) follow the usual Xtensa LX layout. Where the instructions in a slot show what it is
  (EXCSAVE3, EXCSAVE5, `rfi 7`, EXCCAUSE), its header says so.

## Changing the source

Only the instructions and data are fixed; the addresses are not. For example, if a function grows, the functions
and data after it move, and calls, `l32r` operands, jump tables, the section table and the RAM names all follow.
`.org` keeps the vector slots and the start of the program code (0x40000800) at fixed places. A changed program no
longer matches the firmware, so `tools/xtensa_check.py` reports differences, but the build itself still works.

## Regenerating

`tools/xtensa_gen.py` generated these files from the firmware. They are the master copy now: edit them directly.
Running the generator again overwrites every file except this README, so only do that for a deliberate change to
the generator's layout rules, and check the result with `tools/xtensa_check.py`.
