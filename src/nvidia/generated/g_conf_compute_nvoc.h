#ifndef _G_CONF_COMPUTE_NVOC_H_
#define _G_CONF_COMPUTE_NVOC_H_
#include "nvoc/runtime.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * SPDX-FileCopyrightText: Copyright (c) 2021-2024 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "g_conf_compute_nvoc.h"

#ifndef CONF_COMPUTE_H
#define CONF_COMPUTE_H

#include "gpu/gpu.h"
#include "gpu/eng_state.h"
#include "gpu/spdm/spdm.h"
#include "ctrl/ctrl2080/ctrl2080spdm.h"
#include "ctrl/ctrl2080/ctrl2080internal.h"
#include "ctrl/ctrlc56f.h"
#include "cc_drv.h"
#include "conf_compute/cc_keystore.h"
#include "conf_compute/cc_keyrotation.h"
#include "kernel/gpu/fifo/kernel_channel.h"
#include "kernel/gpu/fifo/kernel_fifo.h"
#include "kernel/gpu/intr/engine_idx.h"
#include "kernel/gpu/conf_compute/ccsl_context.h"
#include "objtmr.h"

/****************************************************************************\
 *                                                                           *
 *      Confidential Compute module header.                                  *
 *                                                                           *
 ****************************************************************************/

//
// Per-key info regarding encryption ops
typedef struct
{
    NvU64 totalBytesEncrypted;
    NvU64 totalEncryptOps;
} KEY_ROTATION_STATS_INFO;

// Info needed by workitem to perform key rotation
typedef struct
{
    NvU32 h2dKey;
    NvU32 d2hKey;
    KEY_ROTATION_STATUS status;
} KEY_ROTATION_WORKITEM_INFO;

// Info needed by timer to setup timeouts for key rotation
typedef struct
{
    TMR_EVENT *pTimer;
    NvU64      timeLeftNs; // time left before hitting timeout
} KEY_ROTATION_TIMEOUT_INFO;


// Private field names are wrapped in PRIVATE_FIELD, which does nothing for
// the matching C source file, but causes diagnostics to be issued if another
// source file references the field.
#ifdef NVOC_CONF_COMPUTE_H_PRIVATE_ACCESS_ALLOWED
#define PRIVATE_FIELD(x) x
#else
#define PRIVATE_FIELD(x) NVOC_PRIVATE_FIELD(x)
#endif

struct ConfidentialCompute {
    const struct NVOC_RTTI *__nvoc_rtti;
    struct OBJENGSTATE __nvoc_base_OBJENGSTATE;
    struct Object *__nvoc_pbase_Object;
    struct OBJENGSTATE *__nvoc_pbase_OBJENGSTATE;
    struct ConfidentialCompute *__nvoc_pbase_ConfidentialCompute;
    NV_STATUS (*__confComputeConstructEngine__)(struct OBJGPU *, struct ConfidentialCompute *, ENGDESCRIPTOR);
    void (*__confComputeDestruct__)(struct ConfidentialCompute *);
    NV_STATUS (*__confComputeStatePreInitLocked__)(struct OBJGPU *, struct ConfidentialCompute *);
    NV_STATUS (*__confComputeStateInitLocked__)(struct OBJGPU *, struct ConfidentialCompute *);
    NV_STATUS (*__confComputeStatePostLoad__)(struct OBJGPU *, struct ConfidentialCompute *, NvU32);
    NV_STATUS (*__confComputeStatePreUnload__)(struct OBJGPU *, struct ConfidentialCompute *, NvU32);
    void (*__confComputeSetErrorState__)(struct OBJGPU *, struct ConfidentialCompute *);
    NV_STATUS (*__confComputeKeyStoreRetrieveViaChannel__)(struct ConfidentialCompute *, struct KernelChannel *, ROTATE_IV_TYPE, NvBool, CC_KMB *);
    NV_STATUS (*__confComputeKeyStoreRetrieveViaKeyId__)(struct ConfidentialCompute *, NvU32, ROTATE_IV_TYPE, NvBool, CC_KMB *);
    NV_STATUS (*__confComputeDeriveSecrets__)(struct ConfidentialCompute *, NvU32);
    NV_STATUS (*__confComputeUpdateSecrets__)(struct ConfidentialCompute *, NvU32);
    NvBool (*__confComputeIsSpdmEnabled__)(struct OBJGPU *, struct ConfidentialCompute *);
    RM_ENGINE_TYPE (*__confComputeGetEngineIdFromKeySpace__)(struct ConfidentialCompute *, NvU32);
    NvBool (*__confComputeGlobalKeyIsKernelPriv__)(struct ConfidentialCompute *, NvU32);
    NvBool (*__confComputeGlobalKeyIsUvmKey__)(struct ConfidentialCompute *, NvU32);
    NV_STATUS (*__confComputeGetKeyPairByChannel__)(struct OBJGPU *, struct ConfidentialCompute *, struct KernelChannel *, NvU32 *, NvU32 *);
    NV_STATUS (*__confComputeTriggerKeyRotation__)(struct OBJGPU *, struct ConfidentialCompute *);
    void (*__confComputeGetKeyPairForKeySpace__)(struct OBJGPU *, struct ConfidentialCompute *, NvU32, NvBool, NvU32 *, NvU32 *);
    NV_STATUS (*__confComputeEnableKeyRotationCallback__)(struct OBJGPU *, struct ConfidentialCompute *, NvBool);
    NV_STATUS (*__confComputeEnableKeyRotationSupport__)(struct OBJGPU *, struct ConfidentialCompute *);
    NV_STATUS (*__confComputeEnableInternalKeyRotationSupport__)(struct OBJGPU *, struct ConfidentialCompute *);
    NvBool (*__confComputeIsDebugModeEnabled__)(struct OBJGPU *, struct ConfidentialCompute *);
    NvBool (*__confComputeIsGpuCcCapable__)(struct OBJGPU *, struct ConfidentialCompute *);
    NV_STATUS (*__confComputeEstablishSpdmSessionAndKeys__)(struct OBJGPU *, struct ConfidentialCompute *);
    void (*__confComputeKeyStoreDepositIvMask__)(struct ConfidentialCompute *, NvU32, void *);
    NV_STATUS (*__confComputeKeyStoreUpdateKey__)(struct ConfidentialCompute *, NvU32);
    NvBool (*__confComputeKeyStoreIsValidGlobalKeyId__)(struct ConfidentialCompute *, NvU32);
    NV_STATUS (*__confComputeKeyStoreInit__)(struct ConfidentialCompute *);
    void (*__confComputeKeyStoreDeinit__)(struct ConfidentialCompute *);
    void *(*__confComputeKeyStoreGetExportMasterKey__)(struct ConfidentialCompute *);
    NV_STATUS (*__confComputeKeyStoreDeriveKey__)(struct ConfidentialCompute *, NvU32);
    void (*__confComputeKeyStoreClearExportMasterKey__)(struct ConfidentialCompute *);
    NV_STATUS (*__confComputeStateLoad__)(POBJGPU, struct ConfidentialCompute *, NvU32);
    NV_STATUS (*__confComputeStateUnload__)(POBJGPU, struct ConfidentialCompute *, NvU32);
    NV_STATUS (*__confComputeStatePreLoad__)(POBJGPU, struct ConfidentialCompute *, NvU32);
    NV_STATUS (*__confComputeStatePostUnload__)(POBJGPU, struct ConfidentialCompute *, NvU32);
    void (*__confComputeStateDestroy__)(POBJGPU, struct ConfidentialCompute *);
    NV_STATUS (*__confComputeStateInitUnlocked__)(POBJGPU, struct ConfidentialCompute *);
    void (*__confComputeInitMissing__)(POBJGPU, struct ConfidentialCompute *);
    NV_STATUS (*__confComputeStatePreInitUnlocked__)(POBJGPU, struct ConfidentialCompute *);
    NvBool (*__confComputeIsPresent__)(POBJGPU, struct ConfidentialCompute *);
    NvBool PDB_PROP_CONFCOMPUTE_ENABLED;
    NvBool PDB_PROP_CONFCOMPUTE_CC_FEATURE_ENABLED;
    NvBool PDB_PROP_CONFCOMPUTE_APM_FEATURE_ENABLED;
    NvBool PDB_PROP_CONFCOMPUTE_DEVTOOLS_MODE_ENABLED;
    NvBool PDB_PROP_CONFCOMPUTE_ENABLE_EARLY_INIT;
    NvBool PDB_PROP_CONFCOMPUTE_GPUS_READY_CHECK_ENABLED;
    NvBool PDB_PROP_CONFCOMPUTE_SPDM_ENABLED;
    NvBool PDB_PROP_CONFCOMPUTE_MULTI_GPU_PROTECTED_PCIE_MODE_ENABLED;
    NvBool PDB_PROP_CONFCOMPUTE_KEY_ROTATION_SUPPORTED;
    NvBool PDB_PROP_CONFCOMPUTE_KEY_ROTATION_ENABLED;
    NvBool PDB_PROP_CONFCOMPUTE_INTERNAL_KEY_ROTATION_ENABLED;
    NvU32 gspProxyRegkeys;
    struct Spdm *pSpdm;
    NV2080_CTRL_INTERNAL_CONF_COMPUTE_GET_STATIC_INFO_PARAMS ccStaticInfo;
    struct ccslContext_t *pRpcCcslCtx;
    struct ccslContext_t *pDmaCcslCtx;
    struct ccslContext_t *pNonReplayableFaultCcslCtx;
    struct ccslContext_t *pReplayableFaultCcslCtx;
    struct ccslContext_t *pGspSec2RpcCcslCtx;
    NvBool bAcceptClientRequest;
    PTMR_EVENT pGspHeartbeatTimer;
    NvU32 heartbeatPeriodSec;
    NvU32 keyRotationEnableMask;
    NvU64 keyRotationInternalThreshold;
    NvU64 attackerAdvantage;
    KEY_ROTATION_STATS_INFO aggregateStats[64];
    NvU8 PRIVATE_FIELD(m_exportMasterKey)[32];
    void *PRIVATE_FIELD(m_keySlot);
    KEY_ROTATION_STATUS PRIVATE_FIELD(keyRotationState)[64];
    KEY_ROTATION_STATS_INFO PRIVATE_FIELD(freedChannelAggregateStats)[64];
    KEY_ROTATION_TIMEOUT_INFO PRIVATE_FIELD(keyRotationTimeoutInfo)[64];
    NvU32 PRIVATE_FIELD(keyRotationCount)[64];
    NvU32 PRIVATE_FIELD(keyRotationTimeout);
    NvU64 PRIVATE_FIELD(keyRotationThresholdDelta);
    NvU64 PRIVATE_FIELD(keyRotationUpperThreshold);
    NvU64 PRIVATE_FIELD(keyRotationLowerThreshold);
};

