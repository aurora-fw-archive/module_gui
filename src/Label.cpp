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

#include <AuroraFW/GUI/Label.h>
#include <AuroraFW/GUI/Window.h>
#include <AuroraFW/CLI/Log.h>
#include <AuroraFW/Core/DebugManager.h>

namespace AuroraFW
{
	namespace GUI {
		Label::Label(Window* &parent, const std::string& name)
			: _windowParent(parent->_window), _label(gtk_label_new (name.c_str()))
		{
			DebugManager::Log("creating new label");
			gtk_container_add(GTK_CONTAINER(_windowParent), _label);
			DebugManager::Log("label is created");
		}

		Label::Label(const Label& lbl)
			: _windowParent(lbl._windowParent), _label(lbl._label)
		{}

		Label::~Label()
		{
			delete _label;
			_label = nullptr;
			delete _windowParent;
			_windowParent = nullptr;
		}

		//Settings
		void Label::setText(std::string text)
		{
			DebugManager::Log("setting text on label");
			gtk_label_set_text((GtkLabel*)_label, text.c_str());
		}

		std::string Label::getText() const
		{
			DebugManager::Log("getting text from label");
			return std::string(gtk_label_get_text ((GtkLabel*)_label));
		}

		void Label::setSelectable(bool value)
		{
			DebugManager::Log("setting selectable property on label");
			gtk_label_set_selectable((GtkLabel*)_label, value);
		}

		bool Label::isSelectable() const
		{
			DebugManager::Log("getting selectable property from label");
			return gtk_label_get_selectable((GtkLabel*)_label);
		}

		void Label::setWrap(bool value)
		{
			DebugManager::Log("setting wrap property on label");
			gtk_label_set_line_wrap((GtkLabel*)_label, value);
		}

		bool Label::isWrap() const
		{
			DebugManager::Log("getting wrap property from label");
			return gtk_label_get_line_wrap((GtkLabel*)_label);
		}

		void Label::setWrapMode(WrapMode mode)
		{
			DebugManager::Log("setting wrap mode property on label");
			gtk_label_set_line_wrap_mode((GtkLabel*)_label, (PangoWrapMode)mode);
		}

		WrapMode Label::getWrapMode() const
		{
			DebugManager::Log("getting wrap mode property from label");
			return (WrapMode)gtk_label_get_line_wrap_mode((GtkLabel*)_label);
		}

		void Label::setAlignment(AlignMode mode)
		{
			bool isCustom = false;
			switch(mode)
			{
				case AlignMode::TopLeft :
					DebugManager::Log("setting alignment mode to 'TopLeft' property from label");
					gtk_label_set_xalign((GtkLabel*)_label, 0);
					gtk_label_set_yalign((GtkLabel*)_label, 0);
					break;
				case AlignMode::TopCenter :
					DebugManager::Log("setting alignment mode to 'TopCenter' property from label");
					gtk_label_set_xalign((GtkLabel*)_label, 0.5);
					gtk_label_set_yalign((GtkLabel*)_label, 0);
					break;
				case AlignMode::TopRight :
					DebugManager::Log("setting alignment mode to 'TopRight' property from label");
					gtk_label_set_xalign((GtkLabel*)_label, 1);
					gtk_label_set_yalign((GtkLabel*)_label, 0);
					break;
				case AlignMode::Left :
					DebugManager::Log("setting alignment mode to 'Left' property from label");
					gtk_label_set_xalign((GtkLabel*)_label, 0);
					gtk_label_set_yalign((GtkLabel*)_label, 0.5);
					break;
				case AlignMode::Center :
					DebugManager::Log("setting alignment mode to 'Center' property from label");
					gtk_label_set_xalign((GtkLabel*)_label, 0.5);
					gtk_label_set_yalign((GtkLabel*)_label, 0.5);
					break;
				case AlignMode::Right :
					DebugManager::Log("setting alignment mode to 'Right' property from label");
					gtk_label_set_xalign((GtkLabel*)_label, 1);
					gtk_label_set_yalign((GtkLabel*)_label, 0.5);
					break;
				case AlignMode::BottomLeft :
					DebugManager::Log("setting alignment mode to 'BottomLeft' property from label");
					gtk_label_set_xalign((GtkLabel*)_label, 0);
					gtk_label_set_yalign((GtkLabel*)_label, 1);
					break;
				case AlignMode::BottomCenter :
					DebugManager::Log("setting alignment mode to 'BottomCenter' property from label");
					gtk_label_set_xalign((GtkLabel*)_label, 0.5);
					gtk_label_set_yalign((GtkLabel*)_label, 1);
					break;
				case AlignMode::BottomRight :
					DebugManager::Log("setting alignment mode to 'BottomRight' property from label");
					gtk_label_set_xalign((GtkLabel*)_label, 1);
					gtk_label_set_yalign((GtkLabel*)_label, 1);
					break;
				case AlignMode::Custom :
					isCustom = true;
					break;
			}
			assert(isCustom);
		}

		void Label::setAlignment(const float x, const float y)
		// x and y is acceptable between 0 and 1
		// x value for horizontal	| x >>
		// y value for vertical		| y \/
		{
			DebugManager::Log("setting alignment mode to ", x, "(x value) and ", y, "(y value) ", "property from label");
			gtk_label_set_xalign((GtkLabel*)_label, x);
			gtk_label_set_yalign((GtkLabel*)_label, y);
		}

		AlignMode Label::getAlignment() const
		{
			const float x = gtk_label_get_xalign((GtkLabel*)_label);
			const float y = gtk_label_get_yalign((GtkLabel*)_label);
			DebugManager::Log("getting alignment mode property from label: ", x, "(x value) and ", y, "(y value)");
			if(y == 0.0f)
			{
				if(x == 0.0f) return AlignMode::TopLeft;
				else if(x == 0.5f) return AlignMode::TopCenter;
				else if(x == 1.0f) return AlignMode::TopRight;
			}
			else if (y == 0.5f)
			{
				if(x == 0.0f) return AlignMode::Left;
				else if(x == 0.5f) return AlignMode::Center;
				else if(x == 1.0f) return AlignMode::Right;
			}
			else if (y == 1.0f)
			{
				if(x == 0.0f) return AlignMode::BottomLeft;
				else if(x == 0.5f) return AlignMode::BottomCenter;
				else if(x == 1.0f) return AlignMode::BottomRight;
			}
			return AlignMode::Custom;
		}

		float Label::getXAlignment() const
		{
			DebugManager::Log("getting alignment mode property from label: ", gtk_label_get_xalign((GtkLabel*)_label), "(x value)");
			return gtk_label_get_xalign((GtkLabel*)_label);
		}

		float Label::getYAlignment() const
		{
			DebugManager::Log("getting alignment mode property from label: ", gtk_label_get_yalign((GtkLabel*)_label), "(y value)");
			return gtk_label_get_yalign((GtkLabel*)_label);
		}

		Label& Label::operator=(const Label& lbl)
		{
			this->_label = lbl._label;
			this->_windowParent = lbl._windowParent;
			return *this;
		}
	}
}
