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
#ifndef AST_HH
#define AST_HH

#include <memory>
#include <string>
#include <vector>

namespace kaleidoscope {

class AbstractAST {
 public:
  virtual ~AbstractAST();
};

class StatementAST : public AbstractAST {};

class BlockAST : public AbstractAST {
  std::vector<std::unique_ptr<StatementAST>> body;

 public:
  void addChild(std::unique_ptr<StatementAST> child) {
    body.push_back(std::move(child));
  }
};

class RootAST : public AbstractAST {
  std::vector<std::unique_ptr<AbstractAST>> children;

 public:
  void addChild(std::unique_ptr<AbstractAST> child) {
    children.push_back(std::move(child));
  }
};

class ExprAST : public StatementAST {};

class LiteralExprAST : public ExprAST {
 public:
  LiteralExprAST() = default;
};

class IntLiteralExprAST : public LiteralExprAST {
  bool isChar;
  int value;

 public:
  IntLiteralExprAST(bool isChar, int value) : isChar(isChar), value(value) {}
};

class FloatLiteralExprAST : public LiteralExprAST {
  double value;

 public:
  FloatLiteralExprAST(double value) : value(value) {}
};

class StringLiteralExprAST : public LiteralExprAST {
  std::string value;

 public:
  StringLiteralExprAST(const std::string& value) : value(value) {}
};

class VariableExprAST : public ExprAST {
  std::string name;

 public:
  VariableExprAST(const std::string& name) : name(name) {}

  const std::string& getName() const { return name; }
};

class PrototypeAST {
  std::unique_ptr<VariableExprAST> name;
  std::vector<VariableExprAST> args;

 public:
  PrototypeAST(std::unique_ptr<VariableExprAST> name,
               std::vector<VariableExprAST> args)
      : name(std::move(name)), args(std::move(args)) {}

  const std::unique_ptr<VariableExprAST>& getName() const { return name; }
};

class FunctionAST : public RootAST {
  std::unique_ptr<PrototypeAST> prototype;
  std::unique_ptr<BlockAST> body;

 public:
  FunctionAST(std::unique_ptr<PrototypeAST> prototype,
              std::unique_ptr<BlockAST> body)
      : prototype(std::move(prototype)), body(std::move(body)) {}
};

class BinaryExprAST : public ExprAST {
  char Op;
  std::unique_ptr<ExprAST> LHS, RHS;

 public:
  BinaryExprAST(char Op, std::unique_ptr<ExprAST> LHS,
                std::unique_ptr<ExprAST> RHS)
      : Op(Op), LHS(std::move(LHS)), RHS(std::move(RHS)) {}
};

class CallExprAST : public ExprAST {
  std::string Callee;
  std::vector<std::unique_ptr<ExprAST>> Args;

 public:
  CallExprAST(const std::string& Callee,
              std::vector<std::unique_ptr<ExprAST>> Args)
      : Callee(Callee), Args(std::move(Args)) {}
};

}  // namespace kaleidoscope

#endif  // !AST_HH