#ifndef RAYTRI_H
#define RAYTRI_H

/* This file was automatically generated.  Do not edit! */
int intersect_triangle3(double orig[3],double dir[3],double vert0[3],double vert1[3],double vert2[3],double *t,double *u,double *v);
int intersect_triangle2(double orig[3],double dir[3],double vert0[3],double vert1[3],double vert2[3],double *t,double *u,double *v);
int intersect_triangle1(double orig[3],double dir[3],double vert0[3],double vert1[3],double vert2[3],double *t,double *u,double *v);
int intersect_triangle(double orig[3],double dir[3],double vert0[3],double vert1[3],double vert2[3],double *t,double *u,double *v);

#endif // RAYTRI_H