#ifndef __NVOC_CLASS_ConfidentialCompute_TYPEDEF__
#define __NVOC_CLASS_ConfidentialCompute_TYPEDEF__
typedef struct ConfidentialCompute ConfidentialCompute;
#endif /* __NVOC_CLASS_ConfidentialCompute_TYPEDEF__ */

#ifndef __nvoc_class_id_ConfidentialCompute
#define __nvoc_class_id_ConfidentialCompute 0x9798cc
#endif /* __nvoc_class_id_ConfidentialCompute */

extern const struct NVOC_CLASS_DEF __nvoc_class_def_ConfidentialCompute;

#define __staticCast_ConfidentialCompute(pThis) \
    ((pThis)->__nvoc_pbase_ConfidentialCompute)

#ifdef __nvoc_conf_compute_h_disabled
#define __dynamicCast_ConfidentialCompute(pThis) ((ConfidentialCompute*)NULL)
#else //__nvoc_conf_compute_h_disabled
#define __dynamicCast_ConfidentialCompute(pThis) \
    ((ConfidentialCompute*)__nvoc_dynamicCast(staticCast((pThis), Dynamic), classInfo(ConfidentialCompute)))
#endif //__nvoc_conf_compute_h_disabled

#define PDB_PROP_CONFCOMPUTE_KEY_ROTATION_SUPPORTED_BASE_CAST
#define PDB_PROP_CONFCOMPUTE_KEY_ROTATION_SUPPORTED_BASE_NAME PDB_PROP_CONFCOMPUTE_KEY_ROTATION_SUPPORTED
#define PDB_PROP_CONFCOMPUTE_INTERNAL_KEY_ROTATION_ENABLED_BASE_CAST
#define PDB_PROP_CONFCOMPUTE_INTERNAL_KEY_ROTATION_ENABLED_BASE_NAME PDB_PROP_CONFCOMPUTE_INTERNAL_KEY_ROTATION_ENABLED
#define PDB_PROP_CONFCOMPUTE_KEY_ROTATION_ENABLED_BASE_CAST
#define PDB_PROP_CONFCOMPUTE_KEY_ROTATION_ENABLED_BASE_NAME PDB_PROP_CONFCOMPUTE_KEY_ROTATION_ENABLED
#define PDB_PROP_CONFCOMPUTE_APM_FEATURE_ENABLED_BASE_CAST
#define PDB_PROP_CONFCOMPUTE_APM_FEATURE_ENABLED_BASE_NAME PDB_PROP_CONFCOMPUTE_APM_FEATURE_ENABLED
#define PDB_PROP_CONFCOMPUTE_IS_MISSING_BASE_CAST __nvoc_base_OBJENGSTATE.
#define PDB_PROP_CONFCOMPUTE_IS_MISSING_BASE_NAME PDB_PROP_ENGSTATE_IS_MISSING
#define PDB_PROP_CONFCOMPUTE_ENABLE_EARLY_INIT_BASE_CAST
#define PDB_PROP_CONFCOMPUTE_ENABLE_EARLY_INIT_BASE_NAME PDB_PROP_CONFCOMPUTE_ENABLE_EARLY_INIT
#define PDB_PROP_CONFCOMPUTE_GPUS_READY_CHECK_ENABLED_BASE_CAST
#define PDB_PROP_CONFCOMPUTE_GPUS_READY_CHECK_ENABLED_BASE_NAME PDB_PROP_CONFCOMPUTE_GPUS_READY_CHECK_ENABLED
#define PDB_PROP_CONFCOMPUTE_ENABLED_BASE_CAST
#define PDB_PROP_CONFCOMPUTE_ENABLED_BASE_NAME PDB_PROP_CONFCOMPUTE_ENABLED
#define PDB_PROP_CONFCOMPUTE_CC_FEATURE_ENABLED_BASE_CAST
#define PDB_PROP_CONFCOMPUTE_CC_FEATURE_ENABLED_BASE_NAME PDB_PROP_CONFCOMPUTE_CC_FEATURE_ENABLED
#define PDB_PROP_CONFCOMPUTE_MULTI_GPU_PROTECTED_PCIE_MODE_ENABLED_BASE_CAST
#define PDB_PROP_CONFCOMPUTE_MULTI_GPU_PROTECTED_PCIE_MODE_ENABLED_BASE_NAME PDB_PROP_CONFCOMPUTE_MULTI_GPU_PROTECTED_PCIE_MODE_ENABLED
#define PDB_PROP_CONFCOMPUTE_DEVTOOLS_MODE_ENABLED_BASE_CAST
#define PDB_PROP_CONFCOMPUTE_DEVTOOLS_MODE_ENABLED_BASE_NAME PDB_PROP_CONFCOMPUTE_DEVTOOLS_MODE_ENABLED
#define PDB_PROP_CONFCOMPUTE_SPDM_ENABLED_BASE_CAST
#define PDB_PROP_CONFCOMPUTE_SPDM_ENABLED_BASE_NAME PDB_PROP_CONFCOMPUTE_SPDM_ENABLED

NV_STATUS __nvoc_objCreateDynamic_ConfidentialCompute(ConfidentialCompute**, Dynamic*, NvU32, va_list);

NV_STATUS __nvoc_objCreate_ConfidentialCompute(ConfidentialCompute**, Dynamic*, NvU32);
#define __objCreate_ConfidentialCompute(ppNewObj, pParent, createFlags) \
    __nvoc_objCreate_ConfidentialCompute((ppNewObj), staticCast((pParent), Dynamic), (createFlags))

