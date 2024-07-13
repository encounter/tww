//
// Generated by dtk
// Translation Unit: f_op_kankyo_mng.cpp
//

#include "f_op/f_op_kankyo_mng.h"
#include "f_op/f_op_kankyo.h"
#include "f_pc/f_pc_executor.h"
#include "d/d_procname.h"
#include "d/d_com_inf_game.h"
#include "SSystem/SComponent/c_malloc.h"
#include "SSystem/SComponent/c_lib.h"

/* 8002A860-8002A880       .text fopKyM_SearchByID__FUi */
kankyo_class* fopKyM_SearchByID(fpc_ProcID id) {
    return (kankyo_class*) fpcEx_SearchByID(id);
}

/* 8002A880-8002A8D8       .text fopKyM_CreateAppend__Fv */
static fopKyM_prm_class* fopKyM_CreateAppend() {
    fopKyM_prm_class* params =
        static_cast<fopKyM_prm_class*>(cMl::memalignB(-4, sizeof(fopKyM_prm_class)));

    if (params != NULL) {
        cLib_memSet(params, 0, sizeof(fopKyM_prm_class));
        params->mScale.set(1.0f, 1.0f, 1.0f);
    }
    return params;
}

/* 8002A8D8-8002A968       .text createAppend__FiP4cXyzP4cXyz */
static fopKyM_prm_class* createAppend(int i_param, cXyz* i_pos, cXyz* i_scale) {
    fopKyM_prm_class* prm = fopKyM_CreateAppend();
    if (prm == NULL)
        return NULL;

    if (i_pos != NULL)
        prm->mPos = *i_pos;
    if (i_scale != NULL)
        prm->mScale = *i_scale;
    prm->mParam = i_param;
    return prm;
}

/* 8002A968-8002A988       .text fopKyM_Delete__FPv */
void fopKyM_Delete(void* i_process) {
    fpcM_Delete(i_process);
}

/* 8002A988-8002A9D8       .text fopKyM_Create__FsPFPv_iPv */
fpc_ProcID fopKyM_Create(s16 i_procName, fopKyM_CreateFunc i_createFunc, void* i_process) {
    return fpcM_Create(i_procName, i_createFunc, i_process);
}

/* 8002A9D8-8002AA38       .text fopKyM_create__FsiP4cXyzP4cXyzPFPv_i */
fpc_ProcID fopKyM_create(s16 i_procName, int i_param, cXyz* i_pos, cXyz* i_scale, fopKyM_CreateFunc i_createFunc) {
    fopKyM_prm_class* params = createAppend(i_param, i_pos, i_scale);

    if (params == NULL) {
        return fpcM_ERROR_PROCESS_ID_e;
    }

    return fopKyM_Create(i_procName, i_createFunc, params);
}

/* 8002AA38-8002AA9C       .text fopKyM_fastCreate__FsiP4cXyzP4cXyzPFPv_i */
base_process_class* fopKyM_fastCreate(s16 i_procName, int i_param, cXyz* i_pos, cXyz* i_scale,
                                      fopKyM_CreateFunc i_createFunc) {
    fopKyM_prm_class* params = createAppend(i_param, i_pos, i_scale);

    if (params == NULL) {
        return NULL;
    }

    return fpcM_FastCreate(i_procName, i_createFunc, NULL, params);
}

/* 8002AA9C-8002AB40       .text fopKyM_createWpillar__FPC4cXyzffi */
fpc_ProcID fopKyM_createWpillar(cXyz const* i_pos, f32 scaleXZ, f32 scaleY, int i_param) {
    fopKyM_prm_class* params = fopKyM_CreateAppend();

    if (params == NULL) {
        return fpcM_ERROR_PROCESS_ID_e;
    }

    params->mPos = *i_pos;
    params->mScale.x = scaleXZ;
    params->mScale.y = scaleY;
    params->mScale.z = scaleXZ;
    params->mParam = i_param;

    return fopKyM_Create(PROC_WPILLAR, NULL, params);
}

/* 8002AB40-8002ABB4       .text fopKyM_createMpillar__FPC4cXyzf */
int fopKyM_createMpillar(cXyz const* i_pos, f32 i_size) {
    cXyz scale;
    scale.x = i_size;
    scale.y = i_size;
    scale.z = i_size;
    dComIfGp_particle_set(0x80d5, i_pos, NULL, &scale);
    return -1;
}
