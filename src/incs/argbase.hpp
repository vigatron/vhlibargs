/* ======================================================================================
 * Library       : vhlibargs
 * Description   : A C++ command-line parser library
 * Revision      : 0.1.0-rc3
 * Source        : https://github.com/vigatron/vhlibargs
 * Disclaimer    : Provided "AS IS", without warranty.
 * License       : MIT
 * File          : src/incs/argbase.hpp
 * Content size  : 5782
 * Date / Time   : 06-09-2026 16:07:24
 * MD5           : 8161b883e36e3f3f8c5d4fbc080a02bb
 * Notes         : MD5 = file content without header/footer
 * Encoding      : UTF-8
 * Author        : Viktor Glebov / V01G04A81
 * Copyright     : © 2026 Viktor Glebov
 * ========================[ BEGIN FILE CONTENT ]====================================== */
#pragma once

#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>

namespace VHArgsParser
{

    enum class eOptType
    {
        eOptTypeNoParam = 0,
        eOptTypeString,
        eOptTypeFilename,
        eOptTypeCommand,
        eOptTypeInteger,
        eOptTypeOption
    };

    constexpr std::string_view strTypeFile = "File";
    constexpr std::string_view strTypeText = "String";
    constexpr std::string_view strTypeCmd = "Command";
    constexpr std::string_view strTypeInt = "Integer";
    constexpr std::string_view strTypeOpt = "Option";
    constexpr std::string_view strTypeUnk = "?";

    constexpr std::string_view strForbiddenChars = "<>%*?:\0";

    class VHArgTypeBase
    {
    public:
        VHArgTypeBase(
            const std::string &keyval,
            const std::string &desc,
            bool extraparam)
        {
            keyname = keyval;
            keydesc = desc;
            extra = extraparam;
            parsed = false;
        }

        eOptType typearg;
        std::string keyname;
        std::string keydesc;

        // Text related
        std::string defval;
        std::string strval;

        // Integer related
        int intmin;
        int intval;
        int intmax;
        int intdef;

        // value always should follow next !
        bool extra;

        // was found in cmd line and parsed
        bool parsed;

        /**
         * @brief Assigns the default value to the argument.
         * @return True if the assignment is successful, false otherwise.
         */
        bool AssignDefault()
        {
            if (isTypeFileName() || isTypeString())
            {
                strval = defval;
            }
            else
            {
                intval = intdef;
            }

            return true;
        }

        /**
         * @brief Assigns a value to the argument.
         * @param param The value to assign.
         * @return True if the assignment is successful, false otherwise.
         */
        bool Assign(const std::string &param)
        {

            if (isTypeFileName())
            {
                // Forbidden chars ? Error
                if (param.find_first_of(strForbiddenChars) != std::string::npos)
                    return false;
                strval = param;
            }
            else if (isTypeString())
            {
                strval = param;
            }
            else
            {
                intval = std::stoi(param);

                // Out of range ? Error
                if (intval < intmin || intval > intmax)
                    return false;
            }

            return true;
        }

        /**
         * @brief Checks if the argument is a command.
         * @return True if the argument is a command, false otherwise.
         */
        bool isCommand() const
        {
            return typearg == eOptType::eOptTypeCommand;
        }

        /**
         *
         */
        bool isTypeFileName() const
        {
            return typearg == eOptType::eOptTypeFilename;
        }

        /**
         * @brief Checks if the argument is of text type.
         * @return True if the argument is of text type, false otherwise.
         */
        bool isTypeString() const
        {
            return typearg == eOptType::eOptTypeString;
        }

        /**
         * @brief Checks if the argument is of integer type.
         * @return True if the argument is of integer type, false otherwise.
         */
        bool isTypeInt() const
        {
            return typearg == eOptType::eOptTypeInteger;
        }

        /**
         * @brief Checks if the argument is of bool type.
         * @return True if the argument is of bool type, false otherwise.
         */
        bool isTypeOpt() const
        {
            return typearg == eOptType::eOptTypeOption;
        }

        /**
         * @brief Checks if the argument has been parsed.
         * @return True if the argument has been parsed, false otherwise.
         */
        bool isParsed() const
        {
            return parsed;
        }

        /**
         * @brief Returns the string representation of the argument type.
         * @return The string representation of the argument type.
         */
        const char *getTypeString() const
        {
            switch (typearg)
            {
            case eOptType::eOptTypeFilename:
                return strTypeFile.data();
            case eOptType::eOptTypeString:
                return strTypeText.data();
            case eOptType::eOptTypeCommand:
                return strTypeCmd.data();
            case eOptType::eOptTypeInteger:
                return strTypeInt.data();
            case eOptType::eOptTypeOption:
                return strTypeOpt.data();
            }
            return strTypeUnk.data();
        }

        /**
         * @brief Returns a string containing information about the argument key.
         * @return A string containing information about the argument key.
         */
        std::string getKeyInfo() const
        {

            std::string r;

            if (isTypeFileName() || isTypeString())
            {
                r += defval;
                return r;
            }
            else if (isTypeInt())
            {
                r += "val " + std::to_string(intval);
                r += " [ min " + std::to_string(intmin);
                r += " max " + std::to_string(intmax);
                r += " ] def " + std::to_string(intdef);
                return r;
            }
            else if (isTypeOpt())
            {
                r += defval.size() ? "true" : "false";
                return r;
            }

            return "";
        }
    };

};
/* ========================[  END FILE CONTENT  ]========================
 * Library          : vhlibargs
 * File             : src/incs/argbase.hpp
 * Revision         : 0.1.0-rc3
 * Content size     : 5782
 * Date / Time      : 06-09-2026 16:07:24
 * MD5              : 8161b883e36e3f3f8c5d4fbc080a02bb
 * Copyright        : © 2026 Viktor Glebov
 * ====================================================================== */