#define confComputeConstructEngine(pGpu, pConfCompute, engDesc) confComputeConstructEngine_DISPATCH(pGpu, pConfCompute, engDesc)
#define __nvoc_confComputeDestruct(pConfCompute) confComputeDestruct_DISPATCH(pConfCompute)
#define confComputeStatePreInitLocked(pGpu, pConfCompute) confComputeStatePreInitLocked_DISPATCH(pGpu, pConfCompute)
#define confComputeStatePreInitLocked_HAL(pGpu, pConfCompute) confComputeStatePreInitLocked_DISPATCH(pGpu, pConfCompute)
#define confComputeStateInitLocked(pGpu, pConfCompute) confComputeStateInitLocked_DISPATCH(pGpu, pConfCompute)
#define confComputeStatePostLoad(pGpu, pConfCompute, flags) confComputeStatePostLoad_DISPATCH(pGpu, pConfCompute, flags)
#define confComputeStatePostLoad_HAL(pGpu, pConfCompute, flags) confComputeStatePostLoad_DISPATCH(pGpu, pConfCompute, flags)
#define confComputeStatePreUnload(pGpu, pConfCompute, flags) confComputeStatePreUnload_DISPATCH(pGpu, pConfCompute, flags)
#define confComputeStatePreUnload_HAL(pGpu, pConfCompute, flags) confComputeStatePreUnload_DISPATCH(pGpu, pConfCompute, flags)
#define confComputeSetErrorState(pGpu, pConfCompute) confComputeSetErrorState_DISPATCH(pGpu, pConfCompute)
#define confComputeSetErrorState_HAL(pGpu, pConfCompute) confComputeSetErrorState_DISPATCH(pGpu, pConfCompute)
#define confComputeKeyStoreRetrieveViaChannel(pConfCompute, pKernelChannel, rotateOperation, bIncludeIvOrNonce, keyMaterialBundle) confComputeKeyStoreRetrieveViaChannel_DISPATCH(pConfCompute, pKernelChannel, rotateOperation, bIncludeIvOrNonce, keyMaterialBundle)
#define confComputeKeyStoreRetrieveViaChannel_HAL(pConfCompute, pKernelChannel, rotateOperation, bIncludeIvOrNonce, keyMaterialBundle) confComputeKeyStoreRetrieveViaChannel_DISPATCH(pConfCompute, pKernelChannel, rotateOperation, bIncludeIvOrNonce, keyMaterialBundle)
#define confComputeKeyStoreRetrieveViaKeyId(pConfCompute, globalKeyId, rotateOperation, bIncludeIvOrNonce, keyMaterialBundle) confComputeKeyStoreRetrieveViaKeyId_DISPATCH(pConfCompute, globalKeyId, rotateOperation, bIncludeIvOrNonce, keyMaterialBundle)
#define confComputeKeyStoreRetrieveViaKeyId_HAL(pConfCompute, globalKeyId, rotateOperation, bIncludeIvOrNonce, keyMaterialBundle) confComputeKeyStoreRetrieveViaKeyId_DISPATCH(pConfCompute, globalKeyId, rotateOperation, bIncludeIvOrNonce, keyMaterialBundle)
#define confComputeDeriveSecrets(pConfCompute, engine) confComputeDeriveSecrets_DISPATCH(pConfCompute, engine)
#define confComputeDeriveSecrets_HAL(pConfCompute, engine) confComputeDeriveSecrets_DISPATCH(pConfCompute, engine)
#define confComputeUpdateSecrets(pConfCompute, globalKeyId) confComputeUpdateSecrets_DISPATCH(pConfCompute, globalKeyId)
#define confComputeUpdateSecrets_HAL(pConfCompute, globalKeyId) confComputeUpdateSecrets_DISPATCH(pConfCompute, globalKeyId)
#define confComputeIsSpdmEnabled(pGpu, pConfCompute) confComputeIsSpdmEnabled_DISPATCH(pGpu, pConfCompute)
#define confComputeIsSpdmEnabled_HAL(pGpu, pConfCompute) confComputeIsSpdmEnabled_DISPATCH(pGpu, pConfCompute)
#define confComputeGetEngineIdFromKeySpace(pConfCompute, keySpace) confComputeGetEngineIdFromKeySpace_DISPATCH(pConfCompute, keySpace)
#define confComputeGetEngineIdFromKeySpace_HAL(pConfCompute, keySpace) confComputeGetEngineIdFromKeySpace_DISPATCH(pConfCompute, keySpace)
#define confComputeGlobalKeyIsKernelPriv(pConfCompute, keyId) confComputeGlobalKeyIsKernelPriv_DISPATCH(pConfCompute, keyId)
#define confComputeGlobalKeyIsKernelPriv_HAL(pConfCompute, keyId) confComputeGlobalKeyIsKernelPriv_DISPATCH(pConfCompute, keyId)
#define confComputeGlobalKeyIsUvmKey(pConfCompute, keyId) confComputeGlobalKeyIsUvmKey_DISPATCH(pConfCompute, keyId)
#define confComputeGlobalKeyIsUvmKey_HAL(pConfCompute, keyId) confComputeGlobalKeyIsUvmKey_DISPATCH(pConfCompute, keyId)
#define confComputeGetKeyPairByChannel(pGpu, pConfCompute, pKernelChannel, pH2DKey, pD2HKey) confComputeGetKeyPairByChannel_DISPATCH(pGpu, pConfCompute, pKernelChannel, pH2DKey, pD2HKey)
#define confComputeGetKeyPairByChannel_HAL(pGpu, pConfCompute, pKernelChannel, pH2DKey, pD2HKey) confComputeGetKeyPairByChannel_DISPATCH(pGpu, pConfCompute, pKernelChannel, pH2DKey, pD2HKey)
#define confComputeTriggerKeyRotation(pGpu, pConfCompute) confComputeTriggerKeyRotation_DISPATCH(pGpu, pConfCompute)
#define confComputeTriggerKeyRotation_HAL(pGpu, pConfCompute) confComputeTriggerKeyRotation_DISPATCH(pGpu, pConfCompute)
#define confComputeGetKeyPairForKeySpace(pGpu, pConfCompute, arg0, arg1, arg2, arg3) confComputeGetKeyPairForKeySpace_DISPATCH(pGpu, pConfCompute, arg0, arg1, arg2, arg3)
#define confComputeGetKeyPairForKeySpace_HAL(pGpu, pConfCompute, arg0, arg1, arg2, arg3) confComputeGetKeyPairForKeySpace_DISPATCH(pGpu, pConfCompute, arg0, arg1, arg2, arg3)
#define confComputeEnableKeyRotationCallback(pGpu, pConfCompute, bEnable) confComputeEnableKeyRotationCallback_DISPATCH(pGpu, pConfCompute, bEnable)
#define confComputeEnableKeyRotationCallback_HAL(pGpu, pConfCompute, bEnable) confComputeEnableKeyRotationCallback_DISPATCH(pGpu, pConfCompute, bEnable)
#define confComputeEnableKeyRotationSupport(pGpu, pConfCompute) confComputeEnableKeyRotationSupport_DISPATCH(pGpu, pConfCompute)
#define confComputeEnableKeyRotationSupport_HAL(pGpu, pConfCompute) confComputeEnableKeyRotationSupport_DISPATCH(pGpu, pConfCompute)
#define confComputeEnableInternalKeyRotationSupport(pGpu, pConfCompute) confComputeEnableInternalKeyRotationSupport_DISPATCH(pGpu, pConfCompute)
#define confComputeEnableInternalKeyRotationSupport_HAL(pGpu, pConfCompute) confComputeEnableInternalKeyRotationSupport_DISPATCH(pGpu, pConfCompute)
#define confComputeIsDebugModeEnabled(pGpu, pConfCompute) confComputeIsDebugModeEnabled_DISPATCH(pGpu, pConfCompute)
#define confComputeIsDebugModeEnabled_HAL(pGpu, pConfCompute) confComputeIsDebugModeEnabled_DISPATCH(pGpu, pConfCompute)
#define confComputeIsGpuCcCapable(pGpu, pConfCompute) confComputeIsGpuCcCapable_DISPATCH(pGpu, pConfCompute)
#define confComputeIsGpuCcCapable_HAL(pGpu, pConfCompute) confComputeIsGpuCcCapable_DISPATCH(pGpu, pConfCompute)
#define confComputeEstablishSpdmSessionAndKeys(pGpu, pConfCompute) confComputeEstablishSpdmSessionAndKeys_DISPATCH(pGpu, pConfCompute)
#define confComputeEstablishSpdmSessionAndKeys_HAL(pGpu, pConfCompute) confComputeEstablishSpdmSessionAndKeys_DISPATCH(pGpu, pConfCompute)
#define confComputeKeyStoreDepositIvMask(pConfCompute, globalKeyId, ivMask) confComputeKeyStoreDepositIvMask_DISPATCH(pConfCompute, globalKeyId, ivMask)
#define confComputeKeyStoreDepositIvMask_HAL(pConfCompute, globalKeyId, ivMask) confComputeKeyStoreDepositIvMask_DISPATCH(pConfCompute, globalKeyId, ivMask)
#define confComputeKeyStoreUpdateKey(pConfCompute, globalKeyId) confComputeKeyStoreUpdateKey_DISPATCH(pConfCompute, globalKeyId)
#define confComputeKeyStoreUpdateKey_HAL(pConfCompute, globalKeyId) confComputeKeyStoreUpdateKey_DISPATCH(pConfCompute, globalKeyId)
#define confComputeKeyStoreIsValidGlobalKeyId(pConfCompute, globalKeyId) confComputeKeyStoreIsValidGlobalKeyId_DISPATCH(pConfCompute, globalKeyId)
#define confComputeKeyStoreIsValidGlobalKeyId_HAL(pConfCompute, globalKeyId) confComputeKeyStoreIsValidGlobalKeyId_DISPATCH(pConfCompute, globalKeyId)
#define confComputeKeyStoreInit(pConfCompute) confComputeKeyStoreInit_DISPATCH(pConfCompute)
#define confComputeKeyStoreInit_HAL(pConfCompute) confComputeKeyStoreInit_DISPATCH(pConfCompute)
#define confComputeKeyStoreDeinit(pConfCompute) confComputeKeyStoreDeinit_DISPATCH(pConfCompute)
#define confComputeKeyStoreDeinit_HAL(pConfCompute) confComputeKeyStoreDeinit_DISPATCH(pConfCompute)
#define confComputeKeyStoreGetExportMasterKey(pConfCompute) confComputeKeyStoreGetExportMasterKey_DISPATCH(pConfCompute)
#define confComputeKeyStoreGetExportMasterKey_HAL(pConfCompute) confComputeKeyStoreGetExportMasterKey_DISPATCH(pConfCompute)
#define confComputeKeyStoreDeriveKey(pConfCompute, globalKeyId) confComputeKeyStoreDeriveKey_DISPATCH(pConfCompute, globalKeyId)
#define confComputeKeyStoreDeriveKey_HAL(pConfCompute, globalKeyId) confComputeKeyStoreDeriveKey_DISPATCH(pConfCompute, globalKeyId)
#define confComputeKeyStoreClearExportMasterKey(pConfCompute) confComputeKeyStoreClearExportMasterKey_DISPATCH(pConfCompute)
#define confComputeKeyStoreClearExportMasterKey_HAL(pConfCompute) confComputeKeyStoreClearExportMasterKey_DISPATCH(pConfCompute)
#define confComputeStateLoad(pGpu, pEngstate, arg0) confComputeStateLoad_DISPATCH(pGpu, pEngstate, arg0)
#define confComputeStateUnload(pGpu, pEngstate, arg0) confComputeStateUnload_DISPATCH(pGpu, pEngstate, arg0)
#define confComputeStatePreLoad(pGpu, pEngstate, arg0) confComputeStatePreLoad_DISPATCH(pGpu, pEngstate, arg0)
#define confComputeStatePostUnload(pGpu, pEngstate, arg0) confComputeStatePostUnload_DISPATCH(pGpu, pEngstate, arg0)
#define confComputeStateDestroy(pGpu, pEngstate) confComputeStateDestroy_DISPATCH(pGpu, pEngstate)
#define confComputeStateInitUnlocked(pGpu, pEngstate) confComputeStateInitUnlocked_DISPATCH(pGpu, pEngstate)
#define confComputeInitMissing(pGpu, pEngstate) confComputeInitMissing_DISPATCH(pGpu, pEngstate)
#define confComputeStatePreInitUnlocked(pGpu, pEngstate) confComputeStatePreInitUnlocked_DISPATCH(pGpu, pEngstate)
#define confComputeIsPresent(pGpu, pEngstate) confComputeIsPresent_DISPATCH(pGpu, pEngstate)
static inline NV_STATUS confComputeEarlyInit_56cd7a(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    return NV_OK;
}


