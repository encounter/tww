//
// Generated by dtk
// Translation Unit: d_a_npc_btsw2.cpp
//

#include "d/actor/d_a_npc_btsw2.h"
#include "d/d_com_inf_game.h"
#include "d/d_item.h"
#include "d/d_procname.h"
#include "f_op/f_op_actor_mng.h"
#include "m_Do/m_Do_ext.h"

enum BTSW_RES_FILE_ID {
    /* BCKS */
    BTSW_BCK_BN_KASIGE=0xF,
    BTSW_BCK_BN_ONEGAI=0x10,
    BTSW_BCK_BN_SIWAKE01=0x11,
    BTSW_BCK_BN_SIWAKE02=0x12,
    BTSW_BCK_BN_SUGOI=0x13,
    BTSW_BCK_BN_TALK01=0x14,
    BTSW_BCK_BN_TALK02=0x15,
    BTSW_BCK_BN_WAIT01=0x16,
    BTSW_BCK_BN_WAIT02=0x17,
    BTSW_BCK_BN_WALK=0x18,
    
    /* BDL */
    BTSW_BDL_BN_KABAN=0xC,
    BTSW_BDL_BM_LETTER=0x19,
    BTSW_BDL_BN_TIRASI=0x1A,
    
    /* BDLM */
    BTSW_BDL_QMAIL=0x4,
    BTSW_BDL_BN=0xD,
    
    /* BMDM */
    BTSW_BMD_SHOP_CURSOR01=0x5,
    
    /* BRK */
    BTSW_BRK_SHOP_CURSOR01=0x8,
    
    /* BTP */
    BTSW_BTP_QMAIL=0xA,
    BTSW_BTP_BN_MABA=0xE,
};

enum BTSW_RES_FILE_INDEX {
    /* BCKS */
    BTSW_INDEX_BCK_BN_KASIGE=0x8,
    BTSW_INDEX_BCK_BN_ONEGAI=0x9,
    BTSW_INDEX_BCK_BN_SIWAKE01=0xA,
    BTSW_INDEX_BCK_BN_SIWAKE02=0xB,
    BTSW_INDEX_BCK_BN_SUGOI=0xC,
    BTSW_INDEX_BCK_BN_TALK01=0xD,
    BTSW_INDEX_BCK_BN_TALK02=0xE,
    BTSW_INDEX_BCK_BN_WAIT01=0xF,
    BTSW_INDEX_BCK_BN_WAIT02=0x10,
    BTSW_INDEX_BCK_BN_WALK=0x11,
    
    /* BDL */
    BTSW_INDEX_BDL_BN_KABAN=0x14,
    BTSW_INDEX_BDL_BM_LETTER=0x15,
    BTSW_INDEX_BDL_BN_TIRASI=0x16,
    
    /* BDLM */
    BTSW_INDEX_BDL_QMAIL=0x19,
    BTSW_INDEX_BDL_BN=0x1A,
    
    /* BMDM */
    BTSW_INDEX_BMD_SHOP_CURSOR01=0x1D,
    
    /* BRK */
    BTSW_INDEX_BRK_SHOP_CURSOR01=0x20,
    
    /* BTP */
    BTSW_INDEX_BTP_QMAIL=0x23,
    BTSW_INDEX_BTP_BN_MABA=0x24,
};

// Needed for the .data section to match.
static f32 dummy1[3] = {1.0f, 1.0f, 1.0f};
static f32 dummy2[3] = {1.0f, 1.0f, 1.0f};
static u8 dummy3[4] = {0x02, 0x00, 0x02, 0x01};
static f64 dummy4[2] = {3.0, 0.5};

static u8 dummy[0x4C];

static daNpc_Btsw2_HIO_c l_HIO;

