/* leon2m FUN_a00291c4 @ 0xa00291c4..0xa0029594 (244 words) + the string "Starting test" at 0xa0029594..0xa00295a4
 * BYTE-EXACT hand-written assembly: sparc-elf-as -Av8, .text compared word by word with
 * parts/leon2m.bin 0xa00291c4..0xa0029594: 0 mismatches / 244 words.
 * The Big chip's (Leon2 Main) trap handlers, i.e. what the core does after a fault. Trap table slots are the
 * byte-exact src/leon2m/FUN_a0028000.S .. FUN_a0028ff0.S; each slot reads %psr into %l0 and %tbr into %l3 and
 * jumps here (slot -> target): tt02 illegal_instruction, tt03 privileged_instruction, tt07 mem_address_not_aligned,
 * tt09 data_access_exception, tt2A division_by_zero, tt82 'ta 2' -> 0xa0029460 (fatal path);
 * tt05 window_overflow -> 0xa0029278; tt06 window_underflow -> 0xa00292d0; tt08 fp_exception, tt84 'ta 4' ->
 * 0xa0029210 (skip the instruction); tt0B watchpoint_detected -> 0xa0029220; tt2B data_store_error -> 0xa0029244;
 * tt80 'ta 0' -> 0xa0029388 (halt); tt83 'ta 3' -> 0xa0029328 (flush windows); tt81 'ta 1' is handled in its slot.
 * tt01 instruction_access_exception, tt04 fp_disabled, tt0A tag_overflow and every unused slot hold 'ta 0' itself:
 * executed inside a trap (ET = 0) that is a trap with traps disabled -> SPARC V8 error mode (the core stops, no
 * dump). Hardware facts used (SPARC V8 manual, not firmware): a trap clears ET; any trap while ET = 0 puts the core
 * into error mode; RETT with ET = 1 in supervisor mode is an illegal_instruction trap.
 * FATAL PATH 0xa0029460 (where the fatal traps above lead): saves WIM/%sp/Y, stores word 0 = 0 and %g1..%g7
 *   at 0xA803FF60..+0x1C, the trap window's %l0..%l7 (PSR, PC, nPC, TBR, WIM, sp, Y, fp) and %i0..%i7 at +0x20..+0x5C,
 *   then (restore) the faulting window's %i0..%i7 / %l0..%l7 at +0x60..+0x9C, (save) back, and calls the word at
 *   RAM 0xA8027B98 with traps STILL DISABLED (no %psr write before the call). Its initial value is 0xA002D5AC
 *   (initial-data word at flash 0xEFB98, partition 0x0E -> RAM 0xA8024000..; no code writes 0xA8027B98):
 *   FUN_a002d5ac prints the crash dump on UART 0xC00B0000 and ends in 'b 0xa002dd08' (branch to itself), it has no
 *   ret/retl/jmp. So the core never comes back: endless loop with ET = 0 (no interrupt, no timer, no mailbox, no
 *   main loop). If the 'save' at 0xa0029524 or the callee's 'save' meets the WIM-invalid window, that is a
 *   window_overflow with ET = 0 -> error mode instead: also a permanent stop. The epilogue after the call
 *   (0xa0029558..) would rett with ET = 1 (both %psr writes XOR 0x20 into a %l0 that has ET = 0): per the RETT
 *   rule above that is itself an illegal_instruction trap; unreachable while the hook never returns.
 * Other code facts: NWINDOWS = 16 (the overflow/underflow handlers rotate WIM with srl 1 / sll 15 and srl 15 /
 *   sll 1). data_store_error counter 0xA8027B10 has initial value 0 (flash 0xEFB10), so the first data store error
 *   gives 'ta 0' with ET = 0 = error mode. 0xa00291cc, 0xa0029200, 0xa002923c, 0xa0029274, 0xa002938c, 0xa0029398
 *   (clear 8 register windows, retl), 0xa0029430 ('retl; ta 2' = divide-by-zero stub) and 0xa0029438 (set PIL
 *   from %i0, return the old PIL) are not targets of any trap slot and no direct call or stored word in the Big
 *   chip image points at them (searched as 0xA00xxxxx and 0x4008xxxx).
 */
	.section ".text"
	.align 4
	.global FUN_a00291c4
	.type FUN_a00291c4, #function
