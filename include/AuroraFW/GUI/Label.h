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

#ifndef AURORAFW_GUI_LABEL_H
#define AURORAFW_GUI_LABEL_H

#include <AuroraFW/GUI/Window.h>
#include <AuroraFW/GUI/Layout.h>
#include <AuroraFW/TLib/Target.h>

#ifdef AFW_TARGET_CXX
	#include <cassert>
#elif defined(AFW_TARGET_CC)
	#include <assert.h>
#endif

/* TODO:
** Setters
**	void setSingleLineMode(bool);
**	void setJustify(JustifyMode);
**	void setLength(int);
**	void setMaxLength(int);
**	void setSelection(int, int);
**	void setAngle(double);
**
** Getters
**	bool isSingleLineMode();
**	JustifyMode getJustify();
**	int getLength();
**	int getMaxLength();
**	int getLines();
**	double getAngle();
**
** Signals
** 	> Use g_signal_connect()
**
**	onCursorMove(void);
**	onCopyToClipboard(void);
**	onLinkClick(void);
*/

typedef struct _GtkWidget GtkWidget;

namespace AuroraFW {
	namespace GUI {
        class AFW_PREFIX Label {
    	public:
    		Label(Window*& , const std::string& name = "New Label");
            Label(const Label&);
            ~Label();

    		//Setters
    		void setText(std::string);
    		void setSelectable(bool);
    		void setWrap(bool);
    		void setWrapMode(WrapMode);
    		void setAlignment(AlignMode);
    		void setAlignment(const float, const float);

    		//Getters
    		std::string getText() const;
    		bool isSelectable() const;
    		bool isWrap() const;
    		WrapMode getWrapMode() const;
    		AlignMode getAlignment() const;
    		float getXAlignment() const;
    		float getYAlignment() const;

            Label& operator=(const Label&);

    		//Signals

    	private:
            GtkWidget *_windowParent;
    		GtkWidget *_label;
    	};
    }
}

#endif // AURORAFW_GUI_LABEL_H
