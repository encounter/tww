//
// Generated by dtk
// Translation Unit: JPAEmitter.cpp
//

#include "JSystem/JParticle/JPAEmitter.h"
#include "JSystem/JParticle/JPADynamicsBlock.h"
#include "JSystem/JParticle/JPAExtraShape.h"
#include "JSystem/JParticle/JPASweepShape.h"
#include "JSystem/JParticle/JPAKeyBlock.h"
#include "dolphin/mtx/mtx.h"
#include "dolphin/mtx/mtxvec.h"

JPAEmitterInfo JPABaseEmitter::emtrInfo;

/* 8025C128-8025C254       .text calcVolumePoint__14JPABaseEmitterFv */
void JPABaseEmitter::calcVolumePoint() {
    /* Nonmatching */
    emtrInfo.mVolumePos.z = 0.0f;
    emtrInfo.mVolumePos.y = 0.0f;
    emtrInfo.mVolumePos.x = 0.0f;

    emtrInfo.mVelOmni.z = mRandomSeed.get_ufloat_1() - 0.5f;
    emtrInfo.mVelOmni.y = mRandomSeed.get_ufloat_1() - 0.5f;
    emtrInfo.mVelOmni.x = mRandomSeed.get_ufloat_1() - 0.5f;

    emtrInfo.mVelAxis.x = mRandomSeed.get_ufloat_1() - 0.5f;
    emtrInfo.mVelAxis.y = 0.0f;
    emtrInfo.mVelAxis.z = mRandomSeed.get_ufloat_1() - 0.5f;
}

/* 8025C254-8025C394       .text calcVolumeLine__14JPABaseEmitterFv */
void JPABaseEmitter::calcVolumeLine() {
    /* Nonmatching */
}

/* 8025C394-8025C538       .text calcVolumeCircle__14JPABaseEmitterFv */
void JPABaseEmitter::calcVolumeCircle() {
    /* Nonmatching */
}

/* 8025C538-8025C63C       .text calcVolumeCube__14JPABaseEmitterFv */
void JPABaseEmitter::calcVolumeCube() {
    /* Nonmatching */
}

/* 8025C63C-8025C8A4       .text calcVolumeSphere__14JPABaseEmitterFv */
void JPABaseEmitter::calcVolumeSphere() {
    /* Nonmatching */
}

/* 8025C8A4-8025CA28       .text calcVolumeCylinder__14JPABaseEmitterFv */
void JPABaseEmitter::calcVolumeCylinder() {
    /* Nonmatching */
}

/* 8025CA28-8025CB54       .text calcVolumeTorus__14JPABaseEmitterFv */
void JPABaseEmitter::calcVolumeTorus() {
    /* Nonmatching */
}