#ifdef __nvoc_conf_compute_h_disabled
static inline NV_STATUS confComputeEarlyInit(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    NV_ASSERT_FAILED_PRECOMP("ConfidentialCompute was disabled!");
    return NV_ERR_NOT_SUPPORTED;
}
#else //__nvoc_conf_compute_h_disabled
#define confComputeEarlyInit(pGpu, pConfCompute) confComputeEarlyInit_56cd7a(pGpu, pConfCompute)
#endif //__nvoc_conf_compute_h_disabled

#define confComputeEarlyInit_HAL(pGpu, pConfCompute) confComputeEarlyInit(pGpu, pConfCompute)

NV_STATUS confComputeConstructEngine_IMPL(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, ENGDESCRIPTOR engDesc);

static inline NV_STATUS confComputeConstructEngine_DISPATCH(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, ENGDESCRIPTOR engDesc) {
    return pConfCompute->__confComputeConstructEngine__(pGpu, pConfCompute, engDesc);
}

void confComputeDestruct_KERNEL(struct ConfidentialCompute *pConfCompute);

static inline void confComputeDestruct_b3696a(struct ConfidentialCompute *pConfCompute) {
    return;
}

static inline void confComputeDestruct_DISPATCH(struct ConfidentialCompute *pConfCompute) {
    pConfCompute->__confComputeDestruct__(pConfCompute);
}

static inline NV_STATUS confComputeStatePreInitLocked_56cd7a(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    return NV_OK;
}

static inline NV_STATUS confComputeStatePreInitLocked_DISPATCH(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    return pConfCompute->__confComputeStatePreInitLocked__(pGpu, pConfCompute);
}

NV_STATUS confComputeStateInitLocked_IMPL(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute);

static inline NV_STATUS confComputeStateInitLocked_DISPATCH(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    return pConfCompute->__confComputeStateInitLocked__(pGpu, pConfCompute);
}

NV_STATUS confComputeStatePostLoad_IMPL(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvU32 flags);

static inline NV_STATUS confComputeStatePostLoad_56cd7a(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvU32 flags) {
    return NV_OK;
}

static inline NV_STATUS confComputeStatePostLoad_DISPATCH(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvU32 flags) {
    return pConfCompute->__confComputeStatePostLoad__(pGpu, pConfCompute, flags);
}

NV_STATUS confComputeStatePreUnload_KERNEL(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvU32 flags);

static inline NV_STATUS confComputeStatePreUnload_56cd7a(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvU32 flags) {
    return NV_OK;
}

static inline NV_STATUS confComputeStatePreUnload_DISPATCH(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvU32 flags) {
    return pConfCompute->__confComputeStatePreUnload__(pGpu, pConfCompute, flags);
}

void confComputeSetErrorState_KERNEL(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute);

static inline void confComputeSetErrorState_b3696a(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    return;
}

static inline void confComputeSetErrorState_DISPATCH(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    pConfCompute->__confComputeSetErrorState__(pGpu, pConfCompute);
}

NV_STATUS confComputeKeyStoreRetrieveViaChannel_GH100(struct ConfidentialCompute *pConfCompute, struct KernelChannel *pKernelChannel, ROTATE_IV_TYPE rotateOperation, NvBool bIncludeIvOrNonce, CC_KMB *keyMaterialBundle);

static inline NV_STATUS confComputeKeyStoreRetrieveViaChannel_46f6a7(struct ConfidentialCompute *pConfCompute, struct KernelChannel *pKernelChannel, ROTATE_IV_TYPE rotateOperation, NvBool bIncludeIvOrNonce, CC_KMB *keyMaterialBundle) {
    return NV_ERR_NOT_SUPPORTED;
}

static inline NV_STATUS confComputeKeyStoreRetrieveViaChannel_DISPATCH(struct ConfidentialCompute *pConfCompute, struct KernelChannel *pKernelChannel, ROTATE_IV_TYPE rotateOperation, NvBool bIncludeIvOrNonce, CC_KMB *keyMaterialBundle) {
    return pConfCompute->__confComputeKeyStoreRetrieveViaChannel__(pConfCompute, pKernelChannel, rotateOperation, bIncludeIvOrNonce, keyMaterialBundle);
}

