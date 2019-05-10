#pragma
#ifndef _NODE_H
#define _NODE_H

#include "vec.h"

using namespace utils;
namespace level
{
    struct Node
    {
        Node(const Vector2i& tile, Node *parent, double gCost, double hCost)
            : tile(tile), parent(parent), gCost(gCost), hCost(hCost)
            , fCost(gCost + hCost)
        {
        }

        double fCost;
        double gCost;
        double hCost;
        Vector2i tile;
        Node *parent;
    };
}

#endif /* end of include guard:  */
