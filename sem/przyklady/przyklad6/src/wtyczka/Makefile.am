include $(top_srcdir)/Makefile.tool.am


#----------------------------------------------------------------------------
# wtyczka-<platform>
#----------------------------------------------------------------------------

noinst_PROGRAMS  = wtyczka-@VGCONF_ARCH_PRI@-@VGCONF_OS@
if VGCONF_HAVE_PLATFORM_SEC
noinst_PROGRAMS += wtyczka-@VGCONF_ARCH_SEC@-@VGCONF_OS@
endif

wtyczka_SOURCES_COMMON = wt_main.c

wtyczka_@VGCONF_ARCH_PRI@_@VGCONF_OS@_SOURCES      = \
	$(wtyczka_SOURCES_COMMON)
wtyczka_@VGCONF_ARCH_PRI@_@VGCONF_OS@_CPPFLAGS     = \
	$(AM_CPPFLAGS_@VGCONF_PLATFORM_PRI_CAPS@)
wtyczka_@VGCONF_ARCH_PRI@_@VGCONF_OS@_CFLAGS       = $(LTO_CFLAGS) \
	$(AM_CFLAGS_@VGCONF_PLATFORM_PRI_CAPS@)
wtyczka_@VGCONF_ARCH_PRI@_@VGCONF_OS@_DEPENDENCIES = \
	$(TOOL_DEPENDENCIES_@VGCONF_PLATFORM_PRI_CAPS@)
wtyczka_@VGCONF_ARCH_PRI@_@VGCONF_OS@_LDADD        = \
	$(TOOL_LDADD_@VGCONF_PLATFORM_PRI_CAPS@)
wtyczka_@VGCONF_ARCH_PRI@_@VGCONF_OS@_LDFLAGS      = \
	$(TOOL_LDFLAGS_@VGCONF_PLATFORM_PRI_CAPS@)
wtyczka_@VGCONF_ARCH_PRI@_@VGCONF_OS@_LINK = \
	$(top_builddir)/coregrind/link_tool_exe_@VGCONF_OS@ \
	@VALT_LOAD_ADDRESS_PRI@ \
	$(LINK) \
	$(wtyczka_@VGCONF_ARCH_PRI@_@VGCONF_OS@_CFLAGS) \
	$(wtyczka_@VGCONF_ARCH_PRI@_@VGCONF_OS@_LDFLAGS)

if VGCONF_HAVE_PLATFORM_SEC
wtyczka_@VGCONF_ARCH_SEC@_@VGCONF_OS@_SOURCES      = \
	$(wtyczka_SOURCES_COMMON)
wtyczka_@VGCONF_ARCH_SEC@_@VGCONF_OS@_CPPFLAGS     = \
	$(AM_CPPFLAGS_@VGCONF_PLATFORM_SEC_CAPS@)
wtyczka_@VGCONF_ARCH_SEC@_@VGCONF_OS@_CFLAGS       = $(LTO_CFLAGS) \
	$(AM_CFLAGS_@VGCONF_PLATFORM_SEC_CAPS@)
wtyczka_@VGCONF_ARCH_SEC@_@VGCONF_OS@_DEPENDENCIES = \
	$(TOOL_DEPENDENCIES_@VGCONF_PLATFORM_SEC_CAPS@)
wtyczka_@VGCONF_ARCH_SEC@_@VGCONF_OS@_LDADD        = \
	$(TOOL_LDADD_@VGCONF_PLATFORM_SEC_CAPS@)
wtyczka_@VGCONF_ARCH_SEC@_@VGCONF_OS@_LDFLAGS      = \
	$(TOOL_LDFLAGS_@VGCONF_PLATFORM_SEC_CAPS@)
wtyczka_@VGCONF_ARCH_SEC@_@VGCONF_OS@_LINK = \
	$(top_builddir)/coregrind/link_tool_exe_@VGCONF_OS@ \
	@VALT_LOAD_ADDRESS_SEC@ \
	$(LINK) \
	$(wtyczka_@VGCONF_ARCH_SEC@_@VGCONF_OS@_CFLAGS) \
	$(wtyczka_@VGCONF_ARCH_SEC@_@VGCONF_OS@_LDFLAGS)
endif


