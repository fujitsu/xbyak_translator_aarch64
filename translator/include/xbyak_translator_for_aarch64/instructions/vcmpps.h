void translateVCMPPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

/* 2020/02/25 11:35 */
#define CG64 CodeGeneratorAArch64
xt_reg_idx_t cmpDstIdx = XT_REG_INVALID;
xt_reg_idx_t cmpMaskIdx = XT_REG_INVALID;
xt_reg_idx_t cmpSrcIdx = XT_REG_INVALID;
xt_reg_idx_t cmpSrc2Idx =  XT_REG_INVALID;

/* Col=S103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==128&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==256&&true)) {
  XT_UNIMPLEMENTED;
}
/* Col=T103*/
if(false ||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)) {
  a64.pTmpIdx = xt_push_preg(&a64);
}
/* Col=U103*/
if(false ||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)) {
  a64.zTmpIdx = xt_push_zreg(&a64);
}

/* Col=W103*/
if(false ||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)) {
  CG64::mov(xa::PRegB(a64.pTmpIdx), P_ALL_ONE/xa::T_z, P_ALL_ONE.b);
}

/* Col=Y103*/
if(false ||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==128&&true)) {
  CG64::ldr(xa::QReg(a64.vTmpIdx), xa::ptr(X_TMP_ADDR));
}

/* Col=AA103*/
if(false ||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)) {
  cmpDstIdx = a64.dstIdx;
}
/* Col=AB103*/
if(false ||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)) {
  cmpMaskIdx = P_ALL_ONE.getIdx();
}
/* Col=AC103*/
if(false ||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==512&&true)) {
  cmpMaskIdx = a64.pTmpIdx;
}

/* Col=AE103*/
if(false ||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)) {
  cmpSrcIdx = a64.srcIdx;
}
/* Col=AF103*/
if(false ||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==256&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==256&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==512&&true)) {
  cmpSrc2Idx = a64.src2Idx;
}
/* Col=AG103*/
if(false ||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==256&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==256&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==256&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==256&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)) {
  cmpSrc2Idx = a64.zTmpIdx;
}

/* Col=AI103*/
if(false ||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)) {
  CG64::ldr(xa::ZReg(a64.zTmpIdx), xa::ptr(X_TMP_ADDR));
}
/* Col=AJ103*/
if(false ||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)) {
  CG64::ld1rw(xa::ZRegS(a64.zTmpIdx), xa::PReg(a64.pTmpIdx)/xa::T_z, xa::ptr(X_TMP_ADDR));
}
/* Col=AK103*/
if(false ||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)) {
  CG64::ld1rw(xa::ZRegS(a64.zTmpIdx), xa::PReg(a64.maskIdx)/xa::T_z, xa::ptr(X_TMP_ADDR));
}
/* Col=AL103*/
if(false ||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==256&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==256&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==256&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==256&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==256&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==256&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)) {
  switch(a64.uimm) {
case EQ_OQ: CG64::fcmeq(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;
case LT_OS:CG64::fcmlt(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;
case LE_OS:CG64::fcmle(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;
case NEQ_UQ:CG64::fcmne(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;
case NLT_US:CG64::fcmge(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;
case NLE_US:CG64::fcmgt(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;
case EQ_UQ:CG64::fcmeq(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;
case NGE_US:CG64::fcmlt(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;
case NGT_US:CG64::fcmle(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;
case NEQ_OQ:CG64::fcmne(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;
case GE_OS:CG64::fcmge(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;
case GT_OS:CG64::fcmgt(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;
case EQ_OS:CG64::fcmeq(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;
case LT_OQ:CG64::fcmlt(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;
case LE_OQ:CG64::fcmle(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;
case NEQ_US:CG64::fcmne(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;
case NLT_UQ:CG64::fcmge(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;
case NLE_UQ:CG64::fcmgt(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;
case EQ_US:CG64::fcmeq(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;
case NGE_UQ:CG64::fcmlt(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;
case NGT_UQ:CG64::fcmle(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;
case NEQ_OS:CG64::fcmne(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;
case GE_OQ:CG64::fcmge(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;
case GT_OQ:CG64::fcmgt(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx)/xa::T_z, xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx)); break;

case UNORD_Q:
case ORD_Q:
case FALSE_OQ:
case TRUE_UQ:
case UNORD_S:
case ORD_S:
case FALSE_OS:
case TRUE_US:
default: xt_msg_err(__FILE__, __LINE__, "Unsupported compare mode"); break;
break;
}
}





/* Col=AR103*/
if(false ||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)) {
  CG64::mov(xa::PRegB(a64.dstIdx), xa::PReg(a64.maskIdx)/xa::T_m, xa::PRegB(a64.pTmpIdx));
}








/* Col=BA103*/
if(false ||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)) {
  xt_pop_zreg();
}
/* Col=BB103*/
if(false ||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==128&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)||(a64.dstWidth==0&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&a64.srcWidth==512&&true)) {
  xt_pop_preg();
}

#undef CG64
}
