# Matching tricks

Everything learned while matching this firmware, organised by what you see when a function does not match yet.
The LEON code was built with GCC 3.4.4 (Gaisler BCC 1.0.52), the 8051 code with Keil C51. Getting identical bytes is
mostly a matter of giving the compiler the same *shape* of source the original had.

Some techniques are *no-code aids*: statements that generate no instructions but steer the compiler. They are
allowed when the function's comment documents them. Inline assembly, fake `volatile` on ordinary memory and invented
symbol names are not allowed.

## First 15 minutes on a SPARC function

Run every step, in this order, before blind variants or permutation searches. Most functions written by this team
matched once a sibling's way of writing the same thing was copied.

1. **Read what is known.** The function's claim note and its best draft: which instructions still differ, and where.
2. **Find the siblings.** Matched functions that use the same globals, register addresses, constants or callees
   (`grep -l DAT_a8079538 src/leon2s/*.c src/leon2m/*.c`), and the matched functions at neighbouring addresses (same
   source file, same flags, same habits). Read their `Source form` header lines; `grep -h -A3 'Source form'
   src/<cpu>/*.c` lists them all. A function with the same instruction shape is found by `tools/sibling.py`.
3. **Copy the siblings' idioms at the differing spot:** variable types, in-place updates, reused counters and
   temporaries, declaration initialisers, if/else polarity, statement order, helper functions (see "LEON levers
   by symptom" below).
4. **Trace types through the call chain.** Callers and callees in `src/` give the parameter and return types, and
   also qualifiers: a buffer that a matched caller declares `volatile` is `volatile` here too (FUN_a0086154 gets its
   output buffer from FUN_a00883d0 through FUN_a0086400 and FUN_a00862e4). A caller passing `&rec[port] + 0x18` means
   a nested struct member at +0x18 (H_Total).
5. **Flags.** Try `-msoft-float` on top of the neighbours' flags (it changes loop-invariant hoisting in integer code)
   and check whether the firmware has the `-g` nop after a final call (`tools/show.py` tries every recorded set).
6. **Records.** Named members instead of an array of words when the firmware orders the stores freely
   (FUN_a0096204); an array when it does not; one struct for one record (not separate symbols per field).
7. **One local per firmware register.** Two registers for one source value mean two variables (FUN_a00dae90,
   FUN_a0079b84); one register for two values means one reused variable (FUN_a00dd398, FUN_a0061608, FUN_a00ca130).
8. **Declaration initialisers.** `T x = 0;` in the declaration list and the same value assigned again in an arm give
   the firmware's register copies of another variable's zero (FUN_a006cc24, FUN_a008743c, FUN_a00c2488).
9. **A chain scheduled too early (above a branch):** compute the value inside the arm that uses it. The first
   scheduler moves instructions into an earlier block only when their block is reached at least 40 % of the times
   the earlier block is (FUN_a00614b8).
10. **A mask or extension the firmware keeps and yours drops (or the reverse):** the width of the locals decides it.
    Try an `unsigned char` local, then an `unsigned short` for the shifted value (FUN_a00d7cd0); define the value in
    the loop's test block (FUN_a008d490); pass it through an inline helper parameter of the narrow type.
11. **Operand order of a sum or an `or`:** write the terms in the firmware's order, put one term in its own local
    first (FUN_a00a4ec4), write a product as a shift (`row + (j * 3 << 4)`, FUN_a00d7cd0), keep a constant behind
    a local (FUN_a013aae4, FUN_a00ab5f0), or use an assignment expression to stop reassociation (FUN_a00ee1e8). At
    `-Os` the source operand order of `a + b` and `v | (s << 16)` survives into the code.
12. **Three spellings of a choice:** `if (c) x = a; else x = b;`, `x = b; if (c) x = a;` and `x = c ? a : b;` compile
    differently; try all three (FUN_a00ab0e0, FUN_a012add8, DRV_HDMI_EQScan_FSM_PHY_R_Turning).
13. **Loop shapes:** separate loop variables or one shared counter, `while (cond)` versus `for (;;) { if (!cond)
    break; }`, `for (; i < n; i++)` continuing an earlier counter, the counter's type (FUN_a006c788, FUN_a0126dcc,
    FUN_a0062bac).
14. **Standard reference code.** Code that implements a published algorithm (VESA DSC rate control, HDR10+ tone
    mapping, CRCs) follows the reference implementation's tables, names and loop structure: look it up and copy the
    shape.
15. **Then search.** `tools/permuter2.py` with a budget of a few minutes on the draft that already has the idioms;
    rewrite what it finds into natural C and check again. Reject results that change the meaning, store a variable
    to itself, truncate a value or read one unset.

Two checks before an accept: a switch with a jump table must give the firmware's table entries, not only its code
bytes (the case-to-arm mapping); and the judge hides the values of `sethi` high parts, so compare the immediates of
both builds when a draft uses constant tables or addresses.

## Before you start

- **Use the real prototypes.** Declare every callee with its true parameter and return types, taken from its own
  matched source in `src/` or from its assembly. A byte getter declared as `int` costs instructions. A callee that
  ends in a plain `restore` and reuses `%i0` returns `void`.
  - Exception: when the firmware zero-extends a call result where it is *used* rather than right after the call,
    the original prototype returned `int`. Keep it `int`.
- **Check the argument count of every call.** Compare it with the callee's other call sites and with how the callee
  uses `%i1`, `%i2` and so on. Ghidra often drops arguments, and one missing argument can move registers far away from
  the call.
- **Read the format string of every print call.** The number of `%` fields tells you how many arguments the call
  really has.
- **Copy strings exactly** from the firmware, including trailing spaces, `\r\n` and colour codes. Function-name strings
  used in trace calls are separate read-only objects: write `static const char fn_[] = "<name>";` above the function
  and pass `fn_`.
- **Fix the function table first.** When Ghidra glued two routines together, split off a return tail, or ended a
  function at inline data, correct `symbols/<section>.functions.json` before judging (`tools/splits.py`,
  `tools/mergetails.py`).
- **Look for inlined helpers.** A standalone firmware function without callers that matches a block of the function
  you are working on is a static helper that GCC inlined. Write it as a `static` function and call it.
- **A test repeated before every small block** (for example the same three-way port test four times) means small
  helper functions defined in the same file that GCC inlined at `-O3`. Define the helpers in your file and call them;
  each inlined copy repeats the test.
- **Try every optimisation level.** Each LEON file was compiled with its own flags: mostly `-O2 -g`, often `-O3`, with
  or without `-g` and `-msoft-float`, sometimes `-Os -g` or no optimisation at all. The flags of every matched
  function are recorded in `symbols/<section>.json`.
- **Run `tools/show.py` early** on a large `-O3` draft: it tries every recorded flag set. `-msoft-float` changes
  loop-invariant hoisting even in integer-only code, so a constant or table address hoisted in your build but
  reloaded in the loop by the firmware (or the reverse) points to it (FUN_a0114650, FUN_a00ad970, FUN_a00aee44,
  leon2s DRV_HDMI21_RXDetect_FSM_LTS_3).
