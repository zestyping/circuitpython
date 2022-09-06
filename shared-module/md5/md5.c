// md5 implementation adapted from libtomcrypt by Ka-Ping Yee, 2022.

#include <string.h>

#include "py/gc.h"
#include "py/obj.h"
#include "py/objarray.h"
#include "py/objproperty.h"
#include "py/runtime.h"

#include "shared-bindings/md5/md5.h"
#include "shared-bindings/md5/md5.h"

void shared_module_md5_md5_construct(md5_md5_obj_t *self) {
}

void shared_module_md5_md5_update(md5_md5_obj_t *self, uint8_t *data, uint32_t len) {
}
