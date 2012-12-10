
#include "MockModule.h"

#include <y2/Y2Function.h>
#include <ycp/YCPVoid.h>
#include "log.h"

MockModule::MockModule()
    : Y2Namespace()
{
}

MockModule::~MockModule()
{
}

Y2Function* MockModule::createFunctionCall (const string name, constFunctionTypePtr type)
{
  y2error ("No such function %s", name.c_str ());
  return NULL;
}

YCPValue MockModule::evaluate(bool cse)
{
    if (cse) return YCPNull ();
    else return YCPVoid ();
}

MockModule* MockModule::_instance = NULL;

MockModule* MockModule::instance()
{
  if (_instance == NULL)
    _instance = new MockModule();

  return _instance;
}

void MockModule::destroy()
{
  if (_instance == NULL)
    return;

  delete _instance;
  _instance = NULL;
}
