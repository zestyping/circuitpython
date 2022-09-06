// md5 implementation adapted from libtomcrypt by Ka-Ping Yee, 2022.

#pragma once

#include "py/obj.h"

#define MD5_BLOCKSIZE 64
#define MD5_DIGESTSIZE 16

extern const mp_obj_type_t md5_md5_type;

typedef struct {
    uint32_t length;
    uint32_t state[4], curlen;
    uint8_t buf[MD5_BLOCKSIZE];
} md5_state;

typedef struct {
    mp_obj_base_t base;
    md5_state hash_state;
} md5_md5_obj_t;
