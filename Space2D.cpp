#include "Space2D.h"

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

	return true
}

template <class T>
bool Swap(Limit<T>& In) {
	if (In.UP < In.Buttom) { Swap(In.UP, In.Buttom); }

	return true;
}

Space2D ConstructSpace2D(const size_t& Width, const size_t& Height, const Size2D<Limit<double>>& X) {
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
	if (P.X <= In.Size.X.UP) { return false; }
	if (P.X >= In.Size.X.Buttom) { return false; }

	if (P.Y <= In.Size.Y.UP) { return false; }
	if (P.Y >= In.Size.Y..Buttom) { return false; }

	(*Index(In.S24, P.X, P.Y)) = C;

	return true;
}