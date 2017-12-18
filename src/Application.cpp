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

#include <AuroraFW/STDL/STL/IOStream.h>

#include <gtk/gtk.h>
#include <AuroraFW/GUI/Application.h>
#include <AuroraFW/Core/Application.h>
#include <AuroraFW/Core/Debug.h>
#include <AuroraFW/CLI/Log.h>

namespace AuroraFW {
	namespace GUI {
		Application::Application(const std::string& pkgname, const ApplicationFlags& flags, void (*mainfunction)(), int argc, char *argv[])
			: _app(gtk_application_new (pkgname.c_str(), (GApplicationFlags)flags))
		{
			Debug::Log("creating a new application...");
			Debug::Log("application is created.");
			connect("activate", mainfunction);
			_appStatus = g_application_run(G_APPLICATION(_app), argc, argv);
			g_object_unref(_app);
		}
		Application::~Application() {
			delete _app;
			_app = nullptr;
		}

		void Application::connect(const std::string& detailedSignal, void (*signalFunction)(), void *signalData)
		{
			Debug::Log("creating new signal on application");
			g_signal_connect (_app, detailedSignal.c_str(), G_CALLBACK(signalFunction), signalData);
		}
	}
}
