! trap_enter_halt_loop  (FUN_a0029060)
!
! Raise the interrupt level to 15, enable traps and call the endless loop.
! Note: Calls 0xA002A878 (trap_halt_forever), so the restore path after the call is never reached.
! Name basis: derived - code: call target 0xA002A878 is the endless loop; no references
!
! Matching notes
! --------------
! leon2m FUN_a0029060 @ 0xa0029060  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0029060
	.type FUN_a0029060, #function
FUN_a0029060:
! Continues trap_save_return_pc (no other path leads here). It masks all interrupts, turns traps on and
! calls trap_halt_forever (0xA002A878), an endless loop. The code after the call would put %g0..%g3
! back and return from the trap with traps off and interrupt level 0; its last two instructions (the
! return) are the first two words of irq_entry (0xA00290E4).
	save  %sp, -64, %sp               ! back into the trap window, frame 64 bytes below the trapped one
	rd  %psr, %l0                     ! %l0 = PSR
	or  %l0, 0xf00, %l0               ! interrupt level 15: mask all maskable interrupts
	mov  %l0, %psr                    ! write PSR (traps still off)
	wr  %l0, 0x20, %psr               ! write PSR with ET flipped on: traps on, interrupts still masked
	nop                               ! wait: a PSR write takes effect after three instructions
	nop
	nop
	rd  %psr, %l0                     ! %l0 = PSR as it is now (traps on, level 15)
	nop                               ! no operation
	nop
	sethi  %hi(0xa002a800), %l4       ! upper bits of the address of trap_halt_forever
	or  %l4, 0x78, %l4                ! %l4 = 0xA002A878, trap_halt_forever
	mov  %l4, %l7                     ! %l7 = the routine to call
	mov  %g0, %l1                     ! keep %g0 in %l1
	mov  %g1, %l2                     ! keep %g1 in %l2
	mov  %g2, %l3                     ! keep %g2 in %l3
	mov  %g3, %l4                     ! keep %g3 in %l4
	call  %l7                         ! call trap_halt_forever: an endless loop, it never returns
	nop                               ! delay slot: nothing
! Not reached: trap_halt_forever does not return.
	restore                           ! step to the trapped window ...
	save                              ! ... and back, with traps on
	mov  %l1, %g0                     ! no effect: %g0 is always 0
	mov  %l2, %g1                     ! %g1 back
	mov  %l3, %g2                     ! %g2 back
	mov  %l4, %g3                     ! %g3 back
	nop                               ! no operation
	wr  %l0, 0x20, %psr               ! %l0 has traps on: writing it with ET flipped turns traps off
	andn  %l0, 0xf00, %l4             ! the same PSR with interrupt level 0
	wr  %l4, 0x20, %psr               ! write it with ET flipped: traps stay off, interrupt level 0
	nop                               ! wait: a PSR write takes effect after three instructions
	nop
	nop
	.size FUN_a0029060, .-FUN_a0029060
