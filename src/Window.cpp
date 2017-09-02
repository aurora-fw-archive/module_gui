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

#include <gtk/gtk.h>
#include <AuroraFW/GUI/Window.h>
#include <AuroraFW/Core/Debug.h>
#include <AuroraFW/CLI/Log.h>

namespace AuroraFW
{
	namespace GUI {
		Window::Window(std::string name, int width, int height, WindowPosition pos, WindowType type)
		{
			CLI::Log(CLI::Debug, "creating new window");
			window = gtk_window_new((GtkWindowType)type);
			setTitle(name);
			setPos(pos);
			gtk_window_set_default_size(GTK_WINDOW(window), width, height);
			connect("destroy", []{
				gtk_main_quit();
				CLI::Log(CLI::Debug, "window is destroyed.");
			});
			CLI::Log(CLI::Debug, "window is created.");
		}

		void Window::setTitle(std::string title)
		{
			CLI::Log(CLI::Debug, "setting title on window");
			gtk_window_set_title(GTK_WINDOW(window), title.c_str());
		}

		void Window::setPos(WindowPosition pos)
		{
			CLI::Log(CLI::Debug, "setting window position on window");
			gtk_window_set_position (GTK_WINDOW(window), (GtkWindowPosition) pos);
		}

		void Window::connect(std::string detailedSignal, void (*signalFunction)(), void* signalData)
		{
			CLI::Log(CLI::Debug, "creating new signal on window");
			g_signal_connect(window, detailedSignal.c_str(), G_CALLBACK(signalFunction), signalData);
		}

		void Window::start(void (*startFunction)())
		{
			gtk_widget_show_all(window);
			CLI::Log(CLI::Debug, "showing widgets on window");
			(*startFunction)();
			CLI::Log(CLI::Debug, "starting main loop on window");
			gtk_main();
		}
	}
}
