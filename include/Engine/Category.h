#ifndef CATEGORY_H
#define CATEGORY_H

namespace BW {

    // Enumeration of possible message types, based on type of scene graph object.
    enum Category {
        None  = 0,
        Scene = 1 << 0
    };
}

#endif // CATEGORY_H