/* 8025CB54-8025D0B0       .text create__14JPABaseEmitterFP20JPADataBlockLinkInfo */
void JPABaseEmitter::create(JPADataBlockLinkInfo* info) {
    mpDataLinkInfo = info;

    JPADynamicsBlock * dyn = getEmitterDataBlockInfoPtr()->getDynamics();
    dyn->getEmitterScl(mEmitterScale);
    dyn->getEmitterTrs(mEmitterTranslation);
    dyn->getEmitterRot(mEmitterRot);
    mVolumeType = dyn->getVolumeType();
    mRateStep = dyn->getRateStep();
    mDivNumber = dyn->getDivNumber();
    mRate = dyn->getRate();
    mRateRndm = dyn->getRateRndm();
    mMaxFrame = dyn->getMaxFrame();
    mStartFrame = dyn->getStartFrame();
    mVolumeSize = dyn->getVolumeSize();
    mVolumeSweep = dyn->getVolumeSweep();
    mVolumeMinRad = dyn->getVolumeMinRad();
    mLifeTime = dyn->getLifeTime();
    mLifeTimeRndm = dyn->getLifeTimeRndm();
    mMoment = dyn->getMoment();
    mMomentRndm = dyn->getMomentRndm();
    mInitialVelRatio = dyn->getInitVelRatio();
    mAccelRndm = dyn->getAccelRndm();
    mAirResist = dyn->getAirResist();
    mAirResistRndm = dyn->getAirResistRndm();
    mInitialVelOmni = dyn->getInitVelOmni();
    mInitialVelAxis = dyn->getInitVelAxis();
    mInitialVelRndm = dyn->getInitVelRndm();
    mInitialVelDir = dyn->getInitVelDir();
    mAccel = dyn->getAccel();
    dyn->getEmitterDir(mEmitterDir);
    // This appears to be an attempt at a normalize, but it scales by the length instead (???)
    mEmitterDir.normalize_broken();
    mSpread = dyn->getSpread();
    mDataFlag = dyn->getDataFlag();
    mUseKeyFlag = dyn->getUseKeyFlag();
    mFlags = JPAEmtrStts_FirstEmit | JPAEmtrStts_RateStepEmit;
    MTXIdentity(mGlobalRotation);
    mGlobalDynamicsScale.x = 1.0f;
    mGlobalDynamicsScale.y = 1.0f;
    mGlobalDynamicsScale.z = 1.0f;
    mGlobalTranslation.zero();
    mGlobalParticleScale.x = 1.0f;
    mGlobalParticleScale.y = 1.0f;
    mGlobalParticleScale.z = 1.0f;
    mGlobalEnvColor.r = mGlobalEnvColor.g = mGlobalEnvColor.b = mGlobalEnvColor.a = 0xFF;
    mGlobalPrmColor.r = mGlobalPrmColor.g = mGlobalPrmColor.b = mGlobalPrmColor.a = 0xFF;
    mEmitCount = 0.0f;
    mRateStepTimer = 0.0f;
    mTick = 0.0f;
    mTime = 0.0f;
    mUserData = 0;
    mRandomSeed.setSeed(emtrInfo.mRandom.get());
    mFieldManager.initField(info, &emtrInfo);

    switch (mVolumeType) {
    case 0: mVolumeFunc = &JPABaseEmitter::calcVolumeCube; break;
    case 1: mVolumeFunc = &JPABaseEmitter::calcVolumeSphere; break;
    case 2: mVolumeFunc = &JPABaseEmitter::calcVolumeCylinder; break;
    case 3: mVolumeFunc = &JPABaseEmitter::calcVolumeTorus; break;
    case 4: mVolumeFunc = &JPABaseEmitter::calcVolumePoint; break;
    case 5: mVolumeFunc = &JPABaseEmitter::calcVolumeCircle; break;
    case 6: mVolumeFunc = &JPABaseEmitter::calcVolumeLine; break;
    default: mVolumeFunc = NULL; break;
    }
}

