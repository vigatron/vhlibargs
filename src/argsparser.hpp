/* ======================================================================================
 * Library       : vhlibargs
 * Description   : A C++ command-line parser library
 * Revision      : 0.1.0-rc2
 * Source        : https://github.com/vigatron/vhlibargs
 * Disclaimer    : Provided "AS IS", without warranty.
 * License       : MIT
 * File          : src/argsparser.hpp
 * Content size  : 14847
 * Date / Time   : 06-09-2026 01:45:55
 * MD5           : 4e59031359b24e4d8070a398fe527dbe
 * Notes         : MD5 = file content without header/footer
 * Encoding      : UTF-8
 * Author        : Viktor Glebov / V01G04A81
 * Copyright     : © 2026 Viktor Glebov
 * ========================[ BEGIN FILE CONTENT ]====================================== */
#pragma once

#include "incs/argbase.hpp"
#include "incs/argstr.hpp"
#include "incs/argfile.hpp"
#include "incs/argcmd.hpp"
#include "incs/argopt.hpp"
#include "incs/argint.hpp"

namespace VHArgsParser
{

#ifndef VHPLATFORM_INCLUDED
#define verr uint32_t
#define verror(X) (X)
#define vok verror(0)
    verr verrmsg(int x, const std::string &errmsg);
#endif

    /**
     * Header only implementation
     */
    class VHCmdLineParser
    {

    public:
        /**
         * @brief Constructor for the VHArgsParser class.
         */
        VHCmdLineParser() {}

        /**
         * @brief Parses the command line and returns the result.
         * @param keyslist List of keys to parse.
         * @param argc Number of command line arguments.
         * @param argv Array of command line arguments.
         * @return Result of command line parsing.
         */
        verr ParseCommandLine(
            const std::vector<VHArgTypeBase> &keyslist,
            int argc, char *argv[])
        {
            // No params avail ?
            if (argc < 2)
            {
                ShowUsage(keyslist);
                return 0;
            }

            // Step #1: Preprocess given keys list
            for (const VHArgTypeBase &key : keyslist)
            {
                verr status = add(key);
                if (status != vok)
                    return verrmsg(1, "Can't add key: " + key.keyname);
            }

            // Step #2: Assign default values to unlisted
            for (size_t idx = 0; idx < arrkeys.size(); idx++)
            {
                if (!arrkeys[idx].AssignDefault())
                    return verrmsg(1, "Can't set default value: " + arrkeys[idx].keyname);
            }

            // Step #3: Process argv[] / command line
            for (int i = 1; i < argc; i++)
            {
                char *strarg = argv[i];
                std::string txtargv = std::string(strarg);

                verr status = ProcessArgument(txtargv);
                if (status != vok)
                    return verrmsg(1, "Error processing argv '" + txtargv + "'");
            }

            // All keys passs or incompleted param left ?
            if (extFollowed)
            {
                return verrmsg(1, std::string("key passed without param"));
            }

            return vok;
        }

        /**
         *
         */
        const std::string &GetFileName(const std::string &keyname) const
        {

            int idx = InternalFindKeyIdx(keyname);
            if (idx == -1)
                return strEmptyString;

            const VHArgTypeBase &kobj = GetKeyByIndex(idx);
            if (!kobj.isArgTypeText())
                return strEmptyString;

            return kobj.strval;
        }

        /**
         *
         */
        const std::string &GetString(const std::string &keyname) const
        {

            int idx = InternalFindKeyIdx(keyname);
            if (idx == -1)
                return strEmptyString;

            const VHArgTypeBase &kobj = GetKeyByIndex(idx);
            if (!kobj.isArgTypeText())
                return strEmptyString;

            return kobj.strval;
        }

        /**
         *
         */
        const std::string &GetCommand() const
        {

            int idx = InternalFindIndexActivatedCmd();
            if (idx == -1)
                return strEmptyString;

            const VHArgTypeBase &kobj = GetKeyByIndex(idx);
            if (!kobj.isCommand())
                return strEmptyString;

            return kobj.keyname;
        }

        /**
         * @brief Returns the int value for a given key.
         * @param keyname Name of the key to find.
         * @return Int value for the key if found, and 0 if the key is not found.
         */
        int GetInt(const std::string &keyname) const
        {
            int idx = InternalFindKeyIdx(keyname);
            if (idx == -1)
                return 0;

            const VHArgTypeBase &kobj = GetKeyByIndex(idx);
            if (!kobj.isArgTypeInt())
                return 0;

            return kobj.intval;
        }

