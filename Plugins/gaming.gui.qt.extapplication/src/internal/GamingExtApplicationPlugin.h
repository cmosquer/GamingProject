/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/


#ifndef GAMINGEXTAPPLICATIONPLUGIN_H_
#define GAMINGEXTAPPLICATIONPLUGIN_H_

#include <berryAbstractUICTKPlugin.h>

#include <QString>

class GamingExtApplicationPlugin : public berry::AbstractUICTKPlugin
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "gaming_gui_qt_extapplication")
  Q_INTERFACES(ctkPluginActivator)

public:

  GamingExtApplicationPlugin();
  ~GamingExtApplicationPlugin() override;

  static GamingExtApplicationPlugin* GetDefault();

  ctkPluginContext* GetPluginContext() const;

  void start(ctkPluginContext*) override;

  QString GetQtHelpCollectionFile() const;

private:

  static GamingExtApplicationPlugin* inst;

  ctkPluginContext* context;
};

#endif /* GAMINGEXTAPPLICATIONPLUGIN_H_ */
