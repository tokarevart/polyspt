#pragma once
#include "edge.h"
#include <vector>

namespace spt {

template <std::size_t Dim, typename Real = typename spt::vec<Dim>::value_type>
using polygon = polytope<2, Dim, Real>;

template <typename Real> using polygon2 = polygon<2, Real>;
using polygon2f = polygon2<float>;
using polygon2d = polygon2<double>;
template <typename Real> using polygon3 = polygon<3, Real>;
using polygon3f = polygon3<float>;
using polygon3d = polygon3<double>;

template <std::size_t Dim, typename Real>
struct polytope<2, Dim, Real> {
    static constexpr std::size_t n = 2;
    static constexpr std::size_t dim = Dim;
    using real_type = Real;
    using vertex_type = spt::vertex<Dim, Real>;
    using edge_type = spt::edge<Dim, Real>;
    using facet_type = edge_type;

    std::vector<edge_type*> edges;

    template <typename SubPolytope>
    auto all_of() const {
        static_assert(
            std::is_same<edge_type, SubPolytope>() ||
            std::is_same<vertex_type, SubPolytope>());
        if constexpr (std::is_same<edge_type, SubPolytope>())
            return edges;
        else {
            std::vector<SubPolytope*> res;
            for (const auto& edge : edges)
                for (const auto& vert : edge->vertices)
                    if (std::find(res.begin(), res.end(), vert) == res.end())
                        res.push_back(vert);

            return res;
        }
    }

    bool empty() const {
        return edges.empty();
    }
    
    bool contains(const edge_type* edge) const {
        return edges[0] == edge || edges[1] == edge || edges[2] == edge;
    }
    bool contains(const vertex_type* vert) const {
        return edges[0]->contains(vert) || edges[1]->contains(vert) || edges[2]->contains(vert);
    }

    polytope(const polytope& poly) {
        edges = poly.edges;
    }
    polytope(polytope&& poly) {
        edges = std::move(poly.edges);
    }
    polytope(const std::vector<edge_type*>& edges)
        : edges{ edges } {}
    template <typename... Edges>
    polytope(Edges... edges)
        : edges{ const_cast<edge_type*>(edges)... } {}
};

} // namespace spt
