/*
   Purpose:	Access to mock functions
		Handles Mock::function (list_of_arguments) calls
/-*/

#ifndef MockModuleFunctions_h
#define MockModuleFunctions_h

#include <string>
#include <y2/Y2Namespace.h>

/**
 * A simple class for package management access
 */
class MockModule : public Y2Namespace
{
public:
  MockModule ();

  virtual ~MockModule ();

  virtual const std::string name () const { return "Mock"; }

  virtual const std::string filename () const { return "Mock"; }

  virtual std::string toString () const { return "// not supported"; }

  virtual YCPValue evaluate (bool cse = false );

  virtual Y2Function* createFunctionCall (const std::string name, constFunctionTypePtr type);

  static MockModule* instance ();

  static void destroy();
private:
  static MockModule* _instance;
};
#endif
