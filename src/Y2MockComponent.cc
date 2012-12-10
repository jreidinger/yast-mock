#include <y2/Y2Namespace.h>
#include <y2/Y2Component.h>
#include <y2/Y2ComponentCreator.h>

#include "Y2MockComponent.h"

#include "MockModule.h"

Y2Namespace *Y2MockComponent::import (const char* name)
{
  if ( strcmp (name, "Mock") == 0)
  {
    return MockModule::instance ();
  } else {
	  return NULL;
  }
}

Y2MockComponent* Y2MockComponent::m_instance = NULL;

Y2MockComponent* Y2MockComponent::instance ()
{
  if (m_instance == NULL)
  {
    m_instance = new Y2MockComponent ();
  }

  return m_instance;
}

void Y2MockComponent::destroy()
{
    MockModule::destroy();
}

Y2MockComponent::~Y2MockComponent()
{
    MockModule::destroy();
}
