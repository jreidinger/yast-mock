#include "StubTracker.h"

#include <y2/Y2Component.h>
#include <y2/Y2ComponentBroker.h>
#include <ycp/Import.h>

#include "ProxyComponent.h"
#include "ProxyModule.h"
#include "log.h"

StubTracker *StubTracker::_instance = NULL;

StubTracker::StubTracker()
{}

StubTracker::~StubTracker()
{}

StubTracker* StubTracker::instance()
{
  if (_instance == NULL)
    _instance = new StubTracker();

  return _instance;
}

void StubTracker::stubMethod(const std::string& namespace_name, const std::string& method,
      YCPValue response)
{
  if (stub_modules.count(namespace_name) == 0)
  {
    Y2Component *original = Y2ComponentBroker::getNamespaceComponent(namespace_name.c_str());
    ProxyComponent *proxy_component = new ProxyComponent(original);
    Y2ComponentBroker::replaceNamespaceComponent(namespace_name.c_str(),proxy_component);
    //Import caches result of component broker, so we need to clear it too
    Import::resetCache(namespace_name);
    stub_modules[namespace_name] = (ProxyModule*)proxy_component->import(namespace_name.c_str());
    y2milestone ("Deploy new proxy component for %s", namespace_name.c_str());
  }

  stub_modules[namespace_name]->addStub(method, response);
}

