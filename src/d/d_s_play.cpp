//
// Generated by dtk
// Translation Unit: d_s_play.cpp
//

#include "d/d_s_play.h"
#include "JSystem/JKernel/JKRExpHeap.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "JSystem/JUtility/JUTConsole.h"
#include "JSystem/JUtility/JUTReport.h"
#include "string.h"
#include "SSystem/SComponent/c_counter.h"
#include "d/actor/d_a_player_main.h"
#include "d/actor/d_a_title.h"
#include "d/d_com_inf_game.h"
#include "d/d_com_lib_game.h"
#include "d/d_kankyo_rain.h"
#include "d/d_material.h"
#include "d/d_meter.h"
#include "d/d_procname.h"
#include "d/d_snap.h"
#include "f_op/f_op_draw_iter.h"
#include "f_op/f_op_msg_mng.h"
#include "f_op/f_op_overlap_mng.h"
#include "f_pc/f_pc_manager.h"
#include "m_Do/m_Do_Reset.h"
#include "m_Do/m_Do_audio.h"
#include "m_Do/m_Do_controller_pad.h"
#include "m_Do/m_Do_dvd_thread.h"
#include "m_Do/m_Do_graphic.h"

namespace daObjTribox {
class Act_c {
public:
    static void reset();
};
};  // namespace daObjTribox

s8 dScnPly_ply_c::pauseTimer;
s8 dScnPly_ply_c::nextPauseTimer;

/* 80234570-802345B0       .text calcPauseTimer__13dScnPly_ply_cFv */
s8 dScnPly_ply_c::calcPauseTimer() {
    if (nextPauseTimer != 0) {
        pauseTimer = nextPauseTimer;
        nextPauseTimer = 0;
        return pauseTimer;
    }

    return cLib_calcTimer(&pauseTimer);
}

/* 802345B0-80234654       .text __ct__18dScnPly_dark_HIO_cFv */
dScnPly_dark_HIO_c::dScnPly_dark_HIO_c() {
    field_0x05 = 0;
    field_0x06 = 0;

    mDarkStatus = dStage_roomControl_c::getDarkStatus(0);
}

dScnPly_dark_HIO_c g_darkHIO;

/* 80234654-802346A4       .text __ct__22dScnPly_reg_childHIO_cFv */
dScnPly_reg_childHIO_c::dScnPly_reg_childHIO_c() {
    for (int i = 0; i < 30; i++) {
        mFloatRegs[i] = 0.0f;
    }

    for (int i = 0; i < 10; i++) {
        mShortRegs[i] = 0;
    }
}

dScnPly_reg_HIO_c g_regHIO;

/* 802346A4-80234734       .text __ct__22dScnPly_env_otherHIO_cFv */
dScnPly_env_otherHIO_c::dScnPly_env_otherHIO_c() {
    field_0x05 = 1;
    field_0x06 = 1;
    field_0x40 = 0;
    field_0x07 = 0;
    field_0x08 = 0;
    field_0x09 = 0;
    field_0x44 = 4000.0f;
    field_0x0a = 0;
    field_0x0b = 0;
    field_0x0c = 0;
    field_0x0d = 128;
    field_0x0e = 16;
    field_0x0f = 0;
    field_0x10 = 0;
    field_0x11 = 0;
    field_0x12 = 0;
    field_0x15 = 0;

    for (int i = 0; i < 20; i++) {
        field_0x18[i] = 0xFFFF;
    }

    field_0x16 = 0;
}

/* 80234734-80234778       .text __ct__22dScnPly_env_debugHIO_cFv */
dScnPly_env_debugHIO_c::dScnPly_env_debugHIO_c() {
    field_0x08 = -100.0f;
    field_0x0c = -100.0f;
    field_0x10 = -100.0f;

    field_0x14 = 100.0f;
    field_0x18 = 100.0f;
    field_0x1c = 100.0f;

    field_0x20 = 0.0f;
    field_0x24 = 0.0f;
    field_0x28 = 0.0f;

    field_0x2c = 100.0f;
}

