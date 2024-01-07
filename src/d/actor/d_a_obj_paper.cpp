//
// Generated by dtk
// Translation Unit: d_a_obj_paper.cpp
//

#include "d/actor/d_a_obj_paper.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "f_op/f_op_actor.h"
#include "f_op/f_op_actor_mng.h"
#include "f_op/f_op_msg.h"
#include "f_op/f_op_msg_mng.h"
#include "d/d_procname.h"
#include "d/d_cc_d.h"
#include "d/d_com_inf_game.h"
#include "d/d_kankyo.h"
#include "d/d_a_obj.h"
#include "d/d_npc.h"
#include "m_Do/m_Do_ext.h"
#include "m_Do/m_Do_mtx.h"
#include "dolphin/types.h"

// Needed for the .data section to match.
static f32 dummy1[3] = {1.0f, 1.0f, 1.0f};
static f32 dummy2[3] = {1.0f, 1.0f, 1.0f};
static u8 dummy3[4] = {0x02, 0x00, 0x02, 0x01};
static f64 dummy4[2] = {3.0f, 0.5f};

namespace daObjPaper {
    namespace {
        struct Attr_c {
            /* 0x00 */ char* mResName;
            /* 0x04 */ s32 mHeapSize;
            /* 0x06 */ s16 mModelId;
            /* 0x08 */ s16 mEyeOffset;
            /* 0x0A */ s16 mAttentionOffset;
            /* 0x0C */ s16 mCullSphereRadius;
            /* 0x0E */ s16 mCullSphereYOffset;

            /* 0x10 */ s8 mAttentionDist1;
            /* 0x11 */ s8 mAttentionDist2;
            /* 0x12 */ u8 mTevType;

            /* 0x14 */ s16 mColCylinderRadius;
            /* 0x16 */ s16 mColCylinderHeight;
        };

        static const Attr_c L_attr[3] = {
            { "Opaper", 0x04C0, 3, 0x00, 0x28, 0x28, 0x00, 0x1D, 0x1E, 0x01, 0x00, 0x00 },
            { "Ppos",   0x04C0, 3, 0x00, 0x32, 0x3C, 0x00, 0x1F, 0x20, 0x00, 0x00, 0x00 },
            { "Piwa",   0x04C0, 3, 0x3C, 0x82, 0x50, 0x3C, 0x1D, 0x1E, 0x00, 0x37, 0x73 }
        };

        inline const Attr_c & attr(Type_e type) { return L_attr[type]; }
    }

    const dCcD_SrcCyl Act_c::M_cyl_src = {
        // dCcD_SrcGObjInf
        {
            /* Flags             */ 0,
            /* SrcObjAt  Type    */ 0,
            /* SrcObjAt  Atp     */ 0,
            /* SrcObjAt  SPrm    */ 0,
            /* SrcObjTg  Type    */ ~(AT_TYPE_WATER | AT_TYPE_UNK20000 | AT_TYPE_LEAF_WIND | AT_TYPE_UNK400000 | AT_TYPE_LIGHT),
            /* SrcObjTg  SPrm    */ TG_SPRM_SET | TG_SPRM_GRP,
            /* SrcObjCo  SPrm    */ CO_SPRM_SET | CO_SPRM_IS_UNK8 | CO_SPRM_VSGRP,
            /* SrcGObjAt Se      */ 0,
            /* SrcGObjAt HitMark */ 0,
            /* SrcGObjAt Spl     */ 0,
            /* SrcGObjAt Mtrl    */ 0,
            /* SrcGObjAt SPrm    */ 0,
            /* SrcGObjTg Se      */ 0,
            /* SrcGObjTg HitMark */ 0,
            /* SrcGObjTg Spl     */ 0,
            /* SrcGObjTg Mtrl    */ 0,
            /* SrcGObjTg SPrm    */ G_TG_SPRM_SHIELD | G_TG_SPRM_NO_CON_HIT,
            /* SrcGObjCo SPrm    */ 0,
        },
        // cM3dGCylS
        {
            /* Center */ 0.0f, 0.0f, 0.0f,
            /* Radius */ 0.0f,
            /* Height */ 0.0f,
        },
    };

    /* 00000078-0000009C       .text solidHeapCB__Q210daObjPaper5Act_cFP10fopAc_ac_c */
    int Act_c::solidHeapCB(fopAc_ac_c* i_this) {
        return static_cast<Act_c*>(i_this)->create_heap();
    }

    /* 0000009C-00000170       .text create_heap__Q210daObjPaper5Act_cFv */
    bool Act_c::create_heap() {
        J3DModelData* mdl_data;
        bool ret = false;

        mdl_data = (J3DModelData*)dComIfG_getObjectRes(attr(mType).mResName, attr(mType).mModelId);

        JUT_ASSERT(0x13E, mdl_data != 0);

        mpModel = mDoExt_J3DModel__create(mdl_data, 0x80000, 0x11000022);
        if (mpModel)
            ret = true;

        return ret;
    }

