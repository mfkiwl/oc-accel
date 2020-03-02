/*
 * Copyright 2019 International Business Machines
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __OCACCEL_INTERNAL_H__
#define __OCACCEL_INTERNAL_H__

#include <stdint.h>
#include <libocaccel.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/syscall.h>   /* For SYS_xxx definitions */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __unused
#  define __unused __attribute__((unused))
#endif

#ifndef ARRAY_SIZE
#  define ARRAY_SIZE(a)  (sizeof((a)) / sizeof((a)[0]))
#endif

#ifndef ABS
#  define ABS(a)         (((a) < 0) ? -(a) : (a))
#endif

#ifndef MAX
#  define MAX(a,b)        ({ __typeof__ (a) _a = (a); \
        __typeof__ (b) _b = (b); \
        (_a) > (_b) ? (_a) : (_b); })
#endif

#ifndef MIN
#  define MIN(a,b)        ({ __typeof__ (a) _a = (a); \
        __typeof__ (b) _b = (b); \
        (_a) < (_b) ? (_a) : (_b); })
#endif

#define        OCACCEL_MAX_NUMBER_OF_KERNELS 16

struct ocaccel_funcs {
    void* (* card_alloc_dev) (const char* path, uint16_t vendor_id,
                              uint16_t device_id);

    int (* mmio_per_pasid_write32) (struct ocaccel_card* card, uint64_t offset, uint32_t data);
    int (* mmio_per_pasid_read32) (struct ocaccel_card* card, uint64_t offset, uint32_t* data);
    int (* mmio_global_write64) (struct ocaccel_card* card, uint64_t offset, uint64_t data);
    int (* mmio_global_read64) (struct ocaccel_card* card, uint64_t offset, uint64_t* data);
    void (* card_free) (struct ocaccel_card* card);
    int (* card_ioctl) (struct ocaccel_card* card, unsigned int cmd, char* arg);
};

#ifdef __cplusplus
}
#endif

#endif        /* __OCACCEL_INTERNAL_H__ */
