#pragma once
#include "BooleanExpression.h"

class Binary : public BooleanExpression
{
public:
    Binary(BooleanExpression* lhs, BooleanExpression* rhs);
    void populateVariables(BooleanInterpretation& interpretation) const override;
    ~Binary();
protected:
    BooleanExpression* lhs;
    BooleanExpression* rhs;
};

class Conjunction : public Binary
{
public:
    Conjunction(BooleanExpression* lhs, BooleanExpression* rhs);
    bool eval(const BooleanInterpretation& interpretation) const override;
    BooleanExpression* clone() const override;
};

class Disjunction : public Binary
{
    public:
    Disjunction(BooleanExpression* lhs, BooleanExpression* rhs);
    bool eval(const BooleanInterpretation& interpretation) const override;
    BooleanExpression* clone() const override;
};

class Implies : public Binary
{
    public:
    Implies(BooleanExpression* lhs, BooleanExpression* rhs);
    bool eval(const BooleanInterpretation& interpretation) const override;
    BooleanExpression* clone() const override;
};