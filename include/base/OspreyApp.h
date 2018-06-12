//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef OSPREYAPP_H
#define OSPREYAPP_H

#include "MooseApp.h"

class OspreyApp;

template <>
InputParameters validParams<OspreyApp>();

class OspreyApp : public MooseApp
{
public:
  OspreyApp(InputParameters parameters);
  virtual ~OspreyApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void registerObjectDepends(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void associateSyntaxDepends(Syntax & syntax, ActionFactory & action_factory);
  static void registerExecFlags(Factory & factory);
};

#endif /* OSPREYAPP_H */
