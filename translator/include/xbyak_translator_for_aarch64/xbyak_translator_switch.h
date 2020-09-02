/*******************************************************************************
 * Copyright 2020 FUJITSU LIMITED
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/
#ifdef XT_DEBUG
std::cout << xed_iclass_enum_t2str(p) << std::endl;
#endif

switch (p) {
case XED_ICLASS_INVALID:
  break;
case XED_ICLASS_AAA:
  break;
case XED_ICLASS_AAD:
  break;
case XED_ICLASS_AAM:
  break;
case XED_ICLASS_AAS:
  break;
case XED_ICLASS_ADC:
  translateADC(&xedd);
  break;
case XED_ICLASS_ADCX:
  break;
case XED_ICLASS_ADC_LOCK:
  break;
case XED_ICLASS_ADD:
  translateADD(&xedd);
  break;
case XED_ICLASS_ADDPD:
  break;
case XED_ICLASS_ADDPS:
  translateADDPS(&xedd);
  break;
case XED_ICLASS_ADDSD:
  break;
case XED_ICLASS_ADDSS:
  translateADDSS(&xedd);
  break;
case XED_ICLASS_ADDSUBPD:
  break;
case XED_ICLASS_ADDSUBPS:
  break;
case XED_ICLASS_ADD_LOCK:
  break;
case XED_ICLASS_ADOX:
  break;
case XED_ICLASS_AESDEC:
  break;
case XED_ICLASS_AESDECLAST:
  break;
case XED_ICLASS_AESENC:
  break;
case XED_ICLASS_AESENCLAST:
  break;
case XED_ICLASS_AESIMC:
  break;
case XED_ICLASS_AESKEYGENASSIST:
  break;
case XED_ICLASS_AND:
  translateAND(&xedd);
  break;
case XED_ICLASS_ANDN:
  break;
case XED_ICLASS_ANDNPD:
  break;
case XED_ICLASS_ANDNPS:
  break;
case XED_ICLASS_ANDPD:
  break;
case XED_ICLASS_ANDPS:
  break;
case XED_ICLASS_AND_LOCK:
  break;
case XED_ICLASS_ARPL:
  break;
case XED_ICLASS_BEXTR:
  break;
case XED_ICLASS_BEXTR_XOP:
  break;
case XED_ICLASS_BLCFILL:
  break;
case XED_ICLASS_BLCI:
  break;
case XED_ICLASS_BLCIC:
  break;
case XED_ICLASS_BLCMSK:
  break;
case XED_ICLASS_BLCS:
  break;
case XED_ICLASS_BLENDPD:
  break;
case XED_ICLASS_BLENDPS:
  break;
case XED_ICLASS_BLENDVPD:
  break;
case XED_ICLASS_BLENDVPS:
  translateBLENDVPS(&xedd);
  break;
case XED_ICLASS_BLSFILL:
  break;
case XED_ICLASS_BLSI:
  break;
case XED_ICLASS_BLSIC:
  break;
case XED_ICLASS_BLSMSK:
  break;
case XED_ICLASS_BLSR:
  break;
case XED_ICLASS_BNDCL:
  break;
case XED_ICLASS_BNDCN:
  break;
case XED_ICLASS_BNDCU:
  break;
case XED_ICLASS_BNDLDX:
  break;
case XED_ICLASS_BNDMK:
  break;
case XED_ICLASS_BNDMOV:
  break;
case XED_ICLASS_BNDSTX:
  break;
case XED_ICLASS_BOUND:
  break;
case XED_ICLASS_BSF:
  break;
case XED_ICLASS_BSR:
  break;
case XED_ICLASS_BSWAP:
  break;
case XED_ICLASS_BT:
  break;
case XED_ICLASS_BTC:
  break;
case XED_ICLASS_BTC_LOCK:
  break;
case XED_ICLASS_BTR:
  break;
case XED_ICLASS_BTR_LOCK:
  break;
case XED_ICLASS_BTS:
  break;
case XED_ICLASS_BTS_LOCK:
  break;
case XED_ICLASS_BZHI:
  break;
case XED_ICLASS_CALL_FAR:
  break;
case XED_ICLASS_CALL_NEAR:
  break;
case XED_ICLASS_CBW:
  break;
case XED_ICLASS_CDQ:
  break;
case XED_ICLASS_CDQE:
  break;
case XED_ICLASS_CLAC:
  break;
case XED_ICLASS_CLC:
  break;
case XED_ICLASS_CLD:
  break;
case XED_ICLASS_CLDEMOTE:
  break;
case XED_ICLASS_CLFLUSH:
  break;
case XED_ICLASS_CLFLUSHOPT:
  break;
case XED_ICLASS_CLGI:
  break;
case XED_ICLASS_CLI:
  break;
case XED_ICLASS_CLRSSBSY:
  break;
case XED_ICLASS_CLTS:
  break;
case XED_ICLASS_CLWB:
  break;
case XED_ICLASS_CLZERO:
  break;
case XED_ICLASS_CMC:
  break;
case XED_ICLASS_CMOVB:
  break;
case XED_ICLASS_CMOVBE:
  break;
case XED_ICLASS_CMOVL:
  break;
case XED_ICLASS_CMOVLE:
  break;
case XED_ICLASS_CMOVNB:
  break;
case XED_ICLASS_CMOVNBE:
  break;
case XED_ICLASS_CMOVNL:
  break;
case XED_ICLASS_CMOVNLE:
  translateCMOVNLE(&xedd);
  break;
case XED_ICLASS_CMOVNO:
  break;
case XED_ICLASS_CMOVNP:
  break;
case XED_ICLASS_CMOVNS:
  break;
case XED_ICLASS_CMOVNZ:
  break;
case XED_ICLASS_CMOVO:
  break;
case XED_ICLASS_CMOVP:
  break;
case XED_ICLASS_CMOVS:
  break;
case XED_ICLASS_CMOVZ:
  break;
case XED_ICLASS_CMP:
  translateCMP(&xedd);
  break;
case XED_ICLASS_CMPPD:
  break;
case XED_ICLASS_CMPPS:
  translateCMPPS(&xedd);
  break;
case XED_ICLASS_CMPSB:
  break;
case XED_ICLASS_CMPSD:
  break;
case XED_ICLASS_CMPSD_XMM:
  break;
case XED_ICLASS_CMPSQ:
  break;
case XED_ICLASS_CMPSS:
  break;
case XED_ICLASS_CMPSW:
  break;
case XED_ICLASS_CMPXCHG:
  break;
case XED_ICLASS_CMPXCHG16B:
  break;
case XED_ICLASS_CMPXCHG16B_LOCK:
  break;
case XED_ICLASS_CMPXCHG8B:
  break;
case XED_ICLASS_CMPXCHG8B_LOCK:
  break;
case XED_ICLASS_CMPXCHG_LOCK:
  break;
case XED_ICLASS_COMISD:
  break;
case XED_ICLASS_COMISS:
  break;
case XED_ICLASS_CPUID:
  break;
case XED_ICLASS_CQO:
  break;
case XED_ICLASS_CRC32:
  break;
case XED_ICLASS_CVTDQ2PD:
  break;
case XED_ICLASS_CVTDQ2PS:
  break;
case XED_ICLASS_CVTPD2DQ:
  break;
case XED_ICLASS_CVTPD2PI:
  break;
case XED_ICLASS_CVTPD2PS:
  break;
case XED_ICLASS_CVTPI2PD:
  break;
case XED_ICLASS_CVTPI2PS:
  break;
case XED_ICLASS_CVTPS2DQ:
  break;
case XED_ICLASS_CVTPS2PD:
  break;
case XED_ICLASS_CVTPS2PI:
  break;
case XED_ICLASS_CVTSD2SI:
  break;
case XED_ICLASS_CVTSD2SS:
  break;
case XED_ICLASS_CVTSI2SD:
  break;
case XED_ICLASS_CVTSI2SS:
  break;
case XED_ICLASS_CVTSS2SD:
  break;
case XED_ICLASS_CVTSS2SI:
  break;
case XED_ICLASS_CVTTPD2DQ:
  break;
case XED_ICLASS_CVTTPD2PI:
  break;
case XED_ICLASS_CVTTPS2DQ:
  break;
case XED_ICLASS_CVTTPS2PI:
  break;
case XED_ICLASS_CVTTSD2SI:
  break;
case XED_ICLASS_CVTTSS2SI:
  break;
case XED_ICLASS_CWD:
  break;
case XED_ICLASS_CWDE:
  break;
case XED_ICLASS_DAA:
  break;
case XED_ICLASS_DAS:
  break;
case XED_ICLASS_DEC:
  translateDEC(&xedd);
  break;
case XED_ICLASS_DEC_LOCK:
  break;
case XED_ICLASS_DIV:
  break;
case XED_ICLASS_DIVPD:
  break;
case XED_ICLASS_DIVPS:
  break;
case XED_ICLASS_DIVSD:
  break;
case XED_ICLASS_DIVSS:
  break;
case XED_ICLASS_DPPD:
  break;
case XED_ICLASS_DPPS:
  break;
case XED_ICLASS_EMMS:
  break;
case XED_ICLASS_ENCLS:
  break;
case XED_ICLASS_ENCLU:
  break;
case XED_ICLASS_ENCLV:
  break;
case XED_ICLASS_ENDBR32:
  break;
case XED_ICLASS_ENDBR64:
  break;
case XED_ICLASS_ENQCMD:
  break;
case XED_ICLASS_ENQCMDS:
  break;
case XED_ICLASS_ENTER:
  break;
case XED_ICLASS_EXTRACTPS:
  break;
case XED_ICLASS_EXTRQ:
  break;
case XED_ICLASS_F2XM1:
  break;
case XED_ICLASS_FABS:
  break;
case XED_ICLASS_FADD:
  break;
case XED_ICLASS_FADDP:
  break;
case XED_ICLASS_FBLD:
  break;
case XED_ICLASS_FBSTP:
  break;
case XED_ICLASS_FCHS:
  break;
case XED_ICLASS_FCMOVB:
  break;
case XED_ICLASS_FCMOVBE:
  break;
case XED_ICLASS_FCMOVE:
  break;
case XED_ICLASS_FCMOVNB:
  break;
case XED_ICLASS_FCMOVNBE:
  break;
case XED_ICLASS_FCMOVNE:
  break;
case XED_ICLASS_FCMOVNU:
  break;
case XED_ICLASS_FCMOVU:
  break;
case XED_ICLASS_FCOM:
  break;
case XED_ICLASS_FCOMI:
  break;
case XED_ICLASS_FCOMIP:
  break;
case XED_ICLASS_FCOMP:
  break;
case XED_ICLASS_FCOMPP:
  break;
case XED_ICLASS_FCOS:
  break;
case XED_ICLASS_FDECSTP:
  break;
case XED_ICLASS_FDISI8087_NOP:
  break;
case XED_ICLASS_FDIV:
  break;
case XED_ICLASS_FDIVP:
  break;
case XED_ICLASS_FDIVR:
  break;
case XED_ICLASS_FDIVRP:
  break;
case XED_ICLASS_FEMMS:
  break;
case XED_ICLASS_FENI8087_NOP:
  break;
case XED_ICLASS_FFREE:
  break;
case XED_ICLASS_FFREEP:
  break;
case XED_ICLASS_FIADD:
  break;
case XED_ICLASS_FICOM:
  break;
case XED_ICLASS_FICOMP:
  break;
case XED_ICLASS_FIDIV:
  break;
case XED_ICLASS_FIDIVR:
  break;
case XED_ICLASS_FILD:
  break;
case XED_ICLASS_FIMUL:
  break;
case XED_ICLASS_FINCSTP:
  break;
case XED_ICLASS_FIST:
  break;
case XED_ICLASS_FISTP:
  break;
case XED_ICLASS_FISTTP:
  break;
case XED_ICLASS_FISUB:
  break;
case XED_ICLASS_FISUBR:
  break;
case XED_ICLASS_FLD:
  break;
case XED_ICLASS_FLD1:
  break;
case XED_ICLASS_FLDCW:
  break;
case XED_ICLASS_FLDENV:
  break;
case XED_ICLASS_FLDL2E:
  break;
case XED_ICLASS_FLDL2T:
  break;
case XED_ICLASS_FLDLG2:
  break;
case XED_ICLASS_FLDLN2:
  break;
case XED_ICLASS_FLDPI:
  break;
case XED_ICLASS_FLDZ:
  break;
case XED_ICLASS_FMUL:
  break;
case XED_ICLASS_FMULP:
  break;
case XED_ICLASS_FNCLEX:
  break;
case XED_ICLASS_FNINIT:
  break;
case XED_ICLASS_FNOP:
  break;
case XED_ICLASS_FNSAVE:
  break;
case XED_ICLASS_FNSTCW:
  break;
case XED_ICLASS_FNSTENV:
  break;
case XED_ICLASS_FNSTSW:
  break;
case XED_ICLASS_FPATAN:
  break;
case XED_ICLASS_FPREM:
  break;
case XED_ICLASS_FPREM1:
  break;
case XED_ICLASS_FPTAN:
  break;
case XED_ICLASS_FRNDINT:
  break;
case XED_ICLASS_FRSTOR:
  break;
case XED_ICLASS_FSCALE:
  break;
case XED_ICLASS_FSETPM287_NOP:
  break;
case XED_ICLASS_FSIN:
  break;
case XED_ICLASS_FSINCOS:
  break;
case XED_ICLASS_FSQRT:
  break;
case XED_ICLASS_FST:
  break;
case XED_ICLASS_FSTP:
  break;
case XED_ICLASS_FSTPNCE:
  break;
case XED_ICLASS_FSUB:
  break;
case XED_ICLASS_FSUBP:
  break;
case XED_ICLASS_FSUBR:
  break;
case XED_ICLASS_FSUBRP:
  break;
case XED_ICLASS_FTST:
  break;
case XED_ICLASS_FUCOM:
  break;
case XED_ICLASS_FUCOMI:
  break;
case XED_ICLASS_FUCOMIP:
  break;
case XED_ICLASS_FUCOMP:
  break;
case XED_ICLASS_FUCOMPP:
  break;
case XED_ICLASS_FWAIT:
  break;
case XED_ICLASS_FXAM:
  break;
case XED_ICLASS_FXCH:
  break;
case XED_ICLASS_FXRSTOR:
  break;
case XED_ICLASS_FXRSTOR64:
  break;
case XED_ICLASS_FXSAVE:
  break;
case XED_ICLASS_FXSAVE64:
  break;
case XED_ICLASS_FXTRACT:
  break;
case XED_ICLASS_FYL2X:
  break;
case XED_ICLASS_FYL2XP1:
  break;
case XED_ICLASS_GETSEC:
  break;
case XED_ICLASS_GF2P8AFFINEINVQB:
  break;
case XED_ICLASS_GF2P8AFFINEQB:
  break;
case XED_ICLASS_GF2P8MULB:
  break;
case XED_ICLASS_HADDPD:
  break;
case XED_ICLASS_HADDPS:
  break;
case XED_ICLASS_HLT:
  break;
case XED_ICLASS_HSUBPD:
  break;
case XED_ICLASS_HSUBPS:
  break;
case XED_ICLASS_IDIV:
  break;
case XED_ICLASS_IMUL:
  translateIMUL(&xedd);
  break;
case XED_ICLASS_IN:
  break;
case XED_ICLASS_INC:
  translateINC(&xedd);
  break;
case XED_ICLASS_INCSSPD:
  break;
case XED_ICLASS_INCSSPQ:
  break;
case XED_ICLASS_INC_LOCK:
  break;
case XED_ICLASS_INSB:
  break;
case XED_ICLASS_INSD:
  break;
case XED_ICLASS_INSERTPS:
  break;
case XED_ICLASS_INSERTQ:
  break;
case XED_ICLASS_INSW:
  break;
case XED_ICLASS_INT:
  break;
case XED_ICLASS_INT1:
  break;
case XED_ICLASS_INT3:
  break;
case XED_ICLASS_INTO:
  break;
case XED_ICLASS_INVD:
  break;
case XED_ICLASS_INVEPT:
  break;
case XED_ICLASS_INVLPG:
  break;
case XED_ICLASS_INVLPGA:
  break;
case XED_ICLASS_INVPCID:
  break;
case XED_ICLASS_INVVPID:
  break;
case XED_ICLASS_IRET:
  break;
case XED_ICLASS_IRETD:
  break;
case XED_ICLASS_IRETQ:
  break;
case XED_ICLASS_JB:
  break;
case XED_ICLASS_JBE:
  break;
case XED_ICLASS_JCXZ:
  break;
case XED_ICLASS_JECXZ:
  break;
case XED_ICLASS_JL:
  break;
case XED_ICLASS_JLE:
  break;
case XED_ICLASS_JMP:
  break;
case XED_ICLASS_JMP_FAR:
  break;
case XED_ICLASS_JNB:
  break;
case XED_ICLASS_JNBE:
  break;
case XED_ICLASS_JNL:
  break;
case XED_ICLASS_JNLE:
  break;
case XED_ICLASS_JNO:
  break;
case XED_ICLASS_JNP:
  break;
case XED_ICLASS_JNS:
  break;
case XED_ICLASS_JNZ:
  break;
case XED_ICLASS_JO:
  break;
case XED_ICLASS_JP:
  break;
case XED_ICLASS_JRCXZ:
  break;
case XED_ICLASS_JS:
  break;
case XED_ICLASS_JZ:
  break;
case XED_ICLASS_KADDB:
  break;
case XED_ICLASS_KADDD:
  break;
case XED_ICLASS_KADDQ:
  break;
case XED_ICLASS_KADDW:
  break;
case XED_ICLASS_KANDB:
  break;
case XED_ICLASS_KANDD:
  break;
case XED_ICLASS_KANDNB:
  break;
case XED_ICLASS_KANDND:
  break;
case XED_ICLASS_KANDNQ:
  break;
case XED_ICLASS_KANDNW:
  break;
case XED_ICLASS_KANDQ:
  break;
case XED_ICLASS_KANDW:
  break;
case XED_ICLASS_KMOVB:
  break;
case XED_ICLASS_KMOVD:
  translateKMOVD(&xedd);
  break;
case XED_ICLASS_KMOVQ:
  translateKMOVQ(&xedd);
  break;
case XED_ICLASS_KMOVW:
  translateKMOVW(&xedd);
  break;
case XED_ICLASS_KNOTB:
  break;
case XED_ICLASS_KNOTD:
  break;
case XED_ICLASS_KNOTQ:
  break;
case XED_ICLASS_KNOTW:
  break;
case XED_ICLASS_KORB:
  break;
case XED_ICLASS_KORD:
  break;
case XED_ICLASS_KORQ:
  break;
case XED_ICLASS_KORTESTB:
  break;
case XED_ICLASS_KORTESTD:
  break;
case XED_ICLASS_KORTESTQ:
  break;
case XED_ICLASS_KORTESTW:
  translateKORTESTW(&xedd);
  break;
case XED_ICLASS_KORW:
  break;
case XED_ICLASS_KSHIFTLB:
  break;
case XED_ICLASS_KSHIFTLD:
  break;
case XED_ICLASS_KSHIFTLQ:
  break;
case XED_ICLASS_KSHIFTLW:
  break;
case XED_ICLASS_KSHIFTRB:
  break;
case XED_ICLASS_KSHIFTRD:
  break;
case XED_ICLASS_KSHIFTRQ:
  break;
case XED_ICLASS_KSHIFTRW:
  break;
case XED_ICLASS_KTESTB:
  break;
case XED_ICLASS_KTESTD:
  break;
case XED_ICLASS_KTESTQ:
  translateKTESTQ(&xedd);
  break;
case XED_ICLASS_KTESTW:
  break;
case XED_ICLASS_KUNPCKBW:
  break;
case XED_ICLASS_KUNPCKDQ:
  break;
case XED_ICLASS_KUNPCKWD:
  break;
case XED_ICLASS_KXNORB:
  break;
case XED_ICLASS_KXNORD:
  break;
case XED_ICLASS_KXNORQ:
  break;
case XED_ICLASS_KXNORW:
  break;
case XED_ICLASS_KXORB:
  break;
case XED_ICLASS_KXORD:
  break;
case XED_ICLASS_KXORQ:
  break;
case XED_ICLASS_KXORW:
  break;
case XED_ICLASS_LAHF:
  break;
case XED_ICLASS_LAR:
  break;
case XED_ICLASS_LDDQU:
  break;
case XED_ICLASS_LDMXCSR:
  break;
case XED_ICLASS_LDS:
  break;
case XED_ICLASS_LEA:
  translateLEA(&xedd);
  break;
case XED_ICLASS_LEAVE:
  break;
case XED_ICLASS_LES:
  break;
case XED_ICLASS_LFENCE:
  break;
case XED_ICLASS_LFS:
  break;
case XED_ICLASS_LGDT:
  break;
case XED_ICLASS_LGS:
  break;
case XED_ICLASS_LIDT:
  break;
case XED_ICLASS_LLDT:
  break;
case XED_ICLASS_LLWPCB:
  break;
case XED_ICLASS_LMSW:
  break;
case XED_ICLASS_LODSB:
  break;
case XED_ICLASS_LODSD:
  break;
case XED_ICLASS_LODSQ:
  break;
case XED_ICLASS_LODSW:
  break;
case XED_ICLASS_LOOP:
  break;
case XED_ICLASS_LOOPE:
  break;
case XED_ICLASS_LOOPNE:
  break;
case XED_ICLASS_LSL:
  break;
case XED_ICLASS_LSS:
  break;
case XED_ICLASS_LTR:
  break;
case XED_ICLASS_LWPINS:
  break;
case XED_ICLASS_LWPVAL:
  break;
case XED_ICLASS_LZCNT:
  break;
case XED_ICLASS_MASKMOVDQU:
  break;
case XED_ICLASS_MASKMOVQ:
  break;
case XED_ICLASS_MAXPD:
  break;
case XED_ICLASS_MAXPS:
  break;
case XED_ICLASS_MAXSD:
  break;
case XED_ICLASS_MAXSS:
  break;
case XED_ICLASS_MFENCE:
  break;
case XED_ICLASS_MINPD:
  break;
case XED_ICLASS_MINPS:
  break;
case XED_ICLASS_MINSD:
  break;
case XED_ICLASS_MINSS:
  break;
case XED_ICLASS_MONITOR:
  break;
case XED_ICLASS_MONITORX:
  break;
case XED_ICLASS_MOV:
  translateMOV(&xedd);
  break;
case XED_ICLASS_MOVAPD:
  break;
case XED_ICLASS_MOVAPS:
  translateMOVAPS(&xedd);
  break;
case XED_ICLASS_MOVBE:
  break;
case XED_ICLASS_MOVD:
  translateMOVD(&xedd);
  break;
case XED_ICLASS_MOVDDUP:
  break;
case XED_ICLASS_MOVDIR64B:
  break;
case XED_ICLASS_MOVDIRI:
  break;
case XED_ICLASS_MOVDQ2Q:
  break;
case XED_ICLASS_MOVDQA:
  translateMOVDQA(&xedd);
  break;
case XED_ICLASS_MOVDQU:
  translateMOVDQU(&xedd);
  break;
case XED_ICLASS_MOVHLPS:
  translateMOVHLPS(&xedd);
  break;
case XED_ICLASS_MOVHPD:
  break;
case XED_ICLASS_MOVHPS:
  break;
case XED_ICLASS_MOVLHPS:
  break;
case XED_ICLASS_MOVLPD:
  break;
case XED_ICLASS_MOVLPS:
  break;
case XED_ICLASS_MOVMSKPD:
  break;
case XED_ICLASS_MOVMSKPS:
  break;
case XED_ICLASS_MOVNTDQ:
  break;
case XED_ICLASS_MOVNTDQA:
  break;
case XED_ICLASS_MOVNTI:
  break;
case XED_ICLASS_MOVNTPD:
  break;
case XED_ICLASS_MOVNTPS:
  break;
case XED_ICLASS_MOVNTQ:
  break;
case XED_ICLASS_MOVNTSD:
  break;
case XED_ICLASS_MOVNTSS:
  break;
case XED_ICLASS_MOVQ:
  translateMOVQ(&xedd);
  break;

case XED_ICLASS_MOVQ2DQ:
  break;
case XED_ICLASS_MOVSB:
  break;
case XED_ICLASS_MOVSD:
  break;
case XED_ICLASS_MOVSD_XMM:
  translateMOVSD(&xedd);
  break;
case XED_ICLASS_MOVSHDUP:
  break;
case XED_ICLASS_MOVSLDUP:
  break;
case XED_ICLASS_MOVSQ:
  break;
case XED_ICLASS_MOVSS:
  translateMOVSS(&xedd);
  break;

case XED_ICLASS_MOVSW:
  break;
case XED_ICLASS_MOVSX:
  break;
case XED_ICLASS_MOVSXD:
  break;
case XED_ICLASS_MOVUPD:
  break;
case XED_ICLASS_MOVUPS:
  translateMOVUPS(&xedd);
  break;
case XED_ICLASS_MOVZX:
  break;
case XED_ICLASS_MOV_CR:
  break;
case XED_ICLASS_MOV_DR:
  break;
case XED_ICLASS_MPSADBW:
  break;
case XED_ICLASS_MUL:
  break;
case XED_ICLASS_MULPD:
  break;
case XED_ICLASS_MULPS:
  translateMULPS(&xedd);
  break;
case XED_ICLASS_MULSD:
  break;
case XED_ICLASS_MULSS:
  translateMULSS(&xedd);
  break;
case XED_ICLASS_MULX:
  break;
case XED_ICLASS_MWAIT:
  break;
case XED_ICLASS_MWAITX:
  break;
case XED_ICLASS_NEG:
  break;
case XED_ICLASS_NEG_LOCK:
  break;
case XED_ICLASS_NOP:
  break;
case XED_ICLASS_NOP2:
  break;
case XED_ICLASS_NOP3:
  break;
case XED_ICLASS_NOP4:
  break;
case XED_ICLASS_NOP5:
  break;
case XED_ICLASS_NOP6:
  break;
case XED_ICLASS_NOP7:
  break;
case XED_ICLASS_NOP8:
  break;
case XED_ICLASS_NOP9:
  break;
case XED_ICLASS_NOT:
  translateNOT(&xedd);
  break;
case XED_ICLASS_NOT_LOCK:
  break;
case XED_ICLASS_OR:
  translateOR(&xedd);
  break;
case XED_ICLASS_ORPD:
  break;
case XED_ICLASS_ORPS:
  break;
case XED_ICLASS_OR_LOCK:
  break;
case XED_ICLASS_OUT:
  break;
case XED_ICLASS_OUTSB:
  break;
case XED_ICLASS_OUTSD:
  break;
case XED_ICLASS_OUTSW:
  break;
case XED_ICLASS_PABSB:
  break;
case XED_ICLASS_PABSD:
  break;
case XED_ICLASS_PABSW:
  break;
case XED_ICLASS_PACKSSDW:
  break;
case XED_ICLASS_PACKSSWB:
  break;
case XED_ICLASS_PACKUSDW:
  break;
case XED_ICLASS_PACKUSWB:
  break;
case XED_ICLASS_PADDB:
  break;
case XED_ICLASS_PADDD:
  translatePADDD(&xedd);
  break;
case XED_ICLASS_PADDQ:
  break;
case XED_ICLASS_PADDSB:
  break;
case XED_ICLASS_PADDSW:
  break;
case XED_ICLASS_PADDUSB:
  break;
case XED_ICLASS_PADDUSW:
  break;
case XED_ICLASS_PADDW:
  break;
case XED_ICLASS_PALIGNR:
  break;
case XED_ICLASS_PAND:
  break;
case XED_ICLASS_PANDN:
  break;
case XED_ICLASS_PAUSE:
  translatePAUSE(&xedd);
  break;
case XED_ICLASS_PAVGB:
  break;
case XED_ICLASS_PAVGUSB:
  break;
case XED_ICLASS_PAVGW:
  break;
case XED_ICLASS_PBLENDVB:
  break;
case XED_ICLASS_PBLENDW:
  break;
case XED_ICLASS_PCLMULQDQ:
  break;
case XED_ICLASS_PCMPEQB:
  break;
case XED_ICLASS_PCMPEQD:
  break;
case XED_ICLASS_PCMPEQQ:
  break;
case XED_ICLASS_PCMPEQW:
  break;
case XED_ICLASS_PCMPESTRI:
  break;
case XED_ICLASS_PCMPESTRI64:
  break;
case XED_ICLASS_PCMPESTRM:
  break;
case XED_ICLASS_PCMPESTRM64:
  break;
case XED_ICLASS_PCMPGTB:
  break;
case XED_ICLASS_PCMPGTD:
  break;
case XED_ICLASS_PCMPGTQ:
  break;
case XED_ICLASS_PCMPGTW:
  break;
case XED_ICLASS_PCMPISTRI:
  break;
case XED_ICLASS_PCMPISTRI64:
  break;
case XED_ICLASS_PCMPISTRM:
  break;
case XED_ICLASS_PCONFIG:
  break;
case XED_ICLASS_PDEP:
  break;
case XED_ICLASS_PEXT:
  break;
case XED_ICLASS_PEXTRB:
  break;
case XED_ICLASS_PEXTRD:
  translatePEXTRD(&xedd);
  break;
case XED_ICLASS_PEXTRQ:
  break;
case XED_ICLASS_PEXTRW:
  break;
case XED_ICLASS_PEXTRW_SSE4:
  break;
case XED_ICLASS_PF2ID:
  break;
case XED_ICLASS_PF2IW:
  break;
case XED_ICLASS_PFACC:
  break;
case XED_ICLASS_PFADD:
  break;
case XED_ICLASS_PFCMPEQ:
  break;
case XED_ICLASS_PFCMPGE:
  break;
case XED_ICLASS_PFCMPGT:
  break;
case XED_ICLASS_PFMAX:
  break;
case XED_ICLASS_PFMIN:
  break;
case XED_ICLASS_PFMUL:
  break;
case XED_ICLASS_PFNACC:
  break;
case XED_ICLASS_PFPNACC:
  break;
case XED_ICLASS_PFRCP:
  break;
case XED_ICLASS_PFRCPIT1:
  break;
case XED_ICLASS_PFRCPIT2:
  break;
case XED_ICLASS_PFRSQIT1:
  break;
case XED_ICLASS_PFRSQRT:
  break;
case XED_ICLASS_PFSUB:
  break;
case XED_ICLASS_PFSUBR:
  break;
case XED_ICLASS_PHADDD:
  break;
case XED_ICLASS_PHADDSW:
  break;
case XED_ICLASS_PHADDW:
  translatePHADDW(&xedd);
  break;
case XED_ICLASS_PHMINPOSUW:
  break;
case XED_ICLASS_PHSUBD:
  break;
case XED_ICLASS_PHSUBSW:
  break;
case XED_ICLASS_PHSUBW:
  break;
case XED_ICLASS_PI2FD:
  break;
case XED_ICLASS_PI2FW:
  break;
case XED_ICLASS_PINSRB:
  translatePINSRB(&xedd);
  break;
case XED_ICLASS_PINSRD:
  translatePINSRD(&xedd);
  break;
case XED_ICLASS_PINSRQ:
  break;
case XED_ICLASS_PINSRW:
  translatePINSRW(&xedd);
  break;
case XED_ICLASS_PMADDUBSW:
  break;
case XED_ICLASS_PMADDWD:
  break;
case XED_ICLASS_PMAXSB:
  break;
case XED_ICLASS_PMAXSD:
  break;
case XED_ICLASS_PMAXSW:
  break;
case XED_ICLASS_PMAXUB:
  break;
case XED_ICLASS_PMAXUD:
  break;
case XED_ICLASS_PMAXUW:
  break;
case XED_ICLASS_PMINSB:
  break;
case XED_ICLASS_PMINSD:
  break;
case XED_ICLASS_PMINSW:
  break;
case XED_ICLASS_PMINUB:
  break;
case XED_ICLASS_PMINUD:
  break;
case XED_ICLASS_PMINUW:
  break;
case XED_ICLASS_PMOVMSKB:
  break;
case XED_ICLASS_PMOVSXBD:
  translatePMOVSXBD(&xedd);
  break;
case XED_ICLASS_PMOVSXBQ:
  break;
case XED_ICLASS_PMOVSXBW:
  translatePMOVSXBW(&xedd);
  break;
case XED_ICLASS_PMOVSXDQ:
  break;
case XED_ICLASS_PMOVSXWD:
  translatePMOVSXWD(&xedd);
  break;
case XED_ICLASS_PMOVSXWQ:
  break;
case XED_ICLASS_PMOVZXBD:
  translatePMOVZXBD(&xedd);
  break;
case XED_ICLASS_PMOVZXBQ:
  break;
case XED_ICLASS_PMOVZXBW:
  translatePMOVZXBW(&xedd);
  break;
case XED_ICLASS_PMOVZXDQ:
  break;
case XED_ICLASS_PMOVZXWD:
  translatePMOVZXWD(&xedd);
  break;
case XED_ICLASS_PMOVZXWQ:
  break;
case XED_ICLASS_PMULDQ:
  break;
case XED_ICLASS_PMULHRSW:
  break;
case XED_ICLASS_PMULHRW:
  break;
case XED_ICLASS_PMULHUW:
  break;
case XED_ICLASS_PMULHW:
  break;
case XED_ICLASS_PMULLD:
  break;
case XED_ICLASS_PMULLW:
  break;
case XED_ICLASS_PMULUDQ:
  break;
case XED_ICLASS_POP:
  break;
case XED_ICLASS_POPA:
  break;
case XED_ICLASS_POPAD:
  break;
case XED_ICLASS_POPCNT:
  break;
case XED_ICLASS_POPF:
  break;
case XED_ICLASS_POPFD:
  break;
case XED_ICLASS_POPFQ:
  break;
case XED_ICLASS_POR:
  break;
case XED_ICLASS_PREFETCHNTA:
  break;
case XED_ICLASS_PREFETCHT0:
  translatePREFETCHT0(&xedd);
  break;
case XED_ICLASS_PREFETCHT1:
  translatePREFETCHT1(&xedd);
  break;
case XED_ICLASS_PREFETCHT2:
  translatePREFETCHT2(&xedd);
  break;
case XED_ICLASS_PREFETCHW:
  translatePREFETCHW(&xedd);
  break;
case XED_ICLASS_PREFETCHWT1:
  break;
case XED_ICLASS_PREFETCH_EXCLUSIVE:
  break;
case XED_ICLASS_PREFETCH_RESERVED:
  break;
case XED_ICLASS_PSADBW:
  break;
case XED_ICLASS_PSHUFB:
  break;
case XED_ICLASS_PSHUFD:
  translatePSHUFD(&xedd);
  break;
case XED_ICLASS_PSHUFHW:
  break;
case XED_ICLASS_PSHUFLW:
  break;
case XED_ICLASS_PSHUFW:
  break;
case XED_ICLASS_PSIGNB:
  break;
case XED_ICLASS_PSIGND:
  break;
case XED_ICLASS_PSIGNW:
  break;
case XED_ICLASS_PSLLD:
  break;
case XED_ICLASS_PSLLDQ:
  break;
case XED_ICLASS_PSLLQ:
  break;
case XED_ICLASS_PSLLW:
  break;
case XED_ICLASS_PSRAD:
  break;
case XED_ICLASS_PSRAW:
  break;
case XED_ICLASS_PSRLD:
  break;
case XED_ICLASS_PSRLDQ:
  break;
case XED_ICLASS_PSRLQ:
  break;
case XED_ICLASS_PSRLW:
  break;
case XED_ICLASS_PSUBB:
  break;
case XED_ICLASS_PSUBD:
  break;
case XED_ICLASS_PSUBQ:
  break;
case XED_ICLASS_PSUBSB:
  break;
case XED_ICLASS_PSUBSW:
  break;
case XED_ICLASS_PSUBUSB:
  break;
case XED_ICLASS_PSUBUSW:
  break;
case XED_ICLASS_PSUBW:
  break;
case XED_ICLASS_PSWAPD:
  break;
case XED_ICLASS_PTEST:
  break;
case XED_ICLASS_PTWRITE:
  break;
case XED_ICLASS_PUNPCKHBW:
  translatePUNPCKHBW(&xedd);
  break;
case XED_ICLASS_PUNPCKHDQ:
  translatePUNPCKHDQ(&xedd);
  break;
case XED_ICLASS_PUNPCKHQDQ:
  translatePUNPCKHQDQ(&xedd);
  break;
case XED_ICLASS_PUNPCKHWD:
  translatePUNPCKHWD(&xedd);
  break;
case XED_ICLASS_PUNPCKLBW:
  translatePUNPCKLBW(&xedd);
  break;
case XED_ICLASS_PUNPCKLDQ:
  translatePUNPCKLDQ(&xedd);
  break;
case XED_ICLASS_PUNPCKLQDQ:
  translatePUNPCKLQDQ(&xedd);
  break;
case XED_ICLASS_PUNPCKLWD:
  translatePUNPCKLWD(&xedd);
  break;
case XED_ICLASS_PUSH:
  break;
case XED_ICLASS_PUSHA:
  break;
case XED_ICLASS_PUSHAD:
  break;
case XED_ICLASS_PUSHF:
  break;
case XED_ICLASS_PUSHFD:
  break;
case XED_ICLASS_PUSHFQ:
  break;
case XED_ICLASS_PXOR:
  translatePXOR(&xedd);
  break;
case XED_ICLASS_RCL:
  break;
case XED_ICLASS_RCPPS:
  break;
case XED_ICLASS_RCPSS:
  break;
case XED_ICLASS_RCR:
  break;
case XED_ICLASS_RDFSBASE:
  break;
case XED_ICLASS_RDGSBASE:
  break;
case XED_ICLASS_RDMSR:
  break;
case XED_ICLASS_RDPID:
  break;
case XED_ICLASS_RDPKRU:
  break;
case XED_ICLASS_RDPMC:
  break;
case XED_ICLASS_RDPRU:
  break;
case XED_ICLASS_RDRAND:
  break;
case XED_ICLASS_RDSEED:
  break;
case XED_ICLASS_RDSSPD:
  break;
case XED_ICLASS_RDSSPQ:
  break;
case XED_ICLASS_RDTSC:
  break;
case XED_ICLASS_RDTSCP:
  break;
case XED_ICLASS_REPE_CMPSB:
  break;
case XED_ICLASS_REPE_CMPSD:
  break;
case XED_ICLASS_REPE_CMPSQ:
  break;
case XED_ICLASS_REPE_CMPSW:
  break;
case XED_ICLASS_REPE_SCASB:
  break;
case XED_ICLASS_REPE_SCASD:
  break;
case XED_ICLASS_REPE_SCASQ:
  break;
case XED_ICLASS_REPE_SCASW:
  break;
case XED_ICLASS_REPNE_CMPSB:
  break;
case XED_ICLASS_REPNE_CMPSD:
  break;
case XED_ICLASS_REPNE_CMPSQ:
  break;
case XED_ICLASS_REPNE_CMPSW:
  break;
case XED_ICLASS_REPNE_SCASB:
  break;
case XED_ICLASS_REPNE_SCASD:
  break;
case XED_ICLASS_REPNE_SCASQ:
  break;
case XED_ICLASS_REPNE_SCASW:
  break;
case XED_ICLASS_REP_INSB:
  break;
case XED_ICLASS_REP_INSD:
  break;
case XED_ICLASS_REP_INSW:
  break;
case XED_ICLASS_REP_LODSB:
  break;
case XED_ICLASS_REP_LODSD:
  break;
case XED_ICLASS_REP_LODSQ:
  break;
case XED_ICLASS_REP_LODSW:
  break;
case XED_ICLASS_REP_MONTMUL:
  break;
case XED_ICLASS_REP_MOVSB:
  break;
case XED_ICLASS_REP_MOVSD:
  break;
case XED_ICLASS_REP_MOVSQ:
  break;
case XED_ICLASS_REP_MOVSW:
  break;
case XED_ICLASS_REP_OUTSB:
  break;
case XED_ICLASS_REP_OUTSD:
  break;
case XED_ICLASS_REP_OUTSW:
  break;
case XED_ICLASS_REP_STOSB:
  break;
case XED_ICLASS_REP_STOSD:
  break;
case XED_ICLASS_REP_STOSQ:
  break;
case XED_ICLASS_REP_STOSW:
  break;
case XED_ICLASS_REP_XCRYPTCBC:
  break;
case XED_ICLASS_REP_XCRYPTCFB:
  break;
case XED_ICLASS_REP_XCRYPTCTR:
  break;
case XED_ICLASS_REP_XCRYPTECB:
  break;
case XED_ICLASS_REP_XCRYPTOFB:
  break;
case XED_ICLASS_REP_XSHA1:
  break;
case XED_ICLASS_REP_XSHA256:
  break;
case XED_ICLASS_REP_XSTORE:
  break;
case XED_ICLASS_RET_FAR:
  translateRET(&xedd);
  break;
case XED_ICLASS_RET_NEAR:
  translateRET(&xedd);
  break;
case XED_ICLASS_ROL:
  break;
case XED_ICLASS_ROR:
  break;
case XED_ICLASS_RORX:
  break;
case XED_ICLASS_ROUNDPD:
  break;
case XED_ICLASS_ROUNDPS:
  break;
case XED_ICLASS_ROUNDSD:
  break;
case XED_ICLASS_ROUNDSS:
  break;
case XED_ICLASS_RSM:
  break;
case XED_ICLASS_RSQRTPS:
  break;
case XED_ICLASS_RSQRTSS:
  break;
case XED_ICLASS_RSTORSSP:
  break;
case XED_ICLASS_SAHF:
  break;
case XED_ICLASS_SALC:
  break;
case XED_ICLASS_SAR:
  translateSAR(&xedd);
  break;
case XED_ICLASS_SARX:
  break;
case XED_ICLASS_SAVEPREVSSP:
  break;
case XED_ICLASS_SBB:
  break;
case XED_ICLASS_SBB_LOCK:
  break;
case XED_ICLASS_SCASB:
  break;
case XED_ICLASS_SCASD:
  break;
case XED_ICLASS_SCASQ:
  break;
case XED_ICLASS_SCASW:
  break;
case XED_ICLASS_SETB:
  break;
case XED_ICLASS_SETBE:
  break;
case XED_ICLASS_SETL:
  break;
case XED_ICLASS_SETLE:
  break;
case XED_ICLASS_SETNB:
  break;
case XED_ICLASS_SETNBE:
  break;
case XED_ICLASS_SETNL:
  break;
case XED_ICLASS_SETNLE:
  break;
case XED_ICLASS_SETNO:
  break;
case XED_ICLASS_SETNP:
  break;
case XED_ICLASS_SETNS:
  break;
case XED_ICLASS_SETNZ:
  break;
case XED_ICLASS_SETO:
  break;
case XED_ICLASS_SETP:
  break;
case XED_ICLASS_SETS:
  break;
case XED_ICLASS_SETSSBSY:
  break;
case XED_ICLASS_SETZ:
  break;
case XED_ICLASS_SFENCE:
  break;
case XED_ICLASS_SGDT:
  break;
case XED_ICLASS_SHA1MSG1:
  break;
case XED_ICLASS_SHA1MSG2:
  break;
case XED_ICLASS_SHA1NEXTE:
  break;
case XED_ICLASS_SHA1RNDS4:
  break;
case XED_ICLASS_SHA256MSG1:
  break;
case XED_ICLASS_SHA256MSG2:
  break;
case XED_ICLASS_SHA256RNDS2:
  break;
case XED_ICLASS_SHL:
  translateSHL(&xedd);
  break;
case XED_ICLASS_SHLD:
  break;
case XED_ICLASS_SHLX:
  translateSHLX(&xedd);
  break;
case XED_ICLASS_SHR:
  translateSHR(&xedd);
  break;
case XED_ICLASS_SHRD:
  break;
case XED_ICLASS_SHRX:
  break;
case XED_ICLASS_SHUFPD:
  break;
case XED_ICLASS_SHUFPS:
  translateSHUFPS(&xedd);
  break;
case XED_ICLASS_SIDT:
  break;
case XED_ICLASS_SKINIT:
  break;
case XED_ICLASS_SLDT:
  break;
case XED_ICLASS_SLWPCB:
  break;
case XED_ICLASS_SMSW:
  break;
case XED_ICLASS_SQRTPD:
  break;
case XED_ICLASS_SQRTPS:
  break;
case XED_ICLASS_SQRTSD:
  break;
case XED_ICLASS_SQRTSS:
  break;
case XED_ICLASS_STAC:
  break;
case XED_ICLASS_STC:
  break;
case XED_ICLASS_STD:
  break;
case XED_ICLASS_STGI:
  break;
case XED_ICLASS_STI:
  break;
case XED_ICLASS_STMXCSR:
  break;
case XED_ICLASS_STOSB:
  break;
case XED_ICLASS_STOSD:
  break;
case XED_ICLASS_STOSQ:
  break;
case XED_ICLASS_STOSW:
  break;
case XED_ICLASS_STR:
  break;
case XED_ICLASS_SUB:
  translateSUB(&xedd);
  break;
case XED_ICLASS_SUBPD:
  break;
case XED_ICLASS_SUBPS:
  translateSUBPS(&xedd);
  break;
case XED_ICLASS_SUBSD:
  break;
case XED_ICLASS_SUBSS:
  break;
case XED_ICLASS_SUB_LOCK:
  break;
case XED_ICLASS_SWAPGS:
  break;
case XED_ICLASS_SYSCALL:
  break;
case XED_ICLASS_SYSCALL_AMD:
  break;
case XED_ICLASS_SYSENTER:
  break;
case XED_ICLASS_SYSEXIT:
  break;
case XED_ICLASS_SYSRET:
  break;
case XED_ICLASS_SYSRET64:
  break;
case XED_ICLASS_SYSRET_AMD:
  break;
case XED_ICLASS_T1MSKC:
  break;
case XED_ICLASS_TEST:
  translateTEST(&xedd);
  break;
case XED_ICLASS_TPAUSE:
  break;
case XED_ICLASS_TZCNT:
  break;
case XED_ICLASS_TZMSK:
  break;
case XED_ICLASS_UCOMISD:
  break;
case XED_ICLASS_UCOMISS:
  break;
case XED_ICLASS_UD0:
  break;
case XED_ICLASS_UD1:
  break;
case XED_ICLASS_UD2:
  break;
case XED_ICLASS_UMONITOR:
  break;
case XED_ICLASS_UMWAIT:
  break;
case XED_ICLASS_UNPCKHPD:
  break;
case XED_ICLASS_UNPCKHPS:
  break;
case XED_ICLASS_UNPCKLPD:
  break;
case XED_ICLASS_UNPCKLPS:
  break;
case XED_ICLASS_V4FMADDPS:
  break;
case XED_ICLASS_V4FMADDSS:
  break;
case XED_ICLASS_V4FNMADDPS:
  break;
case XED_ICLASS_V4FNMADDSS:
  break;
case XED_ICLASS_VADDPD:
  break;
case XED_ICLASS_VADDPS:
  translateVADDPS(&xedd);
  break;
case XED_ICLASS_VADDSD:
  break;
case XED_ICLASS_VADDSS:
  translateVADDSS(&xedd);
  break;
case XED_ICLASS_VADDSUBPD:
  break;
case XED_ICLASS_VADDSUBPS:
  break;
case XED_ICLASS_VAESDEC:
  break;
case XED_ICLASS_VAESDECLAST:
  break;
case XED_ICLASS_VAESENC:
  break;
case XED_ICLASS_VAESENCLAST:
  break;
case XED_ICLASS_VAESIMC:
  break;
case XED_ICLASS_VAESKEYGENASSIST:
  break;
case XED_ICLASS_VALIGND:
  break;
case XED_ICLASS_VALIGNQ:
  break;
case XED_ICLASS_VANDNPD:
  break;
case XED_ICLASS_VANDNPS:
  break;
case XED_ICLASS_VANDPD:
  break;
case XED_ICLASS_VANDPS:
  translateVANDPS(&xedd);
  break;
case XED_ICLASS_VBLENDMPD:
  break;
case XED_ICLASS_VBLENDMPS:
  translateVBLENDMPS(&xedd);
  break;
case XED_ICLASS_VBLENDPD:
  break;
case XED_ICLASS_VBLENDPS:
  break;
case XED_ICLASS_VBLENDVPD:
  break;
case XED_ICLASS_VBLENDVPS:
  translateVBLENDVPS(&xedd);
  break;
case XED_ICLASS_VBROADCASTF128:
  break;
case XED_ICLASS_VBROADCASTF32X2:
  break;
case XED_ICLASS_VBROADCASTF32X4:
  translateVBROADCASTF32X4(&xedd);
  break;
case XED_ICLASS_VBROADCASTF32X8:
  break;
case XED_ICLASS_VBROADCASTF64X2:
  break;
case XED_ICLASS_VBROADCASTF64X4:
  translateVBROADCASTF64X4(&xedd);
  break;
case XED_ICLASS_VBROADCASTI128:
  break;
case XED_ICLASS_VBROADCASTI32X2:
  break;
case XED_ICLASS_VBROADCASTI32X4:
  translateVBROADCASTI32X4(&xedd);
  break;
case XED_ICLASS_VBROADCASTI32X8:
  break;
case XED_ICLASS_VBROADCASTI64X2:
  break;
case XED_ICLASS_VBROADCASTI64X4:
  translateVBROADCASTI64X4(&xedd);
  break;
case XED_ICLASS_VBROADCASTSD:
  translateVBROADCASTSD(&xedd);
  break;
case XED_ICLASS_VBROADCASTSS:
  translateVBROADCASTSS(&xedd);
  break;
case XED_ICLASS_VCMPPD:
  break;
case XED_ICLASS_VCMPPS:
  translateVCMPPS(&xedd);
  break;
case XED_ICLASS_VCMPSD:
  break;
case XED_ICLASS_VCMPSS:
  break;
case XED_ICLASS_VCOMISD:
  break;
case XED_ICLASS_VCOMISS:
  break;
case XED_ICLASS_VCOMPRESSPD:
  break;
case XED_ICLASS_VCOMPRESSPS:
  break;
case XED_ICLASS_VCVTDQ2PD:
  break;
case XED_ICLASS_VCVTDQ2PS:
  translateVCVTDQ2PS(&xedd);
  break;
case XED_ICLASS_VCVTNE2PS2BF16:
  break;
case XED_ICLASS_VCVTNEPS2BF16:
  break;
case XED_ICLASS_VCVTPD2DQ:
  break;
case XED_ICLASS_VCVTPD2PS:
  break;
case XED_ICLASS_VCVTPD2QQ:
  break;
case XED_ICLASS_VCVTPD2UDQ:
  break;
case XED_ICLASS_VCVTPD2UQQ:
  break;
case XED_ICLASS_VCVTPH2PS:
  break;
case XED_ICLASS_VCVTPS2DQ:
  translateVCVTPS2DQ(&xedd);
  break;
case XED_ICLASS_VCVTPS2PD:
  break;
case XED_ICLASS_VCVTPS2PH:
  break;
case XED_ICLASS_VCVTPS2QQ:
  break;
case XED_ICLASS_VCVTPS2UDQ:
  break;
case XED_ICLASS_VCVTPS2UQQ:
  break;
case XED_ICLASS_VCVTQQ2PD:
  break;
case XED_ICLASS_VCVTQQ2PS:
  break;
case XED_ICLASS_VCVTSD2SI:
  break;
case XED_ICLASS_VCVTSD2SS:
  break;
case XED_ICLASS_VCVTSD2USI:
  break;
case XED_ICLASS_VCVTSI2SD:
  break;
case XED_ICLASS_VCVTSI2SS:
  break;
case XED_ICLASS_VCVTSS2SD:
  break;
case XED_ICLASS_VCVTSS2SI:
  break;
case XED_ICLASS_VCVTSS2USI:
  break;
case XED_ICLASS_VCVTTPD2DQ:
  break;
case XED_ICLASS_VCVTTPD2QQ:
  break;
case XED_ICLASS_VCVTTPD2UDQ:
  break;
case XED_ICLASS_VCVTTPD2UQQ:
  break;
case XED_ICLASS_VCVTTPS2DQ:
  break;
case XED_ICLASS_VCVTTPS2QQ:
  break;
case XED_ICLASS_VCVTTPS2UDQ:
  break;
case XED_ICLASS_VCVTTPS2UQQ:
  break;
case XED_ICLASS_VCVTTSD2SI:
  break;
case XED_ICLASS_VCVTTSD2USI:
  break;
case XED_ICLASS_VCVTTSS2SI:
  break;
case XED_ICLASS_VCVTTSS2USI:
  break;
case XED_ICLASS_VCVTUDQ2PD:
  break;
case XED_ICLASS_VCVTUDQ2PS:
  break;
case XED_ICLASS_VCVTUQQ2PD:
  break;
case XED_ICLASS_VCVTUQQ2PS:
  break;
case XED_ICLASS_VCVTUSI2SD:
  break;
case XED_ICLASS_VCVTUSI2SS:
  break;
case XED_ICLASS_VDBPSADBW:
  break;
case XED_ICLASS_VDIVPD:
  break;
case XED_ICLASS_VDIVPS:
  translateVDIVPS(&xedd);
  break;
case XED_ICLASS_VDIVSD:
  break;
case XED_ICLASS_VDIVSS:
  break;
case XED_ICLASS_VDPBF16PS:
  break;
case XED_ICLASS_VDPPD:
  break;
case XED_ICLASS_VDPPS:
  break;
case XED_ICLASS_VERR:
  break;
case XED_ICLASS_VERW:
  break;
case XED_ICLASS_VEXP2PD:
  break;
case XED_ICLASS_VEXP2PS:
  break;
case XED_ICLASS_VEXPANDPD:
  break;
case XED_ICLASS_VEXPANDPS:
  break;
case XED_ICLASS_VEXTRACTF128:
  break;
case XED_ICLASS_VEXTRACTF32X4:
  break;
case XED_ICLASS_VEXTRACTF32X8:
  break;
case XED_ICLASS_VEXTRACTF64X2:
  break;
case XED_ICLASS_VEXTRACTF64X4:
  translateVEXTRACTF64X4(&xedd);
  break;
case XED_ICLASS_VEXTRACTI128:
  break;
case XED_ICLASS_VEXTRACTI32X4:
  break;
case XED_ICLASS_VEXTRACTI32X8:
  translateVEXTRACTI32X8(&xedd);
  break;
case XED_ICLASS_VEXTRACTI64X2:
  break;
case XED_ICLASS_VEXTRACTI64X4:
  break;
case XED_ICLASS_VEXTRACTPS:
  break;
case XED_ICLASS_VFIXUPIMMPD:
  break;
case XED_ICLASS_VFIXUPIMMPS:
  translateVFIXUPIMMPS(&xedd);
  break;
case XED_ICLASS_VFIXUPIMMSD:
  break;
case XED_ICLASS_VFIXUPIMMSS:
  break;
case XED_ICLASS_VFMADD132PD:
  break;
case XED_ICLASS_VFMADD132PS:
  translateVFMADD132PS(&xedd);
  break;
case XED_ICLASS_VFMADD132SD:
  break;
case XED_ICLASS_VFMADD132SS:
  break;
case XED_ICLASS_VFMADD213PD:
  break;
case XED_ICLASS_VFMADD213PS:
  translateVFMADD213PS(&xedd);
  break;
case XED_ICLASS_VFMADD213SD:
  break;
case XED_ICLASS_VFMADD213SS:
  break;
case XED_ICLASS_VFMADD231PD:
  break;
case XED_ICLASS_VFMADD231PS:
  translateVFMADD231PS(&xedd);
  break;
case XED_ICLASS_VFMADD231SD:
  break;
case XED_ICLASS_VFMADD231SS:
  break;

case XED_ICLASS_VFMADDPD:
  break;
case XED_ICLASS_VFMADDPS:
  break;
case XED_ICLASS_VFMADDSD:
  break;
case XED_ICLASS_VFMADDSS:
  break;
case XED_ICLASS_VFMADDSUB132PD:
  break;
case XED_ICLASS_VFMADDSUB132PS:
  break;
case XED_ICLASS_VFMADDSUB213PD:
  break;
case XED_ICLASS_VFMADDSUB213PS:
  break;
case XED_ICLASS_VFMADDSUB231PD:
  break;
case XED_ICLASS_VFMADDSUB231PS:
  break;
case XED_ICLASS_VFMADDSUBPD:
  break;
case XED_ICLASS_VFMADDSUBPS:
  break;
case XED_ICLASS_VFMSUB132PD:
  break;
case XED_ICLASS_VFMSUB132PS:
  break;
case XED_ICLASS_VFMSUB132SD:
  break;
case XED_ICLASS_VFMSUB132SS:
  break;
case XED_ICLASS_VFMSUB213PD:
  break;
case XED_ICLASS_VFMSUB213PS:
  break;
case XED_ICLASS_VFMSUB213SD:
  break;
case XED_ICLASS_VFMSUB213SS:
  break;
case XED_ICLASS_VFMSUB231PD:
  break;
case XED_ICLASS_VFMSUB231PS:
  break;
case XED_ICLASS_VFMSUB231SD:
  break;
case XED_ICLASS_VFMSUB231SS:
  break;
case XED_ICLASS_VFMSUBADD132PD:
  break;
case XED_ICLASS_VFMSUBADD132PS:
  break;
case XED_ICLASS_VFMSUBADD213PD:
  break;
case XED_ICLASS_VFMSUBADD213PS:
  break;
case XED_ICLASS_VFMSUBADD231PD:
  break;
case XED_ICLASS_VFMSUBADD231PS:
  break;
case XED_ICLASS_VFMSUBADDPD:
  break;
case XED_ICLASS_VFMSUBADDPS:
  break;
case XED_ICLASS_VFMSUBPD:
  break;
case XED_ICLASS_VFMSUBPS:
  break;
case XED_ICLASS_VFMSUBSD:
  break;
case XED_ICLASS_VFMSUBSS:
  break;
case XED_ICLASS_VFNMADD132PD:
  break;
case XED_ICLASS_VFNMADD132PS:
  break;
case XED_ICLASS_VFNMADD132SD:
  break;
case XED_ICLASS_VFNMADD132SS:
  break;
case XED_ICLASS_VFNMADD213PD:
  break;
case XED_ICLASS_VFNMADD213PS:
  break;
case XED_ICLASS_VFNMADD213SD:
  break;
case XED_ICLASS_VFNMADD213SS:
  break;
case XED_ICLASS_VFNMADD231PD:
  break;
case XED_ICLASS_VFNMADD231PS:
  translateVFNMADD231PS(&xedd);
  break;
case XED_ICLASS_VFNMADD231SD:
  break;
case XED_ICLASS_VFNMADD231SS:
  break;
case XED_ICLASS_VFNMADDPD:
  break;
case XED_ICLASS_VFNMADDPS:
  break;
case XED_ICLASS_VFNMADDSD:
  break;
case XED_ICLASS_VFNMADDSS:
  break;
case XED_ICLASS_VFNMSUB132PD:
  break;
case XED_ICLASS_VFNMSUB132PS:
  break;
case XED_ICLASS_VFNMSUB132SD:
  break;
case XED_ICLASS_VFNMSUB132SS:
  break;
case XED_ICLASS_VFNMSUB213PD:
  break;
case XED_ICLASS_VFNMSUB213PS:
  break;
case XED_ICLASS_VFNMSUB213SD:
  break;
case XED_ICLASS_VFNMSUB213SS:
  break;
case XED_ICLASS_VFNMSUB231PD:
  break;
case XED_ICLASS_VFNMSUB231PS:
  break;
case XED_ICLASS_VFNMSUB231SD:
  break;
case XED_ICLASS_VFNMSUB231SS:
  break;
case XED_ICLASS_VFNMSUBPD:
  break;
case XED_ICLASS_VFNMSUBPS:
  break;
case XED_ICLASS_VFNMSUBSD:
  break;
case XED_ICLASS_VFNMSUBSS:
  break;
case XED_ICLASS_VFPCLASSPD:
  break;
case XED_ICLASS_VFPCLASSPS:
  break;
case XED_ICLASS_VFPCLASSSD:
  break;
case XED_ICLASS_VFPCLASSSS:
  break;
case XED_ICLASS_VFRCZPD:
  break;
case XED_ICLASS_VFRCZPS:
  break;
case XED_ICLASS_VFRCZSD:
  break;
case XED_ICLASS_VFRCZSS:
  break;
case XED_ICLASS_VGATHERDPD:
  break;
case XED_ICLASS_VGATHERDPS:
  break;
case XED_ICLASS_VGATHERPF0DPD:
  break;
case XED_ICLASS_VGATHERPF0DPS:
  break;
case XED_ICLASS_VGATHERPF0QPD:
  break;
case XED_ICLASS_VGATHERPF0QPS:
  break;
case XED_ICLASS_VGATHERPF1DPD:
  break;
case XED_ICLASS_VGATHERPF1DPS:
  break;
case XED_ICLASS_VGATHERPF1QPD:
  break;
case XED_ICLASS_VGATHERPF1QPS:
  break;
case XED_ICLASS_VGATHERQPD:
  break;
case XED_ICLASS_VGATHERQPS:
  translateVGATHERQPS(&xedd);
  break;
case XED_ICLASS_VGETEXPPD:
  break;
case XED_ICLASS_VGETEXPPS:
  break;
case XED_ICLASS_VGETEXPSD:
  break;
case XED_ICLASS_VGETEXPSS:
  break;
case XED_ICLASS_VGETMANTPD:
  break;
case XED_ICLASS_VGETMANTPS:
  break;
case XED_ICLASS_VGETMANTSD:
  break;
case XED_ICLASS_VGETMANTSS:
  break;
case XED_ICLASS_VGF2P8AFFINEINVQB:
  break;
case XED_ICLASS_VGF2P8AFFINEQB:
  break;
case XED_ICLASS_VGF2P8MULB:
  break;
case XED_ICLASS_VHADDPD:
  break;
case XED_ICLASS_VHADDPS:
  break;
case XED_ICLASS_VHSUBPD:
  break;
case XED_ICLASS_VHSUBPS:
  break;
case XED_ICLASS_VINSERTF128:
  translateVINSERTF128(&xedd);
  break;
case XED_ICLASS_VINSERTF32X4:
  break;
case XED_ICLASS_VINSERTF32X8:
  break;
case XED_ICLASS_VINSERTF64X2:
  break;
case XED_ICLASS_VINSERTF64X4:
  translateVINSERTF64X4(&xedd);
  break;
case XED_ICLASS_VINSERTI128:
  break;
case XED_ICLASS_VINSERTI32X4:
  translateVINSERTI32X4(&xedd);
  break;
case XED_ICLASS_VINSERTI32X8:
  break;
case XED_ICLASS_VINSERTI64X2:
  break;
case XED_ICLASS_VINSERTI64X4:
  translateVINSERTI64X4(&xedd);
  break;
case XED_ICLASS_VINSERTPS:
  break;
case XED_ICLASS_VLDDQU:
  break;
case XED_ICLASS_VLDMXCSR:
  break;
case XED_ICLASS_VMASKMOVDQU:
  break;
case XED_ICLASS_VMASKMOVPD:
  break;
case XED_ICLASS_VMASKMOVPS:
  translateVMASKMOVPS(&xedd);
  break;
case XED_ICLASS_VMAXPD:
  break;
case XED_ICLASS_VMAXPS:
  translateVMAXPS(&xedd);
  break;
case XED_ICLASS_VMAXSD:
  break;
case XED_ICLASS_VMAXSS:
  break;
case XED_ICLASS_VMCALL:
  break;
case XED_ICLASS_VMCLEAR:
  break;
case XED_ICLASS_VMFUNC:
  break;
case XED_ICLASS_VMINPD:
  break;
case XED_ICLASS_VMINPS:
  translateVMINPS(&xedd);
  break;
case XED_ICLASS_VMINSD:
  break;
case XED_ICLASS_VMINSS:
  break;
case XED_ICLASS_VMLAUNCH:
  break;
case XED_ICLASS_VMLOAD:
  break;
case XED_ICLASS_VMMCALL:
  break;
case XED_ICLASS_VMOVAPD:
  break;
case XED_ICLASS_VMOVAPS:
  translateVMOVAPS(&xedd);
  break;
case XED_ICLASS_VMOVD:
  translateVMOVD(&xedd);
  break;
case XED_ICLASS_VMOVDDUP:
  break;
case XED_ICLASS_VMOVDQA:
  break;
case XED_ICLASS_VMOVDQA32:
  break;
case XED_ICLASS_VMOVDQA64:
  break;
case XED_ICLASS_VMOVDQU:
  translateVMOVDQU(&xedd);
  break;
case XED_ICLASS_VMOVDQU16:
  translateVMOVDQU16(&xedd);
  break;
case XED_ICLASS_VMOVDQU32:
  translateVMOVDQU32(&xedd);
  break;
case XED_ICLASS_VMOVDQU64:
  break;
case XED_ICLASS_VMOVDQU8:
  translateVMOVDQU8(&xedd);
  break;
case XED_ICLASS_VMOVHLPS:
  translateVMOVHLPS(&xedd);
  break;
case XED_ICLASS_VMOVHPD:
  break;
case XED_ICLASS_VMOVHPS:
  translateVMOVHPS(&xedd);
  break;
case XED_ICLASS_VMOVLHPS:
  break;
case XED_ICLASS_VMOVLPD:
  break;
case XED_ICLASS_VMOVLPS:
  translateVMOVLPS(&xedd);
  break;
case XED_ICLASS_VMOVMSKPD:
  break;
case XED_ICLASS_VMOVMSKPS:
  translateVMOVMSKPS(&xedd);
  break;
case XED_ICLASS_VMOVNTDQ:
  break;
case XED_ICLASS_VMOVNTDQA:
  break;
case XED_ICLASS_VMOVNTPD:
  break;
case XED_ICLASS_VMOVNTPS:
  translateVMOVNTPS(&xedd);
  break;
case XED_ICLASS_VMOVQ:
  translateVMOVQ(&xedd);
  break;
case XED_ICLASS_VMOVSD:
  translateVMOVSD(&xedd);
  break;
case XED_ICLASS_VMOVSHDUP:
  break;
case XED_ICLASS_VMOVSLDUP:
  break;
case XED_ICLASS_VMOVSS:
  translateVMOVSS(&xedd);
  break;
case XED_ICLASS_VMOVUPD:
  break;
case XED_ICLASS_VMOVUPS:
  translateVMOVUPS(&xedd);
  break;
case XED_ICLASS_VMPSADBW:
  break;
case XED_ICLASS_VMPTRLD:
  break;
case XED_ICLASS_VMPTRST:
  break;
case XED_ICLASS_VMREAD:
  break;
case XED_ICLASS_VMRESUME:
  break;
case XED_ICLASS_VMRUN:
  break;
case XED_ICLASS_VMSAVE:
  break;
case XED_ICLASS_VMULPD:
  break;
case XED_ICLASS_VMULPS:
  translateVMULPS(&xedd);
  break;
case XED_ICLASS_VMULSD:
  break;
case XED_ICLASS_VMULSS:
  translateVMULSS(&xedd);
  break;
case XED_ICLASS_VMWRITE:
  break;
case XED_ICLASS_VMXOFF:
  break;
case XED_ICLASS_VMXON:
  break;
case XED_ICLASS_VORPD:
  break;
case XED_ICLASS_VORPS:
  translateVORPS(&xedd);
  break;
case XED_ICLASS_VP2INTERSECTD:
  break;
case XED_ICLASS_VP2INTERSECTQ:
  break;
case XED_ICLASS_VP4DPWSSD:
  break;
case XED_ICLASS_VP4DPWSSDS:
  break;
case XED_ICLASS_VPABSB:
  break;
case XED_ICLASS_VPABSD:
  break;
case XED_ICLASS_VPABSQ:
  break;
case XED_ICLASS_VPABSW:
  break;
case XED_ICLASS_VPACKSSDW:
  break;
case XED_ICLASS_VPACKSSWB:
  break;
case XED_ICLASS_VPACKUSDW:
  break;
case XED_ICLASS_VPACKUSWB:
  break;
case XED_ICLASS_VPADDB:
  translateVPADDB(&xedd);
  break;
case XED_ICLASS_VPADDD:
  translateVPADDD(&xedd);
  break;
case XED_ICLASS_VPADDQ:
  translateVPADDQ(&xedd);
  break;
case XED_ICLASS_VPADDSB:
  break;
case XED_ICLASS_VPADDSW:
  break;
case XED_ICLASS_VPADDUSB:
  break;
case XED_ICLASS_VPADDUSW:
  break;
case XED_ICLASS_VPADDW:
  break;
case XED_ICLASS_VPALIGNR:
  break;
case XED_ICLASS_VPAND:
  break;
case XED_ICLASS_VPANDD:
  translateVPANDD(&xedd);
  break;
case XED_ICLASS_VPANDN:
  break;
case XED_ICLASS_VPANDND:
  break;
case XED_ICLASS_VPANDNQ:
  break;
case XED_ICLASS_VPANDQ:
  break;
case XED_ICLASS_VPAVGB:
  break;
case XED_ICLASS_VPAVGW:
  break;
case XED_ICLASS_VPBLENDD:
  break;
case XED_ICLASS_VPBLENDMB:
  translateVPBLENDMB(&xedd);
  break;
case XED_ICLASS_VPBLENDMD:
  translateVPBLENDMD(&xedd);
  break;
case XED_ICLASS_VPBLENDMQ:
  break;
case XED_ICLASS_VPBLENDMW:
  break;
case XED_ICLASS_VPBLENDVB:
  break;
case XED_ICLASS_VPBLENDW:
  break;
case XED_ICLASS_VPBROADCASTB:
  translateVPBROADCASTB(&xedd);
  break;
case XED_ICLASS_VPBROADCASTD:
  translateVPBROADCASTD(&xedd);
  break;
case XED_ICLASS_VPBROADCASTMB2Q:
  break;
case XED_ICLASS_VPBROADCASTMW2D:
  break;
case XED_ICLASS_VPBROADCASTQ:
  translateVPBROADCASTQ(&xedd);
  break;
case XED_ICLASS_VPBROADCASTW:
  translateVPBROADCASTW(&xedd);
  break;
case XED_ICLASS_VPCLMULQDQ:
  break;
case XED_ICLASS_VPCMOV:
  break;
case XED_ICLASS_VPCMPB:
  translateVPCMPB(&xedd);
  break;
case XED_ICLASS_VPCMPD:
  translateVPCMPD(&xedd);
  break;
case XED_ICLASS_VPCMPEQB:
  translateVPCMPEQB(&xedd);
  break;
case XED_ICLASS_VPCMPEQD:
  translateVPCMPEQD(&xedd);
  break;
case XED_ICLASS_VPCMPEQQ:
  break;
case XED_ICLASS_VPCMPEQW:
  break;
case XED_ICLASS_VPCMPESTRI:
  break;
case XED_ICLASS_VPCMPESTRI64:
  break;
case XED_ICLASS_VPCMPESTRM:
  break;
case XED_ICLASS_VPCMPESTRM64:
  break;
case XED_ICLASS_VPCMPGTB:
  break;
case XED_ICLASS_VPCMPGTD:
  break;
case XED_ICLASS_VPCMPGTQ:
  break;
case XED_ICLASS_VPCMPGTW:
  break;
case XED_ICLASS_VPCMPISTRI:
  break;
case XED_ICLASS_VPCMPISTRI64:
  break;
case XED_ICLASS_VPCMPISTRM:
  break;
case XED_ICLASS_VPCMPQ:
  break;
case XED_ICLASS_VPCMPUB:
  translateVPCMPUB(&xedd);
  break;
case XED_ICLASS_VPCMPUD:
  break;
case XED_ICLASS_VPCMPUQ:
  break;
case XED_ICLASS_VPCMPUW:
  break;
case XED_ICLASS_VPCMPW:
  break;
case XED_ICLASS_VPCOMB:
  break;
case XED_ICLASS_VPCOMD:
  break;
case XED_ICLASS_VPCOMPRESSB:
  break;
case XED_ICLASS_VPCOMPRESSD:
  break;
case XED_ICLASS_VPCOMPRESSQ:
  break;
case XED_ICLASS_VPCOMPRESSW:
  break;
case XED_ICLASS_VPCOMQ:
  break;
case XED_ICLASS_VPCOMUB:
  break;
case XED_ICLASS_VPCOMUD:
  break;
case XED_ICLASS_VPCOMUQ:
  break;
case XED_ICLASS_VPCOMUW:
  break;
case XED_ICLASS_VPCOMW:
  break;
case XED_ICLASS_VPCONFLICTD:
  break;
case XED_ICLASS_VPCONFLICTQ:
  break;
case XED_ICLASS_VPDPBUSD:
  translateVPDPBUSD(&xedd);
  break;
case XED_ICLASS_VPDPBUSDS:
  break;
case XED_ICLASS_VPDPWSSD:
  break;
case XED_ICLASS_VPDPWSSDS:
  break;
case XED_ICLASS_VPERM2F128:
  translateVPERM2F128(&xedd);
  break;
case XED_ICLASS_VPERM2I128:
  translateVPERM2I128(&xedd);
  break;
case XED_ICLASS_VPERMB:
  break;
case XED_ICLASS_VPERMD:
  translateVPERMD(&xedd);
  break;
case XED_ICLASS_VPERMI2B:
  break;
case XED_ICLASS_VPERMI2D:
  break;
case XED_ICLASS_VPERMI2PD:
  break;
case XED_ICLASS_VPERMI2PS:
  break;
case XED_ICLASS_VPERMI2Q:
  break;
case XED_ICLASS_VPERMI2W:
  break;
case XED_ICLASS_VPERMIL2PD:
  break;
case XED_ICLASS_VPERMIL2PS:
  break;
case XED_ICLASS_VPERMILPD:
  translateVPERMILPD(&xedd);
  break;
case XED_ICLASS_VPERMILPS:
  translateVPERMILPS(&xedd);
  break;
case XED_ICLASS_VPERMPD:
  break;
case XED_ICLASS_VPERMPS:
  break;
case XED_ICLASS_VPERMQ:
  break;
case XED_ICLASS_VPERMT2B:
  break;
case XED_ICLASS_VPERMT2D:
  break;
case XED_ICLASS_VPERMT2PD:
  break;
case XED_ICLASS_VPERMT2PS:
  break;
case XED_ICLASS_VPERMT2Q:
  break;
case XED_ICLASS_VPERMT2W:
  break;
case XED_ICLASS_VPERMW:
  translateVPERMW(&xedd);
  break;
case XED_ICLASS_VPEXPANDB:
  break;
case XED_ICLASS_VPEXPANDD:
  break;
case XED_ICLASS_VPEXPANDQ:
  break;
case XED_ICLASS_VPEXPANDW:
  break;
case XED_ICLASS_VPEXTRB:
  translateVPEXTRB(&xedd);
  break;
case XED_ICLASS_VPEXTRD:
  break;
case XED_ICLASS_VPEXTRQ:
  break;
case XED_ICLASS_VPEXTRW:
  break;
case XED_ICLASS_VPEXTRW_C5:
  break;
case XED_ICLASS_VPGATHERDD:
  break;
case XED_ICLASS_VPGATHERDQ:
  break;
case XED_ICLASS_VPGATHERQD:
  break;
case XED_ICLASS_VPGATHERQQ:
  break;
case XED_ICLASS_VPHADDBD:
  break;
case XED_ICLASS_VPHADDBQ:
  break;
case XED_ICLASS_VPHADDBW:
  break;
case XED_ICLASS_VPHADDD:
  translateVPHADDD(&xedd);
  break;
case XED_ICLASS_VPHADDDQ:
  break;
case XED_ICLASS_VPHADDSW:
  break;
case XED_ICLASS_VPHADDUBD:
  break;
case XED_ICLASS_VPHADDUBQ:
  break;
case XED_ICLASS_VPHADDUBW:
  break;
case XED_ICLASS_VPHADDUDQ:
  break;
case XED_ICLASS_VPHADDUWD:
  break;
case XED_ICLASS_VPHADDUWQ:
  break;
case XED_ICLASS_VPHADDW:
  translateVPHADDW(&xedd);
  break;
case XED_ICLASS_VPHADDWD:
  break;
case XED_ICLASS_VPHADDWQ:
  break;
case XED_ICLASS_VPHMINPOSUW:
  break;
case XED_ICLASS_VPHSUBBW:
  break;
case XED_ICLASS_VPHSUBD:
  break;
case XED_ICLASS_VPHSUBDQ:
  break;
case XED_ICLASS_VPHSUBSW:
  break;
case XED_ICLASS_VPHSUBW:
  break;
case XED_ICLASS_VPHSUBWD:
  break;
case XED_ICLASS_VPINSRB:
  translateVPINSRB(&xedd);
  break;
case XED_ICLASS_VPINSRD:
  break;
case XED_ICLASS_VPINSRQ:
  translateVPINSRQ(&xedd);
  break;
case XED_ICLASS_VPINSRW:
  translateVPINSRW(&xedd);
  break;
case XED_ICLASS_VPLZCNTD:
  break;
case XED_ICLASS_VPLZCNTQ:
  break;
case XED_ICLASS_VPMACSDD:
  break;
case XED_ICLASS_VPMACSDQH:
  break;
case XED_ICLASS_VPMACSDQL:
  break;
case XED_ICLASS_VPMACSSDD:
  break;
case XED_ICLASS_VPMACSSDQH:
  break;
case XED_ICLASS_VPMACSSDQL:
  break;
case XED_ICLASS_VPMACSSWD:
  break;
case XED_ICLASS_VPMACSSWW:
  break;
case XED_ICLASS_VPMACSWD:
  break;
case XED_ICLASS_VPMACSWW:
  break;
case XED_ICLASS_VPMADCSSWD:
  break;
case XED_ICLASS_VPMADCSWD:
  break;
case XED_ICLASS_VPMADD52HUQ:
  break;
case XED_ICLASS_VPMADD52LUQ:
  break;
case XED_ICLASS_VPMADDUBSW:
  translateVPMADDUBSW(&xedd);
  break;
case XED_ICLASS_VPMADDWD:
  translateVPMADDWD(&xedd);
  break;
case XED_ICLASS_VPMASKMOVD:
  break;
case XED_ICLASS_VPMASKMOVQ:
  break;
case XED_ICLASS_VPMAXSB:
  translateVPMAXSB(&xedd);
  break;
case XED_ICLASS_VPMAXSD:
  translateVPMAXSD(&xedd);
  break;
case XED_ICLASS_VPMAXSQ:
  break;
case XED_ICLASS_VPMAXSW:
  break;
case XED_ICLASS_VPMAXUB:
  break;
case XED_ICLASS_VPMAXUD:
  break;
case XED_ICLASS_VPMAXUQ:
  break;
case XED_ICLASS_VPMAXUW:
  break;
case XED_ICLASS_VPMINSB:
  break;
case XED_ICLASS_VPMINSD:
  break;
case XED_ICLASS_VPMINSQ:
  break;
case XED_ICLASS_VPMINSW:
  break;
case XED_ICLASS_VPMINUB:
  translateVPMINUB(&xedd);
  break;
case XED_ICLASS_VPMINUD:
  break;
case XED_ICLASS_VPMINUQ:
  break;
case XED_ICLASS_VPMINUW:
  break;
case XED_ICLASS_VPMOVB2M:
  break;
case XED_ICLASS_VPMOVD2M:
  break;
case XED_ICLASS_VPMOVDB:
  translateVPMOVDB(&xedd);
  break;
case XED_ICLASS_VPMOVDW:
  translateVPMOVDW(&xedd);
  break;
case XED_ICLASS_VPMOVM2B:
  break;
case XED_ICLASS_VPMOVM2D:
  break;
case XED_ICLASS_VPMOVM2Q:
  break;
case XED_ICLASS_VPMOVM2W:
  break;
case XED_ICLASS_VPMOVMSKB:
  break;
case XED_ICLASS_VPMOVQ2M:
  break;
case XED_ICLASS_VPMOVQB:
  break;
case XED_ICLASS_VPMOVQD:
  break;
case XED_ICLASS_VPMOVQW:
  break;
case XED_ICLASS_VPMOVSDB:
  translateVPMOVSDB(&xedd);
  break;
case XED_ICLASS_VPMOVSDW:
  break;
case XED_ICLASS_VPMOVSQB:
  break;
case XED_ICLASS_VPMOVSQD:
  break;
case XED_ICLASS_VPMOVSQW:
  break;
case XED_ICLASS_VPMOVSWB:
  break;
case XED_ICLASS_VPMOVSXBD:
  translateVPMOVSXBD(&xedd);
  break;
case XED_ICLASS_VPMOVSXBQ:
  break;
case XED_ICLASS_VPMOVSXBW:
  translateVPMOVSXBW(&xedd);
  break;
case XED_ICLASS_VPMOVSXDQ:
  break;
case XED_ICLASS_VPMOVSXWD:
  translateVPMOVSXWD(&xedd);
  break;
case XED_ICLASS_VPMOVSXWQ:
  break;
case XED_ICLASS_VPMOVUSDB:
  translateVPMOVUSDB(&xedd);
  break;
case XED_ICLASS_VPMOVUSDW:
  break;
case XED_ICLASS_VPMOVUSQB:
  break;
case XED_ICLASS_VPMOVUSQD:
  break;
case XED_ICLASS_VPMOVUSQW:
  break;
case XED_ICLASS_VPMOVUSWB:
  break;
case XED_ICLASS_VPMOVW2M:
  break;
case XED_ICLASS_VPMOVWB:
  break;
case XED_ICLASS_VPMOVZXBD:
  translateVPMOVZXBD(&xedd);
  break;
case XED_ICLASS_VPMOVZXBQ:
  break;
case XED_ICLASS_VPMOVZXBW:
  break;
case XED_ICLASS_VPMOVZXDQ:
  break;
case XED_ICLASS_VPMOVZXWD:
  translateVPMOVZXWD(&xedd);
  break;
case XED_ICLASS_VPMOVZXWQ:
  break;
case XED_ICLASS_VPMULDQ:
  break;
case XED_ICLASS_VPMULHRSW:
  break;
case XED_ICLASS_VPMULHUW:
  break;
case XED_ICLASS_VPMULHW:
  break;
case XED_ICLASS_VPMULLD:
  break;
case XED_ICLASS_VPMULLQ:
  break;
case XED_ICLASS_VPMULLW:
  break;
case XED_ICLASS_VPMULTISHIFTQB:
  break;
case XED_ICLASS_VPMULUDQ:
  break;
case XED_ICLASS_VPOPCNTB:
  break;
case XED_ICLASS_VPOPCNTD:
  break;
case XED_ICLASS_VPOPCNTQ:
  break;
case XED_ICLASS_VPOPCNTW:
  break;
case XED_ICLASS_VPOR:
  break;
case XED_ICLASS_VPORD:
  translateVPORD(&xedd);
  break;
case XED_ICLASS_VPORQ:
  break;
case XED_ICLASS_VPPERM:
  break;
case XED_ICLASS_VPROLD:
  break;
case XED_ICLASS_VPROLQ:
  break;
case XED_ICLASS_VPROLVD:
  break;
case XED_ICLASS_VPROLVQ:
  break;
case XED_ICLASS_VPRORD:
  break;
case XED_ICLASS_VPRORQ:
  break;
case XED_ICLASS_VPRORVD:
  break;
case XED_ICLASS_VPRORVQ:
  break;
case XED_ICLASS_VPROTB:
  break;
case XED_ICLASS_VPROTD:
  break;
case XED_ICLASS_VPROTQ:
  break;
case XED_ICLASS_VPROTW:
  break;
case XED_ICLASS_VPSADBW:
  break;
case XED_ICLASS_VPSCATTERDD:
  break;
case XED_ICLASS_VPSCATTERDQ:
  break;
case XED_ICLASS_VPSCATTERQD:
  break;
case XED_ICLASS_VPSCATTERQQ:
  break;
case XED_ICLASS_VPSHAB:
  break;
case XED_ICLASS_VPSHAD:
  break;
case XED_ICLASS_VPSHAQ:
  break;
case XED_ICLASS_VPSHAW:
  break;
case XED_ICLASS_VPSHLB:
  break;
case XED_ICLASS_VPSHLD:
  break;
case XED_ICLASS_VPSHLDD:
  break;
case XED_ICLASS_VPSHLDQ:
  break;
case XED_ICLASS_VPSHLDVD:
  break;
case XED_ICLASS_VPSHLDVQ:
  break;
case XED_ICLASS_VPSHLDVW:
  break;
case XED_ICLASS_VPSHLDW:
  break;
case XED_ICLASS_VPSHLQ:
  break;
case XED_ICLASS_VPSHLW:
  break;
case XED_ICLASS_VPSHRDD:
  break;
case XED_ICLASS_VPSHRDQ:
  break;
case XED_ICLASS_VPSHRDVD:
  break;
case XED_ICLASS_VPSHRDVQ:
  break;
case XED_ICLASS_VPSHRDVW:
  break;
case XED_ICLASS_VPSHRDW:
  break;
case XED_ICLASS_VPSHUFB:
  translateVPSHUFB(&xedd);
  break;
case XED_ICLASS_VPSHUFBITQMB:
  break;
case XED_ICLASS_VPSHUFD:
  translateVPSHUFD(&xedd);
  break;
case XED_ICLASS_VPSHUFHW:
  break;
case XED_ICLASS_VPSHUFLW:
  break;
case XED_ICLASS_VPSIGNB:
  break;
case XED_ICLASS_VPSIGND:
  translateVPSIGND(&xedd);
  break;
case XED_ICLASS_VPSIGNW:
  break;
case XED_ICLASS_VPSLLD:
  translateVPSLLD(&xedd);
  break;
case XED_ICLASS_VPSLLDQ:
  break;
case XED_ICLASS_VPSLLQ:
  break;
case XED_ICLASS_VPSLLVD:
  break;
case XED_ICLASS_VPSLLVQ:
  break;
case XED_ICLASS_VPSLLVW:
  break;
case XED_ICLASS_VPSLLW:
  break;
case XED_ICLASS_VPSRAD:
  translateVPSRAD(&xedd);
  break;
case XED_ICLASS_VPSRAQ:
  break;
case XED_ICLASS_VPSRAVD:
  break;
case XED_ICLASS_VPSRAVQ:
  break;
case XED_ICLASS_VPSRAVW:
  break;
case XED_ICLASS_VPSRAW:
  break;
case XED_ICLASS_VPSRLD:
  translateVPSRLD(&xedd);
  break;
case XED_ICLASS_VPSRLDQ:
  break;
case XED_ICLASS_VPSRLQ:
  break;
case XED_ICLASS_VPSRLVD:
  break;
case XED_ICLASS_VPSRLVQ:
  break;
case XED_ICLASS_VPSRLVW:
  break;
case XED_ICLASS_VPSRLW:
  break;
case XED_ICLASS_VPSUBB:
  translateVPSUBB(&xedd);
  break;
case XED_ICLASS_VPSUBD:
  translateVPSUBD(&xedd);
  break;
case XED_ICLASS_VPSUBQ:
  break;
case XED_ICLASS_VPSUBSB:
  break;
case XED_ICLASS_VPSUBSW:
  break;
case XED_ICLASS_VPSUBUSB:
  break;
case XED_ICLASS_VPSUBUSW:
  break;
case XED_ICLASS_VPSUBW:
  break;
case XED_ICLASS_VPTERNLOGD:
  break;
case XED_ICLASS_VPTERNLOGQ:
  break;
case XED_ICLASS_VPTEST:
  break;
case XED_ICLASS_VPTESTMB:
  break;
case XED_ICLASS_VPTESTMD:
  translateVPTESTMD(&xedd);
  break;
case XED_ICLASS_VPTESTMQ:
  break;
case XED_ICLASS_VPTESTMW:
  break;
case XED_ICLASS_VPTESTNMB:
  break;
case XED_ICLASS_VPTESTNMD:
  break;
case XED_ICLASS_VPTESTNMQ:
  break;
case XED_ICLASS_VPTESTNMW:
  break;
case XED_ICLASS_VPUNPCKHBW:
  translateVPUNPCKHBW(&xedd);
  break;
case XED_ICLASS_VPUNPCKHDQ:
  break;
case XED_ICLASS_VPUNPCKHQDQ:
  translateVPUNPCKHQDQ(&xedd);
  break;
case XED_ICLASS_VPUNPCKHWD:
  translateVPUNPCKHWD(&xedd);
  break;
case XED_ICLASS_VPUNPCKLBW:
  translateVPUNPCKLBW(&xedd);
  break;
case XED_ICLASS_VPUNPCKLDQ:
  translateVPUNPCKLDQ(&xedd);
  break;
case XED_ICLASS_VPUNPCKLQDQ:
  translateVPUNPCKLQDQ(&xedd);
  break;
case XED_ICLASS_VPUNPCKLWD:
  translateVPUNPCKLWD(&xedd);
  break;
case XED_ICLASS_VPXOR:
  translateVPXOR(&xedd);
  break;
case XED_ICLASS_VPXORD:
  translateVPXORD(&xedd);
  break;
case XED_ICLASS_VPXORQ:
  translateVPXORQ(&xedd);
  break;
case XED_ICLASS_VRANGEPD:
  break;
case XED_ICLASS_VRANGEPS:
  break;
case XED_ICLASS_VRANGESD:
  break;
case XED_ICLASS_VRANGESS:
  break;
case XED_ICLASS_VRCP14PD:
  break;
case XED_ICLASS_VRCP14PS:
  break;
case XED_ICLASS_VRCP14SD:
  break;
case XED_ICLASS_VRCP14SS:
  break;
case XED_ICLASS_VRCP28PD:
  break;
case XED_ICLASS_VRCP28PS:
  break;
case XED_ICLASS_VRCP28SD:
  break;
case XED_ICLASS_VRCP28SS:
  break;
case XED_ICLASS_VRCPPS:
  break;
case XED_ICLASS_VRCPSS:
  break;
case XED_ICLASS_VREDUCEPD:
  break;
case XED_ICLASS_VREDUCEPS:
  break;
case XED_ICLASS_VREDUCESD:
  break;
case XED_ICLASS_VREDUCESS:
  break;
case XED_ICLASS_VRNDSCALEPD:
  break;
case XED_ICLASS_VRNDSCALEPS:
  translateVRNDSCALEPS(&xedd);
  break;
case XED_ICLASS_VRNDSCALESD:
  break;
case XED_ICLASS_VRNDSCALESS:
  break;
case XED_ICLASS_VROUNDPD:
  break;
case XED_ICLASS_VROUNDPS:
  translateVROUNDPS(&xedd);
  break;
case XED_ICLASS_VROUNDSD:
  break;
case XED_ICLASS_VROUNDSS:
  break;
case XED_ICLASS_VRSQRT14PD:
  break;
case XED_ICLASS_VRSQRT14PS:
  break;
case XED_ICLASS_VRSQRT14SD:
  break;
case XED_ICLASS_VRSQRT14SS:
  break;
case XED_ICLASS_VRSQRT28PD:
  break;
case XED_ICLASS_VRSQRT28PS:
  break;
case XED_ICLASS_VRSQRT28SD:
  break;
case XED_ICLASS_VRSQRT28SS:
  break;
case XED_ICLASS_VRSQRTPS:
  break;
case XED_ICLASS_VRSQRTSS:
  break;
case XED_ICLASS_VSCALEFPD:
  break;
case XED_ICLASS_VSCALEFPS:
  break;
case XED_ICLASS_VSCALEFSD:
  break;
case XED_ICLASS_VSCALEFSS:
  break;
case XED_ICLASS_VSCATTERDPD:
  break;
case XED_ICLASS_VSCATTERDPS:
  break;
case XED_ICLASS_VSCATTERPF0DPD:
  break;
case XED_ICLASS_VSCATTERPF0DPS:
  break;
case XED_ICLASS_VSCATTERPF0QPD:
  break;
case XED_ICLASS_VSCATTERPF0QPS:
  break;
case XED_ICLASS_VSCATTERPF1DPD:
  break;
case XED_ICLASS_VSCATTERPF1DPS:
  break;
case XED_ICLASS_VSCATTERPF1QPD:
  break;
case XED_ICLASS_VSCATTERPF1QPS:
  break;
case XED_ICLASS_VSCATTERQPD:
  break;
case XED_ICLASS_VSCATTERQPS:
  break;
case XED_ICLASS_VSHUFF32X4:
  translateVSHUFF32X4(&xedd);
  break;
case XED_ICLASS_VSHUFF64X2:
  translateVSHUFF64X2(&xedd);
  break;
case XED_ICLASS_VSHUFI32X4:
  translateVSHUFI32X4(&xedd);
  break;
case XED_ICLASS_VSHUFI64X2:
case XED_ICLASS_VSHUFPD:
  translateVSHUFPD(&xedd);
  break;
case XED_ICLASS_VSHUFPS:
  translateVSHUFPS(&xedd);
  break;
case XED_ICLASS_VSQRTPD:
  break;
case XED_ICLASS_VSQRTPS:
  translateVSQRTPS(&xedd);
  break;
case XED_ICLASS_VSQRTSD:
  break;
case XED_ICLASS_VSQRTSS:
  break;
case XED_ICLASS_VSTMXCSR:
  break;
case XED_ICLASS_VSUBPD:
  break;
case XED_ICLASS_VSUBPS:
  translateVSUBPS(&xedd);
  break;
case XED_ICLASS_VSUBSD:
  break;
case XED_ICLASS_VSUBSS:
  translateVSUBSS(&xedd);
  break;
case XED_ICLASS_VTESTPD:
  break;
case XED_ICLASS_VTESTPS:
  translateVTESTPS(&xedd);
  break;
case XED_ICLASS_VUCOMISD:
  break;
case XED_ICLASS_VUCOMISS:
  translateVUCOMISS(&xedd);
  break;
case XED_ICLASS_VUNPCKHPD:
  translateVUNPCKHPD(&xedd);
  break;
case XED_ICLASS_VUNPCKHPS:
  translateVUNPCKHPS(&xedd);
  break;
case XED_ICLASS_VUNPCKLPD:
  translateVUNPCKLPD(&xedd);
  break;
case XED_ICLASS_VUNPCKLPS:
  translateVUNPCKLPS(&xedd);
  break;
case XED_ICLASS_VXORPD:
  break;
case XED_ICLASS_VXORPS:
  translateVXORPS(&xedd);
  break;
case XED_ICLASS_VZEROALL:
  break;
case XED_ICLASS_VZEROUPPER:
  translateVZEROUPPER(&xedd);
  break;
case XED_ICLASS_WBINVD:
  break;
case XED_ICLASS_WBNOINVD:
  break;
case XED_ICLASS_WRFSBASE:
  break;
case XED_ICLASS_WRGSBASE:
  break;
case XED_ICLASS_WRMSR:
  break;
case XED_ICLASS_WRPKRU:
  break;
case XED_ICLASS_WRSSD:
  break;
case XED_ICLASS_WRSSQ:
  break;
case XED_ICLASS_WRUSSD:
  break;
case XED_ICLASS_WRUSSQ:
  break;
case XED_ICLASS_XABORT:
  break;
case XED_ICLASS_XADD:
  break;
case XED_ICLASS_XADD_LOCK:
  translateXADD_LOCK(&xedd);
  break;
case XED_ICLASS_XBEGIN:
  break;
case XED_ICLASS_XCHG:
  translateXCHG(&xedd);
  break;
case XED_ICLASS_XEND:
  break;
case XED_ICLASS_XGETBV:
  break;
case XED_ICLASS_XLAT:
  break;
case XED_ICLASS_XOR:
  translateXOR(&xedd);
  break;
case XED_ICLASS_XORPD:
  break;
case XED_ICLASS_XORPS:
  translateXORPS(&xedd);
  break;
case XED_ICLASS_XOR_LOCK:
  break;
case XED_ICLASS_XRSTOR:
  break;
case XED_ICLASS_XRSTOR64:
  break;
case XED_ICLASS_XRSTORS:
  break;
case XED_ICLASS_XRSTORS64:
  break;
case XED_ICLASS_XSAVE:
  break;
case XED_ICLASS_XSAVE64:
  break;
case XED_ICLASS_XSAVEC:
  break;
case XED_ICLASS_XSAVEC64:
  break;
case XED_ICLASS_XSAVEOPT:
  break;
case XED_ICLASS_XSAVEOPT64:
  break;
case XED_ICLASS_XSAVES:
  break;
case XED_ICLASS_XSAVES64:
  break;
case XED_ICLASS_XSETBV:
  break;
case XED_ICLASS_XSTORE:
  break;
case XED_ICLASS_XTEST:
  break;
case XED_ICLASS_LAST:
  break;
default:
  xed_assert(0);
  break;
}
