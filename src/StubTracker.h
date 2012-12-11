#ifndef StubTracker_h
#define StubTracker_h

#include <string>
#include <map>

#include <ycp/YCPValue.h>

class ProxyModule;

class StubTracker
{
public:
  StubTracker();
  ~StubTracker();

  static StubTracker* instance();

  void stubMethod(const std::string& namespace_name, const std::string& method,
      YCPValue response);

private:
  static StubTracker* _instance;
  map<std::string,ProxyModule*> stub_modules;
};

#endif
