$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/views/frame/opaque_browser_frame_view_layout_delegate.h.orig	2024-10-18 12:34:03.360269300 +0000
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view_layout_delegate.h
@@ -10,7 +10,7 @@
 #include "build/build_config.h"
 #include "build/chromeos_buildflags.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #include "ui/base/ui_base_types.h"
 #endif
 
@@ -93,7 +93,7 @@ class OpaqueBrowserFrameViewLayoutDelega
   // Returns true if a client-side shadow should be drawn for restored windows.
   virtual bool ShouldDrawRestoredFrameShadow() const = 0;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns whether the window is in a tiled state.
   virtual bool IsTiled() const = 0;
 #endif
