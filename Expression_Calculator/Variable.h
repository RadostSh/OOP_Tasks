#pragma once
#include "BooleanExpression.h"

class Variable : public BooleanExpression
{
public:
    Variable(char ch);
    bool eval(const BooleanInterpretation& interpretation) const override;
    void populateVariables(BooleanInterpretation& interpretation) const override;

    BooleanExpression* clone() const override;

private:
    char ch;
};