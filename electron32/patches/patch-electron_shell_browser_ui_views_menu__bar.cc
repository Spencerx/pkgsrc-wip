$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/ui/views/menu_bar.cc.orig	2025-02-26 12:22:11.000000000 +0000
+++ electron/shell/browser/ui/views/menu_bar.cc
@@ -13,7 +13,7 @@
 #include "ui/views/background.h"
 #include "ui/views/layout/box_layout.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/gtk/gtk_util.h"  // nogncheck
 #endif
 
@@ -212,7 +212,7 @@ void MenuBar::ViewHierarchyChanged(
 
 void MenuBar::RefreshColorCache(const ui::NativeTheme* theme) {
   if (theme) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     background_color_ = gtk::GetBgColor("GtkMenuBar#menubar");
     enabled_color_ =
         gtk::GetFgColor("GtkMenuBar#menubar GtkMenuItem#menuitem GtkLabel");
@@ -237,7 +237,7 @@ void MenuBar::RebuildChildren() {
 }
 
 void MenuBar::UpdateViewColors() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // set menubar background color
   SetBackground(views::CreateSolidBackground(background_color_));
 #endif
@@ -245,7 +245,7 @@ void MenuBar::UpdateViewColors() {
   // set child colors
   if (menu_model_ == nullptr)
     return;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const auto& textColor =
       window_->IsFocused() ? enabled_color_ : disabled_color_;
   for (views::View* child : GetChildrenInZOrder()) {
