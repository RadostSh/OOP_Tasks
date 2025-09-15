#pragma once
#include "BooleanExpression.h"

class Unary : public BooleanExpression
{
public:
    Unary(BooleanExpression* expr);
    void populateVariables(BooleanInterpretation& interpretation) const override;
    ~Unary();
protected:
    BooleanExpression* expr;
};

class Negation : public Unary
{
public:
    Negation(BooleanExpression* expr);
    bool eval(const BooleanInterpretation& interpretation) const override;
    BooleanExpression* clone() const override;
};