- **Ghidra lists leftover `%i1`-`%i3` as tail-call arguments.** The callee's own register reads give the real
  parameter count; a delay-slot `mov k,%o0` before a tail call is usually that call's argument.

## Reading Ghidra's output

| Ghidra shows | The original was |
|---|---|
| The low byte or halfword of a larger global | An `unsigned char` or `unsigned short` declared at exactly that address. |
| A global at an address ending in 000, 400, 800 or C00 | A hardware register: `#define REG (*(volatile unsigned int *)0xcf......)`. An `extern` gives `ld [%g1+0]` instead of `ld [%g1]`. |
| `f(x); ... x = x & 0xff;` | `x = f(x) & 0xff;` (a lost return value). |
| `f(p); g(p);` where `%o0` of the first call reaches `%o1` of the second | `g(p, f(p) & 0xff);`. |
| `return CONCAT44(junk, v)` | A function that returns `v`, or nothing. |
| Extra trailing parameters | Leftover registers; remove them. |
| `*(byte *)(p + i)` or `*(T *)(i + 0xADDR)` | A plain array: `p[i]`, `TABLE[i]`. |
| `(x & 0xffff)` on a parameter | `(unsigned short)x`. |
| `addx %g0, 0` after `cmp %g0, x` (and the reverse for `subx %g0, -1`) | `x != 0` and `x == 0`. Ghidra often shows them the wrong way round. |
| An empty counting loop | A delay loop: `for (i = 0; i < N; i++) __asm__("nop");`, the one allowed assembly statement. |
| A `void` function ending in `restore %g0, 0, %o0` | A function returning `int` 0. |
| A `sethi` in the delay slot of an annulled conditional branch | It only runs when the branch is taken; on the other path the register keeps its old value. |
| Small ranges tested with identical-looking bodies (5..7, 8..10, else) | A `switch` with grouped `case` labels. |
| A compare chain without a jump table | An if/else chain on ranges, not a `switch`. |

## GCC 3.4.4: wrong or extra instructions

| What you see | What to write |
|---|---|
| The table address is set up before the index multiply | Load the table into a pointer first: `struct X *t = DAT_x; struct X *r = t + idx;`. `&DAT_x[idx]` puts the multiply first. |
| A whole word is cleared on the stack, then bytes are stored into it | An initialised 4-byte buffer: `unsigned char buf[4] = {a, b};`. |
| A global's address is loaded once into an `%l` register and used throughout | A pointer to the global declared at the top of the function. |
| A struct copied word by word instead of a call to `memcpy` | The struct needs 4-byte alignment (an `int` member). `ldd`/`std` pairs need 8-byte alignment. |
| Locals kept on the stack even at `-O3` | They are fields of a local struct; GCC 3.4 does not split structs. |
| Two separate read-modify-writes on one register | Two statements: clear the bits, then set the bits. |
| A constant built with `sethi` + `add` instead of `or` | It was computed from a variable, e.g. `(one << 12) + one`. |
| A call result truncated right after the call | The callee returns `unsigned short` and the variable is `int` or `unsigned int`. |
| `sll`/`srl 16` of a value, versus `sll`/`sra 16` | `unsigned short` versus `signed short`. |
| An extra `nop` after the final call that the firmware lacks | That file was compiled without `-g`. |
| Unoptimised code that multiplies by a constant with shifts and adds instead of `smul` | That file was compiled without `-mcpu=v8` (flags `-g` only). |
| A floating-point operation as a call (`__mulsf3`, …) | Normal `float` C, compiled with `-msoft-float`; the firmware has no FPU instructions. |
| A busy-wait that jumps to its test first, with a single `nop` as body | `while (cond) __asm__ volatile ("nop");`. |
| The same wait-then-write laid out differently in two places | One static helper, inlined twice. |
| An else-arm that reloads a register address and jumps back into shared code | The source wrote the same read-modify-writes twice, once per register. GCC merged the tails. A pointer picked with `?:` does not match. |
| A global read twice in a row (once for a test, again for the update), or loads kept out of call delay slots | The variable or pointer is `volatile` in the original. Use it only when the code shows it this way, and say so in the header; `volatile` is never added just to steer code generation. |
| `and x, 0xff` right after an `ldub`, and the byte value then used in wider arithmetic | The byte was read into an `unsigned char` variable and then copied into an `unsigned int` variable. |
| A pointer table passed to a function, and the whole address of another global kept in a register across the loop | The table is an extern array symbol (`extern unsigned int DAT_00188634[];`), not a cast constant `(unsigned int *)0x188634`. |
| A structure copied halfword by halfword into a local | A plain structure assignment; the record has only 2-byte alignment (`unsigned short` members). |
| A word tested with a mask, then one of its bits cleared or set as a field (`andn`/`or` with a shifted value) | A union of a plain word and a bit-field view: test `u.w & mask`, write `u.f.bit`. |
| An extension into a temporary, then a move into the variable, after a call | The return of an inlined helper with an early return, e.g. `static u16 rd(void) { if (c) return f(a); return f(b); }`. |
| A retry decrement placed before the call gives `add` + `cmp`; after the call it gives `addcc` | Place the decrement to match. |
| Retry loops | `for (; a != read() && n < N; n++) a = read();`, with the comparison first and the counter second. |
| `and %iN, 0xff, %iN; cmp %iN, 0` and later a load `[base + %iN]` at offset 0 of a structure | The structure is an array element indexed by that parameter, used only when it is 0: `if (k == 0) { ... a[k].f ...; }`. |
| A register at a fixed address built with `sethi`/`or` into one register and then `ld`/`st [reg]` | A fixed-address volatile macro, `#define REG (*(volatile unsigned int *)0xcf011fc0)`, instead of an extern. |
| `ldsb` where the firmware has `ldub` on a local character table | Declare the local array `unsigned char`. |
| `mov -1` followed by `and 0xff` on the returned value | An `int` result variable set to -1, returned from an `unsigned char` function. |
| `and %i0, 1, %i0` in a shared exit block | `r = 0; ... r = 1; return r & 1;` (one exit for every path). |
| Several `nop`s in a loop body that are not delay slots | `__asm__("nop");` statements, one per nop. |

## GCC 3.4.4: same instructions, different registers

- **Source order of blocks.** The register-renaming pass (`-frename-registers`) works through blocks in source order
  with one "least recently used" table for the whole function. Swapping the arms of an earlier `if`, or reordering
  `case` blocks, can fix register names much further down. Climb whole blocks at a time, starting from a nearly
  ascending `case` order; single moves get stuck.
- **Statement order of independent stores.** When only registers differ, try every order of the stores.
- **Declaration order** breaks ties in register allocation. Allocation ties can even be broken by a hash of the
  symbol name, so the original identifiers can matter; a declaration such as
  `extern T name __asm__("DAT_xxxxxxxx");` keeps the firmware's link name without generating code.
