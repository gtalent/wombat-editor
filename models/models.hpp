#ifndef MODELS_MODELS_HPP
#define MODELS_MODELS_HPP

#include "generated.hpp"

namespace models {

inline bool operator<(const Point &p1, const Point &p2) {
	return p1.X < p2.X || (p1.X == p2.X && p1.Y < p2.Y);
}


}

#endif