    /* 00000170-000004E0       .text _create__Q210daObjPaper5Act_cFv */
    s32 Act_c::_create() {
        fopAcM_SetupActor(this, Act_c);

        mType = prm_get_type();

        s32 result = dComIfG_resLoad(&mPhs, attr(mType).mResName);

        if (result == cPhs_COMPLEATE_e) {
            if (fopAcM_entrySolidHeap(this, solidHeapCB, attr(mType).mHeapSize)) {
                mEyePos.y += attr(mType).mEyeOffset;

                mAttentionInfo.mPosition.y += attr(mType).mAttentionOffset;
                mAttentionInfo.mDistances[1] = attr(mType).mAttentionDist1;
                mAttentionInfo.mDistances[3] = attr(mType).mAttentionDist2;
                mAttentionInfo.mFlags |= fopAc_Attn_LOCKON_TALK_e | fopAc_Attn_ACTION_TALK_e | fopAc_Attn_TALKFLAG_READ_e;

                mMsgId = fpcM_ERROR_PROCESS_ID_e;

                if (mType == Piwa_e) {
                    fopAcM_SetStatusMap(this, 0x18);
                }

                if (attr(mType).mColCylinderRadius != 0) {
                    mbHasCc = true;

                    mColStatus.Init(0xFF, 0xFF, this);
                    mCylinderCol.Set(M_cyl_src);

                    mCylinderCol.SetStts(&mColStatus);

                    mCylinderCol.SetR(attr(mType).mColCylinderRadius);
                    mCylinderCol.SetH(attr(mType).mColCylinderHeight);
                } else {
                    mbHasCc = false;
                }

                fopAcM_setCullSizeSphere(this, 0.0f, attr(mType).mCullSphereYOffset, 0.0f, attr(mType).mCullSphereRadius);
                fopAcM_SetMtx(this, mpModel->getBaseTRMtx());

                init_mtx();
                mode_wait_init();
            } else {
                result = cPhs_ERROR_e;
            }
        }

        return result;
    }

    /* 000006F4-00000730       .text _delete__Q210daObjPaper5Act_cFv */
    bool daObjPaper::Act_c::_delete() {
        dComIfG_resDelete(&mPhs, attr(mType).mResName);
        return TRUE;
    }

    /* 00000730-00000748       .text mode_wait_init__Q210daObjPaper5Act_cFv */
    void daObjPaper::Act_c::mode_wait_init() {
        fopAcM_OnStatus(this, fopAcStts_NOCULLEXEC_e);
        mMode = ActMode_WAIT_e;
    }

    /* 00000748-00000784       .text mode_wait__Q210daObjPaper5Act_cFv */
    void daObjPaper::Act_c::mode_wait() {
        if (mEvtInfo.mCommand == dEvtCmd_INTALK_e) {
            mode_talk0_init();
        }
        else {
            mEvtInfo.mCondition |= dEvtCnd_CANTALK_e;
        }
    }

    /* 00000784-000007A4       .text mode_talk0_init__Q210daObjPaper5Act_cFv */
    void daObjPaper::Act_c::mode_talk0_init() {
        fopAcM_OffStatus(this, fopAcStts_NOCULLEXEC_e);
        mMsgId = fpcM_ERROR_PROCESS_ID_e;
        mMode = ActMode_TALKBEGIN_e;
    }

    /* 000007A4-00000820       .text mode_talk0__Q210daObjPaper5Act_cFv */
    void daObjPaper::Act_c::mode_talk0() {
        if (mMsgId == fpcM_ERROR_PROCESS_ID_e && dComIfGp_checkCameraAttentionStatus(dComIfGp_getPlayerCameraID(0), 4)) {
            mMsgId = fopMsgM_messageSet(prm_get_msgNo(), &mEyePos);

            mode_talk1_init();
        }
    }

    /* 00000820-0000082C       .text mode_talk1_init__Q210daObjPaper5Act_cFv */
    void daObjPaper::Act_c::mode_talk1_init() {
        mMode = ActMode_GETMSG_e;
    }

    /* 0000082C-00000874       .text mode_talk1__Q210daObjPaper5Act_cFv */
    void daObjPaper::Act_c::mode_talk1() {
        mpMsg = fopMsgM_SearchByID(mMsgId);
        if (mpMsg) {
            mode_talk2_init();
        }
    }

    /* 00000874-00000880       .text mode_talk2_init__Q210daObjPaper5Act_cFv */
    void daObjPaper::Act_c::mode_talk2_init() {
        mMode = ActMode_TALKWAIT_e;
    }

    /* 00000880-000008DC       .text mode_talk2__Q210daObjPaper5Act_cFv */
    void daObjPaper::Act_c::mode_talk2() {
        if (mpMsg->mStatus == fopMsgStts_BOX_CLOSED_e) {
            mpMsg->mStatus = fopMsgStts_MSG_DESTROYED_e;
            mpMsg = 0;
            mMsgId = fpcM_ERROR_PROCESS_ID_e;

            dComIfGp_event_reset();
            mode_wait_init();
        }
    }