- **Reuse of variables.** The original often reuses a dead variable of the same type for a later value. When
  registers are off by a swap, try that instead of a fresh variable.
- **Define a value fully inside each branch** (`if (x) a = w + k; else a = w;`) when a register that should be free
  is still considered live.
- **Conditional expressions in a `for` header.** `for (i = c ? 0 : x; i <= (c ? 2 : x); i++)` compiles the condition
  as `addx`/`btst` flag arithmetic; the same bounds in separate variables give `subx`/`orcc`.
- **A default assignment** before an if/else that sets the same field in every arm (`d.dev = 0xff;`) changes the
  block layout and registers, although it is dead code.
- **Small static helpers.** The same instructions with different register names throughout often means the original
  used small helpers (e.g. a 16-bit register write) that GCC inlined.
- **Types of values that only feed parameters:** declare them with the parameter's type, e.g. `unsigned short`.
- **An `int` return type on a function called in tail position** marks `%i0` as used, which changes register
  allocation for the whole function.
- **An `unsigned int` copy of an index** decides the operand order of a load: `[p + i]` versus `[i + p]`.
- **A separate copy** such as `unsigned int x = id;` taken before another use keeps a value live and changes which
  register a call argument prefers.
- **Bit-fields instead of masks** for flags in a byte or halfword (big-endian: the first field is the most
  significant bit).
- **Register tables** read through pointer arrays: try `volatile T *const TAB[N]`.
- **`unsigned long` versus `unsigned int`** for a 32-bit global or register pointer puts the accesses in a different
  alias set; when two access forms are mixed in one function, switching one of them to `long` changes scheduling and
  register ties (FUN_a011c4cc, DRV_HDMI_EQScan_FSM_PHY_PLL).
- **Narrowing a callee's return type** is only correct when the value really fits. Read the callee's return path first.
- **A fresh `and %i0,0xff` for one use of a byte parameter** (instead of reusing the masked register) means that use
  reads an `unsigned short` copy: `unsigned short k = port; ... (unsigned char)k`, sometimes with the parameter itself
  declared `unsigned short`. With `int` the copy merges with the parameter and the local registers shift
  (FUN_a00c2758, FUN_a010f064).
- **A byte mask re-done before each call** (`and %lN,0xff,%o0` after every call, where GCC reuses one masked value):
  give each call its own guard, e.g. `if (ch < 3) f(ch);` per call. Each join is a CSE boundary
  (DRV_HDMI_EQScan_FSM_Search_Process; also in leon2s).

## GCC 3.4.4: same instructions, different order

- **A load in a branch delay slot** usually means the source reads the value before the preceding test.
- **Write the small or early case first:** after `cmp x, 2; bgu`, the fall-through is `x <= 2`, so write that case first.
- **A pointer type changes scheduling.** Changing a register macro's type between `volatile unsigned int` and
  `volatile unsigned long` (same width) changes the alias set and can move a load across a hardware-register store.
- **CSE boundaries:** `for (;;) break;` generates no code but ends a common-subexpression region.
- **Keep two tests apart** with a flag such as `int in = a || b;`; written inline, GCC may merge them.
- **The order of terms in a sum** decides the order of register renaming and how delay slots are filled.
- **Collapse or expand arithmetic:** a value computed in two steps compiles differently from one expression per
  branch.
- **`-msoft-float` also changes loop hoisting**, even in integer code, because it reserves the floating-point
  registers. Try it when the firmware reloads a value inside a loop that yours hoists.
- **Access globals directly** through `DAT_x->field`, without caching a local pointer, unless the firmware caches it.
- **Two writes to one register** (`st`, `ld`, `or`, `st`): two statements, `REG = a; REG |= b;`; the register is
  volatile, so both writes stay.
- **Search the order of independent statements** (byte copies, store groups): a small brute-force search over all
  orders is quick.
- **One assignment serving two paths:** when the firmware sets a variable once before a test and both outcomes use
  that value, the test reads a copy taken before the assignment:
  `unsigned int t = v; v = 0; if (t != 0x8000 || ...) goto out;` (FUN_a00aec50).
- **A sub-expression computed into its own variable first** (`z = x * 10;` before an unrelated division) changes
  the creation order of instructions and so how the scheduler breaks ties (FUN_a00a4ec4).
- **`do { stmt } while (once);` with `int once = 0`** is a no-code aid (the loop compiles to nothing) that moves the
  statement's instructions relative to its neighbours; a literal `while (0)` is removed too early to have the
  effect (FUN_a00d3bb4, found by the permuter).
- **A struct copy written as `memcpy`** (GCC expands it inline) places the address computation differently from a
  plain struct assignment (FUN_a012af40).
- **A row pointer taken inside a copy loop** gives `[row + index]` operand order instead of `[index + row]`
  (FUN_a01238e8).
- **`cmp x,K; mov K+1,%o; subx %o,0,%n`** is `n = K + (x >= K)`; the `?:` and `K+1 - (x < K)` forms fold to branches
  (FUN_a00a3b68, FUN_a00b1700).
- **`(unsigned char)` casts instead of `& 0xff` / `>> 8`** on a 16-bit value change which copies GCC makes and the
  order of the byte stores.
- **Read-modify-write through inlined helpers:** nest the read inside the write call, `wr(p, r, rd(p, r) & m)`; the
  helper's parameter copy keeps the firmware's second `and 0xff`.
- **Case order of large switches:** a hill-climb over the order of the `case` blocks, judged by the score, settles
  register names and block order where a full permutation search is too big (`work/h42/climb.py` does the same for
  single statements).

## GCC 3.4.4: blocks in a different order

The basic-block reordering pass places blocks by predicted frequency. Rarely executed ("cold") blocks often have
frequency 0 to 2, so their order is decided by ties. Branch predictions are the levers, all of them no-code aids:

| Aid | Effect |
|---|---|
| `__builtin_expect(cond, 0 or 1)` | Overrides all other predictions for that branch. |
| `do continue; while (0);` in a branch | Marks the branch as a `continue` (predicted taken). |
| `goto l; l: ;` in a branch | Marks the branch as a `goto` (predicted not taken). |
| An early `return` in an inlined helper | Predicted taken, where a `goto skip` is not. |
| A provably always-true or always-false test that is folded away later, e.g. `__builtin_expect(!(u16 >> 16), 1)` | Changes predictions without changing the final code. The comment must prove the test is constant. |
| The same call duplicated in the else branch | Merges into the same code, but changes the predicted probability. |
| A long `\|\|` chain in one `else if`, versus separate arms | Flips predictions. |
| A sign test written as a signed 1-bit bit-field (`w.b31`, through a union view) or `w >> 31` instead of `w < 0` | Same `cmp 0; bl` instruction, but without GCC's negative-compare prediction; places the blocks as the firmware does (FUN_a0097508, FUN_a00aad30, FUN_a0153b20). |

**Try pairs, not only single hints.** Predictions combine non-additively, so two hints together can produce an
order that neither gives alone. `FUN_a013dc6c` only matched with a specific pair of `__builtin_expect` hints. Each one
alone made the result worse. Generate a candidate hint for every condition, keep those that change the order without
changing the code, and test all pairs.

