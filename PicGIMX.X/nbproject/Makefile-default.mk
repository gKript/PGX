#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PicGIMX.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PicGIMX.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../PicGIMX_Sources/PicGIMX/src/pgx_module/pgx_timer.c ../PicGIMX_Sources/PicGIMX/src/pgx_module/pgx_lcd_hd44780.c ../PicGIMX_Sources/PicGIMX/src/pgx_module/pgx_delay.c ../PicGIMX_Sources/PicGIMX/src/pgx_init.c ../PicGIMX_Sources/main.c ../PicGIMX_Sources/PicGIMX/src/pgx_module/pgim_event.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/809872133/pgx_timer.p1 ${OBJECTDIR}/_ext/809872133/pgx_lcd_hd44780.p1 ${OBJECTDIR}/_ext/809872133/pgx_delay.p1 ${OBJECTDIR}/_ext/2059308222/pgx_init.p1 ${OBJECTDIR}/_ext/1340699775/main.p1 ${OBJECTDIR}/_ext/809872133/pgim_event.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/809872133/pgx_timer.p1.d ${OBJECTDIR}/_ext/809872133/pgx_lcd_hd44780.p1.d ${OBJECTDIR}/_ext/809872133/pgx_delay.p1.d ${OBJECTDIR}/_ext/2059308222/pgx_init.p1.d ${OBJECTDIR}/_ext/1340699775/main.p1.d ${OBJECTDIR}/_ext/809872133/pgim_event.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/809872133/pgx_timer.p1 ${OBJECTDIR}/_ext/809872133/pgx_lcd_hd44780.p1 ${OBJECTDIR}/_ext/809872133/pgx_delay.p1 ${OBJECTDIR}/_ext/2059308222/pgx_init.p1 ${OBJECTDIR}/_ext/1340699775/main.p1 ${OBJECTDIR}/_ext/809872133/pgim_event.p1