dScnPly_env_HIO_c g_envHIO;

/* 80234778-802347B4       .text __ct__17dScnPly_msg_HIO_cFv */
dScnPly_msg_HIO_c::dScnPly_msg_HIO_c() {
    field_0x08 = 0;
    mIsUpdate = false;
    field_0x06 = 0;
    field_0x07 = 0;
    field_0x09 = 0;
    mGroup = 0;
    mID = 1;
    field_0x10 = -1;
}

dScnPly_msg_HIO_c g_msgDHIO;

/* 802347B4-802347BC       .text dScnPly_msg_HIO_checkUpdate__17dScnPly_msg_HIO_cFUc */
void dScnPly_msg_HIO_c::dScnPly_msg_HIO_checkUpdate(u8 i_update) {
    mIsUpdate = i_update;
}

/* 802347BC-802347C4       .text dScnPly_msg_HIO_setUpdate__17dScnPly_msg_HIO_cFUc */
void dScnPly_msg_HIO_c::dScnPly_msg_HIO_setUpdate(u8 param_0) {
    field_0x07 = param_0;
}

/* 802347C4-80234830       .text dScnPly_msg_HIO_numUpdate__17dScnPly_msg_HIO_cFss */
void dScnPly_msg_HIO_c::dScnPly_msg_HIO_numUpdate(s16 i_addGroup, s16 i_addID) {
    mGroup += i_addGroup;
    mID += i_addID;

    if (mGroup > 99) {
        mGroup = 99;
    }

    if (mGroup < 0) {
        mGroup = 0;
    }

    if (mID > 0x7FFF) {
        mID = 0x7FFF;
    }

    if (mID < 0) {
        mID = 0;
    }
}

/* 80234830-80234AA8       .text dScnPly_msg_HIO_padCheck__17dScnPly_msg_HIO_cFv */
// NONMATCHING - regswap
void dScnPly_msg_HIO_c::dScnPly_msg_HIO_padCheck() {
    if (mIsUpdate) {
        if (CPad_CHECK_TRIG_Z(3)) {
            dScnPly_msg_HIO_checkUpdate(0);
        }

        if (CPad_CHECK_TRIG_UP(3)) {
            if (CPad_CHECK_HOLD_A(3)) {
                dScnPly_msg_HIO_numUpdate(10, 0);
            } else {
                dScnPly_msg_HIO_numUpdate(1, 0);
            }
        } else if (CPad_CHECK_TRIG_DOWN(3)) {
            if (CPad_CHECK_HOLD_A(3)) {
                dScnPly_msg_HIO_numUpdate(-10, 0);
            } else {
                dScnPly_msg_HIO_numUpdate(-1, 0);
            }
        } else if (CPad_CHECK_TRIG_RIGHT(3)) {
            if (CPad_CHECK_HOLD_Y(3)) {
                dScnPly_msg_HIO_numUpdate(0, 1000);
            } else if (CPad_CHECK_HOLD_X(3)) {
                dScnPly_msg_HIO_numUpdate(0, 100);
            } else if (CPad_CHECK_HOLD_A(3)) {
                dScnPly_msg_HIO_numUpdate(0, 10);
            } else {
                dScnPly_msg_HIO_numUpdate(0, 1);
            }
        } else if (CPad_CHECK_TRIG_LEFT(3)) {
            if (CPad_CHECK_HOLD_Y(3)) {
                dScnPly_msg_HIO_numUpdate(0, -1000);
            } else if (CPad_CHECK_HOLD_X(3)) {
                dScnPly_msg_HIO_numUpdate(0, -100);
            } else if (CPad_CHECK_HOLD_A(3)) {
                dScnPly_msg_HIO_numUpdate(0, -10);
            } else {
                dScnPly_msg_HIO_numUpdate(0, -1);
            }
        } else if (CPad_CHECK_TRIG_B(3)) {
            if (field_0x06 == 0) {
                field_0x06 = 1;
            }
        } else if (field_0x07 != 0) {
            if (field_0x06 == 0) {
                field_0x06 = 1;
            }

            dScnPly_msg_HIO_setUpdate(0);
        }

        JUTReport(470, 250, "Group : %05d", mGroup);
        JUTReport(470, 270, "ID    : %05d", mID);
    }
}

