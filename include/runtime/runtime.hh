/*
 Copyright (c) 2022 Haobin Chen

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef RUNTIME_HH
#define RUNTIME_HH

#include <fstream>
#include <string>

#include <llvm/ADT/StringRef.h>

namespace kaleidoscope {

// Use StringRef instead of const char*.
const llvm::StringRef additionalMessage = " This is a toy compiler for a python-C-mix language written by Haobin Chen.";

// Specify the optimization level.
enum OptLevel {
  g, O1, O2, O3
};

class KaleidoscopeRuntime final {
 private:
  // The path of the source file.
  std::string inputFile;

  // The path of the output file.
  std::string outputFile;

 public:
  void run();

  KaleidoscopeRuntime() = delete;

  KaleidoscopeRuntime(int argc, const char** argv);

  ~KaleidoscopeRuntime() = default;
};
}  // namespace kaleidoscope

#endif