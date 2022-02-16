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
#include <common/termcolor.hh>
#include <common/utils.hh>

void compiler::print_indent(const uint32_t& indent, const bool& leaf,
                            std::ostream& os) {
  // Print indentation.
  for (uint32_t i = 0; i < indent; i += 2) {
    os << termcolor::bright_green << "│  " << termcolor::reset;
  }

  // Print node.
  if (leaf) {
    os << termcolor::bright_green << (std::string) "└──" << termcolor::reset;
  } else {
    os << termcolor::bright_green << (std::string) "├──" << termcolor::reset;
  }
}