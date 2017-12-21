#pragma once

#include "cuda_base.h"
#include <catboost/cuda/cuda_lib/memory_pool/stack_like_memory_pool.h>
#include <catboost/cuda/cuda_lib/memory_pool/cuda_malloc_wrapper.h>

namespace NCudaLib {
    template <EPtrType Type>
    class TMemoryProviderImplTrait {
    public:
//TODO: maybe make it template abd cmd-line arg
#if defined(CB_USE_CUDA_MALLOC)
        using TMemoryProvider = TCudaMallocWrapper<Type>;
#else
        using TMemoryProvider = TStackLikeMemoryPool<Type>;
#endif
        using TRawFreeMemory = typename TMemoryProvider::template TMemoryBlock<char>;
    };

    template <>
    class TMemoryProviderImplTrait<Host> {
    public:
        using TMemoryProvider = void;

        using TRawFreeMemory = char*;
    };
}
