// SPDX-License-Identifier: GPL-2.0-only
// Copyright 2025 Cix Technology Group Co., Ltd.

#ifndef __MALI_KBASE_DSM_H
#define __MALI_KBASE_DSM_H

#include <mali_kbase.h>
#if IS_ENABLED(CONFIG_PLAT_DSM_SYSEVENT)
#include <linux/soc/cix/dsm_pub.h>
#endif

#define DSM_GPU_DEF_ARGS(args...) args
#define DSM_GPU_ERROR_ID_DEF(name, subname, value) \
	DSM_GPU_DEF_ARGS(DSM_##name##_##subname =  \
			     (value) + DSM_##name##_ERROR_ID_START)

#define DSM_GPU_ERR_ID_LIST \
	DSM_GPU_ERROR_ID_DEF(GPU, PROBE_ERR, 0x1), \
	DSM_GPU_ERROR_ID_DEF(GPU, PM_ERR, 0x2),    \
	DSM_GPU_ERROR_ID_DEF(GPU, MMU_ERR, 0x3),   \
	DSM_GPU_ERROR_ID_DEF(GPU, CSF_ERR, 0x4)

typedef enum {
	DSM_GPU_ERROR_ID_START = 920050000,
	DSM_GPU_ERR_ID_LIST,
} dsm_gpu_error_id;

#if IS_ENABLED(CONFIG_PLAT_DSM_SYSEVENT)
struct dsm_client *gpu_dsm_init(void);
int gpu_dsm_remove(struct dsm_client *dsm_client);
void gpu_notify_dsm_event(struct kbase_device *kbdev, dsm_gpu_error_id err_id,
							const char *fmt, ...) __printf(3, 4);
#else
static inline void gpu_notify_dsm_event(struct kbase_device *kbdev, dsm_gpu_error_id err_id,
							char *fmt, ...)
{
	/* No-op when DSM is disabled */
	return;
}
#endif // !CONFIG_PLAT_DSM_SYSEVENT

#endif // __MALI_KBASE_DSM_H