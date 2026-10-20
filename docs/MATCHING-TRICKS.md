# Matching tricks

Everything learned while matching this firmware, organised by what you see when a function does not match yet.
The LEON code was built with GCC 3.4.4 (Gaisler BCC 1.0.52), the 8051 code with Keil C51. Getting identical bytes is
mostly a matter of giving the compiler the same *shape* of source the original had.

Some techniques are *no-code aids*: statements that generate no instructions but steer the compiler. They are
allowed when the function's comment documents them. Inline assembly, fake `volatile` on ordinary memory and invented
symbol names are not allowed.

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
- **Try every optimisation level.** Each LEON file was compiled with its own flags: mostly `-O2 -g`, often `-O3`, with
  or without `-g` and `-msoft-float`, sometimes `-Os -g` or no optimisation at all. The flags of every matched
  function are recorded in `symbols/<section>.json`.

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
| An extension into a temporary, then a move into the variable, after a call | The return of an inlined helper with an early return, e.g. `static u16 rd(void) { if (c) return f(a); return f(b); }`. |
| A retry decrement placed before the call gives `add` + `cmp`; after the call it gives `addcc` | Place the decrement to match. |
| Retry loops | `for (; a != read() && n < N; n++) a = read();`, with the comparison first and the counter second. |

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
- **Narrowing a callee's return type** is only correct when the value really fits. Read the callee's return path first.

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

**Try pairs, not only single hints.** Predictions combine non-additively, so two hints together can produce an
order that neither gives alone. `FUN_a013dc6c` only matched with a specific pair of `__builtin_expect` hints. Each one
alone made the result worse. Generate a candidate hint for every condition, keep those that change the order without
changing the code, and test all pairs.

**Switch layout:**
- With a jump table, GCC 3.4 at `-O3` emits the second-to-last `case` of the source first. If the firmware's first
  block after the jump is case X, put X second to last.
- The order of the `case` labels also decides the register names inside the cases; try every order.
- Write identical `case` bodies separately rather than sharing them; GCC merges them itself, in its own way.

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

- **Register files.** Banks 0 and 1 were built with whole-program register optimisation. With the register files
  `symbols/8051_bank*.orc` (`tools/regfile8051.py`), C51 keeps parameters in R6/R7 across calls, as the firmware does.
- **Compiler version.** Comparing 14 matched functions under every downloadable Keil release puts the firmware's
  compiler at C51 9.05 to 9.57, or 9.60.7. 9.02a and 9.03 drop a `MOV DPTR` reload between consecutive XDATA stores;
  9.59 to 9.60a compile `(x & 0xf0) == 0x50` as `XRL`/`JNZ` instead of `MOV R7,A` / `CJNE R7,#50`.
- **Dead copies.** Keil 9.60.7 removes a register copy whose only reader is gone, in a late pass. Releases 9.05 to
  9.56 can leave such a reader behind as an extra instruction.
- **A dead `MOV R7,ARn` that the firmware keeps.** A comparison through a char cast, `(char)x == C`, copies the value
  into a temporary register and compares that register (`MOV R7,AR6; CJNE R7,#C`). If both outcomes of a `?:` on that
  comparison are identical and non-empty, Keil merges them after the clean-up pass, and the copy stays without a
  reader. An empty branch body is removed earlier and leaves nothing. `FUN_CODE_b456` matched this way.
- **Optimisation level and dead copies.** At `OPTIMIZE` 4 to 7, a simple dead copy such as `t = id; t = 5;` stays in
  the code; levels 8 to 11 remove it.
- **Old Keil versions under Wine** share one fixed temporary file per Wine prefix. Give every parallel job its own
  prefix.

## Diagnosis

- **Two judges.** `tools/check/jf.py` scores the match and checks exact bytes. `tools/check/rawcmp.py` compares the raw
  words independently. A function only counts when both pass.
- **Compiler dumps.** `-dB` shows the block-reordering input and output; `-dl`, `-dg` and `-dr` show register
  allocation and scheduling decisions. For register-only differences, running `cc1` in gdb with a breakpoint on
  `find_free_reg` shows each allocation choice.
- **Block numbers in dumps** are only comparable while the block numbering stays the same. Any source change that
  renumbers blocks can fake a moved order; always confirm with the real bytes.

## Proven dead ends

| Approach | Result |
|---|---|
| Other GCC builds (every public BCC 1.0.x, FSF 3.4.0–3.4.6, distribution patches) | Same output as BCC 1.0.52 for the cases tested; no help for block order. |
| Compiler flags and `--param` settings beyond the recorded ones | No combination improved a block-order mismatch. |
| Compiling a function together with its neighbours in one file | Label numbers change, the code does not. |
| Rewriting states or steps as separate static functions | GCC 3.4's inliner turns returns into plain jumps; the result is identical to writing the code in place. |
| A single prediction hint per attempt, for block-order problems | Not enough when two ties must break together; test pairs. |
| Other Keil releases for the 8051 | Every published release was tested. 9.02a, 9.03 and 9.59 to 9.60a fail functions that already match; the rest give the same code as 9.60.7. |
| Fake `volatile`, inline assembly, invented names | Not allowed; they produce code the original did not have. |
