/* ======================================================================================
 * Library       : vhlibargs
 * Description   : A C++ command-line parser library
 * Revision      : 0.2.0
 * Source        : https://github.com/vigatron/vhlibargs
 * Disclaimer    : Provided "AS IS", without warranty.
 * License       : MIT
 * File          : src/incs/argstr.hpp
 * Content size  : 385
 * Date / Time   : 26-10-2026 22:43:15
 * MD5           : 0d58abc59a1ec79cf3dd35e42a90641e
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
class VHCLIArgStr : public VHArgTypeBase
{

public:
    VHCLIArgStr(
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
 * Revision         : 0.2.0
 * Content size     : 385
 * Date / Time      : 26-10-2026 22:43:15
 * MD5              : 0d58abc59a1ec79cf3dd35e42a90641e
 * Copyright        : © 2026 Viktor Glebov
 * ====================================================================== */