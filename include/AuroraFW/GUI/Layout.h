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

#ifndef AURORAFW_GUI_LAYOUT_H
#define AURORAFW_GUI_LAYOUT_H

#include <AuroraFW/Global.h>
#if(AFW_TARGET_PRAGMA_ONCE_SUPPORT)
	#pragma once
#endif

namespace AuroraFW {
	namespace GUI {
		enum class WrapMode
		{
			Word,
			Char,
			WordChar
		};
		enum class AlignMode
		{
			/* TL  TC  TR	| \ | /
			** L   C   R	| < * >
			** BL  BC  BR	| / | \
			*/
			TopLeft,
			TopCenter,
			TopRight,
			Left,
			Center,
			Right,
			BottomLeft,
			BottomCenter,
			BottomRight,
			Custom
		};
		enum class JustifyMode
		{
			Left,
			Right,
			Center,
			Fill
		};
	}
}

#endif // AURORAFW_GUI_LAYOUT_H