**Switch layout:**
- With a jump table, GCC 3.4 at `-O3` emits the second-to-last `case` of the source first. If the firmware's first
  block after the jump is case X, put X second to last.
- The order of the `case` labels also decides the register names inside the cases; try every order.
- Write identical `case` bodies separately rather than sharing them; GCC merges them itself, in its own way.
- **Compare tree off by one case value** (no jump table): GCC balances the tree over the listed case values, so a
  value whose body equals the default can still change the tree shape. List it explicitly (`case 0x31:` with the
  default action); its compare disappears later and only the tree shape remains (FUN_a008ed50, FUN_a00c8c64).
- **An annulled loop increment in the delay slot of a test**, where GCC fills the slot from the fall-through:
  `__builtin_expect(cond, 0)` on that test.
- **Case blocks past the function's listed end:** the function table needs them merged in first; then the switch
  matches.

## LEON levers by symptom

Each entry: what the firmware shows, the source form that gives it, a matched function that uses it.

**House style of the authors** (leon2s and leon2m share it):

| Habit | Matched examples |
|---|---|
| `unsigned char` loop counters and flags; `unsigned short` counters in the 0xa00c.... files | FUN_a00b0e54, FUN_a00c0a88, FUN_a00cec18 |
| Defaults in the declaration list, re-set in the arms: `unsigned char cf, div, mul = 0, mul2 = 1;` then `mul = 2; mul2 = 1;` | FUN_a00dd154, FUN_a006cc24 |
| Accumulators updated in place in a narrow type: `crc <<= 1; crc \|= bit; if (crc & 0x100) crc ^= 0xd5;` | FUN_a00d9988, FUN_a00d68cc |
| A loop counter reused for the next loop or a later value | FUN_a00d68cc, FUN_a00ca130, FUN_a00c850c |
| One temporary reused across statements: `t = (w >> 8) & 0xff; h = (t << 8) + (w & 0xff); t = w >> 24; ...` | FUN_a00dd398, FUN_a00dd154 |
| Parameters masked or updated in place (`mode &= 0xff;`, `v &= m;`, `a += ...; return a;`) | FUN_a0086030, FUN_a0061540, FUN_a0062718 |
| A counter continued by a second loop: `for (i = 0; i < n; i++) ...; for (; i < 20; i++) ...;` | FUN_a0062bac |
| Ceil division as `(16 % w == 0) ? 16 / w : 16 / w + 1`, `q = a / b; if (a == q * b) return q; return q + 1;` | FUN_a00dd154, FUN_a00617f0 |
| Odd halving as `h = k / 2; off = h; if (k & 1) off = h + 1;` | FUN_a00d985c, FUN_a00da838 |
| Hardware blocks as `#define R(a) (*(volatile unsigned int *)(a))` or a base-plus-offset macro, one statement per register | FUN_a00dd154, FUN_a00b0e54 |
| Register block pointers held in records and named in every statement | VBP_tmp, FUN_a00a2b98 |
| Small `static inline` helpers for repeated steps (semaphore lock, interpolation, record updates) | FUN_a006c788, FUN_a0062bac, FUN_a00dac08 |

**Extensions, masks and constants:**

| The firmware shows | Write |
|---|---|
| The port re-masked or `port * K` recomputed in every block | An `unsigned char` parameter in the prototype, as the matched siblings declare it, or a K&R definition (DRV_HDMI_EQScan_FSM_Search_EQTable, DP_GetClrSpace, FUN_a00934c0, FUN_a0120848). |
| A 16-bit parameter extended only at its last use | An `unsigned short` parameter updated in place; one extended at entry is a wider parameter copied into an `unsigned short` local (FUN_a013a0d4). |
| An `unsigned int` parameter that loses a register it should keep | Its entry copy has a stack equivalence that halves its allocation priority; an `unsigned char` parameter makes the copy a conversion without one (FUN_a00a7718). |
| `sll 4; and 0x3f0` on an index whose range is known | An `unsigned char` local for the index and an `unsigned short` for the shifted offset: the byte's zero-extension narrows to the known bits instead of vanishing (FUN_a00d7cd0). |
| An extension kept at a call but not at the compare in the loop | The variable is set in the loop's test block (`for (id = b & 0x1f; id <= 0x17; id = c & 0x1f)`): combine only links a definition and a use in the same block (FUN_a008d490). |
| The mask of a byte at the compare, not at the load | `v = p[i]; ... if (x != (v & 0x7f))` (FUN_a00da288). |
| A read-modify-write of a byte with `mask` / `val` parameters and no extensions | `unsigned char` parameters and each store as `(unsigned char)(whole expression)` (SC_MaskSetByte). |
| A field merge with the shifted value computed inside the read-modify-write | `*p = (*p & ~m) \| ((v << lo) & m);` inside the arm that writes (FUN_a00614b8, FUN_a0061a6c). |
| `and x,0x80000000; cmp; subx` for a sign test | The masked word through a local: `w = x & 0x80000000; r = w ? 0 : 4;` (FUN_a0148868). |
| Two copies of a high byte that GCC would share | `(w & 0xff000000) >> 24` for one use and `w >> 24` for the other (FUN_a009f738, FUN_a009faf0). |
| An `and 0xff` before shifting a one-bit field | `(unsigned char)p->bit << 5` (FUN_a0137e10). |
| The same constant loaded into two registers | One of the stores goes through an `int t = 2;` local (FUN_a009811c). |
| A constant kept in an `or` or compare that fold would move or canonicalise | Keep the constant in a local: `unsigned int k = 0x61000000;` (FUN_a013aae4), `cells = 6; if (full < cells - 2)` (FUN_a00ab5f0). |
| A masked default that PRE deletes | Give the default a different expression: `int r = v; ... default: r = (unsigned char)v;` (FUN_a0100990). |
| Table bytes loaded once at the top and multiplied without masks | Read them into `unsigned int` locals at the top (FUN_a002e960). |

**Register allocation:**