NV_STATUS confComputeKeyStoreRetrieveViaKeyId_GH100(struct ConfidentialCompute *pConfCompute, NvU32 globalKeyId, ROTATE_IV_TYPE rotateOperation, NvBool bIncludeIvOrNonce, CC_KMB *keyMaterialBundle);

static inline NV_STATUS confComputeKeyStoreRetrieveViaKeyId_46f6a7(struct ConfidentialCompute *pConfCompute, NvU32 globalKeyId, ROTATE_IV_TYPE rotateOperation, NvBool bIncludeIvOrNonce, CC_KMB *keyMaterialBundle) {
    return NV_ERR_NOT_SUPPORTED;
}

static inline NV_STATUS confComputeKeyStoreRetrieveViaKeyId_DISPATCH(struct ConfidentialCompute *pConfCompute, NvU32 globalKeyId, ROTATE_IV_TYPE rotateOperation, NvBool bIncludeIvOrNonce, CC_KMB *keyMaterialBundle) {
    return pConfCompute->__confComputeKeyStoreRetrieveViaKeyId__(pConfCompute, globalKeyId, rotateOperation, bIncludeIvOrNonce, keyMaterialBundle);
}

NV_STATUS confComputeDeriveSecrets_GH100(struct ConfidentialCompute *pConfCompute, NvU32 engine);

static inline NV_STATUS confComputeDeriveSecrets_46f6a7(struct ConfidentialCompute *pConfCompute, NvU32 engine) {
    return NV_ERR_NOT_SUPPORTED;
}

static inline NV_STATUS confComputeDeriveSecrets_DISPATCH(struct ConfidentialCompute *pConfCompute, NvU32 engine) {
    return pConfCompute->__confComputeDeriveSecrets__(pConfCompute, engine);
}

NV_STATUS confComputeUpdateSecrets_GH100(struct ConfidentialCompute *pConfCompute, NvU32 globalKeyId);

static inline NV_STATUS confComputeUpdateSecrets_46f6a7(struct ConfidentialCompute *pConfCompute, NvU32 globalKeyId) {
    return NV_ERR_NOT_SUPPORTED;
}

static inline NV_STATUS confComputeUpdateSecrets_DISPATCH(struct ConfidentialCompute *pConfCompute, NvU32 globalKeyId) {
    return pConfCompute->__confComputeUpdateSecrets__(pConfCompute, globalKeyId);
}

static inline NvBool confComputeIsSpdmEnabled_cbe027(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    return ((NvBool)(0 == 0));
}

static inline NvBool confComputeIsSpdmEnabled_491d52(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    return ((NvBool)(0 != 0));
}

static inline NvBool confComputeIsSpdmEnabled_DISPATCH(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    return pConfCompute->__confComputeIsSpdmEnabled__(pGpu, pConfCompute);
}

RM_ENGINE_TYPE confComputeGetEngineIdFromKeySpace_GH100(struct ConfidentialCompute *pConfCompute, NvU32 keySpace);

static inline RM_ENGINE_TYPE confComputeGetEngineIdFromKeySpace_78ac8b(struct ConfidentialCompute *pConfCompute, NvU32 keySpace) {
    return RM_ENGINE_TYPE_NULL;
}

static inline RM_ENGINE_TYPE confComputeGetEngineIdFromKeySpace_DISPATCH(struct ConfidentialCompute *pConfCompute, NvU32 keySpace) {
    return pConfCompute->__confComputeGetEngineIdFromKeySpace__(pConfCompute, keySpace);
}

NvBool confComputeGlobalKeyIsKernelPriv_GH100(struct ConfidentialCompute *pConfCompute, NvU32 keyId);

static inline NvBool confComputeGlobalKeyIsKernelPriv_491d52(struct ConfidentialCompute *pConfCompute, NvU32 keyId) {
    return ((NvBool)(0 != 0));
}

static inline NvBool confComputeGlobalKeyIsKernelPriv_DISPATCH(struct ConfidentialCompute *pConfCompute, NvU32 keyId) {
    return pConfCompute->__confComputeGlobalKeyIsKernelPriv__(pConfCompute, keyId);
}

NvBool confComputeGlobalKeyIsUvmKey_GH100(struct ConfidentialCompute *pConfCompute, NvU32 keyId);

static inline NvBool confComputeGlobalKeyIsUvmKey_491d52(struct ConfidentialCompute *pConfCompute, NvU32 keyId) {
    return ((NvBool)(0 != 0));
}

static inline NvBool confComputeGlobalKeyIsUvmKey_DISPATCH(struct ConfidentialCompute *pConfCompute, NvU32 keyId) {
    return pConfCompute->__confComputeGlobalKeyIsUvmKey__(pConfCompute, keyId);
}

NV_STATUS confComputeGetKeyPairByChannel_GH100(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, struct KernelChannel *pKernelChannel, NvU32 *pH2DKey, NvU32 *pD2HKey);

static inline NV_STATUS confComputeGetKeyPairByChannel_46f6a7(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, struct KernelChannel *pKernelChannel, NvU32 *pH2DKey, NvU32 *pD2HKey) {
    return NV_ERR_NOT_SUPPORTED;
}

static inline NV_STATUS confComputeGetKeyPairByChannel_DISPATCH(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, struct KernelChannel *pKernelChannel, NvU32 *pH2DKey, NvU32 *pD2HKey) {
    return pConfCompute->__confComputeGetKeyPairByChannel__(pGpu, pConfCompute, pKernelChannel, pH2DKey, pD2HKey);
}

NV_STATUS confComputeTriggerKeyRotation_GH100(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute);

static inline NV_STATUS confComputeTriggerKeyRotation_56cd7a(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    return NV_OK;
}

static inline NV_STATUS confComputeTriggerKeyRotation_46f6a7(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    return NV_ERR_NOT_SUPPORTED;
}

static inline NV_STATUS confComputeTriggerKeyRotation_DISPATCH(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    return pConfCompute->__confComputeTriggerKeyRotation__(pGpu, pConfCompute);
}

void confComputeGetKeyPairForKeySpace_GH100(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvU32 arg0, NvBool arg1, NvU32 *arg2, NvU32 *arg3);

static inline void confComputeGetKeyPairForKeySpace_b3696a(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvU32 arg0, NvBool arg1, NvU32 *arg2, NvU32 *arg3) {
    return;
}

static inline void confComputeGetKeyPairForKeySpace_DISPATCH(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvU32 arg0, NvBool arg1, NvU32 *arg2, NvU32 *arg3) {
    pConfCompute->__confComputeGetKeyPairForKeySpace__(pGpu, pConfCompute, arg0, arg1, arg2, arg3);
}

NV_STATUS confComputeEnableKeyRotationCallback_GH100(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvBool bEnable);

static inline NV_STATUS confComputeEnableKeyRotationCallback_56cd7a(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvBool bEnable) {
    return NV_OK;
}

static inline NV_STATUS confComputeEnableKeyRotationCallback_DISPATCH(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvBool bEnable) {
    return pConfCompute->__confComputeEnableKeyRotationCallback__(pGpu, pConfCompute, bEnable);
}

NV_STATUS confComputeEnableKeyRotationSupport_GH100(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute);

static inline NV_STATUS confComputeEnableKeyRotationSupport_56cd7a(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    return NV_OK;
}

static inline NV_STATUS confComputeEnableKeyRotationSupport_DISPATCH(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    return pConfCompute->__confComputeEnableKeyRotationSupport__(pGpu, pConfCompute);
}

NV_STATUS confComputeEnableInternalKeyRotationSupport_GH100(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute);

static inline NV_STATUS confComputeEnableInternalKeyRotationSupport_56cd7a(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    return NV_OK;
}

static inline NV_STATUS confComputeEnableInternalKeyRotationSupport_DISPATCH(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    return pConfCompute->__confComputeEnableInternalKeyRotationSupport__(pGpu, pConfCompute);
}

NvBool confComputeIsDebugModeEnabled_GH100(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute);

static inline NvBool confComputeIsDebugModeEnabled_491d52(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    return ((NvBool)(0 != 0));
}

static inline NvBool confComputeIsDebugModeEnabled_DISPATCH(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    return pConfCompute->__confComputeIsDebugModeEnabled__(pGpu, pConfCompute);
}

NvBool confComputeIsGpuCcCapable_GH100(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute);

static inline NvBool confComputeIsGpuCcCapable_491d52(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    return ((NvBool)(0 != 0));
}

