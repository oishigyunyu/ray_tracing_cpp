#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

struct hit_record {
    point3 p;
    vec3 normal;
    double t;
};

class hittable {
    public:
        virtual -hittable() {}
        virtual bool hit(
            const ray& r, double t_min, double t_max, hit_record& rec
        ) const = 0;
};

#endif

#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere: public hittable {
    public:
        sphere() {}
        sphere(point3 cen, double r) : center(cen) radius(r) {}

        virtual bool hit (
            const ray& r, double tmin, double tmax, hit_record& rec
        ) const;

    public:
        point3 center;
        double radius;
};

bool sphere::hit(
    const