        /**
         * @brief Checks if a key is an option and returns its value.
         * @param keyname Name of the key to find.
         * @return True if the key is an option and is set to true, false otherwise.
         */
        bool GetOpt(const std::string &keyname) const
        {

            int idx = InternalFindKeyIdx(keyname);
            if (idx == -1)
                return false;

            const VHArgTypeBase &kobj = GetKeyByIndex(idx);
            if (!kobj.isArgTypeOpt())
                return 0;

            return kobj.intval;
        }

        /**
         * @brief Returns a list of parameters.
         * @return A vector of strings containing the list of parameters.
         */
        const std::vector<std::string> listparams()
        {
            std::vector<std::string> arr;

            // opts first
            for (int i = 0; i < arrkeys.size(); i++)
            {
                std::string info;
                std::stringstream ss;
                std::string str1 = arrkeys[i].getTypeString();
                std::string str2 = arrkeys[i].getKeyInfo();

                ss << std::left << std::setw(12) << arrkeys[i].keyname + " ";
                ss << std::left << std::setw(12) << str1 << " ";
                ss << std::left << std::setw(12) << str2 << " ";

                arr.push_back(ss.str());
            }

            // args next
            for (int i = 0; i < arrsingle.size(); i++)
            {
                arr.push_back(arrsingle[i]);
            }

            return arr;
        }

        /**
         * @brief Returns a vector of strings containing individual parameters.
         * @return A constant vector of strings containing individual parameters.
         */
        const std::vector<std::string> &singles() const
        {
            return arrsingle;
        }

        /**
         * @brief Returns the VHArgTypeBase object by its index.
         * @param idx Index of the key.
         * @return VHArgTypeBase object at the specified index.
         */
        const VHArgTypeBase &GetKeyByIndex(size_t idx) const
        {
            return arrkeys[idx];
        }

        /**
         * @brief Finds the index of a key by its name.
         * @param keyname Name of the key to find.
         * @return Index of the key in the list of keys, if the key is found,
         *         and -1 otherwise.
         */
        int FindKeyIdxByName(std::string keyname)
        {
            for (size_t i = 0; i < arrkeys.size(); i++)
            {
                if (arrkeys[i].keyname == keyname)
                    return i;
            }
            return -1;
        }

        /**
         * @brief Sets the application name.
         * @param str New application name.
         */
        void setAppName(const std::string &str)
        {
            appname = str;
        }

        /**
         * @brief Sets the application description.
         * @param desc Description of the application.
         */
        void setAppDesc(const std::string &desc)
        {
            appdesc = desc;
        }

        /**
         * @brief Outputs usage information for the application.
         */
        void ShowUsage(const std::vector<VHArgTypeBase> &keyslist)
        {
            std::cout << getappname() << " " << appdesc;
            std::cout << "USAGE : " << getappname() + " [... params ...]" << std::endl;
            for (int i = 0; i < keyslist.size(); i++)
            {
                std::cout
                    << "\t" + keyslist[i].keyname
                    << "\t" << keyslist[i].keydesc
                    << std::endl;
            }
        }

    private:
        // *Local private vars*

        std::string appname;                // Application Name
        std::string appdesc;                // Application description
        std::vector<VHArgTypeBase> arrkeys; // List of keys
        std::vector<std::string> arrsingle; // Individual parameters
        bool extFollowed = false;           // Flag indicating that an additional argument is expected
        size_t idxExtFollow;                // Index of the next argument

        std::string strEmptyString;

        /**
         * @brief Finds the index of a key by its name.
         * @param keyname Name of the key to find.
         * @return Index of the key in the list of keys, if the key is found,
         *         and -1 otherwise.
         */
        int InternalFindKeyIdx(const std::string &keyname) const
        {
            for (size_t i = 0; i < arrkeys.size(); i++)
            {
                if (arrkeys[i].keyname == keyname)
                    return i;
            }
            return -1;
        }

        /**
         * @brief Checks if a string starts with '-'.
         * @param str String to check.
         * @return Returns true if the string starts with '-', and false otherwise.
         */
        bool hasPrefix(std::string str)
        {
            if (str.size() < 2)
                return false;
            return str[0] == '-';
        }

        /**
         * @brief Returns the application name.
         * @return The application name if set, and "application" otherwise.
         */
        std::string getappname()
        {
            return appname.size() ? appname : "application";
        }

        /**
         * @brief Checks if the key name is valid and unique.
         * @param keyname Key name to check.
         * @return Returns true if the key name is valid and unique, and false otherwise.
         */
        bool checkIsValidAndUnique(const std::string &keyname)
        {
            // Valid key name ?
            if (!keyname.size())
            {
                return false;
            }

            // Check if already present
            if (-1 != InternalFindKeyIdx(keyname))
                return false;

            return true;
        }

