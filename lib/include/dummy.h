#ifndef CMAKE_STARTER_PROJECT_DUMMY_H
#define CMAKE_STARTER_PROJECT_DUMMY_H

namespace dummy {

class Dummy {
private:
    int dummy;

public:
    Dummy(int dummy) : dummy(dummy) { }

    int GetDummy() const;
};

}

#endif //CMAKE_STARTER_PROJECT_DUMMY_H
