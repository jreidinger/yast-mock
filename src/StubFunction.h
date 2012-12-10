#ifndef MockFunction_h
#define MockFunction_h

#include <y2/Y2Function.h>

class StubFunction : public Y2Function
{
public:
  StubFunction ();

  ~StubFunction ();

  bool attachParameter (const YCPValue& arg, const int position);

  constTypePtr wantedParameterType () const;

  bool appendParameter (const YCPValue& arg);

  bool finishParameters();

  YCPValue evaluateCall();

  bool reset();

  string name() const { return "stub"; }

private:
  string method;
  YCPValue return_value;
  unsigned assigned_params;
};

#endif