static dCcD_SrcCyl l_cyl_src = {
    // dCcD_SrcGObjInf
    {
        /* Flags             */ 0,
        /* SrcObjAt  Type    */ 0,
        /* SrcObjAt  Atp     */ 0,
        /* SrcObjAt  SPrm    */ 0,
        /* SrcObjTg  Type    */ ~(AT_TYPE_BOOMERANG),
        /* SrcObjTg  SPrm    */ TG_SPRM_SET | TG_SPRM_IS_ENEMY,
        /* SrcObjCo  SPrm    */ CO_SPRM_SET | CO_SPRM_IS_UNK4 | CO_SPRM_VSGRP,
        /* SrcGObjAt Se      */ 0,
        /* SrcGObjAt HitMark */ 0,
        /* SrcGObjAt Spl     */ 0,
        /* SrcGObjAt Mtrl    */ 0,
        /* SrcGObjAt SPrm    */ 0,
        /* SrcGObjTg Se      */ 0,
        /* SrcGObjTg HitMark */ 0,
        /* SrcGObjTg Spl     */ 0,
        /* SrcGObjTg Mtrl    */ 0,
        /* SrcGObjTg SPrm    */ G_TG_SPRM_NO_HIT_MARK,
        /* SrcGObjCo SPrm    */ 0,
    },
    // cM3dGCylS
    {
        /* Center */ 0.0f, 0.0f, 0.0f,
        /* Radius */ 30.0f,
        /* Height */ 80.0f,
    },
};

/* 000000EC-000001A8       .text __ct__17daNpc_Btsw2_HIO_cFv */
daNpc_Btsw2_HIO_c::daNpc_Btsw2_HIO_c() {
    mNpc.m04 = 0.0;
    mNpc.m08 = 0x1F40;
    mNpc.mMaxHeadRot = 0x1F40;
    mNpc.m0A = 0x0;
    mNpc.mMaxBackBoneRot = 0x1F40;
    mNpc.m10 = -0xBB8;
    mNpc.mMinHeadRot = -0x1F40;
    mNpc.m12 = 0x0;
    mNpc.mMinBackBoneRot = -0x1F40;
    mNpc.m18 = 0x3E8;
    mNpc.mMaxHeadTurnVel = 0x640;
    mNpc.m1C = 40.0;
    mNpc.m20 = 0x2000;
    mNpc.m22 = 0x0;
    mNpc.m24 = 200.0;
    m30 = 0x258;
    m32 = 0x5;
    m34 = 0.8;
    m38 = 0.95;
    m3C = 0x5A;
    m3E = 0x5A;
    mChildID = -1;
}

const char daNpc_Btsw2_c::m_arc_name[] = "Btsw";

static const int l_bck_ix_tbl[] = {
	BTSW_INDEX_BCK_BN_WAIT01,
	BTSW_INDEX_BCK_BN_WAIT02,
	BTSW_INDEX_BCK_BN_TALK01,
	BTSW_INDEX_BCK_BN_TALK02,
	BTSW_INDEX_BCK_BN_ONEGAI,
	BTSW_INDEX_BCK_BN_SUGOI,
	BTSW_INDEX_BCK_BN_SUGOI,
	BTSW_INDEX_BCK_BN_WALK,
	BTSW_INDEX_BCK_BN_KASIGE,
	BTSW_INDEX_BCK_BN_SIWAKE01,
	BTSW_INDEX_BCK_BN_SIWAKE02,
};

static const int l_btp_ix_tbl[] = {
    BTSW_INDEX_BTP_BN_MABA,
};

/* 000001A8-000003E0       .text nodeCallBack__FP7J3DNodei */
static BOOL nodeCallBack(J3DNode*, int) {
    /* Nonmatching */
}

