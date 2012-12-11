#ifndef MockFunction_h
#define MockFunction_h

#include <y2/Y2Function.h>

class ProxyFunction : public Y2Function
{
public:
  ProxyFunction (Y2Function* original, YCPValue response) : 
    original_function(original),return_value(response)
  { }

  ~ProxyFunction () { delete original_function; }

  bool attachParameter (const YCPValue& arg, const int position)
  { return original_function->attachParameter(arg,position); }

  constTypePtr wantedParameterType () const
  { return original_function->wantedParameterType(); }

  bool appendParameter (const YCPValue& arg)
  { return original_function->appendParameter(arg); }

  bool finishParameters()
  { return original_function->finishParameters(); }

  YCPValue evaluateCall();

  bool reset()
  { return original_function->reset(); }

  string name() const
  { return original_function->name(); }

private:
  Y2Function *original_function;
  YCPValue return_value;
};

#endif