FUN_a00291c4:
! 0xa00291c4: return of the interrupt dispatcher FUN_a0029128 (PC/nPC in %l5/%l6 from 0xA803FF64/68).
	jmp  %l5                                   ! a00291c4
	rett  %l6                                  ! a00291c8
! 0xa00291cc: unreferenced dispatcher form (handler table 0xA8027B50 indexed by trap type - 0x11).
	mov  %fp, %sp                              ! a00291cc
	sethi  %hi(0xa8027800), %l4                ! a00291d0
	or  %l4, 0x350, %l4                        ! a00291d4
	srl  %l3, 4, %l3                           ! a00291d8
	and  %l3, 0xff, %l3                        ! a00291dc
	sub  %l3, 0x11, %l3                        ! a00291e0
	sll  %l3, 2, %l3                           ! a00291e4
	ld  [ %l4 + %l3 ], %l3                     ! a00291e8
	call  %l3                                  ! a00291ec
	nop                                        ! a00291f0
	jmp  %l1                                   ! a00291f4
	rett  %l2                                  ! a00291f8
	nop                                        ! a00291fc
! 0xa0029200: unreferenced 'retry the instruction'.
	jmp  %l1                                   ! a0029200
	rett  %l2                                  ! a0029204
	nop                                        ! a0029208
	nop                                        ! a002920c
! tt08 fp_exception / tt84 'ta 4': skip the trapped instruction (continue at nPC).
	jmp  %l2                                   ! a0029210
	rett  %l2 + 4                              ! a0029214
	nop                                        ! a0029218
	nop                                        ! a002921c
! tt0B watchpoint_detected: copy the trapped instruction word to RAM 0xA8027B9C, %g1 = old nPC, run it from
! RAM (jmp/rett to 0xA8027B9C); RAM 0xA8027BA0 = 'jmp %g1; nop' (initial data) continues at the old nPC.
	ld  [ %l1 ], %l5                           ! a0029220
	sethi  %hi(0xa8027800), %l6                ! a0029224
	or  %l6, 0x39c, %l6                        ! a0029228
	st  %l5, [ %l6 ]                           ! a002922c
	mov  %l2, %g1                              ! a0029230
	jmp  %l6                                   ! a0029234
	rett  %l6 + 4                              ! a0029238
! 0xa002923c: unreferenced 'skip the instruction'.
	jmp  %l2                                   ! a002923c
	rett  %l2 + 4                              ! a0029240
! tt2B data_store_error: counter 0xA8027B10 - 1 (initial 0); >= 0 -> retry; < 0 -> 'ta 0' with ET = 0 = error mode.
	sethi  %hi(0xa8027800), %l4                ! a0029244
	or  %l4, 0x310, %l4                        ! a0029248
	ld  [ %l4 ], %l5                           ! a002924c
	deccc  %l5                                 ! a0029250
	st  %l5, [ %l4 ]                           ! a0029254
	bl .La0029268                              ! a0029258
	nop                                        ! a002925c
	jmp  %l1                                   ! a0029260
	rett  %l2                                  ! a0029264
.La0029268:
	ta  0                                      ! a0029268
	nop                                        ! a002926c
	nop                                        ! a0029270
! 0xa0029274: unreferenced 'ta 0'.
	ta  0                                      ! a0029274
