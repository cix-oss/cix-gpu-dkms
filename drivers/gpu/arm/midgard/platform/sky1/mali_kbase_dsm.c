// SPDX-License-Identifier: GPL-2.0-only
// Copyright 2025 Cix Technology Group Co., Ltd.

#include "mali_kbase_dsm.h"

#define DSM_GPU_BUF_SIZE 1024 // byte
#define DSM_GPU_NAME "mali_kbase"

/* Reuse the same macro to generate error word entries */
#undef DSM_GPU_ERROR_ID_DEF
#define DSM_GPU_ERROR_ID_DEF(name, subname, value) \
	{ .error_id = DSM_##name##_##subname, .error_name = #subname }

static dsm_error_word gpu_error_words[] = { DSM_GPU_ERR_ID_LIST };

static dsm_error_map gpu_error_map = {
	.num = ARRAY_SIZE(gpu_error_words),
	.words = gpu_error_words,
};

static struct dsm_dev gpu_dsm_device = {
	.name = "GPU",
	.device_name = NULL,
	.ic_name = "sky1",
	.module_name = DSM_GPU_NAME,
	.fops = NULL,
	.error_map = &gpu_error_map,
	.buff_size = DSM_GPU_BUF_SIZE,
};

struct dsm_client *gpu_dsm_init(void)
{
	struct dsm_client *dc = dsm_register_client(&gpu_dsm_device);
	if (!dc)
		pr_err("Failed to register GPU dsm device\n");

	return dc;
}

int gpu_dsm_remove(struct dsm_client *dsm_client)
{
	if (dsm_client)
		dsm_unregister_client(dsm_client, &gpu_dsm_device);

	return 0;
}

void gpu_notify_dsm_event(struct kbase_device *kbdev, dsm_gpu_error_id err_id,
							const char *fmt, ...)
{
	char dsm_msg[DSM_GPU_BUF_SIZE];
	va_list args;

	if (!kbdev || !kbdev->dsm_client || !fmt)
		return;

	va_start(args, fmt);
	vsnprintf(dsm_msg, sizeof(dsm_msg), fmt, args);
	va_end(args);

	if (!dsm_client_ocuppy(kbdev->dsm_client )) {
		dsm_client_record(kbdev->dsm_client , dsm_msg);
		dsm_client_notify(kbdev->dsm_client , err_id);
	}
}