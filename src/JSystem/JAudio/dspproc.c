//
// Generated by dtk
// Translation Unit: dspproc.c
//

#include "JSystem/JAudio/dspproc.h"
#include "JSystem/JAudio/JASDSPInterface.h"
#include "JSystem/JAudio/dsptask.h"
#include "dolphin/dsp.h"

/* 8028E600-8028E648       .text DSPReleaseHalt2__FUl */
void DSPReleaseHalt2(u32 msg) {
    u32 msgs[2];
    u16 dspMap = DSP_CreateMap2(msg);
    msgs[0] = (msg << 16) | dspMap;

    DSPSendCommands2(msgs, 0, NULL);
}

/* 8028E660-8028E694       .text DSPReleaseHalt__Fv */
void DSPReleaseHalt() {
    u32 msgs[2];
    msgs[0] = 0x30000;
    DSPSendCommands2(msgs, 0, NULL);
}

static volatile BOOL flag;

/* 8028E6A0-8028E6AC       .text setup_callback__FUs */
void setup_callback(u16) {
    flag = 0;
}

/* 8028E6C0-8028E724       .text DsetupTable__FUlUlUlUlUl */
void DsetupTable(u32 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5) {
    u32 table[5];
    table[0] = (param_1 & 0xFFFF) | 0x81000000;
    table[1] = param_2;
    table[2] = param_3;
    table[3] = param_4;
    table[4] = param_5;
    flag = 1;
    DSPSendCommands2(table,5,setup_callback);
    while (true) {
        if (flag == 0) {
            return;
        }
    }
}

static u16 DSP_MIXERLEVEL = 0x4000;

/* 8028E740-8028E764       .text DsetMixerLevel__Ff */
void DsetMixerLevel(f32 level) {
    DSP_MIXERLEVEL = 4096.0f * level;
}

/* 8028E780-8028E7C8       .text DsyncFrame__FUlUlUl */
void DsyncFrame(u32 param_1, u32 param_2, u32 param_3) {
    u32 msgs[3];
    msgs[0] = (param_1 & 0xff) << 0x10 | 0x82000000 | DSP_MIXERLEVEL;
    msgs[1] = param_2;
    msgs[2] = param_3;
    DSPSendCommands2(msgs, 3, 0);
}

static volatile BOOL d_waitflag;

/* 8028E7E0-8028E7EC       .text dummy_callback__FUs */
void dummy_callback(u16) {
    d_waitflag = 0;
}

/* 8028E800-8028E854       .text DsetDolbyDelay__FUlUs */
void DsetDolbyDelay(u32 param_1, u16 param_2) {
    u32 msgs[2];
    msgs[0] = param_2 | 0x8D000000;
    msgs[1] = param_1;
    d_waitflag = 1;
    DSPSendCommands2(msgs, 2, dummy_callback);
    while (d_waitflag) {}
}