/* 80234AA8-80234B9C       .text dScnPly_msg_HIO_messageProc__17dScnPly_msg_HIO_cFv */
// NONMATCHING - regalloc
void dScnPly_msg_HIO_c::dScnPly_msg_HIO_messageProc() {
    dScnPly_msg_HIO_padCheck();

    if (field_0x06) {
        if (field_0x10 == 0xFFFFFFFF) {
            u32 msg_num = (mGroup << 0x10) | mID;
            cXyz sp10(0.0f, 0.0f, 0.0f);

            if (mGroup != 99 && mGroup != 98 && mGroup != 89) {
                msg_num = fopMsgM_searchMessageNumber(msg_num);
                mGroup = (msg_num >> 0x10) & 0xFFFF;
                mID = msg_num & 0xFFFF;
            }

            field_0x10 = fopMsgM_messageSet(msg_num, &sp10);
        } else {
            msg_class* msg_p = fopMsgM_SearchByID(field_0x10);
            if (msg_p != NULL) {
                if (msg_p->mMode == 14) {
                    msg_p->mMode = 16;
                } else if (msg_p->mMode == 18) {
                    msg_p->mMode = 19;
                    field_0x10 = -1;
                    field_0x06 = 0;
                    mID++;
                }
            }
        }
    }
}

/* 80234B9C-80234FD0       .text dScnPly_Draw__FP13dScnPly_ply_c */
// NONMATCHING - close, just an issue with the wipe conditional
int dScnPly_Draw(dScnPly_ply_c* i_this) {
    dComIfG_Ccsp()->Move();
    dComIfG_Bgsp()->ClrMoveFlag();

    if (!fopOvlpM_IsPeek() && !dComIfG_resetToOpening(i_this) && fpcM_GetName(i_this) == PROC_PLAY_SCENE) {
        if (dComIfGp_isEnableNextStage()) {
            static s16 l_wipeType[] = {0, 0, 16, 17, 18, 1, 2, 1, 3, 3, 4, 4};

            JUT_ASSERT(1001,
                       dComIfGp_getNextStageWipe() < (sizeof(l_wipeType) / sizeof(l_wipeType[0])));

            if (strcmp(dComIfGp_getNextStageName(), "ENDING") == 0) {
                fopScnM_ChangeReq(i_this, PROC_ENDING_SCENE, 0, 5);
                mDoAud_bgmStop(30);
            } else {
                fopScnM_ChangeReq(i_this, PROC_PLAY_SCENE, l_wipeType[dComIfGp_getNextStageWipe()], 5);

                int hour = dKy_getdaytime_hour();
                bool useWhiteColor = false;

                if (dKy_checkEventNightStop()) {
                    useWhiteColor = true;
                } else {
                    useWhiteColor = (hour >= 6 && hour < 18) == 0;
                }

                int wipe = dComIfGp_getNextStageWipe();
                if (wipe == 1 || wipe == 2 || wipe == 7 ||
                    ((wipe == 8 || wipe == 10) && useWhiteColor) ||
                    ((wipe == 9 || wipe == 11) && !useWhiteColor))
                {
                    mDoGph_gInf_c::setFadeColor(g_saftyWhiteColor);
                } else {
                    mDoGph_gInf_c::setFadeColor(g_blackColor);
                }

                mDoAud_setSceneName(dComIfGp_getNextStageName(), dComIfGp_getNextStageRoomNo(),
                                    dComIfGp_getNextStageLayer());
            }
        }
    }

    if (!dMenu_flag() && dScnPly_ply_c::pauseTimer == 0) {
        dComIfGp_getVibration().Run();
        dMat_control_c::icePlay();
        dComIfGp_executeMagma();

        if (dComIfGp_getGrass() != NULL || dComIfGp_getTree() != NULL ||
            dComIfGp_getWood() != NULL || dComIfGp_getFlower() != NULL || dKyr_poison_live_check())
        {
            // using the inline breaks the match
            // dComIfG_Ccsp()->PrepareMass();
            g_dComIfG_gameInfo.play.mCcS.PrepareMass();
        }

        dComIfGp_executeGrass();
        dComIfGp_executeTree();
        dComIfGp_executeWood();
        dComIfGp_executeFlower();
        dKyr_poison_light_colision();
        dComIfG_Bgsp()->Move();
        dSnap_Execute();

        if (daPy_getPlayerLinkActorClass() == NULL ||
            !daPy_getPlayerLinkActorClass()->checkGameOverStart())
        {
            dComIfGp_particle_calc3D();
        }

        dComIfGp_particle_calc2D();
        cCt_execCounter();
    } else {
        dComIfGp_getVibration().Pause();
    }

    dComIfG_Ccsp()->MassClear();
    dComIfGp_particle_calcMenu();
    g_msgDHIO.dScnPly_msg_HIO_messageProc();
    dComIfGp_roomControl_checkDrawArea();

    for (create_tag_class* i = fopDwIt_Begin(); i != NULL; i = fopDwIt_Next(i)) {
        fpcM_Draw(i->mpTagData);
    }

    if (!dMenu_flag()) {
        dComIfGp_particle_drawModelParticle();
        dComIfGp_drawMagma();
        dComIfGp_drawGrass();
        dComIfGp_drawTree();
        dComIfGp_drawWood();
        dComIfGp_drawFlower();
        dComIfG_Ccsp()->Draw();
        dSnap_DebugDraw();
        dComIfGp_getAttention().Draw();
        dComIfGp_map_mapBufferSendAGB(3);
    }

    return 1;
}

