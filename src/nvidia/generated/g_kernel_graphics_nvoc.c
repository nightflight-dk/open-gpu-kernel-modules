#define NVOC_KERNEL_GRAPHICS_H_PRIVATE_ACCESS_ALLOWED
#include "nvoc/runtime.h"
#include "nvoc/rtti.h"
#include "nvtypes.h"
#include "nvport/nvport.h"
#include "nvport/inline/util_valist.h"
#include "utils/nvassert.h"
#include "g_kernel_graphics_nvoc.h"

#ifdef DEBUG
char __nvoc_class_id_uniqueness_check_0xea3fa9 = 1;
#endif

extern const struct NVOC_CLASS_DEF __nvoc_class_def_KernelGraphics;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_Object;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_OBJENGSTATE;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_IntrService;

void __nvoc_init_KernelGraphics(KernelGraphics*, RmHalspecOwner* );
void __nvoc_init_funcTable_KernelGraphics(KernelGraphics*, RmHalspecOwner* );
NV_STATUS __nvoc_ctor_KernelGraphics(KernelGraphics*, RmHalspecOwner* );
void __nvoc_init_dataField_KernelGraphics(KernelGraphics*, RmHalspecOwner* );
void __nvoc_dtor_KernelGraphics(KernelGraphics*);
extern const struct NVOC_EXPORT_INFO __nvoc_export_info_KernelGraphics;

static const struct NVOC_RTTI __nvoc_rtti_KernelGraphics_KernelGraphics = {
    /*pClassDef=*/          &__nvoc_class_def_KernelGraphics,
    /*dtor=*/               (NVOC_DYNAMIC_DTOR) &__nvoc_dtor_KernelGraphics,
    /*offset=*/             0,
};

static const struct NVOC_RTTI __nvoc_rtti_KernelGraphics_Object = {
    /*pClassDef=*/          &__nvoc_class_def_Object,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(KernelGraphics, __nvoc_base_OBJENGSTATE.__nvoc_base_Object),
};

static const struct NVOC_RTTI __nvoc_rtti_KernelGraphics_OBJENGSTATE = {
    /*pClassDef=*/          &__nvoc_class_def_OBJENGSTATE,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(KernelGraphics, __nvoc_base_OBJENGSTATE),
};

static const struct NVOC_RTTI __nvoc_rtti_KernelGraphics_IntrService = {
    /*pClassDef=*/          &__nvoc_class_def_IntrService,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(KernelGraphics, __nvoc_base_IntrService),
};

static const struct NVOC_CASTINFO __nvoc_castinfo_KernelGraphics = {
    /*numRelatives=*/       4,
    /*relatives=*/ {
        &__nvoc_rtti_KernelGraphics_KernelGraphics,
        &__nvoc_rtti_KernelGraphics_IntrService,
        &__nvoc_rtti_KernelGraphics_OBJENGSTATE,
        &__nvoc_rtti_KernelGraphics_Object,
    },
};

const struct NVOC_CLASS_DEF __nvoc_class_def_KernelGraphics = 
{
    /*classInfo=*/ {
        /*size=*/               sizeof(KernelGraphics),
        /*classId=*/            classId(KernelGraphics),
        /*providerId=*/         &__nvoc_rtti_provider,
#if NV_PRINTF_STRINGS_ALLOWED
        /*name=*/               "KernelGraphics",
#endif
    },
    /*objCreatefn=*/        (NVOC_DYNAMIC_OBJ_CREATE) &__nvoc_objCreateDynamic_KernelGraphics,
    /*pCastInfo=*/          &__nvoc_castinfo_KernelGraphics,
    /*pExportInfo=*/        &__nvoc_export_info_KernelGraphics
};

static NV_STATUS __nvoc_thunk_KernelGraphics_engstateConstructEngine(OBJGPU *arg0, struct OBJENGSTATE *arg1, ENGDESCRIPTOR arg2) {
    return kgraphicsConstructEngine(arg0, (struct KernelGraphics *)(((unsigned char *)arg1) - __nvoc_rtti_KernelGraphics_OBJENGSTATE.offset), arg2);
}

static NV_STATUS __nvoc_thunk_KernelGraphics_engstateStateInitLocked(OBJGPU *arg0, struct OBJENGSTATE *arg1) {
    return kgraphicsStateInitLocked(arg0, (struct KernelGraphics *)(((unsigned char *)arg1) - __nvoc_rtti_KernelGraphics_OBJENGSTATE.offset));
}