/* 0000041C-00000524       .text initTexPatternAnm__13daNpc_Btsw2_cFb */
BOOL daNpc_Btsw2_c::initTexPatternAnm(bool r31) {
    J3DModelData* modelData = mpMcaMorf->getModel()->getModelData();
    m_btp = static_cast<J3DAnmTexPattern*>(dComIfG_getObjectRes(m_arc_name, l_btp_ix_tbl[m744]));
    JUT_ASSERT(282, m_btp != 0);
    if (!mBtpAnm.init(modelData, m_btp, TRUE, 2, 1.0f, 0, -1, r31, 0)) {
        return FALSE;
    }
    m6F0 = 0;
    m6F4 = 0;
    return TRUE;
}

/* 00000524-000005B0       .text playTexPatternAnm__13daNpc_Btsw2_cFv */
void daNpc_Btsw2_c::playTexPatternAnm() {
    /* Nonmatching */
}

/* 000005B0-0000067C       .text setAnm__13daNpc_Btsw2_cFSc */
void daNpc_Btsw2_c::setAnm(s8) {
    /* Nonmatching */
}

/* 0000067C-000007D0       .text chkAttention__13daNpc_Btsw2_cF4cXyzs */
void daNpc_Btsw2_c::chkAttention(cXyz, s16) {
    /* Nonmatching */
}

/* 000007D0-00000820       .text eventOrder__13daNpc_Btsw2_cFv */
void daNpc_Btsw2_c::eventOrder() {
    /* Nonmatching */
}

/* 00000820-00000860       .text checkOrder__13daNpc_Btsw2_cFv */
void daNpc_Btsw2_c::checkOrder() {
    /* Nonmatching */
}

/* 00000860-0000097C       .text anmAtr__13daNpc_Btsw2_cFUs */
void daNpc_Btsw2_c::anmAtr(u16) {
    /* Nonmatching */
}

/* 0000097C-000009EC       .text getMsg__13daNpc_Btsw2_cFv */
u32 daNpc_Btsw2_c::getMsg() {
    /* Nonmatching */
}

/* 000009EC-000009F4       .text next_msgStatus__13daNpc_Btsw2_cFPUl */
u16 daNpc_Btsw2_c::next_msgStatus(u32*) {
    /* Nonmatching */
    return fopMsgStts_MSG_ENDS_e;
}

/* 000009F4-00000A20       .text setAttention__13daNpc_Btsw2_cFv */
void daNpc_Btsw2_c::setAttention() {
    mAttentionInfo.mPosition.set(m704.x, m704.y + l_HIO.mNpc.m1C, m704.z);
}

/* 00000A20-00000B94       .text lookBack__13daNpc_Btsw2_cFv */
void daNpc_Btsw2_c::lookBack() {
    /* Nonmatching */
}

/* 00000B94-00000BB4       .text CallbackCreateHeap__FP10fopAc_ac_c */
static BOOL CallbackCreateHeap(fopAc_ac_c* i_this) {
    return static_cast<daNpc_Btsw2_c*>(i_this)->CreateHeap();
}

