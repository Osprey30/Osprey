#include "OspreyApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<OspreyApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

OspreyApp::OspreyApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  OspreyApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  OspreyApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  OspreyApp::registerExecFlags(_factory);
}

OspreyApp::~OspreyApp() {}

void
OspreyApp::registerApps()
{
  registerApp(OspreyApp);
}

void
OspreyApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"OspreyApp"});
}

void
OspreyApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"OspreyApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
OspreyApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
OspreyApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
OspreyApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
OspreyApp__registerApps()
{
  OspreyApp::registerApps();
}

extern "C" void
OspreyApp__registerObjects(Factory & factory)
{
  OspreyApp::registerObjects(factory);
}

extern "C" void
OspreyApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  OspreyApp::associateSyntax(syntax, action_factory);
}

extern "C" void
OspreyApp__registerExecFlags(Factory & factory)
{
  OspreyApp::registerExecFlags(factory);
}