static NV_STATUS __nvoc_thunk_KernelGraphics_engstateStateLoad(OBJGPU *arg0, struct OBJENGSTATE *arg1, NvU32 flags) {
    return kgraphicsStateLoad(arg0, (struct KernelGraphics *)(((unsigned char *)arg1) - __nvoc_rtti_KernelGraphics_OBJENGSTATE.offset), flags);
}

static NV_STATUS __nvoc_thunk_KernelGraphics_engstateStatePreUnload(OBJGPU *pGpu, struct OBJENGSTATE *arg0, NvU32 flags) {
    return kgraphicsStatePreUnload(pGpu, (struct KernelGraphics *)(((unsigned char *)arg0) - __nvoc_rtti_KernelGraphics_OBJENGSTATE.offset), flags);
}

static NV_STATUS __nvoc_thunk_KernelGraphics_engstateStateUnload(OBJGPU *arg0, struct OBJENGSTATE *arg1, NvU32 flags) {
    return kgraphicsStateUnload(arg0, (struct KernelGraphics *)(((unsigned char *)arg1) - __nvoc_rtti_KernelGraphics_OBJENGSTATE.offset), flags);
}

static void __nvoc_thunk_KernelGraphics_engstateStateDestroy(OBJGPU *arg0, struct OBJENGSTATE *arg1) {
    kgraphicsStateDestroy(arg0, (struct KernelGraphics *)(((unsigned char *)arg1) - __nvoc_rtti_KernelGraphics_OBJENGSTATE.offset));
}

static NvBool __nvoc_thunk_KernelGraphics_engstateIsPresent(OBJGPU *arg0, struct OBJENGSTATE *arg1) {
    return kgraphicsIsPresent(arg0, (struct KernelGraphics *)(((unsigned char *)arg1) - __nvoc_rtti_KernelGraphics_OBJENGSTATE.offset));
}

static NV_STATUS __nvoc_thunk_KernelGraphics_engstateStatePostLoad(OBJGPU *arg0, struct OBJENGSTATE *arg1, NvU32 flags) {
    return kgraphicsStatePostLoad(arg0, (struct KernelGraphics *)(((unsigned char *)arg1) - __nvoc_rtti_KernelGraphics_OBJENGSTATE.offset), flags);
}

static void __nvoc_thunk_KernelGraphics_intrservRegisterIntrService(OBJGPU *arg0, struct IntrService *arg1, IntrServiceRecord arg2[171]) {
    kgraphicsRegisterIntrService(arg0, (struct KernelGraphics *)(((unsigned char *)arg1) - __nvoc_rtti_KernelGraphics_IntrService.offset), arg2);
}

static NV_STATUS __nvoc_thunk_KernelGraphics_intrservServiceNotificationInterrupt(OBJGPU *arg0, struct IntrService *arg1, IntrServiceServiceNotificationInterruptArguments *arg2) {
    return kgraphicsServiceNotificationInterrupt(arg0, (struct KernelGraphics *)(((unsigned char *)arg1) - __nvoc_rtti_KernelGraphics_IntrService.offset), arg2);
}

static NvBool __nvoc_thunk_KernelGraphics_intrservClearInterrupt(OBJGPU *arg0, struct IntrService *arg1, IntrServiceClearInterruptArguments *arg2) {
    return kgraphicsClearInterrupt(arg0, (struct KernelGraphics *)(((unsigned char *)arg1) - __nvoc_rtti_KernelGraphics_IntrService.offset), arg2);
}

static NvU32 __nvoc_thunk_KernelGraphics_intrservServiceInterrupt(OBJGPU *arg0, struct IntrService *arg1, IntrServiceServiceInterruptArguments *arg2) {
    return kgraphicsServiceInterrupt(arg0, (struct KernelGraphics *)(((unsigned char *)arg1) - __nvoc_rtti_KernelGraphics_IntrService.offset), arg2);
}

static NV_STATUS __nvoc_thunk_OBJENGSTATE_kgraphicsStatePreLoad(POBJGPU pGpu, struct KernelGraphics *pEngstate, NvU32 arg0) {
    return engstateStatePreLoad(pGpu, (struct OBJENGSTATE *)(((unsigned char *)pEngstate) + __nvoc_rtti_KernelGraphics_OBJENGSTATE.offset), arg0);
}

static NV_STATUS __nvoc_thunk_OBJENGSTATE_kgraphicsStatePostUnload(POBJGPU pGpu, struct KernelGraphics *pEngstate, NvU32 arg0) {
    return engstateStatePostUnload(pGpu, (struct OBJENGSTATE *)(((unsigned char *)pEngstate) + __nvoc_rtti_KernelGraphics_OBJENGSTATE.offset), arg0);
}

