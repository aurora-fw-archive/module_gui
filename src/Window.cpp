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
		Window::Window(const std::string& name, const int& width, const int& height, const WindowPosition& pos, const WindowType& type)
			: _window(gtk_window_new((GtkWindowType)type))
		{
			DebugManager::Log("creating new window");
			setTitle(name);
			setPos(pos);
			gtk_window_set_default_size(GTK_WINDOW(_window), width, height);
			connect("destroy", []{
				gtk_main_quit();
				DebugManager::Log("window is destroyed.");
			});
			DebugManager::Log("window is created.");
		}

		void Window::setTitle(const std::string& title)
		{
			DebugManager::Log("setting title on window");
			gtk_window_set_title(GTK_WINDOW(_window), title.c_str());
		}

		void Window::setPos(const WindowPosition& pos)
		{
			DebugManager::Log("setting window position on window");
			gtk_window_set_position (GTK_WINDOW(_window), (GtkWindowPosition) pos);
		}

		void Window::setOpacity(double val)
		{
			DebugManager::Log("setting window opacity to: ", val);
			gtk_widget_set_opacity(_window, val);
		}

		void Window::setResizable(bool val)
		{
			DebugManager::Log("setting window resizable value to:", val);
			gtk_window_set_resizable(GTK_WINDOW(_window), val);
		}

		void Window::maximize()
		{
			DebugManager::Log("maximizing window");
			gtk_window_maximize(GTK_WINDOW(_window));
		}

		void Window::unmaximize()
		{
			DebugManager::Log("unmaximizing window");
			gtk_window_unmaximize(GTK_WINDOW(_window));
		}

		void Window::iconify()
		{
			DebugManager::Log("iconify window");
			gtk_window_iconify(GTK_WINDOW(_window));
		}

		void Window::deiconify()
		{
			DebugManager::Log("deiconify window");
			gtk_window_deiconify(GTK_WINDOW(_window));
		}

		void Window::stick()
		{
			DebugManager::Log("sticking window");
			gtk_window_stick(GTK_WINDOW(_window));
		}

		void Window::unstick()
		{
			DebugManager::Log("unsticking window");
			gtk_window_unstick(GTK_WINDOW(_window));
		}

		void Window::fullscreen()
		{
			DebugManager::Log("toggle fullscreen mode to the current window");
			gtk_window_fullscreen(GTK_WINDOW(_window));
		}

		void Window::unfullscreen()
		{
			DebugManager::Log("toggle windowed mode to the current window");
			gtk_window_unfullscreen(GTK_WINDOW(_window));
		}

		void Window::setIcon(const unsigned char* data, int width, int height, int bpp, bool alpha)
		{
			DebugManager::Log("setting the icon for the current window");
			gtk_window_set_icon(GTK_WINDOW(_window),
				gdk_pixbuf_new_from_data(data,
					GDK_COLORSPACE_RGB,
					alpha,
					bpp, width, height,
					0, NULL, NULL));
		}

		void Window::close()
		{
			DebugManager::Log("closing window");
			gtk_window_close(GTK_WINDOW(_window));
		}

		void Window::resize(int w, int h)
		{
			DebugManager::Log("resizing window to: ", w, "*", h);
			gtk_window_resize(GTK_WINDOW(_window), w, h);
		}

		void Window::move(int x, int y)
		{
			DebugManager::Log("moving window ", x, "(x value), ", y, "(y value)");
			gtk_window_move(GTK_WINDOW(_window), x, y);
		}

		void Window::connect(const std::string& detailedSignal, void (*signalFunction)(), void* signalData)
		{
			DebugManager::Log("creating new signal on window");
			g_signal_connect(_window, detailedSignal.c_str(), G_CALLBACK(signalFunction), signalData);
		}

		void Window::start(void (*startFunction)())
		{
			gtk_widget_show_all(_window);
			DebugManager::Log("showing widgets on window");
			(*startFunction)();
			DebugManager::Log("starting main loop on window");
			gtk_main();
		}
	}
}
