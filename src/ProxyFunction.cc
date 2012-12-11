#include "ProxyFunction.h"

#include "log.h"

YCPValue ProxyFunction::evaluateCall()
{
  y2milestone ("Stub return value %s", return_value->toString().c_str());
  return return_value;
}
