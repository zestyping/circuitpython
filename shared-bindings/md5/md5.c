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

//|     def __init__(self) -> None:
//|         """Creates an empty MD5 hash object."""
//|
STATIC mp_obj_t md5_md5_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *all_args) {
    enum { ARG_data };
    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_data, MP_ARG_OBJ, { .u_obj = mp_const_none } },
    };
    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all_kw_array(n_args, n_kw, all_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);

    md5_md5_obj_t *self = m_new_obj(md5_md5_obj_t);
    self->base.type = &md5_md5_type;

    return MP_OBJ_FROM_PTR(self);
}


//|     def hexdigest(self) -> str:
//|         """Returns the MD5 hash as a string of 32 hex digits."""
//|
STATIC mp_obj_t md5_md5_hexdigest(mp_obj_t self_in) {
    md5_md5_obj_t *self = (md5_md5_obj_t *)self_in;
    char data[32] = "0123456789abcdef0123456789abcdef";
    return mp_obj_new_str(self ? data : data, 32);
}
MP_DEFINE_CONST_FUN_OBJ_1(md5_md5_hexdigest_obj, md5_md5_hexdigest);


const mp_obj_type_t md5_md5_type = {
    { &mp_type_type },
    .flags = MP_TYPE_FLAG_EXTENDED,
    .name = MP_QSTR_md5,
    .make_new = md5_md5_make_new,
};
