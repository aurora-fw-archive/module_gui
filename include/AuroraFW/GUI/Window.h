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

#include <AuroraFW/STDL/STL/IOStream.h>
#include <AuroraFW/STDL/STL/String.h>

#include <AuroraFW/Math/Vector2D.h>
#include <AuroraFW/Image/Image.h>

typedef struct _GtkWidget GtkWidget;

namespace AuroraFW {
	namespace GUI {
		class AFW_EXPORT Window {
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

			Window(const std::string& = "Aurora Window", const int& = 200, const int& = 200, const WindowPosition& = NonePosition, const WindowType& = ToplevelWindow);
			
			void setTitle(const std::string& );
			void setPos(const WindowPosition& );
			void resize(int , int );
			inline void resize(Math::Vector2D& );
			void move(int , int );
			inline void move(Math::Vector2D& );
			void setOpacity(double );
			void setResizable(bool );
			void setIcon(const unsigned char* , int , int , int , bool );
			void setIcon(ImageManager::Image& );
			void setIcon(const char* );
			inline void setIcon(const std::string& );
			void maximize();
			void unmaximize();
			void iconify();
			void deiconify();
			void stick();
			void unstick();
			void fullscreen();
			void unfullscreen();
			void close();

			double getOpacity() const;
			Math::Vector2D getSize() const;
			WindowPosition getPos() const;
			std::string getTitle() const;
			bool isResizable() const;
			bool isMaximized() const;
			bool isFocused() const;
			inline GtkWidget* getNativeGtkWidget() const { return _window; }

			void connect(const std::string& , void (*)(), void* = NULL);
			void start(void (*)() = []{});

		private:
			GtkWidget* _window;
		};

		inline void Window::resize(Math::Vector2D& vec)
		{
			resize(vec.x, vec.y);
		}

		inline void Window::move(Math::Vector2D& vec)
		{
			move(vec.x, vec.y);
		}

		inline void setIcon(const std::string& str)
		{
			setIcon(str.c_str());
		}
	}
}

#endif // AURORAFW_GUI_WINDOW_H