static NV_STATUS __nvoc_thunk_OBJENGSTATE_kgraphicsStateInitUnlocked(POBJGPU pGpu, struct KernelGraphics *pEngstate) {
    return engstateStateInitUnlocked(pGpu, (struct OBJENGSTATE *)(((unsigned char *)pEngstate) + __nvoc_rtti_KernelGraphics_OBJENGSTATE.offset));
}

static void __nvoc_thunk_OBJENGSTATE_kgraphicsInitMissing(POBJGPU pGpu, struct KernelGraphics *pEngstate) {
    engstateInitMissing(pGpu, (struct OBJENGSTATE *)(((unsigned char *)pEngstate) + __nvoc_rtti_KernelGraphics_OBJENGSTATE.offset));
}

static NV_STATUS __nvoc_thunk_OBJENGSTATE_kgraphicsStatePreInitLocked(POBJGPU pGpu, struct KernelGraphics *pEngstate) {
    return engstateStatePreInitLocked(pGpu, (struct OBJENGSTATE *)(((unsigned char *)pEngstate) + __nvoc_rtti_KernelGraphics_OBJENGSTATE.offset));
}

static NV_STATUS __nvoc_thunk_OBJENGSTATE_kgraphicsStatePreInitUnlocked(POBJGPU pGpu, struct KernelGraphics *pEngstate) {
    return engstateStatePreInitUnlocked(pGpu, (struct OBJENGSTATE *)(((unsigned char *)pEngstate) + __nvoc_rtti_KernelGraphics_OBJENGSTATE.offset));
}

const struct NVOC_EXPORT_INFO __nvoc_export_info_KernelGraphics = 
{
    /*numEntries=*/     0,
    /*pExportEntries=*/  0
};

void __nvoc_dtor_OBJENGSTATE(OBJENGSTATE*);
void __nvoc_dtor_IntrService(IntrService*);
void __nvoc_dtor_KernelGraphics(KernelGraphics *pThis) {
    __nvoc_kgraphicsDestruct(pThis);
    __nvoc_dtor_OBJENGSTATE(&pThis->__nvoc_base_OBJENGSTATE);
    __nvoc_dtor_IntrService(&pThis->__nvoc_base_IntrService);
    PORT_UNREFERENCED_VARIABLE(pThis);
}

