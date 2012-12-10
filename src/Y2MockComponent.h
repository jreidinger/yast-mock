#ifndef Y2MockComponent_h
#define Y2MockComponent_h

#include <y2/Y2Namespace.h>
#include <y2/Y2Component.h>

class Y2MockComponent : public Y2Component {
public:
    virtual Y2Namespace *import (const char* name);

    virtual string name () const { return "Mock";}

    static Y2MockComponent* instance();

    static void destroy();

    ~Y2MockComponent();

private:
    static Y2MockComponent* m_instance;
};

#endif
