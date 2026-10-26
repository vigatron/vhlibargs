/* ======================================================================================
 * Library       : vhlibargs
 * Description   : A C++ command-line parser library
 * Revision      : 0.2.0
 * Source        : https://github.com/vigatron/vhlibargs
 * Disclaimer    : Provided "AS IS", without warranty.
 * License       : MIT
 * File          : src/incs/argopt.hpp
 * Content size  : 450
 * Date / Time   : 26-10-2026 22:43:15
 * MD5           : 2d16ac6446ec3e53d23020ebca463695
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
class VHCLIArgOpt : public VHArgTypeBase {
  public:
    VHCLIArgOpt(const std::string &keyval, bool def, const std::string &desc)
        : VHArgTypeBase(keyval, desc, false) {
        typearg = eOptType::eOptTypeOption;
        intdef = def ? 1 : 0;
        defval = def ? "1" : "";
    }
};
};    // namespace VHArgsParser

/* ========================[  END FILE CONTENT  ]========================
 * Library          : vhlibargs
 * File             : src/incs/argopt.hpp
 * Revision         : 0.2.0
 * Content size     : 450
 * Date / Time      : 26-10-2026 22:43:15
 * MD5              : 2d16ac6446ec3e53d23020ebca463695
 * Copyright        : © 2026 Viktor Glebov
 * ====================================================================== */