/* 80234FD0-802350B4       .text dScnPly_Execute__FP13dScnPly_ply_c */
int dScnPly_Execute(dScnPly_ply_c* i_this) {
    if (!fopOvlpM_IsPeek()) {
        if (mDoAud_zelAudio_c::isBgmSet()) {
            mDoAud_sceneBgmStart();
            mDoAud_load2ndDynamicWave();
            mDoAud_zelAudio_c::offBgmSet();
        }

        if (i_this->calcPauseTimer() != 0) {
            return 1;
        }
    }

    dKy_itudemo_se();
    if (!dMenu_flag()) {
        dComIfGp_demo_update();
        dComIfGp_evmng_execute();

        if (dComIfGp_getAttention().Owner() != NULL) {
            dComIfGp_getAttention().Run(-1);
        } else {
            dComIfGp_getAttention().Init(dComIfGp_getPlayer(0), 0);
        }

        dComIfGp_getDetect().proc();
    }

    return 1;
}

/* 802350B4-802350BC       .text dScnPly_IsDelete__FP13dScnPly_ply_c */
int dScnPly_IsDelete(dScnPly_ply_c* i_this) {
    return 1;
}

/* 802350BC-80235364       .text dScnPly_Delete__FP13dScnPly_ply_c */
void dScnPly_Delete(dScnPly_ply_c* i_this) {
    /* Nonmatching */
}

/* 80235364-802355A8       .text heapSizeCheck__Fv */
BOOL heapSizeCheck() {
    int archive_free = mDoExt_getArchiveHeap()->getFreeSize();
    int archive_total_free = mDoExt_getArchiveHeap()->getTotalFreeSize();
    f32 temp_f31 = (f32)archive_total_free / (f32)mDoExt_getSafeArchiveHeapSize();
    f32 temp_f30 = (f32)archive_free / (f32)archive_total_free;

    int game_free = mDoExt_getGameHeap()->getFreeSize();
    int game_total_free = mDoExt_getGameHeap()->getTotalFreeSize();
    f32 temp_f29 = (f32)game_total_free / (f32)mDoExt_getSafeGameHeapSize();
    f32 temp_f28 = (f32)game_free / (f32)game_total_free;

    mDoExt_getZeldaHeap()->getFreeSize();
    int zelda_total_free = mDoExt_getZeldaHeap()->getTotalFreeSize();
    f32 temp_f27 = (f32)zelda_total_free / (f32)mDoExt_getSafeZeldaHeapSize();

    mDoExt_getCommandHeap()->getFreeSize();
    int command_total_free = mDoExt_getCommandHeap()->getTotalFreeSize();
    f32 temp_f1 = (f32)command_total_free / (f32)mDoExt_getSafeCommandHeapSize();

    if (temp_f31 < 0.7f || temp_f30 < 0.7f || temp_f29 < 0.7f || temp_f28 < 0.7f ||
        temp_f27 < 0.7f || temp_f1 < 0.7f)
    {
        return 0;
    }

    return 1;
}