! tt05 window_overflow (16 windows): rotate WIM right by one, save the next window's locals/ins to its stack.
	rd  %wim, %l3                              ! a0029278
	mov  %g1, %l7                              ! a002927c
	srl  %l3, 1, %g1                           ! a0029280
	sll  %l3, 0xf, %l4                         ! a0029284
	or  %l4, %g1, %g1                          ! a0029288
	save                                       ! a002928c
	mov  %g1, %wim                             ! a0029290
	nop                                        ! a0029294
	nop                                        ! a0029298
	nop                                        ! a002929c
	std  %l0, [ %sp + 0 ]                      ! a00292a0
	std  %l2, [ %sp + 8 ]                      ! a00292a4
	std  %l4, [ %sp + 0x10 ]                   ! a00292a8
	std  %l6, [ %sp + 0x18 ]                   ! a00292ac
	std  %i0, [ %sp + 0x20 ]                   ! a00292b0
	std  %i2, [ %sp + 0x28 ]                   ! a00292b4
	std  %i4, [ %sp + 0x30 ]                   ! a00292b8
	std  %fp, [ %sp + 0x38 ]                   ! a00292bc
	restore                                    ! a00292c0
	mov  %l7, %g1                              ! a00292c4
	jmp  %l1                                   ! a00292c8
	rett  %l2                                  ! a00292cc
! tt06 window_underflow (16 windows): rotate WIM left by one, reload the window below from its stack.
	rd  %wim, %l3                              ! a00292d0
	sll  %l3, 1, %l4                           ! a00292d4
	srl  %l3, 0xf, %l5                         ! a00292d8
	or  %l5, %l4, %l5                          ! a00292dc
	mov  %l5, %wim                             ! a00292e0
	nop                                        ! a00292e4
	nop                                        ! a00292e8
	nop                                        ! a00292ec
	restore                                    ! a00292f0
	restore                                    ! a00292f4
	ldd  [ %sp + 0 ], %l0                      ! a00292f8
	ldd  [ %sp + 8 ], %l2                      ! a00292fc
	ldd  [ %sp + 0x10 ], %l4                   ! a0029300
	ldd  [ %sp + 0x18 ], %l6                   ! a0029304
	ldd  [ %sp + 0x20 ], %i0                   ! a0029308
	ldd  [ %sp + 0x28 ], %i2                   ! a002930c
	ldd  [ %sp + 0x30 ], %i4                   ! a0029310
	ldd  [ %sp + 0x38 ], %fp                   ! a0029314
	save                                       ! a0029318
	save                                       ! a002931c
	jmp  %l1                                   ! a0029320
	rett  %l2                                  ! a0029324
! tt83 'ta 3' flush windows: PIL 15 + traps on, six saves and five restores push every window to the stack.
	rd  %psr, %g1                              ! a0029328
	or  %g1, 0xf00, %g2                        ! a002932c
	restore                                    ! a0029330
	wr  %g2, 0x20, %psr                        ! a0029334
	nop                                        ! a0029338
	nop                                        ! a002933c
	nop                                        ! a0029340
	save                                       ! a0029344
	save                                       ! a0029348
	save                                       ! a002934c
	save                                       ! a0029350
	save                                       ! a0029354
	save                                       ! a0029358
	restore                                    ! a002935c
	restore                                    ! a0029360
	restore                                    ! a0029364
	restore                                    ! a0029368
	restore                                    ! a002936c
	mov  %g1, %psr                             ! a0029370
	nop                                        ! a0029374
	nop                                        ! a0029378
	nop                                        ! a002937c
	jmp  %l2                                   ! a0029380
	rett  %l2 + 4                              ! a0029384
! tt80 'ta 0': misaligned 'ld [1]' inside the trap (ET = 0) -> error mode: deliberate stop.
	ld  [ 1 ], %g0                             ! a0029388
! 0xa002938c: unreferenced 'skip the instruction'.
	jmp  %l2                                   ! a002938c
	rett  %l2 + 4                              ! a0029390
	nop                                        ! a0029394
! 0xa0029398: unreferenced: WIM = 0, zero %l0..%l7 / %o0..%o7 in 8 windows, restore WIM, return to %g2.
	mov  %g0, %g1                              ! a0029398
	mov  %o7, %g2                              ! a002939c
	mov  %g0, %g4                              ! a00293a0
	mov  %g0, %g5                              ! a00293a4
	mov  %g0, %g6                              ! a00293a8
	mov  %g0, %g7                              ! a00293ac
	rd  %wim, %g7                              ! a00293b0
	mov  %g0, %wim                             ! a00293b4
	nop                                        ! a00293b8
	nop                                        ! a00293bc
	nop                                        ! a00293c0
