// Copyright © 2018-2019 Tokarev Artem Alekseevich. All rights reserved.
// Licensed under the MIT License.

#pragma once
#include <cmath>
#include <algorithm>
#include "simplex.h"

// TODO: experiment with pass by value instead of reference and make benchmark
namespace spt {

// TODO: make template functions instead later
using vec3 = spt::vec<3>;

template <typename Polytope>
typename Polytope::real_type volume(const Polytope* poly)
{
    static_assert(false);
}

template <typename Polytope>
typename Polytope::real_type volume<Polytope, 1>(const Polytope* poly)
{
    return (poly->facets[1]->pos - poly->facets[0]->pos).magnitude();
}

template <std::size_t Dim, typename Real>
Real volume<spt::simplex<2, Dim, Real>, 2>(const spt::simplex<2, Dim>* poly)
{
    //
}


vec3 project(
    const vec3& point,
    const vec3& line_p0, const vec3& line_p1);

// TODO: return std::optional<vec3>
bool project(
    vec3& out,
    const vec3& point,
    const vec3& segm_p0, const vec3& segm_p1);

vec3 project(
    const vec3& point,
    const vec3& plane_p0, const vec3& plane_p1, const vec3& plane_p2);

// TODO: return std::optional<vec3>
bool project(
    vec3& out,
    const vec3& point,
    const vec3& trngl_p0, const vec3& trngl_p1, const vec3& trngl_p2);

bool does_ray_intersect_plane(
    const vec3& dir,
    const vec3& plane_p0, const vec3& plane_p1, const vec3& plane_p2);

// TODO: return std::optional<vec3>
bool ray_intersect_plane(
    vec3& out_intersectPoint,
    const vec3& origin, const vec3& dir,
    const vec3& plane_p0, const vec3& plane_p1, const vec3& plane_p2);

bool does_ray_intersect_triangle(
    const vec3& origin, const vec3& dir,
    const vec3& trngl_p0, const vec3& trngl_p1, const vec3& trngl_p2);

// TODO: return std::optional<vec3>
bool ray_intersect_triangle(
    vec3& out_intersectPoint,
    const vec3& origin, const vec3& dir,
    const vec3& trngl_p0, const vec3& trngl_p1, const vec3& trngl_p2);

bool does_line_intersect_plane(
    const vec3& line_point, const vec3& line_dir,
    const vec3& plane_p0, const vec3& plane_p1, const vec3& plane_p2);

// TODO: return std::optional<vec3>
bool line_intersect_plane(
    vec3& out_intersectPoint,
    const vec3& line_point, const vec3& line_dir,
    const vec3& plane_p0, const vec3& plane_p1, const vec3& plane_p2);

vec3 line_intersect_plane(
    const vec3& line_point, const vec3& line_dir,
    const vec3& plane_p0, const vec3& plane_p1, const vec3& plane_p2);

bool does_segment_intersect_triangle(
    const vec3& segm_p0, const vec3& segm_p1,
    const vec3& trngl_p0, const vec3& trngl_p1, const vec3& trngl_p2);

// TODO: return std::optional<vec3>
bool segment_intersect_triangle(
    vec3& out_intersectPoint,
    const vec3& segm_p0, const vec3& segm_p1,
    const vec3& trngl_p0, const vec3& trngl_p1, const vec3& trngl_p2);

bool does_segment_intersect_plane(
    const vec3& segm_p0, const vec3& segm_p1,
    const vec3& plane_p0, const vec3& plane_p1, const vec3& plane_p2);

// TODO: return std::optional<vec3>
bool segment_intersect_plane(
    vec3& out_intersectPoint,
    const vec3& segm_p0, const vec3& segm_p1,
    const vec3& plane_p0, const vec3& plane_p1, const vec3& plane_p2);

vec3 segment_intersect_plane(
    const vec3& segm_p0, const vec3& segm_p1,
    const vec3& plane_p0, const vec3& plane_p1, const vec3& plane_p2);

bool does_triangle_intersect_sphere(
    const vec3& trngl_p0, const vec3& trngl_p1, const vec3& trngl_p2,
    const vec3& center, vec3::real_type radius);

vec3::real_type sqrs_sum(
    const vec3& point,
    const vec3& trngl_p0, const vec3& trngl_p1, const vec3& trngl_p2);

vec3::real_type max_sqrs_sum(
    const vec3& trngl_p0, const vec3& trngl_p1, const vec3& trngl_p2);

bool is_point_on_plane(
    const vec3& point,
    const vec3& plane_p0, const vec3& plane_p1, const vec3& plane_p2);

bool is_point_on_triangle(
    const vec3& point,
    const vec3& trngl_p0, const vec3& trngl_p1, const vec3& trngl_p2);

bool is_point_on_triangle(
    const vec3& point,
    const vec3& trngl_p0, const vec3& trngl_p1, const vec3& trngl_p2,
    vec3::real_type max_sqrs_sum);

bool is_point_in_tetrahedron(
    const vec3& point,
    const vec3& tetr_p0, const vec3& tetr_p1, const vec3& tetr_p2, const vec3& tetr_p3);

vec3 closest_segment_point_to_point(
    const vec3& point,
    const vec3& segm_p0, const vec3& segm_p1);

vec3 closest_triangle_point_to_point_on_plane(
    const vec3& point,
    const vec3& trngl_p0, const vec3& trngl_p1, const vec3& trngl_p2);

vec3::real_type distance_point_to_line(
    const vec3& point,
    const vec3& line_p0, const vec3& line_p1);

vec3::real_type distance_point_to_segment(
    const vec3& point,
    const vec3& segm_p0, const vec3& segm_p1);

vec3::real_type distance_point_to_plane(
    const vec3& point,
    const vec3& plane_p0, const vec3& plane_p1, const vec3& plane_p2);

vec3::real_type distance_point_to_triangle(
    const vec3& point,
    const vec3& trngl_p0, const vec3& trngl_p1, const vec3& trngl_p2);

vec3::real_type distance_point_to_triangle_on_plane(
    const vec3& point,
    const vec3& trngl_p0, const vec3& trngl_p1, const vec3& trngl_p2);

vec3 lines_closest_point(
    const vec3& line0_p0, const vec3& line0_p1,
    const vec3& line1_p0, const vec3& line1_p1);

vec3::real_type lines_distance(
    const vec3& line0_p0, const vec3& line0_p1,
    const vec3& line1_p0, const vec3& line1_p1);

vec3::real_type segments_distance(
    const vec3& segm0_p0, const vec3& segm0_p1,
    const vec3& segm1_p0, const vec3& segm1_p1);

// CPA - Closest Point of Approach.
vec3::real_type cpa_time(
    const vec3& start0, const vec3& vel0,
    const vec3& start1, const vec3& vel1);

vec3::real_type cpa_distance(
    const vec3& start0, const vec3& vel0,
    const vec3& start1, const vec3& vel1);

} // namespace spt::algs