| The firmware shows | Write |
|---|---|
| Register names that differ from some block on, same instructions | The renaming pass ticks registers in source block order: put the arm the firmware renames first first, e.g. `if (!(w & 0x800)) {...} else {...}` (FUN_a00b1654, FUN_a00b9750, FUN_a0150f44). |
| A jump-table switch with only register differences | The case source order decides only names: climb over case orders (FUN_a00d8100, FUN_a012d554, FUN_a00ccf34); inlined handlers take their case order from their definition order (FUN_a00d2a98). |
| A block with three block-local temporaries in unexpected registers | Local allocation with exactly three block-local pseudos takes them in creation order; a fourth local makes it sort by priority (FUN_a00c68d8, FUN_a010baf4). |
| Two values swapped between two registers | Equal truncated priorities are ordered by pseudo number, i.e. declaration order: declare in the firmware's order, in an inner block if needed (FUN_a012a774); hoisted table addresses in pointer locals declared and assigned in order (FUN_a00ea638); GCSE pseudos follow the hash of the symbol name (FUN_a00e55ec). |
| Lifetimes that differ by one test | Compute after the test: `q = v >> 3; v &= 7; if (q == 0xf) {...} w = ((q + 1) << 3) + v;` (FUN_a00ea308). |
| A value set on both paths and kept in a parameter register | The parameter variable itself is reused (`ch = f(t, c);`); a value assigned before a call lands in a call-saved register (FUN_a01213a4). |
| `mov %lN,%i0` before a block | The parameter copy of an inlined helper holding the rest of the function, `rest(unsigned char port, int sel)` (DRV_HDMI21_LTS_STS_InitialSettings). |
| A leaf allocation where the firmware has a normal frame, or the reverse | The return type: an `int` (or implicit `int`) result keeps `%i0` live (FUN_a00a8184); a `short` result variable (FUN_a0079b84). |
| Priorities that depend on how the tests nest | Nested ifs with one `return 0` at the end instead of several returns (MODEDET_handler_3). |
| Spilled locals in another stack-slot order (-O3) | `-fweb` splits a variable into webs and gives later webs new, higher pseudos, which moves their spill slots: computing a step in the variable itself instead of a separate local changes the webs (FUN_a00a31a4). |

**Scheduling and order:**

| The firmware shows | Write |
|---|---|
| Loads one at a time with one register for every upper byte | One reused temporary (FUN_a00dd398). |
| The first store of a repeated value kept in place | The value must die at that store: chained assignment `a = b = f;` (FUN_a0061f5c). |
| A chain moved above a conditional branch | Compute it inside the arm that uses it; the scheduler speculates only into blocks reached at least 40 % as often (FUN_a00614b8). A loop-free function with at most 10 blocks and 100 instructions is one scheduling region (FUN_a00aa258). |
| Call arguments moved above a compare | Nest the ifs so the call block falls through instead of ending in a jump (FUN_a00f62ac). |
| Stores in a particular order | Climb the statement order (FUN_a0151358, FUN_a00dae90). |
| Sums with the structure word as first operand, function stays leaf | Each sum in its own `int` local first (FUN_a010eca8). |
| A load or store that one alias set too few orders | Named struct members are disambiguated from each other, array elements of one member are not (FUN_a0096204); two refs to one struct type with different fields do not conflict (H_Total); an `unsigned short [][2]` pair instead of a struct makes two stores may-alias (FUN_a012043c); a flat array for a halfword pair (DRV_HDMI21_LTS_STS_InitialSettings); a bit-field byte against store motion (FUN_a00d2a98). |
| Loop-invariant addresses hoisted in a given order | Hoisting follows the body's first use; `T[i] = expr` expands T's address before expr (FUN_a012a2f0). A dead declaration initialiser of the inner index changes the order (FUN_a01138fc). |
| An invariant moved last, or kept in the loop | Hoisting threshold: `-msoft-float` lowers it, the second loop pass appends (FUN_a00df074, FUN_a00a5e68, FUN_a006c788). |
| `r = i` in a non-annulled delay slot before a test | The store sits inside the loop: `if (t[i].id == id) { r = i; break; }` (FUN_a0125198). |

**Blocks, branches and loops:**

| The firmware shows | Write |
|---|---|
| Plain calls for some values and a sibling call for the last | Separate `if (mode == k) f(..);` statements, not an else-if chain (FUN_a0148268). |
| A diamond that your build if-converts or folds into one test | Write the shared body in each arm, or a full if-chain inside each arm (FUN_a00b72cc, FUN_a00b1ba4, FUN_a00aa33c). |
| A flag test predicted not taken | Write it as an equality with 1: `((h & 0x40) >> 6) == 1` (FUN_a014be10, FUN_a014bf64). |
| A constant assignment hoisted out of two arms | Merge the conditions into one `&&` with one else (FUN_a009c09c). |
| A high part kept but the low part rebuilt per block | The arm is off the compare block's CSE path: assign in both arms (FUN_a00c2bd8), make the join a block of its own with an if/else (FUN_a00dac08), name the global directly as an index (FUN_a00d791c). |
| A test layout after jump threading | Two separate statements: `if (a) { if (b) break; } if (b) continue;` (FUN_a008d490). |
| Loop tests renamed after the body | `while (cond)` puts the condition at the loop end; `for (;;)` with a `break` keeps it first (FUN_a0126dcc). Wait loops with their own `break` instead of one `&&` (FUN_a002e2a4). |
| Two copies of a loop chosen by a flag (-O3) | One loop with the flag test inside; loop unswitching makes the copies (FUN_a00b3614, FUN_a0137344). |
| A counter running down where the source counts up | `loop.c` reverses a pure counter with a negative bound: `for (k = 1, m = -4; m < -1; m++, k++)` (FUN_a0062fc8). |
| A latch `add 8` the compiler would replace by a value from the inner test | Three loop variables, so the inner index outlives the outer step (FUN_a006c788). |
| Products before one shared division in a switch | One complete formula per case (FUN_a008c538). |
| A bit-test switch `1 << mode & 0x5500` | A switch with grouped case labels (FUN_a00934c0). |

**Prototypes, helpers and data:**

| The firmware shows | Write |
|---|---|
| A store scheduled one slot early around a ROM call | Declare the ROM routine without a parameter list, `extern void func_0x4008c4d0();` (FUN_a0139ddc). |
| Argument set-up for an unused result | Declare the callee `void` as the matched callers do (FUN_a00a6b98, targeted_system_display_maximum_luminance). |
| Extensions inside a helper | The helper's parameter types: `bitpos(unsigned short f, ...)` (FUN_a012d554); a one-exit helper with an `unsigned short` result variable (FUN_a01405d0, FUN_a0140b78); a check helper returning `unsigned char` with early returns (FUN_a0120de4). |
| An inlined block equal to a matched neighbour | Call the neighbour itself (FUN_a01199ac, FUN_a0104f48). |
| Re-stores of a table after a page write | Call the table-initialisation helper again (FUN_a00e02ec). |
| A stack table copied from ROM | An initialised `const` local array, character constants per entry (FUN_a00fccbc). |
| A table address kept whole in a register inside a helper | A constant pointer `unsigned char (*tab)[0xb0] = (...)0xa807d680;` (TxFFE_Max_L). |
| `(pn * 32 + j) + base` address order | A pointer to rows, `char (*args)[32]`, indexed `args[*pn][j]` (FUN_a00b28d0). |

**Search methods:**

- `tools/permuter2.py` keeps only the target function and `static inline` helpers; every other helper body becomes a
  call. Mark all helper bodies `static inline` in the copy you search, and check that its start score equals the
  judge's (FUN_a002f118).
- When a pass decides the difference, read that pass in the GCC 3.4.4 source (sched-rgn.c, haifa-sched.c, loop.c,
  local-alloc.c, global.c, cse.c, combine.c, reorg.c) and derive the source property from it; then search for a
  natural spelling that has the property.
