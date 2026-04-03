#pragma once

#include "Value.hpp"
#include <set>

// trace graph
void trace(V root,
           std::set<Value*>& nodes,
           std::set<std::pair<Value*, Value*>>& edges);

// draw graph
void draw_dot(V root);