.La00293c4:
	mov  %g0, %l0                              ! a00293c4
	mov  %g0, %l1                              ! a00293c8
	mov  %g0, %l2                              ! a00293cc
	mov  %g0, %l3                              ! a00293d0
	mov  %g0, %l4                              ! a00293d4
	mov  %g0, %l5                              ! a00293d8
	mov  %g0, %l6                              ! a00293dc
	mov  %g0, %l7                              ! a00293e0
	mov  %g0, %o0                              ! a00293e4
	mov  %g0, %o1                              ! a00293e8
	mov  %g0, %o2                              ! a00293ec
	mov  %g0, %o3                              ! a00293f0
	mov  %g0, %o4                              ! a00293f4
	mov  %g0, %o5                              ! a00293f8
	mov  %g0, %sp                              ! a00293fc
	mov  %g0, %o7                              ! a0029400
	save                                       ! a0029404
	cmp  %g1, 7                                ! a0029408
	bne .La00293c4                             ! a002940c
	inc  %g1                                   ! a0029410
	mov  %g7, %wim                             ! a0029414
	nop                                        ! a0029418
	nop                                        ! a002941c
	nop                                        ! a0029420
	mov  %g2, %o7                              ! a0029424
	retl                                       ! a0029428
	nop                                        ! a002942c
! 0xa0029430: unreferenced 'retl; ta 2' (divide-by-zero stub -> tt82 -> fatal path).
	retl                                       ! a0029430
	ta  2                                      ! a0029434
! 0xa0029438: unreferenced trap body: PIL = %i0 & 0xf, returns the old PIL in %i0.
	rd  %psr, %l4                              ! a0029438
	srl  %l4, 8, %l5                           ! a002943c
	andn  %l4, 0xf00, %l4                      ! a0029440
	sll  %i0, 8, %i0                           ! a0029444
	and  %i0, 0xf00, %i0                       ! a0029448
	or  %i0, %l4, %l4                          ! a002944c
	mov  %l4, %psr                             ! a0029450
	and  %l5, 0xf, %i0                         ! a0029454
	jmp  %l2                                   ! a0029458
	rett  %l2 + 4                              ! a002945c
! FATAL PATH (tt02/03/07/09/2A/82): save the full register state at 0xA803FF60.., see the header.
	rd  %wim, %l4                              ! a0029460
	mov  %sp, %l5                              ! a0029464
	rd  %y, %l6                                ! a0029468
	sethi  %hi(0xa803fc00), %l7                ! a002946c
	or  %l7, 0x360, %l7                        ! a0029470
! dump word 0 = 0, then %g1..%g7.
	clr  [ %l7 + 0 ]                           ! a0029474
	st  %g1, [ %l7 + 4 ]                       ! a0029478
	st  %g2, [ %l7 + 8 ]                       ! a002947c
	st  %g3, [ %l7 + 0xc ]                     ! a0029480
	st  %g4, [ %l7 + 0x10 ]                    ! a0029484
	st  %g5, [ %l7 + 0x14 ]                    ! a0029488
	st  %g6, [ %l7 + 0x18 ]                    ! a002948c
	st  %g7, [ %l7 + 0x1c ]                    ! a0029490
	sethi  %hi(0xa803fc00), %g3                ! a0029494
	or  %g3, 0x360, %g3                        ! a0029498
	mov  %fp, %l7                              ! a002949c