- `-fno-sched-interblock`, `-fno-schedule-insns` and similar flags are diagnostics only: they show which pass
  moves an instruction, but they are not the firmware's flags.
- `sparc-elf-readelf --debug-dump=info` prints each local's frame offset (DW_OP_fbreg); named locals that stay in
  memory get their slots in declaration order, nearest `%fp` first.

## Keil C51 (8051)

| What you see | What to write |
|---|---|
| A value kept in R6 and passed as `MOV R7,R6` / `MOV R5,R7` | A type conversion in the argument, e.g. `f(0xc5, (char)x)`. |
| The first parameter copied from R7 to R6 for no reason | Widen the second parameter to `(unsigned) int` (passed in R4:R5); the original only uses its low byte. |
| `ANL A,#n` / `JNZ` instead of `JB ACC.x` in a wait | An `int`-typed test: `while ((unsigned int)(REG & n)) ;`. |
| `INC DPTR` between two XDATA accesses | Both are in one object (array, struct or union). Separate externs each get their own `MOV DPTR,#addr`. |
| Parameters written to XDATA right at the start | The LARGE memory model: plain parameters and locals, judged with `OPTIMIZE(8,SPEED) LARGE`. |
| No `RET` after a final endless loop | Built with `OPTIMIZE(8,…)`; level 7 appends a `RET`. Most bank 0 and bank 2 code needs level 8. |
| A function that returns the carry flag | Declare it as `bit f(...)` and return a normal expression; Keil generates the carry itself. |
| A 4-byte constant after `LCALL ?C?LSTKXDATA` | Inline data; Ghidra ends the function there. Fix the end before judging. |
| A 4-byte struct copy | Compiles to `?C?COPY` with R6:R7 = 4. |
| The print function `FUN_CODE_2820` with extra arguments | Declare it `extern void FUN_CODE_2820(void *fmt, ...) large;` and pass the format as `(void code *)0xNNNN`. |
| An XDATA address re-read for every access | Declare that variable `volatile`. |
| `MOV R2,#HIGH x / MOV R1,#LOW x` then `?C?COPY` from CODE | An initialised local array (`unsigned char a[2] = {0, 0};`); its initialiser bytes sit at x. |
| Shared entry code (a few instructions, then the function) in front of a callee | Keil common-entry blocks: built only when the callee and at least three call sites with that sequence are in one module file; define callees before callers. |

- **Register files.** Banks 0 and 1 were built with whole-program register optimisation. With the register files
  `symbols/8051_bank*.orc` (`tools/regfile8051.py`), C51 keeps parameters in R6/R7 across calls, as the firmware does.
- **Compiler version.** The firmware's compiler is C51 9.57: it reproduces every 8051 function, and FUN_CODE_d351
  matches only with 9.57 or older. Comparing 14 matched functions under every downloadable Keil release first put it
  at C51 9.05 to 9.57, or 9.60.7. 9.02a and 9.03 drop a `MOV DPTR` reload between consecutive XDATA stores;
  9.59 to 9.60a compile `(x & 0xf0) == 0x50` as `XRL`/`JNZ` instead of `MOV R7,A` / `CJNE R7,#50`.
- **Dead copies.** Keil 9.57 and later remove a register copy whose only reader is gone, in a late pass. Releases
  9.05 to 9.56 can leave such a reader behind as an extra instruction.
- **A dead `MOV R7,ARn` that the firmware keeps.** A comparison through a char cast, `(char)x == C`, copies the value
  into a temporary register and compares that register (`MOV R7,AR6; CJNE R7,#C`). If both outcomes of a `?:` on that
  comparison are identical and non-empty, Keil merges them after the clean-up pass, and the copy stays without a
  reader. An empty branch body is removed earlier and leaves nothing. `FUN_CODE_b456` matched this way.
- **Optimisation level and dead copies.** At `OPTIMIZE` 4 to 7, a simple dead copy such as `t = id; t = 5;` stays in
  the code; levels 8 to 11 remove it.
- **Old Keil versions under Wine** share one fixed temporary file per Wine prefix. Give every parallel job its own
  prefix.

## More patterns

LEON (GCC 3.4.4):

- **Find a matched twin first.** Compare the target's opcode sequence with every matched function of the same
  section (`difflib.SequenceMatcher` over the mnemonics). Ratios above about 0.8 are usually ports of one source with
  other registers, addresses or constants (FUN_a00a6aa0 from FUN_a00a8400, FUN_a00f1374 from FUN_a00f232c).
- **A struct pointer versus a word pointer.** When the firmware reloads a global after each store through a pointer
  parameter and your build hoists it, the parameter is a plain `unsigned int *` (`m[0]` to `m[4]`), not a struct
  pointer: GCC treats stores to struct fields as not aliasing scalar globals (FUN_a0135004).
- **A buffer copied into a global ring** keeps the firmware's load and store order only as `unsigned long w[4]`, its own
  alias set (FUN_a0136384). A data pointer kept as `unsigned int p` and cast at each use keeps per-byte stores that a
  pointer type lets GCC drop (FUN_a0136a10).
- **A constant that must not be folded** into a sum: pass it through an inline helper parameter (FUN_a0135ae8).
- **A stack buffer filled from ROM by FUN_a013c910 (memcpy) right before it is read:** the buffer is an initialised
  `const` local array (`const unsigned char t[30] = {...};`); the ROM bytes are its initialiser, and the tables of one
  function sit back to back. GCC copies the initialiser with an implicit `memcpy` call; declare
  `extern void *memcpy(void *, const void *, unsigned int) __asm__("FUN_a013c910");` (a link name only, no code).
  `const` also lets the reads be scheduled independently of volatile register stores (FUN_a0118be4, FUN_a0118e04).
- **A block placed oddly, or a set the compiler could drop but the firmware keeps:** write that block after a label
  at the place the firmware shows and reach it with `goto`. A label resets what the compiler knows about register
  values, so the set survives, and the block keeps its source position (FUN_a00cd31c, FUN_a0095e08).
- **`x = d; if (c) x = v;` and `if (c) x = v; else x = d;`** compile differently around loops and calls; try both
  (DRV_HDMI_EQScan_FSM_PHY_R_Turning).
- **One call after a switch that only sets a variable** (`switch (n) { case 0: k = 0; break; ... } f(k, v);`) appears
  in the firmware as one copy of the call per case: the block-reorder pass duplicates it (FUN_a0146298, FUN_a0149064).
- **A small stuck function that does the same thing as a block inside a matched function** often matches when that
  block's source is copied with its types unchanged, or when matched neighbours that nothing calls are pasted in and
  called (FUN_a00c0adc, FUN_a014f3d8, FUN_a0104f48). Comparing the instruction sequences of unmatched and matched
  functions, ignoring registers, finds such pairs.
- **A block guarded by `x == K` that the firmware shows with constant offsets** may still index with `x` in the
  source (a copied per-port block): constant propagation folds the offsets, but the extra `(x & 0xff)` computations
  stay visible to GCSE, which then keeps later masks and tests (FUN_a00d17a8).
