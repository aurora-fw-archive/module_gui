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
#include <AuroraFW/Core/Debug.h>

namespace AuroraFW
{
	namespace GUI {
		Label::Label(Window* &parent, std::string name)
			: WindowParent(parent->window), label(gtk_label_new (name.c_str()))
		{
			CLI::Log(CLI::Debug, "creating new label");
			gtk_container_add(GTK_CONTAINER(WindowParent), label);
			CLI::Log(CLI::Debug, "label is created");
		}

		Label::Label(const Label& lbl)
			: WindowParent(lbl.WindowParent), label(lbl.label)
		{}

		Label::~Label() {
			delete label;
			label = nullptr;
			delete WindowParent;
			WindowParent = nullptr;
		}

		//Settings
		void Label::setText(std::string text)
		{
			CLI::Log(CLI::Debug, "setting text on label");
			gtk_label_set_text((GtkLabel*)label, text.c_str());
		}
		std::string Label::getText() const
		{
			CLI::Log(CLI::Debug, "getting text from label");
			return std::string(gtk_label_get_text ((GtkLabel*)label));
		}
		void Label::setSelectable(bool value)
		{
			CLI::Log(CLI::Debug, "setting selectable property on label");
			gtk_label_set_selectable((GtkLabel*)label, value);
		}
		bool Label::isSelectable() const
		{
			CLI::Log(CLI::Debug, "getting selectable property from label");
			return gtk_label_get_selectable((GtkLabel*)label);
		}
		void Label::setWrap(bool value)
		{
			CLI::Log(CLI::Debug, "setting wrap property on label");
			gtk_label_set_line_wrap((GtkLabel*)label, value);
		}
		bool Label::isWrap() const
		{
			CLI::Log(CLI::Debug, "getting wrap property from label");
			return gtk_label_get_line_wrap((GtkLabel*)label);
		}
		void Label::setWrapMode(WrapMode mode)
		{
			CLI::Log(CLI::Debug, "setting wrap mode property on label");
			gtk_label_set_line_wrap_mode((GtkLabel*)label, (PangoWrapMode)mode);
		}
		WrapMode Label::getWrapMode() const
		{
			CLI::Log(CLI::Debug, "getting wrap mode property from label");
			return (WrapMode)gtk_label_get_line_wrap_mode((GtkLabel*)label);
		}
		void Label::setAlignment(AlignMode mode)
		{
			bool isCustom = false;
			switch(mode)
			{
				case AlignMode::TopLeft :
					CLI::Log(CLI::Debug, "setting alignment mode to 'TopLeft' property from label");
					gtk_label_set_xalign((GtkLabel*)label, 0);
					gtk_label_set_yalign((GtkLabel*)label, 0);
					break;
				case AlignMode::TopCenter :
					CLI::Log(CLI::Debug, "setting alignment mode to 'TopCenter' property from label");
					gtk_label_set_xalign((GtkLabel*)label, 0.5);
					gtk_label_set_yalign((GtkLabel*)label, 0);
					break;
				case AlignMode::TopRight :
					CLI::Log(CLI::Debug, "setting alignment mode to 'TopRight' property from label");
					gtk_label_set_xalign((GtkLabel*)label, 1);
					gtk_label_set_yalign((GtkLabel*)label, 0);
					break;
				case AlignMode::Left :
					CLI::Log(CLI::Debug, "setting alignment mode to 'Left' property from label");
					gtk_label_set_xalign((GtkLabel*)label, 0);
					gtk_label_set_yalign((GtkLabel*)label, 0.5);
					break;
				case AlignMode::Center :
					CLI::Log(CLI::Debug, "setting alignment mode to 'Center' property from label");
					gtk_label_set_xalign((GtkLabel*)label, 0.5);
					gtk_label_set_yalign((GtkLabel*)label, 0.5);
					break;
				case AlignMode::Right :
					CLI::Log(CLI::Debug, "setting alignment mode to 'Right' property from label");
					gtk_label_set_xalign((GtkLabel*)label, 1);
					gtk_label_set_yalign((GtkLabel*)label, 0.5);
					break;
				case AlignMode::BottomLeft :
					CLI::Log(CLI::Debug, "setting alignment mode to 'BottomLeft' property from label");
					gtk_label_set_xalign((GtkLabel*)label, 0);
					gtk_label_set_yalign((GtkLabel*)label, 1);
					break;
				case AlignMode::BottomCenter :
					CLI::Log(CLI::Debug, "setting alignment mode to 'BottomCenter' property from label");
					gtk_label_set_xalign((GtkLabel*)label, 0.5);
					gtk_label_set_yalign((GtkLabel*)label, 1);
					break;
				case AlignMode::BottomRight :
					CLI::Log(CLI::Debug, "setting alignment mode to 'BottomRight' property from label");
					gtk_label_set_xalign((GtkLabel*)label, 1);
					gtk_label_set_yalign((GtkLabel*)label, 1);
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
			CLI::Log(CLI::Debug, "setting alignment mode to ", x, "(x value) and ", y, "(y value) ", "property from label");
			gtk_label_set_xalign((GtkLabel*)label, x);
			gtk_label_set_yalign((GtkLabel*)label, y);
		}

		AlignMode Label::getAlignment() const
		{
			const float x = gtk_label_get_xalign((GtkLabel*)label);
			const float y = gtk_label_get_yalign((GtkLabel*)label);
			CLI::Log(CLI::Debug, "getting alignment mode property from label: ", x, "(x value) and ", y, "(y value)");
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
			CLI::Log(CLI::Debug, "getting alignment mode property from label: ", gtk_label_get_xalign((GtkLabel*)label), "(x value)");
			return gtk_label_get_xalign((GtkLabel*)label);
		}

		float Label::getYAlignment() const
		{
			CLI::Log(CLI::Debug, "getting alignment mode property from label: ", gtk_label_get_yalign((GtkLabel*)label), "(y value)");
			return gtk_label_get_yalign((GtkLabel*)label);
		}

		Label& Label::operator=(const Label& lbl)
		{
			this->label = lbl.label;
			this->WindowParent = lbl.WindowParent;
			return *this;
		}
	}
}