/* 802355A8-802356B0       .text phase_00__FP13dScnPly_ply_c */
int phase_00(dScnPly_ply_c* i_this) {
    if (mDoAud_isUsedHeapForStreamBuffer()) {
        return 0;
    }

    mDoGph_gInf_c::offBlure();

    if (fpcM_GetName(i_this) != PROC_PLAY_SCENE) {
        if (!heapSizeCheck()) {
            mDoRst_reset(0, 0x80000000, 0);
        }

        if (mDoRst::isReset()) {
            if (mDoAud_zelAudio_c::isResetFlag()) {
                mDoAud_zelAudio_c::getInterface()->resetRecover();
                mDoAud_zelAudio_c::offResetFlag();
            }

            mDoGph_gInf_c::offFade();
            mDoGph_gInf_c::offMonotone();
            dDlst_list_c::offWipe();
            daTitle_proc_c::daTitle_Kirakira_Sound_flag_on();
            daObjTribox::Act_c::reset();
            dComIfGp_offEnableNextStage();
        }

        dComIfGs_init();
    } else {
        if (!heapSizeCheck()) {
            JUT_WARN(3372, "%s", "Memory Danger !!");
        }
    }

    return cPhs_NEXT_e;
}

/* 802356B0-802356E0       .text phase_01__FP13dScnPly_ply_c */
int phase_01(dScnPly_ply_c* i_this) {
    if (!mDoAud_load1stDynamicWave()) {
        return cPhs_INIT_e;
    } else {
        return cPhs_NEXT_e;
    }
}

/* 802356E0-802357F4       .text phase_0__FP13dScnPly_ply_c */
void phase_0(dScnPly_ply_c* i_this) {
    /* Nonmatching */
}

static mDoDvdThd_mountXArchive_c* l_lkDemoAnmCommand;

/* 802357F4-802359DC       .text phase_1__FP13dScnPly_ply_c */
int phase_1(dScnPly_ply_c* i_this) {
    if (l_lkDemoAnmCommand != NULL) {
        if (!l_lkDemoAnmCommand->sync()) {
            return 0;
        }

        JUT_ASSERT(3439, l_lkDemoAnmCommand->getArchive());
        dComIfGp_setLkDemoAnmArchive(l_lkDemoAnmCommand->getArchive());

        delete l_lkDemoAnmCommand;
    }

    u32 id = fopScnM_GetID(i_this);
    dStage_roomControl_c::setProcID(id);

    dComIfGp_setStartStage(dComIfGp_getNextStartStage());
    dComIfGp_offEnableNextStage();

    JUTReportConsole_f("Start StageName:RoomNo [%s:%d]\n", dComIfGp_getStartStageName(),
                       dComIfGp_getStartStageRoomNo());
    dComIfGp_setStatus(0);

    int rt = dComIfG_setStageRes("Stage", NULL);
    JUT_ASSERT(3458, rt == 1);

    dMat_control_c::create((J3DMaterialTable*)dComIfG_getObjectRes("Always", ALWAYS_BMT_ICE),
                           (J3DAnmTextureSRTKey*)dComIfG_getObjectRes("Always", ALWAYS_BTK_ICE));

    return cPhs_NEXT_e;
}

