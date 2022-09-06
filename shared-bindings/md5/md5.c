/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2020 Jeff Epler for Adafruit Industries
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "py/obj.h"
#include "py/objproperty.h"
#include "py/runtime.h"
#include "py/objarray.h"

#include "shared-module/md5/md5.h"
#include "shared-bindings/md5/md5.h"

//| class md5:
//|     """Computes an MD5 hash."""

//|     def __init__(self, data=None) -> None:
//|         """Creates an MD5 hash object with the given input data."""

STATIC mp_obj_t md5_md5_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *all_args) {
    mp_arg_check_num(n_args, n_kw, 0, 1, false);

    md5_md5_obj_t *self = m_new_obj(md5_md5_obj_t);
    self->base.type = &md5_md5_type;
    shared_module_md5_init(&self->hash_state);

    if (n_args == 1) {
        const mp_obj_t data = all_args[0];
        mp_buffer_info_t bufinfo;
        if (mp_obj_is_str(data)) {
            mp_raise_TypeError(translate("Strings must be encoded as bytes for hashing"));
        } else if (mp_get_buffer(data, &bufinfo, MP_BUFFER_READ)) {
            shared_module_md5_process(&self->hash_state, bufinfo.buf, bufinfo.len);
        } else {
            mp_raise_TypeError(translate("Object supporting the buffer API is required"));
        }
    }

    return MP_OBJ_FROM_PTR(self);
}

//|     def copy(self) -> md5:
//|         """Returns a copy of the MD5 hash object."""
//|
STATIC mp_obj_t md5_md5_copy(mp_obj_t self_in) {
    md5_md5_obj_t *self = (md5_md5_obj_t *)self_in;

    md5_md5_obj_t *clone = m_new_obj(md5_md5_obj_t);
    clone->base.type = &md5_md5_type;
    clone->hash_state = self->hash_state;
    return MP_OBJ_FROM_PTR(clone);
}
MP_DEFINE_CONST_FUN_OBJ_1(md5_md5_copy_obj, md5_md5_copy);

//|     def digest(self) -> str:
//|         """Returns the MD5 hash of the input as 16 raw bytes."""
//|
STATIC mp_obj_t md5_md5_digest(mp_obj_t self_in) {
    md5_md5_obj_t *self = (md5_md5_obj_t *)self_in;
    uint8_t digest[MD5_DIGESTSIZE];
    md5_state temp;

    temp = self->hash_state;
    shared_module_md5_done(&temp, digest);
    return mp_obj_new_bytes(digest, MD5_DIGESTSIZE);
}
MP_DEFINE_CONST_FUN_OBJ_1(md5_md5_digest_obj, md5_md5_digest);

//|     def hexdigest(self) -> str:
//|         """Returns the MD5 hash of the input as a string of hex digits."""
//|
STATIC mp_obj_t md5_md5_hexdigest(mp_obj_t self_in) {
    md5_md5_obj_t *self = (md5_md5_obj_t *)self_in;
    uint8_t digest[MD5_DIGESTSIZE];
    md5_state temp;
    char hexdigest[MD5_DIGESTSIZE*2];
    char* out = hexdigest;
    const char hexdigits[16] = "0123456789abcdef";

    temp = self->hash_state;
    shared_module_md5_done(&temp, digest);
    for (int i = 0; i < MD5_DIGESTSIZE; i++) {
        uint8_t value = digest[i];
        *out++ = hexdigits[value >> 4];
        *out++ = hexdigits[value & 0xf];
    }
    return mp_obj_new_str(hexdigest, MD5_DIGESTSIZE*2);
}
MP_DEFINE_CONST_FUN_OBJ_1(md5_md5_hexdigest_obj, md5_md5_hexdigest);

//|     def update(self, bytes) -> None:
//|         """Adds more data as input to the hash function."""
//|
STATIC mp_obj_t md5_md5_update(mp_obj_t self_in, mp_obj_t data) {
    md5_md5_obj_t *self = (md5_md5_obj_t *)self_in;
    mp_buffer_info_t bufinfo;
    if (mp_obj_is_str(data)) {
        mp_raise_TypeError(translate("Strings must be encoded as bytes for hashing"));
    } else if (mp_get_buffer(data, &bufinfo, MP_BUFFER_READ)) {
        shared_module_md5_process(&self->hash_state, bufinfo.buf, bufinfo.len);
    } else {
        mp_raise_TypeError(translate("Object supporting the buffer API is required"));
    }
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_2(md5_md5_update_obj, md5_md5_update);


STATIC const mp_rom_map_elem_t md5_md5_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_copy), MP_ROM_PTR(&md5_md5_copy_obj) },
    { MP_ROM_QSTR(MP_QSTR_digest), MP_ROM_PTR(&md5_md5_digest_obj) },
    { MP_ROM_QSTR(MP_QSTR_hexdigest), MP_ROM_PTR(&md5_md5_hexdigest_obj) },
    { MP_ROM_QSTR(MP_QSTR_update), MP_ROM_PTR(&md5_md5_update_obj) },
};
STATIC MP_DEFINE_CONST_DICT(md5_md5_locals_dict, md5_md5_locals_dict_table);

const mp_obj_type_t md5_md5_type = {
    { &mp_type_type },
    .name = MP_QSTR_md5,
    .locals_dict = (mp_obj_dict_t *)&md5_md5_locals_dict,
    .make_new = md5_md5_make_new,
};