# Source Files
SOURCEFILES=../PicGIMX_Sources/PicGIMX/src/pgx_module/pgx_timer.c ../PicGIMX_Sources/PicGIMX/src/pgx_module/pgx_lcd_hd44780.c ../PicGIMX_Sources/PicGIMX/src/pgx_module/pgx_delay.c ../PicGIMX_Sources/PicGIMX/src/pgx_init.c ../PicGIMX_Sources/main.c ../PicGIMX_Sources/PicGIMX/src/pgx_module/pgim_event.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/PicGIMX.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/809872133/pgx_timer.p1: ../PicGIMX_Sources/PicGIMX/src/pgx_module/pgx_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/809872133" 
	@${RM} ${OBJECTDIR}/_ext/809872133/pgx_timer.p1.d 
	@${RM} ${OBJECTDIR}/_ext/809872133/pgx_timer.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PicGIMX_Sources/PicGIMX/include" -I"../PicGIMX_Sources/PicGIMX/include/pgx_mcu" -I"../PicGIMX_Sources/PicGIMX/include/pgx_module" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/809872133/pgx_timer.p1 ../PicGIMX_Sources/PicGIMX/src/pgx_module/pgx_timer.c 
	@-${MV} ${OBJECTDIR}/_ext/809872133/pgx_timer.d ${OBJECTDIR}/_ext/809872133/pgx_timer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/809872133/pgx_timer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/809872133/pgx_lcd_hd44780.p1: ../PicGIMX_Sources/PicGIMX/src/pgx_module/pgx_lcd_hd44780.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/809872133" 
	@${RM} ${OBJECTDIR}/_ext/809872133/pgx_lcd_hd44780.p1.d 
	@${RM} ${OBJECTDIR}/_ext/809872133/pgx_lcd_hd44780.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PicGIMX_Sources/PicGIMX/include" -I"../PicGIMX_Sources/PicGIMX/include/pgx_mcu" -I"../PicGIMX_Sources/PicGIMX/include/pgx_module" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/809872133/pgx_lcd_hd44780.p1 ../PicGIMX_Sources/PicGIMX/src/pgx_module/pgx_lcd_hd44780.c 
	@-${MV} ${OBJECTDIR}/_ext/809872133/pgx_lcd_hd44780.d ${OBJECTDIR}/_ext/809872133/pgx_lcd_hd44780.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/809872133/pgx_lcd_hd44780.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/809872133/pgx_delay.p1: ../PicGIMX_Sources/PicGIMX/src/pgx_module/pgx_delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/809872133" 
	@${RM} ${OBJECTDIR}/_ext/809872133/pgx_delay.p1.d 
	@${RM} ${OBJECTDIR}/_ext/809872133/pgx_delay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PicGIMX_Sources/PicGIMX/include" -I"../PicGIMX_Sources/PicGIMX/include/pgx_mcu" -I"../PicGIMX_Sources/PicGIMX/include/pgx_module" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/809872133/pgx_delay.p1 ../PicGIMX_Sources/PicGIMX/src/pgx_module/pgx_delay.c 
	@-${MV} ${OBJECTDIR}/_ext/809872133/pgx_delay.d ${OBJECTDIR}/_ext/809872133/pgx_delay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/809872133/pgx_delay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2059308222/pgx_init.p1: ../PicGIMX_Sources/PicGIMX/src/pgx_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2059308222" 
	@${RM} ${OBJECTDIR}/_ext/2059308222/pgx_init.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2059308222/pgx_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PicGIMX_Sources/PicGIMX/include" -I"../PicGIMX_Sources/PicGIMX/include/pgx_mcu" -I"../PicGIMX_Sources/PicGIMX/include/pgx_module" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/2059308222/pgx_init.p1 ../PicGIMX_Sources/PicGIMX/src/pgx_init.c 
	@-${MV} ${OBJECTDIR}/_ext/2059308222/pgx_init.d ${OBJECTDIR}/_ext/2059308222/pgx_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2059308222/pgx_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1340699775/main.p1: ../PicGIMX_Sources/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1340699775" 
	@${RM} ${OBJECTDIR}/_ext/1340699775/main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1340699775/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PicGIMX_Sources/PicGIMX/include" -I"../PicGIMX_Sources/PicGIMX/include/pgx_mcu" -I"../PicGIMX_Sources/PicGIMX/include/pgx_module" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1340699775/main.p1 ../PicGIMX_Sources/main.c 
	@-${MV} ${OBJECTDIR}/_ext/1340699775/main.d ${OBJECTDIR}/_ext/1340699775/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1340699775/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/809872133/pgim_event.p1: ../PicGIMX_Sources/PicGIMX/src/pgx_module/pgim_event.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/809872133" 
	@${RM} ${OBJECTDIR}/_ext/809872133/pgim_event.p1.d 
	@${RM} ${OBJECTDIR}/_ext/809872133/pgim_event.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PicGIMX_Sources/PicGIMX/include" -I"../PicGIMX_Sources/PicGIMX/include/pgx_mcu" -I"../PicGIMX_Sources/PicGIMX/include/pgx_module" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/809872133/pgim_event.p1 ../PicGIMX_Sources/PicGIMX/src/pgx_module/pgim_event.c 
	@-${MV} ${OBJECTDIR}/_ext/809872133/pgim_event.d ${OBJECTDIR}/_ext/809872133/pgim_event.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/809872133/pgim_event.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/809872133/pgx_timer.p1: ../PicGIMX_Sources/PicGIMX/src/pgx_module/pgx_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/809872133" 
	@${RM} ${OBJECTDIR}/_ext/809872133/pgx_timer.p1.d 
	@${RM} ${OBJECTDIR}/_ext/809872133/pgx_timer.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PicGIMX_Sources/PicGIMX/include" -I"../PicGIMX_Sources/PicGIMX/include/pgx_mcu" -I"../PicGIMX_Sources/PicGIMX/include/pgx_module" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/809872133/pgx_timer.p1 ../PicGIMX_Sources/PicGIMX/src/pgx_module/pgx_timer.c 
	@-${MV} ${OBJECTDIR}/_ext/809872133/pgx_timer.d ${OBJECTDIR}/_ext/809872133/pgx_timer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/809872133/pgx_timer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/809872133/pgx_lcd_hd44780.p1: ../PicGIMX_Sources/PicGIMX/src/pgx_module/pgx_lcd_hd44780.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/809872133" 
	@${RM} ${OBJECTDIR}/_ext/809872133/pgx_lcd_hd44780.p1.d 
	@${RM} ${OBJECTDIR}/_ext/809872133/pgx_lcd_hd44780.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PicGIMX_Sources/PicGIMX/include" -I"../PicGIMX_Sources/PicGIMX/include/pgx_mcu" -I"../PicGIMX_Sources/PicGIMX/include/pgx_module" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/809872133/pgx_lcd_hd44780.p1 ../PicGIMX_Sources/PicGIMX/src/pgx_module/pgx_lcd_hd44780.c 
	@-${MV} ${OBJECTDIR}/_ext/809872133/pgx_lcd_hd44780.d ${OBJECTDIR}/_ext/809872133/pgx_lcd_hd44780.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/809872133/pgx_lcd_hd44780.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/809872133/pgx_delay.p1: ../PicGIMX_Sources/PicGIMX/src/pgx_module/pgx_delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/809872133" 
	@${RM} ${OBJECTDIR}/_ext/809872133/pgx_delay.p1.d 
	@${RM} ${OBJECTDIR}/_ext/809872133/pgx_delay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PicGIMX_Sources/PicGIMX/include" -I"../PicGIMX_Sources/PicGIMX/include/pgx_mcu" -I"../PicGIMX_Sources/PicGIMX/include/pgx_module" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/809872133/pgx_delay.p1 ../PicGIMX_Sources/PicGIMX/src/pgx_module/pgx_delay.c 
	@-${MV} ${OBJECTDIR}/_ext/809872133/pgx_delay.d ${OBJECTDIR}/_ext/809872133/pgx_delay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/809872133/pgx_delay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2059308222/pgx_init.p1: ../PicGIMX_Sources/PicGIMX/src/pgx_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2059308222" 
	@${RM} ${OBJECTDIR}/_ext/2059308222/pgx_init.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2059308222/pgx_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PicGIMX_Sources/PicGIMX/include" -I"../PicGIMX_Sources/PicGIMX/include/pgx_mcu" -I"../PicGIMX_Sources/PicGIMX/include/pgx_module" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/2059308222/pgx_init.p1 ../PicGIMX_Sources/PicGIMX/src/pgx_init.c 
	@-${MV} ${OBJECTDIR}/_ext/2059308222/pgx_init.d ${OBJECTDIR}/_ext/2059308222/pgx_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2059308222/pgx_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1340699775/main.p1: ../PicGIMX_Sources/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1340699775" 
	@${RM} ${OBJECTDIR}/_ext/1340699775/main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1340699775/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PicGIMX_Sources/PicGIMX/include" -I"../PicGIMX_Sources/PicGIMX/include/pgx_mcu" -I"../PicGIMX_Sources/PicGIMX/include/pgx_module" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1340699775/main.p1 ../PicGIMX_Sources/main.c 
	@-${MV} ${OBJECTDIR}/_ext/1340699775/main.d ${OBJECTDIR}/_ext/1340699775/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1340699775/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/809872133/pgim_event.p1: ../PicGIMX_Sources/PicGIMX/src/pgx_module/pgim_event.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/809872133" 
	@${RM} ${OBJECTDIR}/_ext/809872133/pgim_event.p1.d 
	@${RM} ${OBJECTDIR}/_ext/809872133/pgim_event.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PicGIMX_Sources/PicGIMX/include" -I"../PicGIMX_Sources/PicGIMX/include/pgx_mcu" -I"../PicGIMX_Sources/PicGIMX/include/pgx_module" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/809872133/pgim_event.p1 ../PicGIMX_Sources/PicGIMX/src/pgx_module/pgim_event.c 
	@-${MV} ${OBJECTDIR}/_ext/809872133/pgim_event.d ${OBJECTDIR}/_ext/809872133/pgim_event.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/809872133/pgim_event.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/PicGIMX.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/PicGIMX.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1    -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PicGIMX_Sources/PicGIMX/include" -I"../PicGIMX_Sources/PicGIMX/include/pgx_mcu" -I"../PicGIMX_Sources/PicGIMX/include/pgx_module" -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -mrom=default,-fd30-ffff -mram=default,-ef4-eff,-f9c-f9c,-fd4-fd4,-fdb-fdf,-fe3-fe7,-feb-fef,-ffd-fff  $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/PicGIMX.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/PicGIMX.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/PicGIMX.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/PicGIMX.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1    -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PicGIMX_Sources/PicGIMX/include" -I"../PicGIMX_Sources/PicGIMX/include/pgx_mcu" -I"../PicGIMX_Sources/PicGIMX/include/pgx_module" -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/PicGIMX.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