! trap window %l0..%l7 (PSR, PC, nPC, TBR, WIM, sp, Y, fp) and %i0..%i7.
	st  %l0, [ %g3 + 0x20 ]                    ! a00294a0
	st  %l1, [ %g3 + 0x24 ]                    ! a00294a4
	st  %l2, [ %g3 + 0x28 ]                    ! a00294a8
	st  %l3, [ %g3 + 0x2c ]                    ! a00294ac
	st  %l4, [ %g3 + 0x30 ]                    ! a00294b0
	st  %l5, [ %g3 + 0x34 ]                    ! a00294b4
	st  %l6, [ %g3 + 0x38 ]                    ! a00294b8
	st  %l7, [ %g3 + 0x3c ]                    ! a00294bc
	st  %i0, [ %g3 + 0x40 ]                    ! a00294c0
	st  %i1, [ %g3 + 0x44 ]                    ! a00294c4
	st  %i2, [ %g3 + 0x48 ]                    ! a00294c8
	st  %i3, [ %g3 + 0x4c ]                    ! a00294cc
	st  %i4, [ %g3 + 0x50 ]                    ! a00294d0
	st  %i5, [ %g3 + 0x54 ]                    ! a00294d4
	st  %fp, [ %g3 + 0x58 ]                    ! a00294d8
	st  %i7, [ %g3 + 0x5c ]                    ! a00294dc
! restore: the faulting window's %i0..%i7 and %l0..%l7.
	restore                                    ! a00294e0
	st  %i0, [ %g3 + 0x60 ]                    ! a00294e4
	st  %i1, [ %g3 + 0x64 ]                    ! a00294e8
	st  %i2, [ %g3 + 0x68 ]                    ! a00294ec
	st  %i3, [ %g3 + 0x6c ]                    ! a00294f0
	st  %i4, [ %g3 + 0x70 ]                    ! a00294f4
	st  %i5, [ %g3 + 0x74 ]                    ! a00294f8
	st  %fp, [ %g3 + 0x78 ]                    ! a00294fc
	st  %i7, [ %g3 + 0x7c ]                    ! a0029500
	st  %l0, [ %g3 + 0x80 ]                    ! a0029504
	st  %l1, [ %g3 + 0x84 ]                    ! a0029508
	st  %l2, [ %g3 + 0x88 ]                    ! a002950c
	st  %l3, [ %g3 + 0x8c ]                    ! a0029510
	st  %l4, [ %g3 + 0x90 ]                    ! a0029514
	st  %l5, [ %g3 + 0x94 ]                    ! a0029518
	st  %l6, [ %g3 + 0x98 ]                    ! a002951c
	st  %l7, [ %g3 + 0x9c ]                    ! a0029520
! save back to the trap window (WIM checked here: invalid window -> window_overflow with ET = 0 = error mode).
	save                                       ! a0029524
	sethi  %hi(0xa803fc00), %l7                ! a0029528
	or  %l7, 0x360, %l7                        ! a002952c
	ld  [ %l7 + 0xc ], %g3                     ! a0029530
! call the hook word at 0xA8027B98 (= FUN_a002d5ac: crash dump on UART, then endless 'b .'), traps still off.
	sethi  %hi(0xa8027800), %l3                ! a0029534
	or  %l3, 0x398, %l3                        ! a0029538
	ld  [ %l3 ], %l7                           ! a002953c
	mov  %g0, %l3                              ! a0029540
	mov  %g1, %l4                              ! a0029544
	mov  %g2, %l5                              ! a0029548
	mov  %g3, %l6                              ! a002954c
	call  %l7                                  ! a0029550
	nop                                        ! a0029554
! not reached while the hook never returns: restore globals, PSR, retry the faulting instruction.
	restore                                    ! a0029558
	save                                       ! a002955c
	mov  %l3, %g0                              ! a0029560
	mov  %l4, %g1                              ! a0029564
	mov  %l5, %g2                              ! a0029568
	mov  %l6, %g3                              ! a002956c
	nop                                        ! a0029570
	wr  %l0, 0x20, %psr                        ! a0029574
	andn  %l0, 0xf00, %l4                      ! a0029578
	wr  %l4, 0x20, %psr                        ! a002957c
	nop                                        ! a0029580
	nop                                        ! a0029584
	nop                                        ! a0029588
	jmp  %l1                                   ! a002958c
	rett  %l2                                  ! a0029590
	.ascii "Starting test\0\0\0"			! a0029594: data (string), not code
	.size FUN_a00291c4, .-FUN_a00291c4
