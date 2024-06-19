#ifndef D_A_YGCWP_H
#define D_A_YGCWP_H

#include "f_op/f_op_actor.h"
#include "m_Do/m_Do_ext.h"
#include "SSystem/SComponent/c_phase.h"

class daYgcwp_c : public fopAc_ac_c {
public:
    BOOL check_ev() const; // weak but not inlined?
    void off_ev() const; // weak but not inlined?

    static BOOL solidHeapCB(fopAc_ac_c*);
    BOOL create_heap();
    s32 _create();
    bool _delete();
    void init_mtx();
    void make_shine();
    void set_timer();
    bool _execute();
    bool _draw();

public:
    static const char M_arcname[6];

public:
    /* 0x290 */ J3DModel* mpModel;
    /* 0x294 */ request_of_phase_process_class mPhs;
    /* 0x29C */ mDoExt_brkAnm mBrkAnm[2];
    /* 0x2CC */ s32 mStaffId;
    /* 0x2D0 */ s32 mTimer;
    /* 0x2D4 */ s32 mCurBrk;
    /* 0x2D8 */ s32 m2D8;
};

#endif /* D_A_YGCWP_H */
