/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/

#include "GamingExtAppWorkbenchAdvisor.h"
#include "internal/GamingExtApplicationPlugin.h"

#include <GamingExtWorkbenchWindowAdvisor.h>

const QString GamingExtAppWorkbenchAdvisor::DEFAULT_PERSPECTIVE_ID =
    "org.mitk.extapp.defaultperspective";

void
GamingExtAppWorkbenchAdvisor::Initialize(berry::IWorkbenchConfigurer::Pointer configurer)
{
  berry::QtWorkbenchAdvisor::Initialize(configurer);
  std::cout<<"INITIALIZING GAMING EXTERNAL WORKBENCH ADVISOR"<<std::endl;

  configurer->SetSaveAndRestore(true);
}

berry::WorkbenchWindowAdvisor*
GamingExtAppWorkbenchAdvisor::CreateWorkbenchWindowAdvisor(
        berry::IWorkbenchWindowConfigurer::Pointer configurer)
{
  GamingExtWorkbenchWindowAdvisor* advisor = new
    GamingExtWorkbenchWindowAdvisor(this, configurer);

  // Exclude the help perspective from org.blueberry.ui.qt.help from
  // the normal perspective list.
  // The perspective gets a dedicated menu entry in the help menu
  QList<QString> excludePerspectives;
  excludePerspectives.push_back("org.blueberry.perspectives.help");
  advisor->SetPerspectiveExcludeList(excludePerspectives);

  // Exclude some views from the normal view list
  QList<QString> excludeViews;
  excludeViews.push_back("org.mitk.views.modules");
  excludeViews.push_back( "org.blueberry.ui.internal.introview" );
  advisor->SetViewExcludeList(excludeViews);
  std::cout<<"CREATING GAMING EXTERNAL WORKBENCH ADVISOR"<<std::endl;

  advisor->SetWindowIcon(":/gaming.gui.qt.extapplication/icon.png");
  return advisor;
  //return new QmitkExtWorkbenchWindowAdvisor(this, configurer);
}

QString GamingExtAppWorkbenchAdvisor::GetInitialWindowPerspectiveId()
{
  return DEFAULT_PERSPECTIVE_ID;
}
