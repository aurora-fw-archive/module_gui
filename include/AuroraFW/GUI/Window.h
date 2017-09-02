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

#ifndef AURORAFW_GUI_WINDOW_H
#define AURORAFW_GUI_WINDOW_H

#include <AuroraFW/Global.h>

#include <iostream>
#include <string>

typedef struct _GtkWidget GtkWidget;

namespace AuroraFW
{
	namespace GUI {
        class Window
    	{
    	friend class Label;
        friend class Button;
    	public:

    		// Window Types
    		enum WindowType
    		{
    			ToplevelWindow,
    			PopupWindow
    		};

    		// Window Positions
    		enum WindowPosition
    		{
    			NonePosition,
    			CenterPosition,
    			MousePosition,
    			AlwaysCenterPosition,
    			CenterParentPosition
    		};

    		Window(std::string = "Aurora Window", int = 200, int = 200, WindowPosition = NonePosition, WindowType = ToplevelWindow);
    		void setTitle(std::string );
    		void setPos(WindowPosition );
    		void connect(std::string , void (*)(), void* = NULL);
    		void show(void);
    		void start(void (*)() = []{});

    	protected:
    		GtkWidget *window;
    	};
    }
}

#endif // AURORAFW_GUI_WINDOW_H
