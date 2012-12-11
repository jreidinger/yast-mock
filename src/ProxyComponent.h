#ifndef Y2ProxyComponent_h
#define Y2ProxyComponent_h

#include <y2/Y2Namespace.h>
#include <y2/Y2Component.h>

#include <map>

class ProxyComponent : public Y2Component {
public:
    ProxyComponent(Y2Component* original) :
      real_component(original)
    { }

    ~ProxyComponent();

    Y2Namespace *import (const char* name);

    string name () const { return string("Proxy for ")+real_component->name();}

private:
    Y2Component* real_component;
    std::map<std::string,Y2Namespace*> namespaces;
};

#endif
