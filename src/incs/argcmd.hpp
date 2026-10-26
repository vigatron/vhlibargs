/* ======================================================================================
 * Library       : vhlibargs
 * Description   : A C++ command-line parser library
 * Revision      : 0.2.0
 * Source        : https://github.com/vigatron/vhlibargs
 * Disclaimer    : Provided "AS IS", without warranty.
 * License       : MIT
 * File          : src/incs/argcmd.hpp
 * Content size  : 412
 * Date / Time   : 26-10-2026 22:43:15
 * MD5           : 95690a2b2e517029241af0fbb2c06988
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
     * Only one command from enumerated keys can be passed to the app
     */
    class VHCLIArgCmd : public VHArgTypeBase
    {
    public:
        VHCLIArgCmd(const std::string &keyval, const std::string &desc)
            : VHArgTypeBase(keyval, desc, false)
        {
            typearg = eOptType::eOptTypeCommand;
        }
    };

};
/* ========================[  END FILE CONTENT  ]========================
 * Library          : vhlibargs
 * File             : src/incs/argcmd.hpp
 * Revision         : 0.2.0
 * Content size     : 412
 * Date / Time      : 26-10-2026 22:43:15
 * MD5              : 95690a2b2e517029241af0fbb2c06988
 * Copyright        : © 2026 Viktor Glebov
 * ====================================================================== */