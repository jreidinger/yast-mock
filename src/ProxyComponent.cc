#include <y2/Y2Namespace.h>
#include <y2/Y2Component.h>
#include <y2/Y2ComponentCreator.h>

#include "ProxyComponent.h"

#include "log.h"
#include "ProxyModule.h"

ProxyComponent::~ProxyComponent()
{
  map<std::string,Y2Namespace*>::iterator i;
  for (i=namespaces.begin();i!=namespaces.end();++i)
    delete i->second;
  delete real_component;
}

Y2Namespace *ProxyComponent::import (const char* name)
{

  y2milestone ("Proxy component import %s",name);
  if (namespaces.count(name) > 0)
    return namespaces[name];

  Y2Namespace *res = real_component->import(name);

  if (res == NULL)
    return res;

  res = new ProxyModule(res);
  namespaces[name] = res;
  return res;
}
