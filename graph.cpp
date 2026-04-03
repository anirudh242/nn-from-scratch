#include "graph.hpp"
#include <fstream>

// collect nodes + edges
void trace(V root,
           std::set<Value*>& nodes,
           std::set<std::pair<Value*, Value*>>& edges) {

    if (!nodes.count(root.get())) {
        nodes.insert(root.get());

        for (auto& child : root->prev) {
            edges.insert({child.get(), root.get()});
            trace(child, nodes, edges);
        }
    }
}

// generate dot file
void draw_dot(V root) {
    std::set<Value*> nodes;
    std::set<std::pair<Value*, Value*>> edges;

    trace(root, nodes, edges);

    std::ofstream file("graph.dot");

    file << "digraph G {\n";
    file << "rankdir=LR;\n";  // left to right layout

    // nodes
    for (auto n : nodes) {
        // value node
        file << "\"" << n << "\" [label=\"{"
             << n->label
             << " | data=" << n->data
             << " | grad=" << n->grad
             << "}\", shape=record];\n";

        // op node (if exists)
        if (!n->op.empty()) {
            file << "\"" << n << n->op << "\" [label=\""
                 << n->op << "\"];\n";

            // connect op -> value
            file << "\"" << n << n->op << "\" -> \"" << n << "\";\n";
        }
    }

    // edges (connect parents to op nodes)
    for (auto e : edges) {
        auto parent = e.first;
        auto child = e.second;

        if (!child->op.empty()) {
            // parent → op
            file << "\"" << parent << "\" -> \""
                 << child << child->op << "\";\n";
        } else {
            // fallback (no op)
            file << "\"" << parent << "\" -> \"" << child << "\";\n";
        }
    }

    file << "}\n";
}