        // /**
        //  * @brief Finds the index of a key that is a command.
        //  * @return Index of the key that is a command, if a command is found,
        //  *         and -1 otherwise.
        //  */
        // int __FindIndexWithCmdFlag()
        // {
        //     for (int i = 0; i < arrkeys.size(); i++)
        //     {
        //         if (arrkeys[i].isCommand())
        //             return i;
        //     }
        //     return -1;
        // }

        /**
         * @brief Parses a prefixed parameter.
         * @param keytxt Prefixed parameter to parse.
         * @return Result of parsing the parameter.
         */
        verr ParsePrefixedParam(const std::string &keytxt)
        {
            // Find dedicated key
            int keyidx = InternalFindKeyIdx(keytxt);
            if (-1 == keyidx)
                return verrmsg(1, "Invalid key: " + keytxt);

            // Mark `extra` should follow
            VHArgTypeBase &arg = arrkeys[keyidx];
            if (arg.isParsed())
                return verrmsg(1, "Dublicated key: " + keytxt);

            // Mark as used
            arg.parsed = true;

            // Save idx for next stage
            if (arg.extra)
            {
                extFollowed = true;
                idxExtFollow = keyidx;
            }

            if (arg.isCommand())
            {
                // Already avail ? Only one cmd allowed
                int previdx = InternalFindIndexActivatedCmd();
                if (previdx != -1)
                    if (arrkeys[previdx].strval.size())
                        return verror(1);

                // Mark executable command
                arg.strval = "1";
            }
            else if (arg.isArgTypeOpt())
            {
                arg.intval = 1;
            }

            return vok;
        }

        /**
         * @brief Parses a default parameter.
         * @param param Default parameter to parse.
         * @return Result of parsing the parameter.
         */
        verr ParseDefaultParam(const std::string &param)
        {
            arrsingle.push_back(param);
            return vok;
        }

        /**
         * @brief Adds a key to the list of keys.
         * @param key Object of type VHArgTypeBase to add.
         * @return Result of adding the key.
         */
        verr add(const VHArgTypeBase &key)
        {
            if (!checkIsValidAndUnique(key.keyname))
                return verrmsg(1, "key add() found dublicated: " + key.keyname);

            // Append key
            arrkeys.push_back(key);

            return vok;
        }

        /**
         * @brief Processes a command line argument.
         * @param txtargv Command line argument to process.
         * @return Result of processing the argument.
         */
        verr ProcessArgument(const std::string &txtargv)
        {
            if (extFollowed)
            {
                extFollowed = false;
                VHArgTypeBase &arg = arrkeys[idxExtFollow];
                verr status = arg.Assign(txtargv) ? vok : verror(1);
                if (status != vok)
                    return verrmsg(1, "Invalid parameter value for key " + arg.keyname);
                return vok;
            }

            if (hasPrefix(txtargv))
            {
                verr status = ParsePrefixedParam(txtargv);
                return status;
            }

            verr status = ParseDefaultParam(txtargv);
            if (status != vok)
                return status;

            return vok;
        }

        /**
         * @brief Finds the index of a file type key by its name.
         * @param keyname Name of the key to find.
         * @return Index of the key in the list of keys, if the key is found and is a file type key,
         *         and -1 otherwise.
         */
        int InternalFindKeyTypeFileNameIdx(const std::string &keyname) const
        {
            for (size_t i = 0; i < arrkeys.size(); i++)
            {
                if (arrkeys[i].keyname == keyname)
                    if (arrkeys[i].typearg == eOptType::eOptTypeFilename)
                        if (arrkeys[i].strval.size())
                            return i;
            }
            return -1;
        }

        /**
         * @brief Finds the index of the selected command.
         * @return Index of the selected command in the list of keys, if a command is found,
         *         and -1 otherwise.
         */
        int InternalFindIndexActivatedCmd() const
        {
            for (int i = 0; i < arrkeys.size(); i++)
            {
                if (arrkeys[i].isCommand())
                    if (arrkeys[i].strval.size())
                        return i;
            }
            return -1;
        }
    };

};
/* ========================[  END FILE CONTENT  ]========================
 * Library          : vhlibargs
 * File             : src/argsparser.hpp
 * Revision         : 0.1.0-rc2
 * Content size     : 14847
 * Date / Time      : 06-09-2026 01:45:55
 * MD5              : 4e59031359b24e4d8070a398fe527dbe
 * Copyright        : © 2026 Viktor Glebov
 * ====================================================================== */