static inline NvBool confComputeIsGpuCcCapable_DISPATCH(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    return pConfCompute->__confComputeIsGpuCcCapable__(pGpu, pConfCompute);
}

NV_STATUS confComputeEstablishSpdmSessionAndKeys_KERNEL(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute);

static inline NV_STATUS confComputeEstablishSpdmSessionAndKeys_46f6a7(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    return NV_ERR_NOT_SUPPORTED;
}

static inline NV_STATUS confComputeEstablishSpdmSessionAndKeys_DISPATCH(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    return pConfCompute->__confComputeEstablishSpdmSessionAndKeys__(pGpu, pConfCompute);
}

void confComputeKeyStoreDepositIvMask_GH100(struct ConfidentialCompute *pConfCompute, NvU32 globalKeyId, void *ivMask);

static inline void confComputeKeyStoreDepositIvMask_b3696a(struct ConfidentialCompute *pConfCompute, NvU32 globalKeyId, void *ivMask) {
    return;
}

static inline void confComputeKeyStoreDepositIvMask_DISPATCH(struct ConfidentialCompute *pConfCompute, NvU32 globalKeyId, void *ivMask) {
    pConfCompute->__confComputeKeyStoreDepositIvMask__(pConfCompute, globalKeyId, ivMask);
}

NV_STATUS confComputeKeyStoreUpdateKey_GH100(struct ConfidentialCompute *pConfCompute, NvU32 globalKeyId);

static inline NV_STATUS confComputeKeyStoreUpdateKey_46f6a7(struct ConfidentialCompute *pConfCompute, NvU32 globalKeyId) {
    return NV_ERR_NOT_SUPPORTED;
}

static inline NV_STATUS confComputeKeyStoreUpdateKey_DISPATCH(struct ConfidentialCompute *pConfCompute, NvU32 globalKeyId) {
    return pConfCompute->__confComputeKeyStoreUpdateKey__(pConfCompute, globalKeyId);
}

NvBool confComputeKeyStoreIsValidGlobalKeyId_GH100(struct ConfidentialCompute *pConfCompute, NvU32 globalKeyId);

static inline NvBool confComputeKeyStoreIsValidGlobalKeyId_491d52(struct ConfidentialCompute *pConfCompute, NvU32 globalKeyId) {
    return ((NvBool)(0 != 0));
}

static inline NvBool confComputeKeyStoreIsValidGlobalKeyId_DISPATCH(struct ConfidentialCompute *pConfCompute, NvU32 globalKeyId) {
    return pConfCompute->__confComputeKeyStoreIsValidGlobalKeyId__(pConfCompute, globalKeyId);
}

NV_STATUS confComputeKeyStoreInit_GH100(struct ConfidentialCompute *pConfCompute);

static inline NV_STATUS confComputeKeyStoreInit_46f6a7(struct ConfidentialCompute *pConfCompute) {
    return NV_ERR_NOT_SUPPORTED;
}

static inline NV_STATUS confComputeKeyStoreInit_DISPATCH(struct ConfidentialCompute *pConfCompute) {
    return pConfCompute->__confComputeKeyStoreInit__(pConfCompute);
}

void confComputeKeyStoreDeinit_GH100(struct ConfidentialCompute *pConfCompute);

static inline void confComputeKeyStoreDeinit_b3696a(struct ConfidentialCompute *pConfCompute) {
    return;
}

static inline void confComputeKeyStoreDeinit_DISPATCH(struct ConfidentialCompute *pConfCompute) {
    pConfCompute->__confComputeKeyStoreDeinit__(pConfCompute);
}

void *confComputeKeyStoreGetExportMasterKey_GH100(struct ConfidentialCompute *pConfCompute);

static inline void *confComputeKeyStoreGetExportMasterKey_fa6e19(struct ConfidentialCompute *pConfCompute) {
    return ((void *)0);
}

static inline void *confComputeKeyStoreGetExportMasterKey_DISPATCH(struct ConfidentialCompute *pConfCompute) {
    return pConfCompute->__confComputeKeyStoreGetExportMasterKey__(pConfCompute);
}

NV_STATUS confComputeKeyStoreDeriveKey_GH100(struct ConfidentialCompute *pConfCompute, NvU32 globalKeyId);

static inline NV_STATUS confComputeKeyStoreDeriveKey_46f6a7(struct ConfidentialCompute *pConfCompute, NvU32 globalKeyId) {
    return NV_ERR_NOT_SUPPORTED;
}

static inline NV_STATUS confComputeKeyStoreDeriveKey_DISPATCH(struct ConfidentialCompute *pConfCompute, NvU32 globalKeyId) {
    return pConfCompute->__confComputeKeyStoreDeriveKey__(pConfCompute, globalKeyId);
}

void confComputeKeyStoreClearExportMasterKey_GH100(struct ConfidentialCompute *pConfCompute);

static inline void confComputeKeyStoreClearExportMasterKey_b3696a(struct ConfidentialCompute *pConfCompute) {
    return;
}

static inline void confComputeKeyStoreClearExportMasterKey_DISPATCH(struct ConfidentialCompute *pConfCompute) {
    pConfCompute->__confComputeKeyStoreClearExportMasterKey__(pConfCompute);
}

static inline NV_STATUS confComputeStateLoad_DISPATCH(POBJGPU pGpu, struct ConfidentialCompute *pEngstate, NvU32 arg0) {
    return pEngstate->__confComputeStateLoad__(pGpu, pEngstate, arg0);
}

static inline NV_STATUS confComputeStateUnload_DISPATCH(POBJGPU pGpu, struct ConfidentialCompute *pEngstate, NvU32 arg0) {
    return pEngstate->__confComputeStateUnload__(pGpu, pEngstate, arg0);
}

static inline NV_STATUS confComputeStatePreLoad_DISPATCH(POBJGPU pGpu, struct ConfidentialCompute *pEngstate, NvU32 arg0) {
    return pEngstate->__confComputeStatePreLoad__(pGpu, pEngstate, arg0);
}

static inline NV_STATUS confComputeStatePostUnload_DISPATCH(POBJGPU pGpu, struct ConfidentialCompute *pEngstate, NvU32 arg0) {
    return pEngstate->__confComputeStatePostUnload__(pGpu, pEngstate, arg0);
}

static inline void confComputeStateDestroy_DISPATCH(POBJGPU pGpu, struct ConfidentialCompute *pEngstate) {
    pEngstate->__confComputeStateDestroy__(pGpu, pEngstate);
}

static inline NV_STATUS confComputeStateInitUnlocked_DISPATCH(POBJGPU pGpu, struct ConfidentialCompute *pEngstate) {
    return pEngstate->__confComputeStateInitUnlocked__(pGpu, pEngstate);
}

static inline void confComputeInitMissing_DISPATCH(POBJGPU pGpu, struct ConfidentialCompute *pEngstate) {
    pEngstate->__confComputeInitMissing__(pGpu, pEngstate);
}

static inline NV_STATUS confComputeStatePreInitUnlocked_DISPATCH(POBJGPU pGpu, struct ConfidentialCompute *pEngstate) {
    return pEngstate->__confComputeStatePreInitUnlocked__(pGpu, pEngstate);
}

static inline NvBool confComputeIsPresent_DISPATCH(POBJGPU pGpu, struct ConfidentialCompute *pEngstate) {
    return pEngstate->__confComputeIsPresent__(pGpu, pEngstate);
}

NvBool confComputeAcceptClientRequest_IMPL(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute);

#ifdef __nvoc_conf_compute_h_disabled
static inline NvBool confComputeAcceptClientRequest(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    NV_ASSERT_FAILED_PRECOMP("ConfidentialCompute was disabled!");
    return NV_FALSE;
}
#else //__nvoc_conf_compute_h_disabled
#define confComputeAcceptClientRequest(pGpu, pConfCompute) confComputeAcceptClientRequest_IMPL(pGpu, pConfCompute)
#endif //__nvoc_conf_compute_h_disabled

NV_STATUS confComputeInitChannelIterForKey_IMPL(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvU32 globalKey, CHANNEL_ITERATOR *pIter);

