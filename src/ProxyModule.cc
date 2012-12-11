
#include "ProxyModule.h"

#include <y2/Y2Function.h>
#include <ycp/YCPVoid.h>
#include "log.h"

#include "ProxyFunction.h"

ProxyModule::~ProxyModule()
{
}

Y2Function* ProxyModule::createFunctionCall (const string name, constFunctionTypePtr type)
{

  Y2Function* original = real_namespace->createFunctionCall(name, type);
  if (stubs.count(name) == 0)
  {
    y2milestone ("Proxy module called for %s. Passing to original implementation.", name.c_str());
    return original;
  }

  y2milestone ("Proxy module called for %s. Providing proxy function.", name.c_str());
  return new ProxyFunction(original,stubs[name]);
}
