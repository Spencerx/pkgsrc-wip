$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/window/custom_frame_view.cc.orig	2024-10-18 12:35:12.880208300 +0000
+++ ui/views/window/custom_frame_view.cc
@@ -268,7 +268,7 @@ int CustomFrameView::CaptionButtonY() co
   // drawn flush with the screen edge, they still obey Fitts' Law.
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   return FrameBorderThickness();
 #else
   return frame_->IsMaximized() ? FrameBorderThickness() : kFrameShadowThickness;
