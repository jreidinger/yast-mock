/*
   Purpose:	Special module that serves as module, that decide
   if call mock or real method
/-*/

#ifndef ProxyModuleFunctions_h
#define ProxyModuleFunctions_h

#include <string>
#include <y2/Y2Namespace.h>

/**
 * A simple class for package management access
 */
class ProxyModule : public Y2Namespace
{
public:
  ProxyModule (Y2Namespace *original) : real_namespace(original)
  { }

  ~ProxyModule ();

  const std::string name () const { return real_namespace->toString(); }

  const std::string filename () const { return real_namespace->toString(); }

  std::string toString () const { return real_namespace->toString(); }

  SymbolTable *table() const { return real_namespace->table(); }

  YCPValue evaluate (bool cse = false ) { return real_namespace->evaluate(cse); }

  Y2Function* createFunctionCall (const std::string name, constFunctionTypePtr type);

  void addStub(const std::string& name, YCPValue response) { stubs[name] = response; }

  void deleteStub(const std::string& name) { stubs.erase(name); }

  void deleteAllStubs(const std::string& name) { stubs.clear(); }

private:
  Y2Namespace *real_namespace;
  map<string,YCPValue> stubs;
};

#endif