#ifdef __nvoc_conf_compute_h_disabled
static inline NV_STATUS confComputeInitChannelIterForKey(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvU32 globalKey, CHANNEL_ITERATOR *pIter) {
    NV_ASSERT_FAILED_PRECOMP("ConfidentialCompute was disabled!");
    return NV_ERR_NOT_SUPPORTED;
}
#else //__nvoc_conf_compute_h_disabled
#define confComputeInitChannelIterForKey(pGpu, pConfCompute, globalKey, pIter) confComputeInitChannelIterForKey_IMPL(pGpu, pConfCompute, globalKey, pIter)
#endif //__nvoc_conf_compute_h_disabled

NV_STATUS confComputeGetNextChannelForKey_IMPL(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, CHANNEL_ITERATOR *pIt, NvU32 globalKey, struct KernelChannel **ppKernelChannel);

#ifdef __nvoc_conf_compute_h_disabled
static inline NV_STATUS confComputeGetNextChannelForKey(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, CHANNEL_ITERATOR *pIt, NvU32 globalKey, struct KernelChannel **ppKernelChannel) {
    NV_ASSERT_FAILED_PRECOMP("ConfidentialCompute was disabled!");
    return NV_ERR_NOT_SUPPORTED;
}
#else //__nvoc_conf_compute_h_disabled
#define confComputeGetNextChannelForKey(pGpu, pConfCompute, pIt, globalKey, ppKernelChannel) confComputeGetNextChannelForKey_IMPL(pGpu, pConfCompute, pIt, globalKey, ppKernelChannel)
#endif //__nvoc_conf_compute_h_disabled

NV_STATUS confComputeGetKeySlotFromGlobalKeyId_IMPL(struct ConfidentialCompute *pConfCompute, NvU32 globalKeyId, NvU32 *pSlot);

#ifdef __nvoc_conf_compute_h_disabled
static inline NV_STATUS confComputeGetKeySlotFromGlobalKeyId(struct ConfidentialCompute *pConfCompute, NvU32 globalKeyId, NvU32 *pSlot) {
    NV_ASSERT_FAILED_PRECOMP("ConfidentialCompute was disabled!");
    return NV_ERR_NOT_SUPPORTED;
}
#else //__nvoc_conf_compute_h_disabled
#define confComputeGetKeySlotFromGlobalKeyId(pConfCompute, globalKeyId, pSlot) confComputeGetKeySlotFromGlobalKeyId_IMPL(pConfCompute, globalKeyId, pSlot)
#endif //__nvoc_conf_compute_h_disabled

NV_STATUS confComputeCheckAndPerformKeyRotation_IMPL(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvU32 h2dKey, NvU32 d2hKey);

#ifdef __nvoc_conf_compute_h_disabled
static inline NV_STATUS confComputeCheckAndPerformKeyRotation(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvU32 h2dKey, NvU32 d2hKey) {
    NV_ASSERT_FAILED_PRECOMP("ConfidentialCompute was disabled!");
    return NV_ERR_NOT_SUPPORTED;
}
#else //__nvoc_conf_compute_h_disabled
#define confComputeCheckAndPerformKeyRotation(pGpu, pConfCompute, h2dKey, d2hKey) confComputeCheckAndPerformKeyRotation_IMPL(pGpu, pConfCompute, h2dKey, d2hKey)
#endif //__nvoc_conf_compute_h_disabled

NV_STATUS confComputePerformKeyRotation_IMPL(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvU32 h2dKey, NvU32 d2hKey, NvBool bWorkItem);

#ifdef __nvoc_conf_compute_h_disabled
static inline NV_STATUS confComputePerformKeyRotation(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvU32 h2dKey, NvU32 d2hKey, NvBool bWorkItem) {
    NV_ASSERT_FAILED_PRECOMP("ConfidentialCompute was disabled!");
    return NV_ERR_NOT_SUPPORTED;
}
#else //__nvoc_conf_compute_h_disabled
#define confComputePerformKeyRotation(pGpu, pConfCompute, h2dKey, d2hKey, bWorkItem) confComputePerformKeyRotation_IMPL(pGpu, pConfCompute, h2dKey, d2hKey, bWorkItem)
#endif //__nvoc_conf_compute_h_disabled

NV_STATUS confComputeForceKeyRotation_IMPL(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvU32 h2dKey, NvU32 d2hKey);

#ifdef __nvoc_conf_compute_h_disabled
static inline NV_STATUS confComputeForceKeyRotation(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvU32 h2dKey, NvU32 d2hKey) {
    NV_ASSERT_FAILED_PRECOMP("ConfidentialCompute was disabled!");
    return NV_ERR_NOT_SUPPORTED;
}
#else //__nvoc_conf_compute_h_disabled
#define confComputeForceKeyRotation(pGpu, pConfCompute, h2dKey, d2hKey) confComputeForceKeyRotation_IMPL(pGpu, pConfCompute, h2dKey, d2hKey)
#endif //__nvoc_conf_compute_h_disabled

NV_STATUS confComputeSetKeyRotationStatus_IMPL(struct ConfidentialCompute *pConfCompute, NvU32 globalKey, KEY_ROTATION_STATUS status);

#ifdef __nvoc_conf_compute_h_disabled
static inline NV_STATUS confComputeSetKeyRotationStatus(struct ConfidentialCompute *pConfCompute, NvU32 globalKey, KEY_ROTATION_STATUS status) {
    NV_ASSERT_FAILED_PRECOMP("ConfidentialCompute was disabled!");
    return NV_ERR_NOT_SUPPORTED;
}
#else //__nvoc_conf_compute_h_disabled
#define confComputeSetKeyRotationStatus(pConfCompute, globalKey, status) confComputeSetKeyRotationStatus_IMPL(pConfCompute, globalKey, status)
#endif //__nvoc_conf_compute_h_disabled

NV_STATUS confComputeGetKeyRotationStatus_IMPL(struct ConfidentialCompute *pConfCompute, NvU32 globalKey, KEY_ROTATION_STATUS *pStatus);

#ifdef __nvoc_conf_compute_h_disabled
static inline NV_STATUS confComputeGetKeyRotationStatus(struct ConfidentialCompute *pConfCompute, NvU32 globalKey, KEY_ROTATION_STATUS *pStatus) {
    NV_ASSERT_FAILED_PRECOMP("ConfidentialCompute was disabled!");
    return NV_ERR_NOT_SUPPORTED;
}
#else //__nvoc_conf_compute_h_disabled
#define confComputeGetKeyRotationStatus(pConfCompute, globalKey, pStatus) confComputeGetKeyRotationStatus_IMPL(pConfCompute, globalKey, pStatus)
#endif //__nvoc_conf_compute_h_disabled

void confComputeGetKeyPairByKey_IMPL(struct ConfidentialCompute *pConfCompute, NvU32 globalKey, NvU32 *pH2DKey, NvU32 *pD2HKey);

#ifdef __nvoc_conf_compute_h_disabled
static inline void confComputeGetKeyPairByKey(struct ConfidentialCompute *pConfCompute, NvU32 globalKey, NvU32 *pH2DKey, NvU32 *pD2HKey) {
    NV_ASSERT_FAILED_PRECOMP("ConfidentialCompute was disabled!");
}
#else //__nvoc_conf_compute_h_disabled
#define confComputeGetKeyPairByKey(pConfCompute, globalKey, pH2DKey, pD2HKey) confComputeGetKeyPairByKey_IMPL(pConfCompute, globalKey, pH2DKey, pD2HKey)
#endif //__nvoc_conf_compute_h_disabled

NV_STATUS confComputeUpdateFreedChannelStats_IMPL(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, struct KernelChannel *pKernelChannel);

#ifdef __nvoc_conf_compute_h_disabled
static inline NV_STATUS confComputeUpdateFreedChannelStats(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, struct KernelChannel *pKernelChannel) {
    NV_ASSERT_FAILED_PRECOMP("ConfidentialCompute was disabled!");
    return NV_ERR_NOT_SUPPORTED;
}
#else //__nvoc_conf_compute_h_disabled
#define confComputeUpdateFreedChannelStats(pGpu, pConfCompute, pKernelChannel) confComputeUpdateFreedChannelStats_IMPL(pGpu, pConfCompute, pKernelChannel)
#endif //__nvoc_conf_compute_h_disabled

NV_STATUS confComputeStartKeyRotationTimer_IMPL(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvU32 h2dKey);

