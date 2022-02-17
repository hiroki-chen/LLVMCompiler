/*
 Copyright (c) 2021 Haobin Chen

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
#include <sstream>
#include <string>

#include <llvm/Support/ErrorHandling.h>

#include <nodes/item_literal.hh>
#include <common/termcolor.hh>
#include <common/utils.hh>

compiler::Item_literal::Item_literal(const uint32_t& line_no)
    : Item_expr(line_no) {}

compiler::Item_literal_numeric::Item_literal_numeric(const uint32_t& line_no,
                                                     const double& value)
    : Item_literal(line_no), value(value) {}

compiler::Item_literal_int::Item_literal_int(const uint32_t& line_no,
                                             const int& value)
    : Item_literal_numeric(line_no, (double)value) {}

compiler::Item_literal_real::Item_literal_real(const uint32_t& line_no,
                                               const double& value)
    : Item_literal_numeric(line_no, (double)value) {}

compiler::Item_literal_char::Item_literal_char(const uint32_t& line_no,
                                               const char& value)
    : Item_literal_numeric(line_no, (double)value) {}

compiler::Item_literal_string::Item_literal_string(const uint32_t& line_no,
                                                   const std::string& str)
    : Item_literal(line_no), str(str) {}

compiler::Item_literal_array_init::Item_literal_array_init(
    const uint32_t& line_no, Item_expr* const expression,
    const bool& is_numeric)
    : Item_literal(line_no), expression(expression), is_numeric(is_numeric) {}

void compiler::Item_literal_array_init::add_value(
    Item_literal_array_init* const value) {
  value_list.emplace_back(value);
}

std::string compiler::Item_literal_numeric::print_result(
    const uint32_t& indent, const bool& leaf) const {
  std::ostringstream oss;

  print_indent(indent, leaf, oss);
  oss << " Literal Numeric with value ";

  switch (get_literal_type()) {
    case Item_literal::literal_type::INT_TYPE: {
      oss << int(value) << termcolor::reset << '\n';
      break;
    }
    case Item_literal::literal_type::CHAR_TYPE: {
      oss << char(value) << termcolor::reset << '\n';
      break;
    }
    case Item_literal::literal_type::REAL_TYPE: {
      oss << double(value) << termcolor::reset << '\n';
      break;
    }
    default: {
      llvm::report_fatal_error("Errorenous literal type!");
    }
  }

  return oss.str();
}

std::string compiler::Item_literal_string::print_result(
    const uint32_t& indent, const bool& leaf) const {
  std::ostringstream oss;

  oss << " Literal String with value " << termcolor::red << str
      << termcolor::reset << '\n';
  return oss.str();
}

std::string compiler::Item_literal_array_init::print_result(
    const uint32_t& indent, const bool& leaf) const {
  std::stringstream oss;
  print_indent(indent, leaf, oss);
  oss << " Literal Array Init" << '\n';

  if (expression != nullptr) {
    oss << expression->print_result(indent + 2, false);
  }

  for (uint32_t i = 0; i < value_list.size(); i++) {
    oss << value_list[i]->print_result(indent + 2, i == value_list.size() - 1);
  }

  return oss.str();
}