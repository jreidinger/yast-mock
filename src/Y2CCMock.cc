/*
 * Component Creator that executes access to mock utility
 */



#include <y2/Y2Component.h>

#include "Y2CCMock.h"
#include "Y2MockComponent.h"
#include "log.h"

Y2Component *Y2CCMock::createInLevel(const char *name, int level, int) const
{
  if (strcmp (name, "mock") == 0){
    return Y2MockComponent::instance ();
  } else {
    return NULL;
  }
}

bool Y2CCMock::isServerCreator() const
{
    return false;
}

Y2Component* Y2CCMock::provideNamespace(const char* name)
{
  if (strcmp (name, "Mock") == 0){
    return Y2MockComponent::instance ();
  } else {
    return NULL;
  }
}

Y2CCMock::~Y2CCMock()
{
    Y2MockComponent::destroy();
}

// Create global variable to register this component creator

Y2CCMock g_y2ccMock;