- **A value GCSE should reuse but the firmware loads again:** look for a second read of it on another path into that
  block, for example the first condition of an `&&` chain reading `b[1]` directly instead of a copy (FUN_a00cef6c).
- **Per-arm `sethi` of the same high part:** each arm names the global directly, or holds its own copy of the
  statements (merged later by cross-jumping); a local pointer shared by the arms keeps one address
  (FUN_a00db054, FUN_a011d670).
- **A limit or divisor that depends on a flag** is written `i < (b8 ? 3u : 1u)` or `pre / (b8 ? 5u : 7u)`: the `?:`
  divisor stops the narrowing to `unsigned char` (`cmp 0` instead of `btst 0xff`), and the `u` suffix gives unsigned
  compares and the multiply-by-reciprocal (DRV_HDMI_EQScan_FSM_PHY_PreRVGA).
- **The same string in two source files** is one copy in the firmware: the linker merges identical strings of
  mergeable sections. Write the literal in both files; `tools/exact.py` then checks such pools per reference
  (DRV_HDMI_EQScan_FSM_PHY_PreRVGA, RCT_Value).
- **One masked copy of a value passed around:** the source has a local holding that value (`unsigned int y = k * 2 +
  6;` passed as `(unsigned char)y`) (FUN_a00b6290, FUN_a00a7e00, FUN_a01112c0).
- **A local table that is first cleared and then has every element stored:** GCC 3.4 does this for a union (or a
  struct with an uninitialised member) initialised through one member, for example
  `const union { unsigned short h[12]; unsigned int w[6]; } m = { { ... } };`. A plain array is only cleared first when
  elements are missing or at least 75 % of them are zero (FUN_a0150b8c).
- **`x >= K` as `cmp; subx`** after a loop whose own test is `cmp K-1; bleu`: the final compare uses a local holding K
  (`unsigned char n = 4; ... return i >= n;`). A literal K is folded to `x > K-1` and branches (FUN_a014f32c).
- **Five case labels whose delay slots differ** give the case order of the source; trying all orders found
  `case 2, 3, 4, 1, default` (FUN_a0121ed0). Explicit empty cases reproduce small compare trees (FUN_a01454c4).
- **Register-field writes** keep the firmware's redundant `and` with the mask after the shift only through an inlined
  helper `wr(volatile unsigned int *r, mask, shift, val) { *r = (*r & ~mask) | ((val << shift) & mask); }`
  (FUN_a00f99a0, FUN_a00fbaa4); plain C and bit fields drop it.
- **Result in an `unsigned char` local before the return** fixed a register swap and an extra `mov` (FUN_a0132dd8).
- **Inlined static copies of small neighbours** keep paying: FUN_a01234b8 is four copies of FUN_a0122dbc,
  FUN_a0104eb0 three neighbours, FUN_a00d0fa0 a checksum helper.
- **Parameters zero-extended at every use** (`and %lN, 0xff` before each use, no mask at entry, the parameter copied
  out of `%i0` with a plain `mov`): an old-style definition, `int f(port, ch) unsigned char port, ch; { ... }`. The
  arguments arrive as `int` and GCC extends them per use (RCT_Value: 85 % with `unsigned int` parameters and casts,
  99.6 % at once as a K&R definition).
- **Big functions are often built from caller-less matched neighbours.** Before writing a large function, look for
  matched routines next to it that nothing calls: they are its inlined static helpers (FUN_a00f793c).
- **The order of struct field initialisations** can decide the register allocation of a whole function:
  `r.c = 16; r.b = 0; r.a = 0;` took FUN_a00f793c from 97.5 % to 100 % register-blind.
- **Two instructions in the wrong order where a later use decides it:** an empty `for (;;) break;` between the two
  statements splits the late scheduling pass there, so they keep source order. It adds no instructions; document
  it in the header as a compiler aid (FUN_a00f6fe4, FUN_a0135ae8, FUN_a013358c).
- **Reads through a pointer parameter that must not lose stores they might overlap:** keep the address as an
  `unsigned int` copy and cast at each read; the reads then have no known memory base (FUN_a0136a10).
- **The firmware keeps a branch that your build turns into flag arithmetic (or the reverse):** a second, dead
  statement in the if-arm (`if (w & 0x80) { r -= 1; v = 0; }` with `v` not read again) emits no code but changes
  when GCC if-converts the arm (FUN_a00ada24, FSM_MODE_DETECT_STANDBY). Document it as a compiler aid.
- **A division constant hoisted out of a sampling loop:** keep the averaging inside the loop,
  `if (--n == 0) { average }`, with `n != 0 &&` in the do-while condition (FUN_a00f4e60, FUN_a00f51b4).
- **A K&R byte parameter that needs a second definition:** `p = port; ... port = p;` (FSM_MODE_DETECT_STANDBY).
- **The barrier as the very first statement** of the function fixed FUN_a0087a14, which otherwise only matched with
  a flag the firmware does not use.
- **Floating-point limits one unit above a round decimal:** the author wrote a product that the compiler folded,
  such as `602.6 * 0.1` instead of `60.26`; the folded value has the firmware's exact bits (FUN_a0120de4).
- **A `const` local table** can change the scheduling of the constant loads around it (FUN_a012e004).
- **Different spellings of the same mask in copied calls** (`p & 0xff`, `(unsigned short)p & 0xff`,
  `(unsigned char)p`): equal spellings are merged into one register, distinct ones are not (FUN_a007a9c0).
- **A test written as `flag == 1`** instead of `flag` fixed the block order of FUN_a009cd74.
- **Judge with `tools/diff.py` or `tools/exact.py`.** A raw comparison that skips address fields can report a match
  where one `sethi` names a different global.

Keil C51:

- **The value loaded before the count in a shift loop** (`MOV A,#k` or `MOV A,Rn` before `MOV R0,count`): C51 9.57
  gives this order from the plain `x = k << n;`. 9.59 and later load the count first at every optimisation level;
  that difference is how the compiler version was found (see "Compiler version" above).
- **Shift counts in large functions:** give every shift site its own count local; one local reused at several sites
  lives across the function and goes to XDATA. In LARGE loops a count stays in a register only when the call that
  uses it sits inside an `if` condition or an `if` block without `else` (FUN_CODE_5a39, FUN_CODE_a085).
- **A store to a LARGE local followed at once by a read of it** (`MOVX @DPTR,A; MOVX A,@DPTR`): the stored value came
  from a `volatile` object, typically a hardware register at 0xF0xx/0xF1xx or memory written outside the 8051 program
  (FUN_CODE_7df1, FUN_CODE_a142, FUN_CODE_42f6). Keil does not keep A equal to the local for volatile sources.
- **Two identical call sequences that Keil merges but the firmware keeps:** end the inner block with `ACC = ACC;`.
  It emits no code and keeps the block from being folded until after jump layout; document it as a compiler aid
  (FUN_CODE_a8a3; also the `Jcc +2; SJMP` shape in FUN_CODE_960f and FUN_CODE_8512).
