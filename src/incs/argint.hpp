/* ======================================================================================
 * Library       : vhlibargs
 * Description   : A C++ command-line parser library
 * Revision      : 0.1.0-rc1
 * Source        : https://github.com/vigatron/vhlibargs
 * Disclaimer    : Provided "AS IS", without warranty.
 * License       : MIT
 * File          : src/incs/argint.hpp
 * Content size  : 450
 * Date / Time   : 05-09-2026 19:27:40
 * MD5           : 997220605463d446fba8db1a3d28bded
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
        intval = def;
        intmin = min;
        intmax = max;
    }
};

};
/* ========================[  END FILE CONTENT  ]========================
 * Library          : vhlibargs
 * File             : src/incs/argint.hpp
 * Revision         : 0.1.0-rc1
 * Content size     : 450
 * Date / Time      : 05-09-2026 19:27:40
 * MD5              : 997220605463d446fba8db1a3d28bded
 * Copyright        : © 2026 Viktor Glebov
 * ====================================================================== */