/* 00000BB4-00000EFC       .text CreateHeap__13daNpc_Btsw2_cFv */
BOOL daNpc_Btsw2_c::CreateHeap() {
    /* Nonmatching */
    J3DModelData* modelData = static_cast<J3DModelData*>(dComIfG_getObjectRes(m_arc_name, BTSW_INDEX_BDL_BN));
    JUT_ASSERT(616, modelData != 0);
    mpMcaMorf = new mDoExt_McaMorf(
        modelData,
        NULL, NULL,
        static_cast<J3DAnmTransform*>(dComIfG_getObjectRes(m_arc_name, BTSW_INDEX_BCK_BN_WAIT01)),
        J3DFrameCtrl::LOOP_REPEAT_e, 1.0f, 0, -1, 1, NULL, 0x80000, 0x15020022
    );
    if (mpMcaMorf == NULL || mpMcaMorf->getModel() == NULL) {
        return FALSE;
    }
    
    m_jnt.setHeadJntNum(modelData->getJointName()->getIndex("head"));
    JUT_ASSERT(634, m_jnt.getHeadJntNum() >= 0);
    m_jnt.setBackboneJntNum(modelData->getJointName()->getIndex("backbone"));
    JUT_ASSERT(639, m_jnt.getBackboneJntNum() >= 0);
    m6F1 = modelData->getJointName()->getIndex("handL");
    m6F2 = modelData->getJointName()->getIndex("handR");
    
    modelData = static_cast<J3DModelData*>(dComIfG_getObjectRes(m_arc_name, BTSW_INDEX_BDL_BN_KABAN));
    m6D0 = mDoExt_J3DModel__create(modelData, 0, 0x11020203);
    if (m6D0 == NULL) {
        return FALSE;
    }
    modelData = static_cast<J3DModelData*>(dComIfG_getObjectRes(m_arc_name, BTSW_INDEX_BDL_BN_TIRASI));
    m6D4 = mDoExt_J3DModel__create(modelData, 0, 0x11020203);
    if (m6D4 == NULL) {
        return FALSE;
    }
    
    m744 = 0;
    if (!initTexPatternAnm(false)) {
        return FALSE;
    }
    
    modelData = mpMcaMorf->getModel()->getModelData();
    modelData->getJointNodePointer(m_jnt.getHeadJntNum())->setCallBack(nodeCallBack);
    modelData->getJointNodePointer(m_jnt.getBackboneJntNum())->setCallBack(nodeCallBack);
    mpMcaMorf->getModel()->setUserArea((u32)this);
    mAcchCir.SetWall(30.0f, 0.0f);
    mObjAcch.Set(&current.pos, &old.pos, this, 1, &mAcchCir, &speed);
    
    return TRUE;
}

/* 00000EFC-000010F8       .text CreateInit__13daNpc_Btsw2_cFv */
BOOL daNpc_Btsw2_c::CreateInit() {
    m714 = current.angle;
    mAttentionInfo.mFlags = fopAc_Attn_LOCKON_TALK_e | fopAc_Attn_ACTION_TALK_e;
    mGravity = -30.0f;
    setAction(&daNpc_Btsw2_c::wait_action, NULL);
    m704 = current.pos;
    mStts.Init(0xFF, 0xFF, this);
    mCyl.Set(l_cyl_src);
    mCyl.SetStts(&mStts);
    setCollision(60.0f, 150.0f);
    m724 = 0;
    mPathNo = fopAcM_GetParamBit(fopAcM_GetParam(this), 0x10, 8);
    mpPath = dPath_GetRoomPath(mPathNo, current.roomNo);
    m73C = mpPath->m_num - 1;
    m73E = 1.0f + cM_rndF(3.0f);
    m742 = 90.0f + cM_rndF(300.0f);
    m735 = 0;
    m736 = 0;
    m740 = 0;
    mEventCut.setActorInfo2("Btsw2", this);
    mAttentionInfo.mDistances[1] = 0xAB;
    mAttentionInfo.mDistances[3] = 0xAB;
    return TRUE;
}

/* 000010F8-0000111C       .text wait01__13daNpc_Btsw2_cFv */
void daNpc_Btsw2_c::wait01() {
    if (m71E) {
        m747 = 2;
    } else {
        m746 = 2;
    }
}

/* 0000111C-000011A8       .text talk01__13daNpc_Btsw2_cFv */
void daNpc_Btsw2_c::talk01() {
    /* Nonmatching */
}

/* 000011A8-00001574       .text pathMove__13daNpc_Btsw2_cFv */
void daNpc_Btsw2_c::pathMove() {
    /* Nonmatching */
}

/* 00001574-00001660       .text wait_action__13daNpc_Btsw2_cFPv */
BOOL daNpc_Btsw2_c::wait_action(void*) {
    /* Nonmatching */
}

