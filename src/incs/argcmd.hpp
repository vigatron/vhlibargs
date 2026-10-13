/* ======================================================================================
 * Library       : vhlibargs
 * Description   : A C++ command-line parser library
 * Revision      : 0.1.0-rc3
 * Source        : https://github.com/vigatron/vhlibargs
 * Disclaimer    : Provided "AS IS", without warranty.
 * License       : MIT
 * File          : src/incs/argcmd.hpp
 * Content size  : 422
 * Date / Time   : 06-09-2026 16:07:24
 * MD5           : 0be26933a19fea51c59d127cdee7a848
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
    class VHArgTypeCommand : public VHArgTypeBase
    {
    public:
        VHArgTypeCommand(const std::string &keyval, const std::string &desc)
            : VHArgTypeBase(keyval, desc, false)
        {
            typearg = eOptType::eOptTypeCommand;
        }
    };

};
/* ========================[  END FILE CONTENT  ]========================
 * Library          : vhlibargs
 * File             : src/incs/argcmd.hpp
 * Revision         : 0.1.0-rc3
 * Content size     : 422
 * Date / Time      : 06-09-2026 16:07:24
 * MD5              : 0be26933a19fea51c59d127cdee7a848
 * Copyright        : © 2026 Viktor Glebov
 * ====================================================================== */