/* 802359DC-80235ABC       .text phase_2__FP13dScnPly_ply_c */
int phase_2(dScnPly_ply_c* i_this) {
    int rt = dComIfG_syncStageRes("Stg_00");
    JUT_ASSERT(3485, rt >= 0)

    if (rt != 0) {
        return cPhs_INIT_e;
    } else {
        dStage_infoCreate();
        u8 particle_no = dStage_stagInfo_GetParticleNo(dComIfGp_getStageStagInfo());
        dComIfGp_particle_readScene(particle_no, &i_this->sceneCommand);
        return cPhs_NEXT_e;
    }
}

/* 80235ABC-80235B0C       .text phase_3__FP13dScnPly_ply_c */
int phase_3(dScnPly_ply_c* i_this) {
    if ((i_this->sceneCommand != NULL && !i_this->sceneCommand->sync()) ||
        mDoAud_zelAudio_c::getInterface()->check1stDynamicWave())
    {
        return cPhs_INIT_e;
    }

    return cPhs_NEXT_e;
}

/* 80235B0C-80236334       .text phase_4__FP13dScnPly_ply_c */
void phase_4(dScnPly_ply_c* i_this) {
    /* Nonmatching */
}

/* 80236334-80236444       .text phase_5__FP13dScnPly_ply_c */
void phase_5(dScnPly_ply_c* i_this) {
    /* Nonmatching */
}

/* 80236444-80236554       .text phase_6__FP13dScnPly_ply_c */
void phase_6(dScnPly_ply_c* i_this) {
    /* Nonmatching */
}

/* 80236554-8023655C       .text phase_compleate__FPv */
int phase_compleate(void* i_this) {
    return cPhs_COMPLEATE_e;
}

/* 8023655C-8023658C       .text dScnPly_Create__FP11scene_class */
int dScnPly_Create(scene_class* i_this) {
    static request_of_phase_process_fn l_method[] = {
        (request_of_phase_process_fn)phase_00, (request_of_phase_process_fn)phase_01,
        (request_of_phase_process_fn)phase_0,  (request_of_phase_process_fn)phase_1,
        (request_of_phase_process_fn)phase_2,  (request_of_phase_process_fn)phase_3,
        (request_of_phase_process_fn)phase_4,  (request_of_phase_process_fn)phase_5,
        (request_of_phase_process_fn)phase_6,  (request_of_phase_process_fn)phase_compleate,
    };

    return dComLbG_PhaseHandler(&static_cast<dScnPly_ply_c*>(i_this)->mLoadPhs, l_method, i_this);
}

static scene_method_class l_dScnPly_Method = {
    (process_method_func)dScnPly_Create,  (process_method_func)dScnPly_Delete,
    (process_method_func)dScnPly_Execute, (process_method_func)dScnPly_IsDelete,
    (process_method_func)dScnPly_Draw,
};

extern scene_process_profile_definition g_profile_PLAY_SCENE = {
    fpcLy_ROOT_e,
    1,
    fpcPi_CURRENT_e,
    PROC_PLAY_SCENE,
    &g_fpcLf_Method.mBase,
    sizeof(dScnPly_ply_c),
    0,
    0,
    &g_fopScn_Method.mBase,
    &l_dScnPly_Method,
};

extern scene_process_profile_definition g_profile_OPENING_SCENE = {
    fpcLy_ROOT_e,
    1,
    fpcPi_CURRENT_e,
    PROC_OPENING_SCENE,
    &g_fpcLf_Method.mBase,
    sizeof(dScnPly_ply_c),
    0,
    0,
    &g_fopScn_Method.mBase,
    &l_dScnPly_Method,
};

extern scene_process_profile_definition g_profile_OPENING2_SCENE = {
    fpcLy_ROOT_e,
    1,
    fpcPi_CURRENT_e,
    PROC_OPENING2_SCENE,
    &g_fpcLf_Method.mBase,
    sizeof(dScnPly_ply_c),
    0,
    0,
    &g_fopScn_Method.mBase,
    &l_dScnPly_Method,
};
