#include "SeedCreator.hpp"

SeedCreator::SeedCreator(Hasher* hasher)
: hasher(hasher)
, state(2)
{
}