void __nvoc_init_dataField_KernelGraphics(KernelGraphics *pThis, RmHalspecOwner *pRmhalspecowner) {
    ChipHal *chipHal = &pRmhalspecowner->chipHal;
    const unsigned long chipHal_HalVarIdx = (unsigned long)chipHal->__nvoc_HalVarIdx;
    RmVariantHal *rmVariantHal = &pRmhalspecowner->rmVariantHal;
    const unsigned long rmVariantHal_HalVarIdx = (unsigned long)rmVariantHal->__nvoc_HalVarIdx;
    PORT_UNREFERENCED_VARIABLE(pThis);
    PORT_UNREFERENCED_VARIABLE(pRmhalspecowner);
    PORT_UNREFERENCED_VARIABLE(chipHal);
    PORT_UNREFERENCED_VARIABLE(chipHal_HalVarIdx);
    PORT_UNREFERENCED_VARIABLE(rmVariantHal);
    PORT_UNREFERENCED_VARIABLE(rmVariantHal_HalVarIdx);

    // Hal field -- bCtxswLoggingSupported
    if (( ((chipHal_HalVarIdx >> 5) == 1UL) && ((1UL << (chipHal_HalVarIdx & 0x1f)) & 0x11f0ffe0UL) )) /* ChipHal: TU102 | TU104 | TU106 | TU116 | TU117 | GA100 | GA102 | GA103 | GA104 | GA106 | GA107 | AD102 | AD103 | AD104 | AD106 | AD107 | GH100 */ 
    {
        pThis->bCtxswLoggingSupported = ((NvBool)(0 == 0));
    }

    // Hal field -- bUsePriFecsMailbox
    pThis->bUsePriFecsMailbox = ((NvBool)(0 != 0));

    // Hal field -- bDeferContextInit
    if (( ((rmVariantHal_HalVarIdx >> 5) == 0UL) && ((1UL << (rmVariantHal_HalVarIdx & 0x1f)) & 0x00000003UL) )) /* RmVariantHal: VF | PF_KERNEL_ONLY */ 
    {
        pThis->bDeferContextInit = ((NvBool)(0 != 0));
    }

    // Hal field -- bPerSubcontextContextHeaderSupported
    if (( ((chipHal_HalVarIdx >> 5) == 1UL) && ((1UL << (chipHal_HalVarIdx & 0x1f)) & 0x11f0ffe0UL) )) /* ChipHal: TU102 | TU104 | TU106 | TU116 | TU117 | GA100 | GA102 | GA103 | GA104 | GA106 | GA107 | AD102 | AD103 | AD104 | AD106 | AD107 | GH100 */ 
    {
        pThis->bPerSubcontextContextHeaderSupported = ((NvBool)(0 == 0));
    }

    // Hal field -- bSetContextBuffersGPUPrivileged
    if (( ((chipHal_HalVarIdx >> 5) == 1UL) && ((1UL << (chipHal_HalVarIdx & 0x1f)) & 0x11f0ffe0UL) )) /* ChipHal: TU102 | TU104 | TU106 | TU116 | TU117 | GA100 | GA102 | GA103 | GA104 | GA106 | GA107 | AD102 | AD103 | AD104 | AD106 | AD107 | GH100 */ 
    {
        pThis->bSetContextBuffersGPUPrivileged = ((NvBool)(0 == 0));
    }

    // Hal field -- bUcodeSupportsPrivAccessMap
    if (( ((chipHal_HalVarIdx >> 5) == 1UL) && ((1UL << (chipHal_HalVarIdx & 0x1f)) & 0x11f0ffe0UL) )) /* ChipHal: TU102 | TU104 | TU106 | TU116 | TU117 | GA100 | GA102 | GA103 | GA104 | GA106 | GA107 | AD102 | AD103 | AD104 | AD106 | AD107 | GH100 */ 
    {
        pThis->bUcodeSupportsPrivAccessMap = ((NvBool)(0 == 0));
    }

    // Hal field -- bRtvCbSupported
    if (( ((chipHal_HalVarIdx >> 5) == 1UL) && ((1UL << (chipHal_HalVarIdx & 0x1f)) & 0x11f0ffe0UL) )) /* ChipHal: TU102 | TU104 | TU106 | TU116 | TU117 | GA100 | GA102 | GA103 | GA104 | GA106 | GA107 | AD102 | AD103 | AD104 | AD106 | AD107 | GH100 */ 
    {
        pThis->bRtvCbSupported = ((NvBool)(0 == 0));
    }

    // Hal field -- bFecsRecordUcodeSeqnoSupported
    if (( ((rmVariantHal_HalVarIdx >> 5) == 0UL) && ((1UL << (rmVariantHal_HalVarIdx & 0x1f)) & 0x00000001UL) )) /* RmVariantHal: VF */ 
    {
        pThis->bFecsRecordUcodeSeqnoSupported = ((NvBool)(0 != 0));
    }
    else if (( ((rmVariantHal_HalVarIdx >> 5) == 0UL) && ((1UL << (rmVariantHal_HalVarIdx & 0x1f)) & 0x00000002UL) )) /* RmVariantHal: PF_KERNEL_ONLY */ 
    {
        if (( ((chipHal_HalVarIdx >> 5) == 1UL) && ((1UL << (chipHal_HalVarIdx & 0x1f)) & 0x10000000UL) )) /* ChipHal: GH100 */ 
        {
            pThis->bFecsRecordUcodeSeqnoSupported = ((NvBool)(0 == 0));
        }
        // default
        else
        {
            pThis->bFecsRecordUcodeSeqnoSupported = ((NvBool)(0 != 0));
        }
    }

    // Hal field -- bBug4208224WAREnabled
    if (( ((rmVariantHal_HalVarIdx >> 5) == 0UL) && ((1UL << (rmVariantHal_HalVarIdx & 0x1f)) & 0x00000001UL) )) /* RmVariantHal: VF */ 
    {
        pThis->bBug4208224WAREnabled = ((NvBool)(0 != 0));
    }
    else if (( ((rmVariantHal_HalVarIdx >> 5) == 0UL) && ((1UL << (rmVariantHal_HalVarIdx & 0x1f)) & 0x00000002UL) )) /* RmVariantHal: PF_KERNEL_ONLY */ 
    {
        if (( ((chipHal_HalVarIdx >> 5) == 1UL) && ((1UL << (chipHal_HalVarIdx & 0x1f)) & 0x000000e0UL) )) /* ChipHal: TU102 | TU104 | TU106 */ 
        {
            pThis->bBug4208224WAREnabled = ((NvBool)(0 == 0));
        }
        // default
        else
        {
            pThis->bBug4208224WAREnabled = ((NvBool)(0 != 0));
        }
    }
}

