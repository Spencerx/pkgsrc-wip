$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc.orig	2024-10-18 12:34:35.600094000 +0000
+++ third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc
@@ -149,7 +149,7 @@ bool ScrollbarThemeAura::SupportsDragSna
 // is true for at least GTK and QT apps).
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
@@ -372,7 +372,7 @@ bool ScrollbarThemeAura::ShouldCenterOnT
                                              const WebMouseEvent& event) const {
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   if (event.button == WebPointerProperties::Button::kMiddle)
     return true;
 #endif
