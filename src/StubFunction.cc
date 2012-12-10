#include "StubFunction.h"
#include "log.h"

#include <ycp/YCPBoolean.h>
#include <ycp/YCPString.h>
#include <ycp/YCPValue.h>

StubFunction::StubFunction() : assigned_params(0) 
{
}

StubFunction::~StubFunction() 
{
}

bool StubFunction::reset()
{
  method.clear();
  assigned_params = 0;
  return true;
}

bool StubFunction::attachParameter (const YCPValue& arg, const int position)
{
  switch(position)
  {
  case 0:
    {
      if (!arg->isString())
        return false;
      method = arg->asString()->value();
      break;
    }
  case 1:
    {
      return_value = arg;
      break;
    }
  default:
    {
      y2error("Attach to wrong argument %i",position);
      return false;
    }
  }

  return true;
}

constTypePtr StubFunction::wantedParameterType() const
{
  switch (assigned_params)
  {
  case 0:
    return Type::String;
  case 1:
    return Type::Any;
  default:
    return Type::Any;
  }
}

bool StubFunction::appendParameter(const YCPValue& arg)
{
  return attachParameter(arg,assigned_params++);
}

bool StubFunction::finishParameters()
{
  return assigned_params < 2;
}

YCPValue StubFunction::evaluateCall()
{
  return YCPBoolean(true);
}