/* 00001660-00001884       .text _create__13daNpc_Btsw2_cFv */
s32 daNpc_Btsw2_c::_create() {
    fopAcM_SetupActor(this, daNpc_Btsw2_c);
    
    if (dComIfGs_getEventReg(0xC203) == 3 || !checkItemGet(PEARL2, TRUE)) {
        return cPhs_ERROR_e;
    }
    
    int phase_state = dComIfG_resLoad(&mPhs, m_arc_name);
    
    if (phase_state == cPhs_COMPLEATE_e) {
        if (!fopAcM_entrySolidHeap(this, CallbackCreateHeap, 0x29E0)) {
            return cPhs_ERROR_e;
        }
        
        fopAcM_SetMtx(this, mpMcaMorf->getModel()->getBaseTRMtx());
        
        if (!CreateInit()) {
            return cPhs_ERROR_e;
        }
    }
    
    return phase_state;
}

/* 00001C34-00001C8C       .text _delete__13daNpc_Btsw2_cFv */
BOOL daNpc_Btsw2_c::_delete() {
    dComIfG_resDelete(&mPhs, m_arc_name);
    if (heap && mpMcaMorf) {
        mpMcaMorf->stopZelAnime();
    }
    return TRUE;
}

/* 00001C8C-00001DDC       .text _execute__13daNpc_Btsw2_cFv */
BOOL daNpc_Btsw2_c::_execute() {
    /* Nonmatching */
}

/* 00001DDC-00001F6C       .text _draw__13daNpc_Btsw2_cFv */
BOOL daNpc_Btsw2_c::_draw() {
    /* Nonmatching */
}

/* 00001F6C-00001F8C       .text daNpc_Btsw2_Create__FP10fopAc_ac_c */
static s32 daNpc_Btsw2_Create(fopAc_ac_c* i_this) {
    return static_cast<daNpc_Btsw2_c*>(i_this)->_create();
}

/* 00001F8C-00001FAC       .text daNpc_Btsw2_Delete__FP13daNpc_Btsw2_c */
static BOOL daNpc_Btsw2_Delete(daNpc_Btsw2_c* i_this) {
    return static_cast<daNpc_Btsw2_c*>(i_this)->_delete();
}

/* 00001FAC-00001FCC       .text daNpc_Btsw2_Execute__FP13daNpc_Btsw2_c */
static BOOL daNpc_Btsw2_Execute(daNpc_Btsw2_c* i_this) {
    return static_cast<daNpc_Btsw2_c*>(i_this)->_execute();
}

/* 00001FCC-00001FEC       .text daNpc_Btsw2_Draw__FP13daNpc_Btsw2_c */
static BOOL daNpc_Btsw2_Draw(daNpc_Btsw2_c* i_this) {
    return static_cast<daNpc_Btsw2_c*>(i_this)->_draw();
}

/* 00001FEC-00001FF4       .text daNpc_Btsw2_IsDelete__FP13daNpc_Btsw2_c */
static BOOL daNpc_Btsw2_IsDelete(daNpc_Btsw2_c* i_this) {
    return TRUE;
}

actor_method_class l_daNpc_Btsw2_Method = {
    (process_method_func)daNpc_Btsw2_Create,
    (process_method_func)daNpc_Btsw2_Delete,
    (process_method_func)daNpc_Btsw2_Execute,
    (process_method_func)daNpc_Btsw2_IsDelete,
    (process_method_func)daNpc_Btsw2_Draw,
};

actor_process_profile_definition g_profile_NPC_BTSW2 = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 7,
    /* ListPrio     */ fpcLy_CURRENT_e,
    /* ProcName     */ PROC_NPC_BTSW2,
    /* Proc SubMtd  */ &g_fpcLf_Method.mBase,
    /* Size         */ sizeof(daNpc_Btsw2_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x0163,
    /* Actor SubMtd */ &l_daNpc_Btsw2_Method,
    /* Status       */ 0x07 | fopAcStts_SHOWMAP_e | fopAcStts_NOCULLEXEC_e | fopAcStts_CULL_e | fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_12_e,
};
