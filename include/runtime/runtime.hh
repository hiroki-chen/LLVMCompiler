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
#include <memory>
#include <string>

#include <llvm/ADT/StringRef.h>
#include <llvm/IR/IRBuilder.h>

#include <nodes/item_all.hh>

namespace compiler {

// Use StringRef instead of const char*.
const llvm::StringRef additionalMessage =
    " This is a toy compiler for a C-like language written by Haobin Chen.";
// For IR generation.
static llvm::LLVMContext context;
static llvm::IRBuilder<> irBuilder(context);
static std::unique_ptr<llvm::Module> thisModule;

// Specify the optimization level.
enum OptLevel { g, O1, O2, O3 };

class CompilerRuntime final {
 private:
  // The path of the source file.
  std::string inputFile;
  // The path of the output file.
  std::string outputFile;

  // Root node of the AST.
  Item_root* root;

  // An interface which is used to generate LLVM IR.
  void codeGenerate(std::ostream& out) const;

  void astGenerate(std::ostream& out) const;

 public:
  void run();

  CompilerRuntime() = delete;

  CompilerRuntime(int argc, const char** argv);

  void setRoot(Item_root* const root) { this->root = root; }

  ~CompilerRuntime() = default;
};
}  // namespace compiler

#endif