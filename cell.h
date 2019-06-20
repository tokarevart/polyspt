#pragma once
#include "polyhedron.h"

namespace spt {

template <std::size_t Dim = 3, typename Real = typename spt::vec<Dim>::real_type>
using cell = polyhedron<Dim, Real>;

} // namespace spt
