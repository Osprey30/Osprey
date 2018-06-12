//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "OspreyTestApp.h"
#include "OspreyApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<OspreyTestApp>()
{
  InputParameters params = validParams<OspreyApp>();
  return params;
}

OspreyTestApp::OspreyTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  OspreyApp::registerObjectDepends(_factory);
  OspreyApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  OspreyApp::associateSyntaxDepends(_syntax, _action_factory);
  OspreyApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  OspreyApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    OspreyTestApp::registerObjects(_factory);
    OspreyTestApp::associateSyntax(_syntax, _action_factory);
    OspreyTestApp::registerExecFlags(_factory);
  }
}

OspreyTestApp::~OspreyTestApp() {}

void
OspreyTestApp::registerApps()
{
  registerApp(OspreyApp);
  registerApp(OspreyTestApp);
}

void
OspreyTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
OspreyTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
OspreyTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
OspreyTestApp__registerApps()
{
  OspreyTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
OspreyTestApp__registerObjects(Factory & factory)
{
  OspreyTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
OspreyTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  OspreyTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
OspreyTestApp__registerExecFlags(Factory & factory)
{
  OspreyTestApp::registerExecFlags(factory);
}
