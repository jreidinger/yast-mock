/*
 * Component Creator that executes access to mocking functionality
 */

#ifndef Y2CCMock_h
#define Y2CCMock_h

#include <y2/Y2ComponentCreator.h>

class Y2Component;

class Y2CCMock : public Y2ComponentCreator
{
public:
    Y2CCMock() : Y2ComponentCreator(Y2ComponentBroker::BUILTIN) {}

    /**
     * Tries to create a Mock module
     */
    virtual Y2Component *createInLevel(const char *name, int level, int current_level) const;

    virtual bool isServerCreator() const;
    
    /**
     * We provide the Pkg namespace
     */
    virtual  Y2Component *provideNamespace(const char *name);

    ~Y2CCMock();
};


#endif
