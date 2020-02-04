/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/

#ifndef GamingExtFileSaveProjectAction_H_
#define GamingExtFileSaveProjectAction_H_

#include <QAction>

#include <gaming_gui_qt_ext_Export.h>

#include <berrySmartPointer.h>

namespace berry {
struct IWorkbenchWindow;
}

class MITK_QT_COMMON_EXT_EXPORT GamingExtFileSaveProjectAction : public QAction
{
  Q_OBJECT

public:

  GamingExtFileSaveProjectAction(berry::SmartPointer<berry::IWorkbenchWindow> window);
  GamingExtFileSaveProjectAction(berry::IWorkbenchWindow* window);

protected slots:

  void Run();

private:

  void Init(berry::IWorkbenchWindow* window);

  berry::IWorkbenchWindow* m_Window;
};


#endif /*QmitkExtFileSaveProjectAction_H_*/
