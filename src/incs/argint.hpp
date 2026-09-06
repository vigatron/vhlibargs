/* ======================================================================================
 * Library       : vhlibargs
 * Description   : A C++ command-line parser library
 * Revision      : 0.1.0-rc3
 * Source        : https://github.com/vigatron/vhlibargs
 * Disclaimer    : Provided "AS IS", without warranty.
 * License       : MIT
 * File          : src/incs/argint.hpp
 * Content size  : 470
 * Date / Time   : 06-09-2026 16:07:24
 * MD5           : ec0113e202e386c3f9848dd776b8b07c
 * Notes         : MD5 = file content without header/footer
 * Encoding      : UTF-8
 * Author        : Viktor Glebov / V01G04A81
 * Copyright     : © 2026 Viktor Glebov
 * ========================[ BEGIN FILE CONTENT ]====================================== */
#pragma once
#include "argbase.hpp"

namespace VHArgsParser
{

/**
 *
 */
class VHArgTypeInteger : public VHArgTypeBase
{

public:
    VHArgTypeInteger(
        const std::string &keyval,
        const std::string &desc,
        int def,
        int min,
        int max
    )
        : VHArgTypeBase(keyval, desc, true)
    {
        typearg = eOptType::eOptTypeInteger;
        intdef = def;
        intval = 0;
        intmin = min;
        intmax = max;
    }
};

};
/* ========================[  END FILE CONTENT  ]========================
 * Library          : vhlibargs
 * File             : src/incs/argint.hpp
 * Revision         : 0.1.0-rc3
 * Content size     : 470
 * Date / Time      : 06-09-2026 16:07:24
 * MD5              : ec0113e202e386c3f9848dd776b8b07c
 * Copyright        : © 2026 Viktor Glebov
 * ====================================================================== */