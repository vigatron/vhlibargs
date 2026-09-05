/* ======================================================================================
 * Library       : vhlibargs
 * Description   : A C++ command-line parser library
 * Revision      : 0.1.0-rc2
 * Source        : https://github.com/vigatron/vhlibargs
 * Disclaimer    : Provided "AS IS", without warranty.
 * License       : MIT
 * File          : src/incs/argfile.hpp
 * Content size  : 399
 * Date / Time   : 06-09-2026 01:45:55
 * MD5           : 9427ec12480c70929873447b542cc8ca
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
class VHArgTypeFileName : public VHArgTypeBase
{

public:
    VHArgTypeFileName(
        const std::string &keyval,
        const std::string &defval,
        const std::string &desc)
        : VHArgTypeBase(keyval, desc, true)
    {
        typearg = eOptType::eOptTypeFilename;
        this->defval = defval;
    }

};

};
/* ========================[  END FILE CONTENT  ]========================
 * Library          : vhlibargs
 * File             : src/incs/argfile.hpp
 * Revision         : 0.1.0-rc2
 * Content size     : 399
 * Date / Time      : 06-09-2026 01:45:55
 * MD5              : 9427ec12480c70929873447b542cc8ca
 * Copyright        : © 2026 Viktor Glebov
 * ====================================================================== */