/* 8025D0B0-8025D294       .text calcEmitterInfo__14JPABaseEmitterFv */
void JPABaseEmitter::calcEmitterInfo() {
    /* Nonmatching */
    emtrInfo.mpCurEmitter = this;
    emtrInfo.mVolumeEmitXCount = 0;
    emtrInfo.mVolumeEmitAngleCount = 0;
    emtrInfo.mVolumeEmitAngleMax = 1;
    emtrInfo.mDivNumber = mDivNumber * 2 + 1;
    emtrInfo.mVolumeSize = mVolumeSize;
    
    Mtx mtxScale, mtxRot, mtx;
    MTXScale(mtxScale, mEmitterScale.x, mEmitterScale.y, mEmitterScale.z);
    JPAGetXYZRotateMtx((mEmitterRot.x << 14) / 0x5a, (mEmitterRot.y << 14) / 0x5a, (mEmitterRot.z << 14) / 0x5a, mtxRot);
    
    MTXScale(mtx, mGlobalDynamicsScale.x, mGlobalDynamicsScale.y, mGlobalDynamicsScale.z);
    MTXConcat(mGlobalRotation, mtx, mtx);
    mtx[0][3] = mGlobalTranslation.x;
    mtx[1][3] = mGlobalTranslation.y;
    mtx[2][3] = mGlobalTranslation.z;
    MTXCopy(mGlobalRotation, emtrInfo.mGlobalRot);
    MTXConcat(mGlobalRotation, mtxRot, emtrInfo.mEmitterGlobalRot);
    MTXConcat(emtrInfo.mEmitterGlobalRot, mtxScale, emtrInfo.mEmitterGlobalSR);
    JPAGetDirMtx(mEmitterDir, emtrInfo.mEmitterDirMtx);
    emtrInfo.mEmitterGlobalScale.x = mEmitterScale.x * mGlobalDynamicsScale.x;
    emtrInfo.mEmitterGlobalScale.y = mEmitterScale.y * mGlobalDynamicsScale.y;
    emtrInfo.mEmitterGlobalScale.z = mEmitterScale.z * mGlobalDynamicsScale.z;
    emtrInfo.mEmitterTranslation.x = mEmitterTranslation.x;
    emtrInfo.mEmitterTranslation.y = mEmitterTranslation.y;
    emtrInfo.mEmitterTranslation.z = mEmitterTranslation.z;
    emtrInfo.mPublicScale.x = mGlobalDynamicsScale.x * 1.0f;
    emtrInfo.mPublicScale.y = mGlobalDynamicsScale.y * 1.0f;
    emtrInfo.mPublicScale.z = mGlobalDynamicsScale.z * 1.0f;
    MTXMultVec(mtx, mEmitterTranslation, emtrInfo.mEmitterGlobalCenter);
}

/* 8025D294-8025D3C0       .text calc__14JPABaseEmitterFv */
void JPABaseEmitter::calc() {
    emtrInfo.mVolumeEmitCount = 0;
    if (!checkStatus(JPAEmtrStts_StopCalc)) {
        calcKey();
        if (mpEmitterCallBack != NULL)
            mpEmitterCallBack->execute(this);
        calcEmitterInfo();
        mDraw.calc();
        mFieldManager.preCalc();
        if (!checkStatus(JPAEmtrStts_EnableDeleteEmitter))
            calcCreatePtcls();
        if (mpEmitterCallBack != NULL)
            mpEmitterCallBack->executeAfter(this);
        calcParticle();
        calcChild();
        mTick += 1.0f;
        if (mTick < 0.0f)
            mTick = 0.0f;
    } else {
        if (mpEmitterCallBack != NULL)
            mpEmitterCallBack->execute(this);
        if (mpEmitterCallBack != NULL)
            mpEmitterCallBack->executeAfter(this);
    }
}

/* 8025D3C0-8025D5D4       .text calcCreatePtcls__14JPABaseEmitterFv */
void JPABaseEmitter::calcCreatePtcls() {
    /* Nonmatching */
}

/* 8025D5D4-8025D670       .text createChildren__14JPABaseEmitterFP15JPABaseParticle */
void JPABaseEmitter::createChildren(JPABaseParticle* ptcl) {
    s32 num = getEmitterDataBlockInfoPtr()->getSweepShape()->getRate();
    for (s32 i = 0; i < num; i++) {
        JPABaseParticle * chld = getPtclFromVacList();
        if (chld == NULL)
            break;
        mChildParticles.prepend(&chld->mLink);
        chld->initChild(ptcl);
        mDraw.initChild(ptcl, chld);
    }
}

/* 8025D670-8025D6E0       .text createParticle__14JPABaseEmitterFv */
JPABaseParticle * JPABaseEmitter::createParticle() {
    JPABaseParticle * ptcl = getPtclFromVacList();
    if (ptcl != NULL) {
        mActiveParticles.prepend(&ptcl->mLink);
        (this->*mVolumeFunc)();
        ptcl->initParticle();
        mDraw.initParticle(ptcl);
    }
    return ptcl;
}