    /* 000008DC-00000948       .text set_mtx__Q210daObjPaper5Act_cFv */
    void daObjPaper::Act_c::set_mtx() {
        mDoMtx_stack_c::transS(current.pos);
        mDoMtx_stack_c::ZXYrotM(shape_angle);

        mpModel->setBaseTRMtx(mDoMtx_stack_c::get());
    }

    /* 00000948-00000984       .text init_mtx__Q210daObjPaper5Act_cFv */
    void daObjPaper::Act_c::init_mtx() {
        mpModel->setBaseScale(mScale);
        set_mtx();
    }

    /* 00000984-00000A38       .text damage_cc_proc__Q210daObjPaper5Act_cFv */
    void daObjPaper::Act_c::damage_cc_proc() {
        u32 hitResult = mCylinderCol.ChkTgHit();
        if (hitResult) {
            daObj::HitSeStart(&mEyePos, current.roomNo, &mCylinderCol, 0x0D);
            dKy_Sound_set(current.pos, 4, fopAcM_GetID(this), 100);

            daObj::HitEff_hibana(this, &mCylinderCol);

            mCylinderCol.ClrTgHit();
        }

        mColStatus.Move();
    }

    typedef void (Act_c::*daObjPaper_mode_t)(void);

    /* 00000A38-00000B58       .text _execute__Q210daObjPaper5Act_cFv */
    bool daObjPaper::Act_c::_execute() {
        static const daObjPaper_mode_t mode_proc[] = {
            &Act_c::mode_wait,
            &Act_c::mode_talk0,
            &Act_c::mode_talk1,
            &Act_c::mode_talk2,
        };

        if (mbHasCc) {
            damage_cc_proc();
        }

        (this->*mode_proc[mMode])();

        set_mtx();
        if (mbHasCc) {
            mCylinderCol.SetC(current.pos);
            dComIfG_Ccsp()->Set(&mCylinderCol);
        }

        return true;
    }

    /* 00000B58-00000BD4       .text _draw__Q210daObjPaper5Act_cFv */
    bool daObjPaper::Act_c::_draw() {
        g_env_light.settingTevStruct(attr(mType).mTevType == 0 ? TEV_TYPE_BG0 : TEV_TYPE_ACTOR, &current.pos, &mTevStr);
        g_env_light.setLightTevColorType(mpModel, &mTevStr);

        mDoExt_modelUpdateDL(mpModel);

        return TRUE;
    }

    namespace {
        /* 00000BD4-00000BF4       .text Mthd_Create__Q210daObjPaper27@unnamed@d_a_obj_paper_cpp@FPv */
        static s32 Mthd_Create(void* i_this) {
            return static_cast<Act_c*>(i_this)->_create();
        }

        /* 00000BF4-00000C18       .text Mthd_Delete__Q210daObjPaper27@unnamed@d_a_obj_paper_cpp@FPv */
        static s32 Mthd_Delete(void* i_this) {
            return static_cast<Act_c*>(i_this)->_delete();
        }

        /* 00000C18-00000C3C       .text Mthd_Execute__Q210daObjPaper27@unnamed@d_a_obj_paper_cpp@FPv */
        static s32 Mthd_Execute(void* i_this) {
            return static_cast<Act_c*>(i_this)->_execute();
        }

        /* 00000C3C-00000C60       .text Mthd_Draw__Q210daObjPaper27@unnamed@d_a_obj_paper_cpp@FPv */
        static s32 Mthd_Draw(void* i_this) {
            return static_cast<Act_c*>(i_this)->_draw();
        }

        /* 00000C60-00000C68       .text Mthd_IsDelete__Q210daObjPaper27@unnamed@d_a_obj_paper_cpp@FPv */
        static s32 Mthd_IsDelete(void* i_this) {
            return TRUE;
        }

        static actor_method_class Mthd_Table = {
            (process_method_func)Mthd_Create,
            (process_method_func)Mthd_Delete,
            (process_method_func)Mthd_Execute,
            (process_method_func)Mthd_IsDelete,
            (process_method_func)Mthd_Draw,
        };
    }
}

actor_process_profile_definition g_profile_Obj_Paper = {
    fpcLy_CURRENT_e,
    7,
    fpcLy_CURRENT_e,
    PROC_Obj_Paper,
    &g_fpcLf_Method.mBase,
    sizeof(daObjPaper::Act_c),
    0,
    0,
    &g_fopAc_Method.base,
    0x0108,
    &daObjPaper::Mthd_Table,
    fopAcStts_NOCULLEXEC_e | fopAcStts_CULL_e | fopAcStts_UNK40000_e,
    fopAc_ACTOR_e,
    fopAc_CULLSPHERE_CUSTOM_e,
};