- **A local loop guard after `ACC = 1;`:** `if (ACC == 1) f(...);` emits no test (Keil knows A) but keeps the shift
  count locals of the call in registers (FUN_CODE_b881).
- **A conditional expression with two identical arms** (`t == t ? t >> c : t >> c`, `n == K ? f() : f()`,
  `m = m == m ? m : m;`) emits no code, but changes which variables Keil keeps in registers and the order of loads and
  register copies (FUN_CODE_9975). Document it in the header as a no-code aid.
- **A 16-bit value loaded into R2:R3 instead of R4:R5:** convert through `unsigned long` and back,
  `(unsigned int)(unsigned long)n >> 8` (FUN_CODE_6f26).
- **Low byte first:** `(x & 0xffffff00) | ((unsigned long)r & 0xff)` evaluates the low-byte value first
  (FUN_CODE_c103). A repeated index expression instead of a local copy avoids an extra `MOV R7,AR5` (FUN_CODE_42f6).
- **A call and return, or `Jcc +2; SJMP`, at the end of both arms** of an if/else: write the shared statement in both
  arms (FUN_CODE_8622, FUN_CODE_db96, FUN_CODE_dbaf, FUN_CODE_18ab).
- **`& 0xff` on a char operand** changes which operand is loaded first and stops the merging of a repeated array read
  (FUN_CODE_dae3).
- **An `unsigned int` read-modify-write** keeps the compiler's temporary out of R7 (FUN_CODE_a41f).
- **A 4-byte constant after `LCALL ?C?LSTKXDATA`** often looks like `LCALL` or `AJMP` to a non-function address;
  check such callers before adding a function-table entry (0x5F3C, 0xDAC4).

## Diagnosis

- **Two judges.** `tools/check/jf.py` scores the match and checks exact bytes. `tools/check/rawcmp.py` compares the raw
  words independently. A function only counts when both pass.
- **Compiler dumps.** `-dB` shows the block-reordering input and output; `-dl`, `-dg` and `-dr` show register
  allocation and scheduling decisions. For register-only differences, running `cc1` in gdb with a breakpoint on
  `find_free_reg` shows each allocation choice.
- **Block numbers in dumps** are only comparable while the block numbering stays the same. Any source change that
  renumbers blocks can fake a moved order; always confirm with the real bytes.

- **Permutation search.** `tools/permuter2.py <section> --names <fn> --src <draft> --budget 300` often finds the
  missing register or order detail of a 60 to 90 % draft within seconds; it writes its best source to
  `<draft>.p2.c`. Rewrite what it found into natural C and check again: it can produce undefined behaviour (a
  variable read before it is set), which is never accepted.
- **Compiler aids.** A statement that emits no instructions but changes register allocation or block order (an empty
  `if (v) { }`, `x++; x--;`, `__builtin_expect`) is accepted only when the file header names it and says what it
  changes.

- **SPARC register order (GCC 3.4, functions with calls):** %g1-%g7, %o5 down to %o0, then %o7, %l0-%l7,
  %i5-%i0. A value in %o7 in the firmware means %o0 was taken by another value live over the same range
  (config/sparc/sparc.h REG_ALLOC_ORDER).
- **Scheduler ties and alias sets.** When two ready instructions have the same priority, GCC 3.4 prefers the one
  with more dependent instructions (haifa-sched.c rank_for_schedule). A store through a pointer depends on every
  later load and store of the same alias set, so it often wins such a tie. Declaring the stored variable with
  another integer type of the same size (`unsigned long` instead of `unsigned int`) gives it its own alias set and
  removes those dependences (FUN_a00d378c).
- **Identical if/else arms.** The original authors sometimes wrote the same statement in both arms of an if/else.
  GCC 3.4 merges such arms only after register allocation (cross-jumping), so before that the shared values are
  live across blocks and go to the global allocator, which can pick another register (%o0 in
  DRV_HDMI_EQScan_FSM_PHY_EQ). Look for this when a single register differs in a value computed just before a
  store or call.
- **Symbol names and GCSE order (-O2/-O3).** GCSE numbers the registers it creates in the order of its hash buckets,
  and a symbol's hash comes from the characters of its name. When two such registers tie in allocation priority
  (priorities are truncated to integers in global.c allocno_compare), the lower number wins. The data name is free
  within the pattern tools/exact.py resolves (DAT_/ARR_/PTR_/s_/u_ + address + optional _suffix); another name can
  give the firmware order (FUN_a00af44c, ARR_00190cec).
- **Allocator experiments in gdb.** cc1 has symbols: break on find_free_reg (local-alloc), combine_regs (ties) or
  find_reg (global; allocno array at the `allocno` symbol, 0x68-byte records: reg, size, calls, refs, freq,
  live_length, conflicts). Forcing one decision and diffing shows whether that decision alone gives the firmware
  bytes, before looking for the C that produces it.
- **Signatures from the callers.** A %o7 or %o0 choice that nothing in the body explains can come from the
  function's own signature: in a non-void function %i0 is the return register and is live everywhere, so a
  parameter copy cannot share it. FUN_a00d0d78 is void with an unsigned char parameter, as its caller declares it.
  A void function whose last statement is a call becomes a sibling call (call; restore) and switches to the leaf
  register order; a statement after the call that compiles to nothing (testing the callee's int result) keeps a
  normal call.
- **Always-true tests that combine removes.** combine records each register's possible bits before it simplifies;
  a default value set behind a test that is always true but only removed by combine keeps the full zero-extension
  mask (FUN_a00f8f78). A no-code aid; name it in the header.
- **Array index or pointer sum.** `*(table + i) = v` and `table[i] = v` can produce different operand order and
  scheduling for the same store; try both (DRV_HDMI21_RXDetect_FSM_LTS_P).

## Proven dead ends

| Approach | Result |
|---|---|
| Other GCC builds (every public BCC 1.0.x, FSF 3.4.0–3.4.6, distribution patches) | Same output as BCC 1.0.52 for the cases tested; no help for block order. |
| Compiler flags and `--param` settings beyond the recorded ones | No combination improved a block-order mismatch. |
| Compiling a function together with its neighbours in one file | Label numbers change, the code does not. |
| Rewriting states or steps as separate static functions | GCC 3.4's inliner turns returns into plain jumps; the result is identical to writing the code in place. |
| A single prediction hint per attempt, for block-order problems | Not enough when two ties must break together; test pairs. |
| Other Keil releases for the 8051 | C51 9.57 is the release that reproduces every function. 9.59 and later load the shift count before the value (FUN_CODE_d351 cannot match); 9.02a and 9.03 differ in other functions. |
| Do-nothing loops as statement carriers (`do { } while (0)`, `while (0)`) | Removed when the tree is expanded; no effect on scheduling. A carrier must be code the firmware has. |
| `-fno-strict-aliasing` against loads hoisted above constant-address register stores | No change: those are separated by base address, not by type. |
| Fake `volatile`, inline assembly, invented names | Not allowed; they produce code the original did not have. |
