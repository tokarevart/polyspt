#pragma once
#include <cstddef>
#include "vec.h"


namespace spt {

template <std::size_t N, std::size_t Dim = 3, typename Real = typename spt::vec<Dim>::value_type>
struct polytope;

enum class amount {
    single,
    aggregate
};

} // namespace spt
