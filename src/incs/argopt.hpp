/* ======================================================================================
 * Library       : vhlibargs
 * Description   : A C++ command-line parser library
 * Revision      : 0.1.0-rc2
 * Source        : https://github.com/vigatron/vhlibargs
 * Disclaimer    : Provided "AS IS", without warranty.
 * License       : MIT
 * File          : src/incs/argopt.hpp
 * Content size  : 500
 * Date / Time   : 06-09-2026 01:45:55
 * MD5           : a12ab1b15b1e6663e06c7ac4392029e8
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
            intdef = def ? 1 : 0;
            if(def)
                defval = "1";
        }
    };

};
/* ========================[  END FILE CONTENT  ]========================
 * Library          : vhlibargs
 * File             : src/incs/argopt.hpp
 * Revision         : 0.1.0-rc2
 * Content size     : 500
 * Date / Time      : 06-09-2026 01:45:55
 * MD5              : a12ab1b15b1e6663e06c7ac4392029e8
 * Copyright        : © 2026 Viktor Glebov
 * ====================================================================== */