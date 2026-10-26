# vhlibargs

> A lightweight, header-only C++ command-line arguments parser library.

- **Author**: Viktor Glebov
- **Version**: 0.2.0
- **Language**: C++ (C++17 and later)
- **License**: MIT

---

## 📌 Features

- **Header-only**: Zero compilation overhead, just include `argsparser.hpp`.
- **Type-safe**: Dedicated getter methods (`GetInt`, `GetString`, etc.) prevent casting errors.
- **Built-in Validation**: 
  - Integer bounds checking (`min` / `max`).
  - Filename forbidden characters detection.
  - Duplicate key prevention.
- **Flexible Argument Types**: Supports integers, strings, filenames, boolean options, exclusive commands, and positional arguments.
- **Minimal Dependencies**: Standalone by default, optionally integrates with `vhlibplatform` for unified error codes (`verr`, `vok`).

---

## 📦 Installation

### Option 1: CMake (Recommended)
Add the repository as a submodule and include it in your `CMakeLists.txt`:

```cmake
add_subdirectory(path/to/vhlibargs)
target_link_libraries(your_target PRIVATE vhlib_args)
```

### Option 2: Manual Integration
Simply copy `src/argsparser.hpp` and the `src/incs/` directory into your project's include path.

---

## 🚀 Quick Start

Here is a comprehensive example demonstrating metadata setup, argument registration, parsing, and value retrieval.

```cpp
#include <iostream>
#include <vector>
#include "argsparser.hpp"

using namespace VHArgsParser;

int main(int argc, char** argv) {
    VHCmdLineParser cmdline;

    // 1. Setup application metadata
    cmdline.setAppName("vhtool");
    cmdline.setAppDesc("compression tool. V0.1.0");

    // 2. Define expected arguments
    std::vector<VHArgTypeBase> arrcmd;

    // Commands (mutually exclusive)
    arrcmd.push_back(VHCLIArgCmd("-compress", "Run compression"));
    arrcmd.push_back(VHCLIArgCmd("-extract", "Run extraction"));

    // Integers with min/max validation: (key, default, min, max, description)
    arrcmd.push_back(VHCLIArgInt("-B", 1024, 1, 4096, "Pack block size"));
    arrcmd.push_back(VHCLIArgInt("-cd", 0, 0, 128, "Color: 0 disabled, >=1 blocksize"));

    // Strings and Files: (key, default_value, description)
    arrcmd.push_back(VHCLIArgFile("-srcfile", "", "Source file path"));
    arrcmd.push_back(VHCLIArgStr("-logfolder", ".", "Logs folder"));

    // Boolean options: (key, default_bool, description)
    arrcmd.push_back(VHCLIArgOpt("-cntr", false, "Container allowed / disabled"));

    // 3. Parse command line
    verr parse_status = cmdline.ParseCommandLine(arrcmd, argc, argv);

    // 4. Handle parsing errors
    if (parse_status != vok) {
        std::cerr << "Error parsing command line. Use -h for help.\n";
        return 1;
    }

    // 5. Retrieve values safely
    std::string cmd = cmdline.GetCommand();
    if (cmd == "-compress") {
        int block_size = cmdline.GetInt("-B");
        std::string src = cmdline.GetFileName("-srcfile");
        bool use_container = cmdline.GetOpt("-cntr");
        
        std::cout << "Compressing: " << src 
                  << " (Block: " << block_size 
                  << ", Container: " << (use_container ? "yes" : "no") << ")\n";
    } else {
        cmdline.ShowUsage(arrcmd);
    }

    return 0;
}
```

---

## 📚 API Reference

### Argument Types
⚠️ **Note**: Pay attention to the parameter order, which differs slightly between types.

| Class | Constructor Signature | Description |
| :--- | :--- | :--- |
| `VHCLIArgCmd` | `(key, desc)` | Mutually exclusive command trigger. Only one can be active. |
| `VHCLIArgInt` | `(key, default, min, max, desc)` | Validates integer input against `min` and `max` bounds. |
| `VHCLIArgStr` | `(key, default, desc)` | Standard string parameter. |
| `VHCLIArgFile` | `(key, default, desc)` | String parameter with forbidden characters validation (`<>%*?:\0`). |
| `VHCLIArgOpt` | `(key, default_bool, desc)` | Boolean flag. Does not consume the next `argv` token. |

### `VHCmdLineParser` Methods

| Method | Return Type | Description |
| :--- | :--- | :--- |
| `setAppName(str)` | `void` | Sets the application name for usage output. |
| `setAppDesc(str)` | `void` | Sets the application description for usage output. |
| `ParseCommandLine(keys, argc, argv)` | `verr` | Parses arguments. Returns `vok` (0) on success, error code otherwise. |
| `GetInt(key)` | `int` | Retrieves integer value. Returns `0` if not found or wrong type. |
| `GetString(key)` | `std::string` | Retrieves string value. Returns empty string if not found. |
| `GetFileName(key)` | `std::string` | Retrieves validated file path. Returns empty string if not found. |
| `GetOpt(key)` | `bool` | Retrieves boolean state of an option flag. |
| `GetCommand()` | `std::string` | Returns the name of the activated command (e.g., `"-compress"`). |
| `singles()` | `const std::vector<std::string>&` | Returns a list of positional (non-prefixed) arguments. |
| `listparams()` | `std::vector<std::string>` | Returns a formatted list of all parsed parameters for debugging. |
| `ShowUsage(keys)` | `void` | Prints formatted help text to `stdout`. |

---

## ⚙️ Advanced Usage

### Positional Arguments
Arguments without a `-` prefix are automatically collected as positional parameters. Retrieve them using the `singles()` method:

```cpp
// Example: ./app -compress file1.txt file2.txt
const auto& positional = cmdline.singles();
for (const auto& arg : positional) {
    std::cout << "Positional arg: " << arg << "\n";
}
```

### Error Handling
The library uses a lightweight error code system:
- `vok`: Success (value `0`).
- `verr`: Unsigned 32-bit integer representing an error code.
- `verrmsg(code, message)`: Helper function to log and return an error.

If `argc < 2`, the parser automatically invokes `ShowUsage()` and returns `vok` (intended behavior for triggering help when no args are provided).

---

## 📄 License

Distributed under the **MIT License**. See the `LICENSE` file or repository header for details.  
*Provided "AS IS", without warranty of any kind.*

---
*© 2026 Viktor Glebov / V01G04A81*
