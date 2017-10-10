/****************************************************************************
** ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─
** ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐
** ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴
** A Powerful General Purpose Framework
** More information in: https://aurora-fw.github.io/
**
** Copyright (C) 2017 Aurora Framework, All rights reserved.
**
** This file is part of the Aurora Framework. This framework is free
** software; you can redistribute it and/or modify it under the terms of
** the GNU Lesser General Public License version 3 as published by the
** Free Software Foundation and appearing in the file LICENSE included in
** the packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
****************************************************************************/

#ifndef AURORAFW_GUI_APPLICATION_H
#define AURORAFW_GUI_APPLICATION_H

#include <AuroraFW/Global.h>

#include <AuroraFW/Core/Application.h>

#include <AuroraFW/GUI/_GtkApplication.h>

namespace AuroraFW {
	namespace GUI {
		class AFW_EXPORT Application {
		public:
			enum ApplicationFlags
			{
				NoneFlag,
				ServiceFlag,
				LauncherFlag,
				HandlesOpenFlag,
				HandlesCommandLineFlag,
				SendEnvironmentFlag,
				NonUniqueFlag,
				OverrideAppIDFlag
			};
			Application(const std::string& pkgname = "org.aurora.example", const ApplicationFlags& flags = NoneFlag, void (*mainfunction)() = []{}, int argc = 0, char *argv[] = NULL);
			~Application();

			Application (const Application& x) = delete;
			Application& operator= (const Application& x) = delete;

			void connect(const std::string& detailedSignal, void (*signalFunction)(), void *signalData = NULL);
			int appStatus;
		private:
			GtkApplication *_app;
			AuroraFW::Application *_processApp;
		};
	}
}

#endif // AURORAFW_GUI_APPLICATION
