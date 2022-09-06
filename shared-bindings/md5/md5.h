// md5 implementation adapted from libtomcrypt by Ka-Ping Yee, 2022.

#pragma once

#include "shared-module/md5/md5.h"

extern const mp_obj_type_t md5_md5_type;

void shared_module_md5_md5_init(md5_md5_obj_t *self);
void shared_module_md5_md5_update(md5_md5_obj_t *self, uint8_t *data, uint32_t len);
