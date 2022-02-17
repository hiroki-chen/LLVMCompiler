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
#include <cassert>

#include <llvm/Support/CommandLine.h>
#include <llvm/Support/ErrorHandling.h>

#include <runtime/runtime.hh>

using namespace llvm;

// Predefined command line fields and their usage.
cl::opt<std::string> outputFileName("o", cl::desc("Specify output filename"),
                                    cl::value_desc("filename"));
cl::opt<std::string> sourceFileName(cl::Positional, cl::desc("<input file>"),
                                    cl::init("-"), cl::Required);
cl::opt<bool> emitLLVM("emit-llvm",
                       cl::desc("Output the LLVM IR for the source program"),
                       cl::Optional);
cl::opt<bool> emitAST("emit-ast",
                       cl::desc("Output the AST for the source program"),
                       cl::Optional);
cl::opt<bool> verbose("verbose", cl::desc("Enable verbose mode"), cl::Optional);
cl::opt<compiler::OptLevel> optimizationLevel(
    cl::desc("Choose optimization level:"),
    cl::values(
        clEnumValN(compiler::OptLevel::g, "g", "Debug mode, no optimizations"),
        clEnumValN(compiler::OptLevel::O1, "O1", "Enable trivial optmiations"),
        clEnumValN(compiler::OptLevel::O2, "O2", "Enable default optmiations"),
        clEnumValN(compiler::OptLevel::O3, "O3",
                   "Enable radical optmiations (may cause problems)")));

// External interfaces and variables provided by the yacc.
extern int yyparse();
extern int yylex_destroy();
extern void yyset_lineno(int);
extern int yycolumn;
extern void yyset_in(FILE*);

compiler::CompilerRuntime::CompilerRuntime(int argc, const char** argv)
    : root(nullptr) {
  // Feed the command line parser.
  cl::ParseCommandLineOptions(argc, argv, additionalMessage);
}

void compiler::CompilerRuntime::run() {
  inputFile = sourceFileName;
  outputFile = outputFileName;

  // Dispatch the file to the lexer and parse the tokens.
  yyset_lineno(1);
  yyset_in(fopen(inputFile.c_str(), "r"));
  yyparse();
  yylex_destroy();

  // Do the job.
  if (emitAST == true) {
    astGenerate(errs());
  }
}

void compiler::CompilerRuntime::codeGenerate(llvm::raw_ostream& out) const {}

void compiler::CompilerRuntime::astGenerate(llvm::raw_ostream& out) const {
  errs() << "Generating AST for the source file...\n";

  assert(root != nullptr && "The root node cannot be null!");
  out << root->print_result(0, false);
}