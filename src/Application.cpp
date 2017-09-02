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

#include <AuroraFW/TLib/_IOStream.h>

#include <gtk/gtk.h>
#include <AuroraFW/GUI/Application.h>
#include <AuroraFW/Core/Application.h>
#include <AuroraFW/Core/Debug.h>
#include <AuroraFW/CLI/Log.h>

namespace AuroraFW
{
	namespace GUI {
		Application::Application(std::string pkgname, ApplicationFlags flags, void (*mainfunction)(), int argc, char *argv[])
		{
			ProcessApp = new AuroraFW::Application(mainfunction, argc, argv);
			CLI::Log(CLI::Debug, "creating a new application...");
			App = gtk_application_new (pkgname.c_str(), (GApplicationFlags)flags);
			CLI::Log(CLI::Debug, "application is created.");
			connect("activate", mainfunction);
			AppStatus = g_application_run (G_APPLICATION (App), 0, NULL);
			g_object_unref(App);
		}
		Application::~Application() {
			delete App;
			App = nullptr;
			delete ProcessApp;
			ProcessApp = nullptr;
		}

		void Application::connect(std::string detailedSignal, void (*signalFunction)(), void *signalData)
		{
			CLI::Log(CLI::Debug, "creating new signal on application");
			g_signal_connect (App, detailedSignal.c_str(), G_CALLBACK(signalFunction), signalData);
		}
	}
}
