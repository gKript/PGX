//
#ifndef _PGIMX_EZFUSE_H_
	#define _PGIMX_EZFUSE_H_
	//------------------------------------------------------------------------
	#if defined( __18F4620 )
		#include "./pgx_mcu/pgx_18f4620.h"
	#endif
	//------------------------------------------------------------------------
#endif

/*!	
	\page	SWC_EzFuse			Easy FUSE settingss
		\tableofcontents

		\n
		\image html easyfuse.png
		\n

		\endcode

		<b>EzFuse</b> is an easy way to configure the fuse and the basic parameters to start a project in a very short time. \n
		If you still do not know the modules of \a PicGIM then read this section specifies : \ref WPC_module

		\attention	This is  the only one COMPULSORY module so you can not disable it. \n
					But it will be possible to do it from the first release of the next MileStone 1.0 .

	\section		HOWezmp8		MPLAB 8 : How to select the microcontroller

		\htmlonly <hr> \endhtmlonly
		\endcode

		From the menu bar click <b>"Configure"</b>. Then click <b>"select device..."</b>. \n \n
		\image	html	cpuselect.jpg
		\n \n

		This will open the following dialog box. \n \n
		\image	html	cpuselected.jpg
		\n \n

		From the drop down menu you can choose the desired MCU. \n \n
		\image	html	cpuselecting.jpg
		\n \n

		<b>PicGIM</b> does not support all MCU listed but only a few. The list of supported MCU is constantly updated. \n
		<b>PicGIM</b> is an open source project so you can add yourself a specific MCU. \n \n

		Here you can refer to the specifications for the \a MCU supported by \a PicGIM : \subpage cpu

	\section		HOWezmpx		MPLAB X : How to select the microcontroller

		\htmlonly <hr> \endhtmlonly
		\endcode

		From the Dashboard, click the icon highlighted in yellow in the figure below. \n \n
		\image	html	mplabx-dasboard.png
		\n \n

		This will open the following dialog box. \n \n
		\image	html	mplabx-project-properities.png
		\n \n

		From the drop down menu you can choose the desired MCU. \n \n
		\n \n

		<b>PicGIM</b> does not support all MCU listed but only a few. The list of supported MCU is constantly updated. \n
		<b>PicGIM</b> is an open source project so you can add yourself a specific MCU. \n \n

		Here you can refer to the specifications for the \a MCU supported by \a PicGIM : \subpage cpu


	\section	SCM_cpu		Supported MCU by PicGIM

		\htmlonly <hr> \endhtmlonly
		\endcode

		These are the MCU currently supported by PicGIM. As already mentioned, the list is constantly updated. \n \n
		Check on http://www.gkript.org PicGIM that is always the latest version. \n
		As mentioned above, you can create your own support for one another MCU or request support PicGIM developers. \n \n

		\attention	Here a link to the file : \ref pgim_ezfuse.h \n
					This is not a file defined as public and therefore would not be edited. \n
					We suggest that you edit this file only if necessary and only if you know what you are doing.
			
			\subpage	MCU_PIC18F97J60	\n
			\subpage	MCU_PIC18F4620	\n
			\subpage	MCU_PIC18F4553	\n
			\subpage	MCU_PIC18F4550	\n
			\subpage	MCU_PIC18F4520	\n
			\subpage	MCU_PIC18F2553	\n
			\subpage	MCU_PIC18F2550	\n
			\subpage	MCU_PIC18F2320	\n \n \n

 */


 
