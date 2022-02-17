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
#include <sstream>

#include <nodes/item_decl.hh>
#include <common/termcolor.hh>
#include <common/utils.hh>

compiler::Item_decl::Item_decl(const uint32_t& line_no) : Item(line_no) {}

compiler::Item_stmt_decl::Item_stmt_decl(const uint32_t& line_no,
                                         const basic_type& type)
    : Item_stmt(line_no), type(type) {}

compiler::Item_decl_var::Item_decl_var(const uint32_t& line_no,
                                       Item_ident* const identifier)
    : Item_decl(line_no), identifier(identifier) {}

compiler::Item_decl_array::Item_decl_array(const uint32_t& line_no,
                                           Item_ident_array* const identifier)
    : Item_decl(line_no), identifier(identifier) {}

compiler::Item_decl_pointer::Item_decl_pointer(
    const uint32_t& line_no, Item_ident_pointer* const identifier)
    : Item_decl(line_no), identifier(identifier) {}

compiler::Item_decl_var_init::Item_decl_var_init(const uint32_t& line_no,
                                                 Item_ident* const identifier,
                                                 Item_expr* const expression,
                                                 const bool& is_const)
    : Item_decl_var(line_no, identifier),
      expression(expression),
      is_const(is_const) {}

compiler::Item_decl_array_init::Item_decl_array_init(
    const uint32_t& line_no, Item_ident_array* const identifier,
    Item_literal_array_init* const init_value, const bool& is_const)
    : Item_decl_array(line_no, identifier),
      init_value(init_value),
      is_const(is_const) {}

void compiler::Item_stmt_decl::add_declaration(Item_decl* const declaration) {
  declarations.emplace_back(declaration);
}

std::string compiler::Item_stmt_decl::print_result(const uint32_t& indent,
                                                   const bool& leaf) const {
  std::ostringstream oss;
  print_indent(indent, leaf, oss);
  oss << " Declaration" << '\n';

  for (uint32_t i = 0; i < declarations.size(); i++) {
    oss << declarations[i]->print_result(indent + 2,
                                         i == declarations.size() - 1);
  }
  return oss.str();
}

std::string compiler::Item_decl_var::print_result(const uint32_t& indent,
                                                  const bool& leaf) const {
  std::ostringstream oss;
  print_indent(indent, leaf, oss);
  oss << " Variable Declaration" << '\n';
  oss << identifier->print_result(indent + 2, true);
  return oss.str();
}

std::string compiler::Item_decl_var_init::print_result(const uint32_t& indent,
                                                       const bool& leaf) const {
  std::ostringstream oss;

  print_indent(indent, leaf, oss);
  oss << " Variale Declaration with initial value";
  if (is_const == true) {
    oss << " and is CONST" << termcolor::reset;
  }
  oss << '\n';
  oss << identifier->print_result(indent + 2, false);
  oss << expression->print_result(indent + 2, true);

  return oss.str();
}

std::string compiler::Item_decl_array::print_result(const uint32_t& indent,
                                                    const bool& leaf) const {
  std::ostringstream oss;
  print_indent(indent, leaf, oss);
  oss << " Array Declaration" << '\n';
  oss << identifier->print_result(indent + 2, true);
  return oss.str();
}

std::string compiler::Item_decl_array_init::print_result(
    const uint32_t& indent, const bool& leaf) const {
  std::ostringstream oss;
  print_indent(indent, leaf, oss);
  oss << " Array Declaration with initial value" << '\n';
  oss << identifier->print_result(indent + 2, false);
  oss << init_value->print_result(indent + 2, true);
  return oss.str();
}

std::string compiler::Item_decl_pointer::print_result(const uint32_t& indent,
                                                      const bool& leaf) const {
  std::ostringstream oss;
  print_indent(indent, leaf, oss);
  oss << " Pointer Declaration" << '\n';
  oss << identifier->print_result(indent + 2, true);
  return oss.str();
}
