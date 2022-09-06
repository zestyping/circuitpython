// md5 implementation adapted from libtomcrypt by Ka-Ping Yee, 2022.

#include <string.h>

#include "py/gc.h"
#include "py/obj.h"
#include "py/objarray.h"
#include "py/objproperty.h"
#include "py/runtime.h"

#include "shared-bindings/md5/md5.h"
#include "shared-bindings/md5/md5.h"

void shared_module_md5_md5_init(md5_md5_obj_t *self) {
    self->state[0] = 0x67452301UL;
    self->state[1] = 0xefcdab89UL;
    self->state[2] = 0x98badcfeUL;
    self->state[3] = 0x10325476UL;
    self->curlen = 0;
    self->length = 0;
}

void shared_module_md5_md5_update(md5_md5_obj_t *self, uint8_t *data, uint32_t len) {
    for (uint32_t i = 0; i < 32 && i < len; i++) {
        self->buf[i] = data[i];
    }
}