#ifdef __nvoc_conf_compute_h_disabled
static inline NV_STATUS confComputeStartKeyRotationTimer(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvU32 h2dKey) {
    NV_ASSERT_FAILED_PRECOMP("ConfidentialCompute was disabled!");
    return NV_ERR_NOT_SUPPORTED;
}
#else //__nvoc_conf_compute_h_disabled
#define confComputeStartKeyRotationTimer(pGpu, pConfCompute, h2dKey) confComputeStartKeyRotationTimer_IMPL(pGpu, pConfCompute, h2dKey)
#endif //__nvoc_conf_compute_h_disabled

NV_STATUS confComputeStopKeyRotationTimer_IMPL(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvU32 h2dKey);

#ifdef __nvoc_conf_compute_h_disabled
static inline NV_STATUS confComputeStopKeyRotationTimer(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute, NvU32 h2dKey) {
    NV_ASSERT_FAILED_PRECOMP("ConfidentialCompute was disabled!");
    return NV_ERR_NOT_SUPPORTED;
}
#else //__nvoc_conf_compute_h_disabled
#define confComputeStopKeyRotationTimer(pGpu, pConfCompute, h2dKey) confComputeStopKeyRotationTimer_IMPL(pGpu, pConfCompute, h2dKey)
#endif //__nvoc_conf_compute_h_disabled

NvBool confComputeIsUvmKeyRotationPending_IMPL(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute);

#ifdef __nvoc_conf_compute_h_disabled
static inline NvBool confComputeIsUvmKeyRotationPending(struct OBJGPU *pGpu, struct ConfidentialCompute *pConfCompute) {
    NV_ASSERT_FAILED_PRECOMP("ConfidentialCompute was disabled!");
    return NV_FALSE;
}
#else //__nvoc_conf_compute_h_disabled
#define confComputeIsUvmKeyRotationPending(pGpu, pConfCompute) confComputeIsUvmKeyRotationPending_IMPL(pGpu, pConfCompute)
#endif //__nvoc_conf_compute_h_disabled

NV_STATUS confComputeSetKeyRotationThreshold_IMPL(struct ConfidentialCompute *pConfCompute, NvU64 attackerAdvantage);

#ifdef __nvoc_conf_compute_h_disabled
static inline NV_STATUS confComputeSetKeyRotationThreshold(struct ConfidentialCompute *pConfCompute, NvU64 attackerAdvantage) {
    NV_ASSERT_FAILED_PRECOMP("ConfidentialCompute was disabled!");
    return NV_ERR_NOT_SUPPORTED;
}
#else //__nvoc_conf_compute_h_disabled
#define confComputeSetKeyRotationThreshold(pConfCompute, attackerAdvantage) confComputeSetKeyRotationThreshold_IMPL(pConfCompute, attackerAdvantage)
#endif //__nvoc_conf_compute_h_disabled

NvBool confComputeIsUpperThresholdCrossed_IMPL(struct ConfidentialCompute *pConfCompute, const KEY_ROTATION_STATS_INFO *pStatsInfo);

#ifdef __nvoc_conf_compute_h_disabled
static inline NvBool confComputeIsUpperThresholdCrossed(struct ConfidentialCompute *pConfCompute, const KEY_ROTATION_STATS_INFO *pStatsInfo) {
    NV_ASSERT_FAILED_PRECOMP("ConfidentialCompute was disabled!");
    return NV_FALSE;
}
#else //__nvoc_conf_compute_h_disabled
#define confComputeIsUpperThresholdCrossed(pConfCompute, pStatsInfo) confComputeIsUpperThresholdCrossed_IMPL(pConfCompute, pStatsInfo)
#endif //__nvoc_conf_compute_h_disabled

NvBool confComputeIsLowerThresholdCrossed_IMPL(struct ConfidentialCompute *pConfCompute, const KEY_ROTATION_STATS_INFO *pStatsInfo);

#ifdef __nvoc_conf_compute_h_disabled
static inline NvBool confComputeIsLowerThresholdCrossed(struct ConfidentialCompute *pConfCompute, const KEY_ROTATION_STATS_INFO *pStatsInfo) {
    NV_ASSERT_FAILED_PRECOMP("ConfidentialCompute was disabled!");
    return NV_FALSE;
}
#else //__nvoc_conf_compute_h_disabled
#define confComputeIsLowerThresholdCrossed(pConfCompute, pStatsInfo) confComputeIsLowerThresholdCrossed_IMPL(pConfCompute, pStatsInfo)
#endif //__nvoc_conf_compute_h_disabled

NvBool confComputeIsGivenThresholdCrossed_IMPL(const CC_CRYPTOBUNDLE_STATS *pStatsInfo, NvU64 threshold, NvBool bEncrypt);

#define confComputeIsGivenThresholdCrossed(pStatsInfo, threshold, bEncrypt) confComputeIsGivenThresholdCrossed_IMPL(pStatsInfo, threshold, bEncrypt)
#undef PRIVATE_FIELD

#ifndef NVOC_CONF_COMPUTE_H_PRIVATE_ACCESS_ALLOWED
#undef confComputeKeyStoreInit
NV_STATUS NVOC_PRIVATE_FUNCTION(confComputeKeyStoreInit)(struct ConfidentialCompute *pConfCompute);

#undef confComputeKeyStoreInit_HAL
NV_STATUS NVOC_PRIVATE_FUNCTION(confComputeKeyStoreInit_HAL)(struct ConfidentialCompute *pConfCompute);

#undef confComputeKeyStoreDeinit
void NVOC_PRIVATE_FUNCTION(confComputeKeyStoreDeinit)(struct ConfidentialCompute *pConfCompute);

#undef confComputeKeyStoreDeinit_HAL
void NVOC_PRIVATE_FUNCTION(confComputeKeyStoreDeinit_HAL)(struct ConfidentialCompute *pConfCompute);

#undef confComputeKeyStoreGetExportMasterKey
void *NVOC_PRIVATE_FUNCTION(confComputeKeyStoreGetExportMasterKey)(struct ConfidentialCompute *pConfCompute);

#undef confComputeKeyStoreGetExportMasterKey_HAL
void *NVOC_PRIVATE_FUNCTION(confComputeKeyStoreGetExportMasterKey_HAL)(struct ConfidentialCompute *pConfCompute);

#undef confComputeKeyStoreDeriveKey
NV_STATUS NVOC_PRIVATE_FUNCTION(confComputeKeyStoreDeriveKey)(struct ConfidentialCompute *pConfCompute, NvU32 globalKeyId);

#undef confComputeKeyStoreDeriveKey_HAL
NV_STATUS NVOC_PRIVATE_FUNCTION(confComputeKeyStoreDeriveKey_HAL)(struct ConfidentialCompute *pConfCompute, NvU32 globalKeyId);

#undef confComputeKeyStoreClearExportMasterKey
void NVOC_PRIVATE_FUNCTION(confComputeKeyStoreClearExportMasterKey)(struct ConfidentialCompute *pConfCompute);

#undef confComputeKeyStoreClearExportMasterKey_HAL
void NVOC_PRIVATE_FUNCTION(confComputeKeyStoreClearExportMasterKey_HAL)(struct ConfidentialCompute *pConfCompute);

#endif // NVOC_CONF_COMPUTE_H_PRIVATE_ACCESS_ALLOWED


// Refactor spdmCtrlSpdmPartition into SPDM module.

/*!
 * @brief spdmCtrlSpdmPartition
 *        Common function used to call gspCommandPostBlocking based on the platform on which it runs (i.e. vGPU, GSP-RM, Monolithic).
 *
 * @param[in]     pGpu                     : OBJGPU Pointer
 * @param[in]     pSpdmPartitionParams     : SPDM RPC structure pointer
 */
NV_STATUS spdmCtrlSpdmPartition(struct OBJGPU *pGpu, NV2080_CTRL_INTERNAL_SPDM_PARTITION_PARAMS *pSpdmPartitionParams);

/*!
 * @brief 1Hz callback function to perform key rotation
 *
 * @param[in]     pGpu                     : OBJGPU Pointer
 * @param[in]     data                     : void Pointer
 */
void confComputeKeyRotationCallback(struct OBJGPU *pGpu, void *data);

// spdmCtrlWriteSharedMemory is a common function called from both Physical-RM and Kernel-RM.
// However, SPDM module is disabled on Phyiscal-RM and hence declared in conf_compute.h.

#endif // CONF_COMPUTE_H

#ifdef __cplusplus
} // extern "C"
#endif

#endif // _G_CONF_COMPUTE_NVOC_H_
