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

template<class T>
Limit<T> ConstructLimit(T UP, T Buttom) {
	Limit<T> L;
	L.UP = UP;
	L.Buttom = Buttom;

	return L;
}

template<class T>
bool Swap(T& A, T& B) {
	T C = A;
	A = B;
	B = C;

	return true;
}

template <class T>
bool Swap(Limit<T>& In) {
	if (In.UP < In.Buttom) { Swap(In.UP, In.Buttom); }

	return true;
}

struct Space2D
{
	Surface24 S24;
	Size2D<Limit<double>> Size;
};

Space2D ConstructSpace2D(const size_t& Width, const size_t& Height,const Size2D<Limit<double>>& X) {
	Space2D S;
	S.S24 = ConstructSurface24(Width, Height);
	S.Size = X;
	return S;
}

bool Free(Space2D& In) {
	Free(In.S24);
	ToZero(In.Size);
}

bool SetPixel(Space2D& In, Point2D<double>& P, RGB C) {
	if (Index(In.S24, P.X, P.Y) == NULL) { return false; }
	if (P.X >= In.Size.X) { return false; }
	if (P.Y >= In.Size.Y) { return false; }
	(*Index(In.S24, P.X, P.Y)) = C;

	return true;
}

int main() {
	Space2D S = ConstructSpace2D(16, 16, { 1,1 });

	RGB C;
	C.R = 128;
	SetPixel(S, { 8,8 }, C);

	Free(S);

	return 0;
}