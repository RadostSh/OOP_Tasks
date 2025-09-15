#include "Binary.h"

Binary::Binary(BooleanExpression* lhs, BooleanExpression* rhs) : lhs(lhs), rhs(rhs)
{
}

void Binary::populateVariables(BooleanInterpretation& interpretation) const
{
    lhs->populateVariables(interpretation);
    rhs->populateVariables(interpretation);
}

Binary::~Binary()
{
    delete lhs;
    delete rhs;
}

Conjunction::Conjunction(BooleanExpression* lhs, BooleanExpression* rhs) : Binary(lhs, rhs)
{
}

bool Conjunction::eval(const BooleanInterpretation& interpretation) const
{
    return lhs->eval(interpretation) && rhs->eval(interpretation);
}

BooleanExpression* Conjunction::clone() const
{
    return new Conjunction(lhs->clone(), rhs->clone());
}

Disjunction::Disjunction(BooleanExpression* lhs, BooleanExpression* rhs) : Binary(lhs, rhs)
{
}

bool Disjunction::eval(const BooleanInterpretation& interpretation) const
{
    return lhs->eval(interpretation) || rhs->eval(interpretation);
}

BooleanExpression* Disjunction::clone() const
{
    return new Disjunction(lhs->clone(), rhs->clone());
}

Implies::Implies(BooleanExpression* lhs, BooleanExpression* rhs) : Binary(lhs, rhs)
{
}

bool Implies::eval(const BooleanInterpretation& interpretation) const
{
    return !lhs->eval(interpretation) || rhs->eval(interpretation);
}

BooleanExpression* Implies::clone() const
{
    return new Implies(lhs->clone(), rhs->clone());
}
