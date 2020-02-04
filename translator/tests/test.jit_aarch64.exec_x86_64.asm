
test.jit_aarch64.exec_x86_64.bin:     file format binary


Disassembly of section .data:

0000000000000000 <.data>:
   0:	a9bf07e0 	stp	x0, x1, [sp,#-16]!
   4:	a9bf0fe2 	stp	x2, x3, [sp,#-16]!
   8:	a9bf17e4 	stp	x4, x5, [sp,#-16]!
   c:	a9bf1fe6 	stp	x6, x7, [sp,#-16]!
  10:	a9bf27e8 	stp	x8, x9, [sp,#-16]!
  14:	a9bf2fea 	stp	x10, x11, [sp,#-16]!
  18:	a9bf37ec 	stp	x12, x13, [sp,#-16]!
  1c:	a9bf3fee 	stp	x14, x15, [sp,#-16]!
  20:	d2893500 	mov	x0, #0x49a8                	// #18856
  24:	d2accb41 	mov	x1, #0x665a0000            	// #1717174272
  28:	aa010000 	orr	x0, x0, x1
  2c:	d2cfffa1 	mov	x1, #0x7ffd00000000        	// #140724603453440
  30:	aa010000 	orr	x0, x0, x1
  34:	d2e00001 	movz	x1, #0x0, lsl #48
  38:	aa010000 	orr	x0, x0, x1
  3c:	f8408402 	ldr	x2, [x0],#8
  40:	f8408403 	ldr	x3, [x0],#8
  44:	f8408404 	ldr	x4, [x0],#8
  48:	f8408405 	ldr	x5, [x0],#8
  4c:	f8408406 	ldr	x6, [x0],#8
  50:	f8408407 	ldr	x7, [x0],#8
  54:	f8408408 	ldr	x8, [x0],#8
  58:	f8408409 	ldr	x9, [x0],#8
  5c:	f840840a 	ldr	x10, [x0],#8
  60:	f840840b 	ldr	x11, [x0],#8
  64:	f840840c 	ldr	x12, [x0],#8
  68:	f840840d 	ldr	x13, [x0],#8
  6c:	f840840e 	ldr	x14, [x0],#8
  70:	f840840f 	ldr	x15, [x0],#8
  74:	d2893300 	mov	x0, #0x4998                	// #18840
  78:	d2accb41 	mov	x1, #0x665a0000            	// #1717174272
  7c:	aa010000 	orr	x0, x0, x1
  80:	d2cfffa1 	mov	x1, #0x7ffd00000000        	// #140724603453440
  84:	aa010000 	orr	x0, x0, x1
  88:	d2e00001 	movz	x1, #0x0, lsl #48
  8c:	aa010000 	orr	x0, x0, x1
  90:	a9400400 	ldp	x0, x1, [x0]
  94:	a9bf07e0 	stp	x0, x1, [sp,#-16]!
  98:	d2894300 	mov	x0, #0x4a18                	// #18968
  9c:	d2accb41 	mov	x1, #0x665a0000            	// #1717174272
  a0:	aa010000 	orr	x0, x0, x1
  a4:	d2cfffa1 	mov	x1, #0x7ffd00000000        	// #140724603453440
  a8:	aa010000 	orr	x0, x0, x1
  ac:	d2e00001 	movz	x1, #0x0, lsl #48
  b0:	aa010000 	orr	x0, x0, x1
  b4:	85800000 	.inst	0x85800000 ; undefined
  b8:	85800401 	.inst	0x85800401 ; undefined
  bc:	85800802 	.inst	0x85800802 ; undefined
  c0:	85800c03 	.inst	0x85800c03 ; undefined
  c4:	85801004 	.inst	0x85801004 ; undefined
  c8:	85801405 	.inst	0x85801405 ; undefined
  cc:	85801806 	.inst	0x85801806 ; undefined
  d0:	85801c07 	.inst	0x85801c07 ; undefined
  d4:	a8c107e0 	ldp	x0, x1, [sp],#16
  d8:	a9bf07e0 	stp	x0, x1, [sp,#-16]!
  dc:	d2894b00 	mov	x0, #0x4a58                	// #19032
  e0:	d2accb41 	mov	x1, #0x665a0000            	// #1717174272
  e4:	aa010000 	orr	x0, x0, x1
  e8:	d2cfffa1 	mov	x1, #0x7ffd00000000        	// #140724603453440
  ec:	aa010000 	orr	x0, x0, x1
  f0:	d2e00001 	movz	x1, #0x0, lsl #48
  f4:	aa010000 	orr	x0, x0, x1
  f8:	85804000 	.inst	0x85804000 ; undefined
  fc:	85804401 	.inst	0x85804401 ; undefined
 100:	85804802 	.inst	0x85804802 ; undefined
 104:	85804c03 	.inst	0x85804c03 ; undefined
 108:	85805004 	.inst	0x85805004 ; undefined
 10c:	85805405 	.inst	0x85805405 ; undefined
 110:	85805806 	.inst	0x85805806 ; undefined
 114:	85805c07 	.inst	0x85805c07 ; undefined
 118:	85814008 	.inst	0x85814008 ; undefined
 11c:	85814409 	.inst	0x85814409 ; undefined
 120:	8581480a 	.inst	0x8581480a ; undefined
 124:	85814c0b 	.inst	0x85814c0b ; undefined
 128:	8581500c 	.inst	0x8581500c ; undefined
 12c:	8581540d 	.inst	0x8581540d ; undefined
 130:	8581580e 	.inst	0x8581580e ; undefined
 134:	85815c0f 	.inst	0x85815c0f ; undefined
 138:	85824010 	.inst	0x85824010 ; undefined
 13c:	85824411 	.inst	0x85824411 ; undefined
 140:	85824812 	.inst	0x85824812 ; undefined
 144:	85824c13 	.inst	0x85824c13 ; undefined
 148:	85825014 	.inst	0x85825014 ; undefined
 14c:	85825415 	.inst	0x85825415 ; undefined
 150:	85825816 	.inst	0x85825816 ; undefined
 154:	85825c17 	.inst	0x85825c17 ; undefined
 158:	85834018 	.inst	0x85834018 ; undefined
 15c:	85834419 	.inst	0x85834419 ; undefined
 160:	8583481a 	.inst	0x8583481a ; undefined
 164:	85834c1b 	.inst	0x85834c1b ; undefined
 168:	8583501c 	.inst	0x8583501c ; undefined
 16c:	8583541d 	.inst	0x8583541d ; undefined
 170:	8583581e 	.inst	0x8583581e ; undefined
 174:	85835c1f 	.inst	0x85835c1f ; undefined
 178:	a8c107e0 	ldp	x0, x1, [sp],#16
 17c:	a9bf07e0 	stp	x0, x1, [sp,#-16]!
 180:	d28a4f00 	mov	x0, #0x5278                	// #21112
 184:	d2accb41 	mov	x1, #0x665a0000            	// #1717174272
 188:	aa010000 	orr	x0, x0, x1
 18c:	d2cfffa1 	mov	x1, #0x7ffd00000000        	// #140724603453440
 190:	aa010000 	orr	x0, x0, x1
 194:	d2e00001 	movz	x1, #0x0, lsl #48
 198:	aa010000 	orr	x0, x0, x1
 19c:	f8008402 	str	x2, [x0],#8
 1a0:	f8008403 	str	x3, [x0],#8
 1a4:	f8008404 	str	x4, [x0],#8
 1a8:	f8008405 	str	x5, [x0],#8
 1ac:	f8008406 	str	x6, [x0],#8
 1b0:	f8008407 	str	x7, [x0],#8
 1b4:	f8008408 	str	x8, [x0],#8
 1b8:	f8008409 	str	x9, [x0],#8
 1bc:	f800840a 	str	x10, [x0],#8
 1c0:	f800840b 	str	x11, [x0],#8
 1c4:	f800840c 	str	x12, [x0],#8
 1c8:	f800840d 	str	x13, [x0],#8
 1cc:	f800840e 	str	x14, [x0],#8
 1d0:	f800840f 	str	x15, [x0],#8
 1d4:	d28a4d00 	mov	x0, #0x5268                	// #21096
 1d8:	d2accb41 	mov	x1, #0x665a0000            	// #1717174272
 1dc:	aa010000 	orr	x0, x0, x1
 1e0:	d2cfffa1 	mov	x1, #0x7ffd00000000        	// #140724603453440
 1e4:	aa010000 	orr	x0, x0, x1
 1e8:	d2e00001 	movz	x1, #0x0, lsl #48
 1ec:	aa010000 	orr	x0, x0, x1
 1f0:	a8c10fe2 	ldp	x2, x3, [sp],#16
 1f4:	a9000c02 	stp	x2, x3, [x0]
 1f8:	a9bf07e0 	stp	x0, x1, [sp,#-16]!
 1fc:	d28a5d00 	mov	x0, #0x52e8                	// #21224
 200:	d2accb41 	mov	x1, #0x665a0000            	// #1717174272
 204:	aa010000 	orr	x0, x0, x1
 208:	d2cfffa1 	mov	x1, #0x7ffd00000000        	// #140724603453440
 20c:	aa010000 	orr	x0, x0, x1
 210:	d2e00001 	movz	x1, #0x0, lsl #48
 214:	aa010000 	orr	x0, x0, x1
 218:	e5800000 	.inst	0xe5800000 ; undefined
 21c:	e5800401 	.inst	0xe5800401 ; undefined
 220:	e5800802 	.inst	0xe5800802 ; undefined
 224:	e5800c03 	.inst	0xe5800c03 ; undefined
 228:	e5801004 	.inst	0xe5801004 ; undefined
 22c:	e5801405 	.inst	0xe5801405 ; undefined
 230:	e5801806 	.inst	0xe5801806 ; undefined
 234:	e5801c07 	.inst	0xe5801c07 ; undefined
 238:	a8c107e0 	ldp	x0, x1, [sp],#16
 23c:	a9bf07e0 	stp	x0, x1, [sp,#-16]!
 240:	d28a6500 	mov	x0, #0x5328                	// #21288
 244:	d2accb41 	mov	x1, #0x665a0000            	// #1717174272
 248:	aa010000 	orr	x0, x0, x1
 24c:	d2cfffa1 	mov	x1, #0x7ffd00000000        	// #140724603453440
 250:	aa010000 	orr	x0, x0, x1
 254:	d2e00001 	movz	x1, #0x0, lsl #48
 258:	aa010000 	orr	x0, x0, x1
 25c:	e5804000 	.inst	0xe5804000 ; undefined
 260:	e5804401 	.inst	0xe5804401 ; undefined
 264:	e5804802 	.inst	0xe5804802 ; undefined
 268:	e5804c03 	.inst	0xe5804c03 ; undefined
 26c:	e5805004 	.inst	0xe5805004 ; undefined
 270:	e5805405 	.inst	0xe5805405 ; undefined
 274:	e5805806 	.inst	0xe5805806 ; undefined
 278:	e5805c07 	.inst	0xe5805c07 ; undefined
 27c:	e5814008 	.inst	0xe5814008 ; undefined
 280:	e5814409 	.inst	0xe5814409 ; undefined
 284:	e581480a 	.inst	0xe581480a ; undefined
 288:	e5814c0b 	.inst	0xe5814c0b ; undefined
 28c:	e581500c 	.inst	0xe581500c ; undefined
 290:	e581540d 	.inst	0xe581540d ; undefined
 294:	e581580e 	.inst	0xe581580e ; undefined
 298:	e5815c0f 	.inst	0xe5815c0f ; undefined
 29c:	e5824010 	.inst	0xe5824010 ; undefined
 2a0:	e5824411 	.inst	0xe5824411 ; undefined
 2a4:	e5824812 	.inst	0xe5824812 ; undefined
 2a8:	e5824c13 	.inst	0xe5824c13 ; undefined
 2ac:	e5825014 	.inst	0xe5825014 ; undefined
 2b0:	e5825415 	.inst	0xe5825415 ; undefined
 2b4:	e5825816 	.inst	0xe5825816 ; undefined
 2b8:	e5825c17 	.inst	0xe5825c17 ; undefined
 2bc:	e5834018 	.inst	0xe5834018 ; undefined
 2c0:	e5834419 	.inst	0xe5834419 ; undefined
 2c4:	e583481a 	.inst	0xe583481a ; undefined
 2c8:	e5834c1b 	.inst	0xe5834c1b ; undefined
 2cc:	e583501c 	.inst	0xe583501c ; undefined
 2d0:	e583541d 	.inst	0xe583541d ; undefined
 2d4:	e583581e 	.inst	0xe583581e ; undefined
 2d8:	e5835c1f 	.inst	0xe5835c1f ; undefined
 2dc:	a8c107e0 	ldp	x0, x1, [sp],#16
 2e0:	a8c13bef 	ldp	x15, x14, [sp],#16
 2e4:	a8c133ed 	ldp	x13, x12, [sp],#16
 2e8:	a8c12beb 	ldp	x11, x10, [sp],#16
 2ec:	a8c123e9 	ldp	x9, x8, [sp],#16
 2f0:	a8c11be7 	ldp	x7, x6, [sp],#16
 2f4:	a8c113e5 	ldp	x5, x4, [sp],#16
 2f8:	a8c10be3 	ldp	x3, x2, [sp],#16
 2fc:	a8c103e1 	ldp	x1, x0, [sp],#16
 300:	d65f03c0 	ret