/* 8025D6E0-8025D7E0       .text calcParticle__14JPABaseEmitterFv */
void JPABaseEmitter::calcParticle() {
    for (JSULink<JPABaseParticle> * link = mActiveParticles.getFirst(); link != NULL;) {
        JSULink<JPABaseParticle> * next = link->getNext();
        JPABaseParticle * ptcl = (JPABaseParticle *) link->getObjectPtr();
        ptcl->incFrame();
        if (!(ptcl->mStatus & 0x80)) {
            ptcl->calcVelocity();
            if (ptcl->mpCallBack2 != NULL)
                ptcl->mpCallBack2->execute(this, ptcl);
            if (!(ptcl->mStatus & 0x02)) {
                mDraw.calcParticle(ptcl);
                if (getEmitterDataBlockInfoPtr()->getSweepShape() != NULL && ptcl->checkCreateChild())
                    createChildren(ptcl);
                ptcl->calcPosition();
            }
        } else {
            ptcl->mStatus |= 0x02;
        }

        if (ptcl->mStatus & 0x02)
            deleteParticle(ptcl, &mActiveParticles);

        link = next;
    }
}

/* 8025D7E0-8025D8CC       .text calcChild__14JPABaseEmitterFv */
void JPABaseEmitter::calcChild() {
    for (JSULink<JPABaseParticle> * link = mChildParticles.getFirst(); link != NULL;) {
        JSULink<JPABaseParticle> * next = link->getNext();
        JPABaseParticle * ptcl = (JPABaseParticle *) link->getObjectPtr();
        ptcl->incFrame();
        if (!(ptcl->mStatus & 0x80)) {
            if ((s32)ptcl->mCurFrame != 0)
                ptcl->calcVelocity();
            if (ptcl->mpCallBack2 != NULL)
                ptcl->mpCallBack2->execute(this, ptcl);
            if (!(ptcl->mStatus & 0x02)) {
                mDraw.calcChild(ptcl);
                ptcl->calcPosition();
            }
        } else {
            ptcl->mStatus |= 0x02;
        }

        if (ptcl->mStatus & 0x02)
            deleteParticle(ptcl, &mChildParticles);

        link = next;
    }
}

/* 8025D8CC-8025DA90       .text calcKey__14JPABaseEmitterFv */
void JPABaseEmitter::calcKey() {
    /* Nonmatching */
    for (u32 i = 0; i < getEmitterDataBlockInfoPtr()->getKeyNum(); i++) {
        JPAKeyBlock* key = getEmitterDataBlockInfoPtr()->getKey()[i];
        f32 tick = mTick;
        const f32* dataPtr = key->getKeyDataPtr();
        u32 dataNum = key->getNumber();
        if (key->isLoopEnable()) {
            s32 tickMax = (s32)(dataPtr[(dataNum - 1) * 4]) + 1;
            tick -= (s32)tick % (s32)tickMax;
        }
        f32 value = JPAGetKeyFrameValue(tick, dataNum, dataPtr);

        switch (key->getID()) {
        case 0: mRate = value; break;
        case 1: mVolumeSize = value; break;
        case 2: mVolumeSweep = value; break;
        case 3: mVolumeMinRad = value; break;
        case 4: mLifeTime = value; break;
        case 5: mMoment = value; break;
        case 6: mInitialVelOmni = value; break;
        case 7: mInitialVelAxis = value; break;
        case 8: mInitialVelDir = value; break;
        case 9: mSpread = value; break;
        case 10: mDraw.mScaleOut = value; break;
        }
    }
}

/* 8025DA90-8025DAD8       .text deleteParticle__14JPABaseEmitterFP15JPABaseParticleP26JSUList<15JPABaseParticle> */
void JPABaseEmitter::deleteParticle(JPABaseParticle* ptcl, JSUList<JPABaseParticle>* list) {
    JSUPtrList * ptrlist = list;
    ptrlist->remove(&ptcl->mLink);
    mpPtclVacList->prepend(&ptcl->mLink);
}

