// md5 implementation adapted from libtomcrypt by Ka-Ping Yee, 2022.

#pragma once

#include "shared-module/md5/md5.h"

extern const mp_obj_type_t md5_md5_type;

void shared_module_md5_compress(md5_state* md, const uint8_t* buf);
void shared_module_md5_init(md5_state* md);
void shared_module_md5_process(md5_state* md, const uint8_t* buf, uint32_t len);
void shared_module_md5_done(md5_state* md, uint8_t* out);
