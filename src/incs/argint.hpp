/* ======================================================================================
 * Library       : vhlibargs
 * Description   : A C++ command-line parser library
 * Revision      : 0.2.0
 * Source        : https://github.com/vigatron/vhlibargs
 * Disclaimer    : Provided "AS IS", without warranty.
 * License       : MIT
 * File          : src/incs/argint.hpp
 * Content size  : 460
 * Date / Time   : 26-10-2026 22:43:15
 * MD5           : c235686476cd243e1eadc302cc632cb5
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
class VHCLIArgInt : public VHArgTypeBase
{

public:
    VHCLIArgInt(
        const std::string &keyval,
        int def,
        int min,
        int max,
        const std::string &desc
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
 * Revision         : 0.2.0
 * Content size     : 460
 * Date / Time      : 26-10-2026 22:43:15
 * MD5              : c235686476cd243e1eadc302cc632cb5
 * Copyright        : © 2026 Viktor Glebov
 * ====================================================================== */