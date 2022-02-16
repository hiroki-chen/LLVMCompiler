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
#ifndef ITEM_LITERAL_HH
#define ITEM_LITERAL_HH

#include <nodes/item_expr.hh>

#include <string>
#include <vector>

namespace compiler {

/**
 * @brief Class for literals.
 * 
 */
typedef class Item_literal : public Item_expr {
public:
    typedef enum literal_type {
        INT_TYPE,
        REAL_TYPE,
        CHAR_TYPE,
        STRING_TYPE,
        ARRAY_INIT,
    } literal_type;

    virtual Item_literal::literal_type get_literal_type(void) const = 0;

    virtual Item_expr::expr_type get_expr_type(void) const override { return Item_expr::expr_type::LITERAL_TYPE; }

    Item_literal() = delete;

    Item_literal(const uint32_t& line_no);

    virtual ~Item_literal() override = default;
} Item_literal;

/**
 * @brief Class for basic numbers. INT/DOUBLE/CHAR
 * 
 */
typedef class Item_literal_numeric : public Item_literal {
protected:
    const double value;

public:
    Item_literal_numeric() = delete;

    Item_literal_numeric(const uint32_t& line_no, const double& value);

    virtual Item_literal::literal_type get_literal_type(void) const override = 0;

    virtual std::string print_result(const uint32_t& indent, const bool& leaf) const override;

    virtual ~Item_literal_numeric() override = default;
} Item_literal_numeric;

typedef class Item_literal_int final : public Item_literal_numeric {
public:
    virtual Item_literal::literal_type get_literal_type(void) const override { return Item_literal::literal_type::INT_TYPE; }

    virtual int get_int() const { return (int)value; }

    Item_literal_int() = delete;

    Item_literal_int(const uint32_t& line_no, const int& value);

    virtual ~Item_literal_int() override = default;
} Item_literal_int;

typedef class Item_literal_real final : public Item_literal_numeric {
public:
    virtual Item_literal::literal_type get_literal_type(void) const override { return Item_literal::literal_type::REAL_TYPE; }

    virtual double get_double() const { return (double)value; }

    virtual float get_float() const { return (float)value; }

    Item_literal_real() = delete;

    Item_literal_real(const uint32_t& line_no, const double& value);

    virtual ~Item_literal_real() override = default;
} Item_literal_real;

typedef class Item_literal_char final : public Item_literal_numeric {
public:
    virtual Item_literal::literal_type get_literal_type(void) const override { return Item_literal::literal_type::CHAR_TYPE; }

    virtual char get_char() const { return (char)value; }

    Item_literal_char() = delete;

    Item_literal_char(const uint32_t& line_no, const char& value);

    virtual ~Item_literal_char() override = default;
} Item_literal_char;

typedef class Item_literal_string final : public Item_literal {
protected:
    const std::string str;

public:
    virtual Item_literal::literal_type get_literal_type(void) const override { return Item_literal::literal_type::STRING_TYPE; }

    virtual std::string get_str(void) const { return str; }

    Item_literal_string() = delete;

    Item_literal_string(const uint32_t& line_no, const std::string& str);

    virtual std::string print_result(const uint32_t& indent, const bool& leaf) const override;

    virtual ~Item_literal_string() override = default;
} Item_literal_string;

/**
 * @brief Class for array init value.
 * 
 */
typedef class Item_literal_array_init : public Item_literal {
protected:
    const bool is_numeric;

    Item_expr* const expression;

    std::vector<Item_literal_array_init*> value_list;

public:
    virtual Item_literal::literal_type get_literal_type(void) const override { return Item_literal::literal_type::ARRAY_INIT; }

    virtual void add_value(Item_literal_array_init* const value);

    Item_literal_array_init() = delete;

    Item_literal_array_init(const uint32_t& line_no, Item_expr* const expression, const bool& is_numeric);

    virtual std::string print_result(const uint32_t& indent, const bool& leaf) const override;

    virtual ~Item_literal_array_init() override = default;
} Item_literal_array_init;
} // namespace compiler

#endif