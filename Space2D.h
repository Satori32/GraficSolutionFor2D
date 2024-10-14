#pragma once

#include <stdio.h>

#include "Surface24.h"
#include "Size2D.h"
#include "Point2D.h"
#include "Point3D.h"

template<class T>
struct Limit {
	T UP = 0;
	T Buttom = 0;
};

struct Space2D
{
	Surface24 S24;
	Size2D<Limit<double>> Size;
};

template <class T> bool Swap(Limit<T>& In);
Space2D ConstructSpace2D(const size_t& Width, const size_t& Height, const Size2D<Limit<double>>& X);
bool Free(Space2D& In);
bool SetPixel(Space2D& In, Point2D<double>& P, RGB C);