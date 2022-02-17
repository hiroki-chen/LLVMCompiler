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
#ifndef UTILS_HH
#define UTILS_HH

#include <cstdint>
#include <ostream>

#include <common/types.hh>

namespace compiler {
/**
 * @brief Print indentation for each node in the AST.
 *
 * @param indent
 * @param leaf
 * @param os
 */
void print_indent(const uint32_t& indent, const bool& leaf, std::ostream& os);

std::string to_string(const compiler::basic_type& type);

std::string to_string(const compiler::unary_type& type);

std::string to_string(const compiler::binary_type& type);

}  // namespace compiler

#endif