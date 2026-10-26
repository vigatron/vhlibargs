/* ======================================================================================
 * Library       : vhlibargs
 * Description   : A C++ command-line parser library
 * Revision      : 0.2.0
 * Source        : https://github.com/vigatron/vhlibargs
 * Disclaimer    : Provided "AS IS", without warranty.
 * License       : MIT
 * File          : src/incs/argfile.hpp
 * Content size  : 389
 * Date / Time   : 26-10-2026 22:43:15
 * MD5           : b11cde696ce55057577be3737d01fec0
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
class VHCLIArgFile : public VHArgTypeBase
{

public:
    VHCLIArgFile(
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
 * Revision         : 0.2.0
 * Content size     : 389
 * Date / Time      : 26-10-2026 22:43:15
 * MD5              : b11cde696ce55057577be3737d01fec0
 * Copyright        : © 2026 Viktor Glebov
 * ====================================================================== */