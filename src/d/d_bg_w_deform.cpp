//
// Generated by dtk
// Translation Unit: d_bg_w_deform.cpp
//

#include "d/d_bg_w_deform.h"
#include "JSystem/J3DGraphAnimator/J3DModel.h"
#include "JSystem/J3DGraphAnimator/J3DModelData.h"

/* 800A9928-800A9A48       .text Set__10dBgWDeformFP6cBgD_tP8J3DModelUl */
bool dBgWDeform::Set(cBgD_t* bgd, J3DModel* pmodel, u32 r30) {
    JUT_ASSERT(32, pmodel->getModelData()->isDeformablePositionFormat() == true);
    if (cBgW::Set(bgd, 0x33, NULL)) {
        return true;
    }
    mBC = r30;
    if (pmodel->setSkinDeform(this, 1) == J3DErrType_OutOfMemory) {
        return true;
    }
    pmodel->offFlag(J3DMdlFlag_SkinNrmCpu);
    pmodel->onFlag(J3DMdlFlag_SkinPosCpu);
    if (mBC & 1) {
        return false;
    }
    mC0 = new Vec[pm_bgd->m_v_num];
    if (mC0 == NULL) {
        return true;
    }
    return false;
}
