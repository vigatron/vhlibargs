/* ======================================================================================
 * Library       : vhlibargs
 * Description   : A C++ command-line parser library
 * Revision      : 0.1.0
 * Source        : https://github.com/vigatron/vhlibargs
 * Disclaimer    : Provided "AS IS", without warranty.
 * License       : MIT
 * File          : src/incs/argopt.hpp
 * Content size  : 570
 * Date / Time   : 13-10-2026 17:30:59
 * MD5           : b31e930a2d13a5436f466e880da911ff
 * Notes         : MD5 = file content without header/footer
 * Encoding      : UTF-8
 * Author        : Viktor Glebov / V01G04A81
 * Copyright     : © 2026 Viktor Glebov
 * ========================[ BEGIN FILE CONTENT ]====================================== */
#pragma once
#include "argbase.hpp"

namespace VHArgsParser {

/**
 * Single Option param without followed extended arg
 */
class VHArgTypeOption : public VHArgTypeBase {
  public:
    VHArgTypeOption(const std::string &keyval, const std::string &desc, bool def)
        : VHArgTypeBase(keyval, desc, false) {
        typearg = eOptType::eOptTypeOption;
        intdef = def ? 1 : 0;
        if (def) {
            defval = "1";
            intdef = 1;
        } else {
            defval = "";
            intdef = 0;
        }
    }
};
};    // namespace VHArgsParser

/* ========================[  END FILE CONTENT  ]========================
 * Library          : vhlibargs
 * File             : src/incs/argopt.hpp
 * Revision         : 0.1.0
 * Content size     : 570
 * Date / Time      : 13-10-2026 17:30:59
 * MD5              : b31e930a2d13a5436f466e880da911ff
 * Copyright        : © 2026 Viktor Glebov
 * ====================================================================== */