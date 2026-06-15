# SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note
#
# (C) COPYRIGHT 2023-2025 ARM Limited. All rights reserved.
#
# This file defines path prefixes for the gpu_kernel package tree.
# Use these constants instead of hardcoding full paths.

# Base path for the gpu_kernel package tree
GPU_KERNEL_BASE = "//common-modules/cix/gpu_kernel"

# Shortcuts for common subpackages
GPU_KERNEL_CONFIG = GPU_KERNEL_BASE + "/config"
GPU_KERNEL_DRIVERS = GPU_KERNEL_BASE + "/drivers"
GPU_KERNEL_DRIVERS_BASE_ARM = GPU_KERNEL_DRIVERS + "/base/arm"
GPU_KERNEL_DRIVERS_GPU_ARM = GPU_KERNEL_DRIVERS + "/gpu/arm"
GPU_KERNEL_DRIVERS_GPU_ARM_MIDGARD = GPU_KERNEL_DRIVERS_GPU_ARM + "/midgard"
GPU_KERNEL_DRIVERS_GPU_ARM_MIDGARD_TESTS = GPU_KERNEL_DRIVERS_GPU_ARM_MIDGARD + "/tests"
GPU_KERNEL_DRIVERS_HWTRACING_CORESIGHT_MALI = GPU_KERNEL_DRIVERS + "/hwtracing/coresight/mali"
GPU_KERNEL_CONFIG_FRAGMENT = GPU_KERNEL_CONFIG + "/fragment"
