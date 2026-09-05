/* ======================================================================================
 * Library       : vhlibargs
 * Description   : A C++ command-line parser library
 * Revision      : 0.1.0-rc2
 * Source        : https://github.com/vigatron/vhlibargs
 * Disclaimer    : Provided "AS IS", without warranty.
 * License       : MIT
 * File          : src/incs/argstr.hpp
 * Content size  : 393
 * Date / Time   : 06-09-2026 01:45:55
 * MD5           : 7b5e623a99c74a52a199fb8058afaa17
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
class VHArgTypeString : public VHArgTypeBase
{

public:
    VHArgTypeString(
        const std::string &keyval,
        const std::string &defval,
        const std::string &desc)
        : VHArgTypeBase(keyval, desc, true)
    {
        typearg = eOptType::eOptTypeString;
        this->defval = defval;
    }

};


};
/* ========================[  END FILE CONTENT  ]========================
 * Library          : vhlibargs
 * File             : src/incs/argstr.hpp
 * Revision         : 0.1.0-rc2
 * Content size     : 393
 * Date / Time      : 06-09-2026 01:45:55
 * MD5              : 7b5e623a99c74a52a199fb8058afaa17
 * Copyright        : © 2026 Viktor Glebov
 * ====================================================================== */