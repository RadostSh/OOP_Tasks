#include "Unary.h"

Unary::Unary(BooleanExpression* expr)
{
    this->expr = expr;
}

void Unary::populateVariables(BooleanInterpretation& interpretation) const
{
    expr->populateVariables(interpretation);
}

Unary::~Unary()
{
    delete expr;
}

Negation::Negation(BooleanExpression* expr) : Unary(expr) {}

bool Negation::eval(const BooleanInterpretation& interpretation) const
{
    return !expr->eval(interpretation);
}

BooleanExpression* Negation::clone() const
{
    return new Negation(expr->clone());
}
