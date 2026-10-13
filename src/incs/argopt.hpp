/* ======================================================================================
 * Library       : vhlibargs
 * Description   : A C++ command-line parser library
 * Revision      : 0.1.0
 * Source        : https://github.com/vigatron/vhlibargs
 * Disclaimer    : Provided "AS IS", without warranty.
 * License       : MIT
 * File          : src/incs/argopt.hpp
 * Content size  : 589
 * Date / Time   : 13-10-2026 17:18:21
 * MD5           : 8e860fbe1b2f487bb52e73a0fdb3134e
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
                intdef = 1;
            } else {
                defval = "";
                intdef = 0;
            }
        }
    };

};
/* ========================[  END FILE CONTENT  ]========================
 * Library          : vhlibargs
 * File             : src/incs/argopt.hpp
 * Revision         : 0.1.0
 * Content size     : 589
 * Date / Time      : 13-10-2026 17:18:21
 * MD5              : 8e860fbe1b2f487bb52e73a0fdb3134e
 * Copyright        : © 2026 Viktor Glebov
 * ====================================================================== */