$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/security_interstitials/content/utils.cc.orig	2024-10-18 12:34:07.997750000 +0000
+++ components/security_interstitials/content/utils.cc
@@ -38,7 +38,7 @@ void LaunchDateAndTimeSettings() {
 #if BUILDFLAG(IS_ANDROID)
   JNIEnv* env = base::android::AttachCurrentThread();
   Java_DateAndTimeSettingsHelper_openDateAndTimeSettings(env);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   struct ClockCommand {
     const char* const pathname;
     const char* const argument;
