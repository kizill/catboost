CUDA_NVCC_FLAGS(
    --expt-relaxed-constexpr
    -gencode arch=compute_52,code=sm_52
    --ptxas-options=-v
    -lineinfo
    --use_fast_math
)
