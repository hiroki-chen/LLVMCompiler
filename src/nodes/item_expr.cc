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

#include <nodes/item_expr.hh>
#include <common/utils.hh>

compiler::Item_expr::Item_expr(const uint32_t& line_no) : Item(line_no) {}

compiler::Item_expr_cond::Item_expr_cond(const uint32_t& line_no,
                                         Item_expr* const item_expr)
    : Item_expr(line_no), expr(item_expr) {}

compiler::Item_expr_binary::Item_expr_binary(const uint32_t& line_no,
                                             const binary_type& type,
                                             Item_expr* const lhs,
                                             Item_expr* const rhs)
    : Item_expr(line_no), type(type), lhs(lhs), rhs(rhs) {}

compiler::Item_expr_comma::Item_expr_comma(const uint32_t& lineno)
    : Item_expr(lineno) {}

compiler::Item_expr_unary::Item_expr_unary(const uint32_t& line_no,
                                           const unary_type& type,
                                           Item_expr* const expr)
    : Item_expr(line_no), type(type), expr(expr) {}

std::string compiler::Item_expr_cond::print_result(const uint32_t& indent,
                                                   const bool& leaf) const {
  std::ostringstream oss;
  oss << "Node: Conditional Expression" << std::endl;
  oss << "--Expression: " << std::endl << expr->print_result() << std::endl;
  return oss.str();
}

std::string compiler::Item_expr_binary::print_result(const uint32_t& indent,
                                                     const bool& leaf) const {
  std::ostringstream oss;
  oss << "Node: Binary Expression" << std::endl;
  oss << "--Left Expression: " << std::endl << lhs->print_result() << std::endl;
  oss << "--Right Expression: " << std::endl
      << rhs->print_result() << std::endl;
  return oss.str();
}

std::string compiler::Item_expr_unary::print_result(const uint32_t& indent,
                                                    const bool& leaf) const {
  std::ostringstream oss;
  oss << "Node: Unary Expression" << std::endl;
  oss << "--Expression: " << std::endl << expr->print_result() << std::endl;
  return oss.str();
}

std::string compiler::Item_expr_comma::print_result(const uint32_t& indent,
                                                    const bool& leaf) const {
  std::ostringstream oss;
  print_indent(indent, leaf, oss);
  oss << " Comma Expression" << '\n';
  for (uint32_t i = 0; i < expressions.size(); i++) {
    oss << expressions[i]->print_result(
        indent + 2, i == expressions.size() - 1 ? true : false);
  }
  return oss.str();
}