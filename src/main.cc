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
#include <memory>
#include <iostream>

#include <runtime/runtime.hh>

static const auto __ = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
  return nullptr;
}();

using compiler::CompilerRuntime;

// A shared compiler runtime.
std::unique_ptr<CompilerRuntime> compiler_runtime;

int main(int argc, const char** argv) {
  compiler_runtime = std::make_unique<CompilerRuntime>(argc, argv);
  compiler_runtime->run();

  return 0;
}