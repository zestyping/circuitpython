// md5 implementation adapted from libtomcrypt by Ka-Ping Yee, 2022.

#include <stdint.h>

#include "py/obj.h"
#include "py/runtime.h"

#include "shared-bindings/md5/md5.h"

STATIC const mp_rom_map_elem_t md5_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_md5) },
    { MP_ROM_QSTR(MP_QSTR_md5), MP_ROM_PTR(&md5_md5_type) },
};

STATIC MP_DEFINE_CONST_DICT(md5_module_globals, md5_module_globals_table);

const mp_obj_module_t md5_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&md5_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_md5, md5_module, CIRCUITPY_MD5);