/* 8025DAD8-8025DB68       .text deleteAllParticle__14JPABaseEmitterFv */
void JPABaseEmitter::deleteAllParticle() {
    for (JSULink<JPABaseParticle>* link = mActiveParticles.getFirst(); link != NULL;) {
        JSULink<JPABaseParticle>* next = link->getNext();
        mActiveParticles.remove(link);
        mpPtclVacList->prepend(link);
        link = next;
    }

    for (JSULink<JPABaseParticle>* link = mChildParticles.getFirst(); link != NULL;) {
        JSULink<JPABaseParticle>* next = link->getNext();
        mChildParticles.remove(link);
        mpPtclVacList->prepend(link);
        link = next;
    }
}

/* 8025DB68-8025DBB4       .text getPtclFromVacList__14JPABaseEmitterFv */
JPABaseParticle * JPABaseEmitter::getPtclFromVacList() {
    JPABaseParticle * ptcl = NULL;
    if (mpPtclVacList->getNumLinks() != 0) {
        ptcl = (JPABaseParticle*)mpPtclVacList->getFirstLink()->getObjectPtr();
        mpPtclVacList->remove(&ptcl->mLink);
    }
    return ptcl;
}

/* 8025DBB4-8025DC2C       .text doStartFrameProcess__14JPABaseEmitterFv */
bool JPABaseEmitter::doStartFrameProcess() {
    /* Nonmatching */
    if (mTime >= mStartFrame)
        return true;

    if (!checkStatus(JPAEmtrStts_StopCalc)) {
        mTime++;
        if (mTime < 0.0f)
            mTime = 0.0f;
    }

    return false;
}

/* 8025DC2C-8025DCDC       .text doTerminationProcess__14JPABaseEmitterFv */
bool JPABaseEmitter::doTerminationProcess() {
    if (mMaxFrame == 0) {
        return false;
    } else if (mMaxFrame < 0) {
        mFlags |= JPAEmtrStts_EnableDeleteEmitter;
        return getParticleNumber() == 0;
    } else if (mTick >= mMaxFrame) {
        mFlags |= JPAEmtrStts_EnableDeleteEmitter;
        if (mFlags & JPAEmtrStts_Immortal)
            return false;
        return getParticleNumber() == 0;
    } else {
        return false;
    }
}

/* 8025DCDC-8025DD5C       .text calcEmitterGlobalPosition__14JPABaseEmitterFRQ29JGeometry8TVec3<f> */
void JPABaseEmitter::calcEmitterGlobalPosition(JGeometry::TVec3<float>& dst) {
    Mtx mtx;
    MTXScale(mtx, mGlobalDynamicsScale.x, mGlobalDynamicsScale.y, mGlobalDynamicsScale.z);
    MTXConcat(mGlobalRotation, mtx, mtx);
    mtx[0][3] = mGlobalTranslation.x;
    mtx[1][3] = mGlobalTranslation.y;
    mtx[2][3] = mGlobalTranslation.z;
    MTXMultVec(mtx, mEmitterTranslation, dst);
}

/* 8025DD5C-8025DDE8       .text calcgReRDirection__14JPABaseEmitterFv */
void JPABaseEmitter::calcgReRDirection() {
    // gReR = globalRotation emitterRotation
    Mtx mtx;
    JPAGetXYZRotateMtx((mEmitterRot.x << 14) / 0x5a, (mEmitterRot.y << 14) / 0x5a, (mEmitterRot.z << 14) / 0x5a, mtx);
    MTXConcat(mGlobalRotation, mtx, mtx);
    MTXMultVec(mtx, mEmitterDir, emtrInfo.mgReRDir);
}

/* 8025DDE8-8025DE2C       .text getPivotX__14JPABaseEmitterFv */
u32 JPABaseEmitter::getPivotX() {
    if (getEmitterDataBlockInfoPtr()->getExtraShape() != NULL)
        return getEmitterDataBlockInfoPtr()->getExtraShape()->getPivotX();
    else
        return 1;
}

/* 8025DE2C-8025DE70       .text getPivotY__14JPABaseEmitterFv */
u32 JPABaseEmitter::getPivotY() {
    if (getEmitterDataBlockInfoPtr()->getExtraShape() != NULL)
        return getEmitterDataBlockInfoPtr()->getExtraShape()->getPivotY();
    else
        return 1;
}