NV_STATUS __nvoc_ctor_OBJENGSTATE(OBJENGSTATE* );
NV_STATUS __nvoc_ctor_IntrService(IntrService* );
NV_STATUS __nvoc_ctor_KernelGraphics(KernelGraphics *pThis, RmHalspecOwner *pRmhalspecowner) {
    NV_STATUS status = NV_OK;
    status = __nvoc_ctor_OBJENGSTATE(&pThis->__nvoc_base_OBJENGSTATE);
    if (status != NV_OK) goto __nvoc_ctor_KernelGraphics_fail_OBJENGSTATE;
    status = __nvoc_ctor_IntrService(&pThis->__nvoc_base_IntrService);
    if (status != NV_OK) goto __nvoc_ctor_KernelGraphics_fail_IntrService;
    __nvoc_init_dataField_KernelGraphics(pThis, pRmhalspecowner);
    goto __nvoc_ctor_KernelGraphics_exit; // Success

__nvoc_ctor_KernelGraphics_fail_IntrService:
    __nvoc_dtor_OBJENGSTATE(&pThis->__nvoc_base_OBJENGSTATE);
__nvoc_ctor_KernelGraphics_fail_OBJENGSTATE:
__nvoc_ctor_KernelGraphics_exit:

    return status;
}

static void __nvoc_init_funcTable_KernelGraphics_1(KernelGraphics *pThis, RmHalspecOwner *pRmhalspecowner) {
    ChipHal *chipHal = &pRmhalspecowner->chipHal;
    const unsigned long chipHal_HalVarIdx = (unsigned long)chipHal->__nvoc_HalVarIdx;
    RmVariantHal *rmVariantHal = &pRmhalspecowner->rmVariantHal;
    const unsigned long rmVariantHal_HalVarIdx = (unsigned long)rmVariantHal->__nvoc_HalVarIdx;
    PORT_UNREFERENCED_VARIABLE(pThis);
    PORT_UNREFERENCED_VARIABLE(pRmhalspecowner);
    PORT_UNREFERENCED_VARIABLE(chipHal);
    PORT_UNREFERENCED_VARIABLE(chipHal_HalVarIdx);
    PORT_UNREFERENCED_VARIABLE(rmVariantHal);
    PORT_UNREFERENCED_VARIABLE(rmVariantHal_HalVarIdx);

    pThis->__kgraphicsConstructEngine__ = &kgraphicsConstructEngine_IMPL;

    pThis->__kgraphicsStateInitLocked__ = &kgraphicsStateInitLocked_IMPL;

    pThis->__kgraphicsStateLoad__ = &kgraphicsStateLoad_IMPL;

    pThis->__kgraphicsStatePreUnload__ = &kgraphicsStatePreUnload_IMPL;

    pThis->__kgraphicsStateUnload__ = &kgraphicsStateUnload_IMPL;

    pThis->__kgraphicsStateDestroy__ = &kgraphicsStateDestroy_IMPL;

    pThis->__kgraphicsIsPresent__ = &kgraphicsIsPresent_IMPL;

    pThis->__kgraphicsStatePostLoad__ = &kgraphicsStatePostLoad_IMPL;

    pThis->__kgraphicsRegisterIntrService__ = &kgraphicsRegisterIntrService_IMPL;

    pThis->__kgraphicsServiceNotificationInterrupt__ = &kgraphicsServiceNotificationInterrupt_IMPL;

    // Hal function -- kgraphicsCreateBug4208224Channel
    if (( ((chipHal_HalVarIdx >> 5) == 1UL) && ((1UL << (chipHal_HalVarIdx & 0x1f)) & 0x000000e0UL) )) /* ChipHal: TU102 | TU104 | TU106 */ 
    {
        pThis->__kgraphicsCreateBug4208224Channel__ = &kgraphicsCreateBug4208224Channel_TU102;
    }
    // default
    else
    {
        pThis->__kgraphicsCreateBug4208224Channel__ = &kgraphicsCreateBug4208224Channel_56cd7a;
    }

    // Hal function -- kgraphicsInitializeBug4208224WAR
    if (( ((rmVariantHal_HalVarIdx >> 5) == 0UL) && ((1UL << (rmVariantHal_HalVarIdx & 0x1f)) & 0x00000001UL) )) /* RmVariantHal: VF */ 
    {
        pThis->__kgraphicsInitializeBug4208224WAR__ = &kgraphicsInitializeBug4208224WAR_56cd7a;
    }
    else
    {
        if (( ((chipHal_HalVarIdx >> 5) == 1UL) && ((1UL << (chipHal_HalVarIdx & 0x1f)) & 0x000000e0UL) )) /* ChipHal: TU102 | TU104 | TU106 */ 
        {
            pThis->__kgraphicsInitializeBug4208224WAR__ = &kgraphicsInitializeBug4208224WAR_TU102;
        }
        // default
        else
        {
            pThis->__kgraphicsInitializeBug4208224WAR__ = &kgraphicsInitializeBug4208224WAR_56cd7a;
        }
    }

    // Hal function -- kgraphicsIsBug4208224WARNeeded
    if (( ((rmVariantHal_HalVarIdx >> 5) == 0UL) && ((1UL << (rmVariantHal_HalVarIdx & 0x1f)) & 0x00000001UL) )) /* RmVariantHal: VF */ 
    {
        pThis->__kgraphicsIsBug4208224WARNeeded__ = &kgraphicsIsBug4208224WARNeeded_491d52;
    }
    else
    {
        if (( ((chipHal_HalVarIdx >> 5) == 1UL) && ((1UL << (chipHal_HalVarIdx & 0x1f)) & 0x000000e0UL) )) /* ChipHal: TU102 | TU104 | TU106 */ 
        {
            pThis->__kgraphicsIsBug4208224WARNeeded__ = &kgraphicsIsBug4208224WARNeeded_TU102;
        }
        // default
        else
        {
            pThis->__kgraphicsIsBug4208224WARNeeded__ = &kgraphicsIsBug4208224WARNeeded_491d52;
        }
    }

    // Hal function -- kgraphicsLoadStaticInfo
    if (( ((rmVariantHal_HalVarIdx >> 5) == 0UL) && ((1UL << (rmVariantHal_HalVarIdx & 0x1f)) & 0x00000001UL) )) /* RmVariantHal: VF */ 
    {
        pThis->__kgraphicsLoadStaticInfo__ = &kgraphicsLoadStaticInfo_VF;
    }
    else
    {
        pThis->__kgraphicsLoadStaticInfo__ = &kgraphicsLoadStaticInfo_KERNEL;
    }

    // Hal function -- kgraphicsClearInterrupt
    pThis->__kgraphicsClearInterrupt__ = &kgraphicsClearInterrupt_GP100;

    // Hal function -- kgraphicsServiceInterrupt
    pThis->__kgraphicsServiceInterrupt__ = &kgraphicsServiceInterrupt_GP100;

    // Hal function -- kgraphicsIsUnrestrictedAccessMapSupported
    if (( ((rmVariantHal_HalVarIdx >> 5) == 0UL) && ((1UL << (rmVariantHal_HalVarIdx & 0x1f)) & 0x00000001UL) )) /* RmVariantHal: VF */ 
    {
        pThis->__kgraphicsIsUnrestrictedAccessMapSupported__ = &kgraphicsIsUnrestrictedAccessMapSupported_491d52;
    }
    // default
    else
    {
        pThis->__kgraphicsIsUnrestrictedAccessMapSupported__ = &kgraphicsIsUnrestrictedAccessMapSupported_PF;
    }

    // Hal function -- kgraphicsGetFecsTraceRdOffset
    if (( ((chipHal_HalVarIdx >> 5) == 1UL) && ((1UL << (chipHal_HalVarIdx & 0x1f)) & 0x000003e0UL) )) /* ChipHal: TU102 | TU104 | TU106 | TU116 | TU117 */ 
    {
        pThis->__kgraphicsGetFecsTraceRdOffset__ = &kgraphicsGetFecsTraceRdOffset_474d46;
    }
    else
    {
        pThis->__kgraphicsGetFecsTraceRdOffset__ = &kgraphicsGetFecsTraceRdOffset_GA100;
    }

    // Hal function -- kgraphicsSetFecsTraceRdOffset
    if (( ((chipHal_HalVarIdx >> 5) == 1UL) && ((1UL << (chipHal_HalVarIdx & 0x1f)) & 0x000003e0UL) )) /* ChipHal: TU102 | TU104 | TU106 | TU116 | TU117 */ 
    {
        pThis->__kgraphicsSetFecsTraceRdOffset__ = &kgraphicsSetFecsTraceRdOffset_d44104;
    }
    else
    {
        pThis->__kgraphicsSetFecsTraceRdOffset__ = &kgraphicsSetFecsTraceRdOffset_GA100;
    }

    // Hal function -- kgraphicsSetFecsTraceWrOffset
    if (( ((chipHal_HalVarIdx >> 5) == 1UL) && ((1UL << (chipHal_HalVarIdx & 0x1f)) & 0x000003e0UL) )) /* ChipHal: TU102 | TU104 | TU106 | TU116 | TU117 */ 
    {
        pThis->__kgraphicsSetFecsTraceWrOffset__ = &kgraphicsSetFecsTraceWrOffset_d44104;
    }
    else
    {
        pThis->__kgraphicsSetFecsTraceWrOffset__ = &kgraphicsSetFecsTraceWrOffset_GA100;
    }

    // Hal function -- kgraphicsSetFecsTraceHwEnable
    if (( ((chipHal_HalVarIdx >> 5) == 1UL) && ((1UL << (chipHal_HalVarIdx & 0x1f)) & 0x000003e0UL) )) /* ChipHal: TU102 | TU104 | TU106 | TU116 | TU117 */ 
    {
        pThis->__kgraphicsSetFecsTraceHwEnable__ = &kgraphicsSetFecsTraceHwEnable_d44104;
    }
    else
    {
        pThis->__kgraphicsSetFecsTraceHwEnable__ = &kgraphicsSetFecsTraceHwEnable_GA100;
    }

    pThis->__nvoc_base_OBJENGSTATE.__engstateConstructEngine__ = &__nvoc_thunk_KernelGraphics_engstateConstructEngine;

    pThis->__nvoc_base_OBJENGSTATE.__engstateStateInitLocked__ = &__nvoc_thunk_KernelGraphics_engstateStateInitLocked;

    pThis->__nvoc_base_OBJENGSTATE.__engstateStateLoad__ = &__nvoc_thunk_KernelGraphics_engstateStateLoad;

    pThis->__nvoc_base_OBJENGSTATE.__engstateStatePreUnload__ = &__nvoc_thunk_KernelGraphics_engstateStatePreUnload;

    pThis->__nvoc_base_OBJENGSTATE.__engstateStateUnload__ = &__nvoc_thunk_KernelGraphics_engstateStateUnload;

    pThis->__nvoc_base_OBJENGSTATE.__engstateStateDestroy__ = &__nvoc_thunk_KernelGraphics_engstateStateDestroy;

    pThis->__nvoc_base_OBJENGSTATE.__engstateIsPresent__ = &__nvoc_thunk_KernelGraphics_engstateIsPresent;

    pThis->__nvoc_base_OBJENGSTATE.__engstateStatePostLoad__ = &__nvoc_thunk_KernelGraphics_engstateStatePostLoad;

    pThis->__nvoc_base_IntrService.__intrservRegisterIntrService__ = &__nvoc_thunk_KernelGraphics_intrservRegisterIntrService;

    pThis->__nvoc_base_IntrService.__intrservServiceNotificationInterrupt__ = &__nvoc_thunk_KernelGraphics_intrservServiceNotificationInterrupt;

    pThis->__nvoc_base_IntrService.__intrservClearInterrupt__ = &__nvoc_thunk_KernelGraphics_intrservClearInterrupt;

    pThis->__nvoc_base_IntrService.__intrservServiceInterrupt__ = &__nvoc_thunk_KernelGraphics_intrservServiceInterrupt;

    pThis->__kgraphicsStatePreLoad__ = &__nvoc_thunk_OBJENGSTATE_kgraphicsStatePreLoad;

    pThis->__kgraphicsStatePostUnload__ = &__nvoc_thunk_OBJENGSTATE_kgraphicsStatePostUnload;

    pThis->__kgraphicsStateInitUnlocked__ = &__nvoc_thunk_OBJENGSTATE_kgraphicsStateInitUnlocked;

    pThis->__kgraphicsInitMissing__ = &__nvoc_thunk_OBJENGSTATE_kgraphicsInitMissing;

    pThis->__kgraphicsStatePreInitLocked__ = &__nvoc_thunk_OBJENGSTATE_kgraphicsStatePreInitLocked;

    pThis->__kgraphicsStatePreInitUnlocked__ = &__nvoc_thunk_OBJENGSTATE_kgraphicsStatePreInitUnlocked;
}

