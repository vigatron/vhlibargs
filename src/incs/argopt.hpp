/* ======================================================================================
 * Library       : vhlibargs
 * Description   : A C++ command-line parser library
 * Revision      : 0.1.0-rc1
 * Source        : https://github.com/vigatron/vhlibargs
 * Disclaimer    : Provided "AS IS", without warranty.
 * License       : MIT
 * File          : src/incs/argopt.hpp
 * Content size  : 511
 * Date / Time   : 05-09-2026 19:27:40
 * MD5           : 34e6e196d62a075ef709a6c056e0bddb
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
     * Single Option param without followed extended arg
     */
    class VHArgTypeOption : public VHArgTypeBase
    {
    public:
        VHArgTypeOption(const std::string &keyval, const std::string &desc, bool def)
            : VHArgTypeBase(keyval, desc, false)
        {
            typearg = eOptType::eOptTypeOption;
            if (def) {
                defval = "1";
                intdef = 1;
            }
        }
    };

};
/* ========================[  END FILE CONTENT  ]========================
 * Library          : vhlibargs
 * File             : src/incs/argopt.hpp
 * Revision         : 0.1.0-rc1
 * Content size     : 511
 * Date / Time      : 05-09-2026 19:27:40
 * MD5              : 34e6e196d62a075ef709a6c056e0bddb
 * Copyright        : © 2026 Viktor Glebov
 * ====================================================================== */