void __nvoc_init_funcTable_KernelGraphics(KernelGraphics *pThis, RmHalspecOwner *pRmhalspecowner) {
    __nvoc_init_funcTable_KernelGraphics_1(pThis, pRmhalspecowner);
}

void __nvoc_init_OBJENGSTATE(OBJENGSTATE*);
void __nvoc_init_IntrService(IntrService*);
void __nvoc_init_KernelGraphics(KernelGraphics *pThis, RmHalspecOwner *pRmhalspecowner) {
    pThis->__nvoc_pbase_KernelGraphics = pThis;
    pThis->__nvoc_pbase_Object = &pThis->__nvoc_base_OBJENGSTATE.__nvoc_base_Object;
    pThis->__nvoc_pbase_OBJENGSTATE = &pThis->__nvoc_base_OBJENGSTATE;
    pThis->__nvoc_pbase_IntrService = &pThis->__nvoc_base_IntrService;
    __nvoc_init_OBJENGSTATE(&pThis->__nvoc_base_OBJENGSTATE);
    __nvoc_init_IntrService(&pThis->__nvoc_base_IntrService);
    __nvoc_init_funcTable_KernelGraphics(pThis, pRmhalspecowner);
}

NV_STATUS __nvoc_objCreate_KernelGraphics(KernelGraphics **ppThis, Dynamic *pParent, NvU32 createFlags)
{
    NV_STATUS status;
    Object *pParentObj = NULL;
    KernelGraphics *pThis;
    RmHalspecOwner *pRmhalspecowner;

    // Assign `pThis`, allocating memory unless suppressed by flag.
    status = __nvoc_handleObjCreateMemAlloc(createFlags, sizeof(KernelGraphics), (void**)&pThis, (void**)ppThis);
    if (status != NV_OK)
        return status;

    // Zero is the initial value for everything.
    portMemSet(pThis, 0, sizeof(KernelGraphics));

    // Initialize runtime type information.
    __nvoc_initRtti(staticCast(pThis, Dynamic), &__nvoc_class_def_KernelGraphics);

    pThis->__nvoc_base_OBJENGSTATE.__nvoc_base_Object.createFlags = createFlags;

    // pParent must be a valid object that derives from a halspec owner class.
    NV_ASSERT_OR_RETURN(pParent != NULL, NV_ERR_INVALID_ARGUMENT);

    // Link the child into the parent unless flagged not to do so.
    if (!(createFlags & NVOC_OBJ_CREATE_FLAGS_PARENT_HALSPEC_ONLY))
    {
        pParentObj = dynamicCast(pParent, Object);
        objAddChild(pParentObj, &pThis->__nvoc_base_OBJENGSTATE.__nvoc_base_Object);
    }
    else
    {
        pThis->__nvoc_base_OBJENGSTATE.__nvoc_base_Object.pParent = NULL;
    }

    if ((pRmhalspecowner = dynamicCast(pParent, RmHalspecOwner)) == NULL)
        pRmhalspecowner = objFindAncestorOfType(RmHalspecOwner, pParent);
    NV_ASSERT_OR_RETURN(pRmhalspecowner != NULL, NV_ERR_INVALID_ARGUMENT);

    __nvoc_init_KernelGraphics(pThis, pRmhalspecowner);
    status = __nvoc_ctor_KernelGraphics(pThis, pRmhalspecowner);
    if (status != NV_OK) goto __nvoc_objCreate_KernelGraphics_cleanup;

    // Assignment has no effect if NVOC_OBJ_CREATE_FLAGS_IN_PLACE_CONSTRUCT is set.
    *ppThis = pThis;

    return NV_OK;

__nvoc_objCreate_KernelGraphics_cleanup:

    // Unlink the child from the parent if it was linked above.
    if (pParentObj != NULL)
        objRemoveChild(pParentObj, &pThis->__nvoc_base_OBJENGSTATE.__nvoc_base_Object);

    // Do not call destructors here since the constructor already called them.
    if (createFlags & NVOC_OBJ_CREATE_FLAGS_IN_PLACE_CONSTRUCT)
        portMemSet(pThis, 0, sizeof(KernelGraphics));
    else
    {
        portMemFree(pThis);
        *ppThis = NULL;
    }

    // coverity[leaked_storage:FALSE]
    return status;
}

NV_STATUS __nvoc_objCreateDynamic_KernelGraphics(KernelGraphics **ppThis, Dynamic *pParent, NvU32 createFlags, va_list args) {
    NV_STATUS status;

    status = __nvoc_objCreate_KernelGraphics(ppThis, pParent, createFlags);

    return status;
}

